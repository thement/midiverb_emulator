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
    int numEffects;     // Number of effects
    int displayOffset;  // Added to 0-based index for display (1 for MIDIVerb/MidiFex, 0 for MIDIVerb 2)
    const char** effectNames;
    void (**effects)(int16_t input, int16_t *out_left, int16_t *out_right, int16_t *DRAM, int ptr);
};

static const DeviceInfo devices[] = {
    { "MIDIVerb",   64,  1, names_midiverb,  midiverb_effects },
    { "MidiFex",    64,  1, names_midifex,   midifex_effects },
    { "MIDIVerb 2", 100, 0, names_midiverb2, midiverb2_effects },
};

static constexpr int NUM_DEVICES = 3;
