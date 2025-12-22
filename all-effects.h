// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=285, taps=[213, 285]
// Delay line 4: length=297, taps=[179, 297]
// Delay line 5: length=137, taps=[120, 137]
// Delay line 6: length=217, taps=[151, 217]
// Delay line 7: length=234, taps=[131, 234]
// Delay line 8: length=263, taps=[167, 263]
// Delay line 9: length=172, taps=[40, 172]
// Delay line 10: length=261, taps=[64, 261]
// Delay line 11: length=113, taps=[113]
// Delay line 12: length=89, taps=[89]
// Delay line 13: length=58, taps=[58]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_1(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp11, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 15992, 64) / 2 + LINE(7, 15290, 131) / 2 + LINE(5, 14835, 120) / 2 + LINE(4, 14696, 179) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp5 = Acc;
	Acc = LINE(9, 15729, 40) / 2 + LINE(8, 15555, 167) / 2 + LINE(6, 15054, 151) / 2 + LINE(3, 14397, 213) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp3 = Acc;
	Acc = LINE(13, 16381, 58) * 0.625 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 0.625 + WRITE_LINE(13, 16381) * 0.625 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 113) * 0.625 + WRITE_LINE(12, 16321) * 0.625 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -WRITE_LINE(11, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(11, 16230) / 2 + LINE(11, 16230, 113) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -1.6875 + tmp1 * 3.375;
	tmp11 = Acc;
	Acc = LINE(10, 15992, 261) / 2 + LINE(9, 15729, 172) / 2;
	WRITE_LINE(9, 15729) = -Acc;
	Acc = -Acc / 2 + LINE(9, 15729, 172);
	WRITE_LINE(8, 15555) = Acc;
	Acc = LINE(8, 15555, 263) / 2 + LINE(7, 15290, 234) / 2;
	WRITE_LINE(7, 15290) = -Acc;
	Acc = -Acc / 2 + LINE(7, 15290, 234);
	tmp1 = Acc;
	Acc = LINE(2, 14107, 1) / 2 + tmp1 / 2;
	WRITE_LINE(2, 14107) = Acc;
	Acc = LINE(2, 14107, 1) + tmp11;
	WRITE_LINE(10, 15992) = Acc;
	Acc = LINE(6, 15054, 217) / 2 + LINE(5, 14835, 137) / 2;
	WRITE_LINE(5, 14835) = -Acc;
	Acc = -Acc / 2 + LINE(5, 14835, 137);
	WRITE_LINE(4, 14696) = Acc;
	Acc = LINE(4, 14696, 297) / 2 + LINE(3, 14397, 285) / 2;
	WRITE_LINE(3, 14397) = -Acc;
	Acc = -Acc / 2 + LINE(3, 14397, 285);
	tmp1 = Acc;
	Acc = LINE(1, 14104, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 14104) = Acc;
	Acc = LINE(1, 14104, 1) + tmp11;
	WRITE_LINE(6, 15054) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=285, taps=[213, 285]
// Delay line 5: length=297, taps=[179, 297]
// Delay line 6: length=137, taps=[120, 137]
// Delay line 7: length=217, taps=[151, 217]
// Delay line 8: length=234, taps=[131, 234]
// Delay line 9: length=263, taps=[167, 263]
// Delay line 10: length=172, taps=[40, 172]
// Delay line 11: length=261, taps=[64, 261]
// Delay line 12: length=113, taps=[113]
// Delay line 13: length=89, taps=[89]
// Delay line 14: length=58, taps=[58]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_2(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp11, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(11, 15992, 64) / 2 + LINE(8, 15290, 131) / 2 + LINE(6, 14835, 120) / 2 + LINE(5, 14696, 179) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp5 = Acc;
	Acc = LINE(10, 15729, 40) / 2 + LINE(9, 15555, 167) / 2 + LINE(7, 15054, 151) / 2 + LINE(4, 14397, 213) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp3 = Acc;
	Acc = LINE(3, 14110, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(3, 14110) = Acc;
	Acc = LINE(14, 16381, 58) * 0.625 + LINE(3, 14110, 1) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = LINE(13, 16321, 89) * 0.625 + WRITE_LINE(14, 16381) * 0.625 + LINE(14, 16381, 58);
	WRITE_LINE(13, 16321) = -Acc;
	Acc = LINE(12, 16230, 113) * 0.625 + WRITE_LINE(13, 16321) * 0.625 + LINE(13, 16321, 89);
	WRITE_LINE(12, 16230) = -Acc;
	Acc = -WRITE_LINE(12, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(12, 16230) / 2 + LINE(12, 16230, 113) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -1.6875 + tmp1 * 3.375;
	tmp11 = Acc;
	Acc = LINE(11, 15992, 261) / 2 + LINE(10, 15729, 172) / 2;
	WRITE_LINE(10, 15729) = -Acc;
	Acc = -Acc / 2 + LINE(10, 15729, 172);
	WRITE_LINE(9, 15555) = Acc;
	Acc = LINE(9, 15555, 263) / 2 + LINE(8, 15290, 234) / 2;
	WRITE_LINE(8, 15290) = -Acc;
	Acc = -Acc / 2 + LINE(8, 15290, 234);
	tmp1 = Acc;
	Acc = LINE(2, 14107, 1) / 2 + tmp1 / 2;
	WRITE_LINE(2, 14107) = Acc;
	Acc = LINE(2, 14107, 1) + tmp11;
	WRITE_LINE(11, 15992) = Acc;
	Acc = LINE(7, 15054, 217) / 2 + LINE(6, 14835, 137) / 2;
	WRITE_LINE(6, 14835) = -Acc;
	Acc = -Acc / 2 + LINE(6, 14835, 137);
	WRITE_LINE(5, 14696) = Acc;
	Acc = LINE(5, 14696, 297) / 2 + LINE(4, 14397, 285) / 2;
	WRITE_LINE(4, 14397) = -Acc;
	Acc = -Acc / 2 + LINE(4, 14397, 285);
	tmp1 = Acc;
	Acc = LINE(1, 14104, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 14104) = Acc;
	Acc = LINE(1, 14104, 1) + tmp11;
	WRITE_LINE(7, 15054) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=485, taps=[485]
// Delay line 4: length=597, taps=[179, 512, 597]
// Delay line 5: length=337, taps=[337]
// Delay line 6: length=417, taps=[151, 339, 417]
// Delay line 7: length=434, taps=[434]
// Delay line 8: length=563, taps=[167, 396, 563]
// Delay line 9: length=372, taps=[372]
// Delay line 10: length=461, taps=[64, 303, 461]
// Delay line 11: length=183, taps=[183]
// Delay line 12: length=89, taps=[89]
// Delay line 13: length=58, taps=[58]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_3(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp11, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 15812, 64) / 2 + LINE(8, 14975, 396) / 2 + LINE(6, 13974, 339) / 2 + LINE(4, 13216, 179) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp5 = Acc;
	Acc = LINE(10, 15812, 303) / 2 + LINE(8, 14975, 167) / 2 + LINE(6, 13974, 151) / 2 + LINE(4, 13216, 512) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp3 = Acc;
	Acc = LINE(13, 16381, 58) * 0.625 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 0.625 + WRITE_LINE(13, 16381) * 0.625 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 183) * 0.625 + WRITE_LINE(12, 16321) * 0.625 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -WRITE_LINE(11, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(11, 16230) / 2 + LINE(11, 16230, 183) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -1.6875 + tmp1 * 3.375;
	tmp11 = Acc;
	Acc = LINE(10, 15812, 461) / 2 + LINE(9, 15349, 372) / 2;
	WRITE_LINE(9, 15349) = -Acc;
	Acc = -Acc / 2 + LINE(9, 15349, 372);
	WRITE_LINE(8, 14975) = Acc;
	Acc = -LINE(8, 14975, 563) / 4 + LINE(7, 14410, 434) / 2;
	WRITE_LINE(7, 14410) = -Acc;
	Acc = -Acc / 2 + LINE(7, 14410, 434);
	tmp1 = Acc;
	Acc = LINE(2, 12127, 1) / 2 + tmp1 / 2;
	WRITE_LINE(2, 12127) = Acc;
	Acc = LINE(2, 12127, 1) + tmp11;
	WRITE_LINE(10, 15812) = Acc;
	Acc = LINE(6, 13974, 417) / 2 + LINE(5, 13555, 337) / 2;
	WRITE_LINE(5, 13555) = -Acc;
	Acc = -Acc / 2 + LINE(5, 13555, 337);
	WRITE_LINE(4, 13216) = Acc;
	Acc = -LINE(4, 13216, 597) / 4 + LINE(3, 12617, 485) / 2;
	WRITE_LINE(3, 12617) = -Acc;
	Acc = -Acc / 2 + LINE(3, 12617, 485);
	tmp1 = Acc;
	Acc = LINE(1, 12124, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 12124) = Acc;
	Acc = LINE(1, 12124, 1) + tmp11;
	WRITE_LINE(6, 13974) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=385, taps=[113, 385]
// Delay line 4: length=397, taps=[179, 397]
// Delay line 5: length=337, taps=[337]
// Delay line 6: length=417, taps=[151, 339, 417]
// Delay line 7: length=234, taps=[234]
// Delay line 8: length=463, taps=[167, 396, 463]
// Delay line 9: length=272, taps=[272]
// Delay line 10: length=461, taps=[64, 303, 461]
// Delay line 11: length=103, taps=[103]
// Delay line 12: length=89, taps=[89]
// Delay line 13: length=58, taps=[58]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_4(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp11, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 15992, 64) / 2 + LINE(8, 15255, 396) / 2 + LINE(6, 14554, 339) / 2 + LINE(4, 13796, 179) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp5 = Acc;
	Acc = LINE(10, 15992, 303) / 2 + LINE(8, 15255, 167) / 2 + LINE(6, 14554, 151) / 2 + LINE(3, 13397, 113) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp3 = Acc;
	Acc = LINE(13, 16381, 58) * 0.625 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 0.625 + WRITE_LINE(13, 16381) * 0.625 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 103) * 0.625 + WRITE_LINE(12, 16321) * 0.625 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -WRITE_LINE(11, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(11, 16230) / 2 + LINE(11, 16230, 103) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -1.6875 + tmp1 * 3.375;
	tmp11 = Acc;
	Acc = LINE(10, 15992, 461) / 2 + LINE(9, 15529, 272) / 2;
	WRITE_LINE(9, 15529) = -Acc;
	Acc = -Acc / 2 + LINE(9, 15529, 272);
	WRITE_LINE(8, 15255) = Acc;
	Acc = LINE(8, 15255, 463) / 2 + LINE(7, 14790, 234) / 2;
	WRITE_LINE(7, 14790) = -Acc;
	Acc = -Acc / 2 + LINE(7, 14790, 234);
	tmp1 = Acc;
	Acc = LINE(2, 13007, 1) / 2 + tmp1 / 2;
	WRITE_LINE(2, 13007) = Acc;
	Acc = LINE(2, 13007, 1) + tmp11;
	WRITE_LINE(10, 15992) = Acc;
	Acc = LINE(6, 14554, 417) / 2 + LINE(5, 14135, 337) / 2;
	WRITE_LINE(5, 14135) = -Acc;
	Acc = -Acc / 2 + LINE(5, 14135, 337);
	WRITE_LINE(4, 13796) = Acc;
	Acc = LINE(4, 13796, 397) / 2 + LINE(3, 13397, 385) / 2;
	WRITE_LINE(3, 13397) = -Acc;
	Acc = -Acc / 2 + LINE(3, 13397, 385);
	tmp1 = Acc;
	Acc = LINE(1, 13004, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 13004) = Acc;
	Acc = LINE(1, 13004, 1) + tmp11;
	WRITE_LINE(6, 14554) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=485, taps=[485]
// Delay line 5: length=397, taps=[179, 212, 397]
// Delay line 6: length=337, taps=[337]
// Delay line 7: length=417, taps=[151, 339, 417]
// Delay line 8: length=434, taps=[434]
// Delay line 9: length=363, taps=[167, 196, 363]
// Delay line 10: length=372, taps=[372]
// Delay line 11: length=461, taps=[64, 303, 461]
// Delay line 12: length=103, taps=[103]
// Delay line 13: length=89, taps=[89]
// Delay line 14: length=58, taps=[58]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_5(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp11, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(11, 15978, 64) / 2 + LINE(9, 15141, 196) / 2 + LINE(7, 14340, 339) / 2 + LINE(5, 13582, 179) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp5 = Acc;
	Acc = LINE(11, 15978, 303) / 2 + LINE(9, 15141, 167) / 2 + LINE(7, 14340, 151) / 2 + LINE(5, 13582, 212) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp3 = Acc;
	Acc = LINE(3, 12696, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(3, 12696) = Acc;
	Acc = LINE(14, 16381, 58) * 0.625 + LINE(3, 12696, 1) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = LINE(13, 16321, 89) * 0.625 + WRITE_LINE(14, 16381) * 0.625 + LINE(14, 16381, 58);
	WRITE_LINE(13, 16321) = -Acc;
	Acc = LINE(12, 16230, 103) * 0.625 + WRITE_LINE(13, 16321) * 0.625 + LINE(13, 16321, 89);
	WRITE_LINE(12, 16230) = -Acc;
	Acc = -WRITE_LINE(12, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(12, 16230) / 2 + LINE(12, 16230, 103) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -1.6875 + tmp1 * 3.375;
	tmp11 = Acc;
	Acc = LINE(11, 15978, 461) / 2 + LINE(10, 15515, 372) / 2;
	WRITE_LINE(10, 15515) = -Acc;
	Acc = -Acc / 2 + LINE(10, 15515, 372);
	WRITE_LINE(9, 15141) = Acc;
	Acc = LINE(9, 15141, 363) / 2 + LINE(8, 14776, 434) / 2;
	WRITE_LINE(8, 14776) = -Acc;
	Acc = -Acc / 2 + LINE(8, 14776, 434);
	tmp1 = Acc;
	Acc = LINE(2, 12693, 1) / 2 + tmp1 / 2;
	WRITE_LINE(2, 12693) = Acc;
	Acc = LINE(2, 12693, 1) + tmp11;
	WRITE_LINE(11, 15978) = Acc;
	Acc = LINE(7, 14340, 417) / 2 + LINE(6, 13921, 337) / 2;
	WRITE_LINE(6, 13921) = -Acc;
	Acc = -Acc / 2 + LINE(6, 13921, 337);
	WRITE_LINE(5, 13582) = Acc;
	Acc = LINE(5, 13582, 397) / 2 + LINE(4, 13183, 485) / 2;
	WRITE_LINE(4, 13183) = -Acc;
	Acc = -Acc / 2 + LINE(4, 13183, 485);
	tmp1 = Acc;
	Acc = LINE(1, 12690, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 12690) = Acc;
	Acc = LINE(1, 12690, 1) + tmp11;
	WRITE_LINE(7, 14340) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=485, taps=[485]
// Delay line 4: length=597, taps=[179, 512, 597]
// Delay line 5: length=337, taps=[337]
// Delay line 6: length=417, taps=[151, 339, 417]
// Delay line 7: length=434, taps=[434]
// Delay line 8: length=563, taps=[167, 396, 563]
// Delay line 9: length=372, taps=[372]
// Delay line 10: length=461, taps=[64, 303, 461]
// Delay line 11: length=183, taps=[183]
// Delay line 12: length=89, taps=[89]
// Delay line 13: length=58, taps=[58]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_6(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp11, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 15812, 64) / 2 + LINE(8, 14975, 396) / 2 + LINE(6, 13974, 339) / 2 + LINE(4, 13216, 179) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp5 = Acc;
	Acc = LINE(10, 15812, 303) / 2 + LINE(8, 14975, 167) / 2 + LINE(6, 13974, 151) / 2 + LINE(4, 13216, 512) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp3 = Acc;
	Acc = LINE(13, 16381, 58) * 0.625 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 0.625 + WRITE_LINE(13, 16381) * 0.625 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 183) * 0.625 + WRITE_LINE(12, 16321) * 0.625 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -WRITE_LINE(11, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(11, 16230) / 2 + LINE(11, 16230, 183) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -1.6875 + tmp1 * 3.375;
	tmp11 = Acc;
	Acc = LINE(10, 15812, 461) / 2 + LINE(9, 15349, 372) / 2;
	WRITE_LINE(9, 15349) = -Acc;
	Acc = -Acc / 2 + LINE(9, 15349, 372);
	WRITE_LINE(8, 14975) = Acc;
	Acc = LINE(8, 14975, 563) / 2 + LINE(7, 14410, 434) / 2;
	WRITE_LINE(7, 14410) = -Acc;
	Acc = -Acc / 2 + LINE(7, 14410, 434);
	tmp1 = Acc;
	Acc = LINE(2, 12127, 1) / 2 + tmp1 / 2;
	WRITE_LINE(2, 12127) = Acc;
	Acc = LINE(2, 12127, 1) + tmp11;
	WRITE_LINE(10, 15812) = Acc;
	Acc = LINE(6, 13974, 417) / 2 + LINE(5, 13555, 337) / 2;
	WRITE_LINE(5, 13555) = -Acc;
	Acc = -Acc / 2 + LINE(5, 13555, 337);
	WRITE_LINE(4, 13216) = Acc;
	Acc = LINE(4, 13216, 597) / 2 + LINE(3, 12617, 485) / 2;
	WRITE_LINE(3, 12617) = -Acc;
	Acc = -Acc / 2 + LINE(3, 12617, 485);
	tmp1 = Acc;
	Acc = LINE(1, 12124, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 12124) = Acc;
	Acc = LINE(1, 12124, 1) + tmp11;
	WRITE_LINE(6, 13974) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=485, taps=[485]
// Delay line 5: length=597, taps=[179, 512, 597]
// Delay line 6: length=337, taps=[337]
// Delay line 7: length=417, taps=[151, 339, 417]
// Delay line 8: length=434, taps=[434]
// Delay line 9: length=563, taps=[167, 396, 563]
// Delay line 10: length=372, taps=[372]
// Delay line 11: length=461, taps=[64, 303, 461]
// Delay line 12: length=183, taps=[183]
// Delay line 13: length=89, taps=[89]
// Delay line 14: length=58, taps=[58]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_7(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp11, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(11, 15812, 64) / 4 + -LINE(9, 14975, 396) / 4 + -LINE(7, 13974, 339) / 4 + -LINE(5, 13216, 179) / 4;
	tmp5 = -Acc;
	Acc = -LINE(11, 15812, 303) / 4 + -LINE(9, 14975, 167) / 4 + -LINE(7, 13974, 151) / 4 + -LINE(5, 13216, 512) / 4;
	tmp3 = -Acc;
	Acc = LINE(3, 12130, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(3, 12130) = Acc;
	Acc = LINE(14, 16381, 58) * 0.625 + LINE(3, 12130, 1) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = LINE(13, 16321, 89) * 0.625 + WRITE_LINE(14, 16381) * 0.625 + LINE(14, 16381, 58);
	WRITE_LINE(13, 16321) = -Acc;
	Acc = LINE(12, 16230, 183) * 0.625 + WRITE_LINE(13, 16321) * 0.625 + LINE(13, 16321, 89);
	WRITE_LINE(12, 16230) = -Acc;
	Acc = -WRITE_LINE(12, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(12, 16230) / 2 + LINE(12, 16230, 183) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -1.6875 + tmp1 * 3.375;
	tmp11 = Acc;
	Acc = LINE(11, 15812, 461) / 2 + LINE(10, 15349, 372) / 2;
	WRITE_LINE(10, 15349) = -Acc;
	Acc = -Acc / 2 + LINE(10, 15349, 372);
	WRITE_LINE(9, 14975) = Acc;
	Acc = LINE(9, 14975, 563) / 2 + LINE(8, 14410, 434) / 2;
	WRITE_LINE(8, 14410) = -Acc;
	Acc = -Acc / 2 + LINE(8, 14410, 434);
	tmp1 = Acc;
	Acc = LINE(2, 12127, 1) / 2 + tmp1 / 2;
	WRITE_LINE(2, 12127) = Acc;
	Acc = LINE(2, 12127, 1) + tmp11;
	WRITE_LINE(11, 15812) = Acc;
	Acc = LINE(7, 13974, 417) / 2 + LINE(6, 13555, 337) / 2;
	WRITE_LINE(6, 13555) = -Acc;
	Acc = -Acc / 2 + LINE(6, 13555, 337);
	WRITE_LINE(5, 13216) = Acc;
	Acc = LINE(5, 13216, 597) / 2 + LINE(4, 12617, 485) / 2;
	WRITE_LINE(4, 12617) = -Acc;
	Acc = -Acc / 2 + LINE(4, 12617, 485);
	tmp1 = Acc;
	Acc = LINE(1, 12124, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 12124) = Acc;
	Acc = LINE(1, 12124, 1) + tmp11;
	WRITE_LINE(7, 13974) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=655, taps=[655]
// Delay line 4: length=597, taps=[151, 339, 597]
// Delay line 5: length=637, taps=[637]
// Delay line 6: length=617, taps=[617]
// Delay line 7: length=634, taps=[634]
// Delay line 8: length=683, taps=[167, 496, 683]
// Delay line 9: length=472, taps=[472]
// Delay line 10: length=601, taps=[64, 403, 601]
// Delay line 11: length=357, taps=[24, 183, 357]
// Delay line 12: length=89, taps=[89]
// Delay line 13: length=58, taps=[58]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_8(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5, tmp7, tmp11;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 15645, 64) / 2 + LINE(8, 14568, 496) / 2 + LINE(4, 11989, 339) / 2 + LINE(11, 16230, 24) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp5 = Acc;
	Acc = LINE(10, 15645, 403) / 2 + LINE(8, 14568, 167) / 2 + LINE(4, 11989, 151) / 2 + LINE(11, 16230, 357) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp3 = Acc;
	Acc = LINE(13, 16381, 58) * 0.625 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 0.625 + WRITE_LINE(13, 16381) * 0.625 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 183) * 0.625 + WRITE_LINE(12, 16321) * 0.625 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -WRITE_LINE(11, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(11, 16230) / 2 + LINE(11, 16230, 183) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -1.6875 + tmp1 * 3.375;
	tmp11 = Acc;
	Acc = LINE(10, 15645, 601) / 2 + LINE(9, 15042, 472) / 2;
	WRITE_LINE(9, 15042) = -Acc;
	Acc = -Acc / 2 + LINE(9, 15042, 472);
	WRITE_LINE(8, 14568) = Acc;
	Acc = LINE(8, 14568, 683) / 2 + LINE(7, 13883, 634) / 2;
	WRITE_LINE(7, 13883) = -Acc;
	Acc = Acc * -0.75 + LINE(7, 13883, 634) * 1.5;
	tmp1 = Acc;
	Acc = LINE(2, 10730, 1) / 4 + tmp1 / 2;
	WRITE_LINE(2, 10730) = Acc;
	Acc = LINE(2, 10730, 1) + tmp11;
	WRITE_LINE(10, 15645) = Acc;
	Acc = LINE(6, 13247, 617) / 2 + LINE(5, 12628, 637) / 2;
	WRITE_LINE(5, 12628) = -Acc;
	Acc = -Acc / 2 + LINE(5, 12628, 637);
	WRITE_LINE(4, 11989) = Acc;
	Acc = LINE(4, 11989, 597) / 2 + LINE(3, 11390, 655) / 2;
	WRITE_LINE(3, 11390) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 11390, 655) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 10727, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 10727) = Acc;
	*out_left = tmp5;
	Acc = LINE(1, 10727, 1) + tmp11;
	WRITE_LINE(6, 13247) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=100, taps=[100]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=1385, taps=[1385]
// Delay line 5: length=1483, taps=[301, 678, 1483]
// Delay line 6: length=1456, taps=[1456]
// Delay line 7: length=1034, taps=[1034]
// Delay line 8: length=1289, taps=[1289]
// Delay line 9: length=1369, taps=[342, 987, 1369]
// Delay line 10: length=1345, taps=[1345]
// Delay line 11: length=1203, taps=[123, 803, 1203]
// Delay line 12: length=789, taps=[789]
// Delay line 13: length=620, taps=[367, 620]
// Delay line 14: length=198, taps=[142, 198]
// Delay line 15: length=98, taps=[98]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_9(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5, tmp7, tmp11;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(11, 14322, 123) / 4 + -LINE(9, 11770, 987) / 4 + -LINE(5, 6614, 678) / 4 + -LINE(14, 16182, 142) / 4;
	tmp5 = -Acc;
	Acc = -LINE(11, 14322, 803) / 4 + -LINE(9, 11770, 342) / 4 + -LINE(5, 6614, 301) / 4 + -LINE(13, 15982, 620) / 4;
	tmp3 = -Acc;
	Acc = LINE(3, 3742, 1) / 2 + LINE(0, 0, 100) / 2;
	WRITE_LINE(3, 3742) = Acc;
	Acc = LINE(15, 16282, 98) * 0.625 + LINE(3, 3742, 1) / 2;
	WRITE_LINE(15, 16282) = -Acc;
	Acc = LINE(14, 16182, 198) * 0.625 + WRITE_LINE(15, 16282) * 0.625 + LINE(15, 16282, 98);
	WRITE_LINE(14, 16182) = -Acc;
	Acc = LINE(13, 15982, 367) * 0.625 + WRITE_LINE(14, 16182) * 0.625 + LINE(14, 16182, 198);
	WRITE_LINE(13, 15982) = -Acc;
	Acc = WRITE_LINE(13, 15982) * 0.625 + LINE(13, 15982, 367) + LINE(12, 15113, 789) / 2;
	WRITE_LINE(12, 15113) = -Acc;
	Acc = Acc * -1.6875 + LINE(12, 15113, 789) * 3.375;
	tmp11 = Acc;
	Acc = -LINE(11, 14322, 1203) / 4 + LINE(10, 13117, 1345) / 2;
	WRITE_LINE(10, 13117) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13117, 1345);
	WRITE_LINE(9, 11770) = Acc;
	Acc = -LINE(9, 11770, 1369) / 4 + LINE(8, 10399, 1289) / 2;
	WRITE_LINE(8, 10399) = -Acc;
	Acc = Acc * -0.75 + LINE(8, 10399, 1289) * 1.5;
	tmp1 = Acc;
	Acc = LINE(2, 3739, 1) / 4 + tmp1 / 2;
	WRITE_LINE(2, 3739) = Acc;
	Acc = LINE(2, 3739, 1) + tmp11;
	WRITE_LINE(11, 14322) = Acc;
	Acc = -LINE(7, 9108, 1034) / 4 + LINE(6, 8072, 1456) / 2;
	WRITE_LINE(6, 8072) = -Acc;
	Acc = -Acc / 2 + LINE(6, 8072, 1456);
	WRITE_LINE(5, 6614) = Acc;
	Acc = -LINE(5, 6614, 1483) / 4 + LINE(4, 5129, 1385) / 2;
	WRITE_LINE(4, 5129) = -Acc;
	Acc = Acc * -0.75 + LINE(4, 5129, 1385) * 1.5;
	tmp1 = Acc;
	*out_left = tmp5;
	Acc = LINE(1, 3736, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 3736) = Acc;
	Acc = LINE(1, 3736, 1) + tmp11;
	WRITE_LINE(7, 9108) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=100, taps=[100]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=1385, taps=[1385]
// Delay line 5: length=1483, taps=[301, 678, 1483]
// Delay line 6: length=1456, taps=[1456]
// Delay line 7: length=1034, taps=[1034]
// Delay line 8: length=1289, taps=[1289]
// Delay line 9: length=1369, taps=[342, 987, 1369]
// Delay line 10: length=1345, taps=[1345]
// Delay line 11: length=1203, taps=[123, 503, 1203]
// Delay line 12: length=789, taps=[789]
// Delay line 13: length=620, taps=[367, 620]
// Delay line 14: length=198, taps=[142, 198]
// Delay line 15: length=98, taps=[98]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_10(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5, tmp7, tmp11;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(11, 14322, 123) / 4 + -LINE(9, 11770, 987) / 4 + -LINE(5, 6614, 678) / 4 + -LINE(14, 16182, 142) / 4;
	tmp5 = -Acc;
	Acc = -LINE(11, 14322, 503) / 4 + -LINE(9, 11770, 342) / 4 + -LINE(5, 6614, 301) / 4 + -LINE(13, 15982, 620) / 4;
	tmp3 = -Acc;
	Acc = LINE(3, 3742, 1) * 0.75 + LINE(0, 0, 100) / 2;
	WRITE_LINE(3, 3742) = Acc;
	Acc = LINE(15, 16282, 98) * 0.625 + LINE(3, 3742, 1) / 2;
	WRITE_LINE(15, 16282) = -Acc;
	Acc = LINE(14, 16182, 198) * 0.625 + WRITE_LINE(15, 16282) * 0.625 + LINE(15, 16282, 98);
	WRITE_LINE(14, 16182) = -Acc;
	Acc = LINE(13, 15982, 367) * 0.625 + WRITE_LINE(14, 16182) * 0.625 + LINE(14, 16182, 198);
	WRITE_LINE(13, 15982) = -Acc;
	Acc = WRITE_LINE(13, 15982) * 0.625 + LINE(13, 15982, 367) + LINE(12, 15113, 789) / 2;
	WRITE_LINE(12, 15113) = -Acc;
	Acc = Acc * -1.6875 + LINE(12, 15113, 789) * 3.375;
	tmp11 = Acc;
	Acc = -LINE(11, 14322, 1203) / 4 + LINE(10, 13117, 1345) / 2;
	WRITE_LINE(10, 13117) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13117, 1345);
	WRITE_LINE(9, 11770) = Acc;
	Acc = -LINE(9, 11770, 1369) / 4 + LINE(8, 10399, 1289) / 2;
	WRITE_LINE(8, 10399) = -Acc;
	Acc = Acc * -0.75 + LINE(8, 10399, 1289) * 1.5;
	tmp1 = Acc;
	Acc = LINE(2, 3739, 1) / 4 + tmp1 / 2;
	WRITE_LINE(2, 3739) = Acc;
	Acc = LINE(2, 3739, 1) + tmp11;
	WRITE_LINE(11, 14322) = Acc;
	Acc = -LINE(7, 9108, 1034) / 4 + LINE(6, 8072, 1456) / 2;
	WRITE_LINE(6, 8072) = -Acc;
	Acc = -Acc / 2 + LINE(6, 8072, 1456);
	WRITE_LINE(5, 6614) = Acc;
	Acc = -LINE(5, 6614, 1483) / 4 + LINE(4, 5129, 1385) / 2;
	WRITE_LINE(4, 5129) = -Acc;
	Acc = Acc * -0.75 + LINE(4, 5129, 1385) * 1.5;
	tmp1 = Acc;
	*out_left = tmp5;
	Acc = LINE(1, 3736, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 3736) = Acc;
	Acc = LINE(1, 3736, 1) + tmp11;
	WRITE_LINE(7, 9108) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=655, taps=[655]
// Delay line 4: length=567, taps=[151, 339, 567]
// Delay line 5: length=637, taps=[637]
// Delay line 6: length=617, taps=[617]
// Delay line 7: length=634, taps=[634]
// Delay line 8: length=783, taps=[167, 496, 783]
// Delay line 9: length=472, taps=[472]
// Delay line 10: length=701, taps=[64, 403, 701]
// Delay line 11: length=357, taps=[24, 183, 357]
// Delay line 12: length=89, taps=[89]
// Delay line 13: length=58, taps=[58]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_11(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5, tmp7, tmp11;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(10, 15645, 64) / 4 + -LINE(8, 14468, 496) / 4 + -LINE(4, 11789, 339) / 4 + -LINE(11, 16230, 24) / 4;
	tmp5 = -Acc;
	Acc = -LINE(10, 15645, 403) / 4 + -LINE(8, 14468, 167) / 4 + -LINE(4, 11789, 151) / 4 + -LINE(11, 16230, 357) / 4;
	tmp3 = -Acc;
	Acc = LINE(13, 16381, 58) * 0.625 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 0.625 + WRITE_LINE(13, 16381) * 0.625 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 183) * 0.625 + WRITE_LINE(12, 16321) * 0.625 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -WRITE_LINE(11, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(11, 16230) / 2 + LINE(11, 16230, 183) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -1.6875 + tmp1 * 3.375;
	tmp11 = Acc;
	Acc = LINE(10, 15645, 701) * 0.625 + LINE(9, 14942, 472) / 2;
	WRITE_LINE(9, 14942) = -Acc;
	Acc = -Acc / 2 + LINE(9, 14942, 472);
	WRITE_LINE(8, 14468) = Acc;
	Acc = LINE(8, 14468, 783) * 0.625 + LINE(7, 13683, 634) / 2;
	WRITE_LINE(7, 13683) = -Acc;
	Acc = Acc * -0.75 + LINE(7, 13683, 634) * 1.5;
	tmp1 = Acc;
	Acc = LINE(2, 10560, 1) / 4 + tmp1 / 2;
	WRITE_LINE(2, 10560) = Acc;
	Acc = LINE(2, 10560, 1) + tmp11;
	WRITE_LINE(10, 15645) = Acc;
	Acc = LINE(6, 13047, 617) * 0.625 + LINE(5, 12428, 637) / 2;
	WRITE_LINE(5, 12428) = -Acc;
	Acc = -Acc / 2 + LINE(5, 12428, 637);
	WRITE_LINE(4, 11789) = Acc;
	Acc = LINE(4, 11789, 567) * 0.625 + LINE(3, 11220, 655) / 2;
	WRITE_LINE(3, 11220) = -Acc;
	*out_left = tmp5;
	Acc = Acc * -0.75 + LINE(3, 11220, 655) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 10557, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 10557) = Acc;
	Acc = LINE(1, 10557, 1) + tmp11;
	WRITE_LINE(6, 13047) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2612, taps=[2612]
// Delay line 4: length=2057, taps=[671, 1203, 2057]
// Delay line 5: length=2371, taps=[2371]
// Delay line 6: length=2010, taps=[890, 1591, 2010]
// Delay line 7: length=1992, taps=[1992]
// Delay line 8: length=1424, taps=[21, 801, 1424]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1120, taps=[1120]
// Delay line 12: length=868, taps=[868]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_12(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 13241, 21) / 2 + LINE(6, 9821, 1591) / 2 + LINE(4, 5436, 1203) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp3 = Acc;
	Acc = LINE(8, 13241, 801) / 2 + LINE(6, 9821, 890) / 2 + LINE(4, 5436, 671) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp5 = Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 763, 1) / 2;
	WRITE_LINE(2, 763) = Acc;
	Acc = LINE(2, 763, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 868) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 868) + LINE(11, 14755, 1120) / 2;
	WRITE_LINE(11, 14755) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14755, 1120) + LINE(10, 13633, 234) / 2;
	WRITE_LINE(10, 13633) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13633, 234) + LINE(9, 13397, 154) / 2;
	WRITE_LINE(9, 13397) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13397, 154);
	tmp2 = Acc;
	Acc = -LINE(8, 13241, 1424) / 4 + LINE(7, 11815, 1992) / 2;
	WRITE_LINE(7, 11815) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11815, 1992) + LINE(1, 760, 1) / 2;
	WRITE_LINE(1, 760) = Acc;
	Acc = WRITE_LINE(1, 760);
	WRITE_LINE(6, 9821) = Acc;
	Acc = -LINE(6, 9821, 2010) / 4 + LINE(5, 7809, 2371) / 2;
	WRITE_LINE(5, 7809) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7809, 2371);
	WRITE_LINE(4, 5436) = Acc;
	Acc = -LINE(4, 5436, 2057) / 4 + LINE(3, 3377, 2612) / 2;
	WRITE_LINE(3, 3377) = -Acc;
	Acc = -Acc / 2 + LINE(3, 3377, 2612) + tmp2;
	WRITE_LINE(8, 13241) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=555, taps=[555]
