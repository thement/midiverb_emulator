#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct {
    const char *rom_file, *input_wav, *output_wav;
    const char *model_name;
    float dry_wet_ratio, feedback_ratio;
    int program_number;
} Args;

void usage(void) {
    fprintf(stderr, "usage: midiverb [-m model_name] [-r rom_file] [-d dry_wet] [-f feedback] program_num input.wav output.wav");
    exit(1);
}

Args parse_args(int argc, char **argv) {
    Args args = { NULL, NULL, NULL, NULL, 1.0, 0.0, 0 };

    int opt;
    while ((opt = getopt(argc, argv, "r:d:f:m:")) != -1) {
        switch (opt) {
        case 'r': args.rom_file = optarg; break;
        case 'd': args.dry_wet_ratio = atof(optarg); break;
        case 'f': args.feedback_ratio = atof(optarg); break;
        case 'm': args.model_name = optarg; break;
        default:
            usage();
        }
    }

    if (argc - optind != 3)
        usage();

    args.program_number = atoi(argv[optind]);
    args.input_wav = argv[optind + 1];
    args.output_wav = argv[optind + 2];
    return args;
}
