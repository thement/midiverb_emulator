#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_0(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc;
	*out_left = LINE(0, 140, 135);
	*out_right = LINE(0, 140, 137);
	Acc = 0;
	WRITE_LINE(0, 140) = -Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_1(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(18, 15972, 12) * 3 / 4 + LINE(17, 15549, 234) * 3 / 4 + LINE(16, 15035, 252) * 3 / 4 + LINE(15, 14477, 378) * 3 / 4 + LINE(10, 12812, 169) * 3 / 4 + LINE(9, 12375, 199) * 3 / 4 + LINE(8, 11892, 423) * 3 / 4;
	tmp_3 = Acc;
	Acc = LINE(18, 15972, 145) * 3 / 4 + LINE(17, 15549, 130) * 3 / 4 + LINE(16, 15035, 459) * 3 / 4 + LINE(15, 14477, 277) * 3 / 4 + LINE(10, 12812, 103) * 3 / 4 + LINE(9, 12375, 208) * 3 / 4 + LINE(6, 10744, 16) * 3 / 4;
	tmp_5 = Acc;
	Acc = LINE(23, 16381, 19) * 3 / 4 + LINE(0, 0, 1) / 2;
	WRITE_LINE(23, 16381) = -Acc;
	Acc = Acc * -3 / 4 + LINE(22, 16360, 45) * 3 / 4 + LINE(23, 16381, 19);
	WRITE_LINE(22, 16360) = -Acc;
	Acc = Acc * -3 / 4 + LINE(21, 16313, 84) * 3 / 4 + LINE(22, 16360, 45);
	WRITE_LINE(21, 16313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 16227, 115) * 3 / 4 + LINE(21, 16313, 84);
	WRITE_LINE(20, 16227) = -Acc;
	Acc = Acc * -3 / 4 + LINE(19, 16110, 136) * 3 / 4 + LINE(20, 16227, 115);
	WRITE_LINE(19, 16110) = -Acc;
	Acc = Acc * -9 / 8 + LINE(19, 16110, 136) * 3 / 2;
	tmp_b = Acc;
	Acc = LINE(18, 15972, 421) / 2 + LINE(14, 13797, 278) / 2;
	WRITE_LINE(14, 13797) = -Acc;
	Acc = -Acc / 2 + LINE(14, 13797, 278);
	WRITE_LINE(17, 15549) = Acc;
	Acc = -LINE(17, 15549, 512) / 4 + -LINE(17, 15549, 513) / 4 + LINE(13, 13517, 212) / 2;
	WRITE_LINE(13, 13517) = -Acc;
	Acc = -Acc / 2 + LINE(13, 13517, 212);
	WRITE_LINE(16, 15035) = Acc;
	Acc = LINE(16, 15035, 556) / 2 + LINE(12, 13303, 256) / 2;
	WRITE_LINE(12, 13303) = -Acc;
	Acc = -Acc / 2 + LINE(12, 13303, 256);
	WRITE_LINE(15, 14477) = Acc;
	Acc = LINE(15, 14477, 678) / 2 + LINE(11, 13045, 231) / 2;
	WRITE_LINE(11, 13045) = -Acc;
	Acc = -Acc / 2 + LINE(11, 13045, 231) + LINE(2, 9694, 1) / 2;
	WRITE_LINE(2, 9694) = Acc;
	Acc = LINE(2, 9694, 0) / 2 + tmp_b;
	WRITE_LINE(18, 15972) = Acc;
	Acc = LINE(10, 12812, 435) / 2 + LINE(6, 10744, 292) / 2;
	WRITE_LINE(6, 10744) = -Acc;
	Acc = -Acc / 2 + LINE(6, 10744, 292);
	WRITE_LINE(9, 12375) = Acc;
	Acc = -LINE(9, 12375, 481) / 4 + -LINE(9, 12375, 482) / 4 + LINE(5, 10450, 281) / 2;
	WRITE_LINE(5, 10450) = -Acc;
	Acc = -Acc / 2 + LINE(5, 10450, 281);
	WRITE_LINE(8, 11892) = Acc;
	Acc = LINE(8, 11892, 571) / 2 + LINE(4, 10167, 234) / 2;
	WRITE_LINE(4, 10167) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + LINE(4, 10167, 234);
	WRITE_LINE(7, 11319) = Acc;
	Acc = LINE(7, 11319, 573) / 2 + LINE(3, 9931, 232) / 2;
	WRITE_LINE(3, 9931) = -Acc;
	Acc = -Acc / 2 + LINE(3, 9931, 232) + LINE(1, 9691, 1) / 2;
	WRITE_LINE(1, 9691) = Acc;
	Acc = LINE(1, 9691, 0) / 2 + tmp_b;
	WRITE_LINE(10, 12812) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_2(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(20, 15962, 120) * 3 / 4 + LINE(19, 15092, 334) * 3 / 4 + LINE(16, 12751, 252) * 3 / 4 + LINE(15, 11359, 478) * 3 / 4 + LINE(12, 9457, 369) * 3 / 4 + LINE(11, 8482, 499) * 3 / 4 + LINE(8, 6402, 723) * 3 / 4 + LINE(7, 5629, 214) * 3 / 4;
	tmp_3 = Acc;
	Acc = LINE(20, 15962, 129) * 3 / 4 + LINE(19, 15092, 130) * 3 / 4 + LINE(16, 12751, 459) * 3 / 4 + LINE(15, 11359, 277) * 3 / 4 + LINE(12, 9457, 363) * 3 / 4 + LINE(11, 8482, 208) * 3 / 4 + LINE(8, 6402, 421) * 3 / 4 + LINE(7, 5629, 891) * 3 / 4;
	tmp_5 = Acc;
	Acc = LINE(25, 16381, 19) * 3 / 4 + LINE(0, 0, 1) / 2;
	WRITE_LINE(25, 16381) = -Acc;
	Acc = Acc * -3 / 4 + LINE(24, 16360, 45) * 3 / 4 + LINE(25, 16381, 19);
	WRITE_LINE(24, 16360) = -Acc;
	Acc = Acc * -3 / 4 + LINE(23, 16313, 84) * 3 / 4 + LINE(24, 16360, 45);
	WRITE_LINE(23, 16313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(22, 16227, 115) * 3 / 4 + LINE(23, 16313, 84);
	WRITE_LINE(22, 16227) = -Acc;
	Acc = Acc * -3 / 4 + LINE(21, 16110, 146) * 3 / 4 + LINE(22, 16227, 115);
	WRITE_LINE(21, 16110) = -Acc;
	Acc = Acc * -9 / 8 + LINE(21, 16110, 146) * 3 / 2;
	tmp_b = Acc;
	Acc = LINE(20, 15962, 868) / 2 + LINE(18, 13745, 678) / 2;
	WRITE_LINE(18, 13745) = -Acc;
	Acc = -Acc / 2 + LINE(18, 13745, 678);
	WRITE_LINE(19, 15092) = Acc;
	Acc = LINE(19, 15092, 1345) / 2 + LINE(17, 13065, 312) / 2;
	WRITE_LINE(17, 13065) = -Acc;
	Acc = -Acc / 2 + LINE(17, 13065, 312) + LINE(4, 3636, 1) / 2;
	WRITE_LINE(4, 3636) = Acc;
	Acc = LINE(4, 3636, 0) / 2 + tmp_b / 2;
	WRITE_LINE(20, 15962) = Acc;
	Acc = LINE(16, 12751, 1390) / 2 + LINE(14, 10568, 676) / 2;
	WRITE_LINE(14, 10568) = -Acc;
	Acc = -Acc / 2 + LINE(14, 10568, 676);
	WRITE_LINE(15, 11359) = Acc;
	Acc = LINE(15, 11359, 789) / 2 + LINE(13, 9890, 431) / 2;
	WRITE_LINE(13, 9890) = -Acc;
	Acc = -Acc / 2 + LINE(13, 9890, 431) + LINE(3, 3633, 1) / 2;
	WRITE_LINE(3, 3633) = Acc;
	Acc = LINE(3, 3633, 0) / 2 + tmp_b / 2;
	WRITE_LINE(16, 12751) = Acc;
	Acc = LINE(12, 9457, 973) / 2 + LINE(10, 7499, 712) / 2;
	WRITE_LINE(10, 7499) = -Acc;
	Acc = -Acc / 2 + LINE(10, 7499, 712);
	WRITE_LINE(11, 8482) = Acc;
	Acc = LINE(11, 8482, 981) / 2 + LINE(9, 6785, 381) / 2;
	WRITE_LINE(9, 6785) = -Acc;
	Acc = -Acc / 2 + LINE(9, 6785, 381) + LINE(2, 3630, 1) / 2;
	WRITE_LINE(2, 3630) = Acc;
	*out_left = tmp_5;
	Acc = LINE(2, 3630, 0) / 2 + tmp_b;
	WRITE_LINE(12, 9457) = Acc;
	Acc = LINE(8, 6402, 771) / 2 + LINE(6, 4606, 634) / 2;
	WRITE_LINE(6, 4606) = -Acc;
	Acc = -Acc / 2 + LINE(6, 4606, 634);
	WRITE_LINE(7, 5629) = Acc;
	Acc = LINE(7, 5629, 1021) / 2 + LINE(5, 3970, 332) / 2;
	WRITE_LINE(5, 3970) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + LINE(5, 3970, 332) + LINE(1, 3627, 1) / 2;
	WRITE_LINE(1, 3627) = Acc;
	Acc = LINE(1, 3627, 0) / 2 + tmp_b;
	WRITE_LINE(8, 6402) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_3(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(20, 15962, 320) * 3 / 4 + LINE(19, 15092, 734) * 3 / 4 + LINE(16, 12551, 252) * 3 / 4 + LINE(15, 11159, 478) * 3 / 4 + LINE(12, 8857, 369) * 3 / 4 + LINE(11, 7621, 499) * 3 / 4 + LINE(8, 5441, 723) * 3 / 4 + LINE(7, 4468, 214) * 3 / 4;
	tmp_3 = Acc;
	Acc = LINE(20, 15962, 129) * 3 / 4 + LINE(19, 15092, 130) * 3 / 4 + LINE(16, 12551, 859) * 3 / 4 + LINE(15, 11159, 277) * 3 / 4 + LINE(12, 8857, 563) * 3 / 4 + LINE(11, 7621, 208) * 3 / 4 + LINE(8, 5441, 421) * 3 / 4 + LINE(7, 4468, 891) * 3 / 4;
	tmp_5 = Acc;
	Acc = LINE(25, 16381, 19) * 3 / 4 + LINE(0, 0, 1) / 2;
	WRITE_LINE(25, 16381) = -Acc;
	Acc = Acc * -3 / 4 + LINE(24, 16360, 45) * 3 / 4 + LINE(25, 16381, 19);
	WRITE_LINE(24, 16360) = -Acc;
	Acc = Acc * -3 / 4 + LINE(23, 16313, 84) * 3 / 4 + LINE(24, 16360, 45);
	WRITE_LINE(23, 16313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(22, 16227, 115) * 3 / 4 + LINE(23, 16313, 84);
	WRITE_LINE(22, 16227) = -Acc;
	Acc = Acc * -3 / 4 + LINE(21, 16110, 146) * 3 / 4 + LINE(22, 16227, 115);
	WRITE_LINE(21, 16110) = -Acc;
	Acc = Acc * -9 / 8 + LINE(21, 16110, 146) * 3 / 2;
	tmp_b = Acc;
	Acc = LINE(20, 15962, 868) / 2 + LINE(18, 13745, 678) / 2;
	WRITE_LINE(18, 13745) = -Acc;
	Acc = -Acc / 2 + LINE(18, 13745, 678);
	WRITE_LINE(19, 15092) = Acc;
	Acc = LINE(19, 15092, 1345) / 2 + LINE(17, 13065, 512) / 2;
	WRITE_LINE(17, 13065) = -Acc;
	Acc = -Acc / 2 + LINE(17, 13065, 512) + LINE(4, 2475, 1) / 2;
	WRITE_LINE(4, 2475) = Acc;
	Acc = LINE(4, 2475, 0) / 2 + tmp_b / 2;
	WRITE_LINE(20, 15962) = Acc;
	Acc = LINE(16, 12551, 1390) / 2 + LINE(14, 10168, 676) / 2;
	WRITE_LINE(14, 10168) = -Acc;
	Acc = -Acc / 2 + LINE(14, 10168, 676);
	WRITE_LINE(15, 11159) = Acc;
	Acc = LINE(15, 11159, 989) / 2 + LINE(13, 9490, 631) / 2;
	WRITE_LINE(13, 9490) = -Acc;
	Acc = -Acc / 2 + LINE(13, 9490, 631) + LINE(3, 2472, 1) / 2;
	WRITE_LINE(3, 2472) = Acc;
	Acc = LINE(3, 2472, 0) / 2 + tmp_b / 2;
	WRITE_LINE(16, 12551) = Acc;
	Acc = LINE(12, 8857, 1234) / 2 + LINE(10, 6638, 712) / 2;
	WRITE_LINE(10, 6638) = -Acc;
	Acc = -Acc / 2 + LINE(10, 6638, 712);
	WRITE_LINE(11, 7621) = Acc;
	Acc = LINE(11, 7621, 981) / 2 + LINE(9, 5924, 481) / 2;
	WRITE_LINE(9, 5924) = -Acc;
	Acc = -Acc / 2 + LINE(9, 5924, 481) + LINE(2, 2469, 1) / 2;
	WRITE_LINE(2, 2469) = Acc;
	*out_left = tmp_5;
	Acc = LINE(2, 2469, 0) / 2 + tmp_b;
	WRITE_LINE(12, 8857) = Acc;
	Acc = LINE(8, 5441, 971) / 2 + LINE(6, 3445, 634) / 2;
	WRITE_LINE(6, 3445) = -Acc;
	Acc = -Acc / 2 + LINE(6, 3445, 634);
	WRITE_LINE(7, 4468) = Acc;
	Acc = LINE(7, 4468, 1021) / 2 + LINE(5, 2809, 332) / 2;
	WRITE_LINE(5, 2809) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + LINE(5, 2809, 332) + LINE(1, 2466, 1) / 2;
	WRITE_LINE(1, 2466) = Acc;
	Acc = LINE(1, 2466, 0) / 2 + tmp_b;
	WRITE_LINE(8, 5441) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_4(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 14885, 361) * 9 / 8 + LINE(6, 11865, 789) * 9 / 8 + LINE(4, 7880, 1703) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(8, 14885, 576) * 9 / 8 + LINE(6, 11865, 390) * 9 / 8 + LINE(4, 7880, 671) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(2, 3607, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(2, 3607) = Acc;
	Acc = LINE(2, 3607, 0) / 2 + LINE(14, 16381, 36) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 36) + LINE(13, 16343, 79) / 2;
	WRITE_LINE(13, 16343) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16343, 79) + LINE(12, 16262, 158) / 2;
	WRITE_LINE(12, 16262) = -Acc;
	Acc = -Acc / 2 + LINE(12, 16262, 158) + LINE(11, 16102, 269) / 2;
	WRITE_LINE(11, 16102) = -Acc;
	Acc = -Acc / 2 + LINE(11, 16102, 269) + LINE(10, 15831, 344) / 2;
	WRITE_LINE(10, 15831) = -Acc;
	Acc = -Acc / 2 + LINE(10, 15831, 344) + LINE(9, 15485, 598) / 2;
	WRITE_LINE(9, 15485) = -Acc;
	Acc = Acc * -3 / 4 + LINE(9, 15485, 598) * 3 / 2;
	tmp_b = Acc;
	Acc = LINE(8, 14885, 1624) / 2 + LINE(8, 14885, 1625) / 2 + LINE(7, 13259, 1392) / 2;
	WRITE_LINE(7, 13259) = -Acc;
	Acc = -Acc / 2 + LINE(7, 13259, 1392);
	WRITE_LINE(6, 11865) = Acc;
	Acc = -LINE(6, 11865, 2410) / 4 + LINE(5, 9453, 1571) / 2;
	WRITE_LINE(5, 9453) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9453, 1571);
	WRITE_LINE(4, 7880) = Acc;
	Acc = LINE(4, 7880, 2657) * 3 / 4 + LINE(3, 5221, 1612) / 2;
	WRITE_LINE(3, 5221) = -Acc;
	Acc = -Acc / 2 + LINE(3, 5221, 1612) + LINE(1, 3604, 1) / 2;
	WRITE_LINE(1, 3604) = Acc;
	Acc = LINE(1, 3604, 0) / 2 + tmp_b;
	WRITE_LINE(8, 14885) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_5(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(19, 15952, 120) * 9 / 8 + LINE(18, 15282, 334) * 9 / 8 + LINE(17, 14568, 252) * 9 / 8 + LINE(16, 13710, 478) * 9 / 8 + LINE(11, 11245, 369) * 9 / 8 + LINE(10, 10670, 499) * 9 / 8 + LINE(9, 9987, 723) * 9 / 8 + LINE(8, 9114, 207) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(19, 15952, 129) * 9 / 8 + LINE(18, 15282, 130) * 9 / 8 + LINE(17, 14568, 459) * 9 / 8 + LINE(16, 13710, 277) * 9 / 8 + LINE(11, 11245, 363) * 9 / 8 + LINE(10, 10670, 208) * 9 / 8 + LINE(9, 9987, 451) * 9 / 8 + LINE(7, 8279, 56) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(3, 6812, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(3, 6812) = Acc;
	Acc = LINE(24, 16381, 19) * 3 / 4 + LINE(0, 0, 1) / 2;
	WRITE_LINE(24, 16381) = -Acc;
	Acc = Acc * -3 / 4 + LINE(23, 16360, 45) * 3 / 4 + LINE(24, 16381, 19);
	WRITE_LINE(23, 16360) = -Acc;
	Acc = Acc * -3 / 4 + LINE(22, 16313, 84) * 3 / 4 + LINE(23, 16360, 45);
	WRITE_LINE(22, 16313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(21, 16227, 115) * 3 / 4 + LINE(22, 16313, 84);
	WRITE_LINE(21, 16227) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 16110, 156) * 3 / 4 + LINE(21, 16227, 115);
	WRITE_LINE(20, 16110) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 16110, 156);
	tmp_b = Acc;
	Acc = LINE(19, 15952, 668) * 3 / 4 + LINE(15, 12830, 478) / 2;
	WRITE_LINE(15, 12830) = -Acc;
	Acc = -Acc / 2 + LINE(15, 12830, 478);
	WRITE_LINE(18, 15282) = Acc;
	Acc = LINE(18, 15282, 712) * 3 / 4 + LINE(14, 12350, 312) / 2;
	WRITE_LINE(14, 12350) = -Acc;
	Acc = -Acc / 2 + LINE(14, 12350, 312);
	WRITE_LINE(17, 14568) = Acc;
	Acc = LINE(17, 14568, 856) * 3 / 4 + LINE(13, 12036, 456) / 2;
	WRITE_LINE(13, 12036) = -Acc;
	Acc = -Acc / 2 + LINE(13, 12036, 456);
	WRITE_LINE(16, 13710) = Acc;
	Acc = LINE(16, 13710, 878) * 3 / 4 + LINE(12, 11578, 331) / 2;
	WRITE_LINE(12, 11578) = -Acc;
	Acc = -Acc / 2 + LINE(12, 11578, 331) + LINE(2, 6809, 1) / 2;
	WRITE_LINE(2, 6809) = Acc;
	Acc = LINE(2, 6809, 0) / 2 + tmp_b;
	WRITE_LINE(19, 15952) = Acc;
	Acc = LINE(11, 11245, 573) * 3 / 4 + LINE(7, 8279, 412) / 2;
	WRITE_LINE(7, 8279) = -Acc;
	Acc = -Acc / 2 + LINE(7, 8279, 412);
	WRITE_LINE(10, 10670) = Acc;
	*out_left = tmp_5;
	Acc = LINE(10, 10670, 681) * 3 / 4 + LINE(6, 7865, 381) / 2;
	WRITE_LINE(6, 7865) = -Acc;
	Acc = -Acc / 2 + LINE(6, 7865, 381);
	WRITE_LINE(9, 9987) = Acc;
	Acc = LINE(9, 9987, 871) * 3 / 4 + LINE(5, 7482, 434) / 2;
	WRITE_LINE(5, 7482) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7482, 434);
	WRITE_LINE(8, 9114) = Acc;
	*out_right = tmp_3;
	Acc = LINE(8, 9114, 833) * 3 / 4 + LINE(4, 7046, 232) / 2;
	WRITE_LINE(4, 7046) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7046, 232) + LINE(1, 6806, 1) / 2;
	WRITE_LINE(1, 6806) = Acc;
	Acc = LINE(1, 6806, 0) / 2 + tmp_b;
	WRITE_LINE(11, 11245) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_6(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 14666, 345) * 9 / 8 + LINE(8, 10834, 987) * 9 / 8 + LINE(4, 3735, 678) * 9 / 8 + LINE(6, 7372, 345) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(10, 14666, 685) * 9 / 8 + LINE(8, 10834, 342) * 9 / 8 + LINE(4, 3735, 340) * 9 / 8 + LINE(6, 7372, 1023) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(15, 16282, 98) * 5 / 8 + LINE(0, 0, 100) / 2;
	WRITE_LINE(15, 16282) = -Acc;
	Acc = -Acc / 8 + LINE(14, 16182, 198) * 5 / 8 + LINE(15, 16282, 0) / 2 + LINE(15, 16282, 98);
	WRITE_LINE(14, 16182) = -Acc;
	Acc = -Acc / 8 + LINE(13, 15982, 367) * 5 / 8 + LINE(14, 16182, 0) / 2 + LINE(14, 16182, 198);
	WRITE_LINE(13, 15982) = -Acc;
	Acc = -Acc / 8 + LINE(12, 15613, 598) * 5 / 8 + LINE(13, 15982, 0) / 2 + LINE(13, 15982, 367);
	WRITE_LINE(12, 15613) = -Acc;
	Acc = -Acc / 8 + LINE(12, 15613, 0) / 2 + LINE(12, 15613, 598) + LINE(11, 15013, 345) / 2;
	WRITE_LINE(11, 15013) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15013, 345);
	tmp_b = Acc;
	Acc = LINE(10, 14666, 2203) / 2 + LINE(10, 14666, 2204) / 2 + LINE(9, 12461, 1625) / 2;
	WRITE_LINE(9, 12461) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12461, 1625);
	WRITE_LINE(8, 10834) = Acc;
	Acc = -LINE(8, 10834, 1969) / 4 + LINE(7, 8863, 1489) / 2;
	WRITE_LINE(7, 8863) = -Acc;
	Acc = -Acc / 2 + LINE(7, 8863, 1489) + LINE(2, 160, 1) / 2;
	WRITE_LINE(2, 160) = Acc;
	Acc = LINE(2, 160, 0) / 2 + tmp_b;
	WRITE_LINE(10, 14666) = Acc;
	Acc = LINE(6, 7372, 1934) / 2 + LINE(6, 7372, 1935) / 2 + LINE(5, 5436, 1699) / 2;
	WRITE_LINE(5, 5436) = -Acc;
	Acc = -Acc / 2 + LINE(5, 5436, 1699);
	WRITE_LINE(4, 3735) = Acc;
	Acc = -LINE(4, 3735, 2183) / 4 + LINE(3, 1550, 1385) / 2;
	WRITE_LINE(3, 1550) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1550, 1385) + LINE(1, 157, 1) / 2;
	WRITE_LINE(1, 157) = Acc;
	Acc = LINE(1, 157, 0) / 2 + tmp_b;
	WRITE_LINE(6, 7372) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_7(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(11, 14666, 1209) * 9 / 8 + LINE(9, 10834, 987) * 9 / 8 + LINE(5, 3735, 678) * 9 / 8 + LINE(7, 7372, 787) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(11, 14666, 685) * 9 / 8 + LINE(9, 10834, 342) * 9 / 8 + LINE(5, 3735, 340) * 9 / 8 + LINE(7, 7372, 1023) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 100) / 2 + LINE(3, 163, 1) / 2;
	WRITE_LINE(3, 163) = Acc;
	Acc = LINE(16, 16282, 98) * 5 / 8 + LINE(3, 163, 1) / 2;
	WRITE_LINE(16, 16282) = -Acc;
	Acc = -Acc / 8 + LINE(15, 16182, 198) * 5 / 8 + LINE(16, 16282, 0) / 2 + LINE(16, 16282, 98);
	WRITE_LINE(15, 16182) = -Acc;
	Acc = -Acc / 8 + LINE(14, 15982, 367) * 5 / 8 + LINE(15, 16182, 0) / 2 + LINE(15, 16182, 198);
	WRITE_LINE(14, 15982) = -Acc;
	Acc = -Acc / 8 + LINE(13, 15613, 598) * 5 / 8 + LINE(14, 15982, 0) / 2 + LINE(14, 15982, 367);
	WRITE_LINE(13, 15613) = -Acc;
	Acc = -Acc / 8 + LINE(13, 15613, 0) / 2 + LINE(13, 15613, 598) + LINE(12, 15013, 345) / 2;
	WRITE_LINE(12, 15013) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15013, 345);
	tmp_b = Acc;
	Acc = LINE(11, 14666, 2203) / 2 + LINE(11, 14666, 2204) / 2 + LINE(10, 12461, 1625) / 2;
	WRITE_LINE(10, 12461) = -Acc;
	Acc = -Acc / 2 + LINE(10, 12461, 1625);
	WRITE_LINE(9, 10834) = Acc;
	Acc = -LINE(9, 10834, 1969) / 4 + LINE(8, 8863, 1489) / 2;
	WRITE_LINE(8, 8863) = -Acc;
	Acc = -Acc / 2 + LINE(8, 8863, 1489) + LINE(2, 160, 1) / 2;
	WRITE_LINE(2, 160) = Acc;
	Acc = LINE(2, 160, 0) / 2 + tmp_b;
	WRITE_LINE(11, 14666) = Acc;
	Acc = LINE(7, 7372, 1934) / 2 + LINE(7, 7372, 1935) / 2 + LINE(6, 5436, 1699) / 2;
	WRITE_LINE(6, 5436) = -Acc;
	Acc = -Acc / 2 + LINE(6, 5436, 1699);
	WRITE_LINE(5, 3735) = Acc;
	Acc = -LINE(5, 3735, 2183) / 4 + LINE(4, 1550, 1385) / 2;
	WRITE_LINE(4, 1550) = -Acc;
	Acc = -Acc / 2 + LINE(4, 1550, 1385) + LINE(1, 157, 1) / 2;
	WRITE_LINE(1, 157) = Acc;
	Acc = LINE(1, 157, 0) / 2 + tmp_b;
	WRITE_LINE(7, 7372) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_8(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(19, 15952, 120) * 9 / 8 + LINE(18, 15282, 334) * 9 / 8 + LINE(17, 14568, 252) * 9 / 8 + LINE(16, 13710, 478) * 9 / 8 + LINE(11, 11245, 369) * 9 / 8 + LINE(10, 10670, 499) * 9 / 8 + LINE(9, 9987, 723) * 9 / 8 + LINE(8, 9114, 207) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(19, 15952, 129) * 9 / 8 + LINE(18, 15282, 130) * 9 / 8 + LINE(17, 14568, 459) * 9 / 8 + LINE(16, 13710, 277) * 9 / 8 + LINE(11, 11245, 363) * 9 / 8 + LINE(10, 10670, 208) * 9 / 8 + LINE(9, 9987, 451) * 9 / 8 + LINE(7, 8279, 56) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(3, 6812, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(3, 6812) = Acc;
	Acc = LINE(24, 16381, 19) * 3 / 4 + LINE(3, 6812, 0) / 2;
	WRITE_LINE(24, 16381) = -Acc;
	Acc = Acc * -3 / 4 + LINE(23, 16360, 45) * 3 / 4 + LINE(24, 16381, 19);
	WRITE_LINE(23, 16360) = -Acc;
	Acc = Acc * -3 / 4 + LINE(22, 16313, 84) * 3 / 4 + LINE(23, 16360, 45);
	WRITE_LINE(22, 16313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(21, 16227, 115) * 3 / 4 + LINE(22, 16313, 84);
	WRITE_LINE(21, 16227) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 16110, 156) * 3 / 4 + LINE(21, 16227, 115);
	WRITE_LINE(20, 16110) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 16110, 156);
	tmp_b = Acc;
	Acc = LINE(19, 15952, 668) * 3 / 4 + LINE(15, 12830, 478) / 2;
	WRITE_LINE(15, 12830) = -Acc;
	Acc = -Acc / 2 + LINE(15, 12830, 478);
	WRITE_LINE(18, 15282) = Acc;
	Acc = LINE(18, 15282, 712) * 3 / 4 + LINE(14, 12350, 312) / 2;
	WRITE_LINE(14, 12350) = -Acc;
	Acc = -Acc / 2 + LINE(14, 12350, 312);
	WRITE_LINE(17, 14568) = Acc;
	Acc = LINE(17, 14568, 856) * 3 / 4 + LINE(13, 12036, 456) / 2;
	WRITE_LINE(13, 12036) = -Acc;
	Acc = -Acc / 2 + LINE(13, 12036, 456);
	WRITE_LINE(16, 13710) = Acc;
	Acc = LINE(16, 13710, 878) * 3 / 4 + LINE(12, 11578, 331) / 2;
	WRITE_LINE(12, 11578) = -Acc;
	Acc = -Acc / 2 + LINE(12, 11578, 331) + LINE(2, 6809, 1) / 2;
	WRITE_LINE(2, 6809) = Acc;
	Acc = LINE(2, 6809, 0) / 2 + tmp_b;
	WRITE_LINE(19, 15952) = Acc;
	Acc = LINE(11, 11245, 573) * 3 / 4 + LINE(7, 8279, 412) / 2;
	WRITE_LINE(7, 8279) = -Acc;
	Acc = -Acc / 2 + LINE(7, 8279, 412);
	WRITE_LINE(10, 10670) = Acc;
	*out_left = tmp_5;
	Acc = LINE(10, 10670, 681) * 3 / 4 + LINE(6, 7865, 381) / 2;
	WRITE_LINE(6, 7865) = -Acc;
	Acc = -Acc / 2 + LINE(6, 7865, 381);
	WRITE_LINE(9, 9987) = Acc;
	Acc = LINE(9, 9987, 871) * 3 / 4 + LINE(5, 7482, 434) / 2;
	WRITE_LINE(5, 7482) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7482, 434);
	WRITE_LINE(8, 9114) = Acc;
	*out_right = tmp_3;
	Acc = LINE(8, 9114, 833) * 3 / 4 + LINE(4, 7046, 232) / 2;
	WRITE_LINE(4, 7046) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7046, 232) + LINE(1, 6806, 1) / 2;
	WRITE_LINE(1, 6806) = Acc;
	Acc = LINE(1, 6806, 0) / 2 + tmp_b;
	WRITE_LINE(11, 11245) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_9(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(17, 15922, 120) * 9 / 8 + LINE(16, 14952, 334) * 9 / 8 + LINE(15, 14138, 252) * 9 / 8 + LINE(14, 13180, 478) * 9 / 8 + LINE(9, 9647, 369) * 9 / 8 + LINE(8, 8772, 499) * 9 / 8 + LINE(7, 7889, 323) * 9 / 8;
	tmp_3 = -Acc;
	Acc = LINE(17, 15922, 129) * 9 / 8 + LINE(16, 14952, 130) * 9 / 8 + LINE(15, 14138, 459) * 9 / 8 + LINE(14, 13180, 277) * 9 / 8 + LINE(9, 9647, 363) * 9 / 8 + LINE(8, 8772, 208) * 9 / 8 + LINE(6, 6916, 491) * 9 / 8;
	tmp_5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(1, 3037, 1) / 2;
	WRITE_LINE(1, 3037) = Acc;
	Acc = LINE(22, 16381, 19) * 3 / 4 + LINE(1, 3037, 0) / 2;
	WRITE_LINE(22, 16381) = -Acc;
	Acc = Acc * -3 / 4 + LINE(21, 16360, 45) * 3 / 4 + LINE(22, 16381, 19);
	WRITE_LINE(21, 16360) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 16313, 84) * 3 / 4 + LINE(21, 16360, 45);
	WRITE_LINE(20, 16313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(19, 16227, 125) * 3 / 4 + LINE(20, 16313, 84);
	WRITE_LINE(19, 16227) = -Acc;
	Acc = Acc * -3 / 4 + LINE(18, 16100, 176) * 3 / 4 + LINE(19, 16227, 125);
	WRITE_LINE(18, 16100) = -Acc;
	Acc = Acc * -3 / 4 + LINE(18, 16100, 176);
	tmp_b = -Acc;
	Acc = LINE(17, 15922, 968) * 5 / 8 + LINE(13, 12432, 678) / 2;
	WRITE_LINE(13, 12432) = -Acc;
	Acc = -Acc / 2 + LINE(13, 12432, 678);
	WRITE_LINE(16, 14952) = Acc;
	Acc = LINE(16, 14952, 812) / 2 + LINE(12, 11752, 512) / 2;
	WRITE_LINE(12, 11752) = -Acc;
	Acc = -Acc / 2 + LINE(12, 11752, 512);
	WRITE_LINE(15, 14138) = Acc;
	Acc = LINE(15, 14138, 956) * 5 / 8 + LINE(11, 11238, 756) / 2;
	WRITE_LINE(11, 11238) = -Acc;
	Acc = -Acc / 2 + LINE(11, 11238, 756);
	WRITE_LINE(14, 13180) = Acc;
	Acc = LINE(14, 13180, 746) * 5 / 8 + LINE(10, 10480, 831) / 2;
	WRITE_LINE(10, 10480) = -Acc;
	Acc = -Acc / 2 + LINE(10, 10480, 831) + tmp_b;
	WRITE_LINE(17, 15922) = Acc;
	Acc = LINE(9, 9647, 873) * 5 / 8 + LINE(5, 5904, 512) / 2;
	WRITE_LINE(5, 5904) = -Acc;
	Acc = -Acc / 2 + LINE(5, 5904, 512);
	WRITE_LINE(8, 8772) = Acc;
	*out_left = tmp_5;
	Acc = LINE(8, 8772, 881) / 2 + LINE(4, 5390, 781) / 2;
	WRITE_LINE(4, 5390) = -Acc;
	Acc = -Acc / 2 + LINE(4, 5390, 781);
	WRITE_LINE(7, 7889) = Acc;
	Acc = LINE(7, 7889, 971) * 5 / 8 + LINE(3, 4607, 634) / 2;
	WRITE_LINE(3, 4607) = -Acc;
	Acc = -Acc / 2 + LINE(3, 4607, 634);
	WRITE_LINE(6, 6916) = Acc;
	*out_right = tmp_3;
	Acc = LINE(6, 6916, 1010) * 5 / 8 + LINE(2, 3971, 932) / 2;
	WRITE_LINE(2, 3971) = -Acc;
	Acc = -Acc / 2 + LINE(2, 3971, 932) + tmp_b;
	WRITE_LINE(9, 9647) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_10(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(16, 15922, 120) * 9 / 8 + LINE(15, 14952, 334) * 9 / 8 + LINE(14, 14138, 252) * 9 / 8 + LINE(13, 13180, 478) * 9 / 8 + LINE(8, 9647, 369) * 9 / 8 + LINE(7, 8772, 499) * 9 / 8 + LINE(6, 7889, 323) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(16, 15922, 129) * 9 / 8 + LINE(15, 14952, 130) * 9 / 8 + LINE(14, 14138, 459) * 9 / 8 + LINE(13, 13180, 277) * 9 / 8 + LINE(8, 9647, 363) * 9 / 8 + LINE(7, 8772, 208) * 9 / 8 + LINE(5, 6916, 491) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(21, 16381, 19) * 3 / 4 + LINE(0, 0, 1) / 2;
	WRITE_LINE(21, 16381) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 16360, 45) * 3 / 4 + LINE(21, 16381, 19);
	WRITE_LINE(20, 16360) = -Acc;
	Acc = Acc * -3 / 4 + LINE(19, 16313, 84) * 3 / 4 + LINE(20, 16360, 45);
	WRITE_LINE(19, 16313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(18, 16227, 125) * 3 / 4 + LINE(19, 16313, 84);
	WRITE_LINE(18, 16227) = -Acc;
	Acc = Acc * -3 / 4 + LINE(17, 16100, 176) * 3 / 4 + LINE(18, 16227, 125);
	WRITE_LINE(17, 16100) = -Acc;
	Acc = Acc * -3 / 4 + LINE(17, 16100, 176);
	tmp_b = Acc;
	Acc = LINE(16, 15922, 968) * 5 / 8 + LINE(12, 12432, 678) / 2;
	WRITE_LINE(12, 12432) = -Acc;
	Acc = -Acc / 2 + LINE(12, 12432, 678);
	WRITE_LINE(15, 14952) = Acc;
	Acc = LINE(15, 14952, 812) * 5 / 8 + LINE(11, 11752, 512) / 2;
	WRITE_LINE(11, 11752) = -Acc;
	Acc = -Acc / 2 + LINE(11, 11752, 512);
	WRITE_LINE(14, 14138) = Acc;
	Acc = LINE(14, 14138, 956) * 5 / 8 + LINE(10, 11238, 756) / 2;
	WRITE_LINE(10, 11238) = -Acc;
	Acc = -Acc / 2 + LINE(10, 11238, 756);
	WRITE_LINE(13, 13180) = Acc;
	Acc = LINE(13, 13180, 746) * 5 / 8 + LINE(9, 10480, 831) / 2;
	WRITE_LINE(9, 10480) = -Acc;
	Acc = -Acc / 2 + LINE(9, 10480, 831) + tmp_b;
	WRITE_LINE(16, 15922) = Acc;
	Acc = LINE(8, 9647, 873) * 5 / 8 + LINE(4, 5904, 512) / 2;
	WRITE_LINE(4, 5904) = -Acc;
	Acc = -Acc / 2 + LINE(4, 5904, 512);
	WRITE_LINE(7, 8772) = Acc;
	*out_left = tmp_5;
	Acc = LINE(7, 8772, 881) * 5 / 8 + LINE(3, 5390, 781) / 2;
	WRITE_LINE(3, 5390) = -Acc;
	Acc = -Acc / 2 + LINE(3, 5390, 781);
	WRITE_LINE(6, 7889) = Acc;
	Acc = LINE(6, 7889, 971) * 5 / 8 + LINE(2, 4607, 634) / 2;
	WRITE_LINE(2, 4607) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + LINE(2, 4607, 634);
	WRITE_LINE(5, 6916) = Acc;
	Acc = LINE(5, 6916, 1010) * 5 / 8 + LINE(1, 3971, 932) / 2;
	WRITE_LINE(1, 3971) = -Acc;
	Acc = -Acc / 2 + LINE(1, 3971, 932) + tmp_b;
	WRITE_LINE(8, 9647) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_11(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(18, 15922, 120) * 9 / 8 + LINE(17, 14952, 334) * 9 / 8 + LINE(16, 14138, 252) * 9 / 8 + LINE(15, 13180, 478) * 9 / 8 + LINE(10, 9647, 369) * 9 / 8 + LINE(9, 8772, 499) * 9 / 8 + LINE(8, 7889, 323) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(18, 15922, 129) * 9 / 8 + LINE(17, 14952, 130) * 9 / 8 + LINE(16, 14138, 459) * 9 / 8 + LINE(15, 13180, 277) * 9 / 8 + LINE(10, 9647, 363) * 9 / 8 + LINE(9, 8772, 208) * 9 / 8 + LINE(7, 6916, 491) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(23, 16381, 19) * 3 / 4 + LINE(0, 0, 1) / 2;
	WRITE_LINE(23, 16381) = -Acc;
	Acc = Acc * -3 / 4 + LINE(22, 16360, 45) * 3 / 4 + LINE(23, 16381, 19);
	WRITE_LINE(22, 16360) = -Acc;
	Acc = Acc * -3 / 4 + LINE(21, 16313, 84) * 3 / 4 + LINE(22, 16360, 45);
	WRITE_LINE(21, 16313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 16227, 125) * 3 / 4 + LINE(21, 16313, 84);
	WRITE_LINE(20, 16227) = -Acc;
	Acc = Acc * -3 / 4 + LINE(19, 16100, 176) * 3 / 4 + LINE(20, 16227, 125);
	WRITE_LINE(19, 16100) = -Acc;
	Acc = Acc * -3 / 4 + LINE(19, 16100, 176);
	tmp_b = Acc;
	Acc = LINE(18, 15922, 968) * 3 / 4 + LINE(14, 12432, 678) / 2;
	WRITE_LINE(14, 12432) = -Acc;
	Acc = -Acc / 2 + LINE(14, 12432, 678);
	WRITE_LINE(17, 14952) = Acc;
	Acc = LINE(17, 14952, 812) * 3 / 4 + LINE(13, 11752, 512) / 2;
	WRITE_LINE(13, 11752) = -Acc;
	Acc = -Acc / 2 + LINE(13, 11752, 512);
	WRITE_LINE(16, 14138) = Acc;
	Acc = LINE(16, 14138, 956) * 5 / 8 + LINE(12, 11238, 756) / 2;
	WRITE_LINE(12, 11238) = -Acc;
	Acc = -Acc / 2 + LINE(12, 11238, 756);
	WRITE_LINE(15, 13180) = Acc;
	Acc = LINE(15, 13180, 746) * 5 / 8 + LINE(11, 10480, 831) / 2;
	WRITE_LINE(11, 10480) = -Acc;
	Acc = -Acc / 2 + LINE(11, 10480, 831) + LINE(2, 3034, 1) / 2;
	WRITE_LINE(2, 3034) = Acc;
	Acc = LINE(2, 3034, 0) / 2 + tmp_b;
	WRITE_LINE(18, 15922) = Acc;
	Acc = LINE(10, 9647, 873) * 3 / 4 + LINE(6, 5904, 512) / 2;
	WRITE_LINE(6, 5904) = -Acc;
	Acc = -Acc / 2 + LINE(6, 5904, 512);
	WRITE_LINE(9, 8772) = Acc;
	*out_left = tmp_5;
	Acc = LINE(9, 8772, 881) * 3 / 4 + LINE(5, 5390, 781) / 2;
	WRITE_LINE(5, 5390) = -Acc;
	Acc = -Acc / 2 + LINE(5, 5390, 781);
	WRITE_LINE(8, 7889) = Acc;
	Acc = LINE(8, 7889, 971) * 5 / 8 + LINE(4, 4607, 634) / 2;
	WRITE_LINE(4, 4607) = -Acc;
	Acc = -Acc / 2 + LINE(4, 4607, 634);
	WRITE_LINE(7, 6916) = Acc;
	*out_right = tmp_3;
	Acc = LINE(7, 6916, 1010) * 5 / 8 + LINE(3, 3971, 932) / 2;
	WRITE_LINE(3, 3971) = -Acc;
	Acc = -Acc / 2 + LINE(3, 3971, 932) + LINE(1, 3031, 1) / 2;
	WRITE_LINE(1, 3031) = Acc;
	Acc = LINE(1, 3031, 0) / 2 + tmp_b;
	WRITE_LINE(10, 9647) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_12(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(18, 15417, 37) * 3 / 4 + LINE(17, 14594, 336) * 3 / 4 + LINE(16, 13980, 454) * 3 / 4 + LINE(15, 13222, 478) * 3 / 4 + LINE(10, 9824, 569) * 3 / 4 + LINE(9, 8887, 499) * 3 / 4 + LINE(8, 7904, 723) * 3 / 4 + LINE(7, 7031, 391) * 3 / 4;
	tmp_3 = Acc;
	Acc = LINE(18, 15417, 370) * 3 / 4 + LINE(17, 14594, 230) * 3 / 4 + LINE(16, 13980, 457) * 3 / 4 + LINE(15, 13222, 477) * 3 / 4 + LINE(10, 9824, 569) * 3 / 4 + LINE(9, 8887, 208) * 3 / 4 + LINE(8, 7904, 223) * 3 / 4 + LINE(7, 7031, 891) * 3 / 4;
	tmp_5 = Acc;
	Acc = LINE(2, 3852, 1) / 2 + LINE(0, 0, 451) / 2;
	WRITE_LINE(2, 3852) = Acc;
	Acc = LINE(24, 15931, 7) * 3 / 4 + LINE(0, 0, 451) / 2;
	WRITE_LINE(24, 15931) = -Acc;
	Acc = Acc * -3 / 4 + LINE(23, 15922, 15) * 3 / 4 + LINE(24, 15931, 7);
	WRITE_LINE(23, 15922) = -Acc;
	Acc = Acc * -3 / 4 + LINE(22, 15905, 34) * 3 / 4 + LINE(23, 15922, 15);
	WRITE_LINE(22, 15905) = -Acc;
	Acc = Acc * -3 / 4 + LINE(21, 15869, 75) * 3 / 4 + LINE(22, 15905, 34);
	WRITE_LINE(21, 15869) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 15792, 135) * 3 / 4 + LINE(21, 15869, 75);
	WRITE_LINE(20, 15792) = -Acc;
	Acc = Acc * -3 / 4 + LINE(19, 15655, 236) * 3 / 4 + LINE(20, 15792, 135);
	WRITE_LINE(19, 15655) = -Acc;
	Acc = Acc * -9 / 8 + LINE(19, 15655, 236) * 3 / 2;
	tmp_b = Acc;
	Acc = LINE(18, 15417, 821) / 2 + LINE(18, 15417, 822) / 2 + LINE(14, 12242, 789) / 2;
	WRITE_LINE(14, 12242) = -Acc;
	Acc = -Acc / 2 + LINE(14, 12242, 789);
	WRITE_LINE(17, 14594) = Acc;
	Acc = LINE(17, 14594, 612) / 2 + LINE(17, 14594, 613) / 2 + LINE(13, 11451, 412) / 2;
	WRITE_LINE(13, 11451) = -Acc;
	Acc = -Acc / 2 + LINE(13, 11451, 412);
	WRITE_LINE(16, 13980) = Acc;
	Acc = LINE(16, 13980, 756) * -3 / 8 + LINE(16, 13980, 757) * -3 / 8 + LINE(12, 11037, 678) / 2;
	WRITE_LINE(12, 11037) = -Acc;
	Acc = -Acc / 2 + LINE(12, 11037, 678);
	WRITE_LINE(15, 13222) = Acc;
	Acc = LINE(15, 13222, 978) / 2 + LINE(11, 10357, 531) / 2;
	WRITE_LINE(11, 10357) = -Acc;
	Acc = -Acc / 2 + LINE(11, 10357, 531);
	WRITE_LINE(10, 9824) = Acc;
	Acc = LINE(10, 9824, 935) * 3 / 4 + LINE(6, 5819, 612) / 2;
	WRITE_LINE(6, 5819) = -Acc;
	Acc = -Acc / 2 + LINE(6, 5819, 612);
	WRITE_LINE(9, 8887) = Acc;
	*out_left = tmp_5;
	Acc = LINE(9, 8887, 981) * -3 / 8 + LINE(9, 8887, 982) * -3 / 8 + LINE(5, 5205, 381) / 2;
	WRITE_LINE(5, 5205) = -Acc;
	Acc = -Acc / 2 + LINE(5, 5205, 381);
	WRITE_LINE(8, 7904) = Acc;
	Acc = LINE(8, 7904, 871) * 3 / 4 + LINE(4, 4822, 534) / 2;
	WRITE_LINE(4, 4822) = -Acc;
	Acc = -Acc / 2 + LINE(4, 4822, 534);
	WRITE_LINE(7, 7031) = Acc;
	*out_right = tmp_3;
	Acc = LINE(7, 7031, 1210) * 3 / 4 + LINE(3, 4286, 432) / 2;
	WRITE_LINE(3, 4286) = -Acc;
	Acc = Acc / 4 + -LINE(3, 4286, 432) / 2 + LINE(1, 3846, 1) / 2;
	WRITE_LINE(1, 3846) = Acc;
	Acc = LINE(1, 3846, 0) + tmp_b;
	WRITE_LINE(18, 15417) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_13(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(18, 15417, 37) * 3 / 4 + LINE(17, 14794, 236) * 3 / 4 + LINE(16, 14380, 454) * 3 / 4 + LINE(15, 13922, 478) * 3 / 4 + LINE(10, 10081, 569) * 3 / 4 + LINE(9, 9144, 499) * 3 / 4 + LINE(8, 8161, 723) * 3 / 4 + LINE(7, 7288, 391) * 3 / 4;
	tmp_3 = Acc;
	Acc = LINE(18, 15417, 37) * 3 / 4 + LINE(17, 14794, 230) * 3 / 4 + LINE(16, 14380, 457) * 3 / 4 + LINE(15, 13922, 477) * 3 / 4 + LINE(10, 10081, 569) * 3 / 4 + LINE(9, 9144, 508) * 3 / 4 + LINE(8, 8161, 223) * 3 / 4 + LINE(7, 7288, 891) * 3 / 4;
	tmp_5 = Acc;
	Acc = LINE(2, 3509, 1) / 2 + LINE(0, 0, 451) / 2;
	WRITE_LINE(2, 3509) = Acc;
	Acc = LINE(24, 15931, 7) * 3 / 4 + LINE(0, 0, 451) / 2;
	WRITE_LINE(24, 15931) = -Acc;
	Acc = Acc * -3 / 4 + LINE(23, 15922, 15) * 3 / 4 + LINE(24, 15931, 7);
	WRITE_LINE(23, 15922) = -Acc;
	Acc = Acc * -3 / 4 + LINE(22, 15905, 34) * 3 / 4 + LINE(23, 15922, 15);
	WRITE_LINE(22, 15905) = -Acc;
	Acc = Acc * -3 / 4 + LINE(21, 15869, 75) * 3 / 4 + LINE(22, 15905, 34);
	WRITE_LINE(21, 15869) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 15792, 135) * 3 / 4 + LINE(21, 15869, 75);
	WRITE_LINE(20, 15792) = -Acc;
	Acc = Acc * -3 / 4 + LINE(19, 15655, 236) * 3 / 4 + LINE(20, 15792, 135);
	WRITE_LINE(19, 15655) = -Acc;
	Acc = Acc * -9 / 8 + LINE(19, 15655, 236) * 3 / 2;
	tmp_b = Acc;
	Acc = LINE(18, 15417, 621) / 2 + LINE(18, 15417, 622) / 2 + LINE(14, 13342, 789) / 2;
	WRITE_LINE(14, 13342) = -Acc;
	Acc = -Acc / 2 + LINE(14, 13342, 789);
	WRITE_LINE(17, 14794) = Acc;
	Acc = LINE(17, 14794, 412) / 2 + LINE(17, 14794, 413) / 2 + LINE(13, 12551, 912) / 2;
	WRITE_LINE(13, 12551) = -Acc;
	Acc = -Acc / 2 + LINE(13, 12551, 912);
	WRITE_LINE(16, 14380) = Acc;
	Acc = LINE(16, 14380, 456) * -3 / 8 + LINE(16, 14380, 457) * -3 / 8 + LINE(12, 11637, 1021) / 2;
	WRITE_LINE(12, 11637) = -Acc;
	Acc = -Acc / 2 + LINE(12, 11637, 1021);
	WRITE_LINE(15, 13922) = Acc;
	Acc = LINE(15, 13922, 578) / 2 + LINE(11, 10614, 531) / 2;
	WRITE_LINE(11, 10614) = -Acc;
	Acc = -Acc / 2 + LINE(11, 10614, 531);
	WRITE_LINE(10, 10081) = Acc;
	Acc = LINE(10, 10081, 935) * 3 / 4 + LINE(6, 6076, 712) / 2;
	WRITE_LINE(6, 6076) = -Acc;
	Acc = -Acc / 2 + LINE(6, 6076, 712);
	WRITE_LINE(9, 9144) = Acc;
	*out_left = tmp_5;
	Acc = LINE(9, 9144, 981) * -3 / 8 + LINE(9, 9144, 982) * -3 / 8 + LINE(5, 5362, 381) / 2;
	WRITE_LINE(5, 5362) = -Acc;
	Acc = -Acc / 2 + LINE(5, 5362, 381);
	WRITE_LINE(8, 8161) = Acc;
	Acc = LINE(8, 8161, 871) * 3 / 4 + LINE(4, 4979, 634) / 2;
	WRITE_LINE(4, 4979) = -Acc;
	Acc = -Acc / 2 + LINE(4, 4979, 634);
	WRITE_LINE(7, 7288) = Acc;
	*out_right = tmp_3;
	Acc = LINE(7, 7288, 1210) * 3 / 4 + LINE(3, 4343, 832) / 2;
	WRITE_LINE(3, 4343) = -Acc;
	Acc = Acc / 4 + -LINE(3, 4343, 832) / 2 + LINE(1, 3503, 1) / 2;
	WRITE_LINE(1, 3503) = Acc;
	Acc = LINE(1, 3503, 0) + tmp_b;
	WRITE_LINE(18, 15417) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_14(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(17, 15922, 120) * 9 / 8 + LINE(16, 15252, 334) * 9 / 8 + LINE(15, 14438, 252) * 9 / 8 + LINE(14, 13480, 478) * 9 / 8 + LINE(9, 9683, 369) * 9 / 8 + LINE(8, 9008, 499) * 9 / 8 + LINE(7, 8125, 723) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(17, 15922, 129) * 9 / 8 + LINE(16, 15252, 130) * 9 / 8 + LINE(15, 14438, 459) * 9 / 8 + LINE(14, 13480, 277) * 9 / 8 + LINE(9, 9683, 363) * 9 / 8 + LINE(8, 9008, 208) * 9 / 8 + LINE(6, 7152, 891) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(1, 3073, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(1, 3073) = Acc;
	Acc = LINE(22, 16381, 19) * 3 / 4 + LINE(1, 3073, 1) / 2;
	WRITE_LINE(22, 16381) = -Acc;
	Acc = Acc * -3 / 4 + LINE(21, 16360, 45) * 3 / 4 + LINE(22, 16381, 19);
	WRITE_LINE(21, 16360) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 16313, 84) * 3 / 4 + LINE(21, 16360, 45);
	WRITE_LINE(20, 16313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(19, 16227, 125) * 3 / 4 + LINE(20, 16313, 84);
	WRITE_LINE(19, 16227) = -Acc;
	Acc = Acc * -3 / 4 + LINE(18, 16100, 176) * 3 / 4 + LINE(19, 16227, 125);
	WRITE_LINE(18, 16100) = -Acc;
	Acc = Acc * -3 / 4 + LINE(18, 16100, 176);
	tmp_b = Acc;
	Acc = LINE(17, 15922, 668) * 3 / 4 + LINE(13, 12468, 678) / 2;
	WRITE_LINE(13, 12468) = -Acc;
	Acc = -Acc / 2 + LINE(13, 12468, 678);
	WRITE_LINE(16, 15252) = Acc;
	Acc = LINE(16, 15252, 812) * 3 / 4 + LINE(12, 11788, 512) / 2;
	WRITE_LINE(12, 11788) = -Acc;
	Acc = -Acc / 2 + LINE(12, 11788, 512);
	WRITE_LINE(15, 14438) = Acc;
	Acc = LINE(15, 14438, 956) * 3 / 4 + LINE(11, 11274, 756) / 2;
	WRITE_LINE(11, 11274) = -Acc;
	Acc = -Acc / 2 + LINE(11, 11274, 756);
	WRITE_LINE(14, 13480) = Acc;
	Acc = LINE(14, 13480, 1010) * 3 / 4 + LINE(10, 10516, 831) / 2;
	WRITE_LINE(10, 10516) = -Acc;
	Acc = -Acc / 2 + LINE(10, 10516, 831) + tmp_b;
	WRITE_LINE(17, 15922) = Acc;
	Acc = LINE(9, 9683, 673) * 3 / 4 + LINE(5, 5940, 512) / 2;
	WRITE_LINE(5, 5940) = -Acc;
	Acc = -Acc / 2 + LINE(5, 5940, 512);
	WRITE_LINE(8, 9008) = Acc;
	Acc = LINE(8, 9008, 881) * 3 / 4 + LINE(4, 5426, 781) / 2;
	WRITE_LINE(4, 5426) = -Acc;
	Acc = -Acc / 2 + LINE(4, 5426, 781);
	WRITE_LINE(7, 8125) = Acc;
	*out_left = tmp_5;
	Acc = LINE(7, 8125, 971) * 3 / 4 + LINE(3, 4643, 634) / 2;
	WRITE_LINE(3, 4643) = -Acc;
	Acc = -Acc / 2 + LINE(3, 4643, 634);
	WRITE_LINE(6, 7152) = Acc;
	Acc = LINE(6, 7152, 1210) * 3 / 4 + LINE(2, 4007, 932) / 2;
	WRITE_LINE(2, 4007) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + LINE(2, 4007, 932) + tmp_b;
	WRITE_LINE(9, 9683) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_15(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(19, 15922, 520) * 9 / 8 + LINE(18, 14952, 334) * 9 / 8 + LINE(17, 14138, 252) * 9 / 8 + LINE(16, 13180, 478) * 9 / 8 + LINE(11, 9183, 369) * 9 / 8 + LINE(10, 8408, 499) * 9 / 8 + LINE(9, 7525, 723) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(19, 15922, 129) * 9 / 8 + LINE(18, 14952, 130) * 9 / 8 + LINE(17, 14138, 459) * 9 / 8 + LINE(16, 13180, 277) * 9 / 8 + LINE(11, 9183, 363) * 9 / 8 + LINE(10, 8408, 208) * 9 / 8 + LINE(8, 6552, 891) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(3, 2473, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(3, 2473) = Acc;
	Acc = LINE(24, 16381, 19) * 3 / 4 + LINE(0, 0, 1) / 2;
	WRITE_LINE(24, 16381) = -Acc;
	Acc = Acc * -3 / 4 + LINE(23, 16360, 45) * 3 / 4 + LINE(24, 16381, 19);
	WRITE_LINE(23, 16360) = -Acc;
	Acc = Acc * -3 / 4 + LINE(22, 16313, 84) * 3 / 4 + LINE(23, 16360, 45);
	WRITE_LINE(22, 16313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(21, 16227, 125) * 3 / 4 + LINE(22, 16313, 84);
	WRITE_LINE(21, 16227) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 16100, 176) * 3 / 4 + LINE(21, 16227, 125);
	WRITE_LINE(20, 16100) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 16100, 176);
	tmp_b = Acc;
	Acc = LINE(19, 15922, 968) * 3 / 4 + LINE(15, 12068, 678) / 2;
	WRITE_LINE(15, 12068) = -Acc;
	Acc = -Acc / 2 + LINE(15, 12068, 678);
	WRITE_LINE(18, 14952) = Acc;
	Acc = LINE(18, 14952, 812) * 3 / 4 + LINE(14, 11388, 612) / 2;
	WRITE_LINE(14, 11388) = -Acc;
	Acc = -Acc / 2 + LINE(14, 11388, 612);
	WRITE_LINE(17, 14138) = Acc;
	Acc = LINE(17, 14138, 956) * 3 / 4 + LINE(13, 10774, 756) / 2;
	WRITE_LINE(13, 10774) = -Acc;
	Acc = -Acc / 2 + LINE(13, 10774, 756);
	WRITE_LINE(16, 13180) = Acc;
	Acc = LINE(16, 13180, 1110) * 3 / 4 + LINE(12, 10016, 831) / 2;
	WRITE_LINE(12, 10016) = -Acc;
	Acc = -Acc / 2 + LINE(12, 10016, 831) + LINE(2, 2470, 1) / 2;
	WRITE_LINE(2, 2470) = Acc;
	Acc = LINE(2, 2470, 0) / 2 + tmp_b;
	WRITE_LINE(19, 15922) = Acc;
	Acc = LINE(11, 9183, 773) * 3 / 4 + LINE(7, 5340, 512) / 2;
	WRITE_LINE(7, 5340) = -Acc;
	Acc = -Acc / 2 + LINE(7, 5340, 512);
	WRITE_LINE(10, 8408) = Acc;
	Acc = LINE(10, 8408, 881) * 3 / 4 + LINE(6, 4826, 781) / 2;
	WRITE_LINE(6, 4826) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + LINE(6, 4826, 781);
	WRITE_LINE(9, 7525) = Acc;
	Acc = LINE(9, 7525, 971) * 3 / 4 + LINE(5, 4043, 634) / 2;
	WRITE_LINE(5, 4043) = -Acc;
	Acc = -Acc / 2 + LINE(5, 4043, 634);
	WRITE_LINE(8, 6552) = Acc;
	Acc = LINE(8, 6552, 1210) * 3 / 4 + LINE(4, 3407, 932) / 2;
	WRITE_LINE(4, 3407) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + LINE(4, 3407, 932) + LINE(1, 2467, 1) / 2;
	WRITE_LINE(1, 2467) = Acc;
	Acc = LINE(1, 2467, 0) / 2 + tmp_b;
	WRITE_LINE(11, 9183) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_16(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(17, 15922, 120) * 9 / 8 + LINE(16, 15252, 334) * 9 / 8 + LINE(15, 14438, 252) * 9 / 8 + LINE(14, 13480, 478) * 9 / 8 + LINE(9, 9683, 369) * 9 / 8 + LINE(8, 9008, 499) * 9 / 8 + LINE(7, 8125, 723) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(17, 15922, 129) * 9 / 8 + LINE(16, 15252, 130) * 9 / 8 + LINE(15, 14438, 459) * 9 / 8 + LINE(14, 13480, 277) * 9 / 8 + LINE(9, 9683, 363) * 9 / 8 + LINE(8, 9008, 208) * 9 / 8 + LINE(6, 7152, 891) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(1, 3073, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(1, 3073) = Acc;
	Acc = LINE(22, 16381, 19) * 3 / 4 + LINE(0, 0, 1) / 2;
	WRITE_LINE(22, 16381) = -Acc;
	Acc = Acc * -3 / 4 + LINE(21, 16360, 45) * 3 / 4 + LINE(22, 16381, 19);
	WRITE_LINE(21, 16360) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 16313, 84) * 3 / 4 + LINE(21, 16360, 45);
	WRITE_LINE(20, 16313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(19, 16227, 125) * 3 / 4 + LINE(20, 16313, 84);
	WRITE_LINE(19, 16227) = -Acc;
	Acc = Acc * -3 / 4 + LINE(18, 16100, 176) * 3 / 4 + LINE(19, 16227, 125);
	WRITE_LINE(18, 16100) = -Acc;
	Acc = Acc * -3 / 4 + LINE(18, 16100, 176);
	tmp_b = Acc;
	Acc = LINE(17, 15922, 668) * 3 / 4 + LINE(13, 12468, 678) / 2;
	WRITE_LINE(13, 12468) = -Acc;
	Acc = -Acc / 2 + LINE(13, 12468, 678);
	WRITE_LINE(16, 15252) = Acc;
	Acc = LINE(16, 15252, 812) * 3 / 4 + LINE(12, 11788, 512) / 2;
	WRITE_LINE(12, 11788) = -Acc;
	Acc = -Acc / 2 + LINE(12, 11788, 512);
	WRITE_LINE(15, 14438) = Acc;
	Acc = LINE(15, 14438, 956) * 3 / 4 + LINE(11, 11274, 756) / 2;
	WRITE_LINE(11, 11274) = -Acc;
	Acc = -Acc / 2 + LINE(11, 11274, 756);
	WRITE_LINE(14, 13480) = Acc;
	Acc = LINE(14, 13480, 1010) * 3 / 4 + LINE(10, 10516, 831) / 2;
	WRITE_LINE(10, 10516) = -Acc;
	Acc = -Acc / 2 + LINE(10, 10516, 831) + tmp_b;
	WRITE_LINE(17, 15922) = Acc;
	Acc = LINE(9, 9683, 673) * 3 / 4 + LINE(5, 5940, 512) / 2;
	WRITE_LINE(5, 5940) = -Acc;
	Acc = -Acc / 2 + LINE(5, 5940, 512);
	WRITE_LINE(8, 9008) = Acc;
	Acc = LINE(8, 9008, 881) * 3 / 4 + LINE(4, 5426, 781) / 2;
	WRITE_LINE(4, 5426) = -Acc;
	Acc = -Acc / 2 + LINE(4, 5426, 781);
	WRITE_LINE(7, 8125) = Acc;
	*out_left = tmp_5;
	Acc = LINE(7, 8125, 971) * 3 / 4 + LINE(3, 4643, 634) / 2;
	WRITE_LINE(3, 4643) = -Acc;
	Acc = -Acc / 2 + LINE(3, 4643, 634);
	WRITE_LINE(6, 7152) = Acc;
	Acc = LINE(6, 7152, 1210) * 3 / 4 + LINE(2, 4007, 932) / 2;
	WRITE_LINE(2, 4007) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + LINE(2, 4007, 932) + tmp_b;
	WRITE_LINE(9, 9683) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_17(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 13337, 211) * 3 / 4 + LINE(6, 10417, 1391) * 3 / 4 + LINE(4, 6832, 1403) * 3 / 4;
	tmp_3 = Acc;
	Acc = LINE(8, 13337, 211) * 3 / 4 + LINE(6, 10417, 690) * 3 / 4 + LINE(4, 6832, 471) * 3 / 4;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 457) / 2 + LINE(2, 3759, 1) / 2;
	WRITE_LINE(2, 3759) = Acc;
	Acc = LINE(0, 0, 457) / 2 + LINE(14, 15925, 321) / 2;
	WRITE_LINE(14, 15925) = -Acc;
	Acc = -Acc / 2 + LINE(14, 15925, 321) + LINE(13, 15602, 431) / 2;
	WRITE_LINE(13, 15602) = -Acc;
	Acc = -Acc / 2 + LINE(13, 15602, 431) + LINE(12, 15169, 668) / 2;
	WRITE_LINE(12, 15169) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15169, 668) + LINE(11, 14499, 808) / 2;
	WRITE_LINE(11, 14499) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14499, 808) + LINE(10, 13689, 204) / 2;
	WRITE_LINE(10, 13689) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13689, 204) + LINE(9, 13483, 144) / 2;
	WRITE_LINE(9, 13483) = -Acc;
	Acc = Acc * -9 / 8 + LINE(9, 13483, 144) * 9 / 4;
	tmp_b = Acc;
	Acc = LINE(8, 13337, 1724) * 3 / 4 + LINE(7, 11611, 1192) / 2;
	WRITE_LINE(7, 11611) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11611, 1192);
	WRITE_LINE(6, 10417) = Acc;
	Acc = LINE(6, 10417, 2510) * 5 / 8 + LINE(5, 7905, 1071) / 2;
	WRITE_LINE(5, 7905) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7905, 1071);
	WRITE_LINE(4, 6832) = Acc;
	Acc = LINE(4, 6832, 1857) * 5 / 8 + LINE(3, 4973, 1212) / 2;
	WRITE_LINE(3, 4973) = -Acc;
	Acc = -Acc / 2 + LINE(3, 4973, 1212) + LINE(1, 3756, 1) / 2;
	WRITE_LINE(1, 3756) = Acc;
	Acc = LINE(1, 3756, 0) / 2 + tmp_b;
	WRITE_LINE(8, 13337) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_18(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 13793, 211) * 3 / 4 + LINE(6, 10673, 1391) * 3 / 4 + LINE(4, 6788, 1403) * 3 / 4;
	tmp_3 = Acc;
	Acc = LINE(8, 13793, 1101) * 3 / 4 + LINE(6, 10673, 690) * 3 / 4 + LINE(4, 6788, 471) * 3 / 4;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 3415, 1) / 2;
	WRITE_LINE(2, 3415) = Acc;
	Acc = LINE(2, 3415, 0) / 2 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 668) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 668) + LINE(11, 14955, 808) / 2;
	WRITE_LINE(11, 14955) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14955, 808) + LINE(10, 14145, 204) / 2;
	WRITE_LINE(10, 14145) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14145, 204) + LINE(9, 13939, 144) / 2;
	WRITE_LINE(9, 13939) = -Acc;
	Acc = Acc * -9 / 8 + LINE(9, 13939, 144) * 9 / 4;
	tmp_b = Acc;
	Acc = LINE(8, 13793, 1724) * 3 / 4 + LINE(7, 12067, 1392) / 2;
	WRITE_LINE(7, 12067) = -Acc;
	Acc = -Acc / 2 + LINE(7, 12067, 1392);
	WRITE_LINE(6, 10673) = Acc;
	Acc = LINE(6, 10673, 2510) * 5 / 8 + LINE(5, 8161, 1371) / 2;
	WRITE_LINE(5, 8161) = -Acc;
	Acc = -Acc / 2 + LINE(5, 8161, 1371);
	WRITE_LINE(4, 6788) = Acc;
	Acc = LINE(4, 6788, 1857) * 5 / 8 + LINE(3, 4929, 1512) / 2;
	WRITE_LINE(3, 4929) = -Acc;
	Acc = -Acc / 2 + LINE(3, 4929, 1512) + LINE(1, 3412, 1) / 2;
	WRITE_LINE(1, 3412) = Acc;
	Acc = LINE(1, 3412, 0) / 2 + tmp_b;
	WRITE_LINE(8, 13793) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_19(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 13254, 64) * 3 / 4 + LINE(8, 10744, 696) * 3 / 4 + LINE(4, 5956, 539) * 3 / 4 + LINE(0, 0, 178) * 3 / 4;
	tmp_5 = Acc;
	Acc = LINE(10, 13254, 503) * 3 / 4 + LINE(8, 10744, 167) * 3 / 4 + LINE(4, 5956, 151) * 3 / 4 + LINE(0, 0, 511) * 3 / 4;
	tmp_3 = Acc;
	Acc = LINE(15, 14382, 58) * 5 / 8 + LINE(0, 0, 2000) / 2;
	WRITE_LINE(15, 14382) = -Acc;
	Acc = LINE(14, 14322, 89) * 5 / 8 + LINE(15, 14382, 0) * 5 / 8 + LINE(15, 14382, 58);
	WRITE_LINE(14, 14322) = -Acc;
	Acc = LINE(13, 14231, 183) * 5 / 8 + LINE(14, 14322, 0) * 5 / 8 + LINE(14, 14322, 89);
	WRITE_LINE(13, 14231) = -Acc;
	Acc = LINE(12, 14046, 321) * 5 / 8 + LINE(13, 14231, 0) * 5 / 8 + LINE(13, 14231, 183);
	WRITE_LINE(12, 14046) = -Acc;
	Acc = LINE(11, 13723, 467) * 5 / 8 + LINE(12, 14046, 0) * 5 / 8 + LINE(12, 14046, 321);
	WRITE_LINE(11, 13723) = -Acc;
	Acc = Acc * -3 / 16 + LINE(11, 13723, 0) * 3 / 4 + LINE(11, 13723, 467) * 3 / 2;
	tmp_b = Acc;
	Acc = LINE(10, 13254, 1385) * 3 / 4 + LINE(9, 11867, 1121) / 2;
	WRITE_LINE(9, 11867) = -Acc;
	Acc = -Acc / 2 + LINE(9, 11867, 1121);
	WRITE_LINE(8, 10744) = Acc;
	Acc = LINE(8, 10744, 1641) * 3 / 4 + LINE(7, 9101, 1020) / 2;
	WRITE_LINE(7, 9101) = -Acc;
	Acc = -Acc / 2 + LINE(7, 9101, 1020);
	tmp_1 = Acc;
	Acc = LINE(2, 3434, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(2, 3434) = Acc;
	Acc = LINE(2, 3434, 1) + tmp_b;
	WRITE_LINE(10, 13254) = Acc;
	Acc = LINE(6, 8079, 1211) * 3 / 4 + LINE(5, 6866, 908) / 2;
	WRITE_LINE(5, 6866) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6866, 908);
	WRITE_LINE(4, 5956) = Acc;
	Acc = LINE(4, 5956, 1417) * 3 / 4 + LINE(3, 4537, 1098) / 2;
	WRITE_LINE(3, 4537) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + LINE(3, 4537, 1098);
	tmp_1 = Acc;
	Acc = LINE(1, 3431, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 3431) = Acc;
	Acc = LINE(1, 3431, 1) + tmp_b;
	WRITE_LINE(6, 8079) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_20(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 15253, 64) * 3 / 4 + LINE(8, 13283, 696) * 3 / 4 + LINE(4, 8586, 539) * 3 / 4 + LINE(13, 16230, 24) * 3 / 4;
	tmp_5 = Acc;
	Acc = LINE(10, 15253, 503) * 3 / 4 + LINE(8, 13283, 167) * 3 / 4 + LINE(4, 8586, 151) * 3 / 4 + LINE(12, 16045, 172) * 3 / 4;
	tmp_3 = Acc;
	Acc = LINE(15, 16381, 58) * 5 / 8 + LINE(0, 0, 1) / 2;
	WRITE_LINE(15, 16381) = -Acc;
	Acc = LINE(14, 16321, 89) * 5 / 8 + LINE(15, 16381, 0) * 5 / 8 + LINE(15, 16381, 58);
	WRITE_LINE(14, 16321) = -Acc;
	Acc = LINE(13, 16230, 183) * 5 / 8 + LINE(14, 16321, 0) * 5 / 8 + LINE(14, 16321, 89);
	WRITE_LINE(13, 16230) = -Acc;
	Acc = LINE(12, 16045, 321) * 5 / 8 + LINE(13, 16230, 0) * 5 / 8 + LINE(13, 16230, 183);
	WRITE_LINE(12, 16045) = -Acc;
	Acc = LINE(11, 15722, 467) * 5 / 8 + LINE(12, 16045, 0) * 5 / 8 + LINE(12, 16045, 321);
	WRITE_LINE(11, 15722) = -Acc;
	Acc = Acc * -3 / 16 + LINE(11, 15722, 0) * 3 / 4 + LINE(11, 15722, 467) * 3 / 2;
	tmp_b = Acc;
	Acc = LINE(10, 15253, 845) * 3 / 4 + LINE(9, 14406, 1121) / 2;
	WRITE_LINE(9, 14406) = -Acc;
	Acc = -Acc / 2 + LINE(9, 14406, 1121);
	WRITE_LINE(8, 13283) = Acc;
	Acc = LINE(8, 13283, 1441) * 3 / 4 + LINE(7, 11840, 1320) / 2;
	WRITE_LINE(7, 11840) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11840, 1320);
	tmp_1 = Acc;
	Acc = LINE(2, 6264, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(2, 6264) = Acc;
	Acc = LINE(2, 6264, 1) + tmp_b;
	WRITE_LINE(10, 15253) = Acc;
	Acc = LINE(6, 10518, 912) * 3 / 4 + LINE(5, 9604, 1016) / 2;
	WRITE_LINE(5, 9604) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9604, 1016);
	WRITE_LINE(4, 8586) = Acc;
	Acc = LINE(4, 8586, 1017) * 3 / 4 + LINE(3, 7567, 1298) / 2;
	WRITE_LINE(3, 7567) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + LINE(3, 7567, 1298);
	tmp_1 = Acc;
	Acc = LINE(1, 6261, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 6261) = Acc;
	Acc = LINE(1, 6261, 1) + tmp_b;
	WRITE_LINE(6, 10518) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_21(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(17, 15822, 120) * 3 / 4 + LINE(16, 14952, 634) * 3 / 4 + LINE(15, 13905, 552) * 3 / 4 + LINE(14, 12769, 478) * 3 / 4 + LINE(9, 8225, 369) * 3 / 4 + LINE(8, 7182, 208) * 3 / 4 + LINE(7, 6199, 723) * 3 / 4;
	tmp_3 = Acc;
	Acc = LINE(17, 15822, 129) * 3 / 4 + LINE(16, 14952, 130) * 3 / 4 + LINE(15, 13905, 359) * 3 / 4 + LINE(14, 12769, 277) * 3 / 4 + LINE(9, 8225, 363) * 3 / 4 + LINE(8, 7182, 499) * 3 / 4 + LINE(6, 5096, 891) * 3 / 4;
	tmp_5 = Acc;
	Acc = LINE(1, 365, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(1, 365) = Acc;
	Acc = LINE(22, 16381, 19) * 3 / 4 + LINE(0, 0, 1) / 2;
	WRITE_LINE(22, 16381) = -Acc;
	Acc = Acc * -3 / 4 + LINE(21, 16360, 45) * 3 / 4 + LINE(22, 16381, 19);
	WRITE_LINE(21, 16360) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 16313, 84) * 3 / 4 + LINE(21, 16360, 45);
	WRITE_LINE(20, 16313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(19, 16227, 125) * 3 / 4 + LINE(20, 16313, 84);
	WRITE_LINE(19, 16227) = -Acc;
	Acc = Acc * -3 / 4 + LINE(18, 16100, 276) * 3 / 4 + LINE(19, 16227, 125);
	WRITE_LINE(18, 16100) = -Acc;
	Acc = Acc * -3 / 4 + LINE(18, 16100, 276);
	tmp_b = Acc;
	Acc = LINE(17, 15822, 868) * 3 / 4 + LINE(13, 11800, 878) / 2;
	WRITE_LINE(13, 11800) = -Acc;
	Acc = -Acc / 2 + LINE(13, 11800, 878);
	WRITE_LINE(16, 14952) = Acc;
	Acc = LINE(16, 14952, 1045) * 3 / 4 + LINE(12, 10920, 712) / 2;
	WRITE_LINE(12, 10920) = -Acc;
	Acc = -Acc / 2 + LINE(12, 10920, 712);
	WRITE_LINE(15, 13905) = Acc;
	Acc = LINE(15, 13905, 1134) / 2 + LINE(15, 13905, 1135) / 2 + LINE(11, 10206, 956) / 2;
	WRITE_LINE(11, 10206) = -Acc;
	Acc = -Acc / 2 + LINE(11, 10206, 956);
	WRITE_LINE(14, 12769) = Acc;
	Acc = LINE(14, 12769, 967) / 2 + LINE(14, 12769, 968) / 2 + LINE(10, 9248, 1021) / 2;
	WRITE_LINE(10, 9248) = -Acc;
	Acc = -Acc / 2 + LINE(10, 9248, 1021) + tmp_b;
	WRITE_LINE(17, 15822) = Acc;
	Acc = LINE(9, 8225, 1041) * 3 / 4 + LINE(5, 4084, 812) / 2;
	WRITE_LINE(5, 4084) = -Acc;
	Acc = -Acc / 2 + LINE(5, 4084, 812);
	WRITE_LINE(8, 7182) = Acc;
	Acc = LINE(8, 7182, 981) * 3 / 4 + LINE(4, 3270, 981) / 2;
	WRITE_LINE(4, 3270) = -Acc;
	Acc = -Acc / 2 + LINE(4, 3270, 981);
	WRITE_LINE(7, 6199) = Acc;
	*out_left = tmp_5;
	Acc = LINE(7, 6199, 1101) / 2 + LINE(7, 6199, 1102) / 2 + LINE(3, 2287, 934) / 2;
	WRITE_LINE(3, 2287) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2287, 934);
	WRITE_LINE(6, 5096) = Acc;
	Acc = LINE(6, 5096, 1010) / 2 + LINE(6, 5096, 1011) / 2 + LINE(2, 1351, 984) / 2;
	WRITE_LINE(2, 1351) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1351, 984) + tmp_b;
	WRITE_LINE(9, 8225) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_22(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(17, 15822, 420) * 3 / 4 + LINE(16, 14617, 634) * 3 / 4 + LINE(15, 13570, 552) * 3 / 4 + LINE(14, 12434, 478) * 3 / 4 + LINE(9, 9099, 269) * 3 / 4 + LINE(8, 8056, 208) * 3 / 4 + LINE(7, 7073, 723) * 3 / 4;
	tmp_3 = Acc;
	Acc = LINE(17, 15822, 129) * 3 / 4 + LINE(16, 14617, 130) * 3 / 4 + LINE(15, 13570, 359) * 3 / 4 + LINE(14, 12434, 277) * 3 / 4 + LINE(9, 9099, 363) * 3 / 4 + LINE(8, 8056, 499) * 3 / 4 + LINE(6, 5970, 891) * 3 / 4;
	tmp_5 = Acc;
	Acc = LINE(1, 2619, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(1, 2619) = Acc;
	Acc = LINE(22, 16381, 19) * 3 / 4 + LINE(0, 0, 1) / 2;
	WRITE_LINE(22, 16381) = -Acc;
	Acc = Acc * -3 / 4 + LINE(21, 16360, 45) * 3 / 4 + LINE(22, 16381, 19);
	WRITE_LINE(21, 16360) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 16313, 84) * 3 / 4 + LINE(21, 16360, 45);
	WRITE_LINE(20, 16313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(19, 16227, 125) * 3 / 4 + LINE(20, 16313, 84);
	WRITE_LINE(19, 16227) = -Acc;
	Acc = Acc * -3 / 4 + LINE(18, 16100, 276) * 3 / 4 + LINE(19, 16227, 125);
	WRITE_LINE(18, 16100) = -Acc;
	Acc = Acc * -3 / 4 + LINE(18, 16100, 276);
	tmp_b = Acc;
	Acc = LINE(17, 15822, 1203) * 3 / 4 + LINE(13, 11465, 578) / 2;
	WRITE_LINE(13, 11465) = -Acc;
	Acc = -Acc / 2 + LINE(13, 11465, 578);
	WRITE_LINE(16, 14617) = Acc;
	Acc = LINE(16, 14617, 1045) * 3 / 4 + LINE(12, 10885, 712) / 2;
	WRITE_LINE(12, 10885) = -Acc;
	Acc = -Acc / 2 + LINE(12, 10885, 712);
	WRITE_LINE(15, 13570) = Acc;
	Acc = LINE(15, 13570, 1134) / 2 + LINE(15, 13570, 1135) / 2 + LINE(11, 10171, 756) / 2;
	WRITE_LINE(11, 10171) = -Acc;
	Acc = -Acc / 2 + LINE(11, 10171, 756);
	WRITE_LINE(14, 12434) = Acc;
	Acc = LINE(14, 12434, 967) / 2 + LINE(14, 12434, 968) / 2 + LINE(10, 9413, 312) / 2;
	WRITE_LINE(10, 9413) = -Acc;
	Acc = -Acc / 2 + LINE(10, 9413, 312) + tmp_b;
	WRITE_LINE(17, 15822) = Acc;
	Acc = LINE(9, 9099, 1041) * 3 / 4 + LINE(5, 4958, 612) / 2;
	WRITE_LINE(5, 4958) = -Acc;
	Acc = -Acc / 2 + LINE(5, 4958, 612);
	WRITE_LINE(8, 8056) = Acc;
	Acc = LINE(8, 8056, 981) * 3 / 4 + LINE(4, 4344, 781) / 2;
	WRITE_LINE(4, 4344) = -Acc;
	Acc = -Acc / 2 + LINE(4, 4344, 781);
	WRITE_LINE(7, 7073) = Acc;
	*out_left = tmp_5;
	Acc = LINE(7, 7073, 1101) / 2 + LINE(7, 7073, 1102) / 2 + LINE(3, 3561, 634) / 2;
	WRITE_LINE(3, 3561) = -Acc;
	Acc = -Acc / 2 + LINE(3, 3561, 634);
	WRITE_LINE(6, 5970) = Acc;
	Acc = LINE(6, 5970, 1010) / 2 + LINE(6, 5970, 1011) / 2 + LINE(2, 2925, 304) / 2;
	WRITE_LINE(2, 2925) = -Acc;
	Acc = -Acc / 2 + LINE(2, 2925, 304) + tmp_b;
	WRITE_LINE(9, 9099) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_23(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 13326, 567) * 9 / 8 + LINE(6, 9506, 1891) * 9 / 8 + LINE(4, 5621, 2003) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(8, 13326, 1190) * 9 / 8 + LINE(6, 9506, 890) * 9 / 8 + LINE(4, 5621, 671) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 1148, 1) / 2;
	WRITE_LINE(2, 1148) = Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 668) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 668) + LINE(11, 14955, 1235) / 2;
	WRITE_LINE(11, 14955) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14955, 1235) + LINE(10, 13718, 234) / 2;
	WRITE_LINE(10, 13718) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13718, 234) + LINE(9, 13482, 154) / 2;
	WRITE_LINE(9, 13482) = -Acc;
	Acc = Acc * -3 / 4 + LINE(9, 13482, 154) * 3 / 2;
	tmp_b = Acc;
	Acc = LINE(8, 13326, 2224) / 2 + LINE(7, 11100, 1592) / 2;
	WRITE_LINE(7, 11100) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11100, 1592);
	WRITE_LINE(6, 9506) = Acc;
	Acc = LINE(6, 9506, 2610) * 3 / 4 + LINE(5, 6894, 1271) / 2;
	WRITE_LINE(5, 6894) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6894, 1271);
	WRITE_LINE(4, 5621) = Acc;
	Acc = LINE(4, 5621, 3357) / 2 + LINE(3, 2262, 1112) / 2;
	WRITE_LINE(3, 2262) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2262, 1112) + LINE(1, 1145, 1) / 2;
	WRITE_LINE(1, 1145) = Acc;
	Acc = LINE(1, 1145, 0) / 2 + tmp_b;
	WRITE_LINE(8, 13326) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_24(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 12327, 567) * 9 / 8 + LINE(6, 9007, 1891) * 9 / 8 + LINE(4, 5159, 2003) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(8, 12327, 567) * 9 / 8 + LINE(6, 9007, 890) * 9 / 8 + LINE(4, 5159, 671) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 1000) / 2 + LINE(2, 1012, 1) / 2;
	WRITE_LINE(2, 1012) = Acc;
	Acc = LINE(2, 1012, 1) / 2 + LINE(14, 15382, 321) / 2;
	WRITE_LINE(14, 15382) = -Acc;
	Acc = -Acc / 2 + LINE(14, 15382, 321) + LINE(13, 15059, 431) / 2;
	WRITE_LINE(13, 15059) = -Acc;
	Acc = -Acc / 2 + LINE(13, 15059, 431) + LINE(12, 14626, 668) / 2;
	WRITE_LINE(12, 14626) = -Acc;
	Acc = -Acc / 2 + LINE(12, 14626, 668) + LINE(11, 13956, 1235) / 2;
	WRITE_LINE(11, 13956) = -Acc;
	Acc = -Acc / 2 + LINE(11, 13956, 1235) + LINE(10, 12719, 234) / 2;
	WRITE_LINE(10, 12719) = -Acc;
	Acc = -Acc / 2 + LINE(10, 12719, 234) + LINE(9, 12483, 154) / 2;
	WRITE_LINE(9, 12483) = -Acc;
	Acc = Acc * -3 / 4 + LINE(9, 12483, 154) * 3 / 2;
	tmp_b = Acc;
	Acc = LINE(8, 12327, 2224) + LINE(7, 10101, 1092) / 2;
	WRITE_LINE(7, 10101) = -Acc;
	Acc = -Acc / 2 + LINE(7, 10101, 1092);
	WRITE_LINE(6, 9007) = Acc;
	Acc = LINE(6, 9007, 2610) * 3 / 4 + LINE(5, 6395, 1234) / 2;
	WRITE_LINE(5, 6395) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6395, 1234);
	WRITE_LINE(4, 5159) = Acc;
	Acc = LINE(4, 5159, 3357) / 2 + LINE(3, 1800, 786) / 2;
	WRITE_LINE(3, 1800) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1800, 786) + LINE(1, 1009, 1) / 2;
	WRITE_LINE(1, 1009) = Acc;
	Acc = LINE(1, 1009, 0) / 2 + tmp_b;
	WRITE_LINE(8, 12327) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_25(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 13326, 567) * 9 / 8 + LINE(6, 9506, 1891) * 9 / 8 + LINE(4, 5621, 2003) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(8, 13326, 1190) * 9 / 8 + LINE(6, 9506, 890) * 9 / 8 + LINE(4, 5621, 671) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 1148, 1) / 2;
	WRITE_LINE(2, 1148) = Acc;
	Acc = LINE(2, 1148, 1) / 2 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 668) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 668) + LINE(11, 14955, 1235) / 2;
	WRITE_LINE(11, 14955) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14955, 1235) + LINE(10, 13718, 234) / 2;
	WRITE_LINE(10, 13718) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13718, 234) + LINE(9, 13482, 154) / 2;
	WRITE_LINE(9, 13482) = -Acc;
	Acc = Acc * -3 / 4 + LINE(9, 13482, 154) * 3 / 2;
	tmp_b = Acc;
	Acc = LINE(8, 13326, 2224) + LINE(7, 11100, 1592) / 2;
	WRITE_LINE(7, 11100) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11100, 1592);
	WRITE_LINE(6, 9506) = Acc;
	Acc = LINE(6, 9506, 2610) * 3 / 4 + LINE(5, 6894, 1271) / 2;
	WRITE_LINE(5, 6894) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6894, 1271);
	WRITE_LINE(4, 5621) = Acc;
	Acc = LINE(4, 5621, 3357) / 2 + LINE(3, 2262, 1112) / 2;
	WRITE_LINE(3, 2262) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2262, 1112) + LINE(1, 1145, 1) / 2;
	WRITE_LINE(1, 1145) = Acc;
	Acc = LINE(1, 1145, 0) / 2 + tmp_b;
	WRITE_LINE(8, 13326) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_26(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 13526, 567) * 9 / 8 + LINE(6, 10206, 1891) * 9 / 8 + LINE(4, 6321, 2003) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(8, 13526, 567) * 9 / 8 + LINE(6, 10206, 890) * 9 / 8 + LINE(4, 6321, 671) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 1848, 1) / 2;
	WRITE_LINE(2, 1848) = Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 668) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 668) + LINE(11, 14955, 1035) / 2;
	WRITE_LINE(11, 14955) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14955, 1035) + LINE(10, 13918, 234) / 2;
	WRITE_LINE(10, 13918) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13918, 234) + LINE(9, 13682, 154) / 2;
	WRITE_LINE(9, 13682) = -Acc;
	Acc = Acc * -3 / 4 + LINE(9, 13682, 154) * 3 / 2;
	tmp_b = Acc;
	Acc = LINE(8, 13526, 2224) + LINE(7, 11300, 1092) / 2;
	WRITE_LINE(7, 11300) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11300, 1092);
	WRITE_LINE(6, 10206) = Acc;
	Acc = LINE(6, 10206, 2610) * 3 / 4 + LINE(5, 7594, 1271) / 2;
	WRITE_LINE(5, 7594) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7594, 1271);
	WRITE_LINE(4, 6321) = Acc;
	Acc = LINE(4, 6321, 3357) / 2 + LINE(3, 2962, 1112) / 2;
	WRITE_LINE(3, 2962) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2962, 1112) + LINE(1, 1845, 1) / 2;
	WRITE_LINE(1, 1845) = Acc;
	Acc = LINE(1, 1845, 0) / 2 + tmp_b;
	WRITE_LINE(8, 13526) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_27(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(16, 15922, 420) * 9 / 8 + LINE(15, 14952, 334) * 9 / 8 + LINE(14, 13863, 252) * 9 / 8 + LINE(13, 12452, 478) * 9 / 8 + LINE(8, 8583, 369) * 9 / 8 + LINE(7, 7708, 499) * 9 / 8 + LINE(6, 6472, 323) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(16, 15922, 129) * 9 / 8 + LINE(15, 14952, 130) * 9 / 8 + LINE(14, 13863, 459) * 9 / 8 + LINE(13, 12452, 277) * 9 / 8 + LINE(8, 8583, 363) * 9 / 8 + LINE(7, 7708, 208) * 9 / 8 + LINE(5, 5025, 491) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(21, 16381, 19) * 3 / 4 + LINE(0, 0, 1) / 2;
	WRITE_LINE(21, 16381) = -Acc;
	Acc = Acc * -3 / 4 + LINE(20, 16360, 45) * 3 / 4 + LINE(21, 16381, 19);
	WRITE_LINE(20, 16360) = -Acc;
	Acc = Acc * -3 / 4 + LINE(19, 16313, 84) * 3 / 4 + LINE(20, 16360, 45);
	WRITE_LINE(19, 16313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(18, 16227, 125) * 3 / 4 + LINE(19, 16313, 84);
	WRITE_LINE(18, 16227) = -Acc;
	Acc = Acc * -3 / 4 + LINE(17, 16100, 176) * 3 / 4 + LINE(18, 16227, 125);
	WRITE_LINE(17, 16100) = -Acc;
	Acc = Acc * -3 / 4 + LINE(17, 16100, 176);
	tmp_b = Acc;
	Acc = LINE(16, 15922, 968) + LINE(12, 11046, 1056) / 2;
	WRITE_LINE(12, 11046) = -Acc;
	Acc = -Acc / 2 + LINE(12, 11046, 1056);
	WRITE_LINE(15, 14952) = Acc;
	Acc = LINE(15, 14952, 1087) / 2 + LINE(15, 14952, 1088) / 2 + LINE(11, 9988, 612) / 2;
	WRITE_LINE(11, 9988) = -Acc;
	Acc = -Acc / 2 + LINE(11, 9988, 612);
	WRITE_LINE(14, 13863) = Acc;
	Acc = LINE(14, 13863, 1409) * 3 / 4 + LINE(10, 9374, 356) / 2;
	WRITE_LINE(10, 9374) = -Acc;
	Acc = -Acc / 2 + LINE(10, 9374, 356);
	WRITE_LINE(13, 12452) = Acc;
	Acc = LINE(13, 12452, 1404) * 3 / 4 + LINE(9, 9016, 431) / 2;
	WRITE_LINE(9, 9016) = -Acc;
	Acc = -Acc / 2 + LINE(9, 9016, 431) + tmp_b;
	WRITE_LINE(16, 15922) = Acc;
	Acc = LINE(8, 8583, 873) + LINE(4, 3413, 987) / 2;
	WRITE_LINE(4, 3413) = -Acc;
	Acc = -Acc / 2 + LINE(4, 3413, 987);
	WRITE_LINE(7, 7708) = Acc;
	Acc = LINE(7, 7708, 1235) / 2 + LINE(3, 2424, 681) / 2;
	WRITE_LINE(3, 2424) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2424, 681);
	WRITE_LINE(6, 6472) = Acc;
	*out_left = tmp_5;
	Acc = LINE(6, 6472, 1445) * 3 / 4 + LINE(2, 1741, 634) / 2;
	WRITE_LINE(2, 1741) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1741, 634);
	WRITE_LINE(5, 5025) = Acc;
	Acc = LINE(5, 5025, 1610) * 3 / 4 + LINE(1, 1105, 432) / 2;
	WRITE_LINE(1, 1105) = -Acc;
	Acc = -Acc / 2 + LINE(1, 1105, 432) + tmp_b;
	WRITE_LINE(8, 8583) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_28(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(7, 13341, 21) * 9 / 8 + LINE(5, 9321, 1891) * 9 / 8 + LINE(3, 5236, 2003) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(7, 13341, 1010) * 9 / 8 + LINE(5, 9321, 890) * 9 / 8 + LINE(3, 5236, 671) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(15, 16381, 321) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(15, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(15, 16381, 321) + LINE(14, 16058, 431) / 2;
	WRITE_LINE(14, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16058, 431) + LINE(13, 15625, 968) / 2;
	WRITE_LINE(13, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(13, 15625, 968) + LINE(8, 14363, 1020) / 2;
	WRITE_LINE(8, 14363) = -Acc;
	Acc = -Acc / 2 + LINE(8, 14363, 1020) + LINE(12, 14655, 23) / 2;
	WRITE_LINE(12, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(12, 14655, 23) + LINE(11, 14630, 56) / 2;
	WRITE_LINE(11, 14630) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14630, 56) + LINE(10, 14572, 78) / 2;
	WRITE_LINE(10, 14572) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14572, 78) + LINE(9, 14492, 127) / 2;
	WRITE_LINE(9, 14492) = -Acc;
	Acc = -Acc / 2 + LINE(9, 14492, 127);
	tmp_b = Acc;
	Acc = LINE(7, 13341, 2624) / 2 + LINE(7, 13341, 2625) / 2 + LINE(6, 10715, 1392) / 2;
	WRITE_LINE(6, 10715) = -Acc;
	Acc = -Acc / 2 + LINE(6, 10715, 1392);
	WRITE_LINE(5, 9321) = Acc;
	Acc = LINE(5, 9321, 2810) * 15 / 16 + LINE(4, 6509, 1271) / 2;
	WRITE_LINE(4, 6509) = -Acc;
	Acc = -Acc / 2 + LINE(4, 6509, 1271);
	WRITE_LINE(3, 5236) = Acc;
	Acc = LINE(3, 5236, 3857) * 3 / 4 + LINE(2, 1377, 1112) / 2;
	WRITE_LINE(2, 1377) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1377, 1112) + LINE(1, 260, 1) / 2;
	WRITE_LINE(1, 260) = Acc;
	Acc = LINE(1, 260, 0) / 2 + tmp_b;
	WRITE_LINE(7, 13341) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_29(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(7, 12741, 21) * 9 / 8 + LINE(5, 9121, 1891) * 9 / 8 + LINE(3, 4636, 2003) * 9 / 8;
	tmp_3 = Acc;
	Acc = LINE(7, 12741, 1010) * 9 / 8 + LINE(5, 9121, 890) * 9 / 8 + LINE(3, 4636, 671) * 9 / 8;
	tmp_5 = Acc;
	Acc = LINE(15, 16381, 321) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(15, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(15, 16381, 321) + LINE(14, 16058, 431) / 2;
	WRITE_LINE(14, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16058, 431) + LINE(13, 15625, 968) / 2;
	WRITE_LINE(13, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(13, 15625, 968) + LINE(8, 14363, 1620) / 2;
	WRITE_LINE(8, 14363) = -Acc;
	Acc = -Acc / 2 + LINE(8, 14363, 1620) + LINE(12, 14655, 23) / 2;
	WRITE_LINE(12, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(12, 14655, 23) + LINE(11, 14630, 56) / 2;
	WRITE_LINE(11, 14630) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14630, 56) + LINE(10, 14572, 78) / 2;
	WRITE_LINE(10, 14572) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14572, 78) + LINE(9, 14492, 127) / 2;
	WRITE_LINE(9, 14492) = -Acc;
	Acc = -Acc / 2 + LINE(9, 14492, 127);
	tmp_b = Acc;
	Acc = LINE(7, 12741, 1624) / 2 + LINE(7, 12741, 1625) / 2 + LINE(6, 11115, 1992) / 2;
	WRITE_LINE(6, 11115) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11115, 1992);
	WRITE_LINE(5, 9121) = Acc;
	Acc = LINE(5, 9121, 2110) * 15 / 16 + LINE(4, 7009, 2371) / 2;
	WRITE_LINE(4, 7009) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7009, 2371);
	WRITE_LINE(3, 4636) = Acc;
	Acc = LINE(3, 4636, 2157) * 15 / 16 + LINE(2, 2477, 2212) / 2;
	WRITE_LINE(2, 2477) = -Acc;
	Acc = -Acc / 2 + LINE(2, 2477, 2212) + LINE(1, 260, 1) / 2;
	WRITE_LINE(1, 260) = Acc;
	Acc = LINE(1, 260, 0) / 2 + tmp_b;
	WRITE_LINE(7, 12741) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_30(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5, tmp_b, tmp_15;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 6109, 5) / 2 + LINE(6, 5375, 361) / 2 + LINE(4, 4072, 120) / 2 + LINE(2, 3222, 861) / 2;
	tmp_3 = Acc;
	Acc = LINE(8, 6109, 126) / 2 + LINE(6, 5375, 897) / 2 + LINE(4, 4072, 1) / 2 + LINE(2, 3222, 356) / 2;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 0) / 2 + LINE(0, 0, 245) / 2 + LINE(0, 0, 523) / 2 + LINE(0, 0, 891) / 2 + LINE(0, 0, 1200) / 2 + LINE(0, 0, 1568) / 2 + LINE(0, 0, 1987) / 2 + LINE(0, 0, 2567) / 2 + LINE(0, 0, 2893) / 2 + LINE(0, 0, 3104) / 2;
	tmp_b = -Acc;
	Acc = -Acc / 8 + LINE(17, 7382, 245) * 5 / 8 + tmp_b / 2;
	WRITE_LINE(17, 7382) = -Acc;
	Acc = -Acc / 8 + LINE(16, 7135, 189) * 5 / 8 + LINE(17, 7382, 0) / 2 + LINE(17, 7382, 245);
	WRITE_LINE(16, 7135) = -Acc;
	Acc = -Acc / 8 + LINE(15, 6944, 145) * 5 / 8 + LINE(16, 7135, 0) / 2 + LINE(16, 7135, 189);
	WRITE_LINE(15, 6944) = -Acc;
	Acc = -Acc / 8 + LINE(14, 6797, 123) * 5 / 8 + LINE(15, 6944, 0) / 2 + LINE(15, 6944, 145);
	WRITE_LINE(14, 6797) = -Acc;
	Acc = -Acc / 8 + LINE(13, 6672, 198) * 5 / 8 + LINE(14, 6797, 0) / 2 + LINE(14, 6797, 123);
	WRITE_LINE(13, 6672) = -Acc;
	Acc = -Acc / 8 + LINE(13, 6672, 0) / 2 + LINE(13, 6672, 198) + LINE(12, 6472, 34) / 2;
	WRITE_LINE(12, 6472) = -Acc;
	Acc = -Acc / 2 + LINE(12, 6472, 34) + LINE(11, 6436, 69) / 2;
	WRITE_LINE(11, 6436) = -Acc;
	Acc = -Acc / 2 + LINE(11, 6436, 69) + LINE(10, 6365, 104) / 2;
	WRITE_LINE(10, 6365) = -Acc;
	Acc = -Acc / 2 + LINE(10, 6365, 104) + LINE(9, 6259, 148) / 2;
	WRITE_LINE(9, 6259) = -Acc;
	Acc = -Acc / 2 + LINE(9, 6259, 148);
	tmp_15 = -Acc;
	Acc = LINE(8, 6109, 497) / 2 + LINE(7, 5610, 233) / 2;
	WRITE_LINE(7, 5610) = -Acc;
	Acc = -Acc / 2 + LINE(7, 5610, 233);
	WRITE_LINE(6, 5375) = Acc;
	Acc = LINE(6, 5375, 1010) * 3 / 4 + LINE(5, 4363, 289) / 2;
	WRITE_LINE(5, 4363) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + LINE(5, 4363, 289) + tmp_15;
	WRITE_LINE(4, 4072) = -Acc;
	Acc = LINE(4, 4072, 590) / 2 + LINE(3, 3480, 256) / 2;
	WRITE_LINE(3, 3480) = -Acc;
	Acc = -Acc / 2 + LINE(3, 3480, 256);
	WRITE_LINE(2, 3222) = Acc;
	Acc = LINE(2, 3222, 1071) * 3 / 4 + LINE(1, 2149, 225) / 2;
	WRITE_LINE(1, 2149) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + LINE(1, 2149, 225) + tmp_15;
	WRITE_LINE(8, 6109) = -Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_31(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5, tmp_b, tmp_15;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 6109, 123) / 2 + LINE(6, 4749, 361) / 2 + LINE(4, 3446, 205) / 2 + LINE(2, 2196, 861) / 2;
	tmp_3 = Acc;
	Acc = LINE(8, 6109, 126) / 2 + LINE(6, 4749, 897) / 2 + LINE(4, 3446, 202) / 2 + LINE(2, 2196, 356) / 2;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 0) / 2 + LINE(0, 0, 245) / 2 + LINE(0, 0, 891) / 2 + LINE(0, 0, 1568) / 2 + LINE(0, 0, 1987) / 2 + LINE(0, 0, 2746) / 2 + LINE(0, 0, 3245) / 2;
	tmp_b = -Acc;
	Acc = -Acc / 8 + LINE(17, 7382, 245) * 5 / 8 + tmp_b / 2;
	WRITE_LINE(17, 7382) = -Acc;
	Acc = -Acc / 8 + LINE(16, 7135, 189) * 5 / 8 + LINE(17, 7382, 0) / 2 + LINE(17, 7382, 245);
	WRITE_LINE(16, 7135) = -Acc;
	Acc = -Acc / 8 + LINE(15, 6944, 145) * 5 / 8 + LINE(16, 7135, 0) / 2 + LINE(16, 7135, 189);
	WRITE_LINE(15, 6944) = -Acc;
	Acc = -Acc / 8 + LINE(14, 6797, 123) * 5 / 8 + LINE(15, 6944, 0) / 2 + LINE(15, 6944, 145);
	WRITE_LINE(14, 6797) = -Acc;
	Acc = -Acc / 8 + LINE(13, 6672, 198) * 5 / 8 + LINE(14, 6797, 0) / 2 + LINE(14, 6797, 123);
	WRITE_LINE(13, 6672) = -Acc;
	Acc = -Acc / 8 + LINE(13, 6672, 0) / 2 + LINE(13, 6672, 198) + LINE(12, 6472, 34) / 2;
	WRITE_LINE(12, 6472) = -Acc;
	Acc = -Acc / 2 + LINE(12, 6472, 34) + LINE(11, 6436, 69) / 2;
	WRITE_LINE(11, 6436) = -Acc;
	Acc = -Acc / 2 + LINE(11, 6436, 69) + LINE(10, 6365, 104) / 2;
	WRITE_LINE(10, 6365) = -Acc;
	Acc = -Acc / 2 + LINE(10, 6365, 104) + LINE(9, 6259, 148) / 2;
	WRITE_LINE(9, 6259) = -Acc;
	Acc = -Acc / 2 + LINE(9, 6259, 148);
	tmp_15 = -Acc;
	Acc = LINE(8, 6109, 1123) * 3 / 4 + LINE(7, 4984, 233) / 2;
	WRITE_LINE(7, 4984) = -Acc;
	Acc = -Acc / 2 + LINE(7, 4984, 233);
	WRITE_LINE(6, 4749) = Acc;
	Acc = -LINE(6, 4749, 1010) / 4 + -LINE(6, 4749, 1011) / 4 + LINE(5, 3737, 289) / 2;
	WRITE_LINE(5, 3737) = -Acc;
	Acc = -Acc / 2 + LINE(5, 3737, 289) + tmp_15;
	WRITE_LINE(8, 6109) = -Acc;
	*out_left = tmp_5;
	Acc = LINE(4, 3446, 990) * 3 / 4 + LINE(3, 2454, 256) / 2;
	WRITE_LINE(3, 2454) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2454, 256);
	WRITE_LINE(2, 2196) = Acc;
	Acc = -LINE(2, 2196, 1371) / 4 + -LINE(2, 2196, 1372) / 4 + LINE(1, 823, 225) / 2;
	WRITE_LINE(1, 823) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + LINE(1, 823, 225) + tmp_15;
	WRITE_LINE(4, 3446) = -Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_32(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5, tmp_b, tmp_15;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 8865, 123) / 2 + LINE(6, 7228, 361) / 2 + LINE(4, 5925, 505) / 2 + LINE(2, 4645, 861) / 2;
	tmp_3 = Acc;
	Acc = LINE(8, 8865, 626) / 2 + LINE(6, 7228, 897) / 2 + LINE(4, 5925, 56) / 2 + LINE(2, 4645, 756) / 2;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 1000) / 2 + LINE(0, 0, 999) / 2;
	WRITE_LINE(18, 15384) = Acc;
	Acc = LINE(18, 15384, 4423) / 2 + LINE(18, 15384, 3987) / 2 + LINE(18, 15384, 3231) / 2 + LINE(18, 15384, 2889) / 2 + LINE(18, 15384, 2221) / 2 + LINE(18, 15384, 1746) / 2 + LINE(18, 15384, 1341) / 2 + LINE(18, 15384, 923) / 2 + LINE(18, 15384, 523) / 2 + LINE(18, 15384, 109) / 2 + LINE(0, 0, 876) / 2 + LINE(0, 0, 435) / 2 + LINE(0, 0, 235) / 2 + LINE(0, 0, 0) / 2;
	tmp_b = -Acc;
	Acc = -Acc / 8 + LINE(17, 10382, 245) * 5 / 8 + tmp_b / 2;
	WRITE_LINE(17, 10382) = -Acc;
	Acc = -Acc / 8 + LINE(16, 10135, 189) * 5 / 8 + LINE(17, 10382, 0) / 2 + LINE(17, 10382, 245);
	WRITE_LINE(16, 10135) = -Acc;
	Acc = -Acc / 8 + LINE(15, 9944, 189) * 5 / 8 + LINE(16, 10135, 0) / 2 + LINE(16, 10135, 189);
	WRITE_LINE(15, 9944) = -Acc;
	Acc = -Acc / 8 + LINE(14, 9753, 223) * 5 / 8 + LINE(15, 9944, 0) / 2 + LINE(15, 9944, 189);
	WRITE_LINE(14, 9753) = -Acc;
	Acc = -Acc / 8 + LINE(13, 9528, 298) * 5 / 8 + LINE(14, 9753, 0) / 2 + LINE(14, 9753, 223);
	WRITE_LINE(13, 9528) = -Acc;
	Acc = -Acc / 8 + LINE(13, 9528, 0) / 2 + LINE(13, 9528, 298) + LINE(12, 9228, 34) / 2;
	WRITE_LINE(12, 9228) = -Acc;
	Acc = -Acc / 2 + LINE(12, 9228, 34) + LINE(11, 9192, 69) / 2;
	WRITE_LINE(11, 9192) = -Acc;
	Acc = -Acc / 2 + LINE(11, 9192, 69) + LINE(10, 9121, 104) / 2;
	WRITE_LINE(10, 9121) = -Acc;
	Acc = -Acc / 2 + LINE(10, 9121, 104) + LINE(9, 9015, 148) / 2;
	WRITE_LINE(9, 9015) = -Acc;
	Acc = -Acc / 2 + LINE(9, 9015, 148);
	tmp_15 = -Acc;
	Acc = LINE(8, 8865, 1310) / 2 + LINE(7, 7553, 323) / 2;
	WRITE_LINE(7, 7553) = -Acc;
	Acc = -Acc / 2 + LINE(7, 7553, 323);
	WRITE_LINE(6, 7228) = Acc;
	*out_left = tmp_5;
	Acc = LINE(6, 7228, 1010) / 2 + LINE(5, 6216, 289) / 2;
	WRITE_LINE(5, 6216) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6216, 289) + tmp_15;
	WRITE_LINE(4, 5925) = -Acc;
	Acc = LINE(4, 5925, 1020) / 2;
	WRITE_LINE(3, 4903) = -Acc;
	Acc = -Acc / 2 + LINE(3, 4903, 256);
	WRITE_LINE(2, 4645) = Acc;
	Acc = LINE(2, 4645, 1071) / 2 + LINE(1, 3572, 125) / 2;
	WRITE_LINE(1, 3572) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + LINE(1, 3572, 125) + tmp_15;
	WRITE_LINE(8, 8865) = -Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_33(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5, tmp_b, tmp_15;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 6259, 123) / 2 + LINE(8, 4899, 361) / 2 + LINE(6, 3596, 205) / 2 + LINE(4, 2346, 861) / 2;
	tmp_3 = Acc;
	Acc = LINE(10, 6259, 126) / 2 + LINE(8, 4899, 897) / 2 + LINE(6, 3596, 202) / 2 + LINE(4, 2346, 356) / 2;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 0) / 2 + LINE(0, 0, 245) / 2 + LINE(0, 0, 891) / 2 + LINE(0, 0, 1568) / 2 + LINE(0, 0, 1987) / 2 + LINE(0, 0, 2746) / 2 + LINE(0, 0, 3245) / 2 + LINE(0, 0, 3678) / 2 + LINE(0, 0, 4232) / 2 + LINE(0, 0, 4980) / 2 + LINE(0, 0, 5123) / 2 + LINE(0, 0, 5765) / 2 + LINE(0, 0, 6345) / 2 + LINE(0, 0, 7045) / 2 + LINE(0, 0, 7589) / 2 + LINE(0, 0, 8245) / 2 + LINE(0, 0, 8531) / 2 + LINE(0, 0, 8921) / 2;
	tmp_b = -Acc;
	Acc = -Acc / 8 + LINE(18, 7382, 245) * 5 / 8 + tmp_b / 2;
	WRITE_LINE(18, 7382) = -Acc;
	Acc = -Acc / 8 + LINE(17, 7135, 189) * 5 / 8 + LINE(18, 7382, 0) / 2 + LINE(18, 7382, 245);
	WRITE_LINE(17, 7135) = -Acc;
	Acc = -Acc / 8 + LINE(16, 6944, 145) * 5 / 8 + LINE(17, 7135, 0) / 2 + LINE(17, 7135, 189);
	WRITE_LINE(16, 6944) = -Acc;
	Acc = -Acc / 8 + LINE(15, 6797, 123) * 5 / 8 + LINE(16, 6944, 0) / 2 + LINE(16, 6944, 145);
	WRITE_LINE(15, 6797) = -Acc;
	Acc = -Acc / 8 + LINE(14, 6672, 198) * 5 / 8 + LINE(15, 6797, 0) / 2 + LINE(15, 6797, 123);
	WRITE_LINE(14, 6672) = -Acc;
	Acc = -Acc / 8 + LINE(14, 6672, 0) / 2 + LINE(14, 6672, 198) + LINE(13, 6472, 34) / 2;
	WRITE_LINE(13, 6472) = -Acc;
	Acc = -Acc / 2 + LINE(13, 6472, 34) + LINE(12, 6436, 69) / 2;
	WRITE_LINE(12, 6436) = -Acc;
	Acc = -Acc / 2 + LINE(12, 6436, 69) + LINE(11, 6365, 104) / 2;
	WRITE_LINE(11, 6365) = -Acc;
	Acc = -Acc / 2 + LINE(11, 6365, 104);
	tmp_15 = -Acc;
	Acc = LINE(10, 6259, 1123) / 2 + LINE(9, 5134, 233) / 2;
	WRITE_LINE(9, 5134) = -Acc;
	Acc = -Acc / 2 + LINE(9, 5134, 233);
	WRITE_LINE(8, 4899) = Acc;
	Acc = LINE(8, 4899, 1010) / 2 + LINE(7, 3887, 289) / 2;
	WRITE_LINE(7, 3887) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + LINE(7, 3887, 289) + LINE(2, 746, 1) / 2;
	WRITE_LINE(2, 746) = Acc;
	Acc = Acc * -3 / 4 + tmp_15;
	WRITE_LINE(10, 6259) = -Acc;
	Acc = LINE(6, 3596, 990) / 2 + LINE(5, 2604, 256) / 2;
	WRITE_LINE(5, 2604) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2604, 256);
	WRITE_LINE(4, 2346) = Acc;
	*out_right = tmp_3;
	Acc = LINE(4, 2346, 1371) / 2 + LINE(3, 973, 225) / 2;
	WRITE_LINE(3, 973) = -Acc;
	Acc = -Acc / 2 + LINE(3, 973, 225) + LINE(1, 743, 1) / 2;
	WRITE_LINE(1, 743) = Acc;
	Acc = Acc * -3 / 4 + tmp_15;
	WRITE_LINE(6, 3596) = -Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_34(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5, tmp_b, tmp_15;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 6109, 123) / 2 + LINE(6, 4749, 361) / 2 + LINE(4, 3446, 205) / 2 + LINE(2, 2196, 861) / 2;
	tmp_3 = Acc;
	Acc = LINE(8, 6109, 126) / 2 + LINE(6, 4749, 897) / 2 + LINE(4, 3446, 202) / 2 + LINE(2, 2196, 356) / 2;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 0) / 2 + LINE(0, 0, 245) / 2 + LINE(0, 0, 891) / 2 + LINE(0, 0, 1568) / 2 + LINE(0, 0, 1987) / 2 + LINE(0, 0, 2746) / 2 + LINE(0, 0, 3245) / 2 + LINE(0, 0, 3678) / 2 + LINE(0, 0, 4232) / 2 + LINE(0, 0, 4980) / 2 + LINE(0, 0, 5123) / 2 + LINE(0, 0, 5765) / 2 + LINE(0, 0, 6345) / 2 + LINE(0, 0, 7045) / 2 + LINE(0, 0, 7589) / 2 + LINE(0, 0, 8245) / 2 + LINE(0, 0, 8531) / 2 + LINE(0, 0, 8921) / 2;
	tmp_b = -Acc;
	Acc = -Acc / 8 + LINE(17, 7382, 245) * 5 / 8 + tmp_b / 2;
	WRITE_LINE(17, 7382) = -Acc;
	Acc = -Acc / 8 + LINE(16, 7135, 189) * 5 / 8 + LINE(17, 7382, 0) / 2 + LINE(17, 7382, 245);
	WRITE_LINE(16, 7135) = -Acc;
	Acc = -Acc / 8 + LINE(15, 6944, 145) * 5 / 8 + LINE(16, 7135, 0) / 2 + LINE(16, 7135, 189);
	WRITE_LINE(15, 6944) = -Acc;
	Acc = -Acc / 8 + LINE(14, 6797, 123) * 5 / 8 + LINE(15, 6944, 0) / 2 + LINE(15, 6944, 145);
	WRITE_LINE(14, 6797) = -Acc;
	Acc = -Acc / 8 + LINE(13, 6672, 198) * 5 / 8 + LINE(14, 6797, 0) / 2 + LINE(14, 6797, 123);
	WRITE_LINE(13, 6672) = -Acc;
	Acc = -Acc / 8 + LINE(13, 6672, 0) / 2 + LINE(13, 6672, 198) + LINE(12, 6472, 34) / 2;
	WRITE_LINE(12, 6472) = -Acc;
	Acc = -Acc / 2 + LINE(12, 6472, 34) + LINE(11, 6436, 69) / 2;
	WRITE_LINE(11, 6436) = -Acc;
	Acc = -Acc / 2 + LINE(11, 6436, 69) + LINE(10, 6365, 104) / 2;
	WRITE_LINE(10, 6365) = -Acc;
	Acc = -Acc / 2 + LINE(10, 6365, 104) + LINE(9, 6259, 148) / 2;
	WRITE_LINE(9, 6259) = -Acc;
	Acc = -Acc / 2 + LINE(9, 6259, 148);
	tmp_15 = -Acc;
	Acc = LINE(8, 6109, 1123) * 3 / 4 + LINE(7, 4984, 233) / 2;
	WRITE_LINE(7, 4984) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + LINE(7, 4984, 233);
	WRITE_LINE(6, 4749) = Acc;
	Acc = -LINE(6, 4749, 1010) / 4 + -LINE(6, 4749, 1011) / 4 + LINE(5, 3737, 289) / 2;
	WRITE_LINE(5, 3737) = -Acc;
	Acc = -Acc / 2 + LINE(5, 3737, 289) + tmp_15;
	WRITE_LINE(4, 3446) = -Acc;
	Acc = LINE(4, 3446, 990) * 3 / 4 + LINE(3, 2454, 256) / 2;
	WRITE_LINE(3, 2454) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + LINE(3, 2454, 256);
	WRITE_LINE(2, 2196) = Acc;
	Acc = -LINE(2, 2196, 1371) / 4 + -LINE(2, 2196, 1372) / 4 + LINE(1, 823, 225) / 2;
	WRITE_LINE(1, 823) = -Acc;
	Acc = -Acc / 2 + LINE(1, 823, 225) + tmp_15;
	WRITE_LINE(8, 6109) = -Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_35(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) + LINE(9, 2298, 31) / 2;
	WRITE_LINE(9, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(9, 2298, 31) + LINE(8, 2265, 153) / 2;
	WRITE_LINE(8, 2265) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2265, 153) + LINE(7, 2110, 273) / 2;
	WRITE_LINE(7, 2110) = -Acc;
	Acc = Acc * -9 / 8 + LINE(7, 2110, 273) * 9 / 4;
	tmp_3 = -Acc;
	Acc = LINE(1, 11, 2) + LINE(6, 1835, 42) / 2;
	WRITE_LINE(6, 1835) = -Acc;
	Acc = -Acc / 2 + LINE(6, 1835, 42) + LINE(5, 1791, 181) / 2;
	WRITE_LINE(5, 1791) = -Acc;
	Acc = -Acc / 2 + LINE(5, 1791, 181) + LINE(4, 1608, 233) / 2;
	WRITE_LINE(4, 1608) = -Acc;
	Acc = Acc * -9 / 8 + LINE(4, 1608, 233) * 9 / 4;
	tmp_5 = -Acc;
	Acc = LINE(0, 0, 0) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(0, 0) = Acc;
	Acc = LINE(0, 0, 10) * -3 / 8;
	WRITE_LINE(11, 16373) = -Acc;
	Acc = LINE(11, 16373, 220) / 2 + LINE(11, 16373, 401) / 2 + LINE(11, 16373, 523) / 2 + LINE(11, 16373, 750) / 2 + LINE(11, 16373, 864) / 2 + LINE(10, 15383, 64) / 2 + LINE(10, 15383, 118) / 2 + LINE(10, 15383, 232) / 2 + LINE(10, 15383, 433) / 2 + LINE(10, 15383, 554) / 2 + LINE(10, 15383, 741) / 2 + LINE(10, 15383, 861) / 2 + LINE(10, 15383, 1045) / 2 + LINE(10, 15383, 1148) / 2 + LINE(10, 15383, 1255) / 2 + LINE(10, 15383, 1442) / 2 + LINE(10, 15383, 1578) / 2 + LINE(10, 15383, 1720) / 2 + LINE(10, 15383, 1872) / 2 + LINE(10, 15383, 2035) / 2 + LINE(10, 15383, 2120) / 2 + LINE(10, 15383, 2266) / 2 + LINE(10, 15383, 2450) / 2 + LINE(10, 15383, 2568) / 2 + LINE(10, 15383, 2724) / 2 + LINE(10, 15383, 2888) / 2 + LINE(10, 15383, 3033) / 2 + LINE(10, 15383, 3151) / 2 + LINE(10, 15383, 3256) / 2 + LINE(10, 15383, 3491) / 2 + LINE(10, 15383, 3555) / 2;
	WRITE_LINE(1, 11) = -Acc;
	*out_left = tmp_5;
	Acc = -LINE(10, 15383, 8094) / 16 + -LINE(10, 15383, 7848) / 16 + -LINE(10, 15383, 7792) / 16 + -LINE(10, 15383, 7514) / 16 + -LINE(10, 15383, 7461) / 16 + -LINE(10, 15383, 7378) / 16 + -LINE(10, 15383, 7138) / 16 + -LINE(10, 15383, 7091) / 16 + LINE(10, 15383, 6864) / 8 + LINE(10, 15383, 6726) / 8 + LINE(10, 15383, 6656) / 8 + LINE(10, 15383, 6418) / 8 + LINE(10, 15383, 6363) / 8 + LINE(10, 15383, 6153) / 8 + LINE(10, 15383, 6017) / 8 + LINE(10, 15383, 5966) / 8 + -LINE(10, 15383, 5727) / 4 + -LINE(10, 15383, 5656) / 4 + -LINE(10, 15383, 5494) / 4 + -LINE(10, 15383, 5318) / 4 + -LINE(10, 15383, 5260) / 4 + -LINE(10, 15383, 5018) / 4 + -LINE(10, 15383, 4957) / 4 + -LINE(10, 15383, 4733) / 4 + LINE(10, 15383, 4626) / 2 + LINE(10, 15383, 4550) / 2 + LINE(10, 15383, 4338) / 2 + LINE(10, 15383, 4209) / 2 + LINE(10, 15383, 4045) / 2 + LINE(10, 15383, 3920) / 2 + LINE(10, 15383, 3799) / 2 + LINE(10, 15383, 3618) / 2 + LINE(3, 1373, 1) / 2;
	WRITE_LINE(3, 1373) = Acc;
	*out_right = tmp_3;
	Acc = -LINE(3, 1373, 1) / 4 + LINE(1, 11, 0);
	WRITE_LINE(1, 11) = -Acc;
	Acc = LINE(11, 16373, 989) / 2 + LINE(2, 1370, 1) / 2;
	WRITE_LINE(2, 1370) = -Acc;
	Acc = LINE(2, 1370, 1);
	WRITE_LINE(10, 15383) = -Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_36(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 1796) = Acc;
	Acc = LINE(1, 1796, 1500);
	WRITE_LINE(10, 16383) = -Acc;
	Acc = LINE(0, 11, 2) / 2 + LINE(7, 2298, 21) / 2;
	WRITE_LINE(7, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2298, 21) + LINE(6, 2275, 53) / 2;
	WRITE_LINE(6, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2275, 53) + LINE(5, 2220, 173) / 2;
	WRITE_LINE(5, 2220) = -Acc;
	Acc = Acc * -3 / 4 + LINE(5, 2220, 173) * 3 / 2;
	tmp_3 = Acc;
	Acc = LINE(0, 11, 2) / 2 + LINE(4, 2045, 32) / 2;
	WRITE_LINE(4, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2045, 32) + LINE(3, 2011, 75) / 2;
	WRITE_LINE(3, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2011, 75) + LINE(2, 1934, 133) / 2;
	WRITE_LINE(2, 1934) = -Acc;
	Acc = Acc * -3 / 4 + LINE(2, 1934, 133) * 3 / 2;
	tmp_5 = Acc;
	Acc = LINE(10, 16383, 4) / 2 + LINE(9, 16379, 1) / 2;
	WRITE_LINE(9, 16379) = Acc;
	Acc = LINE(9, 16379, 5) / 2;
	WRITE_LINE(8, 16373) = Acc;
	Acc = LINE(8, 16373, 152) / 2 + LINE(8, 16373, 222) / 2 + LINE(8, 16373, 401) / 2 + LINE(8, 16373, 523) / 2 + LINE(8, 16373, 750) / 2 + LINE(8, 16373, 864) / 2 + LINE(8, 16373, 1054) / 2 + LINE(8, 16373, 1108) / 2 + LINE(8, 16373, 1222) / 2 + LINE(8, 16373, 1423) / 2 + LINE(8, 16373, 1544) / 2 + LINE(8, 16373, 1731) / 2 + LINE(8, 16373, 1851) / 2 + LINE(8, 16373, 2035) / 2 + LINE(8, 16373, 2138) / 2 + LINE(8, 16373, 2245) / 2 + LINE(8, 16373, 2432) / 2 + LINE(8, 16373, 2568) / 2 + LINE(8, 16373, 2710) / 2 + LINE(8, 16373, 2862) / 2 + LINE(8, 16373, 3025) / 2 + LINE(8, 16373, 3110) / 2 + LINE(8, 16373, 3256) / 2 + LINE(8, 16373, 3440) / 2 + LINE(8, 16373, 3558) / 2;
	WRITE_LINE(0, 11) = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_37(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5;
	tmp_0 = input;
	Acc = LINE(0, 11, 2) + LINE(9, 6298, 31) / 2;
	WRITE_LINE(9, 6298) = -Acc;
	Acc = -Acc / 2 + LINE(9, 6298, 31) + LINE(8, 6265, 153) / 2;
	WRITE_LINE(8, 6265) = -Acc;
	Acc = -Acc / 2 + LINE(8, 6265, 153) + LINE(7, 6110, 273) / 2;
	WRITE_LINE(7, 6110) = -Acc;
	Acc = Acc * -9 / 8 + LINE(7, 6110, 273) * 9 / 4;
	tmp_3 = -Acc;
	Acc = LINE(0, 11, 2) + LINE(6, 5835, 42) / 2;
	WRITE_LINE(6, 5835) = -Acc;
	Acc = -Acc / 2 + LINE(6, 5835, 42) + LINE(5, 5791, 181) / 2;
	WRITE_LINE(5, 5791) = -Acc;
	Acc = -Acc / 2 + LINE(5, 5791, 181) + LINE(4, 5608, 233) / 2;
	WRITE_LINE(4, 5608) = -Acc;
	Acc = Acc * -9 / 8 + LINE(4, 5608, 233) * 9 / 4;
	tmp_5 = -Acc;
	Acc = tmp_0;
	WRITE_LINE(1, 5364) = -Acc;
	Acc = LINE(1, 5364, 1500);
	WRITE_LINE(13, 16382) = -Acc;
	Acc = LINE(13, 16382, 2) / 2 + LINE(12, 16380, 1) / 2;
	WRITE_LINE(12, 16380) = Acc;
	Acc = LINE(12, 16380, 6) * -3 / 8;
	WRITE_LINE(11, 16373) = -Acc;
	Acc = -Acc / 2 + LINE(11, 16373, 523) / 2 + LINE(11, 16373, 750) / 2 + LINE(11, 16373, 864) / 2 + LINE(10, 15383, 64) / 2 + LINE(10, 15383, 118) / 2 + LINE(10, 15383, 232) / 2 + LINE(10, 15383, 433) / 2 + LINE(10, 15383, 554) / 2 + LINE(10, 15383, 741) / 2 + LINE(10, 15383, 861) / 2 + LINE(10, 15383, 1045) / 2 + LINE(10, 15383, 1148) / 2 + LINE(10, 15383, 1255) / 2 + LINE(10, 15383, 1442) / 2 + LINE(10, 15383, 1578) / 2 + LINE(10, 15383, 1720) / 2 + LINE(10, 15383, 1872) / 2 + LINE(10, 15383, 2035) / 2 + LINE(10, 15383, 2120) / 2 + LINE(10, 15383, 2266) / 2 + LINE(10, 15383, 2450) / 2 + LINE(10, 15383, 2568) / 2 + LINE(10, 15383, 2724) / 2 + LINE(10, 15383, 2888) / 2 + LINE(10, 15383, 3033) / 2 + LINE(10, 15383, 3151) / 2 + LINE(10, 15383, 3256) / 2 + LINE(10, 15383, 3491) / 2 + LINE(10, 15383, 3555) / 2;
	WRITE_LINE(0, 11) = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
	Acc = -LINE(10, 15383, 8094) / 16 + -LINE(10, 15383, 7848) / 16 + -LINE(10, 15383, 7792) / 16 + -LINE(10, 15383, 7514) / 16 + -LINE(10, 15383, 7461) / 16 + -LINE(10, 15383, 7378) / 16 + -LINE(10, 15383, 7138) / 16 + -LINE(10, 15383, 7091) / 16 + LINE(10, 15383, 6864) / 8 + LINE(10, 15383, 6726) / 8 + LINE(10, 15383, 6656) / 8 + LINE(10, 15383, 6418) / 8 + LINE(10, 15383, 6363) / 8 + LINE(10, 15383, 6153) / 8 + LINE(10, 15383, 6017) / 8 + LINE(10, 15383, 5966) / 8 + -LINE(10, 15383, 5727) / 4 + -LINE(10, 15383, 5656) / 4 + -LINE(10, 15383, 5494) / 4 + -LINE(10, 15383, 5318) / 4 + -LINE(10, 15383, 5260) / 4 + -LINE(10, 15383, 5018) / 4 + -LINE(10, 15383, 4957) / 4 + -LINE(10, 15383, 4733) / 4 + LINE(10, 15383, 4626) / 2 + LINE(10, 15383, 4550) / 2 + LINE(10, 15383, 4338) / 2 + LINE(10, 15383, 4209) / 2 + LINE(10, 15383, 4045) / 2 + LINE(10, 15383, 3920) / 2 + LINE(10, 15383, 3799) / 2 + LINE(10, 15383, 3618) / 2 + LINE(3, 5373, 1) / 2;
	WRITE_LINE(3, 5373) = Acc;
	Acc = -LINE(3, 5373, 1) / 4 + LINE(0, 11, 0);
	WRITE_LINE(0, 11) = -Acc;
	Acc = LINE(11, 16373, 989) / 2 + LINE(2, 5370, 1) / 2;
	WRITE_LINE(2, 5370) = -Acc;
	Acc = LINE(2, 5370, 1);
	WRITE_LINE(10, 15383) = -Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_38(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5;
	tmp_0 = input;
	Acc = LINE(0, 11, 2) / 2 + LINE(6, 2298, 21) / 2;
	WRITE_LINE(6, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2298, 21) + LINE(5, 2275, 53) / 2;
	WRITE_LINE(5, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2275, 53) + LINE(4, 2220, 173) / 2;
	WRITE_LINE(4, 2220) = -Acc;
	Acc = Acc * -3 / 4 + LINE(4, 2220, 173) * 3 / 2;
	tmp_3 = Acc;
	Acc = LINE(0, 11, 2) / 2 + LINE(3, 2045, 32) / 2;
	WRITE_LINE(3, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2045, 32) + LINE(2, 2011, 75) / 2;
	WRITE_LINE(2, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(2, 2011, 75) + LINE(1, 1934, 133) / 2;
	WRITE_LINE(1, 1934) = -Acc;
	Acc = Acc * -3 / 4 + LINE(1, 1934, 133) * 3 / 2;
	tmp_5 = Acc;
	Acc = LINE(8, 16382, 1) * 3 / 4 + tmp_0 / 2;
	WRITE_LINE(8, 16382) = Acc;
	Acc = LINE(8, 16382, 8) / 2;
	WRITE_LINE(7, 16373) = Acc;
	Acc = LINE(7, 16373, 152) / 2 + LINE(7, 16373, 222) / 2 + LINE(7, 16373, 401) / 2 + LINE(7, 16373, 523) / 2 + LINE(7, 16373, 750) / 2 + LINE(7, 16373, 864) / 2 + LINE(7, 16373, 1054) / 2 + LINE(7, 16373, 1108) / 2 + LINE(7, 16373, 1222) / 2 + LINE(7, 16373, 1423) / 2 + LINE(7, 16373, 1544) / 2 + LINE(7, 16373, 1731) / 2 + LINE(7, 16373, 1851) / 2 + LINE(7, 16373, 2035) / 2 + LINE(7, 16373, 2138) / 2 + LINE(7, 16373, 2245) / 2 + LINE(7, 16373, 2432) / 2 + LINE(7, 16373, 2568) / 2 + LINE(7, 16373, 2710) / 2 + LINE(7, 16373, 2862) / 2 + LINE(7, 16373, 3025) / 2 + LINE(7, 16373, 3110) / 2 + LINE(7, 16373, 3256) / 2 + LINE(7, 16373, 3440) / 2 + LINE(7, 16373, 3558) / 2;
	WRITE_LINE(0, 11) = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_39(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5;
	tmp_0 = input;
	Acc = LINE(0, 11, 2) + LINE(8, 2298, 31) / 2;
	WRITE_LINE(8, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2298, 31) + LINE(7, 2265, 153) / 2;
	WRITE_LINE(7, 2265) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2265, 153) + LINE(6, 2110, 273) / 2;
	WRITE_LINE(6, 2110) = -Acc;
	Acc = Acc * -9 / 8 + LINE(6, 2110, 273) * 9 / 4;
	tmp_3 = -Acc;
	Acc = LINE(0, 11, 2) + LINE(5, 1835, 42) / 2;
	WRITE_LINE(5, 1835) = -Acc;
	Acc = -Acc / 2 + LINE(5, 1835, 42) + LINE(4, 1791, 181) / 2;
	WRITE_LINE(4, 1791) = -Acc;
	Acc = -Acc / 2 + LINE(4, 1791, 181) + LINE(3, 1608, 233) / 2;
	WRITE_LINE(3, 1608) = -Acc;
	Acc = Acc * -9 / 8 + LINE(3, 1608, 233) * 9 / 4;
	tmp_5 = -Acc;
	Acc = LINE(11, 16382, 1) * 3 / 4 + tmp_0 / 2;
	WRITE_LINE(11, 16382) = Acc;
	Acc = LINE(11, 16382, 8) * -3 / 8;
	WRITE_LINE(10, 16373) = -Acc;
	Acc = LINE(10, 16373, 220) / 2 + LINE(10, 16373, 401) / 2 + LINE(10, 16373, 523) / 2 + LINE(10, 16373, 750) / 2 + LINE(10, 16373, 864) / 2 + LINE(9, 15383, 64) / 2 + LINE(9, 15383, 118) / 2 + LINE(9, 15383, 232) / 2 + LINE(9, 15383, 433) / 2 + LINE(9, 15383, 554) / 2 + LINE(9, 15383, 741) / 2 + LINE(9, 15383, 861) / 2 + LINE(9, 15383, 1045) / 2 + LINE(9, 15383, 1148) / 2 + LINE(9, 15383, 1255) / 2 + LINE(9, 15383, 1442) / 2 + LINE(9, 15383, 1578) / 2 + LINE(9, 15383, 1720) / 2 + LINE(9, 15383, 1872) / 2 + LINE(9, 15383, 2035) / 2 + LINE(9, 15383, 2120) / 2 + LINE(9, 15383, 2266) / 2 + LINE(9, 15383, 2450) / 2 + LINE(9, 15383, 2568) / 2 + LINE(9, 15383, 2724) / 2 + LINE(9, 15383, 2888) / 2 + LINE(9, 15383, 3033) / 2 + LINE(9, 15383, 3151) / 2 + LINE(9, 15383, 3256) / 2 + LINE(9, 15383, 3491) / 2 + LINE(9, 15383, 3555) / 2;
	WRITE_LINE(0, 11) = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
	Acc = -LINE(9, 15383, 8094) / 16 + -LINE(9, 15383, 7848) / 16 + -LINE(9, 15383, 7792) / 16 + -LINE(9, 15383, 7514) / 16 + -LINE(9, 15383, 7461) / 16 + -LINE(9, 15383, 7378) / 16 + -LINE(9, 15383, 7138) / 16 + -LINE(9, 15383, 7091) / 16 + LINE(9, 15383, 6864) / 8 + LINE(9, 15383, 6726) / 8 + LINE(9, 15383, 6656) / 8 + LINE(9, 15383, 6418) / 8 + LINE(9, 15383, 6363) / 8 + LINE(9, 15383, 6153) / 8 + LINE(9, 15383, 6017) / 8 + LINE(9, 15383, 5966) / 8 + -LINE(9, 15383, 5727) / 4 + -LINE(9, 15383, 5656) / 4 + -LINE(9, 15383, 5494) / 4 + -LINE(9, 15383, 5318) / 4 + -LINE(9, 15383, 5260) / 4 + -LINE(9, 15383, 5018) / 4 + -LINE(9, 15383, 4957) / 4 + -LINE(9, 15383, 4733) / 4 + LINE(9, 15383, 4626) / 2 + LINE(9, 15383, 4550) / 2 + LINE(9, 15383, 4338) / 2 + LINE(9, 15383, 4209) / 2 + LINE(9, 15383, 4045) / 2 + LINE(9, 15383, 3920) / 2 + LINE(9, 15383, 3799) / 2 + LINE(9, 15383, 3618) / 2 + LINE(2, 1373, 1) / 2;
	WRITE_LINE(2, 1373) = Acc;
	Acc = -LINE(2, 1373, 1) / 4 + LINE(0, 11, 0);
	WRITE_LINE(0, 11) = -Acc;
	Acc = LINE(10, 16373, 989) / 2 + LINE(1, 1370, 1) / 2;
	WRITE_LINE(1, 1370) = -Acc;
	Acc = LINE(1, 1370, 1);
	WRITE_LINE(9, 15383) = -Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_40(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5;
	tmp_0 = input;
	Acc = LINE(0, 11, 2) / 2 + LINE(9, 2298, 51) / 2;
	WRITE_LINE(9, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(9, 2298, 51) + LINE(8, 2245, 131) / 2;
	WRITE_LINE(8, 2245) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2245, 131) + LINE(7, 2112, 213) / 2;
	WRITE_LINE(7, 2112) = -Acc;
	Acc = Acc * -9 / 8 + LINE(7, 2112, 213) * 9 / 4 + LINE(10, 16382, 11316) * 9 / 4;
	tmp_3 = -Acc;
	Acc = LINE(0, 11, 2) / 2 + LINE(6, 1897, 62) / 2;
	WRITE_LINE(6, 1897) = -Acc;
	Acc = -Acc / 2 + LINE(6, 1897, 62) + LINE(5, 1833, 105) / 2;
	WRITE_LINE(5, 1833) = -Acc;
	Acc = -Acc / 2 + LINE(5, 1833, 105) + LINE(4, 1726, 189) / 2;
	WRITE_LINE(4, 1726) = -Acc;
	Acc = Acc * -9 / 8 + LINE(4, 1726, 189) * 9 / 4 + LINE(10, 16382, 11316) * 9 / 4;
	tmp_5 = -Acc;
	Acc = tmp_0 / 2;
	WRITE_LINE(10, 16382) = Acc;
	Acc = -LINE(10, 16382, 231) / 16 + -LINE(10, 16382, 410) / 16 + -LINE(10, 16382, 759) / 16 + -LINE(10, 16382, 1063) / 16 + LINE(10, 16382, 1231) / 8 + LINE(10, 16382, 1432) / 8 + LINE(10, 16382, 1740) / 8 + LINE(10, 16382, 1860) / 8 + LINE(10, 16382, 3034) / 8 + LINE(10, 16382, 2147) / 8 + -LINE(10, 16382, 2254) / 4 + -LINE(10, 16382, 2441) / 4 + -LINE(10, 16382, 1553) / 4 + -LINE(10, 16382, 2719) / 4 + -LINE(10, 16382, 2871) / 4 + -LINE(10, 16382, 2044) / 4 + LINE(3, 1535, 1) / 2;
	WRITE_LINE(3, 1535) = Acc;
	Acc = Acc * 3 / 32 + LINE(10, 16382, 3119) / 32 + LINE(10, 16382, 3265) / 32 + LINE(10, 16382, 3449) / 32 + LINE(10, 16382, 3567) / 32 + LINE(10, 16382, 5032) / 32 + LINE(10, 16382, 3887) / 32 + LINE(10, 16382, 4032) / 32 + -LINE(10, 16382, 4725) / 16 + -LINE(10, 16382, 4255) / 16 + -LINE(10, 16382, 4490) / 16 + -LINE(10, 16382, 4554) / 16 + -LINE(10, 16382, 4847) / 16 + -LINE(10, 16382, 3723) / 16 + LINE(10, 16382, 5127) / 8 + LINE(10, 16382, 5233) / 8 + LINE(10, 16382, 5419) / 8 + LINE(10, 16382, 5532) / 8 + LINE(10, 16382, 5757) / 8 + LINE(10, 16382, 6857) / 8 + -LINE(10, 16382, 6033) / 4 + -LINE(10, 16382, 6157) / 4 + -LINE(10, 16382, 6221) / 4 + -LINE(10, 16382, 7124) / 4 + LINE(2, 1532, 1) / 2;
	WRITE_LINE(2, 1532) = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 8 + LINE(10, 16382, 6532) / 8 + LINE(10, 16382, 6780) / 8 + LINE(10, 16382, 5835) / 8 + LINE(10, 16382, 7037) / 8 + LINE(10, 16382, 6444) / 8 + LINE(10, 16382, 7219) / 8 + LINE(10, 16382, 7437) / 8 + -LINE(10, 16382, 7734) / 4 + -LINE(10, 16382, 7889) / 4 + -LINE(10, 16382, 8032) / 4 + -LINE(10, 16382, 9213) / 4 + -LINE(10, 16382, 8445) / 4 + -LINE(10, 16382, 8563) / 4 + -LINE(10, 16382, 9511) / 4 + LINE(1, 1529, 1) / 2;
	WRITE_LINE(1, 1529) = Acc;
	*out_right = tmp_3;
	Acc = Acc * -3 / 4 + -LINE(10, 16382, 8883) / 4 + -LINE(10, 16382, 9010) / 4 + -LINE(10, 16382, 9169) / 4 + -LINE(10, 16382, 8144) / 4 + -LINE(10, 16382, 9447) / 4 + -LINE(10, 16382, 8698) / 4 + -LINE(10, 16382, 9763) / 4 + -LINE(10, 16382, 9865) / 4 + -LINE(10, 16382, 10044) / 4 + -LINE(10, 16382, 10108) / 4 + LINE(10, 16382, 10283) / 2 + LINE(10, 16382, 10426) / 2 + LINE(10, 16382, 10576) / 2 + LINE(10, 16382, 10732) / 2 + LINE(10, 16382, 10813) / 2 + LINE(10, 16382, 11021) / 2 + LINE(10, 16382, 11252) / 2;
	WRITE_LINE(0, 11) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_41(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(7, 2298, 21) / 2;
	WRITE_LINE(7, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2298, 21) + LINE(6, 2275, 53) / 2;
	WRITE_LINE(6, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2275, 53) + LINE(5, 2220, 173) / 2;
	WRITE_LINE(5, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2220, 173) + LINE(0, 0, 14000);
	tmp_3 = Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(4, 2045, 32) / 2;
	WRITE_LINE(4, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2045, 32) + LINE(3, 2011, 75) / 2;
	WRITE_LINE(3, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2011, 75) + LINE(2, 1934, 133) / 2;
	WRITE_LINE(2, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1934, 133) + LINE(0, 0, 14000);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
	Acc = Acc * 3 / 32 + LINE(0, 0, 1065) / 32 + LINE(0, 0, 1119) / 32 + LINE(0, 0, 1233) / 32 + LINE(0, 0, 1434) / 32 + LINE(0, 0, 1555) / 32 + LINE(0, 0, 1742) / 32 + LINE(0, 0, 1862) / 32 + LINE(0, 0, 2046) / 32 + LINE(0, 0, 3569) / 32 + LINE(0, 0, 2256) / 32 + LINE(0, 0, 2443) / 32 + LINE(0, 0, 3121) / 32 + LINE(0, 0, 2721) / 32 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 3036) / 16 + -LINE(0, 0, 2579) / 16 + -LINE(0, 0, 3267) / 16 + -LINE(0, 0, 3451) / 16 + -LINE(0, 0, 2149) / 16 + -LINE(0, 0, 3725) / 16 + -LINE(0, 0, 3889) / 16 + -LINE(0, 0, 4034) / 16 + -LINE(0, 0, 4152) / 16 + -LINE(0, 0, 4257) / 16 + -LINE(0, 0, 4492) / 16 + -LINE(0, 0, 4556) / 16 + -LINE(0, 0, 4727) / 16 + -LINE(0, 0, 4849) / 16 + -LINE(0, 0, 6035) / 16 + -LINE(0, 0, 5129) / 16 + -LINE(0, 0, 5235) / 16 + -LINE(0, 0, 6223) / 16 + -LINE(0, 0, 5534) / 16 + LINE(0, 0, 5759) / 8 + LINE(0, 0, 5837) / 8 + LINE(0, 0, 5034) / 8 + LINE(0, 0, 6159) / 8 + LINE(0, 0, 5421) / 8 + LINE(0, 0, 6446) / 8 + LINE(0, 0, 6534) / 8 + LINE(0, 0, 6782) / 8 + LINE(0, 0, 6859) / 8 + LINE(0, 0, 7039) / 8 + LINE(0, 0, 7126) / 8 + LINE(0, 0, 7221) / 8 + LINE(0, 0, 8565) / 8 + LINE(0, 0, 7534) / 8 + LINE(0, 0, 7736) / 8 + LINE(0, 0, 7891) / 8 + LINE(0, 0, 9215) / 8 + LINE(0, 0, 8146) / 8 + LINE(0, 0, 8278) / 8 + -LINE(0, 0, 8447) / 4 + -LINE(0, 0, 7439) / 4 + -LINE(0, 0, 8700) / 4 + -LINE(0, 0, 8885) / 4 + -LINE(0, 0, 9012) / 4 + -LINE(0, 0, 9171) / 4 + -LINE(0, 0, 8034) / 4 + -LINE(0, 0, 9449) / 4 + -LINE(0, 0, 9513) / 4 + -LINE(0, 0, 9765) / 4 + -LINE(0, 0, 9867) / 4 + -LINE(0, 0, 10046) / 4 + -LINE(0, 0, 10110) / 4 + -LINE(0, 0, 10285) / 4 + -LINE(0, 0, 12074) / 4 + -LINE(0, 0, 10578) / 4 + -LINE(0, 0, 10734) / 4 + -LINE(0, 0, 11715) / 4 + -LINE(0, 0, 11023) / 4 + -LINE(0, 0, 11185) / 4 + LINE(0, 0, 11254) / 2 + LINE(0, 0, 11479) / 2 + LINE(0, 0, 11546) / 2 + LINE(0, 0, 10815) / 2 + LINE(0, 0, 11847) / 2 + LINE(0, 0, 10428) / 2 + LINE(0, 0, 12112) / 2 + LINE(0, 0, 12279) / 2 + LINE(0, 0, 12415) / 2 + LINE(0, 0, 12516) / 2 + LINE(0, 0, 12746) / 2 + LINE(0, 0, 12815) / 2 + LINE(0, 0, 13046) / 2 + LINE(0, 0, 13217) / 2 + LINE(0, 0, 13378) / 2 + LINE(0, 0, 13534) / 2;
	WRITE_LINE(1, 11) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_42(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(7, 2298, 21) / 2;
	WRITE_LINE(7, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2298, 21) + LINE(6, 2275, 53) / 2;
	WRITE_LINE(6, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2275, 53) + LINE(5, 2220, 173) / 2;
	WRITE_LINE(5, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2220, 173) + LINE(0, 0, 11718);
	tmp_3 = Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(4, 2045, 32) / 2;
	WRITE_LINE(4, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2045, 32) + LINE(3, 2011, 75) / 2;
	WRITE_LINE(3, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2011, 75) + LINE(2, 1934, 133) / 2;
	WRITE_LINE(2, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1934, 133) + LINE(0, 0, 11718);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
	Acc = LINE(0, 0, 163) / 32 + LINE(0, 0, 233) / 32 + LINE(0, 0, 412) / 32 + LINE(0, 0, 534) / 32 + LINE(0, 0, 761) / 32 + LINE(0, 0, 875) / 32 + LINE(0, 0, 1065) / 32 + LINE(0, 0, 1119) / 32 + LINE(0, 0, 1233) / 32 + LINE(0, 0, 1434) / 32 + LINE(0, 0, 2579) / 32 + LINE(0, 0, 1742) / 32 + LINE(0, 0, 1862) / 32 + LINE(0, 0, 3036) / 32 + LINE(0, 0, 2149) / 32 + -LINE(0, 0, 2256) / 16 + -LINE(0, 0, 2443) / 16 + -LINE(0, 0, 1555) / 16 + -LINE(0, 0, 2721) / 16 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 2046) / 16 + -LINE(0, 0, 3121) / 16 + -LINE(0, 0, 3267) / 16 + -LINE(0, 0, 3451) / 16 + -LINE(0, 0, 3569) / 16 + -LINE(0, 0, 5034) / 16 + -LINE(0, 0, 3889) / 16 + -LINE(0, 0, 4034) / 16 + -LINE(0, 0, 4727) / 16 + -LINE(0, 0, 4257) / 16 + LINE(0, 0, 4492) / 8 + LINE(0, 0, 4556) / 8 + LINE(0, 0, 4152) / 8 + LINE(0, 0, 4849) / 8 + LINE(0, 0, 3725) / 8 + LINE(0, 0, 5129) / 8 + LINE(0, 0, 5235) / 8 + LINE(0, 0, 5421) / 8 + LINE(0, 0, 5534) / 8 + LINE(0, 0, 5759) / 8 + LINE(0, 0, 6859) / 8 + LINE(0, 0, 6035) / 8 + LINE(0, 0, 6159) / 8 + LINE(0, 0, 6223) / 8 + LINE(0, 0, 7126) / 8 + LINE(0, 0, 6534) / 8 + -LINE(0, 0, 6782) / 4 + -LINE(0, 0, 5837) / 4 + -LINE(0, 0, 7039) / 4 + -LINE(0, 0, 6446) / 4 + -LINE(0, 0, 7221) / 4 + -LINE(0, 0, 7439) / 4 + -LINE(0, 0, 7534) / 4 + -LINE(0, 0, 7736) / 4 + -LINE(0, 0, 7891) / 4 + -LINE(0, 0, 8034) / 4 + -LINE(0, 0, 9215) / 4 + -LINE(0, 0, 8278) / 4 + -LINE(0, 0, 8447) / 4 + -LINE(0, 0, 8565) / 4 + -LINE(0, 0, 9513) / 4 + -LINE(0, 0, 8885) / 4 + LINE(0, 0, 9012) / 2 + LINE(0, 0, 9171) / 2 + LINE(0, 0, 8146) / 2 + LINE(0, 0, 9449) / 2 + LINE(0, 0, 8700) / 2 + LINE(0, 0, 9765) / 2 + LINE(0, 0, 9867) / 2 + LINE(0, 0, 10046) / 2 + LINE(0, 0, 10110) / 2 + LINE(0, 0, 10285) / 2 + LINE(0, 0, 10428) / 2 + LINE(0, 0, 10578) / 2 + LINE(0, 0, 10734) / 2 + LINE(0, 0, 10815) / 2 + LINE(0, 0, 11023) / 2 + LINE(0, 0, 11185) / 2 + LINE(0, 0, 11254) / 2;
	WRITE_LINE(1, 11) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_43(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(7, 2298, 21) / 2;
	WRITE_LINE(7, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2298, 21) + LINE(6, 2275, 53) / 2;
	WRITE_LINE(6, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2275, 53) + LINE(5, 2220, 173) / 2;
	WRITE_LINE(5, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2220, 173) + LINE(0, 0, 9375);
	tmp_3 = -Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(4, 2045, 32) / 2;
	WRITE_LINE(4, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2045, 32) + LINE(3, 2011, 75) / 2;
	WRITE_LINE(3, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2011, 75) + LINE(2, 1934, 133) / 2;
	WRITE_LINE(2, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1934, 133) + LINE(0, 0, 9375);
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = LINE(0, 0, 163) / 32 + LINE(0, 0, 233) / 32 + LINE(0, 0, 412) / 32 + LINE(0, 0, 534) / 32 + LINE(0, 0, 761) / 32 + LINE(0, 0, 875) / 32 + LINE(0, 0, 2721) / 32 + LINE(0, 0, 1119) / 32 + LINE(0, 0, 1233) / 32 + LINE(0, 0, 1434) / 32 + LINE(0, 0, 2443) / 32 + LINE(0, 0, 1742) / 32 + LINE(0, 0, 1862) / 32 + -LINE(0, 0, 2046) / 16 + -LINE(0, 0, 2149) / 16 + -LINE(0, 0, 2256) / 16 + -LINE(0, 0, 1555) / 16 + -LINE(0, 0, 2579) / 16 + -LINE(0, 0, 1065) / 16 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 3036) / 16 + -LINE(0, 0, 4152) / 16 + -LINE(0, 0, 3267) / 16 + -LINE(0, 0, 3451) / 16 + -LINE(0, 0, 4492) / 16 + -LINE(0, 0, 3725) / 16 + LINE(0, 0, 3889) / 8 + LINE(0, 0, 4034) / 8 + LINE(0, 0, 3121) / 8 + LINE(0, 0, 4257) / 8 + LINE(0, 0, 3569) / 8 + LINE(0, 0, 4556) / 8 + LINE(0, 0, 4727) / 8 + LINE(0, 0, 4849) / 8 + LINE(0, 0, 5837) / 8 + LINE(0, 0, 5129) / 8 + LINE(0, 0, 5235) / 8 + LINE(0, 0, 5421) / 8 + LINE(0, 0, 6159) / 8 + -LINE(0, 0, 5759) / 4 + -LINE(0, 0, 5034) / 4 + -LINE(0, 0, 6035) / 4 + -LINE(0, 0, 5534) / 4 + -LINE(0, 0, 6223) / 4 + -LINE(0, 0, 6446) / 4 + -LINE(0, 0, 6534) / 4 + -LINE(0, 0, 8034) / 4 + -LINE(0, 0, 6859) / 4 + -LINE(0, 0, 7039) / 4 + -LINE(0, 0, 7736) / 4 + -LINE(0, 0, 7221) / 4 + -LINE(0, 0, 7439) / 4 + LINE(0, 0, 7534) / 2 + LINE(0, 0, 7126) / 2 + LINE(0, 0, 7891) / 2 + LINE(0, 0, 6782) / 2 + LINE(0, 0, 8146) / 2 + LINE(0, 0, 8278) / 2 + LINE(0, 0, 8447) / 2 + LINE(0, 0, 8565) / 2 + LINE(0, 0, 8700) / 2;
	WRITE_LINE(1, 11) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_44(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(7, 2298, 21) / 2;
	WRITE_LINE(7, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2298, 21) + LINE(6, 2275, 53) / 2;
	WRITE_LINE(6, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2275, 53) + LINE(5, 2220, 173) / 2;
	WRITE_LINE(5, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2220, 173) + LINE(0, 0, 7031);
	tmp_3 = -Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(4, 2045, 32) / 2;
	WRITE_LINE(4, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2045, 32) + LINE(3, 2011, 75) / 2;
	WRITE_LINE(3, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2011, 75) + LINE(2, 1934, 133) / 2;
	WRITE_LINE(2, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1934, 133) + LINE(0, 0, 7031);
	tmp_5 = -Acc;
	Acc = LINE(0, 0, 163) / 32 + LINE(0, 0, 233) / 32 + LINE(0, 0, 412) / 32 + LINE(0, 0, 534) / 32 + LINE(0, 0, 761) / 32 + LINE(0, 0, 875) / 32 + LINE(0, 0, 1434) / 32 + LINE(0, 0, 1119) / 32 + LINE(0, 0, 1862) / 32 + -LINE(0, 0, 1065) / 16 + -LINE(0, 0, 1555) / 16 + -LINE(0, 0, 1742) / 16 + -LINE(0, 0, 1233) / 16 + -LINE(0, 0, 2046) / 16 + -LINE(0, 0, 2149) / 16 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 2443) / 16 + -LINE(0, 0, 3121) / 16 + -LINE(0, 0, 2721) / 16 + LINE(0, 0, 2256) / 8 + LINE(0, 0, 3036) / 8 + LINE(0, 0, 2579) / 8 + LINE(0, 0, 3267) / 8 + LINE(0, 0, 3451) / 8 + LINE(0, 0, 3569) / 8 + LINE(0, 0, 4492) / 8 + LINE(0, 0, 3889) / 8 + LINE(0, 0, 4034) / 8 + LINE(0, 0, 4152) / 8 + LINE(0, 0, 4849) / 8 + -LINE(0, 0, 3725) / 4 + -LINE(0, 0, 4556) / 4 + -LINE(0, 0, 4727) / 4 + -LINE(0, 0, 4257) / 4 + -LINE(0, 0, 5034) / 4 + -LINE(0, 0, 5837) / 4 + -LINE(0, 0, 5235) / 4 + -LINE(0, 0, 5421) / 4 + -LINE(0, 0, 6159) / 4 + LINE(0, 0, 5759) / 2 + LINE(0, 0, 5129) / 2 + LINE(0, 0, 6035) / 2 + LINE(0, 0, 5534) / 2 + LINE(0, 0, 6223) / 2 + LINE(0, 0, 6446) / 2;
	WRITE_LINE(1, 11) = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_45(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(4, 2190, 1);
	tmp_3 = -Acc;
	Acc = LINE(3, 2187, 1);
	tmp_5 = -Acc;
	Acc = LINE(5, 2193, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(5, 2193) = Acc;
	Acc = -LINE(1, 11, 1) / 4 + LINE(2, 2184, 1) / 2;
	WRITE_LINE(2, 2184) = Acc;
	Acc = Acc * 3 / 2 + LINE(5, 2193, 1) + LINE(26, 16381, 13) / 2;
	WRITE_LINE(26, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(26, 16381, 13) + LINE(25, 16366, 83) / 2;
	WRITE_LINE(25, 16366) = -Acc;
	Acc = -Acc / 2 + LINE(25, 16366, 83) + LINE(24, 16281, 116) / 2;
	WRITE_LINE(24, 16281) = -Acc;
	Acc = -Acc / 2 + LINE(24, 16281, 116) + LINE(23, 16163, 239) / 2;
	WRITE_LINE(23, 16163) = -Acc;
	Acc = -Acc / 2 + LINE(23, 16163, 239) + LINE(22, 15922, 339) / 2;
	WRITE_LINE(22, 15922) = -Acc;
	Acc = -Acc / 2 + LINE(22, 15922, 339) + LINE(21, 15581, 481) / 2;
	WRITE_LINE(21, 15581) = -Acc;
	Acc = -Acc / 2 + LINE(21, 15581, 481) + LINE(20, 15098, 555) / 2;
	WRITE_LINE(20, 15098) = -Acc;
	Acc = -Acc / 2 + LINE(20, 15098, 555) + LINE(19, 14541, 823) / 2;
	WRITE_LINE(19, 14541) = -Acc;
	Acc = -Acc / 2 + LINE(19, 14541, 823) + LINE(18, 13716, 999) / 2;
	WRITE_LINE(18, 13716) = -Acc;
	Acc = -Acc / 2 + LINE(18, 13716, 999) + LINE(17, 12715, 1100) / 2;
	WRITE_LINE(17, 12715) = -Acc;
	Acc = -Acc / 2 + LINE(17, 12715, 1100) + LINE(16, 11613, 1347) / 2;
	WRITE_LINE(16, 11613) = -Acc;
	Acc = -Acc / 2 + LINE(16, 11613, 1347) + LINE(15, 10264, 1563) / 2;
	WRITE_LINE(15, 10264) = -Acc;
	Acc = -Acc / 2 + LINE(15, 10264, 1563) + LINE(14, 8699, 1841) / 2;
	WRITE_LINE(14, 8699) = -Acc;
	Acc = -Acc / 2 + LINE(14, 8699, 1841) + LINE(13, 6856, 2001) / 2;
	WRITE_LINE(13, 6856) = -Acc;
	Acc = -Acc / 2 + LINE(13, 6856, 2001) + LINE(12, 4853, 2083) / 2;
	WRITE_LINE(12, 4853) = -Acc;
	Acc = -Acc / 2 + LINE(12, 4853, 2083);
	WRITE_LINE(1, 11) = -Acc;
	Acc = LINE(1, 11, 0) + LINE(9, 2666, 147) / 2;
	WRITE_LINE(9, 2666) = -Acc;
	Acc = -Acc / 2 + LINE(9, 2666, 147) + LINE(11, 2768, 43) / 2;
	WRITE_LINE(11, 2768) = -Acc;
	Acc = -Acc / 2 + LINE(11, 2768, 43) + LINE(10, 2723, 55) / 2;
	WRITE_LINE(10, 2723) = -Acc;
	Acc = -Acc / 2 + LINE(10, 2723, 55);
	WRITE_LINE(4, 2190) = -Acc;
	Acc = LINE(1, 11, 0) + LINE(6, 2444, 249) / 2;
	WRITE_LINE(6, 2444) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + LINE(6, 2444, 249) + LINE(7, 2494, 48) / 2;
	WRITE_LINE(7, 2494) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2494, 48) + LINE(8, 2517, 21) / 2;
	WRITE_LINE(8, 2517) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2517, 21);
	WRITE_LINE(3, 2187) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_46(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 0);
	WRITE_LINE(2, 3166) = -Acc;
	Acc = LINE(2, 3166, 2000);
	WRITE_LINE(0, 0) = -Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(11, 4298, 51) / 2;
	WRITE_LINE(11, 4298) = -Acc;
	Acc = -Acc / 2 + LINE(11, 4298, 51) + LINE(10, 4245, 231) / 2;
	WRITE_LINE(10, 4245) = -Acc;
	Acc = -Acc / 2 + LINE(10, 4245, 231) + LINE(9, 4012, 313) / 2;
	WRITE_LINE(9, 4012) = -Acc;
	Acc = Acc * -9 / 8 + LINE(9, 4012, 313) * 9 / 4 + LINE(12, 16373, 11307) * 9 / 4;
	tmp_3 = -Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(8, 3697, 62) / 2;
	WRITE_LINE(8, 3697) = -Acc;
	Acc = -Acc / 2 + LINE(8, 3697, 62) + LINE(7, 3633, 165) / 2;
	WRITE_LINE(7, 3633) = -Acc;
	Acc = -Acc / 2 + LINE(7, 3633, 165) + LINE(6, 3466, 289) / 2;
	WRITE_LINE(6, 3466) = -Acc;
	Acc = Acc * -9 / 8 + LINE(6, 3466, 289) * 9 / 4 + LINE(12, 16373, 11307) * 9 / 4;
	tmp_5 = -Acc;
	Acc = LINE(0, 0, 10) / 2;
	WRITE_LINE(12, 16373) = Acc;
	Acc = Acc * -3 / 16 + -LINE(12, 16373, 401) / 16 + -LINE(12, 16373, 750) / 16 + -LINE(12, 16373, 1054) / 16 + LINE(12, 16373, 1222) / 8 + LINE(12, 16373, 1423) / 8 + LINE(12, 16373, 1731) / 8 + LINE(12, 16373, 1851) / 8 + LINE(12, 16373, 2138) / 8 + -LINE(12, 16373, 2245) / 4 + -LINE(12, 16373, 2432) / 4 + -LINE(12, 16373, 1544) / 4 + -LINE(12, 16373, 2710) / 4 + -LINE(12, 16373, 2862) / 4 + -LINE(12, 16373, 2035) / 4 + LINE(5, 3175, 1) / 2;
	WRITE_LINE(5, 3175) = Acc;
	Acc = Acc * 3 / 32 + LINE(12, 16373, 3110) / 32 + LINE(12, 16373, 3256) / 32 + LINE(12, 16373, 3558) / 32 + LINE(12, 16373, 5023) / 32 + LINE(12, 16373, 3878) / 32 + LINE(12, 16373, 4023) / 32 + -LINE(12, 16373, 4716) / 16 + -LINE(12, 16373, 4246) / 16 + -LINE(12, 16373, 4481) / 16 + -LINE(12, 16373, 4838) / 16 + -LINE(12, 16373, 3714) / 16 + LINE(12, 16373, 5118) / 8 + LINE(12, 16373, 5224) / 8 + LINE(12, 16373, 5410) / 8 + LINE(12, 16373, 5523) / 8 + LINE(12, 16373, 5748) / 8 + LINE(12, 16373, 6848) / 8 + -LINE(12, 16373, 6024) / 4 + -LINE(12, 16373, 6212) / 4 + -LINE(12, 16373, 7115) / 4 + LINE(4, 3172, 1) / 2;
	WRITE_LINE(4, 3172) = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 8 + LINE(12, 16373, 6523) / 8 + LINE(12, 16373, 5826) / 8 + LINE(12, 16373, 7028) / 8 + LINE(12, 16373, 6435) / 8 + LINE(12, 16373, 7210) / 8 + LINE(12, 16373, 7428) / 8 + -LINE(12, 16373, 7725) / 4 + -LINE(12, 16373, 7880) / 4 + -LINE(12, 16373, 8023) / 4 + -LINE(12, 16373, 9204) / 4 + -LINE(12, 16373, 8436) / 4 + -LINE(12, 16373, 8554) / 4 + -LINE(12, 16373, 9502) / 4 + LINE(3, 3169, 1) / 2;
	WRITE_LINE(3, 3169) = Acc;
	*out_right = tmp_3;
	Acc = Acc * -3 / 4 + -LINE(12, 16373, 8874) / 4 + -LINE(12, 16373, 9001) / 4 + -LINE(12, 16373, 9160) / 4 + -LINE(12, 16373, 8135) / 4 + -LINE(12, 16373, 9438) / 4 + -LINE(12, 16373, 8689) / 4 + -LINE(12, 16373, 9754) / 4 + -LINE(12, 16373, 9856) / 4 + -LINE(12, 16373, 10035) / 4 + -LINE(12, 16373, 10099) / 4 + LINE(12, 16373, 10274) / 2 + LINE(12, 16373, 10417) / 2 + LINE(12, 16373, 10567) / 2 + LINE(12, 16373, 10723) / 2 + LINE(12, 16373, 10804) / 2 + LINE(12, 16373, 11012) / 2 + LINE(12, 16373, 11243) / 2;
	WRITE_LINE(1, 11) = -Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_47(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5;
	tmp_0 = input;
	Acc = LINE(0, 11, 2) / 2 + LINE(9, 2298, 51) / 2;
	WRITE_LINE(9, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(9, 2298, 51) + LINE(8, 2245, 131) / 2;
	WRITE_LINE(8, 2245) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2245, 131) + LINE(7, 2112, 213) / 2;
	WRITE_LINE(7, 2112) = -Acc;
	Acc = Acc * -9 / 8 + LINE(7, 2112, 213) * 9 / 4 + LINE(10, 16373, 11307) * 9 / 4;
	tmp_3 = -Acc;
	Acc = LINE(0, 11, 2) / 2 + LINE(6, 1897, 62) / 2;
	WRITE_LINE(6, 1897) = -Acc;
	Acc = -Acc / 2 + LINE(6, 1897, 62) + LINE(5, 1833, 105) / 2;
	WRITE_LINE(5, 1833) = -Acc;
	Acc = -Acc / 2 + LINE(5, 1833, 105) + LINE(4, 1726, 189) / 2;
	WRITE_LINE(4, 1726) = -Acc;
	Acc = Acc * -9 / 8 + LINE(4, 1726, 189) * 9 / 4 + LINE(10, 16373, 11307) * 9 / 4;
	tmp_5 = -Acc;
	Acc = tmp_0 / 2 + LINE(10, 16373, 11307) / 2;
	WRITE_LINE(11, 16383) = -Acc;
	Acc = LINE(11, 16383, 9) / 2;
	WRITE_LINE(10, 16373) = Acc;
	Acc = LINE(10, 16373, 1222) / 8 + LINE(10, 16373, 1423) / 8 + LINE(10, 16373, 1731) / 8 + LINE(10, 16373, 1851) / 8 + LINE(10, 16373, 3025) / 8 + LINE(10, 16373, 2138) / 8 + -LINE(10, 16373, 2245) / 4 + -LINE(10, 16373, 2432) / 4 + -LINE(10, 16373, 1544) / 4 + -LINE(10, 16373, 2710) / 4 + -LINE(10, 16373, 2862) / 4 + -LINE(10, 16373, 2035) / 4 + LINE(3, 1535, 1) / 2;
	WRITE_LINE(3, 1535) = Acc;
	Acc = Acc * 3 / 32 + LINE(10, 16373, 3110) / 32 + LINE(10, 16373, 3256) / 32 + LINE(10, 16373, 3440) / 32 + LINE(10, 16373, 3558) / 32 + LINE(10, 16373, 5023) / 32 + LINE(10, 16373, 3878) / 32 + LINE(10, 16373, 4023) / 32 + -LINE(10, 16373, 4716) / 16 + -LINE(10, 16373, 4246) / 16 + -LINE(10, 16373, 4481) / 16 + -LINE(10, 16373, 4545) / 16 + -LINE(10, 16373, 4838) / 16 + -LINE(10, 16373, 3714) / 16 + LINE(10, 16373, 5118) / 8 + LINE(10, 16373, 5224) / 8 + LINE(10, 16373, 5410) / 8 + LINE(10, 16373, 5523) / 8 + LINE(10, 16373, 5748) / 8 + LINE(10, 16373, 6848) / 8 + -LINE(10, 16373, 6024) / 4 + -LINE(10, 16373, 6148) / 4 + -LINE(10, 16373, 6212) / 4 + -LINE(10, 16373, 7115) / 4 + LINE(2, 1532, 1) / 2;
	WRITE_LINE(2, 1532) = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 8 + LINE(10, 16373, 6523) / 8 + LINE(10, 16373, 6771) / 8 + LINE(10, 16373, 5826) / 8 + LINE(10, 16373, 7028) / 8 + LINE(10, 16373, 6435) / 8 + LINE(10, 16373, 7210) / 8 + LINE(10, 16373, 7428) / 8 + -LINE(10, 16373, 7725) / 4 + -LINE(10, 16373, 7880) / 4 + -LINE(10, 16373, 8023) / 4 + -LINE(10, 16373, 9204) / 4 + -LINE(10, 16373, 8436) / 4 + -LINE(10, 16373, 8554) / 4 + -LINE(10, 16373, 9502) / 4 + LINE(1, 1529, 1) / 2;
	WRITE_LINE(1, 1529) = Acc;
	*out_right = tmp_3;
	Acc = Acc * -3 / 4 + -LINE(10, 16373, 8874) / 4 + -LINE(10, 16373, 9001) / 4 + -LINE(10, 16373, 9160) / 4 + -LINE(10, 16373, 8135) / 4 + -LINE(10, 16373, 9438) / 4 + -LINE(10, 16373, 8689) / 4 + -LINE(10, 16373, 9754) / 4 + -LINE(10, 16373, 9856) / 4 + -LINE(10, 16373, 10035) / 4 + -LINE(10, 16373, 10099) / 4 + LINE(10, 16373, 10274) / 2 + LINE(10, 16373, 10417) / 2 + LINE(10, 16373, 10567) / 2 + LINE(10, 16373, 10723) / 2 + LINE(10, 16373, 10804) / 2 + LINE(10, 16373, 11012) / 2 + LINE(10, 16373, 11243) / 2;
	WRITE_LINE(0, 11) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_48(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(11, 2298, 51) / 2;
	WRITE_LINE(11, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(11, 2298, 51) + LINE(10, 2245, 131) / 2;
	WRITE_LINE(10, 2245) = -Acc;
	Acc = -Acc / 2 + LINE(10, 2245, 131) + LINE(9, 2112, 213) / 2;
	WRITE_LINE(9, 2112) = -Acc;
	Acc = Acc * -9 / 8 + LINE(9, 2112, 213) * 9 / 4 + LINE(12, 16364, 11298) * 9 / 4;
	tmp_3 = -Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(8, 1897, 62) / 2;
	WRITE_LINE(8, 1897) = -Acc;
	Acc = -Acc / 2 + LINE(8, 1897, 62) + LINE(7, 1833, 105) / 2;
	WRITE_LINE(7, 1833) = -Acc;
	Acc = -Acc / 2 + LINE(7, 1833, 105) + LINE(6, 1726, 189) / 2;
	WRITE_LINE(6, 1726) = -Acc;
	Acc = Acc * -9 / 8 + LINE(6, 1726, 189) * 9 / 4 + LINE(12, 16364, 11298) * 9 / 4;
	tmp_5 = -Acc;
	Acc = LINE(0, 0, 3);
	WRITE_LINE(2, 1526) = -Acc;
	Acc = LINE(2, 1526, 1300);
	WRITE_LINE(13, 16380) = -Acc;
	Acc = LINE(12, 16364, 11298) * 3 / 4 + LINE(0, 0, 0) / 2;
	WRITE_LINE(12, 16364) = -Acc;
	Acc = LINE(12, 16364, 1213) / 8 + LINE(12, 16364, 2129) / 8 + -LINE(12, 16364, 2236) / 4 + -LINE(12, 16364, 2853) / 4 + -LINE(12, 16364, 2026) / 4 + LINE(5, 1535, 1) / 2;
	WRITE_LINE(5, 1535) = Acc;
	Acc = Acc * 3 / 32 + LINE(12, 16364, 3101) / 32 + LINE(12, 16364, 3549) / 32 + LINE(12, 16364, 5014) / 32 + LINE(12, 16364, 3869) / 32 + LINE(12, 16364, 4014) / 32 + -LINE(12, 16364, 4707) / 16 + -LINE(12, 16364, 4237) / 16 + -LINE(12, 16364, 4472) / 16 + -LINE(12, 16364, 4536) / 16 + -LINE(12, 16364, 4829) / 16 + -LINE(12, 16364, 3705) / 16 + LINE(12, 16364, 5109) / 8 + LINE(12, 16364, 5215) / 8 + LINE(12, 16364, 5401) / 8 + LINE(12, 16364, 5514) / 8 + LINE(12, 16364, 5739) / 8 + LINE(12, 16364, 6839) / 8 + -LINE(12, 16364, 6015) / 4 + -LINE(12, 16364, 6139) / 4 + -LINE(12, 16364, 6203) / 4 + -LINE(12, 16364, 7106) / 4 + LINE(4, 1532, 1) / 2;
	WRITE_LINE(4, 1532) = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 8 + LINE(12, 16364, 6514) / 8 + LINE(12, 16364, 6762) / 8 + LINE(12, 16364, 5817) / 8 + LINE(12, 16364, 7019) / 8 + LINE(12, 16364, 6426) / 8 + LINE(12, 16364, 7201) / 8 + LINE(12, 16364, 7419) / 8 + -LINE(12, 16364, 7716) / 4 + -LINE(12, 16364, 7871) / 4 + -LINE(12, 16364, 8014) / 4 + -LINE(12, 16364, 9195) / 4 + -LINE(12, 16364, 8427) / 4 + -LINE(12, 16364, 8545) / 4 + -LINE(12, 16364, 9493) / 4 + LINE(3, 1529, 1) / 2;
	WRITE_LINE(3, 1529) = Acc;
	*out_right = tmp_3;
	Acc = Acc * -3 / 4 + -LINE(12, 16364, 8865) / 4 + -LINE(12, 16364, 8992) / 4 + -LINE(12, 16364, 9151) / 4 + -LINE(12, 16364, 8126) / 4 + -LINE(12, 16364, 9429) / 4 + -LINE(12, 16364, 8680) / 4 + -LINE(12, 16364, 9745) / 4 + -LINE(12, 16364, 9847) / 4 + -LINE(12, 16364, 10026) / 4 + -LINE(12, 16364, 10090) / 4 + LINE(12, 16364, 10265) / 2 + LINE(12, 16364, 10408) / 2 + LINE(12, 16364, 10558) / 2 + LINE(12, 16364, 10714) / 2 + LINE(12, 16364, 10795) / 2 + LINE(12, 16364, 11003) / 2 + LINE(12, 16364, 11234) / 2;
	WRITE_LINE(1, 11) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_49(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(4, 191, 1);
	tmp_3 = -Acc;
	Acc = LINE(3, 188, 1);
	tmp_5 = -Acc;
	Acc = LINE(5, 194, 1) / 2 + LINE(0, 0, 2000) / 2;
	WRITE_LINE(5, 194) = Acc;
	Acc = -LINE(1, 11, 1) / 4 + LINE(2, 185, 1) / 2;
	WRITE_LINE(2, 185) = Acc;
	Acc = Acc * 3 / 2 + LINE(5, 194, 1) + LINE(26, 14382, 13) / 2;
	WRITE_LINE(26, 14382) = -Acc;
	Acc = -Acc / 2 + LINE(26, 14382, 13) + LINE(25, 14367, 83) / 2;
	WRITE_LINE(25, 14367) = -Acc;
	Acc = -Acc / 2 + LINE(25, 14367, 83) + LINE(24, 14282, 116) / 2;
	WRITE_LINE(24, 14282) = -Acc;
	Acc = -Acc / 2 + LINE(24, 14282, 116) + LINE(23, 14164, 239) / 2;
	WRITE_LINE(23, 14164) = -Acc;
	Acc = -Acc / 2 + LINE(23, 14164, 239) + LINE(22, 13923, 339) / 2;
	WRITE_LINE(22, 13923) = -Acc;
	Acc = -Acc / 2 + LINE(22, 13923, 339) + LINE(21, 13582, 481) / 2;
	WRITE_LINE(21, 13582) = -Acc;
	Acc = -Acc / 2 + LINE(21, 13582, 481) + LINE(20, 13099, 555) / 2;
	WRITE_LINE(20, 13099) = -Acc;
	Acc = -Acc / 2 + LINE(20, 13099, 555) + LINE(19, 12542, 823) / 2;
	WRITE_LINE(19, 12542) = -Acc;
	Acc = -Acc / 2 + LINE(19, 12542, 823) + LINE(18, 11717, 999) / 2;
	WRITE_LINE(18, 11717) = -Acc;
	Acc = -Acc / 2 + LINE(18, 11717, 999) + LINE(17, 10716, 1100) / 2;
	WRITE_LINE(17, 10716) = -Acc;
	Acc = -Acc / 2 + LINE(17, 10716, 1100) + LINE(16, 9614, 1347) / 2;
	WRITE_LINE(16, 9614) = -Acc;
	Acc = -Acc / 2 + LINE(16, 9614, 1347) + LINE(15, 8265, 1563) / 2;
	WRITE_LINE(15, 8265) = -Acc;
	Acc = -Acc / 2 + LINE(15, 8265, 1563) + LINE(14, 6700, 1841) / 2;
	WRITE_LINE(14, 6700) = -Acc;
	Acc = -Acc / 2 + LINE(14, 6700, 1841) + LINE(13, 4857, 2001) / 2;
	WRITE_LINE(13, 4857) = -Acc;
	Acc = -Acc / 2 + LINE(13, 4857, 2001) + LINE(12, 2854, 2083) / 2;
	WRITE_LINE(12, 2854) = -Acc;
	Acc = -Acc / 2 + LINE(12, 2854, 2083);
	WRITE_LINE(1, 11) = -Acc;
	Acc = LINE(1, 11, 0) + LINE(9, 667, 147) / 2;
	WRITE_LINE(9, 667) = -Acc;
	Acc = -Acc / 2 + LINE(9, 667, 147) + LINE(11, 769, 43) / 2;
	WRITE_LINE(11, 769) = -Acc;
	Acc = -Acc / 2 + LINE(11, 769, 43) + LINE(10, 724, 55) / 2;
	WRITE_LINE(10, 724) = -Acc;
	Acc = -Acc / 2 + LINE(10, 724, 55);
	WRITE_LINE(4, 191) = -Acc;
	Acc = LINE(1, 11, 0) + LINE(6, 445, 249) / 2;
	WRITE_LINE(6, 445) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + LINE(6, 445, 249) + LINE(7, 495, 48) / 2;
	WRITE_LINE(7, 495) = -Acc;
	Acc = -Acc / 2 + LINE(7, 495, 48) + LINE(8, 518, 21) / 2;
	WRITE_LINE(8, 518) = -Acc;
	Acc = -Acc / 2 + LINE(8, 518, 21);
	WRITE_LINE(3, 188) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_50(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_51(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_52(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_53(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_54(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_55(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_56(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_57(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_58(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_59(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_60(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_61(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_62(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_63(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_64(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_65(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_66(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_67(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_68(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_69(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	WRITE_LINE(1, 16282) = Acc;
	Acc = LINE(2, (16374 - (lfo1_value >> 8)), 88) * 27 / 1024 + LINE(1, (16282 - (lfo1_value >> 8)), 5) * 27 / 1024 + LINE(2, (16374 - (lfo1_value >> 8)), 89) * -27 / 512 + LINE(1, (16282 - (lfo1_value >> 8)), 4) * -27 / 512 + LINE(2, (16374 - (lfo1_value >> 8)), 90) * 27 / 256 + LINE(1, (16282 - (lfo1_value >> 8)), 3) * 27 / 256 + LINE(2, (16374 - (lfo1_value >> 8)), 91) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 2) * -27 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 0) * 81 / 128 + LINE(1, (16282 - (lfo1_value >> 8)), 1) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo1_value >> 8)), 0) / 2 + tmp_1f47 / 2;
		break;
	case 2:
		Acc = tmp_1f47;
		break;
	case 3:
		Acc = tmp_1f47 / 2 + tmp_1f48 / 2;
		break;
	case 4:
		Acc = tmp_1f48;
		break;
	case 5:
		Acc = tmp_1f48 / 2 + tmp_1f49 / 2;
		break;
	case 6:
		Acc = tmp_1f49;
		break;
	case 7:
		Acc = tmp_1f49 / 2 + tmp_1f4a / 2;
		break;
	case 8:
		Acc = tmp_1f4a;
		break;
	case 9:
		Acc = tmp_1f4a / 2 + tmp_1f4b / 2;
		break;
	case 10:
		Acc = tmp_1f4b;
		break;
	case 11:
		Acc = tmp_1f4b / 2 + tmp_1f4c / 2;
		break;
	case 12:
		Acc = tmp_1f4c;
		break;
	case 13:
		Acc = tmp_1f4c / 2 + tmp_1f4d / 2;
		break;
	case 14:
		Acc = tmp_1f4d;
		break;
	case 15:
		Acc = tmp_1f4d / 2 + LINE(1, (16282 - (lfo1_value >> 8)), 1) / 2;
		break;
	}
	tmp_3 = Acc;
	Acc = LINE(2, (16374 - (lfo2_value >> 8)), 88) * 9 / 512 + LINE(1, (16282 - (lfo2_value >> 8)), 5) * 9 / 512 + LINE(2, (16374 - (lfo2_value >> 8)), 89) * -9 / 256 + LINE(1, (16282 - (lfo2_value >> 8)), 4) * -9 / 256 + LINE(2, (16374 - (lfo2_value >> 8)), 90) * 9 / 128 + LINE(1, (16282 - (lfo2_value >> 8)), 3) * 9 / 128 + LINE(2, (16374 - (lfo2_value >> 8)), 91) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 2) * -9 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 0) * 27 / 64 + LINE(1, (16282 - (lfo2_value >> 8)), 1) * 27 / 64;
	WRITE_LINE(0, (4006 - (lfo2_value >> 8))) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0);
		break;
	case 1:
		Acc = LINE(1, (16282 - (lfo2_value >> 8)), 0) / 2 + tmp_fa7 / 2;
		break;
	case 2:
		Acc = tmp_fa7;
		break;
	case 3:
		Acc = tmp_fa7 / 2 + tmp_fa8 / 2;
		break;
	case 4:
		Acc = tmp_fa8;
		break;
	case 5:
		Acc = tmp_fa8 / 2 + tmp_fa9 / 2;
		break;
	case 6:
		Acc = tmp_fa9;
		break;
	case 7:
		Acc = tmp_fa9 / 2 + tmp_faa / 2;
		break;
	case 8:
		Acc = tmp_faa;
		break;
	case 9:
		Acc = tmp_faa / 2 + tmp_fab / 2;
		break;
	case 10:
		Acc = tmp_fab;
		break;
	case 11:
		Acc = tmp_fab / 2 + tmp_fac / 2;
		break;
	case 12:
		Acc = tmp_fac;
		break;
	case 13:
		Acc = tmp_fac / 2 + tmp_fad / 2;
		break;
	case 14:
		Acc = tmp_fad;
		break;
	case 15:
		Acc = tmp_fad / 2 + LINE(1, (16282 - (lfo2_value >> 8)), 1) / 2;
		break;
	}
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 32768;
	WRITE_LINE(2, 16374) = -Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_70(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 1172);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 1172);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_71(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 1758);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 1758);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_72(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 2344);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 2344);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_73(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 3516);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 3516);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_74(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 4688);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 4688);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_75(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 4922);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 4922);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_76(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 5156);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 5156);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_77(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 5391);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 5391);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_78(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 5625);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 5625);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_79(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 5859);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 5859);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_80(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 6094);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 6094);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_81(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 6328);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 6328);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_82(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 6563);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 6563);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_83(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 6797);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 6797);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_84(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 7031);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 7031);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_85(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 7500);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 7500);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_86(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 7969);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 7969);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_87(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 9141);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 9141);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_88(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 11719);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 11719);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_89(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 14063);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 14063);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_90(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 15705) / 2 + LINE(0, 0, 7853) + LINE(3, 330, 41) / 2;
	WRITE_LINE(3, 330) = -Acc;
	Acc = -Acc / 2 + LINE(3, 330, 41) + LINE(2, 287, 195) / 2;
	WRITE_LINE(2, 287) = -Acc;
	Acc = -Acc / 2 + LINE(2, 287, 195) + LINE(1, 90, 63) / 2;
	WRITE_LINE(1, 90) = -Acc;
	Acc = -Acc / 2 + LINE(1, 90, 63);
	tmp_5 = -Acc;
	Acc = LINE(0, 0, 15705) / 2 + LINE(0, 0, 7853) + LINE(6, 677, 49) / 2;
	WRITE_LINE(6, 677) = -Acc;
	Acc = -Acc / 2 + LINE(6, 677, 49) + LINE(5, 626, 114) / 2;
	WRITE_LINE(5, 626) = -Acc;
	Acc = -Acc / 2 + LINE(5, 626, 114) + LINE(4, 510, 178) / 2;
	WRITE_LINE(4, 510) = -Acc;
	Acc = -Acc / 2 + LINE(4, 510, 178);
	tmp_3 = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_91(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 5460) + LINE(0, 0, 16378) / 2;
	tmp_5 = Acc;
	Acc = tmp_5 * 21 / 32;
	tmp_5 = -Acc;
	Acc = LINE(0, 0, 10919) + LINE(0, 0, 16378) / 2;
	tmp_3 = Acc;
	Acc = tmp_3 * 21 / 32;
	tmp_3 = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_92(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 13998) / 128 + LINE(0, 0, 13968) / 128 + LINE(0, 0, 13955) / 128 + LINE(0, 0, 13957) / 128 + LINE(0, 0, 13815) / 128 + -LINE(0, 0, 13819) / 64 + -LINE(0, 0, 13749) / 64 + -LINE(0, 0, 13756) / 64 + -LINE(0, 0, 13676) / 64 + LINE(0, 0, 13552) / 32 + LINE(0, 0, 13319) / 32 + LINE(0, 0, 13185) / 32 + LINE(0, 0, 12927) / 32 + LINE(0, 0, 12656) / 32 + -LINE(0, 0, 12338) / 16 + -LINE(0, 0, 11919) / 16 + -LINE(0, 0, 11361) / 16 + -LINE(0, 0, 10683) / 16 + LINE(0, 0, 9835) / 8 + LINE(0, 0, 8775) / 8 + -LINE(0, 0, 9450) / 4 + -LINE(0, 0, 5194) / 4 + LINE(0, 0, 4501) / 2 + LINE(0, 0, 2724) / 2 + LINE(0, 0, 781) / 2;
	tmp_3 = -Acc;
	Acc = LINE(0, 0, 13986) / 128 + LINE(0, 0, 13919) / 128 + LINE(0, 0, 13918) / 128 + LINE(0, 0, 13972) / 128 + LINE(0, 0, 13807) / 128 + LINE(0, 0, 13854) / 128 + -LINE(0, 0, 13727) / 64 + -LINE(0, 0, 13619) / 64 + -LINE(0, 0, 13519) / 64 + LINE(0, 0, 13457) / 32 + LINE(0, 0, 13289) / 32 + LINE(0, 0, 13071) / 32 + -LINE(0, 0, 12727) / 16 + -LINE(0, 0, 12449) / 16 + -LINE(0, 0, 12016) / 16 + -LINE(0, 0, 11571) / 16 + LINE(0, 0, 10981) / 8 + LINE(0, 0, 10160) / 8 + LINE(0, 0, 9145) / 8 + LINE(0, 0, 8913) / 8 + -LINE(0, 0, 6873) / 4 + -LINE(0, 0, 4048) / 4 + LINE(0, 0, 3041) / 2 + LINE(0, 0, 1121) / 2;
	tmp_5 = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_93(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 12, 1) / 2 + LINE(6, 2298, 67) / 2;
	WRITE_LINE(6, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2298, 67) + LINE(5, 2229, 121) / 2;
	WRITE_LINE(5, 2229) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2229, 121) + LINE(0, 0, 14000);
	tmp_3 = -Acc;
	Acc = LINE(1, 10, 1) / 2 + LINE(4, 1931, 45) / 2;
	WRITE_LINE(4, 1931) = -Acc;
	Acc = -Acc / 2 + LINE(4, 1931, 45) + LINE(3, 1884, 98) / 2;
	WRITE_LINE(3, 1884) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1884, 98);
	tmp_5 = -Acc;
	Acc = LINE(0, 0, 1065) / 32 + LINE(0, 0, 1233) / 32 + LINE(0, 0, 1555) / 32 + LINE(0, 0, 1862) / 32 + LINE(0, 0, 3569) / 32 + LINE(0, 0, 2443) / 32 + LINE(0, 0, 2721) / 32 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 2579) / 16 + -LINE(0, 0, 3451) / 16 + -LINE(0, 0, 13112) / 16 + -LINE(0, 0, 3725) / 16 + -LINE(0, 0, 3889) / 16 + LINE(0, 0, 4152) / 8 + LINE(0, 0, 4492) / 8 + LINE(0, 0, 6035) / 8 + LINE(0, 0, 12345) / 8 + LINE(0, 0, 11111) / 8 + LINE(0, 0, 5235) / 8 + LINE(0, 0, 5534) / 8 + -LINE(0, 0, 5759) / 4 + -LINE(0, 0, 5034) / 4 + -LINE(0, 0, 10211) / 4 + -LINE(0, 0, 9123) / 4 + -LINE(0, 0, 12781) / 4 + -LINE(0, 0, 5421) / 4 + -LINE(0, 0, 6534) / 4 + LINE(0, 0, 6859) / 2 + LINE(0, 0, 7126) / 2 + LINE(0, 0, 8565) / 2 + LINE(0, 0, 7736) / 2 + LINE(0, 0, 9215) / 2 + LINE(0, 0, 8146) / 2;
	WRITE_LINE(1, 10) = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
	Acc = LINE(0, 0, 5759) / 8 + LINE(0, 0, 5837) / 8 + LINE(0, 0, 5034) / 8 + LINE(0, 0, 6159) / 8 + LINE(0, 0, 5421) / 8 + LINE(0, 0, 6446) / 8 + LINE(0, 0, 6534) / 8 + LINE(0, 0, 6782) / 8 + LINE(0, 0, 6859) / 8 + LINE(0, 0, 7039) / 8 + LINE(0, 0, 7126) / 8 + LINE(0, 0, 7221) / 8 + LINE(0, 0, 8565) / 8 + LINE(0, 0, 7534) / 8 + LINE(0, 0, 7736) / 8 + LINE(0, 0, 7891) / 8 + LINE(0, 0, 9215) / 8 + LINE(0, 0, 8146) / 8 + LINE(0, 0, 8278) / 8 + -LINE(0, 0, 8447) / 4 + -LINE(0, 0, 7439) / 4 + -LINE(0, 0, 8700) / 4 + -LINE(0, 0, 8885) / 4 + -LINE(0, 0, 9012) / 4 + -LINE(0, 0, 9171) / 4 + -LINE(0, 0, 8034) / 4 + -LINE(0, 0, 9449) / 4 + -LINE(0, 0, 9513) / 4 + -LINE(0, 0, 9765) / 4 + -LINE(0, 0, 9867) / 4 + -LINE(0, 0, 10046) / 4 + -LINE(0, 0, 10110) / 4 + -LINE(0, 0, 10285) / 4 + -LINE(0, 0, 12074) / 4 + -LINE(0, 0, 10578) / 4 + -LINE(0, 0, 10734) / 4 + -LINE(0, 0, 11715) / 4 + -LINE(0, 0, 11023) / 4 + -LINE(0, 0, 11185) / 4 + LINE(0, 0, 11254) / 2 + LINE(0, 0, 11479) / 2 + LINE(0, 0, 11546) / 2 + LINE(0, 0, 10815) / 2 + LINE(0, 0, 11847) / 2 + LINE(0, 0, 10428) / 2 + LINE(0, 0, 12112) / 2 + LINE(0, 0, 12279) / 2 + LINE(0, 0, 12415) / 2 + LINE(0, 0, 12516) / 2 + LINE(0, 0, 12746) / 2 + LINE(0, 0, 12815) / 2 + LINE(0, 0, 13046) / 2 + LINE(0, 0, 13217) / 2 + LINE(0, 0, 13378) / 2 + LINE(0, 0, 13534) / 2;
	WRITE_LINE(2, 12) = -Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_94(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 1) + LINE(1, 5, 1) / 2 + LINE(7, 16381, 34) / 2;
	WRITE_LINE(7, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(7, 16381, 34) + LINE(6, 16345, 45) / 2;
	WRITE_LINE(6, 16345) = -Acc;
	Acc = -Acc / 2 + LINE(6, 16345, 45) + LINE(5, 16298, 67) / 2;
	WRITE_LINE(5, 16298) = -Acc;
	Acc = -Acc / 2 + LINE(5, 16298, 67) + LINE(4, 16229, 89) / 2;
	WRITE_LINE(4, 16229) = -Acc;
	Acc = -Acc / 2 + LINE(4, 16229, 89) + LINE(3, 16138, 101) / 2;
	WRITE_LINE(3, 16138) = -Acc;
	Acc = -Acc / 2 + LINE(3, 16138, 101) + LINE(2, 16035, 120) / 2;
	WRITE_LINE(2, 16035) = -Acc;
	Acc = -Acc / 2 + LINE(2, 16035, 120);
	tmp_3 = -Acc;
	Acc = tmp_3;
	WRITE_LINE(1, 5) = -Acc;
	*out_left = LINE(1, 5, 0);
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_95(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 150);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 300);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_96(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(1, 14261, 1) / 4 + LINE(2, 14264, 1);
	tmp_3 = -Acc;
	Acc = -LINE(2, 14264, 1) / 4 + LINE(1, 14261, 1);
	tmp_5 = -Acc;
	Acc = LINE(0, 0, 3) * 3 / 2 + LINE(20, 16089, 15) / 2;
	WRITE_LINE(20, 16089) = -Acc;
	Acc = -Acc / 2 + LINE(20, 16089, 15) + LINE(19, 16072, 22) / 2;
	WRITE_LINE(19, 16072) = -Acc;
	Acc = -Acc / 2 + LINE(19, 16072, 22) + LINE(18, 16048, 29) / 2;
	WRITE_LINE(18, 16048) = -Acc;
	Acc = -Acc / 2 + LINE(18, 16048, 29) + LINE(17, 16017, 45) / 2;
	WRITE_LINE(17, 16017) = -Acc;
	Acc = -Acc / 2 + LINE(17, 16017, 45) + LINE(16, 15970, 61) / 2;
	WRITE_LINE(16, 15970) = -Acc;
	Acc = -Acc / 2 + LINE(16, 15970, 61) + LINE(6, 14997, 105) / 2;
	WRITE_LINE(6, 14997) = -Acc;
	Acc = -Acc / 2 + LINE(6, 14997, 105) + LINE(5, 14890, 149) / 2;
	WRITE_LINE(5, 14890) = -Acc;
	Acc = -Acc / 2 + LINE(5, 14890, 149) + LINE(4, 14739, 213) / 2;
	WRITE_LINE(4, 14739) = -Acc;
	Acc = -Acc / 2 + LINE(4, 14739, 213) + LINE(3, 14524, 258) / 2;
	WRITE_LINE(3, 14524) = -Acc;
	Acc = -Acc / 2 + LINE(3, 14524, 258);
	WRITE_LINE(2, 14264) = -Acc;
	Acc = LINE(0, 0, 3) * 3 / 2 + LINE(11, 15210, 17) / 2;
	WRITE_LINE(11, 15210) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15210, 17) + LINE(10, 15191, 25) / 2;
	WRITE_LINE(10, 15191) = -Acc;
	Acc = -Acc / 2 + LINE(10, 15191, 25) + LINE(9, 15164, 35) / 2;
	WRITE_LINE(9, 15164) = -Acc;
	Acc = -Acc / 2 + LINE(9, 15164, 35) + LINE(8, 15127, 52) / 2;
	WRITE_LINE(8, 15127) = -Acc;
	Acc = -Acc / 2 + LINE(8, 15127, 52) + LINE(7, 15073, 74) / 2;
	WRITE_LINE(7, 15073) = -Acc;
	Acc = -Acc / 2 + LINE(7, 15073, 74) + LINE(15, 15907, 88) / 2;
	WRITE_LINE(15, 15907) = -Acc;
	Acc = -Acc / 2 + LINE(15, 15907, 88) + LINE(14, 15817, 123) / 2;
	WRITE_LINE(14, 15817) = -Acc;
	Acc = -Acc / 2 + LINE(14, 15817, 123) + LINE(13, 15692, 174) / 2;
	WRITE_LINE(13, 15692) = -Acc;
	Acc = -Acc / 2 + LINE(13, 15692, 174) + LINE(12, 15516, 304) / 2;
	WRITE_LINE(12, 15516) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15516, 304);
	WRITE_LINE(1, 14261) = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_97(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 16380, 5859);
	tmp_3 = -Acc;
	Acc = LINE(1, 16380, 5859);
	tmp_5 = -Acc;
	Acc = LINE(0, 0, 2) + LINE(1, 16380, 5859) / 2;
	WRITE_LINE(1, 16380) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_98(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 16380, 8789);
	tmp_3 = -Acc;
	Acc = LINE(1, 16380, 8789);
	tmp_5 = -Acc;
	Acc = LINE(0, 0, 2) + LINE(1, 16380, 8789) / 2;
	WRITE_LINE(1, 16380) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb2_effect_99(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 16380, 11718);
	tmp_3 = -Acc;
	Acc = LINE(1, 16380, 11718);
	tmp_5 = -Acc;
	Acc = LINE(0, 0, 2) + LINE(1, 16380, 11718) / 2;
	WRITE_LINE(1, 16380) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
