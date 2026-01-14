#pragma once

// Provide ARRAY_SIZE macro needed by lfo.h
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif

#include <cassert>
#include <cstdint>

// Include the original LFO implementation
#include "../../lfo.h"