// Delay line 5: length=697, taps=[151, 339, 697]
// Delay line 6: length=507, taps=[507]
// Delay line 7: length=417, taps=[417]
// Delay line 8: length=534, taps=[534]
// Delay line 9: length=683, taps=[167, 496, 683]
// Delay line 10: length=372, taps=[372]
// Delay line 11: length=501, taps=[64, 403, 501]
// Delay line 12: length=357, taps=[24, 183, 357]
// Delay line 13: length=89, taps=[89]
// Delay line 14: length=58, taps=[58]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_13(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5, tmp7, tmp11;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(11, 15785, 64) / 4 + -LINE(9, 14908, 496) / 4 + -LINE(5, 12759, 339) / 4 + -LINE(12, 16230, 24) / 4;
	tmp5 = -Acc;
	Acc = -LINE(11, 15785, 403) / 4 + -LINE(9, 14908, 167) / 4 + -LINE(5, 12759, 151) / 4 + -LINE(12, 16230, 357) / 4;
	tmp3 = -Acc;
	Acc = LINE(3, 11503, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(3, 11503) = Acc;
	Acc = LINE(14, 16381, 58) * 0.625 + LINE(3, 11503, 1) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = LINE(13, 16321, 89) * 0.625 + WRITE_LINE(14, 16381) * 0.625 + LINE(14, 16381, 58);
	WRITE_LINE(13, 16321) = -Acc;
	Acc = LINE(12, 16230, 183) * 0.625 + WRITE_LINE(13, 16321) * 0.625 + LINE(13, 16321, 89);
	WRITE_LINE(12, 16230) = -Acc;
	Acc = -WRITE_LINE(12, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(12, 16230) / 2 + LINE(12, 16230, 183) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -1.6875 + tmp1 * 3.375;
	tmp11 = Acc;
	Acc = LINE(11, 15785, 501) * 0.75 + LINE(10, 15282, 372) / 2;
	WRITE_LINE(10, 15282) = -Acc;
	Acc = -Acc / 2 + LINE(10, 15282, 372);
	WRITE_LINE(9, 14908) = Acc;
	Acc = LINE(9, 14908, 683) * 0.75 + LINE(8, 14223, 534) / 2;
	WRITE_LINE(8, 14223) = -Acc;
	Acc = Acc * -0.75 + LINE(8, 14223, 534) * 1.5;
	tmp1 = Acc;
	Acc = LINE(2, 11500, 1) / 4 + tmp1 / 2;
	WRITE_LINE(2, 11500) = Acc;
	Acc = LINE(2, 11500, 1) + tmp11;
	WRITE_LINE(11, 15785) = Acc;
	Acc = LINE(7, 13687, 417) * 0.75 + LINE(6, 13268, 507) / 2;
	WRITE_LINE(6, 13268) = -Acc;
	Acc = -Acc / 2 + LINE(6, 13268, 507);
	WRITE_LINE(5, 12759) = Acc;
	Acc = LINE(5, 12759, 697) * 0.75 + LINE(4, 12060, 555) / 2;
	WRITE_LINE(4, 12060) = -Acc;
	Acc = Acc * -0.75 + LINE(4, 12060, 555) * 1.5;
	tmp1 = Acc;
	*out_left = tmp5;
	Acc = LINE(1, 11497, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 11497) = Acc;
	Acc = LINE(1, 11497, 1) + tmp11;
	WRITE_LINE(7, 13687) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=100, taps=[100]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=1385, taps=[1385]
// Delay line 5: length=1683, taps=[301, 678, 1683]
// Delay line 6: length=1056, taps=[1056]
// Delay line 7: length=1004, taps=[1004]
// Delay line 8: length=1339, taps=[1339]
// Delay line 9: length=1569, taps=[342, 987, 1569]
// Delay line 10: length=1145, taps=[1145]
// Delay line 11: length=1203, taps=[123, 803, 1203]
// Delay line 12: length=875, taps=[875]
// Delay line 13: length=620, taps=[367, 620]
// Delay line 14: length=198, taps=[142, 198]
// Delay line 15: length=98, taps=[98]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_14(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5, tmp7, tmp11;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(11, 14236, 123) / 2 + LINE(9, 11884, 987) / 2 + LINE(5, 6908, 678) / 2 + LINE(14, 16182, 142) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp5 = Acc;
	Acc = LINE(11, 14236, 803) / 2 + LINE(9, 11884, 342) / 2 + LINE(5, 6908, 301) / 2 + LINE(13, 15982, 620) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp3 = Acc;
	Acc = LINE(3, 3836, 1) / 2 + LINE(0, 0, 100) / 2;
	WRITE_LINE(3, 3836) = Acc;
	Acc = LINE(15, 16282, 98) * 0.625 + LINE(3, 3836, 1) / 2;
	WRITE_LINE(15, 16282) = -Acc;
	Acc = LINE(14, 16182, 198) * 0.625 + WRITE_LINE(15, 16282) * 0.625 + LINE(15, 16282, 98);
	WRITE_LINE(14, 16182) = -Acc;
	Acc = LINE(13, 15982, 367) * 0.625 + WRITE_LINE(14, 16182) * 0.625 + LINE(14, 16182, 198);
	WRITE_LINE(13, 15982) = -Acc;
	Acc = WRITE_LINE(13, 15982) * 0.625 + LINE(13, 15982, 367) + LINE(12, 15113, 875) / 2;
	WRITE_LINE(12, 15113) = -Acc;
	Acc = Acc * -1.6875 + LINE(12, 15113, 875) * 3.375;
	tmp11 = Acc;
	Acc = LINE(11, 14236, 1203) / 2 + LINE(10, 13031, 1145) / 2;
	WRITE_LINE(10, 13031) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13031, 1145);
	WRITE_LINE(9, 11884) = Acc;
	Acc = LINE(9, 11884, 1569) / 2 + LINE(8, 10313, 1339) / 2;
	WRITE_LINE(8, 10313) = -Acc;
	Acc = Acc * -0.75 + LINE(8, 10313, 1339) * 1.5;
	tmp1 = Acc;
	Acc = LINE(2, 3833, 1) / 4 + tmp1 / 2;
	WRITE_LINE(2, 3833) = Acc;
	Acc = LINE(2, 3833, 1) + tmp11;
	WRITE_LINE(11, 14236) = Acc;
	Acc = LINE(7, 8972, 1004) / 2 + LINE(6, 7966, 1056) / 2;
	WRITE_LINE(6, 7966) = -Acc;
	Acc = -Acc / 2 + LINE(6, 7966, 1056);
	WRITE_LINE(5, 6908) = Acc;
	Acc = LINE(5, 6908, 1683) / 2 + LINE(4, 5223, 1385) / 2;
	WRITE_LINE(4, 5223) = -Acc;
	Acc = Acc * -0.75 + LINE(4, 5223, 1385) * 1.5;
	tmp1 = Acc;
	*out_left = tmp5;
	Acc = LINE(1, 3830, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 3830) = Acc;
	Acc = LINE(1, 3830, 1) + tmp11;
	WRITE_LINE(7, 8972) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=100, taps=[100]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1785, taps=[1785]
// Delay line 4: length=1983, taps=[301, 678, 1983]
// Delay line 5: length=1456, taps=[1456]
// Delay line 6: length=1034, taps=[1034]
// Delay line 7: length=1789, taps=[1789]
// Delay line 8: length=1569, taps=[342, 987, 1569]
// Delay line 9: length=1345, taps=[1345]
// Delay line 10: length=1203, taps=[123, 803, 1203]
// Delay line 11: length=1256, taps=[1256]
// Delay line 12: length=620, taps=[367, 620]
// Delay line 13: length=198, taps=[142, 198]
// Delay line 14: length=98, taps=[98]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_15(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5, tmp7, tmp11;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(10, 13855, 123) / 4 + -LINE(8, 11303, 987) / 4 + -LINE(4, 5447, 678) / 4 + -LINE(13, 16182, 142) / 4;
	tmp5 = -Acc;
	Acc = -LINE(10, 13855, 803) / 4 + -LINE(8, 11303, 342) / 4 + -LINE(4, 5447, 301) / 4 + -LINE(12, 15982, 620) / 4;
	tmp3 = -Acc;
	Acc = LINE(14, 16282, 98) * 0.625 + LINE(0, 0, 100) / 2;
	WRITE_LINE(14, 16282) = -Acc;
	Acc = LINE(13, 16182, 198) * 0.625 + WRITE_LINE(14, 16282) * 0.625 + LINE(14, 16282, 98);
	WRITE_LINE(13, 16182) = -Acc;
	Acc = LINE(12, 15982, 367) * 0.625 + WRITE_LINE(13, 16182) * 0.625 + LINE(13, 16182, 198);
	WRITE_LINE(12, 15982) = -Acc;
	Acc = WRITE_LINE(12, 15982) * 0.625 + LINE(12, 15982, 367) + LINE(11, 15113, 1256) / 2;
	WRITE_LINE(11, 15113) = -Acc;
	Acc = Acc * -1.6875 + LINE(11, 15113, 1256) * 3.375;
	tmp11 = Acc;
	Acc = LINE(10, 13855, 1203) + LINE(9, 12650, 1345) / 2;
	WRITE_LINE(9, 12650) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12650, 1345);
	WRITE_LINE(8, 11303) = Acc;
	Acc = -LINE(8, 11303, 1569) / 4 + LINE(7, 9732, 1789) / 2;
	WRITE_LINE(7, 9732) = -Acc;
	Acc = Acc * -0.75 + LINE(7, 9732, 1789) * 1.5;
	tmp1 = Acc;
	Acc = LINE(2, 1672, 1) / 4 + tmp1 / 2;
	WRITE_LINE(2, 1672) = Acc;
	Acc = LINE(2, 1672, 1) + tmp11;
	WRITE_LINE(10, 13855) = Acc;
	Acc = LINE(6, 7941, 1034) + LINE(5, 6905, 1456) / 2;
	WRITE_LINE(5, 6905) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6905, 1456);
	WRITE_LINE(4, 5447) = Acc;
	Acc = -LINE(4, 5447, 1983) / 4 + LINE(3, 3462, 1785) / 2;
	WRITE_LINE(3, 3462) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 3462, 1785) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 1669, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 1669) = Acc;
	*out_left = tmp5;
	Acc = LINE(1, 1669, 1) + tmp11;
	WRITE_LINE(6, 7941) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=100, taps=[100]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=1785, taps=[1785]
