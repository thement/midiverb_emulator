#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdarg.h>
#include <sndfile.h>
#include <math.h>
#include "utils.h"
#include "all-effects.h"

void load_wav_file(const char *filename, int16_t **samples, sf_count_t *num_samples, int *sample_rate, int *channels) {
    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(filename, SFM_READ, &sfinfo);
    if (!infile) {
        die("Failed to open input file: %s", sf_strerror(NULL));
    }

    *sample_rate = sfinfo.samplerate;
    *channels = sfinfo.channels;
    *num_samples = sfinfo.frames * sfinfo.channels;

    *samples = (int16_t *)malloc(*num_samples * sizeof(int16_t));
    if (!*samples) {
        sf_close(infile);
        die("Failed to allocate memory for input samples");
    }

    if (sf_read_short(infile, *samples, *num_samples) != *num_samples) {
        free(*samples);
        sf_close(infile);
        die("Failed to read samples from input file");
    }

    sf_close(infile);
}

void write_wav_file(const char *filename, int16_t *samples, sf_count_t num_samples, int sample_rate, int channels) {
    SF_INFO sfinfo;
    memset(&sfinfo, 0, sizeof(sfinfo));
    sfinfo.samplerate = sample_rate;
    sfinfo.channels = channels;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

    SNDFILE *outfile = sf_open(filename, SFM_WRITE, &sfinfo);
    if (!outfile) {
        die("Failed to open output file: %s", sf_strerror(NULL));
    }

    if (sf_write_short(outfile, samples, num_samples) != num_samples) {
        sf_close(outfile);
        die("Failed to write samples to output file");
    }

    sf_close(outfile);
}

int16_t clip(int32_t input) {
    if (input > INT16_MAX) {
        return INT16_MAX;
    } else if (input < INT16_MIN) {
        return INT16_MIN;
    } else {
        return (int16_t)input;
    }
}

static inline float saturate(float x)
{
    if (x <= -1.0)
        return -1.0;
    if (x >= 1.0)
        return 1.0;
    return x;
}

void effect_mix(
        int program_no,
        float feedback,
        float dry_wet,
        float input_left,
        float input_right,
        float previous_wet_output,
        float *mixed_output_left,
        float *mixed_output_right,
        float *wet_output,
        int16_t *DRAM,
        int *memory_pointer
) {
    float input = (input_left + input_right) / 2.0 + previous_wet_output * feedback;
    int16_t input_int = saturate(input) * 0x7ff; // input is 12 bit
    int16_t output_left_int, output_right_int;

    effects[program_no](input_int, &output_left_int, &output_right_int, DRAM, (*memory_pointer)++);

    float output_left = saturate(output_left_int / (float) 0x7ff);
    float output_right = saturate(output_right_int / (float) 0x7ff);

    *wet_output = (output_left + output_right) / 2;
    float equal_power_dry = powf(1.0 - dry_wet, 2.0);
    float equal_power_wet = powf(dry_wet, 2.0);
    *mixed_output_left = output_left * equal_power_wet + input_left * equal_power_dry;
    *mixed_output_right = output_right * equal_power_wet + input_right * equal_power_dry;
}

int main(int argc, char *argv[]) {
    if (argc < 6) {
        fprintf(stderr, "Usage: %s <program_no> <input_wav> <output_wav> <dry_wet> <feedback>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int program_no = atoi(argv[1]);
    const char *input_wav = argv[2];
    const char *output_wav = argv[3];
    float dry_wet = atof(argv[4]);
    float feedback = atof(argv[5]);

    if (program_no < 1 || program_no > ARRAY_SIZE(effects)) {
        die("Program number must be in range 1-%d", ARRAY_SIZE(effects));
    }

    // Read input WAV file
    int16_t *input_samples;
    sf_count_t num_samples;
    int sample_rate, channels;
    load_wav_file(input_wav, &input_samples, &num_samples, &sample_rate, &channels);
    printf("channels=%d, sample_rate=%d, num=%ld\n", channels, sample_rate, (long)num_samples);

    if (channels != 2) {
        free(input_samples);
        die("Input WAV file must be stereo");
    }

    // Prepare output samples
    int16_t *output_samples = (int16_t *)malloc(num_samples * sizeof(int16_t));
    if (!output_samples) {
        free(input_samples);
        die("Failed to allocate memory for output samples");
    }

    // Process each sample
    printf("drywet=%f feedbakc=%f\n", dry_wet, feedback);
    float wet_output = 0.0;
    int16_t DRAM[0x4000] = { 0 };
    int memory_pointer = 0;
    for (sf_count_t i = 0; i < num_samples; i += 2) {
        float input_left = input_samples[i] / 32768.0;
        float input_right = input_samples[i + 1] / 32768.0;
        float output_left;
        float output_right;

        effect_mix(program_no, feedback, dry_wet, input_left, input_right, wet_output, &output_left, &output_right, &wet_output, DRAM, &memory_pointer);

        output_samples[i] = clip(output_left * 32767.0);
        output_samples[i + 1] = clip(output_right * 32767.0);
    }

    // Write output WAV file
    write_wav_file(output_wav, output_samples, num_samples, sample_rate, channels);

    // Clean up
    free(input_samples);
    free(output_samples);

    return 0;
}