void (*midiverb2_effects[])(int16_t input, int16_t *out_left, int16_t *out_right, int16_t *DRAM, int ptr, uint32_t lfo1_value, uint32_t lfo2_value) = {
	midiverb2_effect_0,
	midiverb2_effect_1,
	midiverb2_effect_2,
	midiverb2_effect_3,
	midiverb2_effect_4,
	midiverb2_effect_5,
	midiverb2_effect_6,
	midiverb2_effect_7,
	midiverb2_effect_8,
	midiverb2_effect_9,
	midiverb2_effect_10,
	midiverb2_effect_11,
	midiverb2_effect_12,
	midiverb2_effect_13,
	midiverb2_effect_14,
	midiverb2_effect_15,
	midiverb2_effect_16,
	midiverb2_effect_17,
	midiverb2_effect_18,
	midiverb2_effect_19,
	midiverb2_effect_20,
	midiverb2_effect_21,
	midiverb2_effect_22,
	midiverb2_effect_23,
	midiverb2_effect_24,
	midiverb2_effect_25,
	midiverb2_effect_26,
	midiverb2_effect_27,
	midiverb2_effect_28,
	midiverb2_effect_29,
	midiverb2_effect_30,
	midiverb2_effect_31,
	midiverb2_effect_32,
	midiverb2_effect_33,
	midiverb2_effect_34,
	midiverb2_effect_35,
	midiverb2_effect_36,
	midiverb2_effect_37,
	midiverb2_effect_38,
	midiverb2_effect_39,
	midiverb2_effect_40,
	midiverb2_effect_41,
	midiverb2_effect_42,
	midiverb2_effect_43,
	midiverb2_effect_44,
	midiverb2_effect_45,
	midiverb2_effect_46,
	midiverb2_effect_47,
	midiverb2_effect_48,
	midiverb2_effect_49,
	midiverb2_effect_50,
	midiverb2_effect_51,
	midiverb2_effect_52,
	midiverb2_effect_53,
	midiverb2_effect_54,
	midiverb2_effect_55,
	midiverb2_effect_56,
	midiverb2_effect_57,
	midiverb2_effect_58,
	midiverb2_effect_59,
	midiverb2_effect_60,
	midiverb2_effect_61,
	midiverb2_effect_62,
	midiverb2_effect_63,
	midiverb2_effect_64,
	midiverb2_effect_65,
	midiverb2_effect_66,
	midiverb2_effect_67,
	midiverb2_effect_68,
	midiverb2_effect_69,
	midiverb2_effect_70,
	midiverb2_effect_71,
	midiverb2_effect_72,
	midiverb2_effect_73,
	midiverb2_effect_74,
	midiverb2_effect_75,
	midiverb2_effect_76,
	midiverb2_effect_77,
	midiverb2_effect_78,
	midiverb2_effect_79,
	midiverb2_effect_80,
	midiverb2_effect_81,
	midiverb2_effect_82,
	midiverb2_effect_83,
	midiverb2_effect_84,
	midiverb2_effect_85,
	midiverb2_effect_86,
	midiverb2_effect_87,
	midiverb2_effect_88,
	midiverb2_effect_89,
	midiverb2_effect_90,
	midiverb2_effect_91,
	midiverb2_effect_92,
	midiverb2_effect_93,
	midiverb2_effect_94,
	midiverb2_effect_95,
	midiverb2_effect_96,
	midiverb2_effect_97,
	midiverb2_effect_98,
	midiverb2_effect_99,
};