// Delay line 5: length=1983, taps=[301, 678, 1983]
// Delay line 6: length=1456, taps=[1456]
// Delay line 7: length=1034, taps=[1034]
// Delay line 8: length=1789, taps=[1789]
// Delay line 9: length=1569, taps=[342, 987, 1569]
// Delay line 10: length=1345, taps=[1345]
// Delay line 11: length=1203, taps=[123, 803, 1203]
// Delay line 12: length=987, taps=[987]
// Delay line 13: length=620, taps=[367, 620]
// Delay line 14: length=198, taps=[142, 198]
// Delay line 15: length=98, taps=[98]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_16(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5, tmp7, tmp11;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(11, 14124, 123) / 4 + -LINE(9, 11572, 987) / 4 + -LINE(5, 5716, 678) / 4 + -LINE(14, 16182, 142) / 4;
	tmp5 = -Acc;
	Acc = -LINE(11, 14124, 803) / 4 + -LINE(9, 11572, 342) / 4 + -LINE(5, 5716, 301) / 4 + -LINE(13, 15982, 620) / 4;
	tmp3 = -Acc;
	Acc = LINE(3, 1944, 1) / 2 + LINE(0, 0, 100) / 2;
	WRITE_LINE(3, 1944) = Acc;
	Acc = LINE(15, 16282, 98) * 0.625 + WRITE_LINE(3, 1944) / 2;
	WRITE_LINE(15, 16282) = -Acc;
	Acc = LINE(14, 16182, 198) * 0.625 + WRITE_LINE(15, 16282) * 0.625 + LINE(15, 16282, 98);
	WRITE_LINE(14, 16182) = -Acc;
	Acc = LINE(13, 15982, 367) * 0.625 + WRITE_LINE(14, 16182) * 0.625 + LINE(14, 16182, 198);
	WRITE_LINE(13, 15982) = -Acc;
	Acc = WRITE_LINE(13, 15982) * 0.625 + LINE(13, 15982, 367) + LINE(12, 15113, 987) / 2;
	WRITE_LINE(12, 15113) = -Acc;
	Acc = Acc * -1.6875 + LINE(12, 15113, 987) * 3.375;
	tmp11 = Acc;
	Acc = LINE(11, 14124, 1203) * 0.75 + LINE(10, 12919, 1345) / 2;
	WRITE_LINE(10, 12919) = -Acc;
	Acc = -Acc / 2 + LINE(10, 12919, 1345);
	WRITE_LINE(9, 11572) = Acc;
	Acc = LINE(9, 11572, 1569) / 2 + LINE(8, 10001, 1789) / 2;
	WRITE_LINE(8, 10001) = -Acc;
	Acc = Acc * -0.75 + LINE(8, 10001, 1789) * 1.5;
	tmp1 = Acc;
	Acc = LINE(2, 1941, 1) / 4 + tmp1 / 2;
	WRITE_LINE(2, 1941) = Acc;
	Acc = LINE(2, 1941, 1) + tmp11;
	WRITE_LINE(11, 14124) = Acc;
	Acc = LINE(7, 8210, 1034) * 0.75 + LINE(6, 7174, 1456) / 2;
	WRITE_LINE(6, 7174) = -Acc;
	Acc = -Acc / 2 + LINE(6, 7174, 1456);
	WRITE_LINE(5, 5716) = Acc;
	Acc = LINE(5, 5716, 1983) / 2 + LINE(4, 3731, 1785) / 2;
	WRITE_LINE(4, 3731) = -Acc;
	Acc = Acc * -0.75 + LINE(4, 3731, 1785) * 1.5;
	tmp1 = Acc;
	*out_left = tmp5;
	Acc = LINE(1, 1938, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 1938) = Acc;
	Acc = LINE(1, 1938, 1) + tmp11;
	WRITE_LINE(7, 8210) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=100, taps=[100]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=985, taps=[985]
// Delay line 5: length=1183, taps=[301, 745, 1183]
// Delay line 6: length=1256, taps=[1256]
// Delay line 7: length=1034, taps=[12, 978, 1034]
// Delay line 8: length=1289, taps=[1289]
// Delay line 9: length=1269, taps=[342, 987, 1269]
// Delay line 10: length=1045, taps=[1045]
// Delay line 11: length=798, taps=[12, 523, 798]
// Delay line 12: length=367, taps=[367]
// Delay line 13: length=147, taps=[147]
// Delay line 14: length=78, taps=[78]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_17(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5, tmp7, tmp11;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(11, 15084, 12) / 4 + -LINE(9, 13237, 987) / 4 + -LINE(7, 10675, 978) / 4 + -LINE(5, 8381, 745) / 4;
	tmp5 = -Acc;
	Acc = -LINE(11, 15084, 523) / 4 + -LINE(9, 13237, 342) / 4 + -LINE(7, 10675, 12) / 4 + -LINE(5, 8381, 301) / 4;
	tmp3 = -Acc;
	Acc = LINE(3, 6209, 1) / 2 + LINE(0, 0, 100) / 2;
	WRITE_LINE(3, 6209) = Acc;
	Acc = LINE(14, 16282, 78) * 0.625 + LINE(3, 6209, 1) / 2;
	WRITE_LINE(14, 16282) = -Acc;
	Acc = LINE(13, 16202, 147) * 0.625 + WRITE_LINE(14, 16282) * 0.625 + LINE(14, 16282, 78);
	WRITE_LINE(13, 16202) = -Acc;
	Acc = LINE(12, 16053, 367) * 0.625 + WRITE_LINE(13, 16202) * 0.625 + LINE(13, 16202, 147);
	WRITE_LINE(12, 16053) = -Acc;
	Acc = WRITE_LINE(12, 16053) * 2.109375 + LINE(12, 16053, 367) * 3.375;
	tmp11 = Acc;
	Acc = LINE(11, 15084, 798) * 0.75 + LINE(10, 14284, 1045) / 2;
	WRITE_LINE(10, 14284) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14284, 1045);
	WRITE_LINE(9, 13237) = Acc;
	Acc = LINE(9, 13237, 1269) * 0.75 + LINE(8, 11966, 1289) / 2;
	WRITE_LINE(8, 11966) = -Acc;
	Acc = Acc * -0.75 + LINE(8, 11966, 1289) * 1.5;
	tmp1 = Acc;
	Acc = LINE(2, 6206, 1) / 4 + tmp1 / 2;
	WRITE_LINE(2, 6206) = Acc;
	Acc = LINE(2, 6206, 1) + tmp11;
	WRITE_LINE(11, 15084) = Acc;
	Acc = LINE(7, 10675, 1034) * 0.75 + LINE(6, 9639, 1256) / 2;
	WRITE_LINE(6, 9639) = -Acc;
	Acc = -Acc / 2 + LINE(6, 9639, 1256);
	WRITE_LINE(5, 8381) = Acc;
	Acc = LINE(5, 8381, 1183) * 0.75 + LINE(4, 7196, 985) / 2;
	WRITE_LINE(4, 7196) = -Acc;
	Acc = Acc * -0.75 + LINE(4, 7196, 985) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 6203, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 6203) = Acc;
	*out_left = tmp5;
	Acc = LINE(1, 6203, 1) + tmp11;
	WRITE_LINE(7, 10675) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=100, taps=[100]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=985, taps=[985]
// Delay line 4: length=1183, taps=[301, 745, 1183]
// Delay line 5: length=1256, taps=[1256]
// Delay line 6: length=1034, taps=[12, 978, 1034]
// Delay line 7: length=1289, taps=[1289]
// Delay line 8: length=1269, taps=[342, 987, 1269]
// Delay line 9: length=1045, taps=[1045]
// Delay line 10: length=798, taps=[12, 523, 798]
// Delay line 11: length=367, taps=[367]
// Delay line 12: length=147, taps=[147]
// Delay line 13: length=78, taps=[78]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_18(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5, tmp7, tmp11;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(10, 15084, 12) / 4 + -LINE(8, 13237, 987) / 4 + -LINE(6, 10675, 978) / 4 + -LINE(4, 8381, 745) / 4;
	tmp5 = -Acc;
	Acc = -LINE(10, 15084, 523) / 4 + -LINE(8, 13237, 342) / 4 + -LINE(6, 10675, 12) / 4 + -LINE(4, 8381, 301) / 4;
	tmp3 = -Acc;
	Acc = LINE(13, 16282, 78) * 0.625 + LINE(0, 0, 100) / 2;
	WRITE_LINE(13, 16282) = -Acc;
	Acc = LINE(12, 16202, 147) * 0.625 + WRITE_LINE(13, 16282) * 0.625 + LINE(13, 16282, 78);
	WRITE_LINE(12, 16202) = -Acc;
	Acc = LINE(11, 16053, 367) * 0.625 + WRITE_LINE(12, 16202) * 0.625 + LINE(12, 16202, 147);
	WRITE_LINE(11, 16053) = -Acc;
	Acc = WRITE_LINE(11, 16053) * 2.109375 + LINE(11, 16053, 367) * 3.375;
	tmp11 = Acc;
	Acc = LINE(10, 15084, 798) * 0.75 + LINE(9, 14284, 1045) / 2;
	WRITE_LINE(9, 14284) = -Acc;
	Acc = -Acc / 2 + LINE(9, 14284, 1045);
	WRITE_LINE(8, 13237) = Acc;
	Acc = LINE(8, 13237, 1269) * 0.75 + LINE(7, 11966, 1289) / 2;
	WRITE_LINE(7, 11966) = -Acc;
	Acc = Acc * -0.75 + LINE(7, 11966, 1289) * 1.5;
	tmp1 = Acc;
	Acc = LINE(2, 6206, 1) / 4 + tmp1 / 2;
	WRITE_LINE(2, 6206) = Acc;
	Acc = LINE(2, 6206, 1) + tmp11;
	WRITE_LINE(10, 15084) = Acc;
	Acc = LINE(6, 10675, 1034) * 0.75 + LINE(5, 9639, 1256) / 2;
	WRITE_LINE(5, 9639) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9639, 1256);
	WRITE_LINE(4, 8381) = Acc;
	Acc = LINE(4, 8381, 1183) * 0.75 + LINE(3, 7196, 985) / 2;
	WRITE_LINE(3, 7196) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 7196, 985) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 6203, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 6203) = Acc;
	*out_left = tmp5;
	Acc = LINE(1, 6203, 1) + tmp11;
	WRITE_LINE(6, 10675) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2212, taps=[2212]
// Delay line 4: length=1857, taps=[471, 1403, 1857]
// Delay line 5: length=2071, taps=[2071]
// Delay line 6: length=1910, taps=[690, 1391, 1910]
// Delay line 7: length=1592, taps=[1592]
// Delay line 8: length=1724, taps=[211, 1101, 1724]
// Delay line 9: length=144, taps=[144]
// Delay line 10: length=204, taps=[204]
// Delay line 11: length=808, taps=[808]
// Delay line 12: length=668, taps=[668]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_19(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 13793, 211) / 4 + -LINE(6, 10473, 1391) / 4 + -LINE(4, 6488, 1403) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 13793, 1101) / 4 + -LINE(6, 10473, 690) / 4 + -LINE(4, 6488, 471) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 2415, 1) / 2;
	WRITE_LINE(2, 2415) = Acc;
	Acc = LINE(2, 2415, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
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
	Acc = -Acc / 2 + LINE(9, 13939, 144);
	tmp2 = Acc;
	Acc = LINE(8, 13793, 1724) * 0.75 + LINE(7, 12067, 1592) / 2;
	WRITE_LINE(7, 12067) = -Acc;
	Acc = -Acc / 2 + LINE(7, 12067, 1592);
	WRITE_LINE(6, 10473) = Acc;
	Acc = LINE(6, 10473, 1910) * 0.625 + LINE(5, 8561, 2071) / 2;
	WRITE_LINE(5, 8561) = -Acc;
	Acc = -Acc / 2 + LINE(5, 8561, 2071);
	WRITE_LINE(4, 6488) = Acc;
	Acc = LINE(4, 6488, 1857) * 0.625 + LINE(3, 4629, 2212) / 2;
	WRITE_LINE(3, 4629) = -Acc;
	Acc = LINE(1, 2412, 1) / 2;
	tmp1 = -Acc;
	Acc = -Acc / 2 + LINE(1, 2412, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 2412) = Acc;
	Acc = WRITE_LINE(1, 2412) + tmp2;
	WRITE_LINE(8, 13793) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2612, taps=[2612]
// Delay line 4: length=1657, taps=[671, 1403, 1657]
// Delay line 5: length=2371, taps=[2371]
// Delay line 6: length=2010, taps=[690, 1391, 2010]
// Delay line 7: length=1992, taps=[1992]
// Delay line 8: length=1924, taps=[211, 1101, 1924]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1420, taps=[1420]
// Delay line 12: length=868, taps=[868]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_20(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12941, 211) / 4 + -LINE(6, 9021, 1391) / 4 + -LINE(4, 4636, 1403) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 12941, 1101) / 4 + -LINE(6, 9021, 690) / 4 + -LINE(4, 4636, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 363, 1) / 2;
	WRITE_LINE(2, 363) = Acc;
	Acc = LINE(2, 363, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 868) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 868) + LINE(11, 14755, 1420) / 2;
	WRITE_LINE(11, 14755) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14755, 1420) + LINE(10, 13333, 234) / 2;
	WRITE_LINE(10, 13333) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13333, 234) + LINE(9, 13097, 154) / 2;
	WRITE_LINE(9, 13097) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13097, 154);
	tmp2 = Acc;
	Acc = LINE(8, 12941, 1924) * 0.75 + LINE(7, 11015, 1992) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1992);
	WRITE_LINE(6, 9021) = Acc;
	Acc = LINE(6, 9021, 2010) / 2 + LINE(5, 7009, 2371) / 2;
	WRITE_LINE(5, 7009) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7009, 2371);
	WRITE_LINE(4, 4636) = Acc;
	Acc = LINE(4, 4636, 1657) / 2 + LINE(3, 2977, 2612) / 2;
	WRITE_LINE(3, 2977) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2977, 2612);
	tmp1 = Acc;
	Acc = LINE(1, 360, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 360) = Acc;
	Acc = WRITE_LINE(1, 360) + tmp2;
	WRITE_LINE(8, 12941) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2212, taps=[2212]
// Delay line 4: length=1657, taps=[671, 1503, 1657]
// Delay line 5: length=1871, taps=[1871]
// Delay line 6: length=1410, taps=[890, 1391, 1410]
// Delay line 7: length=1292, taps=[1292]
// Delay line 8: length=1124, taps=[21, 876, 1124]
// Delay line 9: length=104, taps=[104]
// Delay line 10: length=189, taps=[189]
// Delay line 11: length=1320, taps=[1320]
// Delay line 12: length=768, taps=[768]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=251, taps=[251]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_21(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 13306, 21) / 2 + LINE(6, 10886, 1391) / 2 + LINE(4, 7601, 1503) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp5 = Acc;
	Acc = LINE(8, 13306, 876) / 2 + LINE(6, 10886, 890) / 2 + LINE(4, 7601, 671) / 2;
	tmp1 = Acc;
	Acc = tmp1 / 2;
	tmp3 = Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 3728, 1) / 2;
	WRITE_LINE(2, 3728) = Acc;
	Acc = LINE(2, 3728, 1) * 2.53125 + LINE(14, 16381, 251) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 251) + LINE(13, 16128, 431) / 2;
	WRITE_LINE(13, 16128) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16128, 431) + LINE(12, 15695, 768) / 2;
	WRITE_LINE(12, 15695) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15695, 768) + LINE(11, 14925, 1320) / 2;
	WRITE_LINE(11, 14925) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14925, 1320) + LINE(10, 13603, 189) / 2;
	WRITE_LINE(10, 13603) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13603, 189) + LINE(9, 13412, 104) / 2;
	WRITE_LINE(9, 13412) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13412, 104);
	tmp2 = Acc;
	Acc = LINE(8, 13306, 1124) * 0.75 + LINE(7, 12180, 1292) / 2;
	WRITE_LINE(7, 12180) = -Acc;
	Acc = -Acc / 2 + LINE(7, 12180, 1292);
	WRITE_LINE(6, 10886) = Acc;
	Acc = LINE(6, 10886, 1410) / 2 + LINE(5, 9474, 1871) / 2;
	WRITE_LINE(5, 9474) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9474, 1871);
	WRITE_LINE(4, 7601) = Acc;
	Acc = LINE(4, 7601, 1657) / 2 + LINE(3, 5942, 2212) / 2;
	WRITE_LINE(3, 5942) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 5942, 2212) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 3725, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 3725) = Acc;
	Acc = WRITE_LINE(1, 3725) + tmp2;
	WRITE_LINE(8, 13306) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1306, taps=[1306]
