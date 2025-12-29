typedef struct RomType RomType;

struct RomType {
    char *name;
    unsigned length;
    uint8_t signature[4];
    unsigned first_program_number;
    unsigned last_program_number;
    unsigned offset_to_bytecode;
    unsigned offset_to_interpolation_patch_table;
    int has_lfo;
    int memory_shift;
    const char **effect_names;
    //void (*effect)(implementation);
};

static const char *names_midiverb[] = {
#include "names-midiverb.h"
};
static const char *names_midifex[] = {
#include "names-midifex.h"
};
static const char *names_midiverb2[] = {
#include "names-midiverb2.h"
};

static RomType rom_types[] = {
    { "MidiVerb",   16384,  { 0xff, 0x3c, 0x44, 0x3e }, 1, 64, 0,	0,	0, 2, names_midiverb },
    { "MidiFex",    16384,  { 0x00, 0x00, 0xcd, 0x3f }, 1, 64, 0,	0,	0, 2, names_midifex, },
    { "MidiVerb 2", 32768,  { 0x02, 0x00, 0xee, 0x00 }, 0, 99, 0x1c00,	0x1b00, 1, 1, names_midiverb2, },
};
