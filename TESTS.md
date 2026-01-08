# Midiverb Test Suite

## Running Tests

```bash
# Install dependencies
pip install pytest numpy scipy

# Run all tests
pytest tests/ -v

# Run with output (shows which programs clip, etc.)
pytest tests/ -v -s

# Run specific test file
pytest tests/test_defeat.py -v
```

## Test Input Signals

- **sine**: stereo, L=440Hz R=1700Hz, 49% amplitude, 24kHz, 16-bit
- **noise**: stereo white noise, 49% amplitude, 24kHz, 16-bit

Fixture WAVs are auto-generated in `tests/fixtures/` on first run.

## Tests

### test_defeat.py
- **defeat programs output silence**: midiverb/midifex prog 64, midiverb2 prog 0 should output silence when fed non-silent input
- **non-defeat programs produce output**: all other programs should produce audible output (max amplitude > 100)

### test_clipping.py
- **clipping with sine/noise**: report programs that clip >100 samples, assert <30% of programs clip
- tests both emulated (ROM) and decompiled modes

### test_decompiled_vs_emulated.py
- **outputs match**: decompiled and emulated should differ by <10% of max amplitude
- reports programs with >2% difference
- skips MidiVerb 2 LFO programs (50-69) which don't work in decompiled mode

### test_harmonics.py
- **clean sine has low 3rd harmonic**: verify detection method works (ratio < 0.01)
- **clipped sine has high 3rd harmonic**: verify clipped signal is detected (ratio > 0.05)
- **no internal clipping**: effects shouldn't have strong 3rd harmonic (>15%) indicating internal clipping
- skips programs that clip externally or output silence

## Models & Programs

| Model | Programs | Defeat |
|-------|----------|--------|
| MidiVerb | 1-64 | 64 |
| MidiFex | 1-64 | 64 |
| MidiVerb 2 | 0-99 | 0 |

MidiVerb 2 programs 50-69 use LFO and only work in emulated mode.
