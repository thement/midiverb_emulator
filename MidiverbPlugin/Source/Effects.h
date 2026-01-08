#pragma once

#include <cstdint>

// Include the generated effects from the parent directory (int16_t version)
#include "../../decompiled-midiverb.h"
#include "../../decompiled-midifex.h"
#include "../../decompiled-midiverb2.h"

// Include float versions for hi-quality mode
#include "../../decompiled-midiverb-float.h"
#include "../../decompiled-midifex-float.h"
#include "../../decompiled-midiverb2-float.h"

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

// Function pointer types for int16 and float effects
using EffectFn16 = void (*)(int16_t input, int16_t *out_left, int16_t *out_right, int16_t *DRAM, int ptr);
using EffectFnFloat = void (*)(float input, float *out_left, float *out_right, float *DRAM, int ptr);

// Device info structure (templated for different sample types)
struct DeviceInfo {
    const char* name;
    int numEffects;     // Number of effects
    int displayOffset;  // Added to 0-based index for display (1 for MIDIVerb/MidiFex, 0 for MIDIVerb 2)
    const char** effectNames;
    EffectFn16 *effects;        // int16_t version
    EffectFnFloat *effectsFloat; // float version
};

static const DeviceInfo devices[] = {
    { "MIDIVerb",   64,  1, names_midiverb,  midiverb_effects,  midiverb_f_effects },
    { "MidiFex",    64,  1, names_midifex,   midifex_effects,   midifex_f_effects },
    { "MIDIVerb 2", 100, 0, names_midiverb2, midiverb2_effects, midiverb2_f_effects },
};

static constexpr int NUM_DEVICES = 3;
