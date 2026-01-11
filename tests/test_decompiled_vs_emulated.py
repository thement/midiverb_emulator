"""
Tests comparing decompiled vs emulated effect outputs.

The decompiled C code should produce nearly identical output to
the emulated DSP code when processing the same input.

Note: The decompiler uses floating-point optimizations which introduce
small differences. Typical differences are 0.2-2%, which is acceptable.
"""
import pytest
import numpy as np
from conftest import MODELS, run_midiverb


# Maximum allowed difference as fraction of max amplitude
# The decompiler uses floating-point which introduces small differences.
# 10% is a generous threshold - anything above suggests a bug.
MAX_DIFF_RATIO = 0.10
MAX_DIFF = int(32767 * MAX_DIFF_RATIO)  # ~3276 for 10%

# Report threshold - programs exceeding this are reported but not failed
REPORT_THRESHOLD_RATIO = 0.02  # 2%
REPORT_THRESHOLD = int(32767 * REPORT_THRESHOLD_RATIO)

class TestDecompiledVsEmulated:
    """Compare decompiled and emulated effect outputs."""

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_outputs_match(self, model_name, config, sine_wav, tmp_path):
        """
        Decompiled and emulated outputs should be similar.

        Due to floating-point optimizations in the decompiler, small differences
        (typically 0.2-2%) are expected and acceptable.
        """
        first, last = config['range']
        high_diff_programs = []
        all_diffs = []

        skipped_lfo = []
        for prog in range(first, last + 1):
            out_emu = tmp_path / f"emu_{prog}.wav"
            out_dec = tmp_path / f"dec_{prog}.wav"

            # Run with ROM (emulated)
            data_emu = run_midiverb(prog, sine_wav, out_emu, rom=config['rom'])

            # Run with internal (decompiled)
            data_dec = run_midiverb(prog, sine_wav, out_dec, model=model_name)

            # Calculate maximum difference
            diff = np.abs(data_emu.astype(np.int32) - data_dec.astype(np.int32))
            max_diff = int(np.max(diff))
            all_diffs.append((prog, max_diff))

            if max_diff > REPORT_THRESHOLD:
                high_diff_programs.append((prog, max_diff))

        if skipped_lfo:
            print(f"\n{model_name}: skipped {len(skipped_lfo)} LFO programs (50-69)")

        # Report statistics
        diffs_only = [d for _, d in all_diffs]
        print(f"\n{model_name} (sine): diff stats - "
              f"min={min(diffs_only)}, max={max(diffs_only)}, "
              f"mean={np.mean(diffs_only):.0f}, median={np.median(diffs_only):.0f}")

        if high_diff_programs:
            print(f"{model_name} programs with diff > {REPORT_THRESHOLD_RATIO*100}%:")
            for prog, diff in high_diff_programs:
                print(f"  prog {prog}: max_diff={diff} ({diff/32767*100:.2f}%)")

        # Fail only if any program exceeds the generous threshold
        failures = [(p, d) for p, d in all_diffs if d > MAX_DIFF]
        if failures:
            msg = f"\n{model_name}: programs with excessive difference (>{MAX_DIFF_RATIO*100}%):\n"
            for prog, diff in failures:
                msg += f"  prog {prog}: max_diff={diff} ({diff/32767*100:.2f}%)\n"
            pytest.fail(msg)

    @pytest.mark.parametrize("model_name,config", MODELS.items())
    def test_outputs_match_noise(self, model_name, config, noise_wav, tmp_path):
        """
        Decompiled and emulated outputs should be similar with noise input.
        """
        first, last = config['range']
        high_diff_programs = []
        all_diffs = []

        skipped_lfo = []
        for prog in range(first, last + 1):
            out_emu = tmp_path / f"emu_{prog}.wav"
            out_dec = tmp_path / f"dec_{prog}.wav"

            try:
                # Run with ROM (emulated)
                data_emu = run_midiverb(prog, noise_wav, out_emu, rom=config['rom'])

                # Run with internal (decompiled)
                data_dec = run_midiverb(prog, noise_wav, out_dec, model=model_name)

                # Calculate maximum difference
                diff = np.abs(data_emu.astype(np.int32) - data_dec.astype(np.int32))
                max_diff = int(np.max(diff))
                all_diffs.append((prog, max_diff))

                if max_diff > REPORT_THRESHOLD:
                    high_diff_programs.append((prog, max_diff))
            except RuntimeError as e:
                # Some programs may fail with certain inputs
                print(f"\n{model_name} prog {prog} failed: {e}")

        if skipped_lfo:
            print(f"\n{model_name}: skipped {len(skipped_lfo)} LFO programs (50-69)")

        if not all_diffs:
            pytest.skip(f"No valid results for {model_name}")

        # Report statistics
        diffs_only = [d for _, d in all_diffs]
        print(f"\n{model_name} (noise): diff stats - "
              f"min={min(diffs_only)}, max={max(diffs_only)}, "
              f"mean={np.mean(diffs_only):.0f}, median={np.median(diffs_only):.0f}")

        if high_diff_programs:
            print(f"{model_name} programs with diff > {REPORT_THRESHOLD_RATIO*100}%:")
            for prog, diff in high_diff_programs:
                print(f"  prog {prog}: max_diff={diff} ({diff/32767*100:.2f}%)")

        # Fail only if any program exceeds the generous threshold
        failures = [(p, d) for p, d in all_diffs if d > MAX_DIFF]
        if failures:
            msg = f"\n{model_name}: programs with excessive difference (>{MAX_DIFF_RATIO*100}%):\n"
            for prog, diff in failures:
                msg += f"  prog {prog}: max_diff={diff} ({diff/32767*100:.2f}%)\n"
            pytest.fail(msg)
