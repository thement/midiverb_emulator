//  __  __ ___ ____ _____     __        _        __              ____ _____   __
// |  \/  |_ _|  _ \_ _\ \   / /__ _ __| |__    / _| ___  _ __  |  _ \_ _\ \ / /
// | |\/| || || | | | | \ \ / / _ \ '__| '_ \  | |_ / _ \| '__| | | | | | \ V /
// | |  | || || |_| | |  \ V /  __/ |  | |_) | |  _| (_) | |    | |_| | |  | |
// |_|  |_|___|____/___|  \_/ \___|_|  |_.__/  |_|  \___/|_|    |____/___| |_|
//
//
// What is this?
// =============
//
// This is a decompilation of Midiverb (1986) effects into a C code that is
// intended to be easily reusable in DIY projects.
//
// * Will get you a decent (albeit a bit noisy) reverb
// * It's very easy to embed - it's written in C and has no dependencies
// * Individual effects are relatively short (code-wise)
// * Requires 32 KB of memory
// * No floating point arithmetic
// * No division, just 16x16 -> 32 multiplier needed
//
// You try the individual effects live in web demo at http://ibawizard.net/midiverb
//
//
// How to use this?
// ================
//
// 1. Pick an effect you like (see the effect list at the bottom, or try the live demo)
// 2. Copy the effect function and the MEM macro into your project
// 3. Create DRAM memory array and a pointer:
//        int16_t DRAM[0x4000];  // 16K words of delay memory
//        int dram_ptr = 0;
// 4. Call the effect function for each sample:
//        midiverb_effect_XX(input, &out_left, &out_right, DRAM, dram_ptr++);
// 5. This will give you a 100% wet effect, so you might probably want to mix it with
//    the dry signal to get something more plausible sounding.
//
// Beware though:
// * The effect needs headroom (otherwise it internally wraps, which sounds horrible)
//   so keep input in range [-4096,4095] or shift the input sample right by 3 bits.
//   See the `run_effect_at_24khz` function below for an example.
// * The effects are designed to run at 24 KHz (23.4 KHz to be precise), so you should:
//   1. run your whole audio pipeline at 24 KHz, or
//   2. resample to 24 KHz before the effect and back after (not that hard for 48->24->48), or
//   3. just accept it will sound slightly different at other sample rates
//
// Build test program: gcc diy-midiverb.c -o diy-midiverb
//
//
// Drop me a line at thement at ibawizard dot net
// Source code currently at https://github.com/thement/midiverb_emulator/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

int16_t DRAM[0x4000];
int dram_ptr;

// Forward declaration so that we can have this bit of code at the top
void (*midiverb_effects[])(int16_t input, int16_t *out_left, int16_t *out_right, int16_t *DRAM, int ptr);

int16_t clip(int32_t input) {
    if (input > INT16_MAX) {
        return INT16_MAX;
    } else if (input < INT16_MIN) {
        return INT16_MIN;
    } else {
        return (int16_t)input;
    }
}

void run_effect_at_24khz(int effect_no, int16_t input_left, int16_t input_right, int16_t *out_left, int16_t *out_right)
{
	int16_t input = ((int32_t)input_left + input_right) / 2;
	int16_t input_scaled = input >> 3;
	int16_t out_left_scaled, out_right_scaled;

	midiverb_effects[effect_no](input_scaled, &out_left_scaled, &out_right_scaled, DRAM, dram_ptr++);

	*out_left = clip((int32_t)out_left_scaled << 3);
	*out_right = clip((int32_t)out_right_scaled << 3);
}

void write_u16_le(FILE *f, uint16_t v) { fputc(v & 0xff, f); fputc(v >> 8, f); }
void write_u32_le(FILE *f, uint32_t v) { write_u16_le(f, v); write_u16_le(f, v >> 16); }

int main(int argc, char *argv[])
{
    const char *filename = "bit-of-noise-through-effect-50.wav";
    int sample_rate = 24000;
    int noise_samples = sample_rate * 100 / 1000;   // 100ms of noise
    int total_samples = sample_rate * 10;           // 10 seconds total
    int16_t *output = malloc(total_samples * 4);

    srandom(time(NULL));

    // Generate noise burst and let reverb tail ring out
    for (int i = 0; i < total_samples; i++) {
        int16_t input = (i < noise_samples) ? (random() % 65536 - 32768) * 40 / 100 : 0;
        int16_t out_l, out_r;
        run_effect_at_24khz(49, input, input, &out_l, &out_r);  // effect 50
        output[i * 2] = out_l;
        output[i * 2 + 1] = out_r;
    }

    // Write WAV file (stereo, 16-bit, 24kHz)
    int data_size = total_samples * 4;
    FILE *f = fopen(filename, "wb");
    fwrite("RIFF", 1, 4, f);
    write_u32_le(f, 36 + data_size);
    fwrite("WAVEfmt ", 1, 8, f);
    write_u32_le(f, 16);
    write_u16_le(f, 1);
    write_u16_le(f, 2);
    write_u32_le(f, sample_rate);
    write_u32_le(f, sample_rate * 4);
    write_u16_le(f, 4);
    write_u16_le(f, 16);
    fwrite("data", 1, 4, f);
    write_u32_le(f, data_size);
    for (int i = 0; i < total_samples * 2; i++)
        write_u16_le(f, output[i]);
    fclose(f);

    printf("Wrote %s\n", filename);
    return 0;
}

// *** EFFECTS START HERE ***

#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 1: .2 Sec SMALL BRIGHT */
void midiverb_effect_1(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15928) / 2 + MEM(15159) / 2 + MEM(14715) / 2 + MEM(14517) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = MEM(15689) / 2 + MEM(15388) / 2 + MEM(14903) / 2 + MEM(14184) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = MEM(16323) * 5 / 8 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = MEM(16232) * 5 / 8 + MEM(16381) * 5 / 8 + MEM(16323);
	MEM(16321) = -Acc;
	Acc = MEM(16117) * 5 / 8 + MEM(16321) * 5 / 8 + MEM(16232);
	MEM(16230) = -Acc;
	Acc = -MEM(16230) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + MEM(16230) / 2 + MEM(16117) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = MEM(15731) / 2 + MEM(15557) / 2;
	MEM(15729) = -Acc;
	Acc = -Acc / 2 + MEM(15557);
	MEM(15555) = Acc;
	Acc = MEM(15292) / 2 + MEM(15056) / 2;
	MEM(15290) = -Acc;
	Acc = -Acc / 2 + MEM(15056);
	tmp_1 = Acc;
	Acc = MEM(14106) / 2 + tmp_1 / 2;
	MEM(14107) = Acc;
	Acc = MEM(14106) + tmp_b;
	MEM(15992) = Acc;
	Acc = MEM(14837) / 2 + MEM(14698) / 2;
	MEM(14835) = -Acc;
	Acc = -Acc / 2 + MEM(14698);
	MEM(14696) = Acc;
	Acc = MEM(14399) / 2 + MEM(14112) / 2;
	MEM(14397) = -Acc;
	Acc = -Acc / 2 + MEM(14112);
	tmp_1 = Acc;
	Acc = MEM(14103) / 2 + tmp_1 / 2;
	MEM(14104) = Acc;
	Acc = MEM(14103) + tmp_b;
	MEM(15054) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 2: .2 Sec SMALL WARM */
void midiverb_effect_2(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15928) / 2 + MEM(15159) / 2 + MEM(14715) / 2 + MEM(14517) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = MEM(15689) / 2 + MEM(15388) / 2 + MEM(14903) / 2 + MEM(14184) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = MEM(14109) / 2 + MEM(16383) / 2;
	MEM(14110) = Acc;
	Acc = MEM(16323) * 5 / 8 + MEM(14109) / 2;
	MEM(16381) = -Acc;
	Acc = MEM(16232) * 5 / 8 + MEM(16381) * 5 / 8 + MEM(16323);
	MEM(16321) = -Acc;
	Acc = MEM(16117) * 5 / 8 + MEM(16321) * 5 / 8 + MEM(16232);
	MEM(16230) = -Acc;
	Acc = -MEM(16230) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + MEM(16230) / 2 + MEM(16117) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = MEM(15731) / 2 + MEM(15557) / 2;
	MEM(15729) = -Acc;
	Acc = -Acc / 2 + MEM(15557);
	MEM(15555) = Acc;
	Acc = MEM(15292) / 2 + MEM(15056) / 2;
	MEM(15290) = -Acc;
	Acc = -Acc / 2 + MEM(15056);
	tmp_1 = Acc;
	Acc = MEM(14106) / 2 + tmp_1 / 2;
	MEM(14107) = Acc;
	Acc = MEM(14106) + tmp_b;
	MEM(15992) = Acc;
	Acc = MEM(14837) / 2 + MEM(14698) / 2;
	MEM(14835) = -Acc;
	Acc = -Acc / 2 + MEM(14698);
	MEM(14696) = Acc;
	Acc = MEM(14399) / 2 + MEM(14112) / 2;
	MEM(14397) = -Acc;
	Acc = -Acc / 2 + MEM(14112);
	tmp_1 = Acc;
	Acc = MEM(14103) / 2 + tmp_1 / 2;
	MEM(14104) = Acc;
	Acc = MEM(14103) + tmp_b;
	MEM(15054) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 3: .2 Sec MEDIUM BRIGHT */
void midiverb_effect_3(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15748) / 2 + MEM(14579) / 2 + MEM(13635) / 2 + MEM(13037) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = MEM(15509) / 2 + MEM(14808) / 2 + MEM(13823) / 2 + MEM(12704) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = MEM(16323) * 5 / 8 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = MEM(16232) * 5 / 8 + MEM(16381) * 5 / 8 + MEM(16323);
	MEM(16321) = -Acc;
	Acc = MEM(16047) * 5 / 8 + MEM(16321) * 5 / 8 + MEM(16232);
	MEM(16230) = -Acc;
	Acc = -MEM(16230) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + MEM(16230) / 2 + MEM(16047) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = MEM(15351) / 2 + MEM(14977) / 2;
	MEM(15349) = -Acc;
	Acc = -Acc / 2 + MEM(14977);
	MEM(14975) = Acc;
	Acc = -MEM(14412) / 4 + MEM(13976) / 2;
	MEM(14410) = -Acc;
	Acc = -Acc / 2 + MEM(13976);
	tmp_1 = Acc;
	Acc = MEM(12126) / 2 + tmp_1 / 2;
	MEM(12127) = Acc;
	Acc = MEM(12126) + tmp_b;
	MEM(15812) = Acc;
	Acc = MEM(13557) / 2 + MEM(13218) / 2;
	MEM(13555) = -Acc;
	Acc = -Acc / 2 + MEM(13218);
	MEM(13216) = Acc;
	Acc = -MEM(12619) / 4 + MEM(12132) / 2;
	MEM(12617) = -Acc;
	Acc = -Acc / 2 + MEM(12132);
	tmp_1 = Acc;
	Acc = MEM(12123) / 2 + tmp_1 / 2;
	MEM(12124) = Acc;
	Acc = MEM(12123) + tmp_b;
	MEM(13974) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 4: .3 Sec SMALL BRIGHT */
void midiverb_effect_4(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15928) / 2 + MEM(14859) / 2 + MEM(14215) / 2 + MEM(13617) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = MEM(15689) / 2 + MEM(15088) / 2 + MEM(14403) / 2 + MEM(13284) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = MEM(16323) * 5 / 8 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = MEM(16232) * 5 / 8 + MEM(16381) * 5 / 8 + MEM(16323);
	MEM(16321) = -Acc;
	Acc = MEM(16127) * 5 / 8 + MEM(16321) * 5 / 8 + MEM(16232);
	MEM(16230) = -Acc;
	Acc = -MEM(16230) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + MEM(16230) / 2 + MEM(16127) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = MEM(15531) / 2 + MEM(15257) / 2;
	MEM(15529) = -Acc;
	Acc = -Acc / 2 + MEM(15257);
	MEM(15255) = Acc;
	Acc = MEM(14792) / 2 + MEM(14556) / 2;
	MEM(14790) = -Acc;
	Acc = -Acc / 2 + MEM(14556);
	tmp_1 = Acc;
	Acc = MEM(13006) / 2 + tmp_1 / 2;
	MEM(13007) = Acc;
	Acc = MEM(13006) + tmp_b;
	MEM(15992) = Acc;
	Acc = MEM(14137) / 2 + MEM(13798) / 2;
	MEM(14135) = -Acc;
	Acc = -Acc / 2 + MEM(13798);
	MEM(13796) = Acc;
	Acc = MEM(13399) / 2 + MEM(13012) / 2;
	MEM(13397) = -Acc;
	Acc = -Acc / 2 + MEM(13012);
	tmp_1 = Acc;
	Acc = MEM(13003) / 2 + tmp_1 / 2;
	MEM(13004) = Acc;
	Acc = MEM(13003) + tmp_b;
	MEM(14554) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 5: .3 Sec SMALL WARM */
void midiverb_effect_5(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15914) / 2 + MEM(14945) / 2 + MEM(14001) / 2 + MEM(13403) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = MEM(15675) / 2 + MEM(14974) / 2 + MEM(14189) / 2 + MEM(13370) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = MEM(12695) / 2 + MEM(16383) / 2;
	MEM(12696) = Acc;
	Acc = MEM(16323) * 5 / 8 + MEM(12695) / 2;
	MEM(16381) = -Acc;
	Acc = MEM(16232) * 5 / 8 + MEM(16381) * 5 / 8 + MEM(16323);
	MEM(16321) = -Acc;
	Acc = MEM(16127) * 5 / 8 + MEM(16321) * 5 / 8 + MEM(16232);
	MEM(16230) = -Acc;
	Acc = -MEM(16230) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + MEM(16230) / 2 + MEM(16127) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = MEM(15517) / 2 + MEM(15143) / 2;
	MEM(15515) = -Acc;
	Acc = -Acc / 2 + MEM(15143);
	MEM(15141) = Acc;
	Acc = MEM(14778) / 2 + MEM(14342) / 2;
	MEM(14776) = -Acc;
	Acc = -Acc / 2 + MEM(14342);
	tmp_1 = Acc;
	Acc = MEM(12692) / 2 + tmp_1 / 2;
	MEM(12693) = Acc;
	Acc = MEM(12692) + tmp_b;
	MEM(15978) = Acc;
	Acc = MEM(13923) / 2 + MEM(13584) / 2;
	MEM(13921) = -Acc;
	Acc = -Acc / 2 + MEM(13584);
	MEM(13582) = Acc;
	Acc = MEM(13185) / 2 + MEM(12698) / 2;
	MEM(13183) = -Acc;
	Acc = -Acc / 2 + MEM(12698);
	tmp_1 = Acc;
	Acc = MEM(12689) / 2 + tmp_1 / 2;
	MEM(12690) = Acc;
	Acc = MEM(12689) + tmp_b;
	MEM(14340) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 6: .4 Sec MEDIUM BRIGHT */
