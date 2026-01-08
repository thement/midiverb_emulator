"""
Tests for defeat (bypass) programs.

Defeat programs should output silence when given any input.
Non-defeat programs should produce audible output.
"""
import pytest
from conftest import MODELS, run_midiverb, get_max_amplitude


class TestDefeatPrograms:
    """Test that defeat programs output silence."""

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_defeat_outputs_silence_emulated(self, model_name, config, sine_wav, tmp_path):
        """Defeat programs should output silence (emulated mode)."""
        output = tmp_path / "out.wav"
        data = run_midiverb(config['defeat'], sine_wav, output, rom=config['rom'])
        max_amp = get_max_amplitude(data)
        assert max_amp < 10, \
            f"{model_name} defeat prog {config['defeat']} not silent (max={max_amp})"

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_defeat_outputs_silence_decompiled(self, model_name, config, sine_wav, tmp_path):
        """Defeat programs should output silence (decompiled mode)."""
        output = tmp_path / "out.wav"
        data = run_midiverb(config['defeat'], sine_wav, output, model=model_name)
        max_amp = get_max_amplitude(data)
        assert max_amp < 10, \
            f"{model_name} defeat prog {config['defeat']} not silent (max={max_amp})"


class TestNonDefeatPrograms:
    """Test that non-defeat programs produce output."""

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_non_defeat_not_silent_emulated(self, model_name, config, sine_wav, tmp_path):
        """All non-defeat programs should produce some output (emulated mode)."""
        first, last = config['range']
        defeat = config['defeat']
        silent_programs = []

        for prog in range(first, last + 1):
            if prog == defeat:
                continue
            output = tmp_path / f"out_{prog}.wav"
            data = run_midiverb(prog, sine_wav, output, rom=config['rom'])
            max_amp = get_max_amplitude(data)
            if max_amp < 100:
                silent_programs.append((prog, max_amp))

        if silent_programs:
            msg = f"{model_name} (emulated) has silent programs:\n"
            for prog, amp in silent_programs:
                msg += f"  prog {prog}: max_amp={amp}\n"
            pytest.fail(msg)

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_non_defeat_not_silent_decompiled(self, model_name, config, sine_wav, tmp_path):
        """All non-defeat programs should produce some output (decompiled mode)."""
        first, last = config['range']
        defeat = config['defeat']
        silent_programs = []

        for prog in range(first, last + 1):
            if prog == defeat:
                continue
            output = tmp_path / f"out_{prog}.wav"
            data = run_midiverb(prog, sine_wav, output, model=model_name)
            max_amp = get_max_amplitude(data)
            if max_amp < 100:
                silent_programs.append((prog, max_amp))

        if silent_programs:
            msg = f"{model_name} (decompiled) has silent programs:\n"
            for prog, amp in silent_programs:
                msg += f"  prog {prog}: max_amp={amp}\n"
            pytest.fail(msg)