// Delay line 4: length=1028, taps=[336, 1001, 1028]
// Delay line 5: length=1188, taps=[1188]
// Delay line 6: length=1005, taps=[445, 796, 1005]
// Delay line 7: length=995, taps=[995]
// Delay line 8: length=712, taps=[11, 712]
// Delay line 9: length=76, taps=[76]
// Delay line 10: length=117, taps=[117]
// Delay line 11: length=557, taps=[557]
// Delay line 12: length=434, taps=[434]
// Delay line 13: length=215, taps=[215]
// Delay line 14: length=160, taps=[160]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_22(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 14810, 11) / 4 + -LINE(6, 13099, 796) / 4 + -LINE(4, 10902, 1001) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 14810, 11) / 4 + -LINE(6, 13099, 445) / 4 + -LINE(4, 10902, 336) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 8564, 1) / 2;
	WRITE_LINE(2, 8564) = Acc;
	Acc = LINE(2, 8564, 1) * 2.53125 + LINE(14, 16381, 160) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 160) + LINE(13, 16219, 215) / 2;
	WRITE_LINE(13, 16219) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16219, 215) + LINE(12, 16002, 434) / 2;
	WRITE_LINE(12, 16002) = -Acc;
	Acc = -Acc / 2 + LINE(12, 16002, 434) + LINE(11, 15566, 557) / 2;
	WRITE_LINE(11, 15566) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15566, 557) + LINE(10, 15007, 117) / 2;
	WRITE_LINE(10, 15007) = -Acc;
	Acc = -Acc / 2 + LINE(10, 15007, 117) + LINE(9, 14888, 76) / 2;
	WRITE_LINE(9, 14888) = -Acc;
	Acc = -Acc / 2 + LINE(9, 14888, 76);
	tmp2 = Acc;
	Acc = LINE(8, 14810, 712) * 0.625 + LINE(7, 14096, 995) / 2;
	WRITE_LINE(7, 14096) = -Acc;
	Acc = -Acc / 2 + LINE(7, 14096, 995);
	WRITE_LINE(6, 13099) = Acc;
	Acc = LINE(6, 13099, 1005) * 0.75 + LINE(5, 12092, 1188) / 2;
	WRITE_LINE(5, 12092) = -Acc;
	Acc = -Acc / 2 + LINE(5, 12092, 1188);
	WRITE_LINE(4, 10902) = Acc;
	Acc = LINE(4, 10902, 1028) * 0.75 + LINE(3, 9872, 1306) / 2;
	WRITE_LINE(3, 9872) = -Acc;
	Acc = -Acc / 2 + LINE(3, 9872, 1306);
	tmp1 = Acc;
	Acc = LINE(1, 8561, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 8561) = Acc;
	Acc = WRITE_LINE(1, 8561) + tmp2;
	WRITE_LINE(8, 14810) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=2312, taps=[2312]
// Delay line 3: length=2257, taps=[671, 1703, 2257]
// Delay line 4: length=1771, taps=[1771]
// Delay line 5: length=1810, taps=[390, 1491, 1810]
// Delay line 6: length=1592, taps=[1592]
// Delay line 7: length=1424, taps=[21, 876, 1424]
// Delay line 8: length=104, taps=[104]
// Delay line 9: length=234, taps=[234]
// Delay line 10: length=1102, taps=[1102]
// Delay line 11: length=768, taps=[768]
// Delay line 12: length=431, taps=[431]
// Delay line 13: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_23(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 13409, 21) / 4 + -LINE(5, 10389, 1491) / 4 + -LINE(3, 6804, 1703) / 4;
	tmp3 = -Acc;
	Acc = -LINE(7, 13409, 876) / 4 + -LINE(5, 10389, 390) / 4 + -LINE(3, 6804, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) * 2.53125 + LINE(13, 16381, 321) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16381, 321) + LINE(12, 16058, 431) / 2;
	WRITE_LINE(12, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(12, 16058, 431) + LINE(11, 15625, 768) / 2;
	WRITE_LINE(11, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15625, 768) + LINE(10, 14855, 1102) / 2;
	WRITE_LINE(10, 14855) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14855, 1102) + LINE(9, 13751, 234) / 2;
	WRITE_LINE(9, 13751) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13751, 234) + LINE(8, 13515, 104) / 2;
	WRITE_LINE(8, 13515) = -Acc;
	Acc = -Acc / 2 + LINE(8, 13515, 104);
	tmp2 = Acc;
	Acc = LINE(7, 13409, 1424) * 0.75 + LINE(6, 11983, 1592) / 2;
	WRITE_LINE(6, 11983) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11983, 1592);
	WRITE_LINE(5, 10389) = Acc;
	Acc = -LINE(5, 10389, 1810) / 4 + LINE(4, 8577, 1771) / 2;
	WRITE_LINE(4, 8577) = -Acc;
	Acc = -Acc / 2 + LINE(4, 8577, 1771);
	WRITE_LINE(3, 6804) = Acc;
	Acc = LINE(3, 6804, 2257) * 0.75 + LINE(2, 4545, 2312) / 2;
	WRITE_LINE(2, 4545) = -Acc;
	Acc = Acc * -0.75 + LINE(2, 4545, 2312) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 2228, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 2228) = Acc;
	Acc = WRITE_LINE(1, 2228) + tmp2;
	WRITE_LINE(7, 13409) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=2312, taps=[2312]
// Delay line 3: length=2257, taps=[671, 1703, 2257]
// Delay line 4: length=1771, taps=[1771]
// Delay line 5: length=1810, taps=[890, 1491, 1810]
// Delay line 6: length=1592, taps=[1592]
// Delay line 7: length=1424, taps=[21, 876, 1424]
// Delay line 8: length=154, taps=[154]
// Delay line 9: length=234, taps=[234]
// Delay line 10: length=1420, taps=[1420]
// Delay line 11: length=968, taps=[968]
// Delay line 12: length=431, taps=[431]
// Delay line 13: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_24(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12841, 21) / 4 + -LINE(5, 9821, 1491) / 4 + -LINE(3, 6236, 1703) / 4;
	tmp3 = -Acc;
	Acc = -LINE(7, 12841, 876) / 4 + -LINE(5, 9821, 890) / 4 + -LINE(3, 6236, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) * 2.53125 + LINE(13, 16381, 321) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16381, 321) + LINE(12, 16058, 431) / 2;
	WRITE_LINE(12, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(12, 16058, 431) + LINE(11, 15625, 968) / 2;
	WRITE_LINE(11, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15625, 968) + LINE(10, 14655, 1420) / 2;
	WRITE_LINE(10, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14655, 1420) + LINE(9, 13233, 234) / 2;
	WRITE_LINE(9, 13233) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13233, 234) + LINE(8, 12997, 154) / 2;
	WRITE_LINE(8, 12997) = -Acc;
	Acc = -Acc / 2 + LINE(8, 12997, 154);
	tmp2 = Acc;
	Acc = LINE(7, 12841, 1424) * 0.75 + LINE(6, 11415, 1592) / 2;
	WRITE_LINE(6, 11415) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11415, 1592);
	WRITE_LINE(5, 9821) = Acc;
	Acc = LINE(5, 9821, 1810) * 0.75 + LINE(4, 8009, 1771) / 2;
	WRITE_LINE(4, 8009) = -Acc;
	Acc = -Acc / 2 + LINE(4, 8009, 1771);
	WRITE_LINE(3, 6236) = Acc;
	Acc = LINE(3, 6236, 2257) / 2 + LINE(2, 3977, 2312) / 2;
	WRITE_LINE(2, 3977) = -Acc;
	Acc = Acc * -0.75 + LINE(2, 3977, 2312) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 1660, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 1660) = Acc;
	Acc = WRITE_LINE(1, 1660) + tmp2;
	WRITE_LINE(7, 12841) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2612, taps=[2612]
// Delay line 4: length=1857, taps=[671, 1403, 1857]
// Delay line 5: length=2371, taps=[2371]
// Delay line 6: length=2010, taps=[890, 1591, 2010]
// Delay line 7: length=1792, taps=[1792]
// Delay line 8: length=1924, taps=[211, 1101, 1924]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1420, taps=[1420]
// Delay line 12: length=868, taps=[868]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_25(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12941, 211) / 4 + -LINE(6, 9221, 1591) / 4 + -LINE(4, 4836, 1403) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 12941, 1101) / 4 + -LINE(6, 9221, 890) / 4 + -LINE(4, 4836, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 363, 1) / 2;
	WRITE_LINE(2, 363) = Acc;
	Acc = LINE(2, 363, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 868) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 868) + LINE(11, 14755, 1420) / 2;
	WRITE_LINE(11, 14755) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14755, 1420) + LINE(10, 13333, 234) / 2;
	WRITE_LINE(10, 13333) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13333, 234) + LINE(9, 13097, 154) / 2;
	WRITE_LINE(9, 13097) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13097, 154);
	tmp2 = Acc;
	Acc = LINE(8, 12941, 1924) * 0.75 + LINE(7, 11015, 1792) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1792);
	WRITE_LINE(6, 9221) = Acc;
	Acc = LINE(6, 9221, 2010) / 2 + LINE(5, 7209, 2371) / 2;
	WRITE_LINE(5, 7209) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7209, 2371);
	WRITE_LINE(4, 4836) = Acc;
	Acc = LINE(4, 4836, 1857) / 2 + LINE(3, 2977, 2612) / 2;
	WRITE_LINE(3, 2977) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2977, 2612);
	tmp1 = Acc;
	Acc = LINE(1, 360, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 360) = Acc;
	Acc = WRITE_LINE(1, 360) + tmp2;
	WRITE_LINE(8, 12941) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=2612, taps=[2612]
// Delay line 3: length=1857, taps=[671, 1403, 1857]
// Delay line 4: length=2371, taps=[2371]
// Delay line 5: length=2010, taps=[890, 1591, 2010]
// Delay line 6: length=1792, taps=[1792]
// Delay line 7: length=1924, taps=[211, 1101, 1924]
// Delay line 8: length=154, taps=[154]
// Delay line 9: length=234, taps=[234]
// Delay line 10: length=1420, taps=[1420]
// Delay line 11: length=868, taps=[868]
// Delay line 12: length=431, taps=[431]
// Delay line 13: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_26(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12941, 211) / 4 + -LINE(5, 9221, 1591) / 4 + -LINE(3, 4836, 1403) / 4;
	tmp3 = -Acc;
	Acc = -LINE(7, 12941, 1101) / 4 + -LINE(5, 9221, 890) / 4 + -LINE(3, 4836, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) * 2.53125 + LINE(13, 16381, 321) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16381, 321) + LINE(12, 16058, 431) / 2;
	WRITE_LINE(12, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(12, 16058, 431) + LINE(11, 15625, 868) / 2;
	WRITE_LINE(11, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15625, 868) + LINE(10, 14755, 1420) / 2;
	WRITE_LINE(10, 14755) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14755, 1420) + LINE(9, 13333, 234) / 2;
	WRITE_LINE(9, 13333) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13333, 234) + LINE(8, 13097, 154) / 2;
	WRITE_LINE(8, 13097) = -Acc;
	Acc = -Acc / 2 + LINE(8, 13097, 154);
	tmp2 = Acc;
	Acc = LINE(7, 12941, 1924) * 0.75 + LINE(6, 11015, 1792) / 2;
	WRITE_LINE(6, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11015, 1792);
	WRITE_LINE(5, 9221) = Acc;
	Acc = LINE(5, 9221, 2010) / 2 + LINE(4, 7209, 2371) / 2;
	WRITE_LINE(4, 7209) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7209, 2371);
	WRITE_LINE(3, 4836) = Acc;
	Acc = LINE(3, 4836, 1857) / 2 + LINE(2, 2977, 2612) / 2;
	WRITE_LINE(2, 2977) = -Acc;
	Acc = Acc * -0.75 + LINE(2, 2977, 2612) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 360, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 360) = Acc;
	Acc = WRITE_LINE(1, 360) + tmp2;
	WRITE_LINE(7, 12941) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2312, taps=[2312]
// Delay line 4: length=2257, taps=[671, 1703, 2257]
// Delay line 5: length=1971, taps=[1971]
// Delay line 6: length=2110, taps=[890, 1491, 2110]
// Delay line 7: length=1492, taps=[1492]
// Delay line 8: length=1624, taps=[21, 876, 1624]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1520, taps=[1520]
// Delay line 12: length=968, taps=[968]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_27(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12741, 21) / 4 + -LINE(6, 9621, 1491) / 4 + -LINE(4, 5536, 1703) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 12741, 876) / 4 + -LINE(6, 9621, 890) / 4 + -LINE(4, 5536, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 963, 1) / 2;
	WRITE_LINE(2, 963) = Acc;
	Acc = LINE(2, 963, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 968) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 968) + LINE(11, 14655, 1520) / 2;
	WRITE_LINE(11, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14655, 1520) + LINE(10, 13133, 234) / 2;
	WRITE_LINE(10, 13133) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13133, 234) + LINE(9, 12897, 154) / 2;
	WRITE_LINE(9, 12897) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12897, 154);
	tmp2 = Acc;
	Acc = LINE(8, 12741, 1624) * 0.75 + LINE(7, 11115, 1492) / 2;
	WRITE_LINE(7, 11115) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11115, 1492);
	WRITE_LINE(6, 9621) = Acc;
	Acc = LINE(6, 9621, 2110) / 2 + LINE(5, 7509, 1971) / 2;
	WRITE_LINE(5, 7509) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7509, 1971);
	WRITE_LINE(4, 5536) = Acc;
	Acc = LINE(4, 5536, 2257) / 2 + LINE(3, 3277, 2312) / 2;
	WRITE_LINE(3, 3277) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 3277, 2312) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 960, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 960) = Acc;
	Acc = WRITE_LINE(1, 960) + tmp2;
	WRITE_LINE(8, 12741) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=2612, taps=[2612]
// Delay line 3: length=2357, taps=[403, 1234, 2357]
// Delay line 4: length=2371, taps=[2371]
// Delay line 5: length=2010, taps=[890, 1591, 2010]
// Delay line 6: length=1792, taps=[1792]
// Delay line 7: length=1424, taps=[211, 801, 1424]
// Delay line 8: length=154, taps=[154]
// Delay line 9: length=234, taps=[234]
// Delay line 10: length=1420, taps=[1420]
// Delay line 11: length=868, taps=[868]
// Delay line 12: length=431, taps=[431]
// Delay line 13: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_28(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12941, 211) / 4 + -LINE(5, 9721, 1591) / 4 + -LINE(3, 5336, 403) / 4;
	tmp3 = -Acc;
	Acc = -LINE(7, 12941, 801) / 4 + -LINE(5, 9721, 890) / 4 + -LINE(3, 5336, 1234) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) * 2.53125 + LINE(13, 16381, 321) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16381, 321) + LINE(12, 16058, 431) / 2;
	WRITE_LINE(12, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(12, 16058, 431) + LINE(11, 15625, 868) / 2;
	WRITE_LINE(11, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15625, 868) + LINE(10, 14755, 1420) / 2;
	WRITE_LINE(10, 14755) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14755, 1420) + LINE(9, 13333, 234) / 2;
	WRITE_LINE(9, 13333) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13333, 234) + LINE(8, 13097, 154) / 2;
	WRITE_LINE(8, 13097) = -Acc;
	Acc = -Acc / 2 + LINE(8, 13097, 154);
	tmp2 = Acc;
	Acc = LINE(7, 12941, 1424) * 0.75 + LINE(6, 11515, 1792) / 2;
	WRITE_LINE(6, 11515) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11515, 1792);
	WRITE_LINE(5, 9721) = Acc;
	Acc = LINE(5, 9721, 2010) / 2 + LINE(4, 7709, 2371) / 2;
	WRITE_LINE(4, 7709) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7709, 2371);
	WRITE_LINE(3, 5336) = Acc;
	Acc = LINE(3, 5336, 2357) / 2 + LINE(2, 2977, 2612) / 2;
	WRITE_LINE(2, 2977) = -Acc;
	Acc = Acc * -0.75 + LINE(2, 2977, 2612) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 360, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 360) = Acc;
	Acc = WRITE_LINE(1, 360) + tmp2;
	WRITE_LINE(7, 12941) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2312, taps=[2312]
// Delay line 4: length=2157, taps=[671, 1403, 2157]
// Delay line 5: length=2271, taps=[2271]
// Delay line 6: length=2010, taps=[890, 1891, 2010]
// Delay line 7: length=1592, taps=[1592]
// Delay line 8: length=1624, taps=[21, 789, 1624]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1620, taps=[1620]
// Delay line 12: length=968, taps=[968]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_29(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9421, 1891) / 4 + -LINE(4, 5136, 1403) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 12641, 789) / 4 + -LINE(6, 9421, 890) / 4 + -LINE(4, 5136, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 663, 1) / 2;
	WRITE_LINE(2, 663) = Acc;
	Acc = LINE(2, 663, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 968) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 968) + LINE(11, 14655, 1620) / 2;
	WRITE_LINE(11, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14655, 1620) + LINE(10, 13033, 234) / 2;
	WRITE_LINE(10, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13033, 234) + LINE(9, 12797, 154) / 2;
	WRITE_LINE(9, 12797) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12797, 154);
	tmp2 = Acc;
	Acc = LINE(8, 12641, 1624) * 0.9375 + LINE(7, 11015, 1592) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1592);
	WRITE_LINE(6, 9421) = Acc;
	Acc = LINE(6, 9421, 2010) * 0.75 + LINE(5, 7409, 2271) / 2;
	WRITE_LINE(5, 7409) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7409, 2271);
	WRITE_LINE(4, 5136) = Acc;
	Acc = LINE(4, 5136, 2157) / 2 + LINE(3, 2977, 2312) / 2;
	WRITE_LINE(3, 2977) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 2977, 2312) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 660, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 660) = Acc;
	Acc = WRITE_LINE(1, 660) + tmp2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2612, taps=[2612]
// Delay line 4: length=2057, taps=[671, 2003, 2057]
// Delay line 5: length=2371, taps=[2371]
// Delay line 6: length=2010, taps=[890, 1591, 2010]
// Delay line 7: length=1992, taps=[1992]
// Delay line 8: length=1424, taps=[21, 801, 1424]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1120, taps=[1120]
// Delay line 12: length=868, taps=[868]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_30(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 13241, 21) / 4 + -LINE(6, 9821, 1591) / 4 + -LINE(4, 5436, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 13241, 801) / 4 + -LINE(6, 9821, 890) / 4 + -LINE(4, 5436, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 763, 1) / 2;
	WRITE_LINE(2, 763) = Acc;
	Acc = LINE(2, 763, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 868) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 868) + LINE(11, 14755, 1120) / 2;
	WRITE_LINE(11, 14755) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14755, 1120) + LINE(10, 13633, 234) / 2;
	WRITE_LINE(10, 13633) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13633, 234) + LINE(9, 13397, 154) / 2;
	WRITE_LINE(9, 13397) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13397, 154);
	tmp2 = Acc;
	Acc = LINE(8, 13241, 1424) * 0.75 + LINE(7, 11815, 1992) / 2;
	WRITE_LINE(7, 11815) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11815, 1992);
	WRITE_LINE(6, 9821) = Acc;
	Acc = LINE(6, 9821, 2010) * 0.75 + LINE(5, 7809, 2371) / 2;
	WRITE_LINE(5, 7809) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7809, 2371);
	WRITE_LINE(4, 5436) = Acc;
	Acc = LINE(4, 5436, 2057) * 0.625 + LINE(3, 3377, 2612) / 2;
	WRITE_LINE(3, 3377) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 3377, 2612) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 760, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 760) = Acc;
	Acc = WRITE_LINE(1, 760) + tmp2;
	WRITE_LINE(8, 13241) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2312, taps=[2312]
// Delay line 4: length=2157, taps=[671, 2003, 2157]
// Delay line 5: length=2371, taps=[2371]
// Delay line 6: length=2110, taps=[890, 1891, 2110]
// Delay line 7: length=1992, taps=[1992]
// Delay line 8: length=1624, taps=[21, 1010, 1624]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1620, taps=[1620]
// Delay line 12: length=968, taps=[968]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_31(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9021, 1891) / 4 + -LINE(4, 4536, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 12641, 1010) / 4 + -LINE(6, 9021, 890) / 4 + -LINE(4, 4536, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 63, 1) / 2;
	WRITE_LINE(2, 63) = Acc;
	Acc = LINE(2, 63, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 968) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 968) + LINE(11, 14655, 1620) / 2;
	WRITE_LINE(11, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14655, 1620) + LINE(10, 13033, 234) / 2;
	WRITE_LINE(10, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13033, 234) + LINE(9, 12797, 154) / 2;
	WRITE_LINE(9, 12797) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12797, 154);
	tmp2 = Acc;
	Acc = LINE(8, 12641, 1624) * 0.9375 + LINE(7, 11015, 1992) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1992);
	WRITE_LINE(6, 9021) = Acc;
	Acc = LINE(6, 9021, 2110) * 0.75 + LINE(5, 6909, 2371) / 2;
	WRITE_LINE(5, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6909, 2371);
	WRITE_LINE(4, 4536) = Acc;
	Acc = LINE(4, 4536, 2157) / 2 + LINE(3, 2377, 2312) / 2;
	WRITE_LINE(3, 2377) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 2377, 2312) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = WRITE_LINE(1, 60) + tmp2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=2612, taps=[2612]
