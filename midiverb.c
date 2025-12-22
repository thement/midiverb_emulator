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

enum {
    DramLength = 16*1024,
    ProgramLength = 128,
};

typedef struct {
    int address;
    uint16_t program[ProgramLength];
    int16_t dram[DramLength];
    int16_t acc;
} Machine;

typedef struct {
    int16_t s[2];
} Sample;


// Error handling functions
void pexit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void die(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(EXIT_FAILURE);
}

void load_machine(Machine *machine, const char *path, int program_num) {
    // Erase the whole Machine
    memset(machine, 0, sizeof(Machine));

    // Open the file
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        die("Failed to open file: %s\n", strerror(errno));
    }

    // Seek to the correct offset
    off_t offset = ProgramLength * program_num * sizeof(uint16_t);
    if (lseek(fd, offset, SEEK_SET) == (off_t)-1) {
        close(fd);
        die("Failed to seek in file: %s\n", strerror(errno));
    }

    // Read ProgramLength number of bytes
    uint8_t buffer[ProgramLength * sizeof(uint16_t)];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read < 0) {
        close(fd);
        die("Failed to read from file: %s\n", strerror(errno));
    }
    if (bytes_read != sizeof(buffer)) {
        close(fd);
        die("Unexpected end of file\n");
    }

    // Assemble little-endian uint16_t values from bytes
    for (int i = 0; i < ProgramLength; i++) {
        machine->program[i] = buffer[2 * i] | (buffer[2 * i + 1] << 8);
    }

    // Close the file
    close(fd);
}

void reset_machine(Machine *machine) {
    memset(machine->dram, 0, sizeof(machine->dram));
    machine->acc = 0;
    machine->address = 0;
}

void run_machine_tick(Machine *machine, int16_t input, Sample *output) {
    int acc = machine->acc;
    int address = machine->address;
    for (int pc = 0; pc < 128; pc++) {
        uint16_t prev_instruction = machine->program[(pc + 126) % 128];
        uint16_t instruction = machine->program[(pc + 127) % 128];
        uint16_t opcode = (prev_instruction >> 14) & 0x3;
        uint16_t offset = instruction & 0x3FFF;

        int16_t new_acc = acc;
        int16_t data, sgn;
        switch (opcode) {
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
        //printf("op=%d pc=%d addr=%08x data=%d acc=%d\n", opcode, pc, machine->address, data, new_acc);

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
        die("Failed to open input file: %s\n", sf_strerror(NULL));
    }

    *sample_rate = sfinfo.samplerate;
    *channels = sfinfo.channels;
    *num_samples = sfinfo.frames * sfinfo.channels;

    *samples = (int16_t *)malloc(*num_samples * sizeof(int16_t));
    if (!*samples) {
        sf_close(infile);
        die("Failed to allocate memory for input samples\n");
    }

    if (sf_read_short(infile, *samples, *num_samples) != *num_samples) {
        free(*samples);
        sf_close(infile);
        die("Failed to read samples from input file\n");
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
        die("Failed to open output file: %s\n", sf_strerror(NULL));
    }

    if (sf_write_short(outfile, samples, num_samples) != num_samples) {
        sf_close(outfile);
        die("Failed to write samples to output file\n");
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

#ifdef USE_C_EFFECT
#include "effect.h"
#endif

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <program_file> <program_no> <input_wav> <output_wav>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *program_file = argv[1];
    int program_no = atoi(argv[2]);
    const char *input_wav = argv[3];
    const char *output_wav = argv[4];

    if (program_no < 1 || program_no > 64) {
        fprintf(stderr, "Program number must be in range 1-64 (where 64 is the DEFEAT program)\n");
        exit(EXIT_FAILURE);
    }

    // Load the machine
    Machine machine;
    load_machine(&machine, program_file, program_no - 1);
    reset_machine(&machine);

    // Read input WAV file
    int16_t *input_samples;
    sf_count_t num_samples;
    int sample_rate, channels;
    load_wav_file(input_wav, &input_samples, &num_samples, &sample_rate, &channels);
    printf("channels=%d, sample_rate=%d, num=%ld\n", channels, sample_rate, (long)num_samples);

    if (channels != 2) {
        free(input_samples);
        die("Input WAV file must be stereo\n");
    }

    // Prepare output samples
    int16_t *output_samples = (int16_t *)malloc(num_samples * sizeof(int16_t));
    if (!output_samples) {
        free(input_samples);
        die("Failed to allocate memory for output samples\n");
    }

    Sample output;

    // Process each sample
    for (sf_count_t i = 0; i < num_samples; i += 2) {
        int16_t left = input_samples[i];
        int16_t right = input_samples[i + 1];
        // Input should be 12-bit mono.
        // Remove 4 bits to reduce it from 16-bit and 1 bit to average.
        int16_t mono_sample = (left + right) >> 5;

#ifdef USE_C_EFFECT
        effect(mono_sample, &output.s[0], &output.s[1], machine.dram, i / 2);
#else
        run_machine_tick(&machine, mono_sample, &output);
#endif

        // Output is 12-bit stereo, which should be expanded to 16-bit (with clipping).
        output_samples[i] = clip(output.s[0] * 16);     // Left channel
        output_samples[i + 1] = clip(output.s[1] * 16); // Right channel
        //printf("output=%d %d\n", output.s[0], output.s[1]);
    }

    // Write output WAV file
    write_wav_file(output_wav, output_samples, num_samples, sample_rate, channels);

    // Clean up
    free(input_samples);
    free(output_samples);

    return 0;
}
