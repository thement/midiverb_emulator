# Midiverb Test Suite

## Running Tests

```bash
pip install pytest numpy scipy
pytest tests/ -v
```

## Test Input Signals

- **sine (49%)**: stereo, L=440Hz R=1700Hz, 49% amplitude, 24kHz, 16-bit
- **sine (25%)**: stereo, L=440Hz R=1700Hz, 25% amplitude, 24kHz, 16-bit
- **noise**: stereo white noise, 49% amplitude, 24kHz, 16-bit

Fixtures auto-generated in `tests/fixtures/` on first run.

## Tests

### test_defeat.py
- **defeat programs output silence**: midiverb/midifex prog 64, midiverb2 prog 0
- **non-defeat programs produce output**: all other programs (max amplitude > 100)

### test_clipping.py
- **25% sine: no effects clip**: all effects should have headroom at 25% input
- **49% sine: only listed effects clip**: only MidiFex 34 (~3000 samples) and MidiVerb 2 27 (~4700 samples) should clip
- **known clipping effects verified**: listed effects must actually clip

### test_decompiled_vs_emulated.py
- **outputs match**: decompiled vs emulated should differ by <10%
- reports programs with >2% difference
- skips MidiVerb 2 LFO programs (50-69)

### test_harmonics.py
- **clean sine has low 3rd harmonic**: ratio < 0.01
- **clipped sine has high 3rd harmonic**: ratio > 0.05 (validates detection)
- **no internal clipping**: effects shouldn't have strong 3rd harmonic (>15%)

## Known Clipping Effects (49% sine)

| Model | Prog | Samples |
|-------|------|---------|
| MidiFex | 34 | ~3000 |
| MidiVerb 2 | 27 | ~4700 |

## Models & Programs

| Model | Programs | Defeat |
|-------|----------|--------|
| MidiVerb | 1-64 | 64 |
| MidiFex | 1-64 | 64 |
| MidiVerb 2 | 0-99 | 0 |

MidiVerb 2 programs 50-69 use LFO (emulated mode only).