void midiverb_effect_6(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15748) / 2 + MEM(14579) / 2 + MEM(13635) / 2 + MEM(13037) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = MEM(15509) / 2 + MEM(14808) / 2 + MEM(13823) / 2 + MEM(12704) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = MEM(16323) * 5 / 8 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = MEM(16232) * 5 / 8 + MEM(16381) * 5 / 8 + MEM(16323);
	MEM(16321) = -Acc;
	Acc = MEM(16047) * 5 / 8 + MEM(16321) * 5 / 8 + MEM(16232);
	MEM(16230) = -Acc;
	Acc = -MEM(16230) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + MEM(16230) / 2 + MEM(16047) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = MEM(15351) / 2 + MEM(14977) / 2;
	MEM(15349) = -Acc;
	Acc = -Acc / 2 + MEM(14977);
	MEM(14975) = Acc;
	Acc = MEM(14412) / 2 + MEM(13976) / 2;
	MEM(14410) = -Acc;
	Acc = -Acc / 2 + MEM(13976);
	tmp_1 = Acc;
	Acc = MEM(12126) / 2 + tmp_1 / 2;
	MEM(12127) = Acc;
	Acc = MEM(12126) + tmp_b;
	MEM(15812) = Acc;
	Acc = MEM(13557) / 2 + MEM(13218) / 2;
	MEM(13555) = -Acc;
	Acc = -Acc / 2 + MEM(13218);
	MEM(13216) = Acc;
	Acc = MEM(12619) / 2 + MEM(12132) / 2;
	MEM(12617) = -Acc;
	Acc = -Acc / 2 + MEM(12132);
	tmp_1 = Acc;
	Acc = MEM(12123) / 2 + tmp_1 / 2;
	MEM(12124) = Acc;
	Acc = MEM(12123) + tmp_b;
	MEM(13974) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 7: .4 Sec MEDIUM WARM */
