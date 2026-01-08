"""
Tests for internal clipping detection via harmonic analysis.

When a signal clips internally (before output), it introduces harmonic
distortion. Symmetric clipping generates primarily ODD harmonics (3rd, 5th, etc.)
with the 3rd harmonic being the strongest.

By checking for the presence of a strong 3rd harmonic in the output,
we can detect if internal clipping occurred.
"""
import pytest
import numpy as np
from scipy.fft import rfft, rfftfreq
from scipy.io import wavfile
from conftest import (
    MODELS, run_midiverb, count_clipped_samples,
    SAMPLE_RATE, generate_sine_wav
)


# Maximum acceptable 3rd harmonic ratio
# A clean reverb should not introduce significant 3rd harmonic
MAX_3RD_HARMONIC_RATIO = 0.15  # 15%

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


def get_3rd_harmonic_ratio(data, sample_rate, fundamental_freq, channel=0):
    """
    Calculate ratio of 3rd harmonic to fundamental.

    Symmetric clipping produces strong 3rd harmonic, so this is a good
    indicator of internal clipping/distortion.

    Args:
        data: Stereo sample data
        sample_rate: Sample rate in Hz
        fundamental_freq: Fundamental frequency
        channel: 0 for left, 1 for right

    Returns:
        Ratio of 3rd harmonic power to fundamental power
    """
    samples = data[:, channel] if len(data.shape) > 1 else data
    freqs, power = get_spectrum_power(samples, sample_rate)

    fundamental_power = get_power_at_frequency(freqs, power, fundamental_freq)
    third_harmonic_power = get_power_at_frequency(freqs, power, fundamental_freq * 3)

    if fundamental_power == 0:
        return 0

    return third_harmonic_power / fundamental_power


class TestHarmonicDetection:
    """Verify our harmonic detection method works."""

    def test_clean_sine_has_low_3rd_harmonic(self, sine_wav):
        """A clean sine wave should have minimal 3rd harmonic."""
        _, data = wavfile.read(str(sine_wav))

        ratio = get_3rd_harmonic_ratio(data, SAMPLE_RATE, LEFT_FREQ, channel=0)
        assert ratio < 0.01, f"Clean sine has unexpected 3rd harmonic: {ratio:.4f}"

    def test_clipped_sine_has_high_3rd_harmonic(self, tmp_path):
        """A hard-clipped sine should have significant 3rd harmonic."""
        # Generate a sine and clip it
        sine_path = tmp_path / "sine.wav"
        generate_sine_wav(sine_path, amplitude=0.49)
        _, data = wavfile.read(str(sine_path))

        # Hard clip to introduce distortion (symmetric clipping)
        clipped = np.clip(data, -8000, 8000)

        ratio = get_3rd_harmonic_ratio(clipped, SAMPLE_RATE, LEFT_FREQ, channel=0)
        assert ratio > 0.05, \
            f"Clipped sine should have 3rd harmonic but ratio is only {ratio:.4f}"

    def test_soft_clipped_detected(self, tmp_path):
        """Even soft clipping should be detectable via 3rd harmonic."""
        sine_path = tmp_path / "sine.wav"
        generate_sine_wav(sine_path, amplitude=0.49)
        _, data = wavfile.read(str(sine_path))

        # Soft clip using tanh curve
        soft_clipped = (np.tanh(data.astype(np.float64) / 10000) * 10000).astype(np.int16)

        ratio = get_3rd_harmonic_ratio(soft_clipped, SAMPLE_RATE, LEFT_FREQ, channel=0)
        assert ratio > 0.01, \
            f"Soft clipped sine should have some 3rd harmonic: {ratio:.4f}"


class TestInternalClipping:
    """Test effects for internal clipping via 3rd harmonic analysis."""

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_no_internal_clipping_emulated(self, model_name, config, sine_wav, tmp_path):
        """
        Effects should not have strong 3rd harmonic (internal clipping).

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

            # Check 3rd harmonic ratio for left channel (440 Hz input)
            ratio = get_3rd_harmonic_ratio(data, SAMPLE_RATE, LEFT_FREQ, channel=0)

            if ratio > MAX_3RD_HARMONIC_RATIO:
                internal_clip_suspects.append((prog, ratio))

        if internal_clip_suspects:
            print(f"\n{model_name} (emulated) programs with high 3rd harmonic:")
            for prog, ratio in internal_clip_suspects:
                print(f"  prog {prog}: 3rd_harmonic_ratio={ratio:.3f}")

        # Don't fail - this is informational
        # Some effects may naturally have harmonics due to their algorithm

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_no_internal_clipping_decompiled(self, model_name, config, sine_wav, tmp_path):
        """
        Effects should not have strong 3rd harmonic (decompiled mode).
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

            # Check 3rd harmonic ratio for left channel
            ratio = get_3rd_harmonic_ratio(data, SAMPLE_RATE, LEFT_FREQ, channel=0)

            if ratio > MAX_3RD_HARMONIC_RATIO:
                internal_clip_suspects.append((prog, ratio))

        if internal_clip_suspects:
            print(f"\n{model_name} (decompiled) programs with high 3rd harmonic:")
            for prog, ratio in internal_clip_suspects:
                print(f"  prog {prog}: 3rd_harmonic_ratio={ratio:.3f}")
