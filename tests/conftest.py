"""
Test fixtures and utilities for midiverb tests.
"""
import numpy as np
from scipy.io import wavfile
import subprocess
import pytest
import os

# Test parameters
SAMPLE_RATE = 24000  # 24 KHz as specified
DURATION = 2.0       # seconds
AMPLITUDE = 0.49     # 49% of max amplitude

# Models configuration
# Keys are the CLI model names (case-insensitive), used with -m flag
MODELS = {
    'MidiVerb':   {'rom': 'roms/midiverb.rom',  'range': (1, 64),  'defeat': 64},
    'MidiFex':    {'rom': 'roms/midifex.rom',   'range': (1, 64),  'defeat': 64},
    'MidiVerb 2': {'rom': 'roms/midiverb2.rom', 'range': (0, 99),  'defeat': 0},
}

# Get project root (parent of tests/)
PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# Fixed paths for test input files (in tests/fixtures/)
FIXTURES_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'fixtures')
SINE_WAV_PATH = os.path.join(FIXTURES_DIR, 'sine_440_1700.wav')  # 49% amplitude
SINE_25_WAV_PATH = os.path.join(FIXTURES_DIR, 'sine_440_1700_25pct.wav')  # 25% amplitude
NOISE_WAV_PATH = os.path.join(FIXTURES_DIR, 'noise.wav')


def generate_sine_wav(path, sample_rate=SAMPLE_RATE, duration=DURATION, amplitude=AMPLITUDE):
    """Generate stereo sine: L=440Hz, R=1700Hz at specified amplitude"""
    num_samples = int(sample_rate * duration)
    t = np.linspace(0, duration, num_samples, endpoint=False)
    left = (amplitude * 32767 * np.sin(2 * np.pi * 440 * t)).astype(np.int16)
    right = (amplitude * 32767 * np.sin(2 * np.pi * 1700 * t)).astype(np.int16)
    stereo = np.column_stack((left, right))
    wavfile.write(str(path), sample_rate, stereo)
    return path


def generate_noise_wav(path, sample_rate=SAMPLE_RATE, duration=DURATION, amplitude=AMPLITUDE):
    """Generate stereo white noise at specified amplitude"""
    num_samples = int(sample_rate * duration)
    np.random.seed(42)  # Reproducible noise
    left = (amplitude * 32767 * (2 * np.random.random(num_samples) - 1)).astype(np.int16)
    right = (amplitude * 32767 * (2 * np.random.random(num_samples) - 1)).astype(np.int16)
    stereo = np.column_stack((left, right))
    wavfile.write(str(path), sample_rate, stereo)
    return path


def _ensure_fixture_files():
    """Ensure fixture WAV files exist, creating them if needed."""
    os.makedirs(FIXTURES_DIR, exist_ok=True)

    if not os.path.exists(SINE_WAV_PATH):
        generate_sine_wav(SINE_WAV_PATH, amplitude=0.49)

    if not os.path.exists(SINE_25_WAV_PATH):
        generate_sine_wav(SINE_25_WAV_PATH, amplitude=0.25)

    if not os.path.exists(NOISE_WAV_PATH):
        generate_noise_wav(NOISE_WAV_PATH)


# Generate fixtures on module load
_ensure_fixture_files()


@pytest.fixture(scope="session")
def sine_wav():
    """Return path to stereo sine WAV: L=440Hz, R=1700Hz at 49% amplitude"""
    _ensure_fixture_files()
    return SINE_WAV_PATH


@pytest.fixture(scope="session")
def sine_wav_25():
    """Return path to stereo sine WAV: L=440Hz, R=1700Hz at 25% amplitude"""
    _ensure_fixture_files()
    return SINE_25_WAV_PATH


@pytest.fixture(scope="session")
def noise_wav():
    """Return path to stereo white noise WAV at 49% amplitude"""
    _ensure_fixture_files()
    return NOISE_WAV_PATH


def run_midiverb(prog, input_wav, output_wav, rom=None, model=None):
    """
    Run midiverb CLI and return output samples.

    Args:
        prog: Program number
        input_wav: Path to input WAV file
        output_wav: Path for output WAV file
        rom: Path to ROM file (for emulated mode)
        model: Model name (for decompiled mode)

    Returns:
        numpy array of output samples (stereo, int16)
    """
    midiverb_path = os.path.join(PROJECT_ROOT, "midiverb")
    cmd = [midiverb_path]

    if rom:
        rom_path = os.path.join(PROJECT_ROOT, rom)
        cmd += ["-r", rom_path]
    elif model:
        cmd += ["-m", model]

    cmd += [str(prog), str(input_wav), str(output_wav)]

    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        raise RuntimeError(f"midiverb failed: {result.stderr}")

    _, data = wavfile.read(str(output_wav))
    return data


def count_clipped_samples(data, threshold=32760):
    """
    Count samples near INT16_MAX/MIN (clipping).

    Args:
        data: numpy array of samples
        threshold: amplitude threshold to consider as clipped

    Returns:
        Number of clipped samples
    """
    return int(np.sum(np.abs(data) >= threshold))


def get_max_amplitude(data):
    """Get maximum absolute amplitude from sample data."""
    return int(np.max(np.abs(data)))


def get_rms_amplitude(data):
    """Get RMS amplitude from sample data."""
    return float(np.sqrt(np.mean(data.astype(np.float64) ** 2)))
