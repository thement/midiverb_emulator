#pragma once

#include <cstdint>

// Include the generated effects from the parent directory
#include "../../decompiled-midiverb.h"
#include "../../decompiled-midifex.h"
#include "../../decompiled-midiverb2.h"

// Effect names
static const char* names_midiverb[] = {
#include "../../names-midiverb.h"
};

static const char* names_midifex[] = {
#include "../../names-midifex.h"
};

static const char* names_midiverb2[] = {
#include "../../names-midiverb2.h"
};

// Device info structure
struct DeviceInfo {
    const char* name;
    int firstProgram;   // First valid program number (0 or 1)
    int lastProgram;    // Last valid program number
    const char** effectNames;
    void (**effects)(int16_t input, int16_t *out_left, int16_t *out_right, int16_t *DRAM, int ptr);
};

static const DeviceInfo devices[] = {
    { "MIDIVerb",   1, 64, names_midiverb,  midiverb_effects },
    { "MidiFex",    1, 64, names_midifex,   midifex_effects },
    { "MIDIVerb 2", 0, 99, names_midiverb2, midiverb2_effects },
};

static constexpr int NUM_DEVICES = 3;