// Delay line 3: length=2257, taps=[671, 2003, 2257]
// Delay line 4: length=2471, taps=[2471]
// Delay line 5: length=2110, taps=[890, 1591, 2110]
// Delay line 6: length=1992, taps=[1992]
// Delay line 7: length=1624, taps=[21, 801, 1624]
// Delay line 8: length=154, taps=[154]
// Delay line 9: length=234, taps=[234]
// Delay line 10: length=1120, taps=[1120]
// Delay line 11: length=868, taps=[868]
// Delay line 12: length=431, taps=[431]
// Delay line 13: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_32(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 13241, 21) / 4 + -LINE(5, 9621, 1591) / 4 + -LINE(3, 5036, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(7, 13241, 801) / 4 + -LINE(5, 9621, 890) / 4 + -LINE(3, 5036, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) * 2.53125 + LINE(13, 16381, 321) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16381, 321) + LINE(12, 16058, 431) / 2;
	WRITE_LINE(12, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(12, 16058, 431) + LINE(11, 15625, 868) / 2;
	WRITE_LINE(11, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15625, 868) + LINE(10, 14755, 1120) / 2;
	WRITE_LINE(10, 14755) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14755, 1120) + LINE(9, 13633, 234) / 2;
	WRITE_LINE(9, 13633) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13633, 234) + LINE(8, 13397, 154) / 2;
	WRITE_LINE(8, 13397) = -Acc;
	Acc = -Acc / 2 + LINE(8, 13397, 154);
	tmp2 = Acc;
	Acc = LINE(7, 13241, 1624) + LINE(6, 11615, 1992) / 2;
	WRITE_LINE(6, 11615) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11615, 1992);
	WRITE_LINE(5, 9621) = Acc;
	Acc = LINE(5, 9621, 2110) * 0.75 + LINE(4, 7509, 2471) / 2;
	WRITE_LINE(4, 7509) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7509, 2471);
	WRITE_LINE(3, 5036) = Acc;
	Acc = LINE(3, 5036, 2257) / 2 + LINE(2, 2777, 2612) / 2;
	WRITE_LINE(2, 2777) = -Acc;
	Acc = Acc * -0.75 + LINE(2, 2777, 2612) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 160, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 160) = Acc;
	Acc = WRITE_LINE(1, 160) + tmp2;
	WRITE_LINE(7, 13241) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2612, taps=[2612]
// Delay line 4: length=2057, taps=[671, 2003, 2057]
// Delay line 5: length=2371, taps=[2371]
// Delay line 6: length=2010, taps=[890, 1591, 2010]
// Delay line 7: length=1992, taps=[1992]
// Delay line 8: length=1424, taps=[21, 801, 1424]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1120, taps=[1120]
// Delay line 12: length=868, taps=[868]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_33(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 13241, 21) / 4 + -LINE(6, 9821, 1591) / 4 + -LINE(4, 5436, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 13241, 801) / 4 + -LINE(6, 9821, 890) / 4 + -LINE(4, 5436, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 763, 1) / 2;
	WRITE_LINE(2, 763) = Acc;
	Acc = LINE(2, 763, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 868) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 868) + LINE(11, 14755, 1120) / 2;
	WRITE_LINE(11, 14755) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14755, 1120) + LINE(10, 13633, 234) / 2;
	WRITE_LINE(10, 13633) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13633, 234) + LINE(9, 13397, 154) / 2;
	WRITE_LINE(9, 13397) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13397, 154);
	tmp2 = Acc;
	Acc = LINE(8, 13241, 1424) * 0.625 + LINE(7, 11815, 1992) / 2;
	WRITE_LINE(7, 11815) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11815, 1992);
	WRITE_LINE(6, 9821) = Acc;
	Acc = LINE(6, 9821, 2010) * 0.75 + LINE(5, 7809, 2371) / 2;
	WRITE_LINE(5, 7809) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7809, 2371);
	WRITE_LINE(4, 5436) = Acc;
	Acc = LINE(4, 5436, 2057) * 0.75 + LINE(3, 3377, 2612) / 2;
	WRITE_LINE(3, 3377) = -Acc;
	Acc = -Acc / 2 + LINE(3, 3377, 2612);
	tmp1 = Acc;
	Acc = LINE(1, 760, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 760) = Acc;
	Acc = WRITE_LINE(1, 760) + tmp2;
	WRITE_LINE(8, 13241) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1576, taps=[1576]
// Delay line 3: length=1457, taps=[671, 1356, 1457]
// Delay line 4: length=1801, taps=[79, 1801]
// Delay line 5: length=1310, taps=[890, 1310]
// Delay line 6: length=1692, taps=[1692]
// Delay line 7: length=621, taps=[21, 501, 621]
// Delay line 8: length=89, taps=[89]
// Delay line 9: length=171, taps=[171]
// Delay line 10: length=721, taps=[721]
// Delay line 11: length=489, taps=[489]
// Delay line 12: length=301, taps=[301]
// Delay line 13: length=221, taps=[221]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_34(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 14377, 21) / 4 + -LINE(4, 10748, 79) / 4 + -LINE(3, 8945, 1356) / 4;
	tmp3 = -Acc;
	Acc = -LINE(7, 14377, 501) / 4 + -LINE(5, 12060, 890) / 4 + -LINE(3, 8945, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) * 2.53125 + LINE(13, 16381, 221) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16381, 221) + LINE(12, 16158, 301) / 2;
	WRITE_LINE(12, 16158) = -Acc;
	Acc = -Acc / 2 + LINE(12, 16158, 301) + LINE(11, 15855, 489) / 2;
	WRITE_LINE(11, 15855) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15855, 489) + LINE(10, 15364, 721) / 2;
	WRITE_LINE(10, 15364) = -Acc;
	Acc = -Acc / 2 + LINE(10, 15364, 721) + LINE(9, 14641, 171) / 2;
	WRITE_LINE(9, 14641) = -Acc;
	Acc = -Acc / 2 + LINE(9, 14641, 171) + LINE(8, 14468, 89) / 2;
	WRITE_LINE(8, 14468) = -Acc;
	Acc = -Acc / 2 + LINE(8, 14468, 89);
	tmp2 = Acc;
	Acc = LINE(7, 14377, 621) * 0.75 + LINE(6, 13754, 1692) / 2;
	WRITE_LINE(6, 13754) = -Acc;
	Acc = -Acc / 2 + LINE(6, 13754, 1692);
	WRITE_LINE(5, 12060) = Acc;
	Acc = LINE(5, 12060, 1310) * 0.9375 + LINE(4, 10748, 1801) / 2;
	WRITE_LINE(4, 10748) = -Acc;
	Acc = -Acc / 2 + LINE(4, 10748, 1801);
	WRITE_LINE(3, 8945) = Acc;
	Acc = LINE(3, 8945, 1457) * -0.84375 + LINE(2, 7486, 1576) / 2;
	WRITE_LINE(2, 7486) = -Acc;
	Acc = Acc * -0.75 + LINE(2, 7486, 1576) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 5905, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 5905) = Acc;
	Acc = WRITE_LINE(1, 5905) + tmp2;
	WRITE_LINE(7, 14377) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=2312, taps=[2312]
// Delay line 3: length=1957, taps=[671, 1903, 1957]
// Delay line 4: length=2071, taps=[2071]
// Delay line 5: length=1710, taps=[890, 1691, 1710]
// Delay line 6: length=1592, taps=[1592]
// Delay line 7: length=1424, taps=[21, 801, 1424]
// Delay line 8: length=154, taps=[154]
// Delay line 9: length=234, taps=[234]
// Delay line 10: length=1620, taps=[1620]
// Delay line 11: length=968, taps=[968]
// Delay line 12: length=431, taps=[431]
// Delay line 13: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_35(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12641, 21) / 4 + -LINE(5, 9621, 1691) / 4 + -LINE(3, 5836, 1903) / 4;
	tmp3 = -Acc;
	Acc = -LINE(7, 12641, 801) / 4 + -LINE(5, 9621, 890) / 4 + -LINE(3, 5836, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) * 2.53125 + LINE(13, 16381, 321) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16381, 321) + LINE(12, 16058, 431) / 2;
	WRITE_LINE(12, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(12, 16058, 431) + LINE(11, 15625, 968) / 2;
	WRITE_LINE(11, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15625, 968) + LINE(10, 14655, 1620) / 2;
	WRITE_LINE(10, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14655, 1620) + LINE(9, 13033, 234) / 2;
	WRITE_LINE(9, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13033, 234) + LINE(8, 12797, 154) / 2;
	WRITE_LINE(8, 12797) = -Acc;
	Acc = -Acc / 2 + LINE(8, 12797, 154);
	tmp2 = Acc;
	Acc = LINE(7, 12641, 1424) * 0.75 + LINE(6, 11215, 1592) / 2;
	WRITE_LINE(6, 11215) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11215, 1592);
	WRITE_LINE(5, 9621) = Acc;
	Acc = LINE(5, 9621, 1710) * 0.75 + LINE(4, 7909, 2071) / 2;
	WRITE_LINE(4, 7909) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7909, 2071);
	WRITE_LINE(3, 5836) = Acc;
	Acc = LINE(3, 5836, 1957) * -0.84375 + LINE(2, 3877, 2312) / 2;
	WRITE_LINE(2, 3877) = -Acc;
	Acc = Acc * -0.75 + LINE(2, 3877, 2312) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 1560, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 1560) = Acc;
	Acc = WRITE_LINE(1, 1560) + tmp2;
	WRITE_LINE(7, 12641) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=2312, taps=[2312]
// Delay line 3: length=2157, taps=[671, 2003, 2157]
// Delay line 4: length=2371, taps=[2371]
// Delay line 5: length=2110, taps=[890, 1891, 2110]
// Delay line 6: length=1992, taps=[1992]
// Delay line 7: length=1624, taps=[21, 1010, 1624]
// Delay line 8: length=154, taps=[154]
// Delay line 9: length=234, taps=[234]
// Delay line 10: length=1620, taps=[1620]
// Delay line 11: length=968, taps=[968]
// Delay line 12: length=431, taps=[431]
// Delay line 13: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_36(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12641, 21) / 4 + -LINE(5, 9021, 1891) / 4 + -LINE(3, 4536, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(7, 12641, 1010) / 4 + -LINE(5, 9021, 890) / 4 + -LINE(3, 4536, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) * 2.53125 + LINE(13, 16381, 321) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16381, 321) + LINE(12, 16058, 431) / 2;
	WRITE_LINE(12, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(12, 16058, 431) + LINE(11, 15625, 968) / 2;
	WRITE_LINE(11, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15625, 968) + LINE(10, 14655, 1620) / 2;
	WRITE_LINE(10, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14655, 1620) + LINE(9, 13033, 234) / 2;
	WRITE_LINE(9, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13033, 234) + LINE(8, 12797, 154) / 2;
	WRITE_LINE(8, 12797) = -Acc;
	Acc = -Acc / 2 + LINE(8, 12797, 154);
	tmp2 = Acc;
	Acc = LINE(7, 12641, 1624) + LINE(6, 11015, 1992) / 2;
	WRITE_LINE(6, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11015, 1992);
	WRITE_LINE(5, 9021) = Acc;
	Acc = LINE(5, 9021, 2110) * 0.9375 + LINE(4, 6909, 2371) / 2;
	WRITE_LINE(4, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(4, 6909, 2371);
	WRITE_LINE(3, 4536) = Acc;
	Acc = LINE(3, 4536, 2157) / 2 + LINE(2, 2377, 2312) / 2;
	WRITE_LINE(2, 2377) = -Acc;
	Acc = Acc * -0.75 + LINE(2, 2377, 2312) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = WRITE_LINE(1, 60) + tmp2;
	WRITE_LINE(7, 12641) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2312, taps=[2312]
// Delay line 4: length=2157, taps=[671, 2003, 2157]
// Delay line 5: length=2371, taps=[2371]
// Delay line 6: length=2110, taps=[890, 1891, 2110]
// Delay line 7: length=1992, taps=[1992]
// Delay line 8: length=1624, taps=[21, 1010, 1624]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1620, taps=[1620]
// Delay line 12: length=968, taps=[968]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_37(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9021, 1891) / 4 + -LINE(4, 4536, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 12641, 1010) / 4 + -LINE(6, 9021, 890) / 4 + -LINE(4, 4536, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 63, 1) / 2;
	WRITE_LINE(2, 63) = Acc;
	Acc = LINE(2, 63, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 968) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 968) + LINE(11, 14655, 1620) / 2;
	WRITE_LINE(11, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14655, 1620) + LINE(10, 13033, 234) / 2;
	WRITE_LINE(10, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13033, 234) + LINE(9, 12797, 154) / 2;
	WRITE_LINE(9, 12797) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12797, 154);
	tmp2 = Acc;
	Acc = LINE(8, 12641, 1624) + LINE(7, 11015, 1992) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1992);
	WRITE_LINE(6, 9021) = Acc;
	Acc = LINE(6, 9021, 2110) * 0.9375 + LINE(5, 6909, 2371) / 2;
	WRITE_LINE(5, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6909, 2371);
	WRITE_LINE(4, 4536) = Acc;
	Acc = LINE(4, 4536, 2157) / 2 + LINE(3, 2377, 2312) / 2;
	WRITE_LINE(3, 2377) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 2377, 2312) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = WRITE_LINE(1, 60) + tmp2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2612, taps=[2612]
// Delay line 4: length=2357, taps=[671, 2003, 2357]
// Delay line 5: length=2371, taps=[2371]
// Delay line 6: length=1710, taps=[890, 1591, 1710]
// Delay line 7: length=1992, taps=[1992]
// Delay line 8: length=1624, taps=[21, 801, 1624]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1020, taps=[1020]
// Delay line 12: length=768, taps=[768]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_38(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 13441, 21) / 4 + -LINE(6, 9821, 1591) / 4 + -LINE(4, 5736, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 13441, 801) / 4 + -LINE(6, 9821, 890) / 4 + -LINE(4, 5736, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 763, 1) / 2;
	WRITE_LINE(2, 763) = Acc;
	Acc = LINE(2, 763, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 768) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 768) + LINE(11, 14855, 1020) / 2;
	WRITE_LINE(11, 14855) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14855, 1020) + LINE(10, 13833, 234) / 2;
	WRITE_LINE(10, 13833) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13833, 234) + LINE(9, 13597, 154) / 2;
	WRITE_LINE(9, 13597) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13597, 154);
	tmp2 = Acc;
	Acc = LINE(8, 13441, 1624) * 0.75 + LINE(7, 11815, 1992) / 2;
	WRITE_LINE(7, 11815) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11815, 1992);
	WRITE_LINE(6, 9821) = Acc;
	Acc = LINE(6, 9821, 1710) * 0.75 + LINE(5, 8109, 2371) / 2;
	WRITE_LINE(5, 8109) = -Acc;
	Acc = -Acc / 2 + LINE(5, 8109, 2371);
	WRITE_LINE(4, 5736) = Acc;
	Acc = LINE(4, 5736, 2357) * -0.84375 + LINE(3, 3377, 2612) / 2;
	WRITE_LINE(3, 3377) = -Acc;
	Acc = -Acc / 2 + LINE(3, 3377, 2612);
	tmp1 = Acc;
	Acc = LINE(1, 760, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 760) = Acc;
	Acc = WRITE_LINE(1, 760) + tmp2;
	WRITE_LINE(8, 13441) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=2312, taps=[2312]
// Delay line 3: length=2157, taps=[671, 2003, 2157]
// Delay line 4: length=2371, taps=[2371]
// Delay line 5: length=2110, taps=[890, 1891, 2110]
// Delay line 6: length=1992, taps=[1992]
// Delay line 7: length=1624, taps=[21, 801, 1624]
// Delay line 8: length=154, taps=[154]
// Delay line 9: length=234, taps=[234]
// Delay line 10: length=1620, taps=[1620]
// Delay line 11: length=968, taps=[968]
// Delay line 12: length=431, taps=[431]
// Delay line 13: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_39(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12641, 21) / 4 + -LINE(5, 9021, 1891) / 4 + -LINE(3, 4536, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(7, 12641, 801) / 4 + -LINE(5, 9021, 890) / 4 + -LINE(3, 4536, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) * 2.53125 + LINE(13, 16381, 321) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16381, 321) + LINE(12, 16058, 431) / 2;
	WRITE_LINE(12, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(12, 16058, 431) + LINE(11, 15625, 968) / 2;
	WRITE_LINE(11, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15625, 968) + LINE(10, 14655, 1620) / 2;
	WRITE_LINE(10, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14655, 1620) + LINE(9, 13033, 234) / 2;
	WRITE_LINE(9, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13033, 234) + LINE(8, 12797, 154) / 2;
	WRITE_LINE(8, 12797) = -Acc;
	Acc = -Acc / 2 + LINE(8, 12797, 154);
	tmp2 = Acc;
	Acc = LINE(7, 12641, 1624) * -0.84375 + LINE(6, 11015, 1992) / 2;
	WRITE_LINE(6, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11015, 1992);
	WRITE_LINE(5, 9021) = Acc;
	Acc = LINE(5, 9021, 2110) * -0.84375 + LINE(4, 6909, 2371) / 2;
	WRITE_LINE(4, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(4, 6909, 2371);
	WRITE_LINE(3, 4536) = Acc;
	Acc = LINE(3, 4536, 2157) * 0.75 + LINE(2, 2377, 2312) / 2;
	WRITE_LINE(2, 2377) = -Acc;
	Acc = Acc * -0.75 + LINE(2, 2377, 2312) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = WRITE_LINE(1, 60) + tmp2;
	WRITE_LINE(7, 12641) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2312, taps=[2312]
// Delay line 4: length=2157, taps=[571, 1703, 2157]
// Delay line 5: length=2371, taps=[2371]
// Delay line 6: length=2110, taps=[990, 1891, 2110]
// Delay line 7: length=1992, taps=[1992]
// Delay line 8: length=1624, taps=[21, 901, 1624]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1620, taps=[1620]
// Delay line 12: length=968, taps=[968]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_40(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9021, 1891) / 4 + -LINE(4, 4536, 1703) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 12641, 901) / 4 + -LINE(6, 9021, 990) / 4 + -LINE(4, 4536, 571) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 63, 1) / 2;
	WRITE_LINE(2, 63) = Acc;
	Acc = LINE(2, 63, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 968) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 968) + LINE(11, 14655, 1620) / 2;
	WRITE_LINE(11, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14655, 1620) + LINE(10, 13033, 234) / 2;
	WRITE_LINE(10, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13033, 234) + LINE(9, 12797, 154) / 2;
	WRITE_LINE(9, 12797) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12797, 154);
	tmp2 = Acc;
	Acc = LINE(8, 12641, 1624) * 0.75 + LINE(7, 11015, 1992) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1992);
	WRITE_LINE(6, 9021) = Acc;
	Acc = LINE(6, 9021, 2110) * 0.75 + LINE(5, 6909, 2371) / 2;
	WRITE_LINE(5, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6909, 2371);
	WRITE_LINE(4, 4536) = Acc;
	Acc = LINE(4, 4536, 2157) * -0.84375 + LINE(3, 2377, 2312) / 2;
	WRITE_LINE(3, 2377) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 2377, 2312) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = WRITE_LINE(1, 60) + tmp2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2312, taps=[2312]
