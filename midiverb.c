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
#include <assert.h>
#include <stdbool.h>
#include "utils.h"
#include "args.h"
#include "dasp16.h"
#include "wav.h"
#include "lfo.h"
#include "decompiled-midiverb.h"
#include "decompiled-midifex.h"
#include "decompiled-midiverb2.h"
#include "rom.h"

int16_t clip(int32_t input) {
    if (input > INT16_MAX) {
        return INT16_MAX;
    } else if (input < INT16_MIN) {
        return INT16_MIN;
    } else {
        return (int16_t)input;
    }
}

RomType *detect_rom(const char *rom_file, const char *model_name, bool *out_use_internal_effects) {
    if (rom_file == NULL) {
        if (model_name == NULL) {
            *out_use_internal_effects = true;
            return &rom_types[2];
        }
        for (int i = 0; i < ARRAY_SIZE(rom_types); i++) {
            RomType *rom_type = &rom_types[i];
            if (rom_type->decompiled != NULL && strcasecmp(model_name, rom_type->name) == 0) {
                *out_use_internal_effects = true;
                return rom_type;
            }
        }
        int printed_something = 0;
        fprintf(stderr, "model '%s' not found, available are:", model_name);
        for (int i = 0; i < ARRAY_SIZE(rom_types); i++) {
            RomType *rom_type = &rom_types[i];
            if (rom_type->decompiled != NULL) {
                fprintf(stderr, "%s %s", printed_something ? "," : "", rom_type->name);
                printed_something = 1;
            }
        }
        exit(0);
    } else {
        *out_use_internal_effects = false;

        // Detect ROM type
        uint8_t signature[4];
        read_bytes(rom_file, 0, 4, signature);

        for (int i = 0; i < ARRAY_SIZE(rom_types); i++) {
            RomType *rom_type = &rom_types[i];
            if (memcmp(signature, rom_type->signature, sizeof(rom_type->signature)) == 0) {
                fprintf(stderr, "detected ROM: %s\n", rom_type->name);
                return rom_type;
            }
        }

        fprintf(stderr, "warning: ROM was not recognized, assuming Midiverb I\n");
        return &rom_types[0];
    }
}

int main(int argc, char *argv[]) {
    Args args = parse_args(argc, argv);
    RomType *rom_type = NULL;
    bool use_internal_effects = false;

    // Get ROM type
    rom_type = detect_rom(args.rom_file, args.model_name, &use_internal_effects);

    // Check program number is valid
    int program_valid =
        args.program_number >= rom_type->first_program_number &&
        args.program_number <= rom_type->last_program_number;
    if (!program_valid) {
        die("error: program number #%d not valid, range is #%d to #%d",
            args.program_number,
            rom_type->first_program_number,
            rom_type->last_program_number);
    }
    int program_index = args.program_number - rom_type->first_program_number;

    // Load the machine
    Machine machine;
    void (*effect_fn)(int16_t input, int16_t *out_left, int16_t *out_right, int16_t *DRAM, int ptr);

    if (!use_internal_effects) {
        load_rom(&machine, rom_type, args.rom_file, args.program_number);
        effect_fn = NULL;
    } else {
        fprintf(stderr, "using internal decompiled effects for %s\n", rom_type->name);
        effect_fn = rom_type->decompiled[program_index];
    }
    if (rom_type->effect_names) {
	fprintf(stderr, "effect name: %s\n", rom_type->effect_names[program_index]);
    }
    reset_machine(&machine);

    // Initialize LFOs (if any)
    Lfo lfo1, lfo2;
    LfoPatch *lfo_patch;
    int run_lfo = 0;
    if (rom_type->has_lfo) {
        if (init_lfo_for_program(args.program_number, &lfo1, &lfo2, &lfo_patch)) {
            run_lfo = 1;
            fprintf(stderr, "this effect has LFO\n");
        }
    }

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
    int32_t output_left = 0, output_right = 0;


    // Process each sample
    for (sf_count_t i = 0; i < num_samples; i += 2) {
        int16_t input_left = input_samples[i];
        int16_t input_right = input_samples[i + 1];
        int32_t input_mono_with_fb = ((int32_t) input_left + input_right) * 0.5 +
            args.feedback_ratio * ((int32_t) output_left + output_right) * 0.5;
        int16_t input_clipped = clip(input_mono_with_fb);
        unsigned int sample_num = i / 2;

        // Input should be 13-bit mono
        //
        // Sample rate is 23.4 KHz: https://github.com/emeb/MIDIVerb_RE/blob/main/docs/MV_Slides.pdf
        //
        // Remove 3 bits to reduce it from 16-bit to 13-bit
        int16_t input_mono = input_clipped >> 3;

        if (effect_fn != NULL) {
            // Run decompiled version
            effect_fn(input_mono, &output.s[0], &output.s[1], machine.dram, machine.address++);
        } else {
            run_machine_tick(&machine, input_mono, &output);
        }

        // Output is 13-bit stereo, which should be expanded to 16-bit (with clipping)
        // Some effects have gain > 1 which makes them clip at this point.
        output_left = output.s[0] << 3;
        output_right = output.s[1] << 3;

        output_samples[i] = clip(output_left * dry_wet_ratio + input_left * wet_dry_ratio);
        output_samples[i + 1] = clip(output_right * dry_wet_ratio + input_right * wet_dry_ratio);

        // Run the LFO at 23437.5 / 8 == 2930 Hz
        if (sample_num % 8 == 0 && run_lfo) {
            uint32_t lfo1_value = lfo1.update(&lfo1);
            uint32_t lfo2_value = lfo2.update(&lfo2);

            patch_machine(&machine, lfo1_value, lfo2_value, lfo_patch->top1, lfo_patch->top2, lfo_patch->next_instr_opcode);
        }
    }

    // Write output WAV file
    write_wav_file(args.output_wav, output_samples, num_samples, sample_rate, channels);

    // Clean up
    free(input_samples);
    free(output_samples);

    return 0;
}
