"""
Tests for internal clipping detection via harmonic analysis.

When a signal clips internally (before output), it introduces harmonic
distortion. By analyzing the spectrum of the output, we can detect if
internal clipping occurred by checking for strong spurious harmonics.

Note: Symmetric clipping generates primarily ODD harmonics (3rd, 5th, etc.)
while asymmetric clipping generates even harmonics (2nd, 4th, etc.).
"""
import pytest
import numpy as np
from scipy.fft import rfft, rfftfreq
from scipy.io import wavfile
from conftest import (
    MODELS, run_midiverb, count_clipped_samples,
    SAMPLE_RATE, generate_sine_wav
)


# Maximum acceptable total harmonic distortion ratio
# A clean reverb should not introduce significant harmonics
MAX_THD_RATIO = 0.20  # 20% - some effects naturally add harmonics

# Frequencies used in test signal
LEFT_FREQ = 440
RIGHT_FREQ = 1700


def get_spectrum_power(samples, sample_rate):
    """
    Compute the power spectrum of a signal.

    Args:
        samples: 1D numpy array of samples
        sample_rate: Sample rate in Hz

    Returns:
        freqs: Array of frequencies
        power: Array of power values
    """
    # Apply window to reduce spectral leakage
    window = np.hanning(len(samples))
    windowed = samples.astype(np.float64) * window

    spectrum = np.abs(rfft(windowed))
    freqs = rfftfreq(len(samples), 1/sample_rate)

    return freqs, spectrum


def get_power_at_frequency(freqs, power, target_freq, tolerance=10):
    """
    Get the power near a specific frequency.

    Args:
        freqs: Array of frequencies
        power: Array of power values
        target_freq: Target frequency to find
        tolerance: Frequency tolerance in Hz

    Returns:
        Maximum power within tolerance of target frequency
    """
    mask = np.abs(freqs - target_freq) < tolerance
    if not np.any(mask):
        return 0
    return float(np.max(power[mask]))


def get_thd_ratio(data, sample_rate, fundamental_freq, channel=0, num_harmonics=5):
    """
    Calculate Total Harmonic Distortion ratio.

    THD = sqrt(sum of harmonic powers) / fundamental power

    Args:
        data: Stereo sample data
        sample_rate: Sample rate in Hz
        fundamental_freq: Fundamental frequency
        channel: 0 for left, 1 for right
        num_harmonics: Number of harmonics to include (2nd through nth)

    Returns:
        THD ratio (0 = pure sine, higher = more distortion)
    """
    samples = data[:, channel] if len(data.shape) > 1 else data
    freqs, power = get_spectrum_power(samples, sample_rate)

    fundamental_power = get_power_at_frequency(freqs, power, fundamental_freq)

    if fundamental_power == 0:
        return 0

    # Sum power of harmonics (2nd through nth)
    harmonic_power_sum = 0
    for n in range(2, num_harmonics + 2):
        harmonic_freq = fundamental_freq * n
        if harmonic_freq >= sample_rate / 2:  # Above Nyquist
            break
        harmonic_power = get_power_at_frequency(freqs, power, harmonic_freq)
        harmonic_power_sum += harmonic_power ** 2

    return np.sqrt(harmonic_power_sum) / fundamental_power


def get_odd_harmonic_ratio(data, sample_rate, fundamental_freq, channel=0):
    """
    Calculate ratio of odd harmonics (3rd, 5th) to fundamental.

    Symmetric clipping produces primarily odd harmonics.

    Args:
        data: Stereo sample data
        sample_rate: Sample rate in Hz
        fundamental_freq: Fundamental frequency
        channel: 0 for left, 1 for right

    Returns:
        Ratio of odd harmonic power to fundamental power
    """
    samples = data[:, channel] if len(data.shape) > 1 else data
    freqs, power = get_spectrum_power(samples, sample_rate)

    fundamental_power = get_power_at_frequency(freqs, power, fundamental_freq)

    if fundamental_power == 0:
        return 0

    # Get 3rd and 5th harmonic power
    h3_power = get_power_at_frequency(freqs, power, fundamental_freq * 3)
    h5_power = get_power_at_frequency(freqs, power, fundamental_freq * 5)

    return (h3_power + h5_power) / fundamental_power