// Delay line 4: length=2157, taps=[671, 2003, 2157]
// Delay line 5: length=2371, taps=[2371]
// Delay line 6: length=2110, taps=[890, 1891, 2110]
// Delay line 7: length=1992, taps=[1992]
// Delay line 8: length=1624, taps=[21, 1010, 1624]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1620, taps=[1620]
// Delay line 12: length=968, taps=[968]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_41(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9021, 1891) / 4 + -LINE(4, 4536, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 12641, 1010) / 4 + -LINE(6, 9021, 890) / 4 + -LINE(4, 4536, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 63, 1) / 2;
	WRITE_LINE(2, 63) = Acc;
	Acc = LINE(2, 63, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 968) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 968) + LINE(11, 14655, 1620) / 2;
	WRITE_LINE(11, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14655, 1620) + LINE(10, 13033, 234) / 2;
	WRITE_LINE(10, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13033, 234) + LINE(9, 12797, 154) / 2;
	WRITE_LINE(9, 12797) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12797, 154);
	tmp2 = Acc;
	Acc = LINE(8, 12641, 1624) * -0.84375 + LINE(7, 11015, 1992) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1992);
	WRITE_LINE(6, 9021) = Acc;
	Acc = LINE(6, 9021, 2110) * 0.9375 + LINE(5, 6909, 2371) / 2;
	WRITE_LINE(5, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6909, 2371);
	WRITE_LINE(4, 4536) = Acc;
	Acc = LINE(4, 4536, 2157) * 0.75 + LINE(3, 2377, 2312) / 2;
	WRITE_LINE(3, 2377) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2377, 2312);
	tmp1 = Acc;
	Acc = LINE(1, 60, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = WRITE_LINE(1, 60) + tmp2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=2312, taps=[2312]
// Delay line 3: length=2157, taps=[671, 2003, 2157]
// Delay line 4: length=2371, taps=[2371]
// Delay line 5: length=2110, taps=[890, 1891, 2110]
// Delay line 6: length=1992, taps=[1992]
// Delay line 7: length=1624, taps=[21, 801, 1624]
// Delay line 8: length=154, taps=[154]
// Delay line 9: length=234, taps=[234]
// Delay line 10: length=1620, taps=[1620]
// Delay line 11: length=968, taps=[968]
// Delay line 12: length=431, taps=[431]
// Delay line 13: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_42(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12641, 21) / 4 + -LINE(5, 9021, 1891) / 4 + -LINE(3, 4536, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(7, 12641, 801) / 4 + -LINE(5, 9021, 890) / 4 + -LINE(3, 4536, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) * 2.53125 + LINE(13, 16381, 321) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16381, 321) + LINE(12, 16058, 431) / 2;
	WRITE_LINE(12, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(12, 16058, 431) + LINE(11, 15625, 968) / 2;
	WRITE_LINE(11, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15625, 968) + LINE(10, 14655, 1620) / 2;
	WRITE_LINE(10, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14655, 1620) + LINE(9, 13033, 234) / 2;
	WRITE_LINE(9, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13033, 234) + LINE(8, 12797, 154) / 2;
	WRITE_LINE(8, 12797) = -Acc;
	Acc = -Acc / 2 + LINE(8, 12797, 154);
	tmp2 = Acc;
	Acc = LINE(7, 12641, 1624) * 0.75 + LINE(6, 11015, 1992) / 2;
	WRITE_LINE(6, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11015, 1992);
	WRITE_LINE(5, 9021) = Acc;
	Acc = LINE(5, 9021, 2110) * 0.9375 + LINE(4, 6909, 2371) / 2;
	WRITE_LINE(4, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(4, 6909, 2371);
	WRITE_LINE(3, 4536) = Acc;
	Acc = LINE(3, 4536, 2157) * -0.84375 + LINE(2, 2377, 2312) / 2;
	WRITE_LINE(2, 2377) = -Acc;
	Acc = Acc * -0.75 + LINE(2, 2377, 2312) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = WRITE_LINE(1, 60) + tmp2;
	WRITE_LINE(7, 12641) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2512, taps=[2512]
// Delay line 4: length=2257, taps=[671, 2003, 2257]
// Delay line 5: length=2371, taps=[2371]
// Delay line 6: length=2110, taps=[890, 1891, 2110]
// Delay line 7: length=1992, taps=[1992]
// Delay line 8: length=1324, taps=[21, 1010, 1324]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1620, taps=[1620]
// Delay line 12: length=968, taps=[968]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_43(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9321, 1891) / 4 + -LINE(4, 4836, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 12641, 1010) / 4 + -LINE(6, 9321, 890) / 4 + -LINE(4, 4836, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 63, 1) / 2;
	WRITE_LINE(2, 63) = Acc;
	Acc = LINE(2, 63, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 968) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 968) + LINE(11, 14655, 1620) / 2;
	WRITE_LINE(11, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14655, 1620) + LINE(10, 13033, 234) / 2;
	WRITE_LINE(10, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13033, 234) + LINE(9, 12797, 154) / 2;
	WRITE_LINE(9, 12797) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12797, 154);
	tmp2 = Acc;
	Acc = LINE(8, 12641, 1324) + LINE(7, 11315, 1992) / 2;
	WRITE_LINE(7, 11315) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11315, 1992);
	WRITE_LINE(6, 9321) = Acc;
	Acc = LINE(6, 9321, 2110) * 0.9375 + LINE(5, 7209, 2371) / 2;
	WRITE_LINE(5, 7209) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7209, 2371);
	WRITE_LINE(4, 4836) = Acc;
	Acc = LINE(4, 4836, 2257) * 0.75 + LINE(3, 2577, 2512) / 2;
	WRITE_LINE(3, 2577) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 2577, 2512) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = WRITE_LINE(1, 60) + tmp2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=2312, taps=[2312]
// Delay line 3: length=2157, taps=[571, 1703, 2157]
// Delay line 4: length=2371, taps=[2371]
// Delay line 5: length=2110, taps=[990, 1891, 2110]
// Delay line 6: length=1992, taps=[1992]
// Delay line 7: length=1624, taps=[21, 901, 1624]
// Delay line 8: length=154, taps=[154]
// Delay line 9: length=234, taps=[234]
// Delay line 10: length=1620, taps=[1620]
// Delay line 11: length=968, taps=[968]
// Delay line 12: length=431, taps=[431]
// Delay line 13: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_44(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12641, 21) / 4 + -LINE(5, 9021, 1891) / 4 + -LINE(3, 4536, 1703) / 4;
	tmp3 = -Acc;
	Acc = -LINE(7, 12641, 901) / 4 + -LINE(5, 9021, 990) / 4 + -LINE(3, 4536, 571) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) * 2.53125 + LINE(13, 16381, 321) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16381, 321) + LINE(12, 16058, 431) / 2;
	WRITE_LINE(12, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(12, 16058, 431) + LINE(11, 15625, 968) / 2;
	WRITE_LINE(11, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15625, 968) + LINE(10, 14655, 1620) / 2;
	WRITE_LINE(10, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14655, 1620) + LINE(9, 13033, 234) / 2;
	WRITE_LINE(9, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13033, 234) + LINE(8, 12797, 154) / 2;
	WRITE_LINE(8, 12797) = -Acc;
	Acc = -Acc / 2 + LINE(8, 12797, 154);
	tmp2 = Acc;
	Acc = LINE(7, 12641, 1624) * 0.9375 + LINE(6, 11015, 1992) / 2;
	WRITE_LINE(6, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11015, 1992);
	WRITE_LINE(5, 9021) = Acc;
	Acc = LINE(5, 9021, 2110) * 0.9375 + LINE(4, 6909, 2371) / 2;
	WRITE_LINE(4, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(4, 6909, 2371);
	WRITE_LINE(3, 4536) = Acc;
	Acc = LINE(3, 4536, 2157) * -0.84375 + LINE(2, 2377, 2312) / 2;
	WRITE_LINE(2, 2377) = -Acc;
	Acc = Acc * -0.75 + LINE(2, 2377, 2312) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = WRITE_LINE(1, 60) + tmp2;
	WRITE_LINE(7, 12641) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2312, taps=[2312]
// Delay line 4: length=2157, taps=[671, 2003, 2157]
// Delay line 5: length=2371, taps=[2371]
// Delay line 6: length=2110, taps=[890, 1891, 2110]
// Delay line 7: length=1992, taps=[1992]
// Delay line 8: length=1624, taps=[21, 1010, 1624]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1620, taps=[1620]
// Delay line 12: length=968, taps=[968]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_45(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9021, 1891) / 4 + -LINE(4, 4536, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 12641, 1010) / 4 + -LINE(6, 9021, 890) / 4 + -LINE(4, 4536, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 63, 1) / 2;
	WRITE_LINE(2, 63) = Acc;
	Acc = LINE(2, 63, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 968) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 968) + LINE(11, 14655, 1620) / 2;
	WRITE_LINE(11, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14655, 1620) + LINE(10, 13033, 234) / 2;
	WRITE_LINE(10, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13033, 234) + LINE(9, 12797, 154) / 2;
	WRITE_LINE(9, 12797) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12797, 154);
	tmp2 = Acc;
	Acc = LINE(8, 12641, 1624) * 0.9375 + LINE(7, 11015, 1992) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1992);
	WRITE_LINE(6, 9021) = Acc;
	Acc = LINE(6, 9021, 2110) * 0.9375 + LINE(5, 6909, 2371) / 2;
	WRITE_LINE(5, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6909, 2371);
	WRITE_LINE(4, 4536) = Acc;
	Acc = LINE(4, 4536, 2157) * -0.84375 + LINE(3, 2377, 2312) / 2;
	WRITE_LINE(3, 2377) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 2377, 2312) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = WRITE_LINE(1, 60) + tmp2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=2312, taps=[2312]
// Delay line 3: length=2157, taps=[671, 2003, 2157]
// Delay line 4: length=2371, taps=[2371]
// Delay line 5: length=2110, taps=[890, 1891, 2110]
// Delay line 6: length=1992, taps=[1992]
// Delay line 7: length=1624, taps=[21, 1010, 1624]
// Delay line 8: length=154, taps=[154]
// Delay line 9: length=234, taps=[234]
// Delay line 10: length=1620, taps=[1620]
// Delay line 11: length=968, taps=[968]
// Delay line 12: length=431, taps=[431]
// Delay line 13: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_46(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12641, 21) / 4 + -LINE(5, 9021, 1891) / 4 + -LINE(3, 4536, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(7, 12641, 1010) / 4 + -LINE(5, 9021, 890) / 4 + -LINE(3, 4536, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) * 2.53125 + LINE(13, 16381, 321) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16381, 321) + LINE(12, 16058, 431) / 2;
	WRITE_LINE(12, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(12, 16058, 431) + LINE(11, 15625, 968) / 2;
	WRITE_LINE(11, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15625, 968) + LINE(10, 14655, 1620) / 2;
	WRITE_LINE(10, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14655, 1620) + LINE(9, 13033, 234) / 2;
	WRITE_LINE(9, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13033, 234) + LINE(8, 12797, 154) / 2;
	WRITE_LINE(8, 12797) = -Acc;
	Acc = -Acc / 2 + LINE(8, 12797, 154);
	tmp2 = Acc;
	Acc = LINE(7, 12641, 1624) + LINE(6, 11015, 1992) / 2;
	WRITE_LINE(6, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11015, 1992);
	WRITE_LINE(5, 9021) = Acc;
	Acc = LINE(5, 9021, 2110) * 0.9375 + LINE(4, 6909, 2371) / 2;
	WRITE_LINE(4, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(4, 6909, 2371);
	WRITE_LINE(3, 4536) = Acc;
	Acc = LINE(3, 4536, 2157) * -0.84375 + LINE(2, 2377, 2312) / 2;
	WRITE_LINE(2, 2377) = -Acc;
	Acc = Acc * -0.75 + LINE(2, 2377, 2312) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 63, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 63) = Acc;
	Acc = WRITE_LINE(1, 63) + tmp2;
	WRITE_LINE(7, 12641) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2212, taps=[2212]
// Delay line 4: length=2127, taps=[871, 2003, 2127]
// Delay line 5: length=2371, taps=[2371]
// Delay line 6: length=2210, taps=[890, 1591, 2210]
// Delay line 7: length=1992, taps=[1992]
// Delay line 8: length=1624, taps=[21, 812, 1624]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1620, taps=[1620]
// Delay line 12: length=968, taps=[968]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_47(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9021, 1591) / 4 + -LINE(4, 4436, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 12641, 812) / 4 + -LINE(6, 9021, 890) / 4 + -LINE(4, 4436, 871) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 93, 1) / 2;
	WRITE_LINE(2, 93) = Acc;
	Acc = LINE(2, 93, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 968) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 968) + LINE(11, 14655, 1620) / 2;
	WRITE_LINE(11, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14655, 1620) + LINE(10, 13033, 234) / 2;
	WRITE_LINE(10, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13033, 234) + LINE(9, 12797, 154) / 2;
	WRITE_LINE(9, 12797) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12797, 154);
	tmp2 = Acc;
	Acc = LINE(8, 12641, 1624) + LINE(7, 11015, 1992) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1992);
	WRITE_LINE(6, 9021) = Acc;
	Acc = LINE(6, 9021, 2210) * 0.9375 + LINE(5, 6809, 2371) / 2;
	WRITE_LINE(5, 6809) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6809, 2371);
	WRITE_LINE(4, 4436) = Acc;
	Acc = LINE(4, 4436, 2127) * -0.84375 + LINE(3, 2307, 2212) / 2;
	WRITE_LINE(3, 2307) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 2307, 2212) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 90, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 90) = Acc;
	Acc = WRITE_LINE(1, 90) + tmp2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2712, taps=[2712]
// Delay line 4: length=1857, taps=[671, 1403, 1857]
// Delay line 5: length=2371, taps=[2371]
// Delay line 6: length=1610, taps=[890, 1591, 1610]
// Delay line 7: length=1992, taps=[1992]
// Delay line 8: length=1324, taps=[21, 1010, 1324]
// Delay line 9: length=121, taps=[121]
// Delay line 10: length=243, taps=[243]
// Delay line 11: length=1620, taps=[1620]
// Delay line 12: length=968, taps=[968]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_48(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12665, 21) / 4 + -LINE(6, 9345, 1591) / 4 + -LINE(4, 5360, 1403) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 12665, 1010) / 4 + -LINE(6, 9345, 890) / 4 + -LINE(4, 5360, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 787, 1) / 2;
	WRITE_LINE(2, 787) = Acc;
	Acc = LINE(2, 787, 1) * 2.53125 + LINE(14, 16381, 321) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16381, 321) + LINE(13, 16058, 431) / 2;
	WRITE_LINE(13, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16058, 431) + LINE(12, 15625, 968) / 2;
	WRITE_LINE(12, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15625, 968) + LINE(11, 14655, 1620) / 2;
	WRITE_LINE(11, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(11, 14655, 1620) + LINE(10, 13033, 243) / 2;
	WRITE_LINE(10, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13033, 243) + LINE(9, 12788, 121) / 2;
	WRITE_LINE(9, 12788) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12788, 121);
	tmp2 = Acc;
	Acc = LINE(8, 12665, 1324) + LINE(7, 11339, 1992) / 2;
	WRITE_LINE(7, 11339) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11339, 1992);
	WRITE_LINE(6, 9345) = Acc;
	Acc = LINE(6, 9345, 1610) * 0.9375 + LINE(5, 7733, 2371) / 2;
	WRITE_LINE(5, 7733) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7733, 2371);
	WRITE_LINE(4, 5360) = Acc;
	Acc = LINE(4, 5360, 1857) * 0.9375 + LINE(3, 3501, 2712) / 2;
	WRITE_LINE(3, 3501) = -Acc;
	Acc = Acc / 4 + -LINE(3, 3501, 2712) / 2 + LINE(1, 784, 1) / 2;
	WRITE_LINE(1, 784) = Acc;
	Acc = WRITE_LINE(1, 784) + tmp2;
	WRITE_LINE(8, 12665) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=2712, taps=[2712]
