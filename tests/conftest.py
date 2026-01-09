"""
Test fixtures and utilities for midiverb tests.
"""
import numpy as np
from scipy.io import wavfile
import subprocess
import pytest
import os
import tempfile

# Test parameters
SAMPLE_RATE = 24000  # 24 KHz as specified
DURATION = 2.0       # seconds
EXPECTED_SAMPLES = int(SAMPLE_RATE * DURATION)  # 48000 samples

# Models configuration
MODELS = {
    'MidiVerb':   {'rom': 'roms/midiverb.rom',  'range': (1, 64),  'defeat': 64},
    'MidiFex':    {'rom': 'roms/midifex.rom',   'range': (1, 64),  'defeat': 64},
    'MidiVerb 2': {'rom': 'roms/midiverb2.rom', 'range': (0, 99),  'defeat': 0},
}

PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FIXTURES_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'fixtures')
SINE_WAV_PATH = os.path.join(FIXTURES_DIR, 'sine_440_1700.wav')
SINE_25_WAV_PATH = os.path.join(FIXTURES_DIR, 'sine_440_1700_25pct.wav')
NOISE_WAV_PATH = os.path.join(FIXTURES_DIR, 'noise.wav')


def _is_valid_wav(path):
    """Check if WAV file exists and is valid."""
    if not os.path.exists(path):
        return False
    try:
        rate, data = wavfile.read(path)
        return (rate == SAMPLE_RATE and
                len(data.shape) == 2 and
                data.shape[1] == 2 and
                data.shape[0] == EXPECTED_SAMPLES)
    except Exception:
        return False


def _generate_sine(path, amplitude):
    """Generate stereo sine: L=440Hz, R=1700Hz"""
    t = np.linspace(0, DURATION, EXPECTED_SAMPLES, endpoint=False)
    left = (amplitude * 32767 * np.sin(2 * np.pi * 440 * t)).astype(np.int16)
    right = (amplitude * 32767 * np.sin(2 * np.pi * 1700 * t)).astype(np.int16)
    stereo = np.column_stack((left, right))
    wavfile.write(path, SAMPLE_RATE, stereo)


def _generate_noise(path, amplitude):
    """Generate stereo white noise"""
    np.random.seed(42)
    left = (amplitude * 32767 * (2 * np.random.random(EXPECTED_SAMPLES) - 1)).astype(np.int16)
    right = (amplitude * 32767 * (2 * np.random.random(EXPECTED_SAMPLES) - 1)).astype(np.int16)
    stereo = np.column_stack((left, right))
    wavfile.write(path, SAMPLE_RATE, stereo)


def _ensure_wav(path, generate_func):
    """Ensure WAV exists, generate atomically if not."""
    if _is_valid_wav(path):
        return path

    os.makedirs(os.path.dirname(path), exist_ok=True)

    # Generate to temp, then atomic rename
    fd, tmp_path = tempfile.mkstemp(suffix='.wav', dir=os.path.dirname(path))
    os.close(fd)
    generate_func(tmp_path)
    os.rename(tmp_path, path)  # atomic on same filesystem

    return path


# Public function used by test_harmonics.py
def generate_sine_wav(path, sample_rate=SAMPLE_RATE, duration=DURATION, amplitude=0.49):
    """Generate stereo sine: L=440Hz, R=1700Hz at specified amplitude"""
    num_samples = int(sample_rate * duration)
    t = np.linspace(0, duration, num_samples, endpoint=False)
    left = (amplitude * 32767 * np.sin(2 * np.pi * 440 * t)).astype(np.int16)
    right = (amplitude * 32767 * np.sin(2 * np.pi * 1700 * t)).astype(np.int16)
    stereo = np.column_stack((left, right))
    wavfile.write(str(path), sample_rate, stereo)
    return path


@pytest.fixture(scope="session")
def sine_wav():
    return _ensure_wav(SINE_WAV_PATH, lambda p: _generate_sine(p, 0.49))


@pytest.fixture(scope="session")
def sine_wav_25():
    return _ensure_wav(SINE_25_WAV_PATH, lambda p: _generate_sine(p, 0.25))


@pytest.fixture(scope="session")
def noise_wav():
    return _ensure_wav(NOISE_WAV_PATH, lambda p: _generate_noise(p, 0.49))


def run_midiverb(prog, input_wav, output_wav, rom=None, model=None):
    """Run midiverb CLI and return output samples."""
    midiverb_path = os.path.join(PROJECT_ROOT, "midiverb")
    cmd = [midiverb_path]

    if rom:
        cmd += ["-r", os.path.join(PROJECT_ROOT, rom)]
    elif model:
        cmd += ["-m", model]

    cmd += [str(prog), str(input_wav), str(output_wav)]

    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        raise RuntimeError(f"midiverb failed: {result.stderr}")

    _, data = wavfile.read(str(output_wav))
    return data


def count_clipped_samples(data, threshold=32760):
    return int(np.sum(np.abs(data) >= threshold))


def get_max_amplitude(data):
    return int(np.max(np.abs(data)))
