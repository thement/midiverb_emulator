"""
Tests for clipping behavior.

Most programs should not clip when fed with 49% amplitude input.
Programs that clip >100 samples are reported.
"""
import pytest
from conftest import MODELS, run_midiverb, count_clipped_samples


# Threshold for "significant" clipping
CLIP_SAMPLE_THRESHOLD = 100

# Maximum acceptable ratio of programs that clip
MAX_CLIP_RATIO = 0.3  # 30%


class TestClippingSine:
    """Test clipping with sine wave input."""

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_clipping_sine_emulated(self, model_name, config, sine_wav, tmp_path):
        """Report programs that clip with sine input (emulated mode)."""
        clipping_programs = []
        first, last = config['range']

        for prog in range(first, last + 1):
            output = tmp_path / f"out_{prog}.wav"
            data = run_midiverb(prog, sine_wav, output, rom=config['rom'])
            clipped = count_clipped_samples(data)
            if clipped > CLIP_SAMPLE_THRESHOLD:
                clipping_programs.append((prog, clipped))

        # Report clipping programs
        if clipping_programs:
            print(f"\n{model_name} (emulated) programs clipping with sine:")
            for prog, count in clipping_programs:
                print(f"  prog {prog}: {count} clipped samples")

        # Assert most don't clip
        total_programs = last - first + 1
        clip_ratio = len(clipping_programs) / total_programs
        assert clip_ratio < MAX_CLIP_RATIO, \
            f"{model_name} (emulated): too many programs clip with sine ({len(clipping_programs)}/{total_programs} = {clip_ratio*100:.0f}%)"

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_clipping_sine_decompiled(self, model_name, config, sine_wav, tmp_path):
        """Report programs that clip with sine input (decompiled mode)."""
        clipping_programs = []
        first, last = config['range']

        for prog in range(first, last + 1):
            output = tmp_path / f"out_{prog}.wav"
            data = run_midiverb(prog, sine_wav, output, model=model_name)
            clipped = count_clipped_samples(data)
            if clipped > CLIP_SAMPLE_THRESHOLD:
                clipping_programs.append((prog, clipped))

        # Report clipping programs
        if clipping_programs:
            print(f"\n{model_name} (decompiled) programs clipping with sine:")
            for prog, count in clipping_programs:
                print(f"  prog {prog}: {count} clipped samples")

        # Assert most don't clip
        total_programs = last - first + 1
        clip_ratio = len(clipping_programs) / total_programs
        assert clip_ratio < MAX_CLIP_RATIO, \
            f"{model_name} (decompiled): too many programs clip with sine ({len(clipping_programs)}/{total_programs} = {clip_ratio*100:.0f}%)"


class TestClippingNoise:
    """Test clipping with noise input."""

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_clipping_noise_emulated(self, model_name, config, noise_wav, tmp_path):
        """Report programs that clip with noise input (emulated mode)."""
        clipping_programs = []
        first, last = config['range']

        for prog in range(first, last + 1):
            output = tmp_path / f"out_{prog}.wav"
            data = run_midiverb(prog, noise_wav, output, rom=config['rom'])
            clipped = count_clipped_samples(data)
            if clipped > CLIP_SAMPLE_THRESHOLD:
                clipping_programs.append((prog, clipped))

        # Report clipping programs
        if clipping_programs:
            print(f"\n{model_name} (emulated) programs clipping with noise:")
            for prog, count in clipping_programs:
                print(f"  prog {prog}: {count} clipped samples")

        # Assert most don't clip
        total_programs = last - first + 1
        clip_ratio = len(clipping_programs) / total_programs
        assert clip_ratio < MAX_CLIP_RATIO, \
            f"{model_name} (emulated): too many programs clip with noise ({len(clipping_programs)}/{total_programs} = {clip_ratio*100:.0f}%)"

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_clipping_noise_decompiled(self, model_name, config, noise_wav, tmp_path):
        """Report programs that clip with noise input (decompiled mode)."""
        clipping_programs = []
        first, last = config['range']

        for prog in range(first, last + 1):
            output = tmp_path / f"out_{prog}.wav"
            data = run_midiverb(prog, noise_wav, output, model=model_name)
            clipped = count_clipped_samples(data)
            if clipped > CLIP_SAMPLE_THRESHOLD:
                clipping_programs.append((prog, clipped))

        # Report clipping programs
        if clipping_programs:
            print(f"\n{model_name} (decompiled) programs clipping with noise:")
            for prog, count in clipping_programs:
                print(f"  prog {prog}: {count} clipped samples")

        # Assert most don't clip
        total_programs = last - first + 1
        clip_ratio = len(clipping_programs) / total_programs
        assert clip_ratio < MAX_CLIP_RATIO, \
            f"{model_name} (decompiled): too many programs clip with noise ({len(clipping_programs)}/{total_programs} = {clip_ratio*100:.0f}%)"