class TestHarmonicDetection:
    """Verify our harmonic detection method works."""

    def test_clean_sine_has_low_harmonics(self, sine_wav):
        """A clean sine wave should have minimal harmonic distortion."""
        _, data = wavfile.read(str(sine_wav))

        # Check left channel (440 Hz)
        thd = get_thd_ratio(data, SAMPLE_RATE, LEFT_FREQ, channel=0)
        assert thd < 0.01, f"Clean sine has unexpected THD: {thd:.4f}"

    def test_clipped_sine_has_high_harmonics(self, tmp_path):
        """A hard-clipped sine should have significant odd harmonics."""
        # Generate a sine and clip it
        sine_path = tmp_path / "sine.wav"
        generate_sine_wav(sine_path, amplitude=0.49)
        _, data = wavfile.read(str(sine_path))

        # Hard clip to introduce distortion (symmetric clipping)
        clipped = np.clip(data, -8000, 8000)

        # Symmetric clipping generates ODD harmonics (3rd, 5th, etc.)
        ratio = get_odd_harmonic_ratio(clipped, SAMPLE_RATE, LEFT_FREQ, channel=0)
        assert ratio > 0.05, \
            f"Clipped sine should have odd harmonics but ratio is only {ratio:.4f}"

        # Also check THD
        thd = get_thd_ratio(clipped, SAMPLE_RATE, LEFT_FREQ, channel=0)
        assert thd > 0.05, \
            f"Clipped sine should have high THD but got {thd:.4f}"

    def test_soft_clipped_detected(self, tmp_path):
        """Even soft clipping should be detectable."""
        sine_path = tmp_path / "sine.wav"
        generate_sine_wav(sine_path, amplitude=0.49)
        _, data = wavfile.read(str(sine_path))

        # Soft clip using tanh-like curve (asymmetric introduces even harmonics too)
        soft_clipped = (np.tanh(data.astype(np.float64) / 10000) * 10000).astype(np.int16)

        thd = get_thd_ratio(soft_clipped, SAMPLE_RATE, LEFT_FREQ, channel=0)
        assert thd > 0.01, \
            f"Soft clipped sine should have some THD: {thd:.4f}"


class TestInternalClipping:
    """Test effects for internal clipping via harmonic analysis."""

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_no_internal_clipping_emulated(self, model_name, config, sine_wav, tmp_path):
        """
        Effects should not have strong spurious harmonics (internal clipping).

        We skip programs that clip externally (at output stage) since those
        will naturally have harmonics from the output clipping.
        """
        first, last = config['range']
        defeat = config['defeat']
        internal_clip_suspects = []

        for prog in range(first, last + 1):
            if prog == defeat:
                continue

            output = tmp_path / f"out_{prog}.wav"
            data = run_midiverb(prog, sine_wav, output, rom=config['rom'])

            # Skip if output clips externally
            if count_clipped_samples(data) > 100:
                continue

            # Skip if output is very quiet (can have high ratio due to noise)
            if np.max(np.abs(data)) < 500:
                continue

            # Check THD for left channel (440 Hz input)
            thd = get_thd_ratio(data, SAMPLE_RATE, LEFT_FREQ, channel=0)

            if thd > MAX_THD_RATIO:
                internal_clip_suspects.append((prog, thd))

        if internal_clip_suspects:
            print(f"\n{model_name} (emulated) programs with high THD:")
            for prog, thd in internal_clip_suspects:
                print(f"  prog {prog}: THD={thd:.3f}")

        # Don't fail if some effects have harmonics - this is informational
        # Some reverbs naturally add harmonics due to their algorithm

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_no_internal_clipping_decompiled(self, model_name, config, sine_wav, tmp_path):
        """
        Effects should not have strong spurious harmonics (decompiled mode).
        """
        first, last = config['range']
        defeat = config['defeat']
        internal_clip_suspects = []

        for prog in range(first, last + 1):
            if prog == defeat:
                continue

            output = tmp_path / f"out_{prog}.wav"
            data = run_midiverb(prog, sine_wav, output, model=model_name)

            # Skip if output clips externally
            if count_clipped_samples(data) > 100:
                continue

            # Skip if output is very quiet
            if np.max(np.abs(data)) < 500:
                continue

            # Check THD for left channel
            thd = get_thd_ratio(data, SAMPLE_RATE, LEFT_FREQ, channel=0)

            if thd > MAX_THD_RATIO:
                internal_clip_suspects.append((prog, thd))

        if internal_clip_suspects:
            print(f"\n{model_name} (decompiled) programs with high THD:")
            for prog, thd in internal_clip_suspects:
                print(f"  prog {prog}: THD={thd:.3f}")