void midiverb_effect_7(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(15748) / 4 + -MEM(14579) / 4 + -MEM(13635) / 4 + -MEM(13037) / 4;
	tmp_5 = -Acc;
	Acc = -MEM(15509) / 4 + -MEM(14808) / 4 + -MEM(13823) / 4 + -MEM(12704) / 4;
	tmp_3 = -Acc;
	Acc = MEM(12129) / 2 + MEM(16383) / 2;
	MEM(12130) = Acc;
	Acc = MEM(16323) * 5 / 8 + MEM(12129) / 2;
	MEM(16381) = -Acc;
	Acc = MEM(16232) * 5 / 8 + MEM(16381) * 5 / 8 + MEM(16323);
	MEM(16321) = -Acc;
	Acc = MEM(16047) * 5 / 8 + MEM(16321) * 5 / 8 + MEM(16232);
	MEM(16230) = -Acc;
	Acc = -MEM(16230) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + MEM(16230) / 2 + MEM(16047) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = MEM(15351) / 2 + MEM(14977) / 2;
	MEM(15349) = -Acc;
	Acc = -Acc / 2 + MEM(14977);
	MEM(14975) = Acc;
	Acc = MEM(14412) / 2 + MEM(13976) / 2;
	MEM(14410) = -Acc;
	Acc = -Acc / 2 + MEM(13976);
	tmp_1 = Acc;
	Acc = MEM(12126) / 2 + tmp_1 / 2;
	MEM(12127) = Acc;
	Acc = MEM(12126) + tmp_b;
	MEM(15812) = Acc;
	Acc = MEM(13557) / 2 + MEM(13218) / 2;
	MEM(13555) = -Acc;
	Acc = -Acc / 2 + MEM(13218);
	MEM(13216) = Acc;
	Acc = MEM(12619) / 2 + MEM(12132) / 2;
	MEM(12617) = -Acc;
	Acc = -Acc / 2 + MEM(12132);
	tmp_1 = Acc;
	Acc = MEM(12123) / 2 + tmp_1 / 2;
	MEM(12124) = Acc;
	Acc = MEM(12123) + tmp_b;
	MEM(13974) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 8: .6 Sec SMALL BRIGHT */
void midiverb_effect_8(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	MEM(0) = input;
	Acc = MEM(15581) / 2 + MEM(14072) / 2 + MEM(11650) / 2 + MEM(16206) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = MEM(15242) / 2 + MEM(14401) / 2 + MEM(11838) / 2 + MEM(15873) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = MEM(16323) * 5 / 8 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = MEM(16232) * 5 / 8 + MEM(16381) * 5 / 8 + MEM(16323);
	MEM(16321) = -Acc;
	Acc = MEM(16047) * 5 / 8 + MEM(16321) * 5 / 8 + MEM(16232);
	MEM(16230) = -Acc;
	Acc = -MEM(16230) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + MEM(16230) / 2 + MEM(16047) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = MEM(15044) / 2 + MEM(14570) / 2;
	MEM(15042) = -Acc;
	Acc = -Acc / 2 + MEM(14570);
	MEM(14568) = Acc;
	Acc = MEM(13885) / 2 + MEM(13249) / 2;
	MEM(13883) = -Acc;
	Acc = Acc * -3 / 4 + MEM(13249) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(10729) / 4 + tmp_1 / 2;
	MEM(10730) = Acc;
	Acc = MEM(10729) + tmp_b;
	MEM(15645) = Acc;
	Acc = MEM(12630) / 2 + MEM(11991) / 2;
	MEM(12628) = -Acc;
	Acc = -Acc / 2 + MEM(11991);
	MEM(11989) = Acc;
	Acc = MEM(11392) / 2 + MEM(10735) / 2;
	MEM(11390) = -Acc;
	Acc = Acc * -3 / 4 + MEM(10735) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(10726) / 4 + tmp_1 / 2;
	MEM(10727) = Acc;
	*out_left = tmp_5;
	Acc = MEM(10726) + tmp_b;
	MEM(13247) = Acc;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 9: .6 Sec MEDIUM WARM */
void midiverb_effect_9(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	MEM(0) = input;
	Acc = -MEM(14199) / 4 + -MEM(10783) / 4 + -MEM(5936) / 4 + -MEM(16040) / 4;
	tmp_5 = -Acc;
	Acc = -MEM(13519) / 4 + -MEM(11428) / 4 + -MEM(6313) / 4 + -MEM(15362) / 4;
	tmp_3 = -Acc;
	Acc = MEM(3741) / 2 + MEM(16284) / 2;
	MEM(3742) = Acc;
	Acc = MEM(16184) * 5 / 8 + MEM(3741) / 2;
	MEM(16282) = -Acc;
	Acc = MEM(15984) * 5 / 8 + MEM(16282) * 5 / 8 + MEM(16184);
	MEM(16182) = -Acc;
	Acc = MEM(15615) * 5 / 8 + MEM(16182) * 5 / 8 + MEM(15984);
	MEM(15982) = -Acc;
	Acc = MEM(15982) * 5 / 8 + MEM(15615) + MEM(14324) / 2;
	MEM(15113) = -Acc;
	Acc = Acc * -27 / 16 + MEM(14324) * 27 / 8;
	tmp_b = Acc;
	Acc = -MEM(13119) / 4 + MEM(11772) / 2;
	MEM(13117) = -Acc;
	Acc = -Acc / 2 + MEM(11772);
	MEM(11770) = Acc;
	Acc = -MEM(10401) / 4 + MEM(9110) / 2;
	MEM(10399) = -Acc;
	Acc = Acc * -3 / 4 + MEM(9110) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(3738) / 4 + tmp_1 / 2;
	MEM(3739) = Acc;
	Acc = MEM(3738) + tmp_b;
	MEM(14322) = Acc;
	Acc = -MEM(8074) / 4 + MEM(6616) / 2;
	MEM(8072) = -Acc;
	Acc = -Acc / 2 + MEM(6616);
	MEM(6614) = Acc;
	Acc = -MEM(5131) / 4 + MEM(3744) / 2;
	MEM(5129) = -Acc;
	Acc = Acc * -3 / 4 + MEM(3744) * 3 / 2;
	tmp_1 = Acc;
	*out_left = tmp_5;
	Acc = MEM(3735) / 4 + tmp_1 / 2;
	MEM(3736) = Acc;
	Acc = MEM(3735) + tmp_b;
	MEM(9108) = Acc;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 10: .6 Sec MEDIUM DARK */
void midiverb_effect_10(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	MEM(0) = input;
	Acc = -MEM(14199) / 4 + -MEM(10783) / 4 + -MEM(5936) / 4 + -MEM(16040) / 4;
	tmp_5 = -Acc;
	Acc = -MEM(13819) / 4 + -MEM(11428) / 4 + -MEM(6313) / 4 + -MEM(15362) / 4;
	tmp_3 = -Acc;
	Acc = MEM(3741) * 3 / 4 + MEM(16284) / 2;
	MEM(3742) = Acc;
	Acc = MEM(16184) * 5 / 8 + MEM(3741) / 2;
	MEM(16282) = -Acc;
	Acc = MEM(15984) * 5 / 8 + MEM(16282) * 5 / 8 + MEM(16184);
	MEM(16182) = -Acc;
	Acc = MEM(15615) * 5 / 8 + MEM(16182) * 5 / 8 + MEM(15984);
	MEM(15982) = -Acc;
	Acc = MEM(15982) * 5 / 8 + MEM(15615) + MEM(14324) / 2;
	MEM(15113) = -Acc;
	Acc = Acc * -27 / 16 + MEM(14324) * 27 / 8;
	tmp_b = Acc;
	Acc = -MEM(13119) / 4 + MEM(11772) / 2;
	MEM(13117) = -Acc;
	Acc = -Acc / 2 + MEM(11772);
	MEM(11770) = Acc;
	Acc = -MEM(10401) / 4 + MEM(9110) / 2;
	MEM(10399) = -Acc;
	Acc = Acc * -3 / 4 + MEM(9110) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(3738) / 4 + tmp_1 / 2;
	MEM(3739) = Acc;
	Acc = MEM(3738) + tmp_b;
	MEM(14322) = Acc;
	Acc = -MEM(8074) / 4 + MEM(6616) / 2;
	MEM(8072) = -Acc;
	Acc = -Acc / 2 + MEM(6616);
	MEM(6614) = Acc;
	Acc = -MEM(5131) / 4 + MEM(3744) / 2;
	MEM(5129) = -Acc;
	Acc = Acc * -3 / 4 + MEM(3744) * 3 / 2;
	tmp_1 = Acc;
	*out_left = tmp_5;
	Acc = MEM(3735) / 4 + tmp_1 / 2;
	MEM(3736) = Acc;
	Acc = MEM(3735) + tmp_b;
	MEM(9108) = Acc;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 11: .8 Sec SMALL BRIGHT */
void midiverb_effect_11(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	MEM(0) = input;
	Acc = -MEM(15581) / 4 + -MEM(13972) / 4 + -MEM(11450) / 4 + -MEM(16206) / 4;
	tmp_5 = -Acc;
	Acc = -MEM(15242) / 4 + -MEM(14301) / 4 + -MEM(11638) / 4 + -MEM(15873) / 4;
	tmp_3 = -Acc;
	Acc = MEM(16323) * 5 / 8 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = MEM(16232) * 5 / 8 + MEM(16381) * 5 / 8 + MEM(16323);
	MEM(16321) = -Acc;
	Acc = MEM(16047) * 5 / 8 + MEM(16321) * 5 / 8 + MEM(16232);
	MEM(16230) = -Acc;
	Acc = -MEM(16230) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + MEM(16230) / 2 + MEM(16047) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = MEM(14944) * 5 / 8 + MEM(14470) / 2;
	MEM(14942) = -Acc;
	Acc = -Acc / 2 + MEM(14470);
	MEM(14468) = Acc;
	Acc = MEM(13685) * 5 / 8 + MEM(13049) / 2;
	MEM(13683) = -Acc;
	Acc = Acc * -3 / 4 + MEM(13049) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(10559) / 4 + tmp_1 / 2;
	MEM(10560) = Acc;
	Acc = MEM(10559) + tmp_b;
	MEM(15645) = Acc;
	Acc = MEM(12430) * 5 / 8 + MEM(11791) / 2;
	MEM(12428) = -Acc;
	Acc = -Acc / 2 + MEM(11791);
	MEM(11789) = Acc;
	Acc = MEM(11222) * 5 / 8 + MEM(10565) / 2;
	MEM(11220) = -Acc;
	*out_left = tmp_5;
	Acc = Acc * -3 / 4 + MEM(10565) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(10556) / 4 + tmp_1 / 2;
	MEM(10557) = Acc;
	Acc = MEM(10556) + tmp_b;
	MEM(13047) = Acc;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 12: .8 Sec LARGE WARM */
void midiverb_effect_12(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(13220) / 2 + MEM(8230) / 2 + MEM(4233) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = MEM(12440) / 2 + MEM(8931) / 2 + MEM(4765) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = MEM(16383) / 2 + MEM(762) / 2;
	MEM(763) = Acc;
	Acc = MEM(762) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14757) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14757) + MEM(13635) / 2;
	MEM(14755) = -Acc;
	Acc = -Acc / 2 + MEM(13635) + MEM(13399) / 2;
	MEM(13633) = -Acc;
	Acc = -Acc / 2 + MEM(13399) + MEM(13243) / 2;
	MEM(13397) = -Acc;
	Acc = -Acc / 2 + MEM(13243);
	tmp_2 = Acc;
	Acc = -MEM(11817) / 4 + MEM(9823) / 2;
	MEM(11815) = -Acc;
	Acc = -Acc / 2 + MEM(9823) + MEM(759) / 2;
	MEM(760) = Acc;
	Acc = MEM(760);
	MEM(9821) = Acc;
	Acc = -MEM(7811) / 4 + MEM(5438) / 2;
	MEM(7809) = -Acc;
	Acc = -Acc / 2 + MEM(5438);
	MEM(5436) = Acc;
	Acc = -MEM(3379) / 4 + MEM(765) / 2;
	MEM(3377) = -Acc;
	Acc = -Acc / 2 + MEM(765) + tmp_2;
	MEM(13241) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 13: 1.0 Sec SMALL WARM */
void midiverb_effect_13(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	MEM(0) = input;
	Acc = -MEM(15721) / 4 + -MEM(14412) / 4 + -MEM(12420) / 4 + -MEM(16206) / 4;
	tmp_5 = -Acc;
	Acc = -MEM(15382) / 4 + -MEM(14741) / 4 + -MEM(12608) / 4 + -MEM(15873) / 4;
	tmp_3 = -Acc;
	Acc = MEM(11502) / 2 + MEM(16383) / 2;
	MEM(11503) = Acc;
	Acc = MEM(16323) * 5 / 8 + MEM(11502) / 2;
	MEM(16381) = -Acc;
	Acc = MEM(16232) * 5 / 8 + MEM(16381) * 5 / 8 + MEM(16323);
	MEM(16321) = -Acc;
	Acc = MEM(16047) * 5 / 8 + MEM(16321) * 5 / 8 + MEM(16232);
	MEM(16230) = -Acc;
	Acc = -MEM(16230) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + MEM(16230) / 2 + MEM(16047) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = MEM(15284) * 3 / 4 + MEM(14910) / 2;
	MEM(15282) = -Acc;
	Acc = -Acc / 2 + MEM(14910);
	MEM(14908) = Acc;
	Acc = MEM(14225) * 3 / 4 + MEM(13689) / 2;
	MEM(14223) = -Acc;
	Acc = Acc * -3 / 4 + MEM(13689) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(11499) / 4 + tmp_1 / 2;
	MEM(11500) = Acc;
	Acc = MEM(11499) + tmp_b;
	MEM(15785) = Acc;
	Acc = MEM(13270) * 3 / 4 + MEM(12761) / 2;
	MEM(13268) = -Acc;
	Acc = -Acc / 2 + MEM(12761);
	MEM(12759) = Acc;
	Acc = MEM(12062) * 3 / 4 + MEM(11505) / 2;
	MEM(12060) = -Acc;
	Acc = Acc * -3 / 4 + MEM(11505) * 3 / 2;
	tmp_1 = Acc;
	*out_left = tmp_5;
	Acc = MEM(11496) / 4 + tmp_1 / 2;
	MEM(11497) = Acc;
	Acc = MEM(11496) + tmp_b;
	MEM(13687) = Acc;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 14: 1.0 Sec MEDIUM WARM */
void midiverb_effect_14(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	MEM(0) = input;
	Acc = MEM(14113) / 2 + MEM(10897) / 2 + MEM(6230) / 2 + MEM(16040) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = MEM(13433) / 2 + MEM(11542) / 2 + MEM(6607) / 2 + MEM(15362) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = MEM(3835) / 2 + MEM(16284) / 2;
	MEM(3836) = Acc;
	Acc = MEM(16184) * 5 / 8 + MEM(3835) / 2;
	MEM(16282) = -Acc;
	Acc = MEM(15984) * 5 / 8 + MEM(16282) * 5 / 8 + MEM(16184);
	MEM(16182) = -Acc;
	Acc = MEM(15615) * 5 / 8 + MEM(16182) * 5 / 8 + MEM(15984);
	MEM(15982) = -Acc;
	Acc = MEM(15982) * 5 / 8 + MEM(15615) + MEM(14238) / 2;
	MEM(15113) = -Acc;
	Acc = Acc * -27 / 16 + MEM(14238) * 27 / 8;
	tmp_b = Acc;
	Acc = MEM(13033) / 2 + MEM(11886) / 2;
	MEM(13031) = -Acc;
	Acc = -Acc / 2 + MEM(11886);
	MEM(11884) = Acc;
	Acc = MEM(10315) / 2 + MEM(8974) / 2;
	MEM(10313) = -Acc;
	Acc = Acc * -3 / 4 + MEM(8974) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(3832) / 4 + tmp_1 / 2;
	MEM(3833) = Acc;
	Acc = MEM(3832) + tmp_b;
	MEM(14236) = Acc;
	Acc = MEM(7968) / 2 + MEM(6910) / 2;
	MEM(7966) = -Acc;
	Acc = -Acc / 2 + MEM(6910);
	MEM(6908) = Acc;
	Acc = MEM(5225) / 2 + MEM(3838) / 2;
	MEM(5223) = -Acc;
	Acc = Acc * -3 / 4 + MEM(3838) * 3 / 2;
	tmp_1 = Acc;
	*out_left = tmp_5;
	Acc = MEM(3829) / 4 + tmp_1 / 2;
	MEM(3830) = Acc;
	Acc = MEM(3829) + tmp_b;
	MEM(8972) = Acc;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 15: 1.0 Sec LARGE BRIGHT */
void midiverb_effect_15(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	MEM(0) = input;
	Acc = -MEM(13732) / 4 + -MEM(10316) / 4 + -MEM(4769) / 4 + -MEM(16040) / 4;
	tmp_5 = -Acc;
	Acc = -MEM(13052) / 4 + -MEM(10961) / 4 + -MEM(5146) / 4 + -MEM(15362) / 4;
	tmp_3 = -Acc;
	Acc = MEM(16184) * 5 / 8 + MEM(16284) / 2;
	MEM(16282) = -Acc;
	Acc = MEM(15984) * 5 / 8 + MEM(16282) * 5 / 8 + MEM(16184);
	MEM(16182) = -Acc;
	Acc = MEM(15615) * 5 / 8 + MEM(16182) * 5 / 8 + MEM(15984);
	MEM(15982) = -Acc;
	Acc = MEM(15982) * 5 / 8 + MEM(15615) + MEM(13857) / 2;
	MEM(15113) = -Acc;
	Acc = Acc * -27 / 16 + MEM(13857) * 27 / 8;
	tmp_b = Acc;
	Acc = MEM(12652) + MEM(11305) / 2;
	MEM(12650) = -Acc;
	Acc = -Acc / 2 + MEM(11305);
	MEM(11303) = Acc;
	Acc = -MEM(9734) / 4 + MEM(7943) / 2;
	MEM(9732) = -Acc;
	Acc = Acc * -3 / 4 + MEM(7943) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(1671) / 4 + tmp_1 / 2;
	MEM(1672) = Acc;
	Acc = MEM(1671) + tmp_b;
	MEM(13855) = Acc;
	Acc = MEM(6907) + MEM(5449) / 2;
	MEM(6905) = -Acc;
	Acc = -Acc / 2 + MEM(5449);
	MEM(5447) = Acc;
	Acc = -MEM(3464) / 4 + MEM(1677) / 2;
	MEM(3462) = -Acc;
	Acc = Acc * -3 / 4 + MEM(1677) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(1668) / 4 + tmp_1 / 2;
	MEM(1669) = Acc;
	*out_left = tmp_5;
	Acc = MEM(1668) + tmp_b;
	MEM(7941) = Acc;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 16: 1.2 Sec MEDIUM WARM */
void midiverb_effect_16(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	MEM(0) = input;
	Acc = -MEM(14001) / 4 + -MEM(10585) / 4 + -MEM(5038) / 4 + -MEM(16040) / 4;
	tmp_5 = -Acc;
	Acc = -MEM(13321) / 4 + -MEM(11230) / 4 + -MEM(5415) / 4 + -MEM(15362) / 4;
	tmp_3 = -Acc;
	Acc = MEM(1943) / 2 + MEM(16284) / 2;
	MEM(1944) = Acc;
	Acc = MEM(16184) * 5 / 8 + MEM(1944) / 2;
	MEM(16282) = -Acc;
	Acc = MEM(15984) * 5 / 8 + MEM(16282) * 5 / 8 + MEM(16184);
	MEM(16182) = -Acc;
	Acc = MEM(15615) * 5 / 8 + MEM(16182) * 5 / 8 + MEM(15984);
	MEM(15982) = -Acc;
	Acc = MEM(15982) * 5 / 8 + MEM(15615) + MEM(14126) / 2;
	MEM(15113) = -Acc;
	Acc = Acc * -27 / 16 + MEM(14126) * 27 / 8;
	tmp_b = Acc;
	Acc = MEM(12921) * 3 / 4 + MEM(11574) / 2;
	MEM(12919) = -Acc;
	Acc = -Acc / 2 + MEM(11574);
	MEM(11572) = Acc;
	Acc = MEM(10003) / 2 + MEM(8212) / 2;
	MEM(10001) = -Acc;
	Acc = Acc * -3 / 4 + MEM(8212) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(1940) / 4 + tmp_1 / 2;
	MEM(1941) = Acc;
	Acc = MEM(1940) + tmp_b;
	MEM(14124) = Acc;
	Acc = MEM(7176) * 3 / 4 + MEM(5718) / 2;
	MEM(7174) = -Acc;
	Acc = -Acc / 2 + MEM(5718);
	MEM(5716) = Acc;
	Acc = MEM(3733) / 2 + MEM(1946) / 2;
	MEM(3731) = -Acc;
	Acc = Acc * -3 / 4 + MEM(1946) * 3 / 2;
	tmp_1 = Acc;
	*out_left = tmp_5;
	Acc = MEM(1937) / 4 + tmp_1 / 2;
	MEM(1938) = Acc;
	Acc = MEM(1937) + tmp_b;
	MEM(8210) = Acc;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 17: 1.2 Sec SMALL WARM */
void midiverb_effect_17(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	MEM(0) = input;
	Acc = -MEM(15072) / 4 + -MEM(12250) / 4 + -MEM(9697) / 4 + -MEM(7636) / 4;
	tmp_5 = -Acc;
	Acc = -MEM(14561) / 4 + -MEM(12895) / 4 + -MEM(10663) / 4 + -MEM(8080) / 4;
	tmp_3 = -Acc;
	Acc = MEM(6208) / 2 + MEM(16284) / 2;
	MEM(6209) = Acc;
	Acc = MEM(16204) * 5 / 8 + MEM(6208) / 2;
	MEM(16282) = -Acc;
	Acc = MEM(16055) * 5 / 8 + MEM(16282) * 5 / 8 + MEM(16204);
	MEM(16202) = -Acc;
	Acc = MEM(15686) * 5 / 8 + MEM(16202) * 5 / 8 + MEM(16055);
	MEM(16053) = -Acc;
	Acc = MEM(16053) * 135 / 64 + MEM(15686) * 27 / 8;
	tmp_b = Acc;
	Acc = MEM(14286) * 3 / 4 + MEM(13239) / 2;
	MEM(14284) = -Acc;
	Acc = -Acc / 2 + MEM(13239);
	MEM(13237) = Acc;
	Acc = MEM(11968) * 3 / 4 + MEM(10677) / 2;
	MEM(11966) = -Acc;
	Acc = Acc * -3 / 4 + MEM(10677) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(6205) / 4 + tmp_1 / 2;
	MEM(6206) = Acc;
	Acc = MEM(6205) + tmp_b;
	MEM(15084) = Acc;
	Acc = MEM(9641) * 3 / 4 + MEM(8383) / 2;
	MEM(9639) = -Acc;
	Acc = -Acc / 2 + MEM(8383);
	MEM(8381) = Acc;
	Acc = MEM(7198) * 3 / 4 + MEM(6211) / 2;
	MEM(7196) = -Acc;
	Acc = Acc * -3 / 4 + MEM(6211) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(6202) / 4 + tmp_1 / 2;
	MEM(6203) = Acc;
	*out_left = tmp_5;
	Acc = MEM(6202) + tmp_b;
	MEM(10675) = Acc;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 18: 1.2 Sec SMALL BRIGHT */
void midiverb_effect_18(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	MEM(0) = input;
	Acc = -MEM(15072) / 4 + -MEM(12250) / 4 + -MEM(9697) / 4 + -MEM(7636) / 4;
	tmp_5 = -Acc;
	Acc = -MEM(14561) / 4 + -MEM(12895) / 4 + -MEM(10663) / 4 + -MEM(8080) / 4;
	tmp_3 = -Acc;
	Acc = MEM(16204) * 5 / 8 + MEM(16284) / 2;
	MEM(16282) = -Acc;
	Acc = MEM(16055) * 5 / 8 + MEM(16282) * 5 / 8 + MEM(16204);
	MEM(16202) = -Acc;
	Acc = MEM(15686) * 5 / 8 + MEM(16202) * 5 / 8 + MEM(16055);
	MEM(16053) = -Acc;
	Acc = MEM(16053) * 135 / 64 + MEM(15686) * 27 / 8;
	tmp_b = Acc;
	Acc = MEM(14286) * 3 / 4 + MEM(13239) / 2;
	MEM(14284) = -Acc;
	Acc = -Acc / 2 + MEM(13239);
	MEM(13237) = Acc;
	Acc = MEM(11968) * 3 / 4 + MEM(10677) / 2;
	MEM(11966) = -Acc;
	Acc = Acc * -3 / 4 + MEM(10677) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(6205) / 4 + tmp_1 / 2;
	MEM(6206) = Acc;
	Acc = MEM(6205) + tmp_b;
	MEM(15084) = Acc;
	Acc = MEM(9641) * 3 / 4 + MEM(8383) / 2;
	MEM(9639) = -Acc;
	Acc = -Acc / 2 + MEM(8383);
	MEM(8381) = Acc;
	Acc = MEM(7198) * 3 / 4 + MEM(6211) / 2;
	MEM(7196) = -Acc;
	Acc = Acc * -3 / 4 + MEM(6211) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(6202) / 4 + tmp_1 / 2;
	MEM(6203) = Acc;
	*out_left = tmp_5;
	Acc = MEM(6202) + tmp_b;
	MEM(10675) = Acc;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 19: 1.4 Sec LARGE WARM */
void midiverb_effect_19(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(13582) / 4 + -MEM(9082) / 4 + -MEM(5085) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(12692) / 4 + -MEM(9783) / 4 + -MEM(6017) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(2414) / 2;
	MEM(2415) = Acc;
	Acc = MEM(2414) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14957) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14957) + MEM(14147) / 2;
	MEM(14955) = -Acc;
	Acc = -Acc / 2 + MEM(14147) + MEM(13941) / 2;
	MEM(14145) = -Acc;
	Acc = -Acc / 2 + MEM(13941) + MEM(13795) / 2;
	MEM(13939) = -Acc;
	Acc = -Acc / 2 + MEM(13795);
	tmp_2 = Acc;
	Acc = MEM(12069) * 3 / 4 + MEM(10475) / 2;
	MEM(12067) = -Acc;
	Acc = -Acc / 2 + MEM(10475);
	MEM(10473) = Acc;
	Acc = MEM(8563) * 5 / 8 + MEM(6490) / 2;
	MEM(8561) = -Acc;
	Acc = -Acc / 2 + MEM(6490);
	MEM(6488) = Acc;
	Acc = MEM(4631) * 5 / 8 + MEM(2417) / 2;
	MEM(4629) = -Acc;
	Acc = MEM(2411) / 2;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + MEM(2411) / 2 + tmp_1 / 2;
	MEM(2412) = Acc;
	Acc = MEM(2412) + tmp_2;
	MEM(13793) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 20: 1.4 Sec LARGE DARK */
void midiverb_effect_20(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12730) / 4 + -MEM(7630) / 4 + -MEM(3233) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11840) / 4 + -MEM(8331) / 4 + -MEM(3965) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(362) / 2;
	MEM(363) = Acc;
	Acc = MEM(362) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14757) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14757) + MEM(13335) / 2;
	MEM(14755) = -Acc;
	Acc = -Acc / 2 + MEM(13335) + MEM(13099) / 2;
	MEM(13333) = -Acc;
	Acc = -Acc / 2 + MEM(13099) + MEM(12943) / 2;
	MEM(13097) = -Acc;
	Acc = -Acc / 2 + MEM(12943);
	tmp_2 = Acc;
	Acc = MEM(11017) * 3 / 4 + MEM(9023) / 2;
	MEM(11015) = -Acc;
	Acc = -Acc / 2 + MEM(9023);
	MEM(9021) = Acc;
	Acc = MEM(7011) / 2 + MEM(4638) / 2;
	MEM(7009) = -Acc;
	Acc = -Acc / 2 + MEM(4638);
	MEM(4636) = Acc;
	Acc = MEM(2979) / 2 + MEM(365) / 2;
	MEM(2977) = -Acc;
	Acc = -Acc / 2 + MEM(365);
	tmp_1 = Acc;
	Acc = MEM(359) / 2 + tmp_1 / 2;
	MEM(360) = Acc;
	Acc = MEM(360) + tmp_2;
	MEM(12941) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 21: 1.4 Sec MEDIUM WARM */
void midiverb_effect_21(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(13285) / 2 + MEM(9495) / 2 + MEM(6098) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = MEM(12430) / 2 + MEM(9996) / 2 + MEM(6930) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = MEM(16383) / 2 + MEM(3727) / 2;
	MEM(3728) = Acc;
	Acc = MEM(3727) * 81 / 32 + MEM(16130) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16130) + MEM(15697) / 2;
	MEM(16128) = -Acc;
	Acc = -Acc / 2 + MEM(15697) + MEM(14927) / 2;
	MEM(15695) = -Acc;
	Acc = -Acc / 2 + MEM(14927) + MEM(13605) / 2;
	MEM(14925) = -Acc;
	Acc = -Acc / 2 + MEM(13605) + MEM(13414) / 2;
	MEM(13603) = -Acc;
	Acc = -Acc / 2 + MEM(13414) + MEM(13308) / 2;
	MEM(13412) = -Acc;
	Acc = -Acc / 2 + MEM(13308);
	tmp_2 = Acc;
	Acc = MEM(12182) * 3 / 4 + MEM(10888) / 2;
	MEM(12180) = -Acc;
	Acc = -Acc / 2 + MEM(10888);
	MEM(10886) = Acc;
	Acc = MEM(9476) / 2 + MEM(7603) / 2;
	MEM(9474) = -Acc;
	Acc = -Acc / 2 + MEM(7603);
	MEM(7601) = Acc;
	Acc = MEM(5944) / 2 + MEM(3730) / 2;
	MEM(5942) = -Acc;
	Acc = Acc * -3 / 4 + MEM(3730) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(3724) / 4 + tmp_1 / 2;
	MEM(3725) = Acc;
	Acc = MEM(3725) + tmp_2;
	MEM(13306) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 22: 1.6 Sec SMALL DARK */
void midiverb_effect_22(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(14799) / 4 + -MEM(12303) / 4 + -MEM(9901) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(14799) / 4 + -MEM(12654) / 4 + -MEM(10566) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(8563) / 2;
	MEM(8564) = Acc;
	Acc = MEM(8563) * 81 / 32 + MEM(16221) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16221) + MEM(16004) / 2;
	MEM(16219) = -Acc;
	Acc = -Acc / 2 + MEM(16004) + MEM(15568) / 2;
	MEM(16002) = -Acc;
	Acc = -Acc / 2 + MEM(15568) + MEM(15009) / 2;
	MEM(15566) = -Acc;
	Acc = -Acc / 2 + MEM(15009) + MEM(14890) / 2;
	MEM(15007) = -Acc;
	Acc = -Acc / 2 + MEM(14890) + MEM(14812) / 2;
	MEM(14888) = -Acc;
	Acc = -Acc / 2 + MEM(14812);
	tmp_2 = Acc;
	Acc = MEM(14098) * 5 / 8 + MEM(13101) / 2;
	MEM(14096) = -Acc;
	Acc = -Acc / 2 + MEM(13101);
	MEM(13099) = Acc;
	Acc = MEM(12094) * 3 / 4 + MEM(10904) / 2;
	MEM(12092) = -Acc;
	Acc = -Acc / 2 + MEM(10904);
	MEM(10902) = Acc;
	Acc = MEM(9874) * 3 / 4 + MEM(8566) / 2;
	MEM(9872) = -Acc;
	Acc = -Acc / 2 + MEM(8566);
	tmp_1 = Acc;
	Acc = MEM(8560) / 2 + tmp_1 / 2;
	MEM(8561) = Acc;
	Acc = MEM(8561) + tmp_2;
	MEM(14810) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 23: 1.6 Sec LARGE BRIGHT */
void midiverb_effect_23(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(13388) / 4 + -MEM(8898) / 4 + -MEM(5101) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(12533) / 4 + -MEM(9999) / 4 + -MEM(6133) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14857) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14857) + MEM(13753) / 2;
	MEM(14855) = -Acc;
	Acc = -Acc / 2 + MEM(13753) + MEM(13517) / 2;
	MEM(13751) = -Acc;
	Acc = -Acc / 2 + MEM(13517) + MEM(13411) / 2;
	MEM(13515) = -Acc;
	Acc = -Acc / 2 + MEM(13411);
	tmp_2 = Acc;
	Acc = MEM(11985) * 3 / 4 + MEM(10391) / 2;
	MEM(11983) = -Acc;
	Acc = -Acc / 2 + MEM(10391);
	MEM(10389) = Acc;
	Acc = -MEM(8579) / 4 + MEM(6806) / 2;
	MEM(8577) = -Acc;
	Acc = -Acc / 2 + MEM(6806);
	MEM(6804) = Acc;
	Acc = MEM(4547) * 3 / 4 + MEM(2233) / 2;
	MEM(4545) = -Acc;
	Acc = Acc * -3 / 4 + MEM(2233) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(2227) / 4 + tmp_1 / 2;
	MEM(2228) = Acc;
	Acc = MEM(2228) + tmp_2;
	MEM(13409) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 24: 1.6 Sec MEDIUM BRIGHT */
void midiverb_effect_24(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12820) / 4 + -MEM(8330) / 4 + -MEM(4533) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11965) / 4 + -MEM(8931) / 4 + -MEM(5565) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13235) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13235) + MEM(12999) / 2;
	MEM(13233) = -Acc;
	Acc = -Acc / 2 + MEM(12999) + MEM(12843) / 2;
	MEM(12997) = -Acc;
	Acc = -Acc / 2 + MEM(12843);
	tmp_2 = Acc;
	Acc = MEM(11417) * 3 / 4 + MEM(9823) / 2;
	MEM(11415) = -Acc;
	Acc = -Acc / 2 + MEM(9823);
	MEM(9821) = Acc;
	Acc = MEM(8011) * 3 / 4 + MEM(6238) / 2;
	MEM(8009) = -Acc;
	Acc = -Acc / 2 + MEM(6238);
	MEM(6236) = Acc;
	Acc = MEM(3979) / 2 + MEM(1665) / 2;
	MEM(3977) = -Acc;
	Acc = Acc * -3 / 4 + MEM(1665) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(1659) / 4 + tmp_1 / 2;
	MEM(1660) = Acc;
	Acc = MEM(1660) + tmp_2;
	MEM(12841) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 25: 1.8 Sec LARGE DARK */
void midiverb_effect_25(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12730) / 4 + -MEM(7630) / 4 + -MEM(3433) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11840) / 4 + -MEM(8331) / 4 + -MEM(4165) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(362) / 2;
	MEM(363) = Acc;
	Acc = MEM(362) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14757) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14757) + MEM(13335) / 2;
	MEM(14755) = -Acc;
	Acc = -Acc / 2 + MEM(13335) + MEM(13099) / 2;
	MEM(13333) = -Acc;
	Acc = -Acc / 2 + MEM(13099) + MEM(12943) / 2;
	MEM(13097) = -Acc;
	Acc = -Acc / 2 + MEM(12943);
	tmp_2 = Acc;
	Acc = MEM(11017) * 3 / 4 + MEM(9223) / 2;
	MEM(11015) = -Acc;
	Acc = -Acc / 2 + MEM(9223);
	MEM(9221) = Acc;
	Acc = MEM(7211) / 2 + MEM(4838) / 2;
	MEM(7209) = -Acc;
	Acc = -Acc / 2 + MEM(4838);
	MEM(4836) = Acc;
	Acc = MEM(2979) / 2 + MEM(365) / 2;
	MEM(2977) = -Acc;
	Acc = -Acc / 2 + MEM(365);
	tmp_1 = Acc;
	Acc = MEM(359) / 2 + tmp_1 / 2;
	MEM(360) = Acc;
	Acc = MEM(360) + tmp_2;
	MEM(12941) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 26: 1.8 Sec LARGE BRIGHT */
