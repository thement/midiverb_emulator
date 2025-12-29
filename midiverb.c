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
#include "utils.h"
#include "args.h"

enum {
    DramLength = 16*1024,
    ProgramLength = 256,
};

typedef struct {
    int address;
    uint8_t program[ProgramLength];
    int16_t dram[DramLength];
    int16_t acc;
    int memory_shift;
} Machine;

typedef struct {
    int16_t s[2];
} Sample;

void load_machine(Machine *machine, const char *path, int program_num) {
    memset(machine, 0, sizeof(Machine));
    read_bytes(path, (program_num - 1) * ProgramLength, ProgramLength, machine->program);
}

void reset_machine(Machine *machine) {
    memset(machine->dram, 0, sizeof(machine->dram));
    machine->acc = 0;
    machine->address = 0;
    machine->memory_shift = 2; /* 2 for midiverb 1, 1 for midiverb 2 */
}

void run_machine_tick(Machine *machine, int16_t input, Sample *output) {
    int acc = machine->acc;
    int address = machine->address;
    for (int pc = 0; pc < 128; pc++) {
        unsigned operation = machine->program[(2 * pc - machine->memory_shift - 1) & 0xff] >> 6;
        uint16_t offset_lo = machine->program[(2 * pc - machine->memory_shift + 0) & 0xff];
        uint16_t offset_hi = machine->program[(2 * pc - machine->memory_shift + 1) & 0xff] & 0x3f;
        uint16_t offset = (offset_hi << 8) | offset_lo;

        int16_t new_acc = acc;
        int16_t data, sgn;
        switch (operation) {
            case 0: // sumhlf
                data = machine->dram[address];
                sgn = data < 0 ? 1 : 0;
                new_acc = new_acc + (data >> 1) + sgn;
                break;
            case 1: // ldhlf
                data = machine->dram[address];
                sgn = data < 0 ? 1 : 0;
                new_acc = (data >> 1) + sgn;
                break;
            case 2: // strpos
                data = new_acc;
                sgn = data < 0 ? 1 : 0;
                machine->dram[address] = data;
                new_acc = new_acc + (data >> 1) + sgn;
                break;
            case 3: // strneg
                data = ~new_acc;
                sgn = data < 0 ? 1 : 0;
                machine->dram[address] = data;
                new_acc = (data >> 1) + sgn;
                break;
        }
        //printf("op=%d pc=%d addr=%08x data=%d acc=%d\n", operation, pc, machine->address, data, new_acc);

        // Handle special pc values for storing output.
        // Do not update accumulator at those places.
        if (pc == 0x60) {
            output->s[0] = data;
        } else if (pc == 0x70) {
            output->s[1] = data;
        } else if (pc == 0) {
            machine->dram[address] = input;
        } else {
            acc = new_acc;
        }

        address = (address + offset) % DramLength;
    }
    machine->acc = acc;
    machine->address = address;
    //printf("end addr=%d\n", address);
}


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

int main(int argc, char *argv[]) {
    Args args = parse_args(argc, argv);


    if (args.program_number < 1 || args.program_number > 64) {
        fprintf(stderr, "Program number must be in range 1-64 (where 64 is the DEFEAT program)\n");
        exit(EXIT_FAILURE);
    }

    if (args.rom_file == NULL)
        die("rom not specified");

    // Load the machine
    Machine machine;
    load_machine(&machine, args.rom_file, args.program_number);
    reset_machine(&machine);

    // Read input WAV file
    int16_t *input_samples;
    sf_count_t num_samples;
    int sample_rate, channels;
    load_wav_file(args.input_wav, &input_samples, &num_samples, &sample_rate, &channels);
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

    Sample output;
    float dry_wet_ratio = args.dry_wet_ratio;
    float wet_dry_ratio = 1.0 - dry_wet_ratio;

    // Process each sample
    for (sf_count_t i = 0; i < num_samples; i += 2) {
        int16_t input_left = input_samples[i];
        int16_t input_right = input_samples[i + 1];
        // Input should be 13-bit mono
        //
        // Sample rate is 23.4 KHz: https://github.com/emeb/MIDIVerb_RE/blob/main/docs/MV_Slides.pdf
        //
        // Remove 3 bits to reduce it from 16-bit to 13-bit and then shift by 1 bit to average
        int16_t input_mono = (input_left + input_right) >> (3 + 1);

        run_machine_tick(&machine, input_mono, &output);

        // Output is 13-bit stereo, which should be expanded to 16-bit (with clipping)
        // Some effects have gain > 1 which makes them clip at this point.
        int32_t output_left = output.s[0] << 3;
        int32_t output_right = output.s[1] << 3;

        output_samples[i] = clip(output_left * dry_wet_ratio + input_left * wet_dry_ratio);
        output_samples[i + 1] = clip(output_right * dry_wet_ratio + input_right * wet_dry_ratio);
    }

    // Write output WAV file
    write_wav_file(args.output_wav, output_samples, num_samples, sample_rate, channels);

    // Clean up
    free(input_samples);
    free(output_samples);

    return 0;
}