// Delay line 3: length=2157, taps=[671, 2003, 2157]
// Delay line 4: length=2371, taps=[2371]
// Delay line 5: length=2110, taps=[890, 1891, 2110]
// Delay line 6: length=1992, taps=[1992]
// Delay line 7: length=1624, taps=[21, 1010, 1624]
// Delay line 8: length=1620, taps=[1620]
// Delay line 9: length=968, taps=[968]
// Delay line 10: length=431, taps=[431]
// Delay line 11: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_49(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 13033, 21) / 4 + -LINE(5, 9413, 1891) / 4 + -LINE(3, 4928, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(7, 13033, 1010) / 4 + -LINE(5, 9413, 890) / 4 + -LINE(3, 4928, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) * 2.53125 + LINE(11, 16381, 321) / 2;
	WRITE_LINE(11, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(11, 16381, 321) + LINE(10, 16058, 431) / 2;
	WRITE_LINE(10, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(10, 16058, 431) + LINE(9, 15625, 968) / 2;
	WRITE_LINE(9, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(9, 15625, 968) + LINE(8, 14655, 1620) / 2;
	WRITE_LINE(8, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(8, 14655, 1620);
	tmp2 = Acc;
	Acc = LINE(7, 13033, 1624) + LINE(6, 11407, 1992) / 2;
	WRITE_LINE(6, 11407) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11407, 1992);
	WRITE_LINE(5, 9413) = Acc;
	Acc = LINE(5, 9413, 2110) * 0.9375 + LINE(4, 7301, 2371) / 2;
	WRITE_LINE(4, 7301) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7301, 2371);
	WRITE_LINE(3, 4928) = Acc;
	Acc = LINE(3, 4928, 2157) * 0.9375 + LINE(2, 2769, 2712) / 2;
	WRITE_LINE(2, 2769) = -Acc;
	Acc = Acc * -0.75 + LINE(2, 2769, 2712) * 1.5;
	tmp1 = Acc;
	Acc = LINE(1, 55, 1) / 4 + tmp1 / 2;
	WRITE_LINE(1, 55) = Acc;
	Acc = WRITE_LINE(1, 55) + tmp2;
	WRITE_LINE(7, 13033) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=2712, taps=[2712]
// Delay line 4: length=2157, taps=[671, 2003, 2157]
// Delay line 5: length=2371, taps=[2371]
// Delay line 6: length=2110, taps=[890, 1891, 2110]
// Delay line 7: length=1992, taps=[1992]
// Delay line 8: length=1624, taps=[21, 1010, 1624]
// Delay line 9: length=1620, taps=[1620]
// Delay line 10: length=968, taps=[968]
// Delay line 11: length=431, taps=[431]
// Delay line 12: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_50(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 13033, 21) / 4 + -LINE(6, 9413, 1891) / 4 + -LINE(4, 4928, 2003) / 4;
	tmp3 = -Acc;
	Acc = -LINE(8, 13033, 1010) / 4 + -LINE(6, 9413, 890) / 4 + -LINE(4, 4928, 671) / 4;
	tmp5 = -Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 55, 1) / 2;
	WRITE_LINE(2, 55) = Acc;
	Acc = LINE(2, 55, 1) * 2.53125 + LINE(12, 16381, 321) / 2;
	WRITE_LINE(12, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(12, 16381, 321) + LINE(11, 16058, 431) / 2;
	WRITE_LINE(11, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(11, 16058, 431) + LINE(10, 15625, 968) / 2;
	WRITE_LINE(10, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(10, 15625, 968) + LINE(9, 14655, 1620) / 2;
	WRITE_LINE(9, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(9, 14655, 1620);
	tmp2 = Acc;
	Acc = LINE(8, 13033, 1624) + LINE(7, 11407, 1992) / 2;
	WRITE_LINE(7, 11407) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11407, 1992);
	WRITE_LINE(6, 9413) = Acc;
	Acc = LINE(6, 9413, 2110) * 0.9375 + LINE(5, 7301, 2371) / 2;
	WRITE_LINE(5, 7301) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7301, 2371);
	WRITE_LINE(4, 4928) = Acc;
	Acc = LINE(4, 4928, 2157) * 0.9375 + LINE(3, 2769, 2712) / 2;
	WRITE_LINE(3, 2769) = -Acc;
	Acc = Acc / 4 + -LINE(3, 2769, 2712) / 2 + LINE(1, 52, 1) / 2;
	WRITE_LINE(1, 52) = Acc;
	Acc = WRITE_LINE(1, 52) + tmp2;
	WRITE_LINE(8, 13033) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=2443, taps=[163, 233, 412, 534, 761, 875, 1065, 1119, 1233, 1434, 1555, 1742, 1862, 2046, 2149, 2256, 2443]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=2, taps=[2]
// Delay line 3: length=133, taps=[133]
// Delay line 4: length=75, taps=[75]
// Delay line 5: length=32, taps=[32]
// Delay line 6: length=173, taps=[173]
// Delay line 7: length=53, taps=[53]
// Delay line 8: length=21, taps=[21]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_51(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 11, 2) / 2 + LINE(8, 2298, 21) / 2;
	WRITE_LINE(8, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2298, 21) + LINE(7, 2275, 53) / 2;
	WRITE_LINE(7, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2275, 53) + LINE(6, 2220, 173) / 2;
	WRITE_LINE(6, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2220, 173);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(2, 11, 2) / 2 + LINE(5, 2045, 32) / 2;
	WRITE_LINE(5, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2045, 32) + LINE(4, 2011, 75) / 2;
	WRITE_LINE(4, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2011, 75) + LINE(3, 1934, 133) / 2;
	WRITE_LINE(3, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1934, 133);
	tmp5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=3569, taps=[163, 233, 412, 534, 761, 875, 1065, 1119, 1233, 1434, 1555, 1742, 1862, 2046, 2149, 2256, 2443, 2579, 2721, 2873, 3036, 3121, 3267, 3451, 3569]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=2, taps=[2]
// Delay line 3: length=133, taps=[133]
// Delay line 4: length=75, taps=[75]
// Delay line 5: length=32, taps=[32]
// Delay line 6: length=173, taps=[173]
// Delay line 7: length=53, taps=[53]
// Delay line 8: length=21, taps=[21]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_52(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 11, 2) / 2 + LINE(8, 2298, 21) / 2;
	WRITE_LINE(8, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2298, 21) + LINE(7, 2275, 53) / 2;
	WRITE_LINE(7, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2275, 53) + LINE(6, 2220, 173) / 2;
	WRITE_LINE(6, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2220, 173);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(2, 11, 2) / 2 + LINE(5, 2045, 32) / 2;
	WRITE_LINE(5, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2045, 32) + LINE(4, 2011, 75) / 2;
	WRITE_LINE(4, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2011, 75) + LINE(3, 1934, 133) / 2;
	WRITE_LINE(3, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1934, 133);
	tmp5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=4556, taps=[163, 233, 412, 534, 761, 875, 1065, 1119, 1233, 1434, 1555, 1742, 1862, 2046, 2149, 2256, 2443, 2579, 2721, 2873, 3036, 3121, 3267, 3451, 3569, 3725, 3889, 4034, 4152, 4257, 4492, 4556]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=2, taps=[2]
// Delay line 3: length=133, taps=[133]
// Delay line 4: length=75, taps=[75]
// Delay line 5: length=32, taps=[32]
// Delay line 6: length=173, taps=[173]
// Delay line 7: length=53, taps=[53]
// Delay line 8: length=21, taps=[21]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_53(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 11, 2) / 2 + LINE(8, 2298, 21) / 2;
	WRITE_LINE(8, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2298, 21) + LINE(7, 2275, 53) / 2;
	WRITE_LINE(7, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2275, 53) + LINE(6, 2220, 173) / 2;
	WRITE_LINE(6, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2220, 173);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(2, 11, 2) / 2 + LINE(5, 2045, 32) / 2;
	WRITE_LINE(5, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2045, 32) + LINE(4, 2011, 75) / 2;
	WRITE_LINE(4, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2011, 75) + LINE(3, 1934, 133) / 2;
	WRITE_LINE(3, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1934, 133);
	tmp5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2 + LINE(0, 0, 3725) / 2 + LINE(0, 0, 3889) / 2 + LINE(0, 0, 4034) / 2 + LINE(0, 0, 4152) / 2 + LINE(0, 0, 4257) / 2 + LINE(0, 0, 4492) / 2 + LINE(0, 0, 4556) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=5837, taps=[163, 233, 412, 534, 761, 875, 1065, 1119, 1233, 1434, 1555, 1742, 1862, 2046, 2149, 2256, 2443, 2579, 2721, 2873, 3036, 3121, 3267, 3451, 3569, 3725, 3889, 4034, 4152, 4257, 4492, 4556, 4727, 4849, 5034, 5129, 5235, 5421, 5534, 5759, 5837]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=2, taps=[2]
// Delay line 3: length=133, taps=[133]
// Delay line 4: length=75, taps=[75]
// Delay line 5: length=32, taps=[32]
// Delay line 6: length=173, taps=[173]
// Delay line 7: length=53, taps=[53]
// Delay line 8: length=21, taps=[21]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_54(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 11, 2) / 2 + LINE(8, 2298, 21) / 2;
	WRITE_LINE(8, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2298, 21) + LINE(7, 2275, 53) / 2;
	WRITE_LINE(7, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2275, 53) + LINE(6, 2220, 173) / 2;
	WRITE_LINE(6, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2220, 173);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(2, 11, 2) / 2 + LINE(5, 2045, 32) / 2;
	WRITE_LINE(5, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2045, 32) + LINE(4, 2011, 75) / 2;
	WRITE_LINE(4, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2011, 75) + LINE(3, 1934, 133) / 2;
	WRITE_LINE(3, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1934, 133);
	tmp5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2 + LINE(0, 0, 3725) / 2 + LINE(0, 0, 3889) / 2 + LINE(0, 0, 4034) / 2 + LINE(0, 0, 4152) / 2 + LINE(0, 0, 4257) / 2 + LINE(0, 0, 4492) / 2 + LINE(0, 0, 4556) / 2 + LINE(0, 0, 4727) / 2 + LINE(0, 0, 4849) / 2 + LINE(0, 0, 5034) / 2 + LINE(0, 0, 5129) / 2 + LINE(0, 0, 5235) / 2 + LINE(0, 0, 5421) / 2 + LINE(0, 0, 5534) / 2 + LINE(0, 0, 5759) / 2 + LINE(0, 0, 5837) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=7039, taps=[163, 233, 412, 534, 761, 875, 1065, 1119, 1233, 1434, 1555, 1742, 1862, 2046, 2149, 2256, 2443, 2579, 2721, 2873, 3036, 3121, 3267, 3451, 3569, 3725, 3889, 4034, 4152, 4257, 4492, 4556, 4727, 4849, 5034, 5129, 5235, 5421, 5534, 5759, 5837, 6035, 6159, 6223, 6446, 6534, 6782, 6859, 7039]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=2, taps=[2]
// Delay line 3: length=133, taps=[133]
// Delay line 4: length=75, taps=[75]
// Delay line 5: length=32, taps=[32]
// Delay line 6: length=173, taps=[173]
// Delay line 7: length=53, taps=[53]
// Delay line 8: length=21, taps=[21]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_55(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 11, 2) / 2 + LINE(8, 2298, 21) / 2;
	WRITE_LINE(8, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2298, 21) + LINE(7, 2275, 53) / 2;
	WRITE_LINE(7, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2275, 53) + LINE(6, 2220, 173) / 2;
	WRITE_LINE(6, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2220, 173);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(2, 11, 2) / 2 + LINE(5, 2045, 32) / 2;
	WRITE_LINE(5, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2045, 32) + LINE(4, 2011, 75) / 2;
	WRITE_LINE(4, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2011, 75) + LINE(3, 1934, 133) / 2;
	WRITE_LINE(3, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1934, 133);
	tmp5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2 + LINE(0, 0, 3725) / 2 + LINE(0, 0, 3889) / 2 + LINE(0, 0, 4034) / 2 + LINE(0, 0, 4152) / 2 + LINE(0, 0, 4257) / 2 + LINE(0, 0, 4492) / 2 + LINE(0, 0, 4556) / 2 + LINE(0, 0, 4727) / 2 + LINE(0, 0, 4849) / 2 + LINE(0, 0, 5034) / 2 + LINE(0, 0, 5129) / 2 + LINE(0, 0, 5235) / 2 + LINE(0, 0, 5421) / 2 + LINE(0, 0, 5534) / 2 + LINE(0, 0, 5759) / 2 + LINE(0, 0, 5837) / 2 + LINE(0, 0, 6035) / 2 + LINE(0, 0, 6159) / 2 + LINE(0, 0, 6223) / 2 + LINE(0, 0, 6446) / 2 + LINE(0, 0, 6534) / 2 + LINE(0, 0, 6782) / 2 + LINE(0, 0, 6859) / 2 + LINE(0, 0, 7039) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=8278, taps=[163, 233, 412, 534, 761, 875, 1065, 1119, 1233, 1434, 1555, 1742, 1862, 2046, 2149, 2256, 2443, 2579, 2721, 2873, 3036, 3121, 3267, 3451, 3569, 3725, 3889, 4034, 4152, 4257, 4492, 4556, 4727, 4849, 5034, 5129, 5235, 5421, 5534, 5759, 5837, 6035, 6159, 6223, 6446, 6534, 6782, 6859, 7039, 7126, 7221, 7439, 7534, 7736, 7891, 8034, 8146, 8278]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=2, taps=[2]
// Delay line 3: length=133, taps=[133]
// Delay line 4: length=75, taps=[75]
// Delay line 5: length=32, taps=[32]
// Delay line 6: length=173, taps=[173]
// Delay line 7: length=53, taps=[53]
// Delay line 8: length=21, taps=[21]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_56(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 11, 2) / 2 + LINE(8, 2298, 21) / 2;
	WRITE_LINE(8, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2298, 21) + LINE(7, 2275, 53) / 2;
	WRITE_LINE(7, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2275, 53) + LINE(6, 2220, 173) / 2;
	WRITE_LINE(6, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2220, 173);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(2, 11, 2) / 2 + LINE(5, 2045, 32) / 2;
	WRITE_LINE(5, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2045, 32) + LINE(4, 2011, 75) / 2;
	WRITE_LINE(4, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2011, 75) + LINE(3, 1934, 133) / 2;
	WRITE_LINE(3, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1934, 133);
	tmp5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2 + LINE(0, 0, 3725) / 2 + LINE(0, 0, 3889) / 2 + LINE(0, 0, 4034) / 2 + LINE(0, 0, 4152) / 2 + LINE(0, 0, 4257) / 2 + LINE(0, 0, 4492) / 2 + LINE(0, 0, 4556) / 2 + LINE(0, 0, 4727) / 2 + LINE(0, 0, 4849) / 2 + LINE(0, 0, 5034) / 2 + LINE(0, 0, 5129) / 2 + LINE(0, 0, 5235) / 2 + LINE(0, 0, 5421) / 2 + LINE(0, 0, 5534) / 2 + LINE(0, 0, 5759) / 2 + LINE(0, 0, 5837) / 2 + LINE(0, 0, 6035) / 2 + LINE(0, 0, 6159) / 2 + LINE(0, 0, 6223) / 2 + LINE(0, 0, 6446) / 2 + LINE(0, 0, 6534) / 2 + LINE(0, 0, 6782) / 2 + LINE(0, 0, 6859) / 2 + LINE(0, 0, 7039) / 2 + LINE(0, 0, 7126) / 2 + LINE(0, 0, 7221) / 2 + LINE(0, 0, 7439) / 2 + LINE(0, 0, 7534) / 2 + LINE(0, 0, 7736) / 2 + LINE(0, 0, 7891) / 2 + LINE(0, 0, 8034) / 2 + LINE(0, 0, 8146) / 2 + LINE(0, 0, 8278) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=9215, taps=[163, 233, 412, 534, 761, 875, 1065, 1119, 1233, 1434, 1555, 1742, 1862, 2046, 2149, 2256, 2443, 2579, 2721, 2873, 3036, 3121, 3267, 3451, 3569, 3725, 3889, 4034, 4152, 4257, 4492, 4556, 4727, 4849, 5034, 5129, 5235, 5421, 5534, 5759, 5837, 6035, 6159, 6223, 6446, 6534, 6782, 6859, 7039, 7126, 7221, 7439, 7534, 7736, 7891, 8034, 8146, 8278, 8447, 8565, 8700, 8885, 9012, 9171, 9215]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=2, taps=[2]
// Delay line 3: length=133, taps=[133]
// Delay line 4: length=75, taps=[75]
// Delay line 5: length=32, taps=[32]
// Delay line 6: length=173, taps=[173]
// Delay line 7: length=53, taps=[53]
// Delay line 8: length=21, taps=[21]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_57(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 11, 2) / 2 + LINE(8, 2298, 21) / 2;
	WRITE_LINE(8, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2298, 21) + LINE(7, 2275, 53) / 2;
	WRITE_LINE(7, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2275, 53) + LINE(6, 2220, 173) / 2;
	WRITE_LINE(6, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2220, 173);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(2, 11, 2) / 2 + LINE(5, 2045, 32) / 2;
	WRITE_LINE(5, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2045, 32) + LINE(4, 2011, 75) / 2;
	WRITE_LINE(4, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2011, 75) + LINE(3, 1934, 133) / 2;
	WRITE_LINE(3, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1934, 133);
	tmp5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2 + LINE(0, 0, 3725) / 2 + LINE(0, 0, 3889) / 2 + LINE(0, 0, 4034) / 2 + LINE(0, 0, 4152) / 2 + LINE(0, 0, 4257) / 2 + LINE(0, 0, 4492) / 2 + LINE(0, 0, 4556) / 2 + LINE(0, 0, 4727) / 2 + LINE(0, 0, 4849) / 2 + LINE(0, 0, 5034) / 2 + LINE(0, 0, 5129) / 2 + LINE(0, 0, 5235) / 2 + LINE(0, 0, 5421) / 2 + LINE(0, 0, 5534) / 2 + LINE(0, 0, 5759) / 2 + LINE(0, 0, 5837) / 2 + LINE(0, 0, 6035) / 2 + LINE(0, 0, 6159) / 2 + LINE(0, 0, 6223) / 2 + LINE(0, 0, 6446) / 2 + LINE(0, 0, 6534) / 2 + LINE(0, 0, 6782) / 2 + LINE(0, 0, 6859) / 2 + LINE(0, 0, 7039) / 2 + LINE(0, 0, 7126) / 2 + LINE(0, 0, 7221) / 2 + LINE(0, 0, 7439) / 2 + LINE(0, 0, 7534) / 2 + LINE(0, 0, 7736) / 2 + LINE(0, 0, 7891) / 2 + LINE(0, 0, 8034) / 2 + LINE(0, 0, 8146) / 2 + LINE(0, 0, 8278) / 2 + LINE(0, 0, 8447) / 2 + LINE(0, 0, 8565) / 2 + LINE(0, 0, 8700) / 2 + LINE(0, 0, 8885) / 2 + LINE(0, 0, 9012) / 2 + LINE(0, 0, 9171) / 2 + LINE(0, 0, 9215) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=11479, taps=[163, 233, 412, 534, 761, 875, 1065, 1119, 1233, 1434, 1555, 1742, 1862, 2046, 2149, 2256, 2443, 2579, 2721, 2873, 3036, 3121, 3267, 3451, 3569, 3725, 3889, 4034, 4152, 4257, 4492, 4556, 4727, 4849, 5034, 5129, 5235, 5421, 5534, 5759, 5837, 6035, 6159, 6223, 6446, 6534, 6782, 6859, 7039, 7126, 7221, 7439, 7534, 7736, 7891, 8034, 8146, 8278, 8447, 8565, 8700, 8885, 9012, 9171, 9215, 9449, 9513, 9765, 9867, 10046, 10110, 10285, 10428, 10578, 10734, 10815, 11023, 11185, 11254, 11479]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=2, taps=[2]
// Delay line 3: length=133, taps=[133]
// Delay line 4: length=75, taps=[75]
// Delay line 5: length=32, taps=[32]
// Delay line 6: length=173, taps=[173]
// Delay line 7: length=53, taps=[53]
// Delay line 8: length=21, taps=[21]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_58(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 11, 2) / 2 + LINE(8, 2298, 21) / 2;
	WRITE_LINE(8, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2298, 21) + LINE(7, 2275, 53) / 2;
	WRITE_LINE(7, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2275, 53) + LINE(6, 2220, 173) / 2;
	WRITE_LINE(6, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2220, 173);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(2, 11, 2) / 2 + LINE(5, 2045, 32) / 2;
	WRITE_LINE(5, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2045, 32) + LINE(4, 2011, 75) / 2;
	WRITE_LINE(4, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2011, 75) + LINE(3, 1934, 133) / 2;
	WRITE_LINE(3, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1934, 133);
	tmp5 = Acc;
	*out_left = tmp5;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2 + LINE(0, 0, 3725) / 2 + LINE(0, 0, 3889) / 2 + LINE(0, 0, 4034) / 2 + LINE(0, 0, 4152) / 2 + LINE(0, 0, 4257) / 2 + LINE(0, 0, 4492) / 2 + LINE(0, 0, 4556) / 2 + LINE(0, 0, 4727) / 2 + LINE(0, 0, 4849) / 2 + LINE(0, 0, 5034) / 2 + LINE(0, 0, 5129) / 2 + LINE(0, 0, 5235) / 2 + LINE(0, 0, 5421) / 2 + LINE(0, 0, 5534) / 2 + LINE(0, 0, 5759) / 2 + LINE(0, 0, 5837) / 2 + LINE(0, 0, 6035) / 2 + LINE(0, 0, 6159) / 2 + LINE(0, 0, 6223) / 2 + LINE(0, 0, 6446) / 2 + LINE(0, 0, 6534) / 2 + LINE(0, 0, 6782) / 2 + LINE(0, 0, 6859) / 2 + LINE(0, 0, 7039) / 2 + LINE(0, 0, 7126) / 2 + LINE(0, 0, 7221) / 2 + LINE(0, 0, 7439) / 2 + LINE(0, 0, 7534) / 2 + LINE(0, 0, 7736) / 2 + LINE(0, 0, 7891) / 2 + LINE(0, 0, 8034) / 2 + LINE(0, 0, 8146) / 2 + LINE(0, 0, 8278) / 2 + LINE(0, 0, 8447) / 2 + LINE(0, 0, 8565) / 2 + LINE(0, 0, 8700) / 2 + LINE(0, 0, 8885) / 2 + LINE(0, 0, 9012) / 2 + LINE(0, 0, 9171) / 2 + LINE(0, 0, 9215) / 2 + LINE(0, 0, 9449) / 2 + LINE(0, 0, 9513) / 2 + LINE(0, 0, 9765) / 2 + LINE(0, 0, 9867) / 2 + LINE(0, 0, 10046) / 2 + LINE(0, 0, 10110) / 2 + LINE(0, 0, 10285) / 2 + LINE(0, 0, 10428) / 2 + LINE(0, 0, 10578) / 2 + LINE(0, 0, 10734) / 2 + LINE(0, 0, 10815) / 2 + LINE(0, 0, 11023) / 2 + LINE(0, 0, 11185) / 2 + LINE(0, 0, 11254) / 2 + LINE(0, 0, 11479) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=13046, taps=[163, 233, 412, 534, 761, 875, 1065, 1119, 1233, 1434, 1555, 1742, 1862, 2046, 2149, 2256, 2443, 2579, 2721, 2873, 3036, 3121, 3267, 3451, 3569, 3725, 3889, 4034, 4152, 4257, 4492, 4556, 4727, 4849, 5034, 5129, 5235, 5421, 5534, 5759, 5837, 6035, 6159, 6223, 6446, 6534, 6782, 6859, 7039, 7126, 7221, 7439, 7534, 7736, 7891, 8034, 8146, 8278, 8447, 8565, 8700, 8885, 9012, 9171, 9215, 9449, 9513, 9765, 9867, 10046, 10110, 10285, 10428, 10578, 10734, 10815, 11023, 11185, 11254, 11479, 11546, 11715, 11847, 12074, 12112, 12279, 12415, 12516, 12746, 12815, 13046]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=2, taps=[2]
// Delay line 3: length=133, taps=[133]
// Delay line 4: length=75, taps=[75]
// Delay line 5: length=32, taps=[32]
// Delay line 6: length=173, taps=[173]
// Delay line 7: length=53, taps=[53]
// Delay line 8: length=21, taps=[21]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_59(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 11, 2) / 2 + LINE(8, 2298, 21) / 2;
	WRITE_LINE(8, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2298, 21) + LINE(7, 2275, 53) / 2;
	WRITE_LINE(7, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2275, 53) + LINE(6, 2220, 173) / 2;
	WRITE_LINE(6, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2220, 173);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(2, 11, 2) / 2 + LINE(5, 2045, 32) / 2;
	WRITE_LINE(5, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2045, 32) + LINE(4, 2011, 75) / 2;
	WRITE_LINE(4, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2011, 75) + LINE(3, 1934, 133) / 2;
	WRITE_LINE(3, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1934, 133);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2 + LINE(0, 0, 3725) / 2 + LINE(0, 0, 3889) / 2 + LINE(0, 0, 4034) / 2 + LINE(0, 0, 4152) / 2 + LINE(0, 0, 4257) / 2 + LINE(0, 0, 4492) / 2 + LINE(0, 0, 4556) / 2 + LINE(0, 0, 4727) / 2 + LINE(0, 0, 4849) / 2 + LINE(0, 0, 5034) / 2 + LINE(0, 0, 5129) / 2 + LINE(0, 0, 5235) / 2 + LINE(0, 0, 5421) / 2 + LINE(0, 0, 5534) / 2 + LINE(0, 0, 5759) / 2 + LINE(0, 0, 5837) / 2 + LINE(0, 0, 6035) / 2 + LINE(0, 0, 6159) / 2 + LINE(0, 0, 6223) / 2 + LINE(0, 0, 6446) / 2 + LINE(0, 0, 6534) / 2 + LINE(0, 0, 6782) / 2 + LINE(0, 0, 6859) / 2 + LINE(0, 0, 7039) / 2 + LINE(0, 0, 7126) / 2 + LINE(0, 0, 7221) / 2 + LINE(0, 0, 7439) / 2 + LINE(0, 0, 7534) / 2 + LINE(0, 0, 7736) / 2 + LINE(0, 0, 7891) / 2 + LINE(0, 0, 8034) / 2 + LINE(0, 0, 8146) / 2 + LINE(0, 0, 8278) / 2 + LINE(0, 0, 8447) / 2 + LINE(0, 0, 8565) / 2 + LINE(0, 0, 8700) / 2 + LINE(0, 0, 8885) / 2 + LINE(0, 0, 9012) / 2 + LINE(0, 0, 9171) / 2 + LINE(0, 0, 9215) / 2 + LINE(0, 0, 9449) / 2 + LINE(0, 0, 9513) / 2 + LINE(0, 0, 9765) / 2 + LINE(0, 0, 9867) / 2 + LINE(0, 0, 10046) / 2 + LINE(0, 0, 10110) / 2 + LINE(0, 0, 10285) / 2 + LINE(0, 0, 10428) / 2 + LINE(0, 0, 10578) / 2 + LINE(0, 0, 10734) / 2 + LINE(0, 0, 10815) / 2 + LINE(0, 0, 11023) / 2 + LINE(0, 0, 11185) / 2 + LINE(0, 0, 11254) / 2 + LINE(0, 0, 11479) / 2 + LINE(0, 0, 11546) / 2 + LINE(0, 0, 11715) / 2 + LINE(0, 0, 11847) / 2 + LINE(0, 0, 12074) / 2 + LINE(0, 0, 12112) / 2 + LINE(0, 0, 12279) / 2 + LINE(0, 0, 12415) / 2 + LINE(0, 0, 12516) / 2 + LINE(0, 0, 12746) / 2 + LINE(0, 0, 12815) / 2 + LINE(0, 0, 13046) / 2;
	WRITE_LINE(2, 11) = Acc;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=7031, taps=[163, 233, 412, 534, 761, 875, 1065, 1119, 1233, 1434, 1555, 1742, 1862, 2046, 2149, 2256, 2443, 2579, 2721, 2873, 3036, 3121, 3267, 3451, 3569, 3725, 3889, 4034, 4152, 4257, 4492, 4556, 4727, 4849, 5034, 5129, 5235, 5421, 5534, 5759, 5837, 6035, 6159, 6223, 6446, 7031]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=133, taps=[133]
// Delay line 3: length=75, taps=[75]
// Delay line 4: length=32, taps=[32]
// Delay line 5: length=173, taps=[173]
// Delay line 6: length=53, taps=[53]
// Delay line 7: length=21, taps=[21]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_60(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(7, 2298, 21) / 2;
	WRITE_LINE(7, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2298, 21) + LINE(6, 2275, 53) / 2;
	WRITE_LINE(6, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2275, 53) + LINE(5, 2220, 173) / 2;
	WRITE_LINE(5, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2220, 173) + LINE(0, 0, 7031);
	tmp3 = Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(4, 2045, 32) / 2;
	WRITE_LINE(4, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2045, 32) + LINE(3, 2011, 75) / 2;
	WRITE_LINE(3, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2011, 75) + LINE(2, 1934, 133) / 2;
	WRITE_LINE(2, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1934, 133) + LINE(0, 0, 7031);
	tmp5 = Acc;
	Acc = LINE(0, 0, 163) / 32 + LINE(0, 0, 233) / 32 + LINE(0, 0, 412) / 32 + LINE(0, 0, 534) / 32 + LINE(0, 0, 761) / 32 + LINE(0, 0, 875) / 32 + LINE(0, 0, 1434) / 32 + LINE(0, 0, 1119) / 32 + LINE(0, 0, 1862) / 32 + -LINE(0, 0, 1065) / 16 + -LINE(0, 0, 1555) / 16 + -LINE(0, 0, 1742) / 16 + -LINE(0, 0, 1233) / 16 + -LINE(0, 0, 2046) / 16 + -LINE(0, 0, 2149) / 16 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 2443) / 16 + -LINE(0, 0, 3121) / 16 + -LINE(0, 0, 2721) / 16 + LINE(0, 0, 2256) / 8 + LINE(0, 0, 3036) / 8 + LINE(0, 0, 2579) / 8 + LINE(0, 0, 3267) / 8 + LINE(0, 0, 3451) / 8 + LINE(0, 0, 3569) / 8 + LINE(0, 0, 4492) / 8 + LINE(0, 0, 3889) / 8 + LINE(0, 0, 4034) / 8 + LINE(0, 0, 4152) / 8 + LINE(0, 0, 4849) / 8 + -LINE(0, 0, 3725) / 4 + -LINE(0, 0, 4556) / 4 + -LINE(0, 0, 4727) / 4 + -LINE(0, 0, 4257) / 4 + -LINE(0, 0, 5034) / 4 + -LINE(0, 0, 5837) / 4 + -LINE(0, 0, 5235) / 4 + -LINE(0, 0, 5421) / 4 + -LINE(0, 0, 6159) / 4 + LINE(0, 0, 5759) / 2 + LINE(0, 0, 5129) / 2 + LINE(0, 0, 6035) / 2 + LINE(0, 0, 5534) / 2 + LINE(0, 0, 6223) / 2 + LINE(0, 0, 6446) / 2;
	WRITE_LINE(1, 11) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=9375, taps=[163, 233, 412, 534, 761, 875, 1065, 1119, 1233, 1434, 1555, 1742, 1862, 2046, 2149, 2256, 2443, 2579, 2721, 2873, 3036, 3121, 3267, 3451, 3569, 3725, 3889, 4034, 4152, 4257, 4492, 4556, 4727, 4849, 5034, 5129, 5235, 5421, 5534, 5759, 5837, 6035, 6159, 6223, 6446, 6534, 6782, 6859, 7039, 7126, 7221, 7439, 7534, 7736, 7891, 8034, 8146, 8278, 8447, 8565, 8700, 9375]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=133, taps=[133]
// Delay line 3: length=75, taps=[75]
// Delay line 4: length=32, taps=[32]
// Delay line 5: length=173, taps=[173]
// Delay line 6: length=53, taps=[53]
// Delay line 7: length=21, taps=[21]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_61(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(7, 2298, 21) / 2;
	WRITE_LINE(7, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2298, 21) + LINE(6, 2275, 53) / 2;
	WRITE_LINE(6, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2275, 53) + LINE(5, 2220, 173) / 2;
	WRITE_LINE(5, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2220, 173) + LINE(0, 0, 9375);
	tmp3 = Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(4, 2045, 32) / 2;
	WRITE_LINE(4, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2045, 32) + LINE(3, 2011, 75) / 2;
	WRITE_LINE(3, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2011, 75) + LINE(2, 1934, 133) / 2;
	WRITE_LINE(2, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1934, 133) + LINE(0, 0, 9375);
	tmp5 = Acc;
	*out_left = tmp5;
	Acc = LINE(0, 0, 163) / 32 + LINE(0, 0, 233) / 32 + LINE(0, 0, 412) / 32 + LINE(0, 0, 534) / 32 + LINE(0, 0, 761) / 32 + LINE(0, 0, 875) / 32 + LINE(0, 0, 2721) / 32 + LINE(0, 0, 1119) / 32 + LINE(0, 0, 1233) / 32 + LINE(0, 0, 1434) / 32 + LINE(0, 0, 2443) / 32 + LINE(0, 0, 1742) / 32 + LINE(0, 0, 1862) / 32 + -LINE(0, 0, 2046) / 16 + -LINE(0, 0, 2149) / 16 + -LINE(0, 0, 2256) / 16 + -LINE(0, 0, 1555) / 16 + -LINE(0, 0, 2579) / 16 + -LINE(0, 0, 1065) / 16 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 3036) / 16 + -LINE(0, 0, 4152) / 16 + -LINE(0, 0, 3267) / 16 + -LINE(0, 0, 3451) / 16 + -LINE(0, 0, 4492) / 16 + -LINE(0, 0, 3725) / 16 + LINE(0, 0, 3889) / 8 + LINE(0, 0, 4034) / 8 + LINE(0, 0, 3121) / 8 + LINE(0, 0, 4257) / 8 + LINE(0, 0, 3569) / 8 + LINE(0, 0, 4556) / 8 + LINE(0, 0, 4727) / 8 + LINE(0, 0, 4849) / 8 + LINE(0, 0, 5837) / 8 + LINE(0, 0, 5129) / 8 + LINE(0, 0, 5235) / 8 + LINE(0, 0, 5421) / 8 + LINE(0, 0, 6159) / 8 + -LINE(0, 0, 5759) / 4 + -LINE(0, 0, 5034) / 4 + -LINE(0, 0, 6035) / 4 + -LINE(0, 0, 5534) / 4 + -LINE(0, 0, 6223) / 4 + -LINE(0, 0, 6446) / 4 + -LINE(0, 0, 6534) / 4 + -LINE(0, 0, 8034) / 4 + -LINE(0, 0, 6859) / 4 + -LINE(0, 0, 7039) / 4 + -LINE(0, 0, 7736) / 4 + -LINE(0, 0, 7221) / 4 + -LINE(0, 0, 7439) / 4 + LINE(0, 0, 7534) / 2 + LINE(0, 0, 7126) / 2 + LINE(0, 0, 7891) / 2 + LINE(0, 0, 6782) / 2 + LINE(0, 0, 8146) / 2 + LINE(0, 0, 8278) / 2 + LINE(0, 0, 8447) / 2 + LINE(0, 0, 8565) / 2 + LINE(0, 0, 8700) / 2;
	WRITE_LINE(1, 11) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=11718, taps=[163, 233, 412, 534, 761, 875, 1065, 1119, 1233, 1434, 1555, 1742, 1862, 2046, 2149, 2256, 2443, 2579, 2721, 2873, 3036, 3121, 3267, 3451, 3569, 3725, 3889, 4034, 4152, 4257, 4492, 4556, 4727, 4849, 5034, 5129, 5235, 5421, 5534, 5759, 5837, 6035, 6159, 6223, 6446, 6534, 6782, 6859, 7039, 7126, 7221, 7439, 7534, 7736, 7891, 8034, 8146, 8278, 8447, 8565, 8700, 8885, 9012, 9171, 9215, 9449, 9513, 9765, 9867, 10046, 10110, 10285, 10428, 10578, 10734, 10815, 11023, 11185, 11254, 11718]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=133, taps=[133]
// Delay line 3: length=75, taps=[75]
// Delay line 4: length=32, taps=[32]
// Delay line 5: length=173, taps=[173]
// Delay line 6: length=53, taps=[53]
// Delay line 7: length=21, taps=[21]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_62(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(7, 2298, 21) / 2;
	WRITE_LINE(7, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2298, 21) + LINE(6, 2275, 53) / 2;
	WRITE_LINE(6, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2275, 53) + LINE(5, 2220, 173) / 2;
	WRITE_LINE(5, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2220, 173) + LINE(0, 0, 11718);
	tmp3 = Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(4, 2045, 32) / 2;
	WRITE_LINE(4, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2045, 32) + LINE(3, 2011, 75) / 2;
	WRITE_LINE(3, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2011, 75) + LINE(2, 1934, 133) / 2;
	WRITE_LINE(2, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1934, 133) + LINE(0, 0, 11718);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
	Acc = LINE(0, 0, 163) / 32 + LINE(0, 0, 233) / 32 + LINE(0, 0, 412) / 32 + LINE(0, 0, 534) / 32 + LINE(0, 0, 761) / 32 + LINE(0, 0, 875) / 32 + LINE(0, 0, 1065) / 32 + LINE(0, 0, 1119) / 32 + LINE(0, 0, 1233) / 32 + LINE(0, 0, 1434) / 32 + LINE(0, 0, 2579) / 32 + LINE(0, 0, 1742) / 32 + LINE(0, 0, 1862) / 32 + LINE(0, 0, 3036) / 32 + LINE(0, 0, 2149) / 32 + -LINE(0, 0, 2256) / 16 + -LINE(0, 0, 2443) / 16 + -LINE(0, 0, 1555) / 16 + -LINE(0, 0, 2721) / 16 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 2046) / 16 + -LINE(0, 0, 3121) / 16 + -LINE(0, 0, 3267) / 16 + -LINE(0, 0, 3451) / 16 + -LINE(0, 0, 3569) / 16 + -LINE(0, 0, 5034) / 16 + -LINE(0, 0, 3889) / 16 + -LINE(0, 0, 4034) / 16 + -LINE(0, 0, 4727) / 16 + -LINE(0, 0, 4257) / 16 + LINE(0, 0, 4492) / 8 + LINE(0, 0, 4556) / 8 + LINE(0, 0, 4152) / 8 + LINE(0, 0, 4849) / 8 + LINE(0, 0, 3725) / 8 + LINE(0, 0, 5129) / 8 + LINE(0, 0, 5235) / 8 + LINE(0, 0, 5421) / 8 + LINE(0, 0, 5534) / 8 + LINE(0, 0, 5759) / 8 + LINE(0, 0, 6859) / 8 + LINE(0, 0, 6035) / 8 + LINE(0, 0, 6159) / 8 + LINE(0, 0, 6223) / 8 + LINE(0, 0, 7126) / 8 + LINE(0, 0, 6534) / 8 + -LINE(0, 0, 6782) / 4 + -LINE(0, 0, 5837) / 4 + -LINE(0, 0, 7039) / 4 + -LINE(0, 0, 6446) / 4 + -LINE(0, 0, 7221) / 4 + -LINE(0, 0, 7439) / 4 + -LINE(0, 0, 7534) / 4 + -LINE(0, 0, 7736) / 4 + -LINE(0, 0, 7891) / 4 + -LINE(0, 0, 8034) / 4 + -LINE(0, 0, 9215) / 4 + -LINE(0, 0, 8278) / 4 + -LINE(0, 0, 8447) / 4 + -LINE(0, 0, 8565) / 4 + -LINE(0, 0, 9513) / 4 + -LINE(0, 0, 8885) / 4 + LINE(0, 0, 9012) / 2 + LINE(0, 0, 9171) / 2 + LINE(0, 0, 8146) / 2 + LINE(0, 0, 9449) / 2 + LINE(0, 0, 8700) / 2 + LINE(0, 0, 9765) / 2 + LINE(0, 0, 9867) / 2 + LINE(0, 0, 10046) / 2 + LINE(0, 0, 10110) / 2 + LINE(0, 0, 10285) / 2 + LINE(0, 0, 10428) / 2 + LINE(0, 0, 10578) / 2 + LINE(0, 0, 10734) / 2 + LINE(0, 0, 10815) / 2 + LINE(0, 0, 11023) / 2 + LINE(0, 0, 11185) / 2 + LINE(0, 0, 11254) / 2;
	WRITE_LINE(1, 11) = Acc;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=14000, taps=[1065, 1119, 1233, 1434, 1555, 1742, 1862, 2046, 2149, 2256, 2443, 2579, 2721, 2873, 3036, 3121, 3267, 3451, 3569, 3725, 3889, 4034, 4152, 4257, 4492, 4556, 4727, 4849, 5034, 5129, 5235, 5421, 5534, 5759, 5837, 6035, 6159, 6223, 6446, 6534, 6782, 6859, 7039, 7126, 7221, 7439, 7534, 7736, 7891, 8034, 8146, 8278, 8447, 8565, 8700, 8885, 9012, 9171, 9215, 9449, 9513, 9765, 9867, 10046, 10110, 10285, 10428, 10578, 10734, 10815, 11023, 11185, 11254, 11479, 11546, 11715, 11847, 12074, 12112, 12279, 12415, 12516, 12746, 12815, 13046, 13217, 13378, 13534, 14000]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=133, taps=[133]