void midiverb_effect_26(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12730) / 4 + -MEM(7630) / 4 + -MEM(3433) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11840) / 4 + -MEM(8331) / 4 + -MEM(4165) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14757) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14757) + MEM(13335) / 2;
	MEM(14755) = -Acc;
	Acc = -Acc / 2 + MEM(13335) + MEM(13099) / 2;
	MEM(13333) = -Acc;
	Acc = -Acc / 2 + MEM(13099) + MEM(12943) / 2;
	MEM(13097) = -Acc;
	Acc = -Acc / 2 + MEM(12943);
	tmp_2 = Acc;
	Acc = MEM(11017) * 3 / 4 + MEM(9223) / 2;
	MEM(11015) = -Acc;
	Acc = -Acc / 2 + MEM(9223);
	MEM(9221) = Acc;
	Acc = MEM(7211) / 2 + MEM(4838) / 2;
	MEM(7209) = -Acc;
	Acc = -Acc / 2 + MEM(4838);
	MEM(4836) = Acc;
	Acc = MEM(2979) / 2 + MEM(365) / 2;
	MEM(2977) = -Acc;
	Acc = Acc * -3 / 4 + MEM(365) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(359) / 4 + tmp_1 / 2;
	MEM(360) = Acc;
	Acc = MEM(360) + tmp_2;
	MEM(12941) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 27: 1.8 Sec MEDIUM WARM */
void midiverb_effect_27(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12720) / 4 + -MEM(8130) / 4 + -MEM(3833) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11865) / 4 + -MEM(8731) / 4 + -MEM(4865) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(962) / 2;
	MEM(963) = Acc;
	Acc = MEM(962) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13135) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13135) + MEM(12899) / 2;
	MEM(13133) = -Acc;
	Acc = -Acc / 2 + MEM(12899) + MEM(12743) / 2;
	MEM(12897) = -Acc;
	Acc = -Acc / 2 + MEM(12743);
	tmp_2 = Acc;
	Acc = MEM(11117) * 3 / 4 + MEM(9623) / 2;
	MEM(11115) = -Acc;
	Acc = -Acc / 2 + MEM(9623);
	MEM(9621) = Acc;
	Acc = MEM(7511) / 2 + MEM(5538) / 2;
	MEM(7509) = -Acc;
	Acc = -Acc / 2 + MEM(5538);
	MEM(5536) = Acc;
	Acc = MEM(3279) / 2 + MEM(965) / 2;
	MEM(3277) = -Acc;
	Acc = Acc * -3 / 4 + MEM(965) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(959) / 4 + tmp_1 / 2;
	MEM(960) = Acc;
	Acc = MEM(960) + tmp_2;
	MEM(12741) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 28: 2.0 Sec LARGE BRIGHT */
void midiverb_effect_28(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12730) / 4 + -MEM(8130) / 4 + -MEM(4933) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(12140) / 4 + -MEM(8831) / 4 + -MEM(4102) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14757) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14757) + MEM(13335) / 2;
	MEM(14755) = -Acc;
	Acc = -Acc / 2 + MEM(13335) + MEM(13099) / 2;
	MEM(13333) = -Acc;
	Acc = -Acc / 2 + MEM(13099) + MEM(12943) / 2;
	MEM(13097) = -Acc;
	Acc = -Acc / 2 + MEM(12943);
	tmp_2 = Acc;
	Acc = MEM(11517) * 3 / 4 + MEM(9723) / 2;
	MEM(11515) = -Acc;
	Acc = -Acc / 2 + MEM(9723);
	MEM(9721) = Acc;
	Acc = MEM(7711) / 2 + MEM(5338) / 2;
	MEM(7709) = -Acc;
	Acc = -Acc / 2 + MEM(5338);
	MEM(5336) = Acc;
	Acc = MEM(2979) / 2 + MEM(365) / 2;
	MEM(2977) = -Acc;
	Acc = Acc * -3 / 4 + MEM(365) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(359) / 4 + tmp_1 / 2;
	MEM(360) = Acc;
	Acc = MEM(360) + tmp_2;
	MEM(12941) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 29: 2.0 Sec MEDIUM WARM */
