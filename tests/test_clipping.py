"""
Tests for clipping behavior.

- At 25% amplitude sine: no effects should clip
- At 49% amplitude sine: only explicitly listed effects should clip
"""
import pytest
from conftest import MODELS, run_midiverb, count_clipped_samples


# Threshold for "significant" clipping
CLIP_SAMPLE_THRESHOLD = 100

# Effects known to clip at 49% sine input
# Format: {(model_name, prog): min_expected_clips}
KNOWN_CLIPPING_49PCT = {
    ('MidiFex', 34): 2000,      # ~3000 samples
    ('MidiVerb 2', 27): 4000,   # ~4700 samples (decompiled only, but we test both)
}


class TestClipping25Percent:
    """At 25% amplitude, no effects should clip."""

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_no_clipping_at_25pct_emulated(self, model_name, config, sine_wav_25, tmp_path):
        """No effects should clip at 25% amplitude (emulated mode)."""
        first, last = config['range']
        clipping = []

        for prog in range(first, last + 1):
            output = tmp_path / f"out_{prog}.wav"
            data = run_midiverb(prog, sine_wav_25, output, rom=config['rom'])
            clipped = count_clipped_samples(data)
            if clipped > CLIP_SAMPLE_THRESHOLD:
                clipping.append((prog, clipped))

        if clipping:
            msg = f"{model_name} (emulated) programs clipping at 25%:\n"
            for prog, count in clipping:
                msg += f"  prog {prog}: {count} samples\n"
            pytest.fail(msg)

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_no_clipping_at_25pct_decompiled(self, model_name, config, sine_wav_25, tmp_path):
        """No effects should clip at 25% amplitude (decompiled mode)."""
        first, last = config['range']
        clipping = []

        for prog in range(first, last + 1):
            output = tmp_path / f"out_{prog}.wav"
            data = run_midiverb(prog, sine_wav_25, output, model=model_name)
            clipped = count_clipped_samples(data)
            if clipped > CLIP_SAMPLE_THRESHOLD:
                clipping.append((prog, clipped))

        if clipping:
            msg = f"{model_name} (decompiled) programs clipping at 25%:\n"
            for prog, count in clipping:
                msg += f"  prog {prog}: {count} samples\n"
            pytest.fail(msg)


class TestClipping49Percent:
    """At 49% amplitude, only known effects should clip."""

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_only_known_effects_clip_emulated(self, model_name, config, sine_wav, tmp_path):
        """Only explicitly listed effects should clip at 49% (emulated mode)."""
        first, last = config['range']
        unexpected_clipping = []

        for prog in range(first, last + 1):
            output = tmp_path / f"out_{prog}.wav"
            data = run_midiverb(prog, sine_wav, output, rom=config['rom'])
            clipped = count_clipped_samples(data)

            is_known = (model_name, prog) in KNOWN_CLIPPING_49PCT

            if clipped > CLIP_SAMPLE_THRESHOLD and not is_known:
                unexpected_clipping.append((prog, clipped))

        if unexpected_clipping:
            msg = f"{model_name} (emulated) unexpected clipping at 49%:\n"
            for prog, count in unexpected_clipping:
                msg += f"  prog {prog}: {count} samples\n"
            pytest.fail(msg)

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_only_known_effects_clip_decompiled(self, model_name, config, sine_wav, tmp_path):
        """Only explicitly listed effects should clip at 49% (decompiled mode)."""
        first, last = config['range']
        unexpected_clipping = []

        for prog in range(first, last + 1):
            output = tmp_path / f"out_{prog}.wav"
            data = run_midiverb(prog, sine_wav, output, model=model_name)
            clipped = count_clipped_samples(data)

            is_known = (model_name, prog) in KNOWN_CLIPPING_49PCT

            if clipped > CLIP_SAMPLE_THRESHOLD and not is_known:
                unexpected_clipping.append((prog, clipped))

        if unexpected_clipping:
            msg = f"{model_name} (decompiled) unexpected clipping at 49%:\n"
            for prog, count in unexpected_clipping:
                msg += f"  prog {prog}: {count} samples\n"
            pytest.fail(msg)

    @pytest.mark.parametrize("model_prog,min_clips", KNOWN_CLIPPING_49PCT.items())
    def test_known_clipping_effects(self, model_prog, min_clips, sine_wav, tmp_path):
        """Known clipping effects should actually clip."""
        model_name, prog = model_prog
        config = MODELS[model_name]

        output = tmp_path / f"out_{prog}.wav"
        data = run_midiverb(prog, sine_wav, output, model=model_name)
        clipped = count_clipped_samples(data)

        assert clipped >= min_clips, \
            f"{model_name} prog {prog} expected to clip >= {min_clips} samples, got {clipped}"