// Delay line 3: length=75, taps=[75]
// Delay line 4: length=32, taps=[32]
// Delay line 5: length=173, taps=[173]
// Delay line 6: length=53, taps=[53]
// Delay line 7: length=21, taps=[21]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_63(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(7, 2298, 21) / 2;
	WRITE_LINE(7, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2298, 21) + LINE(6, 2275, 53) / 2;
	WRITE_LINE(6, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2275, 53) + LINE(5, 2220, 173) / 2;
	WRITE_LINE(5, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2220, 173) + LINE(0, 0, 14000);
	tmp3 = Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(4, 2045, 32) / 2;
	WRITE_LINE(4, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2045, 32) + LINE(3, 2011, 75) / 2;
	WRITE_LINE(3, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2011, 75) + LINE(2, 1934, 133) / 2;
	WRITE_LINE(2, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1934, 133) + LINE(0, 0, 14000);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
	Acc = Acc * 0.09375 + LINE(0, 0, 1065) / 32 + LINE(0, 0, 1119) / 32 + LINE(0, 0, 1233) / 32 + LINE(0, 0, 1434) / 32 + LINE(0, 0, 1555) / 32 + LINE(0, 0, 1742) / 32 + LINE(0, 0, 1862) / 32 + LINE(0, 0, 2046) / 32 + LINE(0, 0, 3569) / 32 + LINE(0, 0, 2256) / 32 + LINE(0, 0, 2443) / 32 + LINE(0, 0, 3121) / 32 + LINE(0, 0, 2721) / 32 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 3036) / 16 + -LINE(0, 0, 2579) / 16 + -LINE(0, 0, 3267) / 16 + -LINE(0, 0, 3451) / 16 + -LINE(0, 0, 2149) / 16 + -LINE(0, 0, 3725) / 16 + -LINE(0, 0, 3889) / 16 + -LINE(0, 0, 4034) / 16 + -LINE(0, 0, 4152) / 16 + -LINE(0, 0, 4257) / 16 + -LINE(0, 0, 4492) / 16 + -LINE(0, 0, 4556) / 16 + -LINE(0, 0, 4727) / 16 + -LINE(0, 0, 4849) / 16 + -LINE(0, 0, 6035) / 16 + -LINE(0, 0, 5129) / 16 + -LINE(0, 0, 5235) / 16 + -LINE(0, 0, 6223) / 16 + -LINE(0, 0, 5534) / 16 + LINE(0, 0, 5759) / 8 + LINE(0, 0, 5837) / 8 + LINE(0, 0, 5034) / 8 + LINE(0, 0, 6159) / 8 + LINE(0, 0, 5421) / 8 + LINE(0, 0, 6446) / 8 + LINE(0, 0, 6534) / 8 + LINE(0, 0, 6782) / 8 + LINE(0, 0, 6859) / 8 + LINE(0, 0, 7039) / 8 + LINE(0, 0, 7126) / 8 + LINE(0, 0, 7221) / 8 + LINE(0, 0, 8565) / 8 + LINE(0, 0, 7534) / 8 + LINE(0, 0, 7736) / 8 + LINE(0, 0, 7891) / 8 + LINE(0, 0, 9215) / 8 + LINE(0, 0, 8146) / 8 + LINE(0, 0, 8278) / 8 + -LINE(0, 0, 8447) / 4 + -LINE(0, 0, 7439) / 4 + -LINE(0, 0, 8700) / 4 + -LINE(0, 0, 8885) / 4 + -LINE(0, 0, 9012) / 4 + -LINE(0, 0, 9171) / 4 + -LINE(0, 0, 8034) / 4 + -LINE(0, 0, 9449) / 4 + -LINE(0, 0, 9513) / 4 + -LINE(0, 0, 9765) / 4 + -LINE(0, 0, 9867) / 4 + -LINE(0, 0, 10046) / 4 + -LINE(0, 0, 10110) / 4 + -LINE(0, 0, 10285) / 4 + -LINE(0, 0, 12074) / 4 + -LINE(0, 0, 10578) / 4 + -LINE(0, 0, 10734) / 4 + -LINE(0, 0, 11715) / 4 + -LINE(0, 0, 11023) / 4 + -LINE(0, 0, 11185) / 4 + LINE(0, 0, 11254) / 2 + LINE(0, 0, 11479) / 2 + LINE(0, 0, 11546) / 2 + LINE(0, 0, 10815) / 2 + LINE(0, 0, 11847) / 2 + LINE(0, 0, 10428) / 2 + LINE(0, 0, 12112) / 2 + LINE(0, 0, 12279) / 2 + LINE(0, 0, 12415) / 2 + LINE(0, 0, 12516) / 2 + LINE(0, 0, 12746) / 2 + LINE(0, 0, 12815) / 2 + LINE(0, 0, 13046) / 2 + LINE(0, 0, 13217) / 2 + LINE(0, 0, 13378) / 2 + LINE(0, 0, 13534) / 2;
	WRITE_LINE(1, 11) = Acc;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=137, taps=[135, 137]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_64(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp0, tmp5642, tmp11275, tmp533, tmp6166, tmp11799, tmp1057, tmp6690, tmp12323, tmp1581, tmp7214, tmp12847, tmp7738, tmp13371, tmp2629, tmp8262, tmp13895, tmp3153, tmp8786, tmp14419, tmp3677, tmp9310, tmp14943, tmp4201, tmp9834, tmp15467, tmp4725, tmp10358, tmp15991, tmp5249, tmp10882, tmp5773, tmp11406, tmp664, tmp6297, tmp11930, tmp1188, tmp6821, tmp12454, tmp1712, tmp7345, tmp12978, tmp2236, tmp7869, tmp13502, tmp2760, tmp8393, tmp14026, tmp3284, tmp8917, tmp14550, tmp3808, tmp9441, tmp15074, tmp4332, tmp9965, tmp15598, tmp4856, tmp10489, tmp16122, tmp5380, tmp11013, tmp271, tmp5904, tmp11537, tmp795, tmp6428, tmp12061, tmp1319, tmp6952, tmp12585, tmp1843, tmp7476, tmp13109, tmp2367, tmp8000, tmp13633, tmp2891, tmp8524, tmp14157, tmp3415, tmp9048, tmp14681, tmp3939, tmp9572, tmp15205, tmp4463, tmp10096, tmp15729, tmp4987, tmp10620, tmp1405, tmp16253, tmp5511, tmp11144, tmp402, tmp6035, tmp11668, tmp926, tmp6559, tmp12192, tmp1450, tmp7083, tmp12716, tmp1974, tmp7607, tmp13240, tmp2498, tmp8131, tmp13764, tmp3022, tmp8655, tmp14288, tmp3546, tmp9179, tmp14812, tmp4070, tmp9703, tmp15336, tmp4594, tmp10227, tmp15860, tmp5118, tmp10751;
	*out_left = LINE(0, 140, 135);
	*out_right = LINE(0, 140, 137);
	Acc = 0;
	WRITE_LINE(0, 140) = -Acc;
}
#undef LINE
#undef WRITE_LINE
void (*effects[])(int16_t input, int16_t *out_left, int16_t *out_right, int16_t *DRAM, int ptr) = {
	effect_1,
	effect_2,
	effect_3,
	effect_4,
	effect_5,
	effect_6,
	effect_7,
	effect_8,
	effect_9,
	effect_10,
	effect_11,
	effect_12,
	effect_13,
	effect_14,
	effect_15,
	effect_16,
	effect_17,
	effect_18,
	effect_19,
	effect_20,
	effect_21,
	effect_22,
	effect_23,
	effect_24,
	effect_25,
	effect_26,
	effect_27,
	effect_28,
	effect_29,
	effect_30,
	effect_31,
	effect_32,
	effect_33,
	effect_34,
	effect_35,
	effect_36,
	effect_37,
	effect_38,
	effect_39,
	effect_40,
	effect_41,
	effect_42,
	effect_43,
	effect_44,
	effect_45,
	effect_46,
	effect_47,
	effect_48,
	effect_49,
	effect_50,
	effect_51,
	effect_52,
	effect_53,
	effect_54,
	effect_55,
	effect_56,
	effect_57,
	effect_58,
	effect_59,
	effect_60,
	effect_61,
	effect_62,
	effect_63,
	effect_64,
};