void midiverb_effect_29(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12620) / 4 + -MEM(7530) / 4 + -MEM(3733) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11852) / 4 + -MEM(8531) / 4 + -MEM(4465) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(662) / 2;
	MEM(663) = Acc;
	Acc = MEM(662) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035) + MEM(12799) / 2;
	MEM(13033) = -Acc;
	Acc = -Acc / 2 + MEM(12799) + MEM(12643) / 2;
	MEM(12797) = -Acc;
	Acc = -Acc / 2 + MEM(12643);
	tmp_2 = Acc;
	Acc = MEM(11017) * 15 / 16 + MEM(9423) / 2;
	MEM(11015) = -Acc;
	Acc = -Acc / 2 + MEM(9423);
	MEM(9421) = Acc;
	Acc = MEM(7411) * 3 / 4 + MEM(5138) / 2;
	MEM(7409) = -Acc;
	Acc = -Acc / 2 + MEM(5138);
	MEM(5136) = Acc;
	Acc = MEM(2979) / 2 + MEM(665) / 2;
	MEM(2977) = -Acc;
	Acc = Acc * -3 / 4 + MEM(665) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(659) / 4 + tmp_1 / 2;
	MEM(660) = Acc;
	Acc = MEM(660) + tmp_2;
	MEM(12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 30: 2.0 Sec LARGE WARM */
void midiverb_effect_30(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(13220) / 4 + -MEM(8230) / 4 + -MEM(3433) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(12440) / 4 + -MEM(8931) / 4 + -MEM(4765) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(762) / 2;
	MEM(763) = Acc;
	Acc = MEM(762) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14757) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14757) + MEM(13635) / 2;
	MEM(14755) = -Acc;
	Acc = -Acc / 2 + MEM(13635) + MEM(13399) / 2;
	MEM(13633) = -Acc;
	Acc = -Acc / 2 + MEM(13399) + MEM(13243) / 2;
	MEM(13397) = -Acc;
	Acc = -Acc / 2 + MEM(13243);
	tmp_2 = Acc;
	Acc = MEM(11817) * 3 / 4 + MEM(9823) / 2;
	MEM(11815) = -Acc;
	Acc = -Acc / 2 + MEM(9823);
	MEM(9821) = Acc;
	Acc = MEM(7811) * 3 / 4 + MEM(5438) / 2;
	MEM(7809) = -Acc;
	Acc = -Acc / 2 + MEM(5438);
	MEM(5436) = Acc;
	Acc = MEM(3379) * 5 / 8 + MEM(765) / 2;
	MEM(3377) = -Acc;
	Acc = Acc * -3 / 4 + MEM(765) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(759) / 4 + tmp_1 / 2;
	MEM(760) = Acc;
	Acc = MEM(760) + tmp_2;
	MEM(13241) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 31: 2.5 Sec MEDIUM WARM */
void midiverb_effect_31(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12620) / 4 + -MEM(7130) / 4 + -MEM(2533) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11631) / 4 + -MEM(8131) / 4 + -MEM(3865) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(62) / 2;
	MEM(63) = Acc;
	Acc = MEM(62) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035) + MEM(12799) / 2;
	MEM(13033) = -Acc;
	Acc = -Acc / 2 + MEM(12799) + MEM(12643) / 2;
	MEM(12797) = -Acc;
	Acc = -Acc / 2 + MEM(12643);
	tmp_2 = Acc;
	Acc = MEM(11017) * 15 / 16 + MEM(9023) / 2;
	MEM(11015) = -Acc;
	Acc = -Acc / 2 + MEM(9023);
	MEM(9021) = Acc;
	Acc = MEM(6911) * 3 / 4 + MEM(4538) / 2;
	MEM(6909) = -Acc;
	Acc = -Acc / 2 + MEM(4538);
	MEM(4536) = Acc;
	Acc = MEM(2379) / 2 + MEM(65) / 2;
	MEM(2377) = -Acc;
	Acc = Acc * -3 / 4 + MEM(65) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(59) / 4 + tmp_1 / 2;
	MEM(60) = Acc;
	Acc = MEM(60) + tmp_2;
	MEM(12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 32: 2.5 Sec LARGE BRIGHT */
void midiverb_effect_32(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(13220) / 4 + -MEM(8030) / 4 + -MEM(3033) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(12440) / 4 + -MEM(8731) / 4 + -MEM(4365) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14757) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14757) + MEM(13635) / 2;
	MEM(14755) = -Acc;
	Acc = -Acc / 2 + MEM(13635) + MEM(13399) / 2;
	MEM(13633) = -Acc;
	Acc = -Acc / 2 + MEM(13399) + MEM(13243) / 2;
	MEM(13397) = -Acc;
	Acc = -Acc / 2 + MEM(13243);
	tmp_2 = Acc;
	Acc = MEM(11617) + MEM(9623) / 2;
	MEM(11615) = -Acc;
	Acc = -Acc / 2 + MEM(9623);
	MEM(9621) = Acc;
	Acc = MEM(7511) * 3 / 4 + MEM(5038) / 2;
	MEM(7509) = -Acc;
	Acc = -Acc / 2 + MEM(5038);
	MEM(5036) = Acc;
	Acc = MEM(2779) / 2 + MEM(165) / 2;
	MEM(2777) = -Acc;
	Acc = Acc * -3 / 4 + MEM(165) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(159) / 4 + tmp_1 / 2;
	MEM(160) = Acc;
	Acc = MEM(160) + tmp_2;
	MEM(13241) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 33: 2.5 Sec MEDIUM DARK */
void midiverb_effect_33(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(13220) / 4 + -MEM(8230) / 4 + -MEM(3433) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(12440) / 4 + -MEM(8931) / 4 + -MEM(4765) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(762) / 2;
	MEM(763) = Acc;
	Acc = MEM(762) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14757) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14757) + MEM(13635) / 2;
	MEM(14755) = -Acc;
	Acc = -Acc / 2 + MEM(13635) + MEM(13399) / 2;
	MEM(13633) = -Acc;
	Acc = -Acc / 2 + MEM(13399) + MEM(13243) / 2;
	MEM(13397) = -Acc;
	Acc = -Acc / 2 + MEM(13243);
	tmp_2 = Acc;
	Acc = MEM(11817) * 5 / 8 + MEM(9823) / 2;
	MEM(11815) = -Acc;
	Acc = -Acc / 2 + MEM(9823);
	MEM(9821) = Acc;
	Acc = MEM(7811) * 3 / 4 + MEM(5438) / 2;
	MEM(7809) = -Acc;
	Acc = -Acc / 2 + MEM(5438);
	MEM(5436) = Acc;
	Acc = MEM(3379) * 3 / 4 + MEM(765) / 2;
	MEM(3377) = -Acc;
	Acc = -Acc / 2 + MEM(765);
	tmp_1 = Acc;
	Acc = MEM(759) / 2 + tmp_1 / 2;
	MEM(760) = Acc;
	Acc = MEM(760) + tmp_2;
	MEM(13241) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 34: 2.8 Sec SMALL BRIGHT */
void midiverb_effect_34(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(14356) / 4 + -MEM(10669) / 4 + -MEM(7589) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(13876) / 4 + -MEM(11170) / 4 + -MEM(8274) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) * 81 / 32 + MEM(16160) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16160) + MEM(15857) / 2;
	MEM(16158) = -Acc;
	Acc = -Acc / 2 + MEM(15857) + MEM(15366) / 2;
	MEM(15855) = -Acc;
	Acc = -Acc / 2 + MEM(15366) + MEM(14643) / 2;
	MEM(15364) = -Acc;
	Acc = -Acc / 2 + MEM(14643) + MEM(14470) / 2;
	MEM(14641) = -Acc;
	Acc = -Acc / 2 + MEM(14470) + MEM(14379) / 2;
	MEM(14468) = -Acc;
	Acc = -Acc / 2 + MEM(14379);
	tmp_2 = Acc;
	Acc = MEM(13756) * 3 / 4 + MEM(12062) / 2;
	MEM(13754) = -Acc;
	Acc = -Acc / 2 + MEM(12062);
	MEM(12060) = Acc;
	Acc = MEM(10750) * 15 / 16 + MEM(8947) / 2;
	MEM(10748) = -Acc;
	Acc = -Acc / 2 + MEM(8947);
	MEM(8945) = Acc;
	Acc = MEM(7488) * -27 / 32 + MEM(5910) / 2;
	MEM(7486) = -Acc;
	Acc = Acc * -3 / 4 + MEM(5910) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(5904) / 4 + tmp_1 / 2;
	MEM(5905) = Acc;
	Acc = MEM(5905) + tmp_2;
	MEM(14377) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 35: 2.8 Sec MEDIUM BRIGHT */
void midiverb_effect_35(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12620) / 4 + -MEM(7930) / 4 + -MEM(3933) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11840) / 4 + -MEM(8731) / 4 + -MEM(5165) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035) + MEM(12799) / 2;
	MEM(13033) = -Acc;
	Acc = -Acc / 2 + MEM(12799) + MEM(12643) / 2;
	MEM(12797) = -Acc;
	Acc = -Acc / 2 + MEM(12643);
	tmp_2 = Acc;
	Acc = MEM(11217) * 3 / 4 + MEM(9623) / 2;
	MEM(11215) = -Acc;
	Acc = -Acc / 2 + MEM(9623);
	MEM(9621) = Acc;
	Acc = MEM(7911) * 3 / 4 + MEM(5838) / 2;
	MEM(7909) = -Acc;
	Acc = -Acc / 2 + MEM(5838);
	MEM(5836) = Acc;
	Acc = MEM(3879) * -27 / 32 + MEM(1565) / 2;
	MEM(3877) = -Acc;
	Acc = Acc * -3 / 4 + MEM(1565) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(1559) / 4 + tmp_1 / 2;
	MEM(1560) = Acc;
	Acc = MEM(1560) + tmp_2;
	MEM(12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 36: 3.0 Sec LARGE BRIGHT */
void midiverb_effect_36(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12620) / 4 + -MEM(7130) / 4 + -MEM(2533) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11631) / 4 + -MEM(8131) / 4 + -MEM(3865) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035) + MEM(12799) / 2;
	MEM(13033) = -Acc;
	Acc = -Acc / 2 + MEM(12799) + MEM(12643) / 2;
	MEM(12797) = -Acc;
	Acc = -Acc / 2 + MEM(12643);
	tmp_2 = Acc;
	Acc = MEM(11017) + MEM(9023) / 2;
	MEM(11015) = -Acc;
	Acc = -Acc / 2 + MEM(9023);
	MEM(9021) = Acc;
	Acc = MEM(6911) * 15 / 16 + MEM(4538) / 2;
	MEM(6909) = -Acc;
	Acc = -Acc / 2 + MEM(4538);
	MEM(4536) = Acc;
	Acc = MEM(2379) / 2 + MEM(65) / 2;
	MEM(2377) = -Acc;
	Acc = Acc * -3 / 4 + MEM(65) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(59) / 4 + tmp_1 / 2;
	MEM(60) = Acc;
	Acc = MEM(60) + tmp_2;
	MEM(12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 37: 3.0 Sec LARGE WARM */
void midiverb_effect_37(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12620) / 4 + -MEM(7130) / 4 + -MEM(2533) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11631) / 4 + -MEM(8131) / 4 + -MEM(3865) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(62) / 2;
	MEM(63) = Acc;
	Acc = MEM(62) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035) + MEM(12799) / 2;
	MEM(13033) = -Acc;
	Acc = -Acc / 2 + MEM(12799) + MEM(12643) / 2;
	MEM(12797) = -Acc;
	Acc = -Acc / 2 + MEM(12643);
	tmp_2 = Acc;
	Acc = MEM(11017) + MEM(9023) / 2;
	MEM(11015) = -Acc;
	Acc = -Acc / 2 + MEM(9023);
	MEM(9021) = Acc;
	Acc = MEM(6911) * 15 / 16 + MEM(4538) / 2;
	MEM(6909) = -Acc;
	Acc = -Acc / 2 + MEM(4538);
	MEM(4536) = Acc;
	Acc = MEM(2379) / 2 + MEM(65) / 2;
	MEM(2377) = -Acc;
	Acc = Acc * -3 / 4 + MEM(65) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(59) / 4 + tmp_1 / 2;
	MEM(60) = Acc;
	Acc = MEM(60) + tmp_2;
	MEM(12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 38: 3.0 Sec MEDIUM DARK */
void midiverb_effect_38(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(13420) / 4 + -MEM(8230) / 4 + -MEM(3733) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(12640) / 4 + -MEM(8931) / 4 + -MEM(5065) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(762) / 2;
	MEM(763) = Acc;
	Acc = MEM(762) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14857) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14857) + MEM(13835) / 2;
	MEM(14855) = -Acc;
	Acc = -Acc / 2 + MEM(13835) + MEM(13599) / 2;
	MEM(13833) = -Acc;
	Acc = -Acc / 2 + MEM(13599) + MEM(13443) / 2;
	MEM(13597) = -Acc;
	Acc = -Acc / 2 + MEM(13443);
	tmp_2 = Acc;
	Acc = MEM(11817) * 3 / 4 + MEM(9823) / 2;
	MEM(11815) = -Acc;
	Acc = -Acc / 2 + MEM(9823);
	MEM(9821) = Acc;
	Acc = MEM(8111) * 3 / 4 + MEM(5738) / 2;
	MEM(8109) = -Acc;
	Acc = -Acc / 2 + MEM(5738);
	MEM(5736) = Acc;
	Acc = MEM(3379) * -27 / 32 + MEM(765) / 2;
	MEM(3377) = -Acc;
	Acc = -Acc / 2 + MEM(765);
	tmp_1 = Acc;
	Acc = MEM(759) / 2 + tmp_1 / 2;
	MEM(760) = Acc;
	Acc = MEM(760) + tmp_2;
	MEM(13441) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 39: 3.5 Sec LARGE BRIGHT */
void midiverb_effect_39(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12620) / 4 + -MEM(7130) / 4 + -MEM(2533) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11840) / 4 + -MEM(8131) / 4 + -MEM(3865) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035) + MEM(12799) / 2;
	MEM(13033) = -Acc;
	Acc = -Acc / 2 + MEM(12799) + MEM(12643) / 2;
	MEM(12797) = -Acc;
	Acc = -Acc / 2 + MEM(12643);
	tmp_2 = Acc;
	Acc = MEM(11017) * -27 / 32 + MEM(9023) / 2;
	MEM(11015) = -Acc;
	Acc = -Acc / 2 + MEM(9023);
	MEM(9021) = Acc;
	Acc = MEM(6911) * -27 / 32 + MEM(4538) / 2;
	MEM(6909) = -Acc;
	Acc = -Acc / 2 + MEM(4538);
	MEM(4536) = Acc;
	Acc = MEM(2379) * 3 / 4 + MEM(65) / 2;
	MEM(2377) = -Acc;
	Acc = Acc * -3 / 4 + MEM(65) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(59) / 4 + tmp_1 / 2;
	MEM(60) = Acc;
	Acc = MEM(60) + tmp_2;
	MEM(12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 40: 3.5 Sec MEDIUM WARM */
void midiverb_effect_40(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12620) / 4 + -MEM(7130) / 4 + -MEM(2833) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11740) / 4 + -MEM(8031) / 4 + -MEM(3965) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(62) / 2;
	MEM(63) = Acc;
	Acc = MEM(62) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035) + MEM(12799) / 2;
	MEM(13033) = -Acc;
	Acc = -Acc / 2 + MEM(12799) + MEM(12643) / 2;
	MEM(12797) = -Acc;
	Acc = -Acc / 2 + MEM(12643);
	tmp_2 = Acc;
	Acc = MEM(11017) * 3 / 4 + MEM(9023) / 2;
	MEM(11015) = -Acc;
	Acc = -Acc / 2 + MEM(9023);
	MEM(9021) = Acc;
	Acc = MEM(6911) * 3 / 4 + MEM(4538) / 2;
	MEM(6909) = -Acc;
	Acc = -Acc / 2 + MEM(4538);
	MEM(4536) = Acc;
	Acc = MEM(2379) * -27 / 32 + MEM(65) / 2;
	MEM(2377) = -Acc;
	Acc = Acc * -3 / 4 + MEM(65) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(59) / 4 + tmp_1 / 2;
	MEM(60) = Acc;
	Acc = MEM(60) + tmp_2;
	MEM(12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 41: 4.0 Sec LARGE DARK */
void midiverb_effect_41(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12620) / 4 + -MEM(7130) / 4 + -MEM(2533) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11631) / 4 + -MEM(8131) / 4 + -MEM(3865) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(62) / 2;
	MEM(63) = Acc;
	Acc = MEM(62) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035) + MEM(12799) / 2;
	MEM(13033) = -Acc;
	Acc = -Acc / 2 + MEM(12799) + MEM(12643) / 2;
	MEM(12797) = -Acc;
	Acc = -Acc / 2 + MEM(12643);
	tmp_2 = Acc;
	Acc = MEM(11017) * -27 / 32 + MEM(9023) / 2;
	MEM(11015) = -Acc;
	Acc = -Acc / 2 + MEM(9023);
	MEM(9021) = Acc;
	Acc = MEM(6911) * 15 / 16 + MEM(4538) / 2;
	MEM(6909) = -Acc;
	Acc = -Acc / 2 + MEM(4538);
	MEM(4536) = Acc;
	Acc = MEM(2379) * 3 / 4 + MEM(65) / 2;
	MEM(2377) = -Acc;
	Acc = -Acc / 2 + MEM(65);
	tmp_1 = Acc;
	Acc = MEM(59) / 2 + tmp_1 / 2;
	MEM(60) = Acc;
	Acc = MEM(60) + tmp_2;
	MEM(12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 42: 4.0 Sec MEDIUM BRIGHT */
void midiverb_effect_42(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12620) / 4 + -MEM(7130) / 4 + -MEM(2533) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11840) / 4 + -MEM(8131) / 4 + -MEM(3865) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035) + MEM(12799) / 2;
	MEM(13033) = -Acc;
	Acc = -Acc / 2 + MEM(12799) + MEM(12643) / 2;
	MEM(12797) = -Acc;
	Acc = -Acc / 2 + MEM(12643);
	tmp_2 = Acc;
	Acc = MEM(11017) * 3 / 4 + MEM(9023) / 2;
	MEM(11015) = -Acc;
	Acc = -Acc / 2 + MEM(9023);
	MEM(9021) = Acc;
	Acc = MEM(6911) * 15 / 16 + MEM(4538) / 2;
	MEM(6909) = -Acc;
	Acc = -Acc / 2 + MEM(4538);
	MEM(4536) = Acc;
	Acc = MEM(2379) * -27 / 32 + MEM(65) / 2;
	MEM(2377) = -Acc;
	Acc = Acc * -3 / 4 + MEM(65) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(59) / 4 + tmp_1 / 2;
	MEM(60) = Acc;
	Acc = MEM(60) + tmp_2;
	MEM(12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 43: 5 Sec LARGE WARM */
void midiverb_effect_43(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12620) / 4 + -MEM(7430) / 4 + -MEM(2833) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11631) / 4 + -MEM(8431) / 4 + -MEM(4165) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(62) / 2;
	MEM(63) = Acc;
	Acc = MEM(62) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035) + MEM(12799) / 2;
	MEM(13033) = -Acc;
	Acc = -Acc / 2 + MEM(12799) + MEM(12643) / 2;
	MEM(12797) = -Acc;
	Acc = -Acc / 2 + MEM(12643);
	tmp_2 = Acc;
	Acc = MEM(11317) + MEM(9323) / 2;
	MEM(11315) = -Acc;
	Acc = -Acc / 2 + MEM(9323);
	MEM(9321) = Acc;
	Acc = MEM(7211) * 15 / 16 + MEM(4838) / 2;
	MEM(7209) = -Acc;
	Acc = -Acc / 2 + MEM(4838);
	MEM(4836) = Acc;
	Acc = MEM(2579) * 3 / 4 + MEM(65) / 2;
	MEM(2577) = -Acc;
	Acc = Acc * -3 / 4 + MEM(65) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(59) / 4 + tmp_1 / 2;
	MEM(60) = Acc;
	Acc = MEM(60) + tmp_2;
	MEM(12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 44: 8 Sec LARGE BRIGHT */
void midiverb_effect_44(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12620) / 4 + -MEM(7130) / 4 + -MEM(2833) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11740) / 4 + -MEM(8031) / 4 + -MEM(3965) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035) + MEM(12799) / 2;
	MEM(13033) = -Acc;
	Acc = -Acc / 2 + MEM(12799) + MEM(12643) / 2;
	MEM(12797) = -Acc;
	Acc = -Acc / 2 + MEM(12643);
	tmp_2 = Acc;
	Acc = MEM(11017) * 15 / 16 + MEM(9023) / 2;
	MEM(11015) = -Acc;
	Acc = -Acc / 2 + MEM(9023);
	MEM(9021) = Acc;
	Acc = MEM(6911) * 15 / 16 + MEM(4538) / 2;
	MEM(6909) = -Acc;
	Acc = -Acc / 2 + MEM(4538);
	MEM(4536) = Acc;
	Acc = MEM(2379) * -27 / 32 + MEM(65) / 2;
	MEM(2377) = -Acc;
	Acc = Acc * -3 / 4 + MEM(65) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(59) / 4 + tmp_1 / 2;
	MEM(60) = Acc;
	Acc = MEM(60) + tmp_2;
	MEM(12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 45: 8 Sec LARGE WARM */
void midiverb_effect_45(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12620) / 4 + -MEM(7130) / 4 + -MEM(2533) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11631) / 4 + -MEM(8131) / 4 + -MEM(3865) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(62) / 2;
	MEM(63) = Acc;
	Acc = MEM(62) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035) + MEM(12799) / 2;
	MEM(13033) = -Acc;
	Acc = -Acc / 2 + MEM(12799) + MEM(12643) / 2;
	MEM(12797) = -Acc;
	Acc = -Acc / 2 + MEM(12643);
	tmp_2 = Acc;
	Acc = MEM(11017) * 15 / 16 + MEM(9023) / 2;
	MEM(11015) = -Acc;
	Acc = -Acc / 2 + MEM(9023);
	MEM(9021) = Acc;
	Acc = MEM(6911) * 15 / 16 + MEM(4538) / 2;
	MEM(6909) = -Acc;
	Acc = -Acc / 2 + MEM(4538);
	MEM(4536) = Acc;
	Acc = MEM(2379) * -27 / 32 + MEM(65) / 2;
	MEM(2377) = -Acc;
	Acc = Acc * -3 / 4 + MEM(65) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(59) / 4 + tmp_1 / 2;
	MEM(60) = Acc;
	Acc = MEM(60) + tmp_2;
	MEM(12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 46: 10 Sec LARGE BRIGHT */
void midiverb_effect_46(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12620) / 4 + -MEM(7130) / 4 + -MEM(2533) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11631) / 4 + -MEM(8131) / 4 + -MEM(3865) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035) + MEM(12799) / 2;
	MEM(13033) = -Acc;
	Acc = -Acc / 2 + MEM(12799) + MEM(12643) / 2;
	MEM(12797) = -Acc;
	Acc = -Acc / 2 + MEM(12643);
	tmp_2 = Acc;
	Acc = MEM(11017) + MEM(9023) / 2;
	MEM(11015) = -Acc;
	Acc = -Acc / 2 + MEM(9023);
	MEM(9021) = Acc;
	Acc = MEM(6911) * 15 / 16 + MEM(4538) / 2;
	MEM(6909) = -Acc;
	Acc = -Acc / 2 + MEM(4538);
	MEM(4536) = Acc;
	Acc = MEM(2379) * -27 / 32 + MEM(65) / 2;
	MEM(2377) = -Acc;
	Acc = Acc * -3 / 4 + MEM(65) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(62) / 4 + tmp_1 / 2;
	MEM(63) = Acc;
	Acc = MEM(63) + tmp_2;
	MEM(12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 47: 10 Sec LARGE WARM */
void midiverb_effect_47(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12620) / 4 + -MEM(7430) / 4 + -MEM(2433) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11829) / 4 + -MEM(8131) / 4 + -MEM(3565) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(92) / 2;
	MEM(93) = Acc;
	Acc = MEM(92) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035) + MEM(12799) / 2;
	MEM(13033) = -Acc;
	Acc = -Acc / 2 + MEM(12799) + MEM(12643) / 2;
	MEM(12797) = -Acc;
	Acc = -Acc / 2 + MEM(12643);
	tmp_2 = Acc;
	Acc = MEM(11017) + MEM(9023) / 2;
	MEM(11015) = -Acc;
	Acc = -Acc / 2 + MEM(9023);
	MEM(9021) = Acc;
	Acc = MEM(6811) * 15 / 16 + MEM(4438) / 2;
	MEM(6809) = -Acc;
	Acc = -Acc / 2 + MEM(4438);
	MEM(4436) = Acc;
	Acc = MEM(2309) * -27 / 32 + MEM(95) / 2;
	MEM(2307) = -Acc;
	Acc = Acc * -3 / 4 + MEM(95) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(89) / 4 + tmp_1 / 2;
	MEM(90) = Acc;
	Acc = MEM(90) + tmp_2;
	MEM(12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 48: 16 Sec LARGE DARK */
void midiverb_effect_48(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(12644) / 4 + -MEM(7754) / 4 + -MEM(3957) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(11655) / 4 + -MEM(8455) / 4 + -MEM(4689) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(786) / 2;
	MEM(787) = Acc;
	Acc = MEM(786) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035) + MEM(12790) / 2;
	MEM(13033) = -Acc;
	Acc = -Acc / 2 + MEM(12790) + MEM(12667) / 2;
	MEM(12788) = -Acc;
	Acc = -Acc / 2 + MEM(12667);
	tmp_2 = Acc;
	Acc = MEM(11341) + MEM(9347) / 2;
	MEM(11339) = -Acc;
	Acc = -Acc / 2 + MEM(9347);
	MEM(9345) = Acc;
	Acc = MEM(7735) * 15 / 16 + MEM(5362) / 2;
	MEM(7733) = -Acc;
	Acc = -Acc / 2 + MEM(5362);
	MEM(5360) = Acc;
	Acc = MEM(3503) * 15 / 16 + MEM(789) / 2;
	MEM(3501) = -Acc;
	Acc = Acc / 4 + -MEM(789) / 2 + MEM(783) / 2;
	MEM(784) = Acc;
	Acc = MEM(784) + tmp_2;
	MEM(12665) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 49: 18 Sec EX. LARGE BRIGHT */
void midiverb_effect_49(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(13012) / 4 + -MEM(7522) / 4 + -MEM(2925) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(12023) / 4 + -MEM(8523) / 4 + -MEM(4257) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035);
	tmp_2 = Acc;
	Acc = MEM(11409) + MEM(9415) / 2;
	MEM(11407) = -Acc;
	Acc = -Acc / 2 + MEM(9415);
	MEM(9413) = Acc;
	Acc = MEM(7303) * 15 / 16 + MEM(4930) / 2;
	MEM(7301) = -Acc;
	Acc = -Acc / 2 + MEM(4930);
	MEM(4928) = Acc;
	Acc = MEM(2771) * 15 / 16 + MEM(57) / 2;
	MEM(2769) = -Acc;
	Acc = Acc * -3 / 4 + MEM(57) * 3 / 2;
	tmp_1 = Acc;
	Acc = MEM(54) / 4 + tmp_1 / 2;
	MEM(55) = Acc;
	Acc = MEM(55) + tmp_2;
	MEM(13033) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 50: 20 Sec EX. LARGE DARK */
void midiverb_effect_50(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_2, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(13012) / 4 + -MEM(7522) / 4 + -MEM(2925) / 4;
	tmp_3 = -Acc;
	Acc = -MEM(12023) / 4 + -MEM(8523) / 4 + -MEM(4257) / 4;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(54) / 2;
	MEM(55) = Acc;
	Acc = MEM(54) * 81 / 32 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13035) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(13035);
	tmp_2 = Acc;
	Acc = MEM(11409) + MEM(9415) / 2;
	MEM(11407) = -Acc;
	Acc = -Acc / 2 + MEM(9415);
	MEM(9413) = Acc;
	Acc = MEM(7303) * 15 / 16 + MEM(4930) / 2;
	MEM(7301) = -Acc;
	Acc = -Acc / 2 + MEM(4930);
	MEM(4928) = Acc;
	Acc = MEM(2771) * 15 / 16 + MEM(57) / 2;
	MEM(2769) = -Acc;
	Acc = Acc / 4 + -MEM(57) / 2 + MEM(51) / 2;
	MEM(52) = Acc;
	Acc = MEM(52) + tmp_2;
	MEM(13033) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 51: Gated 100 MS */
void midiverb_effect_51(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = -Acc / 2 + MEM(2047);
	MEM(3) = Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = -Acc / 2 + MEM(1801);
	tmp_5 = Acc;
	Acc = MEM(16221) / 2 + MEM(16151) / 2 + MEM(15972) / 2 + MEM(15850) / 2 + MEM(15623) / 2 + MEM(15509) / 2 + MEM(15319) / 2 + MEM(15265) / 2 + MEM(15151) / 2 + MEM(14950) / 2 + MEM(14829) / 2 + MEM(14642) / 2 + MEM(14522) / 2 + MEM(14338) / 2 + MEM(14235) / 2 + MEM(14128) / 2 + MEM(13941) / 2;
	MEM(11) = Acc;
	*out_left = tmp_5;
	*out_right = MEM(3);
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 52: Gated 150 MS */
void midiverb_effect_52(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = -Acc / 2 + MEM(2047);
	MEM(3) = Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = -Acc / 2 + MEM(1801);
	tmp_5 = Acc;
	Acc = MEM(16221) / 2 + MEM(16151) / 2 + MEM(15972) / 2 + MEM(15850) / 2 + MEM(15623) / 2 + MEM(15509) / 2 + MEM(15319) / 2 + MEM(15265) / 2 + MEM(15151) / 2 + MEM(14950) / 2 + MEM(14829) / 2 + MEM(14642) / 2 + MEM(14522) / 2 + MEM(14338) / 2 + MEM(14235) / 2 + MEM(14128) / 2 + MEM(13941) / 2 + MEM(13805) / 2 + MEM(13663) / 2 + MEM(13511) / 2 + MEM(13348) / 2 + MEM(13263) / 2 + MEM(13117) / 2 + MEM(12933) / 2 + MEM(12815) / 2;
	MEM(11) = Acc;
	*out_left = tmp_5;
	*out_right = MEM(3);
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 53: Gated 200 MS */
void midiverb_effect_53(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = -Acc / 2 + MEM(2047);
	MEM(3) = Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = -Acc / 2 + MEM(1801);
	tmp_5 = Acc;
	Acc = MEM(16221) / 2 + MEM(16151) / 2 + MEM(15972) / 2 + MEM(15850) / 2 + MEM(15623) / 2 + MEM(15509) / 2 + MEM(15319) / 2 + MEM(15265) / 2 + MEM(15151) / 2 + MEM(14950) / 2 + MEM(14829) / 2 + MEM(14642) / 2 + MEM(14522) / 2 + MEM(14338) / 2 + MEM(14235) / 2 + MEM(14128) / 2 + MEM(13941) / 2 + MEM(13805) / 2 + MEM(13663) / 2 + MEM(13511) / 2 + MEM(13348) / 2 + MEM(13263) / 2 + MEM(13117) / 2 + MEM(12933) / 2 + MEM(12815) / 2 + MEM(12659) / 2 + MEM(12495) / 2 + MEM(12350) / 2 + MEM(12232) / 2 + MEM(12127) / 2 + MEM(11892) / 2 + MEM(11828) / 2;
	MEM(11) = Acc;
	*out_left = tmp_5;
	*out_right = MEM(3);
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 54: Gated 250 MS */
void midiverb_effect_54(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = -Acc / 2 + MEM(2047);
	MEM(3) = Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = -Acc / 2 + MEM(1801);
	tmp_5 = Acc;
	Acc = MEM(16221) / 2 + MEM(16151) / 2 + MEM(15972) / 2 + MEM(15850) / 2 + MEM(15623) / 2 + MEM(15509) / 2 + MEM(15319) / 2 + MEM(15265) / 2 + MEM(15151) / 2 + MEM(14950) / 2 + MEM(14829) / 2 + MEM(14642) / 2 + MEM(14522) / 2 + MEM(14338) / 2 + MEM(14235) / 2 + MEM(14128) / 2 + MEM(13941) / 2 + MEM(13805) / 2 + MEM(13663) / 2 + MEM(13511) / 2 + MEM(13348) / 2 + MEM(13263) / 2 + MEM(13117) / 2 + MEM(12933) / 2 + MEM(12815) / 2 + MEM(12659) / 2 + MEM(12495) / 2 + MEM(12350) / 2 + MEM(12232) / 2 + MEM(12127) / 2 + MEM(11892) / 2 + MEM(11828) / 2 + MEM(11657) / 2 + MEM(11535) / 2 + MEM(11350) / 2 + MEM(11255) / 2 + MEM(11149) / 2 + MEM(10963) / 2 + MEM(10850) / 2 + MEM(10625) / 2 + MEM(10547) / 2;
	MEM(11) = Acc;
	*out_left = tmp_5;
	*out_right = MEM(3);
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 55: Gated 300 MS */
void midiverb_effect_55(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = -Acc / 2 + MEM(2047);
	MEM(3) = Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = -Acc / 2 + MEM(1801);
	tmp_5 = Acc;
	Acc = MEM(16221) / 2 + MEM(16151) / 2 + MEM(15972) / 2 + MEM(15850) / 2 + MEM(15623) / 2 + MEM(15509) / 2 + MEM(15319) / 2 + MEM(15265) / 2 + MEM(15151) / 2 + MEM(14950) / 2 + MEM(14829) / 2 + MEM(14642) / 2 + MEM(14522) / 2 + MEM(14338) / 2 + MEM(14235) / 2 + MEM(14128) / 2 + MEM(13941) / 2 + MEM(13805) / 2 + MEM(13663) / 2 + MEM(13511) / 2 + MEM(13348) / 2 + MEM(13263) / 2 + MEM(13117) / 2 + MEM(12933) / 2 + MEM(12815) / 2 + MEM(12659) / 2 + MEM(12495) / 2 + MEM(12350) / 2 + MEM(12232) / 2 + MEM(12127) / 2 + MEM(11892) / 2 + MEM(11828) / 2 + MEM(11657) / 2 + MEM(11535) / 2 + MEM(11350) / 2 + MEM(11255) / 2 + MEM(11149) / 2 + MEM(10963) / 2 + MEM(10850) / 2 + MEM(10625) / 2 + MEM(10547) / 2 + MEM(10349) / 2 + MEM(10225) / 2 + MEM(10161) / 2 + MEM(9938) / 2 + MEM(9850) / 2 + MEM(9602) / 2 + MEM(9525) / 2 + MEM(9345) / 2;
	MEM(11) = Acc;
	*out_left = tmp_5;
	*out_right = MEM(3);
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 56: Gated 350 MS */
void midiverb_effect_56(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = -Acc / 2 + MEM(2047);
	MEM(3) = Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = -Acc / 2 + MEM(1801);
	tmp_5 = Acc;
	Acc = MEM(16221) / 2 + MEM(16151) / 2 + MEM(15972) / 2 + MEM(15850) / 2 + MEM(15623) / 2 + MEM(15509) / 2 + MEM(15319) / 2 + MEM(15265) / 2 + MEM(15151) / 2 + MEM(14950) / 2 + MEM(14829) / 2 + MEM(14642) / 2 + MEM(14522) / 2 + MEM(14338) / 2 + MEM(14235) / 2 + MEM(14128) / 2 + MEM(13941) / 2 + MEM(13805) / 2 + MEM(13663) / 2 + MEM(13511) / 2 + MEM(13348) / 2 + MEM(13263) / 2 + MEM(13117) / 2 + MEM(12933) / 2 + MEM(12815) / 2 + MEM(12659) / 2 + MEM(12495) / 2 + MEM(12350) / 2 + MEM(12232) / 2 + MEM(12127) / 2 + MEM(11892) / 2 + MEM(11828) / 2 + MEM(11657) / 2 + MEM(11535) / 2 + MEM(11350) / 2 + MEM(11255) / 2 + MEM(11149) / 2 + MEM(10963) / 2 + MEM(10850) / 2 + MEM(10625) / 2 + MEM(10547) / 2 + MEM(10349) / 2 + MEM(10225) / 2 + MEM(10161) / 2 + MEM(9938) / 2 + MEM(9850) / 2 + MEM(9602) / 2 + MEM(9525) / 2 + MEM(9345) / 2 + MEM(9258) / 2 + MEM(9163) / 2 + MEM(8945) / 2 + MEM(8850) / 2 + MEM(8648) / 2 + MEM(8493) / 2 + MEM(8350) / 2 + MEM(8238) / 2 + MEM(8106) / 2;
	MEM(11) = Acc;
	*out_left = tmp_5;
	*out_right = MEM(3);
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 57: Gated 400 MS */
void midiverb_effect_57(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = -Acc / 2 + MEM(2047);
	MEM(3) = Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = -Acc / 2 + MEM(1801);
	tmp_5 = Acc;
	Acc = MEM(16221) / 2 + MEM(16151) / 2 + MEM(15972) / 2 + MEM(15850) / 2 + MEM(15623) / 2 + MEM(15509) / 2 + MEM(15319) / 2 + MEM(15265) / 2 + MEM(15151) / 2 + MEM(14950) / 2 + MEM(14829) / 2 + MEM(14642) / 2 + MEM(14522) / 2 + MEM(14338) / 2 + MEM(14235) / 2 + MEM(14128) / 2 + MEM(13941) / 2 + MEM(13805) / 2 + MEM(13663) / 2 + MEM(13511) / 2 + MEM(13348) / 2 + MEM(13263) / 2 + MEM(13117) / 2 + MEM(12933) / 2 + MEM(12815) / 2 + MEM(12659) / 2 + MEM(12495) / 2 + MEM(12350) / 2 + MEM(12232) / 2 + MEM(12127) / 2 + MEM(11892) / 2 + MEM(11828) / 2 + MEM(11657) / 2 + MEM(11535) / 2 + MEM(11350) / 2 + MEM(11255) / 2 + MEM(11149) / 2 + MEM(10963) / 2 + MEM(10850) / 2 + MEM(10625) / 2 + MEM(10547) / 2 + MEM(10349) / 2 + MEM(10225) / 2 + MEM(10161) / 2 + MEM(9938) / 2 + MEM(9850) / 2 + MEM(9602) / 2 + MEM(9525) / 2 + MEM(9345) / 2 + MEM(9258) / 2 + MEM(9163) / 2 + MEM(8945) / 2 + MEM(8850) / 2 + MEM(8648) / 2 + MEM(8493) / 2 + MEM(8350) / 2 + MEM(8238) / 2 + MEM(8106) / 2 + MEM(7937) / 2 + MEM(7819) / 2 + MEM(7684) / 2 + MEM(7499) / 2 + MEM(7372) / 2 + MEM(7213) / 2 + MEM(7169) / 2;
	MEM(11) = Acc;
	*out_left = tmp_5;
	*out_right = MEM(3);
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 58: Gated 500 MS */
void midiverb_effect_58(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = -Acc / 2 + MEM(2047);
	MEM(3) = Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = -Acc / 2 + MEM(1801);
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = MEM(16221) / 2 + MEM(16151) / 2 + MEM(15972) / 2 + MEM(15850) / 2 + MEM(15623) / 2 + MEM(15509) / 2 + MEM(15319) / 2 + MEM(15265) / 2 + MEM(15151) / 2 + MEM(14950) / 2 + MEM(14829) / 2 + MEM(14642) / 2 + MEM(14522) / 2 + MEM(14338) / 2 + MEM(14235) / 2 + MEM(14128) / 2 + MEM(13941) / 2 + MEM(13805) / 2 + MEM(13663) / 2 + MEM(13511) / 2 + MEM(13348) / 2 + MEM(13263) / 2 + MEM(13117) / 2 + MEM(12933) / 2 + MEM(12815) / 2 + MEM(12659) / 2 + MEM(12495) / 2 + MEM(12350) / 2 + MEM(12232) / 2 + MEM(12127) / 2 + MEM(11892) / 2 + MEM(11828) / 2 + MEM(11657) / 2 + MEM(11535) / 2 + MEM(11350) / 2 + MEM(11255) / 2 + MEM(11149) / 2 + MEM(10963) / 2 + MEM(10850) / 2 + MEM(10625) / 2 + MEM(10547) / 2 + MEM(10349) / 2 + MEM(10225) / 2 + MEM(10161) / 2 + MEM(9938) / 2 + MEM(9850) / 2 + MEM(9602) / 2 + MEM(9525) / 2 + MEM(9345) / 2 + MEM(9258) / 2 + MEM(9163) / 2 + MEM(8945) / 2 + MEM(8850) / 2 + MEM(8648) / 2 + MEM(8493) / 2 + MEM(8350) / 2 + MEM(8238) / 2 + MEM(8106) / 2 + MEM(7937) / 2 + MEM(7819) / 2 + MEM(7684) / 2 + MEM(7499) / 2 + MEM(7372) / 2 + MEM(7213) / 2 + MEM(7169) / 2 + MEM(6935) / 2 + MEM(6871) / 2 + MEM(6619) / 2 + MEM(6517) / 2 + MEM(6338) / 2 + MEM(6274) / 2 + MEM(6099) / 2 + MEM(5956) / 2 + MEM(5806) / 2 + MEM(5650) / 2 + MEM(5569) / 2 + MEM(5361) / 2 + MEM(5199) / 2 + MEM(5130) / 2 + MEM(4905) / 2;
	MEM(11) = Acc;
	*out_right = MEM(3);
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 59: Gated 600 MS */
void midiverb_effect_59(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = -Acc / 2 + MEM(2047);
	MEM(3) = Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = -Acc / 2 + MEM(1801);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = MEM(3);
	Acc = MEM(16221) / 2 + MEM(16151) / 2 + MEM(15972) / 2 + MEM(15850) / 2 + MEM(15623) / 2 + MEM(15509) / 2 + MEM(15319) / 2 + MEM(15265) / 2 + MEM(15151) / 2 + MEM(14950) / 2 + MEM(14829) / 2 + MEM(14642) / 2 + MEM(14522) / 2 + MEM(14338) / 2 + MEM(14235) / 2 + MEM(14128) / 2 + MEM(13941) / 2 + MEM(13805) / 2 + MEM(13663) / 2 + MEM(13511) / 2 + MEM(13348) / 2 + MEM(13263) / 2 + MEM(13117) / 2 + MEM(12933) / 2 + MEM(12815) / 2 + MEM(12659) / 2 + MEM(12495) / 2 + MEM(12350) / 2 + MEM(12232) / 2 + MEM(12127) / 2 + MEM(11892) / 2 + MEM(11828) / 2 + MEM(11657) / 2 + MEM(11535) / 2 + MEM(11350) / 2 + MEM(11255) / 2 + MEM(11149) / 2 + MEM(10963) / 2 + MEM(10850) / 2 + MEM(10625) / 2 + MEM(10547) / 2 + MEM(10349) / 2 + MEM(10225) / 2 + MEM(10161) / 2 + MEM(9938) / 2 + MEM(9850) / 2 + MEM(9602) / 2 + MEM(9525) / 2 + MEM(9345) / 2 + MEM(9258) / 2 + MEM(9163) / 2 + MEM(8945) / 2 + MEM(8850) / 2 + MEM(8648) / 2 + MEM(8493) / 2 + MEM(8350) / 2 + MEM(8238) / 2 + MEM(8106) / 2 + MEM(7937) / 2 + MEM(7819) / 2 + MEM(7684) / 2 + MEM(7499) / 2 + MEM(7372) / 2 + MEM(7213) / 2 + MEM(7169) / 2 + MEM(6935) / 2 + MEM(6871) / 2 + MEM(6619) / 2 + MEM(6517) / 2 + MEM(6338) / 2 + MEM(6274) / 2 + MEM(6099) / 2 + MEM(5956) / 2 + MEM(5806) / 2 + MEM(5650) / 2 + MEM(5569) / 2 + MEM(5361) / 2 + MEM(5199) / 2 + MEM(5130) / 2 + MEM(4905) / 2 + MEM(4838) / 2 + MEM(4669) / 2 + MEM(4537) / 2 + MEM(4310) / 2 + MEM(4272) / 2 + MEM(4105) / 2 + MEM(3969) / 2 + MEM(3868) / 2 + MEM(3638) / 2 + MEM(3569) / 2 + MEM(3338) / 2;
	MEM(11) = Acc;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 60: REVERSE - 300 MS */
void midiverb_effect_60(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = -Acc / 2 + MEM(2047) + MEM(9353);
	tmp_3 = Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = -Acc / 2 + MEM(1801) + MEM(9353);
	tmp_5 = Acc;
	Acc = MEM(16221) / 32 + MEM(16151) / 32 + MEM(15972) / 32 + MEM(15850) / 32 + MEM(15623) / 32 + MEM(15509) / 32 + MEM(14950) / 32 + MEM(15265) / 32 + MEM(14522) / 32 + -MEM(15319) / 16 + -MEM(14829) / 16 + -MEM(14642) / 16 + -MEM(15151) / 16 + -MEM(14338) / 16 + -MEM(14235) / 16 + -MEM(13511) / 16 + -MEM(13941) / 16 + -MEM(13263) / 16 + -MEM(13663) / 16 + MEM(14128) / 8 + MEM(13348) / 8 + MEM(13805) / 8 + MEM(13117) / 8 + MEM(12933) / 8 + MEM(12815) / 8 + MEM(11892) / 8 + MEM(12495) / 8 + MEM(12350) / 8 + MEM(12232) / 8 + MEM(11535) / 8 + -MEM(12659) / 4 + -MEM(11828) / 4 + -MEM(11657) / 4 + -MEM(12127) / 4 + -MEM(11350) / 4 + -MEM(10547) / 4 + -MEM(11149) / 4 + -MEM(10963) / 4 + -MEM(10225) / 4 + MEM(10625) / 2 + MEM(11255) / 2 + MEM(10349) / 2 + MEM(10850) / 2 + MEM(10161) / 2 + MEM(9938) / 2;
	MEM(11) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 61: REVERSE - 400 MS */
void midiverb_effect_61(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = -Acc / 2 + MEM(2047) + MEM(7009);
	tmp_3 = Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = -Acc / 2 + MEM(1801) + MEM(7009);
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = MEM(16221) / 32 + MEM(16151) / 32 + MEM(15972) / 32 + MEM(15850) / 32 + MEM(15623) / 32 + MEM(15509) / 32 + MEM(13663) / 32 + MEM(15265) / 32 + MEM(15151) / 32 + MEM(14950) / 32 + MEM(13941) / 32 + MEM(14642) / 32 + MEM(14522) / 32 + -MEM(14338) / 16 + -MEM(14235) / 16 + -MEM(14128) / 16 + -MEM(14829) / 16 + -MEM(13805) / 16 + -MEM(15319) / 16 + -MEM(13511) / 16 + -MEM(13348) / 16 + -MEM(12232) / 16 + -MEM(13117) / 16 + -MEM(12933) / 16 + -MEM(11892) / 16 + -MEM(12659) / 16 + MEM(12495) / 8 + MEM(12350) / 8 + MEM(13263) / 8 + MEM(12127) / 8 + MEM(12815) / 8 + MEM(11828) / 8 + MEM(11657) / 8 + MEM(11535) / 8 + MEM(10547) / 8 + MEM(11255) / 8 + MEM(11149) / 8 + MEM(10963) / 8 + MEM(10225) / 8 + -MEM(10625) / 4 + -MEM(11350) / 4 + -MEM(10349) / 4 + -MEM(10850) / 4 + -MEM(10161) / 4 + -MEM(9938) / 4 + -MEM(9850) / 4 + -MEM(8350) / 4 + -MEM(9525) / 4 + -MEM(9345) / 4 + -MEM(8648) / 4 + -MEM(9163) / 4 + -MEM(8945) / 4 + MEM(8850) / 2 + MEM(9258) / 2 + MEM(8493) / 2 + MEM(9602) / 2 + MEM(8238) / 2 + MEM(8106) / 2 + MEM(7937) / 2 + MEM(7819) / 2 + MEM(7684) / 2;
	MEM(11) = Acc;
	*out_right = tmp_3;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 62: REVERSE - 500 MS */
void midiverb_effect_62(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = -Acc / 2 + MEM(2047) + MEM(4666);
	tmp_3 = Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = -Acc / 2 + MEM(1801) + MEM(4666);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
	Acc = MEM(16221) / 32 + MEM(16151) / 32 + MEM(15972) / 32 + MEM(15850) / 32 + MEM(15623) / 32 + MEM(15509) / 32 + MEM(15319) / 32 + MEM(15265) / 32 + MEM(15151) / 32 + MEM(14950) / 32 + MEM(13805) / 32 + MEM(14642) / 32 + MEM(14522) / 32 + MEM(13348) / 32 + MEM(14235) / 32 + -MEM(14128) / 16 + -MEM(13941) / 16 + -MEM(14829) / 16 + -MEM(13663) / 16 + -MEM(13511) / 16 + -MEM(14338) / 16 + -MEM(13263) / 16 + -MEM(13117) / 16 + -MEM(12933) / 16 + -MEM(12815) / 16 + -MEM(11350) / 16 + -MEM(12495) / 16 + -MEM(12350) / 16 + -MEM(11657) / 16 + -MEM(12127) / 16 + MEM(11892) / 8 + MEM(11828) / 8 + MEM(12232) / 8 + MEM(11535) / 8 + MEM(12659) / 8 + MEM(11255) / 8 + MEM(11149) / 8 + MEM(10963) / 8 + MEM(10850) / 8 + MEM(10625) / 8 + MEM(9525) / 8 + MEM(10349) / 8 + MEM(10225) / 8 + MEM(10161) / 8 + MEM(9258) / 8 + MEM(9850) / 8 + -MEM(9602) / 4 + -MEM(10547) / 4 + -MEM(9345) / 4 + -MEM(9938) / 4 + -MEM(9163) / 4 + -MEM(8945) / 4 + -MEM(8850) / 4 + -MEM(8648) / 4 + -MEM(8493) / 4 + -MEM(8350) / 4 + -MEM(7169) / 4 + -MEM(8106) / 4 + -MEM(7937) / 4 + -MEM(7819) / 4 + -MEM(6871) / 4 + -MEM(7499) / 4 + MEM(7372) / 2 + MEM(7213) / 2 + MEM(8238) / 2 + MEM(6935) / 2 + MEM(7684) / 2 + MEM(6619) / 2 + MEM(6517) / 2 + MEM(6338) / 2 + MEM(6274) / 2 + MEM(6099) / 2 + MEM(5956) / 2 + MEM(5806) / 2 + MEM(5650) / 2 + MEM(5569) / 2 + MEM(5361) / 2 + MEM(5199) / 2 + MEM(5130) / 2;
	MEM(11) = Acc;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 63: REVERSE - 600 MS */
void midiverb_effect_63(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = -Acc / 2 + MEM(2047) + MEM(2384);
	tmp_3 = Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = -Acc / 2 + MEM(1801) + MEM(2384);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
	Acc = Acc * 3 / 32 + MEM(15319) / 32 + MEM(15265) / 32 + MEM(15151) / 32 + MEM(14950) / 32 + MEM(14829) / 32 + MEM(14642) / 32 + MEM(14522) / 32 + MEM(14338) / 32 + MEM(12815) / 32 + MEM(14128) / 32 + MEM(13941) / 32 + MEM(13263) / 32 + MEM(13663) / 32 + -MEM(13511) / 16 + -MEM(13348) / 16 + -MEM(13805) / 16 + -MEM(13117) / 16 + -MEM(12933) / 16 + -MEM(14235) / 16 + -MEM(12659) / 16 + -MEM(12495) / 16 + -MEM(12350) / 16 + -MEM(12232) / 16 + -MEM(12127) / 16 + -MEM(11892) / 16 + -MEM(11828) / 16 + -MEM(11657) / 16 + -MEM(11535) / 16 + -MEM(10349) / 16 + -MEM(11255) / 16 + -MEM(11149) / 16 + -MEM(10161) / 16 + -MEM(10850) / 16 + MEM(10625) / 8 + MEM(10547) / 8 + MEM(11350) / 8 + MEM(10225) / 8 + MEM(10963) / 8 + MEM(9938) / 8 + MEM(9850) / 8 + MEM(9602) / 8 + MEM(9525) / 8 + MEM(9345) / 8 + MEM(9258) / 8 + MEM(9163) / 8 + MEM(7819) / 8 + MEM(8850) / 8 + MEM(8648) / 8 + MEM(8493) / 8 + MEM(7169) / 8 + MEM(8238) / 8 + MEM(8106) / 8 + -MEM(7937) / 4 + -MEM(8945) / 4 + -MEM(7684) / 4 + -MEM(7499) / 4 + -MEM(7372) / 4 + -MEM(7213) / 4 + -MEM(8350) / 4 + -MEM(6935) / 4 + -MEM(6871) / 4 + -MEM(6619) / 4 + -MEM(6517) / 4 + -MEM(6338) / 4 + -MEM(6274) / 4 + -MEM(6099) / 4 + -MEM(4310) / 4 + -MEM(5806) / 4 + -MEM(5650) / 4 + -MEM(4669) / 4 + -MEM(5361) / 4 + -MEM(5199) / 4 + MEM(5130) / 2 + MEM(4905) / 2 + MEM(4838) / 2 + MEM(5569) / 2 + MEM(4537) / 2 + MEM(5956) / 2 + MEM(4272) / 2 + MEM(4105) / 2 + MEM(3969) / 2 + MEM(3868) / 2 + MEM(3638) / 2 + MEM(3569) / 2 + MEM(3338) / 2 + MEM(3167) / 2 + MEM(3006) / 2 + MEM(2850) / 2;
	MEM(11) = Acc;
}
#define MEM(a) (DRAM[(ptr + (a)) & 0x3fff])
/* Midiverb effect 64: DEFEAT */
void midiverb_effect_64(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc;
	*out_left = MEM(5);
	*out_right = MEM(3);
	Acc = 0;
	MEM(140) = -Acc;
}
void (*midiverb_effects[])(int16_t input, int16_t *out_left, int16_t *out_right, int16_t *DRAM, int ptr) = {
	midiverb_effect_1,
	midiverb_effect_2,
	midiverb_effect_3,
	midiverb_effect_4,
	midiverb_effect_5,
	midiverb_effect_6,
	midiverb_effect_7,
	midiverb_effect_8,
	midiverb_effect_9,
	midiverb_effect_10,
	midiverb_effect_11,
	midiverb_effect_12,
	midiverb_effect_13,
	midiverb_effect_14,
	midiverb_effect_15,
	midiverb_effect_16,
	midiverb_effect_17,
	midiverb_effect_18,
	midiverb_effect_19,
	midiverb_effect_20,
	midiverb_effect_21,
	midiverb_effect_22,
	midiverb_effect_23,
	midiverb_effect_24,
	midiverb_effect_25,
	midiverb_effect_26,
	midiverb_effect_27,
	midiverb_effect_28,
	midiverb_effect_29,
	midiverb_effect_30,
	midiverb_effect_31,
	midiverb_effect_32,
	midiverb_effect_33,
	midiverb_effect_34,
	midiverb_effect_35,
	midiverb_effect_36,
	midiverb_effect_37,
	midiverb_effect_38,
	midiverb_effect_39,
	midiverb_effect_40,
	midiverb_effect_41,
	midiverb_effect_42,
	midiverb_effect_43,
	midiverb_effect_44,
	midiverb_effect_45,
	midiverb_effect_46,
	midiverb_effect_47,
	midiverb_effect_48,
	midiverb_effect_49,
	midiverb_effect_50,
	midiverb_effect_51,
	midiverb_effect_52,
	midiverb_effect_53,
	midiverb_effect_54,
	midiverb_effect_55,
	midiverb_effect_56,
	midiverb_effect_57,
	midiverb_effect_58,
	midiverb_effect_59,
	midiverb_effect_60,
	midiverb_effect_61,
	midiverb_effect_62,
	midiverb_effect_63,
	midiverb_effect_64,
};
