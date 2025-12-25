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
	Acc = LINE(13, 16381, 58) * 5 / 8 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 5 / 8 + WRITE_LINE(13, 16381) * 5 / 8 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 113) * 5 / 8 + WRITE_LINE(12, 16321) * 5 / 8 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -WRITE_LINE(11, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(11, 16230) / 2 + LINE(11, 16230, 113) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -27 / 16 + tmp1 * 27 / 8;
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
	Acc = LINE(14, 16381, 58) * 5 / 8 + LINE(3, 14110, 1) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = LINE(13, 16321, 89) * 5 / 8 + WRITE_LINE(14, 16381) * 5 / 8 + LINE(14, 16381, 58);
	WRITE_LINE(13, 16321) = -Acc;
	Acc = LINE(12, 16230, 113) * 5 / 8 + WRITE_LINE(13, 16321) * 5 / 8 + LINE(13, 16321, 89);
	WRITE_LINE(12, 16230) = -Acc;
	Acc = -WRITE_LINE(12, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(12, 16230) / 2 + LINE(12, 16230, 113) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -27 / 16 + tmp1 * 27 / 8;
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
	Acc = LINE(13, 16381, 58) * 5 / 8 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 5 / 8 + WRITE_LINE(13, 16381) * 5 / 8 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 183) * 5 / 8 + WRITE_LINE(12, 16321) * 5 / 8 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -WRITE_LINE(11, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(11, 16230) / 2 + LINE(11, 16230, 183) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -27 / 16 + tmp1 * 27 / 8;
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
	Acc = LINE(13, 16381, 58) * 5 / 8 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 5 / 8 + WRITE_LINE(13, 16381) * 5 / 8 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 103) * 5 / 8 + WRITE_LINE(12, 16321) * 5 / 8 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -WRITE_LINE(11, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(11, 16230) / 2 + LINE(11, 16230, 103) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -27 / 16 + tmp1 * 27 / 8;
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
	Acc = LINE(14, 16381, 58) * 5 / 8 + LINE(3, 12696, 1) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = LINE(13, 16321, 89) * 5 / 8 + WRITE_LINE(14, 16381) * 5 / 8 + LINE(14, 16381, 58);
	WRITE_LINE(13, 16321) = -Acc;
	Acc = LINE(12, 16230, 103) * 5 / 8 + WRITE_LINE(13, 16321) * 5 / 8 + LINE(13, 16321, 89);
	WRITE_LINE(12, 16230) = -Acc;
	Acc = -WRITE_LINE(12, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(12, 16230) / 2 + LINE(12, 16230, 103) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -27 / 16 + tmp1 * 27 / 8;
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
	Acc = LINE(13, 16381, 58) * 5 / 8 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 5 / 8 + WRITE_LINE(13, 16381) * 5 / 8 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 183) * 5 / 8 + WRITE_LINE(12, 16321) * 5 / 8 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -WRITE_LINE(11, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(11, 16230) / 2 + LINE(11, 16230, 183) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -27 / 16 + tmp1 * 27 / 8;
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
	Acc = LINE(14, 16381, 58) * 5 / 8 + LINE(3, 12130, 1) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = LINE(13, 16321, 89) * 5 / 8 + WRITE_LINE(14, 16381) * 5 / 8 + LINE(14, 16381, 58);
	WRITE_LINE(13, 16321) = -Acc;
	Acc = LINE(12, 16230, 183) * 5 / 8 + WRITE_LINE(13, 16321) * 5 / 8 + LINE(13, 16321, 89);
	WRITE_LINE(12, 16230) = -Acc;
	Acc = -WRITE_LINE(12, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(12, 16230) / 2 + LINE(12, 16230, 183) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -27 / 16 + tmp1 * 27 / 8;
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
	Acc = LINE(13, 16381, 58) * 5 / 8 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 5 / 8 + WRITE_LINE(13, 16381) * 5 / 8 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 183) * 5 / 8 + WRITE_LINE(12, 16321) * 5 / 8 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -WRITE_LINE(11, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(11, 16230) / 2 + LINE(11, 16230, 183) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -27 / 16 + tmp1 * 27 / 8;
	tmp11 = Acc;
	Acc = LINE(10, 15645, 601) / 2 + LINE(9, 15042, 472) / 2;
	WRITE_LINE(9, 15042) = -Acc;
	Acc = -Acc / 2 + LINE(9, 15042, 472);
	WRITE_LINE(8, 14568) = Acc;
	Acc = LINE(8, 14568, 683) / 2 + LINE(7, 13883, 634) / 2;
	WRITE_LINE(7, 13883) = -Acc;
	Acc = Acc * -3 / 4 + LINE(7, 13883, 634) * 3 / 2;
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
	Acc = Acc * -3 / 4 + LINE(3, 11390, 655) * 3 / 2;
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
	Acc = LINE(15, 16282, 98) * 5 / 8 + LINE(3, 3742, 1) / 2;
	WRITE_LINE(15, 16282) = -Acc;
	Acc = LINE(14, 16182, 198) * 5 / 8 + WRITE_LINE(15, 16282) * 5 / 8 + LINE(15, 16282, 98);
	WRITE_LINE(14, 16182) = -Acc;
	Acc = LINE(13, 15982, 367) * 5 / 8 + WRITE_LINE(14, 16182) * 5 / 8 + LINE(14, 16182, 198);
	WRITE_LINE(13, 15982) = -Acc;
	Acc = WRITE_LINE(13, 15982) * 5 / 8 + LINE(13, 15982, 367) + LINE(12, 15113, 789) / 2;
	WRITE_LINE(12, 15113) = -Acc;
	Acc = Acc * -27 / 16 + LINE(12, 15113, 789) * 27 / 8;
	tmp11 = Acc;
	Acc = -LINE(11, 14322, 1203) / 4 + LINE(10, 13117, 1345) / 2;
	WRITE_LINE(10, 13117) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13117, 1345);
	WRITE_LINE(9, 11770) = Acc;
	Acc = -LINE(9, 11770, 1369) / 4 + LINE(8, 10399, 1289) / 2;
	WRITE_LINE(8, 10399) = -Acc;
	Acc = Acc * -3 / 4 + LINE(8, 10399, 1289) * 3 / 2;
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
	Acc = Acc * -3 / 4 + LINE(4, 5129, 1385) * 3 / 2;
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
	Acc = LINE(3, 3742, 1) * 3 / 4 + LINE(0, 0, 100) / 2;
	WRITE_LINE(3, 3742) = Acc;
	Acc = LINE(15, 16282, 98) * 5 / 8 + LINE(3, 3742, 1) / 2;
	WRITE_LINE(15, 16282) = -Acc;
	Acc = LINE(14, 16182, 198) * 5 / 8 + WRITE_LINE(15, 16282) * 5 / 8 + LINE(15, 16282, 98);
	WRITE_LINE(14, 16182) = -Acc;
	Acc = LINE(13, 15982, 367) * 5 / 8 + WRITE_LINE(14, 16182) * 5 / 8 + LINE(14, 16182, 198);
	WRITE_LINE(13, 15982) = -Acc;
	Acc = WRITE_LINE(13, 15982) * 5 / 8 + LINE(13, 15982, 367) + LINE(12, 15113, 789) / 2;
	WRITE_LINE(12, 15113) = -Acc;
	Acc = Acc * -27 / 16 + LINE(12, 15113, 789) * 27 / 8;
	tmp11 = Acc;
	Acc = -LINE(11, 14322, 1203) / 4 + LINE(10, 13117, 1345) / 2;
	WRITE_LINE(10, 13117) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13117, 1345);
	WRITE_LINE(9, 11770) = Acc;
	Acc = -LINE(9, 11770, 1369) / 4 + LINE(8, 10399, 1289) / 2;
	WRITE_LINE(8, 10399) = -Acc;
	Acc = Acc * -3 / 4 + LINE(8, 10399, 1289) * 3 / 2;
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
	Acc = Acc * -3 / 4 + LINE(4, 5129, 1385) * 3 / 2;
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
	Acc = LINE(13, 16381, 58) * 5 / 8 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 5 / 8 + WRITE_LINE(13, 16381) * 5 / 8 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 183) * 5 / 8 + WRITE_LINE(12, 16321) * 5 / 8 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -WRITE_LINE(11, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(11, 16230) / 2 + LINE(11, 16230, 183) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -27 / 16 + tmp1 * 27 / 8;
	tmp11 = Acc;
	Acc = LINE(10, 15645, 701) * 5 / 8 + LINE(9, 14942, 472) / 2;
	WRITE_LINE(9, 14942) = -Acc;
	Acc = -Acc / 2 + LINE(9, 14942, 472);
	WRITE_LINE(8, 14468) = Acc;
	Acc = LINE(8, 14468, 783) * 5 / 8 + LINE(7, 13683, 634) / 2;
	WRITE_LINE(7, 13683) = -Acc;
	Acc = Acc * -3 / 4 + LINE(7, 13683, 634) * 3 / 2;
	tmp1 = Acc;
	Acc = LINE(2, 10560, 1) / 4 + tmp1 / 2;
	WRITE_LINE(2, 10560) = Acc;
	Acc = LINE(2, 10560, 1) + tmp11;
	WRITE_LINE(10, 15645) = Acc;
	Acc = LINE(6, 13047, 617) * 5 / 8 + LINE(5, 12428, 637) / 2;
	WRITE_LINE(5, 12428) = -Acc;
	Acc = -Acc / 2 + LINE(5, 12428, 637);
	WRITE_LINE(4, 11789) = Acc;
	Acc = LINE(4, 11789, 567) * 5 / 8 + LINE(3, 11220, 655) / 2;
	WRITE_LINE(3, 11220) = -Acc;
	*out_left = tmp5;
	Acc = Acc * -3 / 4 + LINE(3, 11220, 655) * 3 / 2;
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
	Acc = LINE(2, 763, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(14, 16381, 58) * 5 / 8 + LINE(3, 11503, 1) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = LINE(13, 16321, 89) * 5 / 8 + WRITE_LINE(14, 16381) * 5 / 8 + LINE(14, 16381, 58);
	WRITE_LINE(13, 16321) = -Acc;
	Acc = LINE(12, 16230, 183) * 5 / 8 + WRITE_LINE(13, 16321) * 5 / 8 + LINE(13, 16321, 89);
	WRITE_LINE(12, 16230) = -Acc;
	Acc = -WRITE_LINE(12, 16230) / 4;
	tmp1 = -Acc;
	Acc = -Acc / 2 + WRITE_LINE(12, 16230) / 2 + LINE(12, 16230, 183) + tmp1 / 2;
	tmp1 = -Acc;
	Acc = Acc * -27 / 16 + tmp1 * 27 / 8;
	tmp11 = Acc;
	Acc = LINE(11, 15785, 501) * 3 / 4 + LINE(10, 15282, 372) / 2;
	WRITE_LINE(10, 15282) = -Acc;
	Acc = -Acc / 2 + LINE(10, 15282, 372);
	WRITE_LINE(9, 14908) = Acc;
	Acc = LINE(9, 14908, 683) * 3 / 4 + LINE(8, 14223, 534) / 2;
	WRITE_LINE(8, 14223) = -Acc;
	Acc = Acc * -3 / 4 + LINE(8, 14223, 534) * 3 / 2;
	tmp1 = Acc;
	Acc = LINE(2, 11500, 1) / 4 + tmp1 / 2;
	WRITE_LINE(2, 11500) = Acc;
	Acc = LINE(2, 11500, 1) + tmp11;
	WRITE_LINE(11, 15785) = Acc;
	Acc = LINE(7, 13687, 417) * 3 / 4 + LINE(6, 13268, 507) / 2;
	WRITE_LINE(6, 13268) = -Acc;
	Acc = -Acc / 2 + LINE(6, 13268, 507);
	WRITE_LINE(5, 12759) = Acc;
	Acc = LINE(5, 12759, 697) * 3 / 4 + LINE(4, 12060, 555) / 2;
	WRITE_LINE(4, 12060) = -Acc;
	Acc = Acc * -3 / 4 + LINE(4, 12060, 555) * 3 / 2;
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
	Acc = LINE(15, 16282, 98) * 5 / 8 + LINE(3, 3836, 1) / 2;
	WRITE_LINE(15, 16282) = -Acc;
	Acc = LINE(14, 16182, 198) * 5 / 8 + WRITE_LINE(15, 16282) * 5 / 8 + LINE(15, 16282, 98);
	WRITE_LINE(14, 16182) = -Acc;
	Acc = LINE(13, 15982, 367) * 5 / 8 + WRITE_LINE(14, 16182) * 5 / 8 + LINE(14, 16182, 198);
	WRITE_LINE(13, 15982) = -Acc;
	Acc = WRITE_LINE(13, 15982) * 5 / 8 + LINE(13, 15982, 367) + LINE(12, 15113, 875) / 2;
	WRITE_LINE(12, 15113) = -Acc;
	Acc = Acc * -27 / 16 + LINE(12, 15113, 875) * 27 / 8;
	tmp11 = Acc;
	Acc = LINE(11, 14236, 1203) / 2 + LINE(10, 13031, 1145) / 2;
	WRITE_LINE(10, 13031) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13031, 1145);
	WRITE_LINE(9, 11884) = Acc;
	Acc = LINE(9, 11884, 1569) / 2 + LINE(8, 10313, 1339) / 2;
	WRITE_LINE(8, 10313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(8, 10313, 1339) * 3 / 2;
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
	Acc = Acc * -3 / 4 + LINE(4, 5223, 1385) * 3 / 2;
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
	Acc = LINE(14, 16282, 98) * 5 / 8 + LINE(0, 0, 100) / 2;
	WRITE_LINE(14, 16282) = -Acc;
	Acc = LINE(13, 16182, 198) * 5 / 8 + WRITE_LINE(14, 16282) * 5 / 8 + LINE(14, 16282, 98);
	WRITE_LINE(13, 16182) = -Acc;
	Acc = LINE(12, 15982, 367) * 5 / 8 + WRITE_LINE(13, 16182) * 5 / 8 + LINE(13, 16182, 198);
	WRITE_LINE(12, 15982) = -Acc;
	Acc = WRITE_LINE(12, 15982) * 5 / 8 + LINE(12, 15982, 367) + LINE(11, 15113, 1256) / 2;
	WRITE_LINE(11, 15113) = -Acc;
	Acc = Acc * -27 / 16 + LINE(11, 15113, 1256) * 27 / 8;
	tmp11 = Acc;
	Acc = LINE(10, 13855, 1203) + LINE(9, 12650, 1345) / 2;
	WRITE_LINE(9, 12650) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12650, 1345);
	WRITE_LINE(8, 11303) = Acc;
	Acc = -LINE(8, 11303, 1569) / 4 + LINE(7, 9732, 1789) / 2;
	WRITE_LINE(7, 9732) = -Acc;
	Acc = Acc * -3 / 4 + LINE(7, 9732, 1789) * 3 / 2;
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
	Acc = Acc * -3 / 4 + LINE(3, 3462, 1785) * 3 / 2;
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
	Acc = LINE(15, 16282, 98) * 5 / 8 + WRITE_LINE(3, 1944) / 2;
	WRITE_LINE(15, 16282) = -Acc;
	Acc = LINE(14, 16182, 198) * 5 / 8 + WRITE_LINE(15, 16282) * 5 / 8 + LINE(15, 16282, 98);
	WRITE_LINE(14, 16182) = -Acc;
	Acc = LINE(13, 15982, 367) * 5 / 8 + WRITE_LINE(14, 16182) * 5 / 8 + LINE(14, 16182, 198);
	WRITE_LINE(13, 15982) = -Acc;
	Acc = WRITE_LINE(13, 15982) * 5 / 8 + LINE(13, 15982, 367) + LINE(12, 15113, 987) / 2;
	WRITE_LINE(12, 15113) = -Acc;
	Acc = Acc * -27 / 16 + LINE(12, 15113, 987) * 27 / 8;
	tmp11 = Acc;
	Acc = LINE(11, 14124, 1203) * 3 / 4 + LINE(10, 12919, 1345) / 2;
	WRITE_LINE(10, 12919) = -Acc;
	Acc = -Acc / 2 + LINE(10, 12919, 1345);
	WRITE_LINE(9, 11572) = Acc;
	Acc = LINE(9, 11572, 1569) / 2 + LINE(8, 10001, 1789) / 2;
	WRITE_LINE(8, 10001) = -Acc;
	Acc = Acc * -3 / 4 + LINE(8, 10001, 1789) * 3 / 2;
	tmp1 = Acc;
	Acc = LINE(2, 1941, 1) / 4 + tmp1 / 2;
	WRITE_LINE(2, 1941) = Acc;
	Acc = LINE(2, 1941, 1) + tmp11;
	WRITE_LINE(11, 14124) = Acc;
	Acc = LINE(7, 8210, 1034) * 3 / 4 + LINE(6, 7174, 1456) / 2;
	WRITE_LINE(6, 7174) = -Acc;
	Acc = -Acc / 2 + LINE(6, 7174, 1456);
	WRITE_LINE(5, 5716) = Acc;
	Acc = LINE(5, 5716, 1983) / 2 + LINE(4, 3731, 1785) / 2;
	WRITE_LINE(4, 3731) = -Acc;
	Acc = Acc * -3 / 4 + LINE(4, 3731, 1785) * 3 / 2;
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
	Acc = LINE(14, 16282, 78) * 5 / 8 + LINE(3, 6209, 1) / 2;
	WRITE_LINE(14, 16282) = -Acc;
	Acc = LINE(13, 16202, 147) * 5 / 8 + WRITE_LINE(14, 16282) * 5 / 8 + LINE(14, 16282, 78);
	WRITE_LINE(13, 16202) = -Acc;
	Acc = LINE(12, 16053, 367) * 5 / 8 + WRITE_LINE(13, 16202) * 5 / 8 + LINE(13, 16202, 147);
	WRITE_LINE(12, 16053) = -Acc;
	Acc = WRITE_LINE(12, 16053) * 135 / 64 + LINE(12, 16053, 367) * 27 / 8;
	tmp11 = Acc;
	Acc = LINE(11, 15084, 798) * 3 / 4 + LINE(10, 14284, 1045) / 2;
	WRITE_LINE(10, 14284) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14284, 1045);
	WRITE_LINE(9, 13237) = Acc;
	Acc = LINE(9, 13237, 1269) * 3 / 4 + LINE(8, 11966, 1289) / 2;
	WRITE_LINE(8, 11966) = -Acc;
	Acc = Acc * -3 / 4 + LINE(8, 11966, 1289) * 3 / 2;
	tmp1 = Acc;
	Acc = LINE(2, 6206, 1) / 4 + tmp1 / 2;
	WRITE_LINE(2, 6206) = Acc;
	Acc = LINE(2, 6206, 1) + tmp11;
	WRITE_LINE(11, 15084) = Acc;
	Acc = LINE(7, 10675, 1034) * 3 / 4 + LINE(6, 9639, 1256) / 2;
	WRITE_LINE(6, 9639) = -Acc;
	Acc = -Acc / 2 + LINE(6, 9639, 1256);
	WRITE_LINE(5, 8381) = Acc;
	Acc = LINE(5, 8381, 1183) * 3 / 4 + LINE(4, 7196, 985) / 2;
	WRITE_LINE(4, 7196) = -Acc;
	Acc = Acc * -3 / 4 + LINE(4, 7196, 985) * 3 / 2;
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
	Acc = LINE(13, 16282, 78) * 5 / 8 + LINE(0, 0, 100) / 2;
	WRITE_LINE(13, 16282) = -Acc;
	Acc = LINE(12, 16202, 147) * 5 / 8 + WRITE_LINE(13, 16282) * 5 / 8 + LINE(13, 16282, 78);
	WRITE_LINE(12, 16202) = -Acc;
	Acc = LINE(11, 16053, 367) * 5 / 8 + WRITE_LINE(12, 16202) * 5 / 8 + LINE(12, 16202, 147);
	WRITE_LINE(11, 16053) = -Acc;
	Acc = WRITE_LINE(11, 16053) * 135 / 64 + LINE(11, 16053, 367) * 27 / 8;
	tmp11 = Acc;
	Acc = LINE(10, 15084, 798) * 3 / 4 + LINE(9, 14284, 1045) / 2;
	WRITE_LINE(9, 14284) = -Acc;
	Acc = -Acc / 2 + LINE(9, 14284, 1045);
	WRITE_LINE(8, 13237) = Acc;
	Acc = LINE(8, 13237, 1269) * 3 / 4 + LINE(7, 11966, 1289) / 2;
	WRITE_LINE(7, 11966) = -Acc;
	Acc = Acc * -3 / 4 + LINE(7, 11966, 1289) * 3 / 2;
	tmp1 = Acc;
	Acc = LINE(2, 6206, 1) / 4 + tmp1 / 2;
	WRITE_LINE(2, 6206) = Acc;
	Acc = LINE(2, 6206, 1) + tmp11;
	WRITE_LINE(10, 15084) = Acc;
	Acc = LINE(6, 10675, 1034) * 3 / 4 + LINE(5, 9639, 1256) / 2;
	WRITE_LINE(5, 9639) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9639, 1256);
	WRITE_LINE(4, 8381) = Acc;
	Acc = LINE(4, 8381, 1183) * 3 / 4 + LINE(3, 7196, 985) / 2;
	WRITE_LINE(3, 7196) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 7196, 985) * 3 / 2;
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
	Acc = LINE(2, 2415, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(8, 13793, 1724) * 3 / 4 + LINE(7, 12067, 1592) / 2;
	WRITE_LINE(7, 12067) = -Acc;
	Acc = -Acc / 2 + LINE(7, 12067, 1592);
	WRITE_LINE(6, 10473) = Acc;
	Acc = LINE(6, 10473, 1910) * 5 / 8 + LINE(5, 8561, 2071) / 2;
	WRITE_LINE(5, 8561) = -Acc;
	Acc = -Acc / 2 + LINE(5, 8561, 2071);
	WRITE_LINE(4, 6488) = Acc;
	Acc = LINE(4, 6488, 1857) * 5 / 8 + LINE(3, 4629, 2212) / 2;
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
	Acc = LINE(2, 363, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(8, 12941, 1924) * 3 / 4 + LINE(7, 11015, 1992) / 2;
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
	Acc = LINE(2, 3728, 1) * 81 / 32 + LINE(14, 16381, 251) / 2;
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
	Acc = LINE(8, 13306, 1124) * 3 / 4 + LINE(7, 12180, 1292) / 2;
	WRITE_LINE(7, 12180) = -Acc;
	Acc = -Acc / 2 + LINE(7, 12180, 1292);
	WRITE_LINE(6, 10886) = Acc;
	Acc = LINE(6, 10886, 1410) / 2 + LINE(5, 9474, 1871) / 2;
	WRITE_LINE(5, 9474) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9474, 1871);
	WRITE_LINE(4, 7601) = Acc;
	Acc = LINE(4, 7601, 1657) / 2 + LINE(3, 5942, 2212) / 2;
	WRITE_LINE(3, 5942) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 5942, 2212) * 3 / 2;
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
	Acc = LINE(2, 8564, 1) * 81 / 32 + LINE(14, 16381, 160) / 2;
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
	Acc = LINE(8, 14810, 712) * 5 / 8 + LINE(7, 14096, 995) / 2;
	WRITE_LINE(7, 14096) = -Acc;
	Acc = -Acc / 2 + LINE(7, 14096, 995);
	WRITE_LINE(6, 13099) = Acc;
	Acc = LINE(6, 13099, 1005) * 3 / 4 + LINE(5, 12092, 1188) / 2;
	WRITE_LINE(5, 12092) = -Acc;
	Acc = -Acc / 2 + LINE(5, 12092, 1188);
	WRITE_LINE(4, 10902) = Acc;
	Acc = LINE(4, 10902, 1028) * 3 / 4 + LINE(3, 9872, 1306) / 2;
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
	Acc = LINE(0, 0, 1) * 81 / 32 + LINE(13, 16381, 321) / 2;
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
	Acc = LINE(7, 13409, 1424) * 3 / 4 + LINE(6, 11983, 1592) / 2;
	WRITE_LINE(6, 11983) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11983, 1592);
	WRITE_LINE(5, 10389) = Acc;
	Acc = -LINE(5, 10389, 1810) / 4 + LINE(4, 8577, 1771) / 2;
	WRITE_LINE(4, 8577) = -Acc;
	Acc = -Acc / 2 + LINE(4, 8577, 1771);
	WRITE_LINE(3, 6804) = Acc;
	Acc = LINE(3, 6804, 2257) * 3 / 4 + LINE(2, 4545, 2312) / 2;
	WRITE_LINE(2, 4545) = -Acc;
	Acc = Acc * -3 / 4 + LINE(2, 4545, 2312) * 3 / 2;
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
	Acc = LINE(0, 0, 1) * 81 / 32 + LINE(13, 16381, 321) / 2;
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
	Acc = LINE(7, 12841, 1424) * 3 / 4 + LINE(6, 11415, 1592) / 2;
	WRITE_LINE(6, 11415) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11415, 1592);
	WRITE_LINE(5, 9821) = Acc;
	Acc = LINE(5, 9821, 1810) * 3 / 4 + LINE(4, 8009, 1771) / 2;
	WRITE_LINE(4, 8009) = -Acc;
	Acc = -Acc / 2 + LINE(4, 8009, 1771);
	WRITE_LINE(3, 6236) = Acc;
	Acc = LINE(3, 6236, 2257) / 2 + LINE(2, 3977, 2312) / 2;
	WRITE_LINE(2, 3977) = -Acc;
	Acc = Acc * -3 / 4 + LINE(2, 3977, 2312) * 3 / 2;
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
	Acc = LINE(2, 363, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(8, 12941, 1924) * 3 / 4 + LINE(7, 11015, 1792) / 2;
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
	Acc = LINE(0, 0, 1) * 81 / 32 + LINE(13, 16381, 321) / 2;
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
	Acc = LINE(7, 12941, 1924) * 3 / 4 + LINE(6, 11015, 1792) / 2;
	WRITE_LINE(6, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11015, 1792);
	WRITE_LINE(5, 9221) = Acc;
	Acc = LINE(5, 9221, 2010) / 2 + LINE(4, 7209, 2371) / 2;
	WRITE_LINE(4, 7209) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7209, 2371);
	WRITE_LINE(3, 4836) = Acc;
	Acc = LINE(3, 4836, 1857) / 2 + LINE(2, 2977, 2612) / 2;
	WRITE_LINE(2, 2977) = -Acc;
	Acc = Acc * -3 / 4 + LINE(2, 2977, 2612) * 3 / 2;
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
	Acc = LINE(2, 963, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(8, 12741, 1624) * 3 / 4 + LINE(7, 11115, 1492) / 2;
	WRITE_LINE(7, 11115) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11115, 1492);
	WRITE_LINE(6, 9621) = Acc;
	Acc = LINE(6, 9621, 2110) / 2 + LINE(5, 7509, 1971) / 2;
	WRITE_LINE(5, 7509) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7509, 1971);
	WRITE_LINE(4, 5536) = Acc;
	Acc = LINE(4, 5536, 2257) / 2 + LINE(3, 3277, 2312) / 2;
	WRITE_LINE(3, 3277) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 3277, 2312) * 3 / 2;
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
	Acc = LINE(0, 0, 1) * 81 / 32 + LINE(13, 16381, 321) / 2;
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
	Acc = LINE(7, 12941, 1424) * 3 / 4 + LINE(6, 11515, 1792) / 2;
	WRITE_LINE(6, 11515) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11515, 1792);
	WRITE_LINE(5, 9721) = Acc;
	Acc = LINE(5, 9721, 2010) / 2 + LINE(4, 7709, 2371) / 2;
	WRITE_LINE(4, 7709) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7709, 2371);
	WRITE_LINE(3, 5336) = Acc;
	Acc = LINE(3, 5336, 2357) / 2 + LINE(2, 2977, 2612) / 2;
	WRITE_LINE(2, 2977) = -Acc;
	Acc = Acc * -3 / 4 + LINE(2, 2977, 2612) * 3 / 2;
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
	Acc = LINE(2, 663, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(8, 12641, 1624) * 15 / 16 + LINE(7, 11015, 1592) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1592);
	WRITE_LINE(6, 9421) = Acc;
	Acc = LINE(6, 9421, 2010) * 3 / 4 + LINE(5, 7409, 2271) / 2;
	WRITE_LINE(5, 7409) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7409, 2271);
	WRITE_LINE(4, 5136) = Acc;
	Acc = LINE(4, 5136, 2157) / 2 + LINE(3, 2977, 2312) / 2;
	WRITE_LINE(3, 2977) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 2977, 2312) * 3 / 2;
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
	Acc = LINE(2, 763, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(8, 13241, 1424) * 3 / 4 + LINE(7, 11815, 1992) / 2;
	WRITE_LINE(7, 11815) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11815, 1992);
	WRITE_LINE(6, 9821) = Acc;
	Acc = LINE(6, 9821, 2010) * 3 / 4 + LINE(5, 7809, 2371) / 2;
	WRITE_LINE(5, 7809) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7809, 2371);
	WRITE_LINE(4, 5436) = Acc;
	Acc = LINE(4, 5436, 2057) * 5 / 8 + LINE(3, 3377, 2612) / 2;
	WRITE_LINE(3, 3377) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 3377, 2612) * 3 / 2;
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
	Acc = LINE(2, 63, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(8, 12641, 1624) * 15 / 16 + LINE(7, 11015, 1992) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1992);
	WRITE_LINE(6, 9021) = Acc;
	Acc = LINE(6, 9021, 2110) * 3 / 4 + LINE(5, 6909, 2371) / 2;
	WRITE_LINE(5, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6909, 2371);
	WRITE_LINE(4, 4536) = Acc;
	Acc = LINE(4, 4536, 2157) / 2 + LINE(3, 2377, 2312) / 2;
	WRITE_LINE(3, 2377) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 2377, 2312) * 3 / 2;
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
	Acc = LINE(0, 0, 1) * 81 / 32 + LINE(13, 16381, 321) / 2;
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
	Acc = LINE(5, 9621, 2110) * 3 / 4 + LINE(4, 7509, 2471) / 2;
	WRITE_LINE(4, 7509) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7509, 2471);
	WRITE_LINE(3, 5036) = Acc;
	Acc = LINE(3, 5036, 2257) / 2 + LINE(2, 2777, 2612) / 2;
	WRITE_LINE(2, 2777) = -Acc;
	Acc = Acc * -3 / 4 + LINE(2, 2777, 2612) * 3 / 2;
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
	Acc = LINE(2, 763, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(8, 13241, 1424) * 5 / 8 + LINE(7, 11815, 1992) / 2;
	WRITE_LINE(7, 11815) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11815, 1992);
	WRITE_LINE(6, 9821) = Acc;
	Acc = LINE(6, 9821, 2010) * 3 / 4 + LINE(5, 7809, 2371) / 2;
	WRITE_LINE(5, 7809) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7809, 2371);
	WRITE_LINE(4, 5436) = Acc;
	Acc = LINE(4, 5436, 2057) * 3 / 4 + LINE(3, 3377, 2612) / 2;
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
	Acc = LINE(0, 0, 1) * 81 / 32 + LINE(13, 16381, 221) / 2;
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
	Acc = LINE(7, 14377, 621) * 3 / 4 + LINE(6, 13754, 1692) / 2;
	WRITE_LINE(6, 13754) = -Acc;
	Acc = -Acc / 2 + LINE(6, 13754, 1692);
	WRITE_LINE(5, 12060) = Acc;
	Acc = LINE(5, 12060, 1310) * 15 / 16 + LINE(4, 10748, 1801) / 2;
	WRITE_LINE(4, 10748) = -Acc;
	Acc = -Acc / 2 + LINE(4, 10748, 1801);
	WRITE_LINE(3, 8945) = Acc;
	Acc = LINE(3, 8945, 1457) * -27 / 32 + LINE(2, 7486, 1576) / 2;
	WRITE_LINE(2, 7486) = -Acc;
	Acc = Acc * -3 / 4 + LINE(2, 7486, 1576) * 3 / 2;
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
	Acc = LINE(0, 0, 1) * 81 / 32 + LINE(13, 16381, 321) / 2;
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
	Acc = LINE(7, 12641, 1424) * 3 / 4 + LINE(6, 11215, 1592) / 2;
	WRITE_LINE(6, 11215) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11215, 1592);
	WRITE_LINE(5, 9621) = Acc;
	Acc = LINE(5, 9621, 1710) * 3 / 4 + LINE(4, 7909, 2071) / 2;
	WRITE_LINE(4, 7909) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7909, 2071);
	WRITE_LINE(3, 5836) = Acc;
	Acc = LINE(3, 5836, 1957) * -27 / 32 + LINE(2, 3877, 2312) / 2;
	WRITE_LINE(2, 3877) = -Acc;
	Acc = Acc * -3 / 4 + LINE(2, 3877, 2312) * 3 / 2;
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
	Acc = LINE(0, 0, 1) * 81 / 32 + LINE(13, 16381, 321) / 2;
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
	Acc = LINE(5, 9021, 2110) * 15 / 16 + LINE(4, 6909, 2371) / 2;
	WRITE_LINE(4, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(4, 6909, 2371);
	WRITE_LINE(3, 4536) = Acc;
	Acc = LINE(3, 4536, 2157) / 2 + LINE(2, 2377, 2312) / 2;
	WRITE_LINE(2, 2377) = -Acc;
	Acc = Acc * -3 / 4 + LINE(2, 2377, 2312) * 3 / 2;
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
	Acc = LINE(2, 63, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(6, 9021, 2110) * 15 / 16 + LINE(5, 6909, 2371) / 2;
	WRITE_LINE(5, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6909, 2371);
	WRITE_LINE(4, 4536) = Acc;
	Acc = LINE(4, 4536, 2157) / 2 + LINE(3, 2377, 2312) / 2;
	WRITE_LINE(3, 2377) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 2377, 2312) * 3 / 2;
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
	Acc = LINE(2, 763, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(8, 13441, 1624) * 3 / 4 + LINE(7, 11815, 1992) / 2;
	WRITE_LINE(7, 11815) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11815, 1992);
	WRITE_LINE(6, 9821) = Acc;
	Acc = LINE(6, 9821, 1710) * 3 / 4 + LINE(5, 8109, 2371) / 2;
	WRITE_LINE(5, 8109) = -Acc;
	Acc = -Acc / 2 + LINE(5, 8109, 2371);
	WRITE_LINE(4, 5736) = Acc;
	Acc = LINE(4, 5736, 2357) * -27 / 32 + LINE(3, 3377, 2612) / 2;
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
	Acc = LINE(0, 0, 1) * 81 / 32 + LINE(13, 16381, 321) / 2;
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
	Acc = LINE(7, 12641, 1624) * -27 / 32 + LINE(6, 11015, 1992) / 2;
	WRITE_LINE(6, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11015, 1992);
	WRITE_LINE(5, 9021) = Acc;
	Acc = LINE(5, 9021, 2110) * -27 / 32 + LINE(4, 6909, 2371) / 2;
	WRITE_LINE(4, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(4, 6909, 2371);
	WRITE_LINE(3, 4536) = Acc;
	Acc = LINE(3, 4536, 2157) * 3 / 4 + LINE(2, 2377, 2312) / 2;
	WRITE_LINE(2, 2377) = -Acc;
	Acc = Acc * -3 / 4 + LINE(2, 2377, 2312) * 3 / 2;
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
	Acc = LINE(2, 63, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(8, 12641, 1624) * 3 / 4 + LINE(7, 11015, 1992) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1992);
	WRITE_LINE(6, 9021) = Acc;
	Acc = LINE(6, 9021, 2110) * 3 / 4 + LINE(5, 6909, 2371) / 2;
	WRITE_LINE(5, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6909, 2371);
	WRITE_LINE(4, 4536) = Acc;
	Acc = LINE(4, 4536, 2157) * -27 / 32 + LINE(3, 2377, 2312) / 2;
	WRITE_LINE(3, 2377) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 2377, 2312) * 3 / 2;
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
	Acc = LINE(2, 63, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(8, 12641, 1624) * -27 / 32 + LINE(7, 11015, 1992) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1992);
	WRITE_LINE(6, 9021) = Acc;
	Acc = LINE(6, 9021, 2110) * 15 / 16 + LINE(5, 6909, 2371) / 2;
	WRITE_LINE(5, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6909, 2371);
	WRITE_LINE(4, 4536) = Acc;
	Acc = LINE(4, 4536, 2157) * 3 / 4 + LINE(3, 2377, 2312) / 2;
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
	Acc = LINE(0, 0, 1) * 81 / 32 + LINE(13, 16381, 321) / 2;
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
	Acc = LINE(7, 12641, 1624) * 3 / 4 + LINE(6, 11015, 1992) / 2;
	WRITE_LINE(6, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11015, 1992);
	WRITE_LINE(5, 9021) = Acc;
	Acc = LINE(5, 9021, 2110) * 15 / 16 + LINE(4, 6909, 2371) / 2;
	WRITE_LINE(4, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(4, 6909, 2371);
	WRITE_LINE(3, 4536) = Acc;
	Acc = LINE(3, 4536, 2157) * -27 / 32 + LINE(2, 2377, 2312) / 2;
	WRITE_LINE(2, 2377) = -Acc;
	Acc = Acc * -3 / 4 + LINE(2, 2377, 2312) * 3 / 2;
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
	Acc = LINE(2, 63, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(6, 9321, 2110) * 15 / 16 + LINE(5, 7209, 2371) / 2;
	WRITE_LINE(5, 7209) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7209, 2371);
	WRITE_LINE(4, 4836) = Acc;
	Acc = LINE(4, 4836, 2257) * 3 / 4 + LINE(3, 2577, 2512) / 2;
	WRITE_LINE(3, 2577) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 2577, 2512) * 3 / 2;
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
	Acc = LINE(0, 0, 1) * 81 / 32 + LINE(13, 16381, 321) / 2;
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
	Acc = LINE(7, 12641, 1624) * 15 / 16 + LINE(6, 11015, 1992) / 2;
	WRITE_LINE(6, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11015, 1992);
	WRITE_LINE(5, 9021) = Acc;
	Acc = LINE(5, 9021, 2110) * 15 / 16 + LINE(4, 6909, 2371) / 2;
	WRITE_LINE(4, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(4, 6909, 2371);
	WRITE_LINE(3, 4536) = Acc;
	Acc = LINE(3, 4536, 2157) * -27 / 32 + LINE(2, 2377, 2312) / 2;
	WRITE_LINE(2, 2377) = -Acc;
	Acc = Acc * -3 / 4 + LINE(2, 2377, 2312) * 3 / 2;
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
	Acc = LINE(2, 63, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(8, 12641, 1624) * 15 / 16 + LINE(7, 11015, 1992) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1992);
	WRITE_LINE(6, 9021) = Acc;
	Acc = LINE(6, 9021, 2110) * 15 / 16 + LINE(5, 6909, 2371) / 2;
	WRITE_LINE(5, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6909, 2371);
	WRITE_LINE(4, 4536) = Acc;
	Acc = LINE(4, 4536, 2157) * -27 / 32 + LINE(3, 2377, 2312) / 2;
	WRITE_LINE(3, 2377) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 2377, 2312) * 3 / 2;
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
	Acc = LINE(0, 0, 1) * 81 / 32 + LINE(13, 16381, 321) / 2;
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
	Acc = LINE(5, 9021, 2110) * 15 / 16 + LINE(4, 6909, 2371) / 2;
	WRITE_LINE(4, 6909) = -Acc;
	Acc = -Acc / 2 + LINE(4, 6909, 2371);
	WRITE_LINE(3, 4536) = Acc;
	Acc = LINE(3, 4536, 2157) * -27 / 32 + LINE(2, 2377, 2312) / 2;
	WRITE_LINE(2, 2377) = -Acc;
	Acc = Acc * -3 / 4 + LINE(2, 2377, 2312) * 3 / 2;
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
	Acc = LINE(2, 93, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(6, 9021, 2210) * 15 / 16 + LINE(5, 6809, 2371) / 2;
	WRITE_LINE(5, 6809) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6809, 2371);
	WRITE_LINE(4, 4436) = Acc;
	Acc = LINE(4, 4436, 2127) * -27 / 32 + LINE(3, 2307, 2212) / 2;
	WRITE_LINE(3, 2307) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 2307, 2212) * 3 / 2;
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
	Acc = LINE(2, 787, 1) * 81 / 32 + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(6, 9345, 1610) * 15 / 16 + LINE(5, 7733, 2371) / 2;
	WRITE_LINE(5, 7733) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7733, 2371);
	WRITE_LINE(4, 5360) = Acc;
	Acc = LINE(4, 5360, 1857) * 15 / 16 + LINE(3, 3501, 2712) / 2;
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
	Acc = LINE(0, 0, 1) * 81 / 32 + LINE(11, 16381, 321) / 2;
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
	Acc = LINE(5, 9413, 2110) * 15 / 16 + LINE(4, 7301, 2371) / 2;
	WRITE_LINE(4, 7301) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7301, 2371);
	WRITE_LINE(3, 4928) = Acc;
	Acc = LINE(3, 4928, 2157) * 15 / 16 + LINE(2, 2769, 2712) / 2;
	WRITE_LINE(2, 2769) = -Acc;
	Acc = Acc * -3 / 4 + LINE(2, 2769, 2712) * 3 / 2;
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
	Acc = LINE(2, 55, 1) * 81 / 32 + LINE(12, 16381, 321) / 2;
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
	Acc = LINE(6, 9413, 2110) * 15 / 16 + LINE(5, 7301, 2371) / 2;
	WRITE_LINE(5, 7301) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7301, 2371);
	WRITE_LINE(4, 4928) = Acc;
	Acc = LINE(4, 4928, 2157) * 15 / 16 + LINE(3, 2769, 2712) / 2;
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
	Acc = Acc * 3 / 32 + LINE(0, 0, 1065) / 32 + LINE(0, 0, 1119) / 32 + LINE(0, 0, 1233) / 32 + LINE(0, 0, 1434) / 32 + LINE(0, 0, 1555) / 32 + LINE(0, 0, 1742) / 32 + LINE(0, 0, 1862) / 32 + LINE(0, 0, 2046) / 32 + LINE(0, 0, 3569) / 32 + LINE(0, 0, 2256) / 32 + LINE(0, 0, 2443) / 32 + LINE(0, 0, 3121) / 32 + LINE(0, 0, 2721) / 32 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 3036) / 16 + -LINE(0, 0, 2579) / 16 + -LINE(0, 0, 3267) / 16 + -LINE(0, 0, 3451) / 16 + -LINE(0, 0, 2149) / 16 + -LINE(0, 0, 3725) / 16 + -LINE(0, 0, 3889) / 16 + -LINE(0, 0, 4034) / 16 + -LINE(0, 0, 4152) / 16 + -LINE(0, 0, 4257) / 16 + -LINE(0, 0, 4492) / 16 + -LINE(0, 0, 4556) / 16 + -LINE(0, 0, 4727) / 16 + -LINE(0, 0, 4849) / 16 + -LINE(0, 0, 6035) / 16 + -LINE(0, 0, 5129) / 16 + -LINE(0, 0, 5235) / 16 + -LINE(0, 0, 6223) / 16 + -LINE(0, 0, 5534) / 16 + LINE(0, 0, 5759) / 8 + LINE(0, 0, 5837) / 8 + LINE(0, 0, 5034) / 8 + LINE(0, 0, 6159) / 8 + LINE(0, 0, 5421) / 8 + LINE(0, 0, 6446) / 8 + LINE(0, 0, 6534) / 8 + LINE(0, 0, 6782) / 8 + LINE(0, 0, 6859) / 8 + LINE(0, 0, 7039) / 8 + LINE(0, 0, 7126) / 8 + LINE(0, 0, 7221) / 8 + LINE(0, 0, 8565) / 8 + LINE(0, 0, 7534) / 8 + LINE(0, 0, 7736) / 8 + LINE(0, 0, 7891) / 8 + LINE(0, 0, 9215) / 8 + LINE(0, 0, 8146) / 8 + LINE(0, 0, 8278) / 8 + -LINE(0, 0, 8447) / 4 + -LINE(0, 0, 7439) / 4 + -LINE(0, 0, 8700) / 4 + -LINE(0, 0, 8885) / 4 + -LINE(0, 0, 9012) / 4 + -LINE(0, 0, 9171) / 4 + -LINE(0, 0, 8034) / 4 + -LINE(0, 0, 9449) / 4 + -LINE(0, 0, 9513) / 4 + -LINE(0, 0, 9765) / 4 + -LINE(0, 0, 9867) / 4 + -LINE(0, 0, 10046) / 4 + -LINE(0, 0, 10110) / 4 + -LINE(0, 0, 10285) / 4 + -LINE(0, 0, 12074) / 4 + -LINE(0, 0, 10578) / 4 + -LINE(0, 0, 10734) / 4 + -LINE(0, 0, 11715) / 4 + -LINE(0, 0, 11023) / 4 + -LINE(0, 0, 11185) / 4 + LINE(0, 0, 11254) / 2 + LINE(0, 0, 11479) / 2 + LINE(0, 0, 11546) / 2 + LINE(0, 0, 10815) / 2 + LINE(0, 0, 11847) / 2 + LINE(0, 0, 10428) / 2 + LINE(0, 0, 12112) / 2 + LINE(0, 0, 12279) / 2 + LINE(0, 0, 12415) / 2 + LINE(0, 0, 12516) / 2 + LINE(0, 0, 12746) / 2 + LINE(0, 0, 12815) / 2 + LINE(0, 0, 13046) / 2 + LINE(0, 0, 13217) / 2 + LINE(0, 0, 13378) / 2 + LINE(0, 0, 13534) / 2;
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
// Delay line 0: length=15714, taps=[15714]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=63, taps=[63]
// Delay line 3: length=195, taps=[195]
// Delay line 4: length=41, taps=[41]
// Delay line 5: length=178, taps=[178]
// Delay line 6: length=114, taps=[114]
// Delay line 7: length=49, taps=[49]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_65(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 15714) + LINE(7, 668, 49) / 2;
	WRITE_LINE(7, 668) = -Acc;
	Acc = -Acc / 2 + LINE(7, 668, 49) + LINE(6, 617, 114) / 2;
	WRITE_LINE(6, 617) = -Acc;
	Acc = -Acc / 2 + LINE(6, 617, 114) + LINE(5, 501, 178) / 2;
	WRITE_LINE(5, 501) = -Acc;
	Acc = -Acc / 2 + LINE(5, 501, 178);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 15714) + LINE(4, 321, 41) / 2;
	WRITE_LINE(4, 321) = -Acc;
	Acc = -Acc / 2 + LINE(4, 321, 41) + LINE(3, 278, 195) / 2;
	WRITE_LINE(3, 278) = -Acc;
	Acc = -Acc / 2 + LINE(3, 278, 195) + LINE(2, 81, 63) / 2;
	WRITE_LINE(2, 81) = -Acc;
	Acc = -Acc / 2 + LINE(2, 81, 63);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=11257, taps=[11257]
// Delay line 1: length=3, taps=[1, 3]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=30, taps=[30]
// Delay line 4: length=36, taps=[36]
// Delay line 5: length=9, taps=[9]
// Delay line 6: length=75, taps=[75]
// Delay line 7: length=62, taps=[62]
// Delay line 8: length=5, taps=[5]
// Delay line 9: length=4, taps=[4]
// Delay line 10: length=369, taps=[369]
// Delay line 11: length=300, taps=[300]
// Delay line 12: length=251, taps=[251]
// Delay line 13: length=215, taps=[215]
// Delay line 14: length=174, taps=[174]
// Delay line 15: length=143, taps=[143]
// Delay line 16: length=127, taps=[127]
// Delay line 17: length=103, taps=[103]
// Delay line 18: length=87, taps=[87]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_66(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp13;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 11257) + LINE(18, 5125, 87) / 2;
	WRITE_LINE(18, 5125) = -Acc;
	Acc = -Acc / 2 + LINE(18, 5125, 87) + LINE(17, 5036, 103) / 2;
	WRITE_LINE(17, 5036) = -Acc;
	Acc = -Acc / 2 + LINE(17, 5036, 103) + LINE(16, 4931, 127) / 2;
	WRITE_LINE(16, 4931) = -Acc;
	Acc = -Acc / 2 + LINE(16, 4931, 127) + LINE(15, 4802, 143) / 2;
	WRITE_LINE(15, 4802) = -Acc;
	Acc = -Acc / 2 + LINE(15, 4802, 143) + LINE(14, 4657, 174) / 2;
	WRITE_LINE(14, 4657) = -Acc;
	Acc = -Acc / 2 + LINE(14, 4657, 174) + LINE(13, 4481, 215) / 2;
	WRITE_LINE(13, 4481) = -Acc;
	Acc = -Acc / 2 + LINE(13, 4481, 215) + LINE(12, 4264, 251) / 2;
	WRITE_LINE(12, 4264) = -Acc;
	Acc = -Acc / 2 + LINE(12, 4264, 251) + LINE(11, 4011, 300) / 2;
	WRITE_LINE(11, 4011) = -Acc;
	Acc = -Acc / 2 + LINE(11, 4011, 300) + LINE(10, 3709, 369) / 2;
	WRITE_LINE(10, 3709) = -Acc;
	Acc = -Acc / 2 + LINE(10, 3709, 369) + LINE(9, 3338, 4) / 2;
	WRITE_LINE(9, 3338) = -Acc;
	Acc = -Acc / 2 + LINE(9, 3338, 4) + LINE(8, 3332, 5) / 2;
	WRITE_LINE(8, 3332) = -Acc;
	Acc = -Acc / 2 + LINE(8, 3332, 5) + LINE(7, 3325, 62) / 2;
	WRITE_LINE(7, 3325) = -Acc;
	Acc = -Acc / 2 + LINE(7, 3325, 62) + LINE(6, 3261, 75) / 2;
	WRITE_LINE(6, 3261) = -Acc;
	Acc = -Acc / 2 + LINE(6, 3261, 75) + LINE(5, 3184, 9) / 2;
	WRITE_LINE(5, 3184) = -Acc;
	Acc = -Acc / 2 + LINE(5, 3184, 9);
	tmp13 = Acc;
	Acc = tmp13 + LINE(4, 3173, 36) / 2;
	WRITE_LINE(4, 3173) = -Acc;
	Acc = -Acc / 2 + LINE(4, 3173, 36);
	WRITE_LINE(2, 6) = -Acc;
	Acc = tmp13 + LINE(3, 3135, 30) / 2;
	WRITE_LINE(3, 3135) = -Acc;
	Acc = -Acc / 2 + LINE(3, 3135, 30);
	WRITE_LINE(1, 4) = -Acc;
	*out_left = LINE(2, 6, 1);
	*out_right = LINE(1, 4, 1);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=10299, taps=[10299]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=1, taps=[1]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_67(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(3, 6080, 1);
	tmp5 = Acc;
	Acc = LINE(3, 6080, 1);
	tmp3 = Acc;
	Acc = LINE(4, 6083, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(0, 0, 10299) / 8 + tmp1;
	WRITE_LINE(4, 6083) = Acc;
	Acc = LINE(4, 6083, 1);
	tmp1 = -Acc;
	Acc = LINE(0, 0, 10299) + tmp1;
	WRITE_LINE(1, 6074) = Acc;
	Acc = LINE(2, 6077, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(1, 6074, 1) / 8 + tmp1;
	WRITE_LINE(2, 6077) = Acc;
	Acc = LINE(2, 6077, 1);
	tmp1 = -Acc;
	Acc = LINE(1, 6074, 1) + tmp1;
	WRITE_LINE(3, 6080) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=9003, taps=[9003]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=196, taps=[196]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=1, taps=[1]
// Delay line 5: length=1, taps=[1]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_68(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp7376, tmp1, tmp2;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(5, 7379, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(0, 0, 9003) / 8 + tmp1;
	WRITE_LINE(5, 7379) = Acc;
	Acc = LINE(5, 7379, 1);
	tmp1 = -Acc;
	Acc = LINE(0, 0, 9003) + tmp1;
	WRITE_LINE(3, 7355) = Acc;
	Acc = LINE(4, 7373, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(3, 7355, 1) / 8 + tmp1;
	WRITE_LINE(4, 7373) = Acc;
	Acc = LINE(4, 7373, 1);
	tmp1 = -Acc;
	Acc = LINE(3, 7355, 1) + tmp1;
	tmp7376 = Acc;
	Acc = tmp7376;
	WRITE_LINE(1, 4) = Acc;
	Acc = tmp7376;
	WRITE_LINE(2, 201) = Acc;
	*out_left = LINE(2, 201, 196);
	*out_right = LINE(1, 4, 1);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=63, taps=[63]
// Delay line 4: length=195, taps=[195]
// Delay line 5: length=41, taps=[41]
// Delay line 6: length=178, taps=[178]
// Delay line 7: length=114, taps=[114]
// Delay line 8: length=49, taps=[49]
// Delay line 9: length=8424, taps=[8424]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_69(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(9, 16381, 8424) + LINE(5, 7608, 41) / 2;
	WRITE_LINE(5, 7608) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7608, 41) + LINE(4, 7565, 195) / 2;
	WRITE_LINE(4, 7565) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7565, 195) + LINE(3, 7368, 63) / 2;
	WRITE_LINE(3, 7368) = -Acc;
	Acc = -Acc / 2 + LINE(3, 7368, 63);
	tmp5 = Acc;
	Acc = LINE(9, 16381, 8424) + LINE(8, 7955, 49) / 2;
	WRITE_LINE(8, 7955) = -Acc;
	Acc = -Acc / 2 + LINE(8, 7955, 49) + LINE(7, 7904, 114) / 2;
	WRITE_LINE(7, 7904) = -Acc;
	Acc = -Acc / 2 + LINE(7, 7904, 114) + LINE(6, 7788, 178) / 2;
	WRITE_LINE(6, 7788) = -Acc;
	Acc = -Acc / 2 + LINE(6, 7788, 178);
	tmp3 = Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 7303, 1) / 2;
	WRITE_LINE(2, 7303) = Acc;
	Acc = LINE(1, 7300, 1) * 15 / 16;
	tmp1 = Acc;
	Acc = Acc * -3 / 16 + LINE(2, 7303, 1) / 8 + tmp1;
	WRITE_LINE(1, 7300) = Acc;
	Acc = LINE(1, 7300, 1);
	tmp1 = -Acc;
	Acc = LINE(2, 7303, 1) * 3 / 2 + tmp1 * 3 / 2;
	WRITE_LINE(9, 16381) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=596, taps=[596]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=1, taps=[1]
// Delay line 5: length=258, taps=[258]
// Delay line 6: length=213, taps=[213]
// Delay line 7: length=149, taps=[149]
// Delay line 8: length=105, taps=[105]
// Delay line 9: length=74, taps=[74]
// Delay line 10: length=52, taps=[52]
// Delay line 11: length=35, taps=[35]
// Delay line 12: length=25, taps=[25]
// Delay line 13: length=17, taps=[17]
// Delay line 14: length=304, taps=[304]
// Delay line 15: length=174, taps=[174]
// Delay line 16: length=123, taps=[123]
// Delay line 17: length=88, taps=[88]
// Delay line 18: length=61, taps=[61]
// Delay line 19: length=45, taps=[45]
// Delay line 20: length=29, taps=[29]
// Delay line 21: length=22, taps=[22]
// Delay line 22: length=15, taps=[15]
// Delay line 23: length=7722, taps=[7722]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_70(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(23, 16381, 7722) * 3 / 2 + LINE(22, 8657, 15) / 2;
	WRITE_LINE(22, 8657) = -Acc;
	Acc = -Acc / 2 + LINE(22, 8657, 15) + LINE(21, 8640, 22) / 2;
	WRITE_LINE(21, 8640) = -Acc;
	Acc = -Acc / 2 + LINE(21, 8640, 22) + LINE(20, 8616, 29) / 2;
	WRITE_LINE(20, 8616) = -Acc;
	Acc = -Acc / 2 + LINE(20, 8616, 29) + LINE(19, 8585, 45) / 2;
	WRITE_LINE(19, 8585) = -Acc;
	Acc = -Acc / 2 + LINE(19, 8585, 45) + LINE(18, 8538, 61) / 2;
	WRITE_LINE(18, 8538) = -Acc;
	Acc = -Acc / 2 + LINE(18, 8538, 61) + LINE(8, 7565, 105) / 2;
	WRITE_LINE(8, 7565) = -Acc;
	Acc = -Acc / 2 + LINE(8, 7565, 105) + LINE(7, 7458, 149) / 2;
	WRITE_LINE(7, 7458) = -Acc;
	Acc = -Acc / 2 + LINE(7, 7458, 149) + LINE(6, 7307, 213) / 2;
	WRITE_LINE(6, 7307) = -Acc;
	Acc = -Acc / 2 + LINE(6, 7307, 213) + LINE(5, 7092, 258) / 2;
	WRITE_LINE(5, 7092) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7092, 258);
	WRITE_LINE(1, 4) = Acc;
	Acc = LINE(23, 16381, 7722) * 3 / 2 + LINE(13, 7778, 17) / 2;
	WRITE_LINE(13, 7778) = -Acc;
	Acc = -Acc / 2 + LINE(13, 7778, 17) + LINE(12, 7759, 25) / 2;
	WRITE_LINE(12, 7759) = -Acc;
	Acc = -Acc / 2 + LINE(12, 7759, 25) + LINE(11, 7732, 35) / 2;
	WRITE_LINE(11, 7732) = -Acc;
	Acc = -Acc / 2 + LINE(11, 7732, 35) + LINE(10, 7695, 52) / 2;
	WRITE_LINE(10, 7695) = -Acc;
	Acc = -Acc / 2 + LINE(10, 7695, 52) + LINE(9, 7641, 74) / 2;
	WRITE_LINE(9, 7641) = -Acc;
	Acc = -Acc / 2 + LINE(9, 7641, 74) + LINE(17, 8475, 88) / 2;
	WRITE_LINE(17, 8475) = -Acc;
	Acc = -Acc / 2 + LINE(17, 8475, 88) + LINE(16, 8385, 123) / 2;
	WRITE_LINE(16, 8385) = -Acc;
	Acc = -Acc / 2 + LINE(16, 8385, 123) + LINE(15, 8260, 174) / 2;
	WRITE_LINE(15, 8260) = -Acc;
	Acc = -Acc / 2 + LINE(15, 8260, 174) + LINE(14, 8084, 304) / 2;
	WRITE_LINE(14, 8084) = -Acc;
	Acc = -Acc / 2 + LINE(14, 8084, 304);
	WRITE_LINE(2, 601) = Acc;
	Acc = LINE(4, 6832, 1) * 3 / 8;
	tmp1 = Acc;
	Acc = LINE(0, 0, 1) * 5 / 8 + tmp1;
	WRITE_LINE(4, 6832) = Acc;
	*out_left = LINE(2, 601, 596);
	Acc = LINE(3, 6826, 1) * 5 / 8;
	tmp1 = Acc;
	Acc = LINE(4, 6832, 1) * 3 / 8 + tmp1;
	WRITE_LINE(3, 6826) = Acc;
	Acc = LINE(3, 6826, 1);
	WRITE_LINE(23, 16381) = Acc;
	*out_right = LINE(1, 4, 1);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=7385, taps=[7385]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=63, taps=[63]
// Delay line 3: length=195, taps=[195]
// Delay line 4: length=41, taps=[41]
// Delay line 5: length=178, taps=[178]
// Delay line 6: length=114, taps=[114]
// Delay line 7: length=49, taps=[49]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_71(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 7385) + LINE(7, 8997, 49) / 2;
	WRITE_LINE(7, 8997) = -Acc;
	Acc = -Acc / 2 + LINE(7, 8997, 49) + LINE(6, 8946, 114) / 2;
	WRITE_LINE(6, 8946) = -Acc;
	Acc = -Acc / 2 + LINE(6, 8946, 114) + LINE(5, 8830, 178) / 2;
	WRITE_LINE(5, 8830) = -Acc;
	Acc = -Acc / 2 + LINE(5, 8830, 178);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 7385) + LINE(4, 8650, 41) / 2;
	WRITE_LINE(4, 8650) = -Acc;
	Acc = -Acc / 2 + LINE(4, 8650, 41) + LINE(3, 8607, 195) / 2;
	WRITE_LINE(3, 8607) = -Acc;
	Acc = -Acc / 2 + LINE(3, 8607, 195) + LINE(2, 8410, 63) / 2;
	WRITE_LINE(2, 8410) = -Acc;
	Acc = -Acc / 2 + LINE(2, 8410, 63);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=6698, taps=[6698]
// Delay line 1: length=600, taps=[600]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=304, taps=[304]
// Delay line 4: length=213, taps=[213]
// Delay line 5: length=149, taps=[149]
// Delay line 6: length=105, taps=[105]
// Delay line 7: length=74, taps=[74]
// Delay line 8: length=52, taps=[52]
// Delay line 9: length=35, taps=[35]
// Delay line 10: length=25, taps=[25]
// Delay line 11: length=17, taps=[17]
// Delay line 12: length=258, taps=[258]
// Delay line 13: length=174, taps=[174]
// Delay line 14: length=123, taps=[123]
// Delay line 15: length=88, taps=[88]
// Delay line 16: length=61, taps=[61]
// Delay line 17: length=45, taps=[45]
// Delay line 18: length=29, taps=[29]
// Delay line 19: length=22, taps=[22]
// Delay line 20: length=15, taps=[15]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_72(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 7566, 600) / 8 + -LINE(2, 7569, 1) / 2;
	tmp3 = Acc;
	Acc = LINE(2, 7569, 1) / 8 + -LINE(1, 7566, 600) / 2;
	tmp5 = Acc;
	Acc = LINE(0, 0, 6698) * 3 / 2 + LINE(20, 9394, 15) / 2;
	WRITE_LINE(20, 9394) = -Acc;
	Acc = -Acc / 2 + LINE(20, 9394, 15) + LINE(19, 9377, 22) / 2;
	WRITE_LINE(19, 9377) = -Acc;
	Acc = -Acc / 2 + LINE(19, 9377, 22) + LINE(18, 9353, 29) / 2;
	WRITE_LINE(18, 9353) = -Acc;
	Acc = -Acc / 2 + LINE(18, 9353, 29) + LINE(17, 9322, 45) / 2;
	WRITE_LINE(17, 9322) = -Acc;
	Acc = -Acc / 2 + LINE(17, 9322, 45) + LINE(16, 9275, 61) / 2;
	WRITE_LINE(16, 9275) = -Acc;
	Acc = -Acc / 2 + LINE(16, 9275, 61) + LINE(6, 8348, 105) / 2;
	WRITE_LINE(6, 8348) = -Acc;
	Acc = -Acc / 2 + LINE(6, 8348, 105) + LINE(5, 8241, 149) / 2;
	WRITE_LINE(5, 8241) = -Acc;
	Acc = -Acc / 2 + LINE(5, 8241, 149) + LINE(4, 8090, 213) / 2;
	WRITE_LINE(4, 8090) = -Acc;
	Acc = -Acc / 2 + LINE(4, 8090, 213) + LINE(3, 7875, 304) / 2;
	WRITE_LINE(3, 7875) = -Acc;
	Acc = -Acc / 2 + LINE(3, 7875, 304);
	WRITE_LINE(2, 7569) = Acc;
	Acc = LINE(0, 0, 6698) * 3 / 2 + LINE(11, 8561, 17) / 2;
	WRITE_LINE(11, 8561) = -Acc;
	Acc = -Acc / 2 + LINE(11, 8561, 17) + LINE(10, 8542, 25) / 2;
	WRITE_LINE(10, 8542) = -Acc;
	Acc = -Acc / 2 + LINE(10, 8542, 25) + LINE(9, 8515, 35) / 2;
	WRITE_LINE(9, 8515) = -Acc;
	Acc = -Acc / 2 + LINE(9, 8515, 35) + LINE(8, 8478, 52) / 2;
	WRITE_LINE(8, 8478) = -Acc;
	Acc = -Acc / 2 + LINE(8, 8478, 52) + LINE(7, 8424, 74) / 2;
	WRITE_LINE(7, 8424) = -Acc;
	Acc = -Acc / 2 + LINE(7, 8424, 74) + LINE(15, 9212, 88) / 2;
	WRITE_LINE(15, 9212) = -Acc;
	Acc = -Acc / 2 + LINE(15, 9212, 88) + LINE(14, 9122, 123) / 2;
	WRITE_LINE(14, 9122) = -Acc;
	Acc = -Acc / 2 + LINE(14, 9122, 123) + LINE(13, 8997, 174) / 2;
	WRITE_LINE(13, 8997) = -Acc;
	Acc = -Acc / 2 + LINE(13, 8997, 174) + LINE(12, 8821, 258) / 2;
	WRITE_LINE(12, 8821) = -Acc;
	Acc = -Acc / 2 + LINE(12, 8821, 258);
	WRITE_LINE(1, 7566) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=63, taps=[63]
// Delay line 5: length=195, taps=[195]
// Delay line 6: length=41, taps=[41]
// Delay line 7: length=178, taps=[178]
// Delay line 8: length=114, taps=[114]
// Delay line 9: length=49, taps=[49]
// Delay line 10: length=6328, taps=[6328]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_73(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 16381, 6328) + LINE(6, 9704, 41) / 2;
	WRITE_LINE(6, 9704) = -Acc;
	Acc = -Acc / 2 + LINE(6, 9704, 41) + LINE(5, 9661, 195) / 2;
	WRITE_LINE(5, 9661) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9661, 195) + LINE(4, 9464, 63) / 2;
	WRITE_LINE(4, 9464) = -Acc;
	Acc = -Acc / 2 + LINE(4, 9464, 63);
	tmp5 = Acc;
	Acc = LINE(10, 16381, 6328) + LINE(9, 10051, 49) / 2;
	WRITE_LINE(9, 10051) = -Acc;
	Acc = -Acc / 2 + LINE(9, 10051, 49) + LINE(8, 10000, 114) / 2;
	WRITE_LINE(8, 10000) = -Acc;
	Acc = -Acc / 2 + LINE(8, 10000, 114) + LINE(7, 9884, 178) / 2;
	WRITE_LINE(7, 9884) = -Acc;
	Acc = -Acc / 2 + LINE(7, 9884, 178);
	tmp3 = Acc;
	Acc = LINE(3, 9399, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(0, 0, 1) / 8 + tmp1;
	WRITE_LINE(3, 9399) = Acc;
	Acc = LINE(3, 9399, 1);
	tmp1 = -Acc;
	Acc = LINE(0, 0, 1) + tmp1;
	WRITE_LINE(1, 9384) = Acc;
	Acc = LINE(2, 9393, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(1, 9384, 1) / 8 + tmp1;
	WRITE_LINE(2, 9393) = Acc;
	Acc = LINE(2, 9393, 1);
	tmp1 = -Acc;
	Acc = LINE(1, 9384, 1) + tmp1;
	WRITE_LINE(10, 16381) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=63, taps=[63]
// Delay line 4: length=195, taps=[195]
// Delay line 5: length=41, taps=[41]
// Delay line 6: length=178, taps=[178]
// Delay line 7: length=114, taps=[114]
// Delay line 8: length=49, taps=[49]
// Delay line 9: length=5625, taps=[5625]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_74(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(9, 16381, 5625) + LINE(5, 10407, 41) / 2;
	WRITE_LINE(5, 10407) = -Acc;
	Acc = -Acc / 2 + LINE(5, 10407, 41) + LINE(4, 10364, 195) / 2;
	WRITE_LINE(4, 10364) = -Acc;
	Acc = -Acc / 2 + LINE(4, 10364, 195) + LINE(3, 10167, 63) / 2;
	WRITE_LINE(3, 10167) = -Acc;
	Acc = -Acc / 2 + LINE(3, 10167, 63);
	tmp5 = Acc;
	Acc = LINE(9, 16381, 5625) + LINE(8, 10754, 49) / 2;
	WRITE_LINE(8, 10754) = -Acc;
	Acc = -Acc / 2 + LINE(8, 10754, 49) + LINE(7, 10703, 114) / 2;
	WRITE_LINE(7, 10703) = -Acc;
	Acc = -Acc / 2 + LINE(7, 10703, 114) + LINE(6, 10587, 178) / 2;
	WRITE_LINE(6, 10587) = -Acc;
	Acc = -Acc / 2 + LINE(6, 10587, 178);
	tmp3 = Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 10102, 1) / 2;
	WRITE_LINE(2, 10102) = Acc;
	Acc = LINE(1, 10099, 1) * 15 / 16;
	tmp1 = Acc;
	Acc = Acc * -3 / 16 + LINE(2, 10102, 1) / 8 + tmp1;
	WRITE_LINE(1, 10099) = Acc;
	Acc = LINE(1, 10099, 1);
	tmp1 = -Acc;
	Acc = LINE(2, 10102, 1) + tmp1;
	WRITE_LINE(9, 16381) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=63, taps=[63]
// Delay line 4: length=195, taps=[195]
// Delay line 5: length=41, taps=[41]
// Delay line 6: length=178, taps=[178]
// Delay line 7: length=114, taps=[114]
// Delay line 8: length=49, taps=[49]
// Delay line 9: length=5156, taps=[5156]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_75(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(9, 16381, 5156) + LINE(5, 10876, 41) / 2;
	WRITE_LINE(5, 10876) = -Acc;
	Acc = -Acc / 2 + LINE(5, 10876, 41) + LINE(4, 10833, 195) / 2;
	WRITE_LINE(4, 10833) = -Acc;
	Acc = -Acc / 2 + LINE(4, 10833, 195) + LINE(3, 10636, 63) / 2;
	WRITE_LINE(3, 10636) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 10636, 63) * 3 / 2;
	tmp5 = Acc;
	Acc = LINE(9, 16381, 5156) + LINE(8, 11223, 49) / 2;
	WRITE_LINE(8, 11223) = -Acc;
	Acc = -Acc / 2 + LINE(8, 11223, 49) + LINE(7, 11172, 114) / 2;
	WRITE_LINE(7, 11172) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11172, 114) + LINE(6, 11056, 178) / 2;
	WRITE_LINE(6, 11056) = -Acc;
	Acc = Acc * -3 / 4 + LINE(6, 11056, 178) * 3 / 2;
	tmp3 = Acc;
	Acc = LINE(2, 10571, 1) * 3 / 8;
	tmp1 = Acc;
	Acc = LINE(0, 0, 1) * 5 / 8 + tmp1;
	WRITE_LINE(2, 10571) = Acc;
	Acc = LINE(1, 10568, 1) * 5 / 8;
	tmp1 = Acc;
	Acc = LINE(2, 10571, 1) * 3 / 8 + tmp1;
	WRITE_LINE(1, 10568) = Acc;
	Acc = LINE(1, 10568, 1);
	WRITE_LINE(9, 16381) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=600, taps=[600]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=1, taps=[1]
// Delay line 5: length=258, taps=[258]
// Delay line 6: length=213, taps=[213]
// Delay line 7: length=149, taps=[149]
// Delay line 8: length=105, taps=[105]
// Delay line 9: length=74, taps=[74]
// Delay line 10: length=52, taps=[52]
// Delay line 11: length=35, taps=[35]
// Delay line 12: length=25, taps=[25]
// Delay line 13: length=17, taps=[17]
// Delay line 14: length=304, taps=[304]
// Delay line 15: length=174, taps=[174]
// Delay line 16: length=123, taps=[123]
// Delay line 17: length=88, taps=[88]
// Delay line 18: length=61, taps=[61]
// Delay line 19: length=45, taps=[45]
// Delay line 20: length=29, taps=[29]
// Delay line 21: length=22, taps=[22]
// Delay line 22: length=15, taps=[15]
// Delay line 23: length=4687, taps=[4687]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_76(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 9855, 1);
	tmp3 = Acc;
	Acc = LINE(1, 9852, 600);
	tmp5 = Acc;
	Acc = LINE(23, 16381, 4687) * 3 / 2 + LINE(22, 11692, 15) / 2;
	WRITE_LINE(22, 11692) = -Acc;
	Acc = -Acc / 2 + LINE(22, 11692, 15) + LINE(21, 11675, 22) / 2;
	WRITE_LINE(21, 11675) = -Acc;
	Acc = -Acc / 2 + LINE(21, 11675, 22) + LINE(20, 11651, 29) / 2;
	WRITE_LINE(20, 11651) = -Acc;
	Acc = -Acc / 2 + LINE(20, 11651, 29) + LINE(19, 11620, 45) / 2;
	WRITE_LINE(19, 11620) = -Acc;
	Acc = -Acc / 2 + LINE(19, 11620, 45) + LINE(18, 11573, 61) / 2;
	WRITE_LINE(18, 11573) = -Acc;
	Acc = -Acc / 2 + LINE(18, 11573, 61) + LINE(8, 10600, 105) / 2;
	WRITE_LINE(8, 10600) = -Acc;
	Acc = -Acc / 2 + LINE(8, 10600, 105) + LINE(7, 10493, 149) / 2;
	WRITE_LINE(7, 10493) = -Acc;
	Acc = -Acc / 2 + LINE(7, 10493, 149) + LINE(6, 10342, 213) / 2;
	WRITE_LINE(6, 10342) = -Acc;
	Acc = -Acc / 2 + LINE(6, 10342, 213) + LINE(5, 10127, 258) / 2;
	WRITE_LINE(5, 10127) = -Acc;
	Acc = -Acc / 2 + LINE(5, 10127, 258);
	WRITE_LINE(2, 9855) = Acc;
	Acc = LINE(23, 16381, 4687) * 3 / 2 + LINE(13, 10813, 17) / 2;
	WRITE_LINE(13, 10813) = -Acc;
	Acc = -Acc / 2 + LINE(13, 10813, 17) + LINE(12, 10794, 25) / 2;
	WRITE_LINE(12, 10794) = -Acc;
	Acc = -Acc / 2 + LINE(12, 10794, 25) + LINE(11, 10767, 35) / 2;
	WRITE_LINE(11, 10767) = -Acc;
	Acc = -Acc / 2 + LINE(11, 10767, 35) + LINE(10, 10730, 52) / 2;
	WRITE_LINE(10, 10730) = -Acc;
	Acc = -Acc / 2 + LINE(10, 10730, 52) + LINE(9, 10676, 74) / 2;
	WRITE_LINE(9, 10676) = -Acc;
	Acc = -Acc / 2 + LINE(9, 10676, 74) + LINE(17, 11510, 88) / 2;
	WRITE_LINE(17, 11510) = -Acc;
	Acc = -Acc / 2 + LINE(17, 11510, 88) + LINE(16, 11420, 123) / 2;
	WRITE_LINE(16, 11420) = -Acc;
	Acc = -Acc / 2 + LINE(16, 11420, 123) + LINE(15, 11295, 174) / 2;
	WRITE_LINE(15, 11295) = -Acc;
	Acc = -Acc / 2 + LINE(15, 11295, 174) + LINE(14, 11119, 304) / 2;
	WRITE_LINE(14, 11119) = -Acc;
	Acc = -Acc / 2 + LINE(14, 11119, 304);
	WRITE_LINE(1, 9852) = Acc;
	Acc = LINE(4, 9867, 1) * 3 / 8;
	tmp1 = Acc;
	*out_left = tmp5;
	Acc = LINE(0, 0, 1) * 5 / 8 + tmp1;
	WRITE_LINE(4, 9867) = Acc;
	Acc = LINE(3, 9861, 1) * 5 / 8;
	tmp1 = Acc;
	Acc = LINE(4, 9867, 1) * 3 / 8 + tmp1;
	WRITE_LINE(3, 9861) = Acc;
	*out_right = tmp3;
	Acc = LINE(3, 9861, 1);
	WRITE_LINE(23, 16381) = Acc;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=4224, taps=[4224]
// Delay line 1: length=3, taps=[1, 3]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=30, taps=[30]
// Delay line 4: length=36, taps=[36]
// Delay line 5: length=13, taps=[13]
// Delay line 6: length=7, taps=[7]
// Delay line 7: length=62, taps=[62]
// Delay line 8: length=52, taps=[52]
// Delay line 9: length=4, taps=[4]
// Delay line 10: length=369, taps=[369]
// Delay line 11: length=300, taps=[300]
// Delay line 12: length=251, taps=[251]
// Delay line 13: length=215, taps=[215]
// Delay line 14: length=174, taps=[174]
// Delay line 15: length=143, taps=[143]
// Delay line 16: length=127, taps=[127]
// Delay line 17: length=103, taps=[103]
// Delay line 18: length=87, taps=[87]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_77(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp13;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 4224) + LINE(18, 12158, 87) / 2;
	WRITE_LINE(18, 12158) = -Acc;
	Acc = -Acc / 2 + LINE(18, 12158, 87) + LINE(17, 12069, 103) / 2;
	WRITE_LINE(17, 12069) = -Acc;
	Acc = -Acc / 2 + LINE(17, 12069, 103) + LINE(16, 11964, 127) / 2;
	WRITE_LINE(16, 11964) = -Acc;
	Acc = -Acc / 2 + LINE(16, 11964, 127) + LINE(15, 11835, 143) / 2;
	WRITE_LINE(15, 11835) = -Acc;
	Acc = -Acc / 2 + LINE(15, 11835, 143) + LINE(14, 11690, 174) / 2;
	WRITE_LINE(14, 11690) = -Acc;
	Acc = -Acc / 2 + LINE(14, 11690, 174) + LINE(13, 11514, 215) / 2;
	WRITE_LINE(13, 11514) = -Acc;
	Acc = -Acc / 2 + LINE(13, 11514, 215) + LINE(12, 11297, 251) / 2;
	WRITE_LINE(12, 11297) = -Acc;
	Acc = -Acc / 2 + LINE(12, 11297, 251) + LINE(11, 11044, 300) / 2;
	WRITE_LINE(11, 11044) = -Acc;
	Acc = -Acc / 2 + LINE(11, 11044, 300) + LINE(10, 10742, 369) / 2;
	WRITE_LINE(10, 10742) = -Acc;
	Acc = -Acc / 2 + LINE(10, 10742, 369) + LINE(9, 10371, 4) / 2;
	WRITE_LINE(9, 10371) = -Acc;
	Acc = -Acc / 2 + LINE(9, 10371, 4) + LINE(8, 10365, 52) / 2;
	WRITE_LINE(8, 10365) = -Acc;
	Acc = -Acc / 2 + LINE(8, 10365, 52) + LINE(7, 10311, 62) / 2;
	WRITE_LINE(7, 10311) = -Acc;
	Acc = -Acc / 2 + LINE(7, 10311, 62) + LINE(6, 10247, 7) / 2;
	WRITE_LINE(6, 10247) = -Acc;
	Acc = -Acc / 2 + LINE(6, 10247, 7) + LINE(5, 10238, 13) / 2;
	WRITE_LINE(5, 10238) = -Acc;
	Acc = -Acc / 2 + LINE(5, 10238, 13);
	tmp13 = Acc;
	Acc = tmp13 + LINE(4, 10223, 36) / 2;
	WRITE_LINE(4, 10223) = -Acc;
	Acc = -Acc / 2 + LINE(4, 10223, 36);
	WRITE_LINE(2, 6) = -Acc;
	Acc = tmp13 + LINE(3, 10185, 30) / 2;
	WRITE_LINE(3, 10185) = -Acc;
	Acc = -Acc / 2 + LINE(3, 10185, 30);
	WRITE_LINE(1, 4) = -Acc;
	*out_left = LINE(2, 6, 1);
	*out_right = LINE(1, 4, 1);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=3753, taps=[3753]
// Delay line 1: length=2, taps=[2]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_78(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 3753);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 3753);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=63, taps=[63]
// Delay line 4: length=195, taps=[195]
// Delay line 5: length=41, taps=[41]
// Delay line 6: length=178, taps=[178]
// Delay line 7: length=114, taps=[114]
// Delay line 8: length=49, taps=[49]
// Delay line 9: length=3515, taps=[3515]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_79(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(9, 16381, 3515) + LINE(5, 9174, 41) / 2;
	WRITE_LINE(5, 9174) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9174, 41) + LINE(4, 9131, 195) / 2;
	WRITE_LINE(4, 9131) = -Acc;
	Acc = -Acc / 2 + LINE(4, 9131, 195) + LINE(3, 8934, 63) / 2;
	WRITE_LINE(3, 8934) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 8934, 63) * 3 / 2;
	tmp5 = Acc;
	Acc = LINE(9, 16381, 3515) + LINE(8, 9521, 49) / 2;
	WRITE_LINE(8, 9521) = -Acc;
	Acc = -Acc / 2 + LINE(8, 9521, 49) + LINE(7, 9470, 114) / 2;
	WRITE_LINE(7, 9470) = -Acc;
	Acc = -Acc / 2 + LINE(7, 9470, 114) + LINE(6, 9354, 178) / 2;
	WRITE_LINE(6, 9354) = -Acc;
	Acc = Acc * -3 / 4 + LINE(6, 9354, 178) * 3 / 2;
	tmp3 = Acc;
	Acc = LINE(2, 8869, 1) * 3 / 8;
	tmp1 = Acc;
	Acc = LINE(0, 0, 1) * 5 / 8 + tmp1;
	WRITE_LINE(2, 8869) = Acc;
	Acc = LINE(1, 8866, 1) * 5 / 8;
	tmp1 = Acc;
	Acc = LINE(2, 8869, 1) * 3 / 8 + tmp1;
	WRITE_LINE(1, 8866) = Acc;
	Acc = LINE(1, 8866, 1);
	WRITE_LINE(9, 16381) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=1, taps=[1]
// Delay line 5: length=1, taps=[1]
// Delay line 6: length=63, taps=[63]
// Delay line 7: length=195, taps=[195]
// Delay line 8: length=41, taps=[41]
// Delay line 9: length=178, taps=[178]
// Delay line 10: length=114, taps=[114]
// Delay line 11: length=49, taps=[49]
// Delay line 12: length=3281, taps=[3281]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_80(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(12, 16381, 3281) + LINE(8, 12751, 41) / 2;
	WRITE_LINE(8, 12751) = -Acc;
	Acc = -Acc / 2 + LINE(8, 12751, 41) + LINE(7, 12708, 195) / 2;
	WRITE_LINE(7, 12708) = -Acc;
	Acc = -Acc / 2 + LINE(7, 12708, 195) + LINE(6, 12511, 63) / 2;
	WRITE_LINE(6, 12511) = -Acc;
	Acc = -Acc / 2 + LINE(6, 12511, 63);
	WRITE_LINE(2, 6) = Acc;
	Acc = LINE(12, 16381, 3281) + LINE(11, 13098, 49) / 2;
	WRITE_LINE(11, 13098) = -Acc;
	Acc = -Acc / 2 + LINE(11, 13098, 49) + LINE(10, 13047, 114) / 2;
	WRITE_LINE(10, 13047) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13047, 114) + LINE(9, 12931, 178) / 2;
	WRITE_LINE(9, 12931) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12931, 178);
	WRITE_LINE(1, 4) = Acc;
	Acc = LINE(5, 12446, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(0, 0, 1) / 8 + tmp1;
	WRITE_LINE(5, 12446) = Acc;
	Acc = LINE(5, 12446, 1);
	tmp1 = -Acc;
	Acc = LINE(0, 0, 1) + tmp1;
	WRITE_LINE(3, 12431) = Acc;
	Acc = LINE(4, 12443, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(3, 12431, 1) / 8 + tmp1;
	WRITE_LINE(4, 12443) = Acc;
	Acc = LINE(4, 12443, 1);
	tmp1 = -Acc;
	Acc = LINE(3, 12431, 1) + tmp1;
	WRITE_LINE(12, 16381) = Acc;
	*out_left = LINE(2, 6, 1);
	*out_right = LINE(1, 4, 1);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=63, taps=[63]
// Delay line 4: length=195, taps=[195]
// Delay line 5: length=41, taps=[41]
// Delay line 6: length=178, taps=[178]
// Delay line 7: length=114, taps=[114]
// Delay line 8: length=49, taps=[49]
// Delay line 9: length=3046, taps=[3046]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_81(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(9, 16381, 3046) + LINE(5, 12986, 41) / 2;
	WRITE_LINE(5, 12986) = -Acc;
	Acc = -Acc / 2 + LINE(5, 12986, 41) + LINE(4, 12943, 195) / 2;
	WRITE_LINE(4, 12943) = -Acc;
	Acc = -Acc / 2 + LINE(4, 12943, 195) + LINE(3, 12746, 63) / 2;
	WRITE_LINE(3, 12746) = -Acc;
	Acc = -Acc / 2 + LINE(3, 12746, 63);
	tmp5 = Acc;
	Acc = LINE(9, 16381, 3046) + LINE(8, 13333, 49) / 2;
	WRITE_LINE(8, 13333) = -Acc;
	Acc = -Acc / 2 + LINE(8, 13333, 49) + LINE(7, 13282, 114) / 2;
	WRITE_LINE(7, 13282) = -Acc;
	Acc = -Acc / 2 + LINE(7, 13282, 114) + LINE(6, 13166, 178) / 2;
	WRITE_LINE(6, 13166) = -Acc;
	Acc = -Acc / 2 + LINE(6, 13166, 178);
	tmp3 = Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 12681, 1) / 2;
	WRITE_LINE(2, 12681) = Acc;
	Acc = LINE(1, 12678, 1) * 15 / 16;
	tmp1 = Acc;
	Acc = Acc * -3 / 16 + LINE(2, 12681, 1) / 8 + tmp1;
	WRITE_LINE(1, 12678) = Acc;
	Acc = LINE(1, 12678, 1);
	tmp1 = -Acc;
	Acc = LINE(2, 12681, 1) * 3 / 2 + tmp1 * 3 / 2;
	WRITE_LINE(9, 16381) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=2815, taps=[2815]
// Delay line 1: length=2, taps=[2]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_82(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 2815);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 2815);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=2580, taps=[2580]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=304, taps=[304]
// Delay line 4: length=213, taps=[213]
// Delay line 5: length=149, taps=[149]
// Delay line 6: length=105, taps=[105]
// Delay line 7: length=74, taps=[74]
// Delay line 8: length=52, taps=[52]
// Delay line 9: length=35, taps=[35]
// Delay line 10: length=25, taps=[25]
// Delay line 11: length=17, taps=[17]
// Delay line 12: length=258, taps=[258]
// Delay line 13: length=174, taps=[174]
// Delay line 14: length=123, taps=[123]
// Delay line 15: length=88, taps=[88]
// Delay line 16: length=61, taps=[61]
// Delay line 17: length=45, taps=[45]
// Delay line 18: length=29, taps=[29]
// Delay line 19: length=22, taps=[22]
// Delay line 20: length=15, taps=[15]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_83(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(1, 11684, 1) / 4 + LINE(2, 11687, 1);
	tmp3 = Acc;
	Acc = -LINE(2, 11687, 1) / 4 + LINE(1, 11684, 1);
	tmp5 = Acc;
	Acc = LINE(0, 0, 2580) + LINE(20, 13512, 15) / 2;
	WRITE_LINE(20, 13512) = -Acc;
	Acc = -Acc / 2 + LINE(20, 13512, 15) + LINE(19, 13495, 22) / 2;
	WRITE_LINE(19, 13495) = -Acc;
	Acc = -Acc / 2 + LINE(19, 13495, 22) + LINE(18, 13471, 29) / 2;
	WRITE_LINE(18, 13471) = -Acc;
	Acc = -Acc / 2 + LINE(18, 13471, 29) + LINE(17, 13440, 45) / 2;
	WRITE_LINE(17, 13440) = -Acc;
	Acc = -Acc / 2 + LINE(17, 13440, 45) + LINE(16, 13393, 61) / 2;
	WRITE_LINE(16, 13393) = -Acc;
	Acc = -Acc / 2 + LINE(16, 13393, 61) + LINE(6, 12466, 105) / 2;
	WRITE_LINE(6, 12466) = -Acc;
	Acc = -Acc / 2 + LINE(6, 12466, 105) + LINE(5, 12359, 149) / 2;
	WRITE_LINE(5, 12359) = -Acc;
	Acc = -Acc / 2 + LINE(5, 12359, 149) + LINE(4, 12208, 213) / 2;
	WRITE_LINE(4, 12208) = -Acc;
	Acc = -Acc / 2 + LINE(4, 12208, 213) + LINE(3, 11993, 304) / 2;
	WRITE_LINE(3, 11993) = -Acc;
	Acc = -Acc / 2 + LINE(3, 11993, 304);
	WRITE_LINE(2, 11687) = Acc;
	Acc = LINE(0, 0, 2580) + LINE(11, 12679, 17) / 2;
	WRITE_LINE(11, 12679) = -Acc;
	Acc = -Acc / 2 + LINE(11, 12679, 17) + LINE(10, 12660, 25) / 2;
	WRITE_LINE(10, 12660) = -Acc;
	Acc = -Acc / 2 + LINE(10, 12660, 25) + LINE(9, 12633, 35) / 2;
	WRITE_LINE(9, 12633) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12633, 35) + LINE(8, 12596, 52) / 2;
	WRITE_LINE(8, 12596) = -Acc;
	Acc = -Acc / 2 + LINE(8, 12596, 52) + LINE(7, 12542, 74) / 2;
	WRITE_LINE(7, 12542) = -Acc;
	Acc = -Acc / 2 + LINE(7, 12542, 74) + LINE(15, 13330, 88) / 2;
	WRITE_LINE(15, 13330) = -Acc;
	Acc = -Acc / 2 + LINE(15, 13330, 88) + LINE(14, 13240, 123) / 2;
	WRITE_LINE(14, 13240) = -Acc;
	Acc = -Acc / 2 + LINE(14, 13240, 123) + LINE(13, 13115, 174) / 2;
	WRITE_LINE(13, 13115) = -Acc;
	Acc = -Acc / 2 + LINE(13, 13115, 174) + LINE(12, 12939, 258) / 2;
	WRITE_LINE(12, 12939) = -Acc;
	Acc = -Acc / 2 + LINE(12, 12939, 258);
	WRITE_LINE(1, 11684) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=2346, taps=[2346]
// Delay line 1: length=2, taps=[2]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_84(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 2346);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 2346);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=1, taps=[1]
// Delay line 5: length=2, taps=[2]
// Delay line 6: length=21, taps=[21]
// Delay line 7: length=14, taps=[14]
// Delay line 8: length=99, taps=[99]
// Delay line 9: length=74, taps=[74]
// Delay line 10: length=52, taps=[52]
// Delay line 11: length=35, taps=[35]
// Delay line 12: length=3, taps=[3]
// Delay line 13: length=8, taps=[8]
// Delay line 14: length=12, taps=[12]
// Delay line 15: length=88, taps=[88]
// Delay line 16: length=61, taps=[61]
// Delay line 17: length=45, taps=[45]
// Delay line 18: length=29, taps=[29]
// Delay line 19: length=2109, taps=[2109]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_85(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(1, 13597, 1) / 4 + LINE(2, 13600, 1);
	tmp3 = Acc;
	Acc = -LINE(2, 13600, 1) / 4 + LINE(1, 13597, 1);
	tmp5 = Acc;
	Acc = LINE(19, 16381, 2109) * 3 / 2 + LINE(18, 14229, 29) / 2;
	WRITE_LINE(18, 14229) = -Acc;
	Acc = -Acc / 2 + LINE(18, 14229, 29) + LINE(17, 14198, 45) / 2;
	WRITE_LINE(17, 14198) = -Acc;
	Acc = -Acc / 2 + LINE(17, 14198, 45) + LINE(16, 14151, 61) / 2;
	WRITE_LINE(16, 14151) = -Acc;
	Acc = -Acc / 2 + LINE(16, 14151, 61) + LINE(8, 13756, 99) / 2;
	WRITE_LINE(8, 13756) = -Acc;
	Acc = -Acc / 2 + LINE(8, 13756, 99) + LINE(7, 13655, 14) / 2;
	WRITE_LINE(7, 13655) = -Acc;
	Acc = -Acc / 2 + LINE(7, 13655, 14) + LINE(6, 13639, 21) / 2;
	WRITE_LINE(6, 13639) = -Acc;
	Acc = -Acc / 2 + LINE(6, 13639, 21) + LINE(5, 13616, 2) / 2;
	WRITE_LINE(5, 13616) = -Acc;
	Acc = -Acc / 2 + LINE(5, 13616, 2);
	WRITE_LINE(2, 13600) = Acc;
	Acc = LINE(19, 16381, 2109) * 3 / 2 + LINE(11, 13923, 35) / 2;
	WRITE_LINE(11, 13923) = -Acc;
	Acc = -Acc / 2 + LINE(11, 13923, 35) + LINE(10, 13886, 52) / 2;
	WRITE_LINE(10, 13886) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13886, 52) + LINE(9, 13832, 74) / 2;
	WRITE_LINE(9, 13832) = -Acc;
	Acc = -Acc / 2 + LINE(9, 13832, 74) + LINE(15, 14088, 88) / 2;
	WRITE_LINE(15, 14088) = -Acc;
	Acc = -Acc / 2 + LINE(15, 14088, 88) + LINE(14, 13998, 12) / 2;
	WRITE_LINE(14, 13998) = -Acc;
	Acc = -Acc / 2 + LINE(14, 13998, 12) + LINE(13, 13984, 8) / 2;
	WRITE_LINE(13, 13984) = -Acc;
	Acc = -Acc / 2 + LINE(13, 13984, 8) + LINE(12, 13974, 3) / 2;
	WRITE_LINE(12, 13974) = -Acc;
	Acc = -Acc / 2 + LINE(12, 13974, 3);
	WRITE_LINE(1, 13597) = Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(4, 13612, 1) / 2;
	WRITE_LINE(4, 13612) = Acc;
	Acc = LINE(3, 13609, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(4, 13612, 1) / 8 + tmp1;
	WRITE_LINE(3, 13609) = Acc;
	Acc = LINE(3, 13609, 1);
	tmp1 = -Acc;
	*out_left = tmp5;
	Acc = LINE(4, 13612, 1) * 3 / 2 + tmp1 * 3 / 2;
	WRITE_LINE(19, 16381) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=15705, taps=[7853, 15705]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=63, taps=[63]
// Delay line 3: length=195, taps=[195]
// Delay line 4: length=41, taps=[41]
// Delay line 5: length=178, taps=[178]
// Delay line 6: length=114, taps=[114]
// Delay line 7: length=49, taps=[49]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_86(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 15705) / 2 + LINE(0, 0, 7853) + LINE(4, 330, 41) / 2;
	WRITE_LINE(4, 330) = -Acc;
	Acc = -Acc / 2 + LINE(4, 330, 41) + LINE(3, 287, 195) / 2;
	WRITE_LINE(3, 287) = -Acc;
	Acc = -Acc / 2 + LINE(3, 287, 195) + LINE(2, 90, 63) / 2;
	WRITE_LINE(2, 90) = -Acc;
	Acc = -Acc / 2 + LINE(2, 90, 63);
	tmp5 = Acc;
	Acc = LINE(0, 0, 15705) / 2 + LINE(0, 0, 7853) + LINE(7, 677, 49) / 2;
	WRITE_LINE(7, 677) = -Acc;
	Acc = -Acc / 2 + LINE(7, 677, 49) + LINE(6, 626, 114) / 2;
	WRITE_LINE(6, 626) = -Acc;
	Acc = -Acc / 2 + LINE(6, 626, 114) + LINE(5, 510, 178) / 2;
	WRITE_LINE(5, 510) = -Acc;
	Acc = -Acc / 2 + LINE(5, 510, 178);
	WRITE_LINE(1, 3) = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=7, taps=[1, 7]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=63, taps=[63]
// Delay line 5: length=195, taps=[195]
// Delay line 6: length=41, taps=[41]
// Delay line 7: length=178, taps=[178]
// Delay line 8: length=114, taps=[114]
// Delay line 9: length=49, taps=[49]
// Delay line 10: length=6093, taps=[6093]
// Delay line 11: length=6093, taps=[6093]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_87(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(11, 16381, 6093) / 2 + LINE(10, 10286, 6093) / 2 + LINE(6, 3844, 41) / 2;
	WRITE_LINE(6, 3844) = -Acc;
	Acc = -Acc / 2 + LINE(6, 3844, 41) + LINE(5, 3801, 195) / 2;
	WRITE_LINE(5, 3801) = -Acc;
	Acc = -Acc / 2 + LINE(5, 3801, 195) + LINE(4, 3604, 63) / 2;
	WRITE_LINE(4, 3604) = -Acc;
	Acc = -Acc / 2 + LINE(4, 3604, 63);
	tmp5 = Acc;
	Acc = tmp5 * 21 / 32;
	tmp5 = Acc;
	Acc = LINE(11, 16381, 6093) / 2 + LINE(10, 10286, 6093) / 2 + LINE(9, 4191, 49) / 2;
	WRITE_LINE(9, 4191) = -Acc;
	Acc = -Acc / 2 + LINE(9, 4191, 49) + LINE(8, 4140, 114) / 2;
	WRITE_LINE(8, 4140) = -Acc;
	Acc = -Acc / 2 + LINE(8, 4140, 114) + LINE(7, 4024, 178) / 2;
	WRITE_LINE(7, 4024) = -Acc;
	Acc = -Acc / 2 + LINE(7, 4024, 178);
	tmp3 = Acc;
	Acc = tmp3 * 21 / 32;
	tmp3 = Acc;
	Acc = LINE(3, 3539, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(0, 0, 1) / 8 + tmp1;
	WRITE_LINE(3, 3539) = Acc;
	Acc = LINE(3, 3539, 1);
	tmp1 = -Acc;
	Acc = LINE(0, 0, 1) * 3 / 2 + tmp1 * 3 / 2;
	WRITE_LINE(11, 16381) = Acc;
	Acc = LINE(2, 3536, 1) * 13 / 16;
	tmp1 = Acc;
	Acc = LINE(11, 16381, 6093) * 3 / 16 + tmp1;
	WRITE_LINE(2, 3536) = Acc;
	Acc = LINE(2, 3536, 1);
	tmp1 = -Acc;
	Acc = LINE(11, 16381, 6093) * 3 / 2 + tmp1 * 3 / 2;
	WRITE_LINE(10, 10286) = Acc;
	Acc = LINE(1, 3533, 1) / 4;
	tmp1 = Acc;
	*out_left = tmp5;
	Acc = LINE(1, 3533, 7) * 3 / 4 + tmp1;
	WRITE_LINE(1, 3533) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=1, taps=[1]
// Delay line 5: length=63, taps=[63]
// Delay line 6: length=195, taps=[195]
// Delay line 7: length=41, taps=[41]
// Delay line 8: length=178, taps=[178]
// Delay line 9: length=114, taps=[114]
// Delay line 10: length=49, taps=[49]
// Delay line 11: length=5390, taps=[5390]
// Delay line 12: length=5390, taps=[5390]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_88(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(12, 16381, 5390) / 2 + LINE(11, 10989, 5390) / 2 + LINE(7, 5250, 41) / 2;
	WRITE_LINE(7, 5250) = -Acc;
	Acc = -Acc / 2 + LINE(7, 5250, 41) + LINE(6, 5207, 195) / 2;
	WRITE_LINE(6, 5207) = -Acc;
	Acc = -Acc / 2 + LINE(6, 5207, 195) + LINE(5, 5010, 63) / 2;
	WRITE_LINE(5, 5010) = -Acc;
	Acc = Acc * -3 / 4 + LINE(5, 5010, 63) * 3 / 2;
	tmp5 = Acc;
	Acc = LINE(12, 16381, 5390) / 2 + LINE(11, 10989, 5390) / 2 + LINE(10, 5597, 49) / 2;
	WRITE_LINE(10, 5597) = -Acc;
	Acc = -Acc / 2 + LINE(10, 5597, 49) + LINE(9, 5546, 114) / 2;
	WRITE_LINE(9, 5546) = -Acc;
	Acc = -Acc / 2 + LINE(9, 5546, 114) + LINE(8, 5430, 178) / 2;
	WRITE_LINE(8, 5430) = -Acc;
	Acc = Acc * -3 / 4 + LINE(8, 5430, 178) * 3 / 2;
	tmp3 = Acc;
	Acc = LINE(4, 4945, 1) * 3 / 8;
	tmp1 = Acc;
	Acc = LINE(0, 0, 1) * 5 / 8 + tmp1;
	WRITE_LINE(4, 4945) = Acc;
	Acc = LINE(3, 4942, 1) * 15 / 16;
	tmp1 = Acc;
	Acc = Acc * -3 / 16 + LINE(4, 4945, 1) / 8 + tmp1;
	WRITE_LINE(3, 4942) = Acc;
	Acc = LINE(3, 4942, 1);
	tmp1 = -Acc;
	Acc = LINE(4, 4945, 1) + tmp1;
	WRITE_LINE(12, 16381) = Acc;
	Acc = LINE(12, 16381, 5390) / 2 + LINE(2, 4939, 1) / 2;
	WRITE_LINE(2, 4939) = Acc;
	Acc = LINE(1, 4936, 1) * 15 / 16;
	tmp1 = Acc;
	Acc = Acc * -3 / 16 + LINE(2, 4939, 1) / 8 + tmp1;
	WRITE_LINE(1, 4936) = Acc;
	Acc = LINE(1, 4936, 1);
	tmp1 = -Acc;
	Acc = LINE(2, 4939, 1) * 3 / 2 + tmp1 * 3 / 2;
	WRITE_LINE(11, 10989) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=8919, taps=[4210, 8919]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=30, taps=[30]
// Delay line 4: length=36, taps=[36]
// Delay line 5: length=157, taps=[157]
// Delay line 6: length=175, taps=[175]
// Delay line 7: length=369, taps=[369]
// Delay line 8: length=300, taps=[300]
// Delay line 9: length=251, taps=[251]
// Delay line 10: length=215, taps=[215]
// Delay line 11: length=174, taps=[174]
// Delay line 12: length=143, taps=[143]
// Delay line 13: length=127, taps=[127]
// Delay line 14: length=103, taps=[103]
// Delay line 15: length=87, taps=[87]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_89(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp13;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(0, 0, 8919) / 4 + LINE(0, 0, 4210) / 2 + LINE(15, 7463, 87) / 2;
	WRITE_LINE(15, 7463) = -Acc;
	Acc = -Acc / 2 + LINE(15, 7463, 87) + LINE(14, 7374, 103) / 2;
	WRITE_LINE(14, 7374) = -Acc;
	Acc = -Acc / 2 + LINE(14, 7374, 103) + LINE(13, 7269, 127) / 2;
	WRITE_LINE(13, 7269) = -Acc;
	Acc = -Acc / 2 + LINE(13, 7269, 127) + LINE(12, 7140, 143) / 2;
	WRITE_LINE(12, 7140) = -Acc;
	Acc = -Acc / 2 + LINE(12, 7140, 143) + LINE(11, 6995, 174) / 2;
	WRITE_LINE(11, 6995) = -Acc;
	Acc = -Acc / 2 + LINE(11, 6995, 174) + LINE(10, 6819, 215) / 2;
	WRITE_LINE(10, 6819) = -Acc;
	Acc = -Acc / 2 + LINE(10, 6819, 215) + LINE(9, 6602, 251) / 2;
	WRITE_LINE(9, 6602) = -Acc;
	Acc = -Acc / 2 + LINE(9, 6602, 251) + LINE(8, 6349, 300) / 2;
	WRITE_LINE(8, 6349) = -Acc;
	Acc = -Acc / 2 + LINE(8, 6349, 300) + LINE(7, 6047, 369) / 2;
	WRITE_LINE(7, 6047) = -Acc;
	Acc = -Acc / 2 + LINE(7, 6047, 369);
	tmp13 = Acc;
	Acc = tmp13 + LINE(6, 5469, 175) / 2;
	WRITE_LINE(6, 5469) = -Acc;
	Acc = -Acc / 2 + LINE(6, 5469, 175) + LINE(4, 5133, 36) / 2;
	WRITE_LINE(4, 5133) = -Acc;
	Acc = -Acc / 2 + LINE(4, 5133, 36);
	WRITE_LINE(2, 6) = -Acc;
	Acc = tmp13 + LINE(5, 5292, 157) / 2;
	WRITE_LINE(5, 5292) = -Acc;
	Acc = -Acc / 2 + LINE(5, 5292, 157) + LINE(3, 5095, 30) / 2;
	WRITE_LINE(3, 5095) = -Acc;
	Acc = -Acc / 2 + LINE(3, 5095, 30);
	WRITE_LINE(1, 4) = -Acc;
	*out_left = LINE(2, 6, 1);
	*out_right = LINE(1, 4, 1);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=8626, taps=[3890, 4101, 8204, 8626]
// Delay line 1: length=2, taps=[2]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_90(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 4101) + LINE(0, 0, 8204) / 2;
	tmp5 = Acc;
	Acc = LINE(0, 0, 3890) + LINE(0, 0, 8626) / 2;
	WRITE_LINE(1, 3) = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=63, taps=[63]
// Delay line 4: length=195, taps=[195]
// Delay line 5: length=41, taps=[41]
// Delay line 6: length=178, taps=[178]
// Delay line 7: length=114, taps=[114]
// Delay line 8: length=49, taps=[49]
// Delay line 9: length=3515, taps=[3515]
// Delay line 10: length=3515, taps=[3515]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_91(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 16381, 3515) + LINE(5, 9000, 41) / 2;
	WRITE_LINE(5, 9000) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9000, 41) + LINE(4, 8957, 195) / 2;
	WRITE_LINE(4, 8957) = -Acc;
	Acc = -Acc / 2 + LINE(4, 8957, 195) + LINE(3, 8760, 63) / 2;
	WRITE_LINE(3, 8760) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 8760, 63) * 3 / 2;
	tmp5 = Acc;
	Acc = LINE(9, 12864, 3515) + LINE(8, 9347, 49) / 2;
	WRITE_LINE(8, 9347) = -Acc;
	Acc = -Acc / 2 + LINE(8, 9347, 49) + LINE(7, 9296, 114) / 2;
	WRITE_LINE(7, 9296) = -Acc;
	Acc = -Acc / 2 + LINE(7, 9296, 114) + LINE(6, 9180, 178) / 2;
	WRITE_LINE(6, 9180) = -Acc;
	Acc = Acc * -3 / 4 + LINE(6, 9180, 178) * 3 / 2;
	tmp3 = Acc;
	Acc = tmp3 * 21 / 32;
	tmp3 = Acc;
	Acc = LINE(2, 8695, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(0, 0, 1) / 8 + tmp1;
	WRITE_LINE(2, 8695) = Acc;
	Acc = LINE(2, 8695, 1);
	tmp1 = -Acc;
	Acc = LINE(0, 0, 1) + tmp1;
	WRITE_LINE(10, 16381) = Acc;
	Acc = LINE(1, 8692, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(10, 16381, 3515) / 8 + tmp1;
	WRITE_LINE(1, 8692) = Acc;
	Acc = LINE(1, 8692, 1);
	tmp1 = -Acc;
	Acc = LINE(10, 16381, 3515) + tmp1;
	WRITE_LINE(9, 12864) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=396, taps=[396]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=1, taps=[1]
// Delay line 5: length=1, taps=[1]
// Delay line 6: length=63, taps=[63]
// Delay line 7: length=195, taps=[195]
// Delay line 8: length=13, taps=[13]
// Delay line 9: length=178, taps=[178]
// Delay line 10: length=114, taps=[114]
// Delay line 11: length=49, taps=[49]
// Delay line 12: length=3046, taps=[3046]
// Delay line 13: length=3046, taps=[3046]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_92(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(13, 16381, 3046) + LINE(12, 13333, 3046) / 2 + LINE(8, 9938, 13) / 2;
	WRITE_LINE(8, 9938) = -Acc;
	Acc = -Acc / 2 + LINE(8, 9938, 13) + LINE(7, 9923, 195) / 2;
	WRITE_LINE(7, 9923) = -Acc;
	Acc = -Acc / 2 + LINE(7, 9923, 195) + LINE(6, 9726, 63) / 2;
	WRITE_LINE(6, 9726) = -Acc;
	Acc = -Acc / 2 + LINE(6, 9726, 63);
	WRITE_LINE(1, 401) = Acc;
	Acc = LINE(13, 16381, 3046) + LINE(12, 13333, 3046) / 2 + LINE(11, 10285, 49) / 2;
	WRITE_LINE(11, 10285) = -Acc;
	Acc = -Acc / 2 + LINE(11, 10285, 49) + LINE(10, 10234, 114) / 2;
	WRITE_LINE(10, 10234) = -Acc;
	Acc = -Acc / 2 + LINE(10, 10234, 114) + LINE(9, 10118, 178) / 2;
	WRITE_LINE(9, 10118) = -Acc;
	Acc = -Acc / 2 + LINE(9, 10118, 178);
	tmp3 = Acc;
	Acc = LINE(5, 9661, 1) * 3 / 8;
	tmp1 = Acc;
	Acc = LINE(0, 0, 1) * 5 / 8 + tmp1;
	WRITE_LINE(5, 9661) = Acc;
	Acc = LINE(4, 9658, 1) * 15 / 16;
	tmp1 = Acc;
	Acc = LINE(5, 9661, 1) / 16 + tmp1;
	WRITE_LINE(4, 9658) = Acc;
	Acc = LINE(4, 9658, 1);
	tmp1 = -Acc;
	Acc = LINE(5, 9661, 1) + tmp1;
	WRITE_LINE(13, 16381) = Acc;
	Acc = LINE(13, 16381, 3046) / 2 + LINE(3, 9655, 1) / 2;
	WRITE_LINE(3, 9655) = Acc;
	Acc = LINE(2, 9652, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(3, 9655, 1) / 8 + tmp1;
	WRITE_LINE(2, 9652) = Acc;
	Acc = LINE(2, 9652, 1);
	tmp1 = -Acc;
	Acc = LINE(3, 9655, 1) * 3 / 2 + tmp1 * 3 / 2;
	WRITE_LINE(12, 13333) = Acc;
	*out_left = LINE(1, 401, 396);
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=1, taps=[1]
// Delay line 5: length=63, taps=[63]
// Delay line 6: length=195, taps=[195]
// Delay line 7: length=41, taps=[41]
// Delay line 8: length=178, taps=[178]
// Delay line 9: length=114, taps=[114]
// Delay line 10: length=49, taps=[49]
// Delay line 11: length=2695, taps=[2695]
// Delay line 12: length=2695, taps=[2695]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_93(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(12, 16381, 2695) + LINE(11, 13684, 2695) + LINE(7, 10640, 41) / 2;
	WRITE_LINE(7, 10640) = -Acc;
	Acc = -Acc / 2 + LINE(7, 10640, 41) + LINE(6, 10597, 195) / 2;
	WRITE_LINE(6, 10597) = -Acc;
	Acc = -Acc / 2 + LINE(6, 10597, 195) + LINE(5, 10400, 63) / 2;
	WRITE_LINE(5, 10400) = -Acc;
	Acc = -Acc / 2 + LINE(5, 10400, 63);
	WRITE_LINE(2, 6) = Acc;
	Acc = LINE(12, 16381, 2695) + LINE(11, 13684, 2695) + LINE(10, 10987, 49) / 2;
	WRITE_LINE(10, 10987) = -Acc;
	Acc = -Acc / 2 + LINE(10, 10987, 49) + LINE(9, 10936, 114) / 2;
	WRITE_LINE(9, 10936) = -Acc;
	Acc = -Acc / 2 + LINE(9, 10936, 114) + LINE(8, 10820, 178) / 2;
	WRITE_LINE(8, 10820) = -Acc;
	Acc = -Acc / 2 + LINE(8, 10820, 178);
	WRITE_LINE(1, 4) = Acc;
	Acc = LINE(4, 10335, 1) * 3 / 8;
	tmp1 = Acc;
	Acc = LINE(0, 0, 1) * 5 / 8 + tmp1;
	WRITE_LINE(4, 10335) = Acc;
	Acc = LINE(4, 10335, 1);
	WRITE_LINE(12, 16381) = Acc;
	Acc = LINE(3, 10332, 1) / 2 + LINE(12, 16381, 2695) / 2;
	WRITE_LINE(3, 10332) = Acc;
	Acc = LINE(3, 10332, 1);
	WRITE_LINE(11, 13684) = Acc;
	*out_left = LINE(2, 6, 1);
	*out_right = LINE(1, 4, 1);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=4688, taps=[2343, 4688]
// Delay line 1: length=546, taps=[546]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_94(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 2343) * 3 / 4 + LINE(0, 0, 4688) * 3 / 4;
	tmp3 = Acc;
	Acc = LINE(0, 0, 2343) * 3 / 4 + LINE(0, 0, 4688) * 3 / 4;
	WRITE_LINE(1, 551) = Acc;
	*out_left = LINE(1, 551, 546);
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=16378, taps=[5460, 10919, 16378]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_95(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 5460) + LINE(0, 0, 16378) / 2;
	tmp5 = Acc;
	Acc = tmp5 * 21 / 32;
	tmp5 = Acc;
	Acc = LINE(0, 0, 10919) + LINE(0, 0, 16378) / 2;
	tmp3 = Acc;
	Acc = tmp3 * 21 / 32;
	tmp3 = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=12739, taps=[4247, 8493, 12739]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_96(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 4247) + LINE(0, 0, 12739) / 2;
	tmp5 = Acc;
	Acc = tmp5 * 21 / 32;
	tmp5 = Acc;
	Acc = LINE(0, 0, 8493) + LINE(0, 0, 12739) / 2;
	tmp3 = Acc;
	Acc = tmp3 * 21 / 32;
	tmp3 = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=63, taps=[63]
// Delay line 5: length=195, taps=[195]
// Delay line 6: length=41, taps=[41]
// Delay line 7: length=178, taps=[178]
// Delay line 8: length=114, taps=[114]
// Delay line 9: length=49, taps=[49]
// Delay line 10: length=4244, taps=[4244]
// Delay line 11: length=4244, taps=[4244]
// Delay line 12: length=4244, taps=[4244]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_97(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(12, 16381, 4244) / 2 + LINE(11, 12135, 4244) / 2 + LINE(10, 7889, 4244) / 2 + LINE(6, 3296, 41) / 2;
	WRITE_LINE(6, 3296) = -Acc;
	Acc = -Acc / 2 + LINE(6, 3296, 41) + LINE(5, 3253, 195) / 2;
	WRITE_LINE(5, 3253) = -Acc;
	Acc = -Acc / 2 + LINE(5, 3253, 195) + LINE(4, 3056, 63) / 2;
	WRITE_LINE(4, 3056) = -Acc;
	Acc = -Acc / 2 + LINE(4, 3056, 63);
	tmp5 = Acc;
	Acc = LINE(10, 7889, 4244) / 2 + LINE(11, 12135, 4244) / 2 + LINE(12, 16381, 4244) / 2 + LINE(9, 3643, 49) / 2;
	WRITE_LINE(9, 3643) = -Acc;
	Acc = -Acc / 2 + LINE(9, 3643, 49) + LINE(8, 3592, 114) / 2;
	WRITE_LINE(8, 3592) = -Acc;
	Acc = -Acc / 2 + LINE(8, 3592, 114) + LINE(7, 3476, 178) / 2;
	WRITE_LINE(7, 3476) = -Acc;
	Acc = -Acc / 2 + LINE(7, 3476, 178);
	tmp3 = Acc;
	Acc = LINE(1, 2985, 1) * 3 / 8;
	tmp1 = Acc;
	Acc = LINE(0, 0, 1) * 5 / 8 + tmp1;
	WRITE_LINE(1, 2985) = Acc;
	Acc = Acc * 3 / 2;
	WRITE_LINE(10, 7889) = Acc;
	Acc = LINE(2, 2988, 1) / 2 + LINE(10, 7889, 4244) / 2;
	WRITE_LINE(2, 2988) = Acc;
	Acc = LINE(2, 2988, 1);
	WRITE_LINE(11, 12135) = Acc;
	Acc = LINE(3, 2991, 1) / 2 + LINE(11, 12135, 4244) / 2;
	WRITE_LINE(3, 2991) = Acc;
	Acc = WRITE_LINE(3, 2991);
	WRITE_LINE(12, 16381) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=1, taps=[1]
// Delay line 5: length=1, taps=[1]
// Delay line 6: length=1, taps=[1]
// Delay line 7: length=63, taps=[63]
// Delay line 8: length=195, taps=[195]
// Delay line 9: length=41, taps=[41]
// Delay line 10: length=178, taps=[178]
// Delay line 11: length=114, taps=[114]
// Delay line 12: length=49, taps=[49]
// Delay line 13: length=3276, taps=[3276]
// Delay line 14: length=3276, taps=[3276]
// Delay line 15: length=3276, taps=[3276]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_98(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(15, 16381, 3276) / 2 + LINE(14, 13103, 3276) / 2 + LINE(13, 9825, 3276) / 2 + LINE(9, 6200, 41) / 2;
	WRITE_LINE(9, 6200) = -Acc;
	Acc = -Acc / 2 + LINE(9, 6200, 41) + LINE(8, 6157, 195) / 2;
	WRITE_LINE(8, 6157) = -Acc;
	Acc = -Acc / 2 + LINE(8, 6157, 195) + LINE(7, 5960, 63) / 2;
	WRITE_LINE(7, 5960) = -Acc;
	Acc = -Acc / 2 + LINE(7, 5960, 63);
	tmp5 = Acc;
	Acc = LINE(15, 16381, 3276) / 2 + LINE(14, 13103, 3276) / 2 + LINE(13, 9825, 3276) / 2 + LINE(12, 6547, 49) / 2;
	WRITE_LINE(12, 6547) = -Acc;
	Acc = -Acc / 2 + LINE(12, 6547, 49) + LINE(11, 6496, 114) / 2;
	WRITE_LINE(11, 6496) = -Acc;
	Acc = -Acc / 2 + LINE(11, 6496, 114) + LINE(10, 6380, 178) / 2;
	WRITE_LINE(10, 6380) = -Acc;
	Acc = -Acc / 2 + LINE(10, 6380, 178);
	tmp3 = Acc;
	Acc = LINE(6, 5895, 1) * 3 / 8;
	tmp1 = Acc;
	Acc = LINE(0, 0, 1) * 5 / 8 + tmp1;
	WRITE_LINE(6, 5895) = Acc;
	Acc = LINE(5, 5892, 1) * 15 / 16;
	tmp1 = Acc;
	Acc = LINE(6, 5895, 1) / 16 + tmp1;
	WRITE_LINE(5, 5892) = Acc;
	Acc = LINE(5, 5892, 1);
	tmp1 = -Acc;
	Acc = LINE(6, 5895, 1) + tmp1;
	WRITE_LINE(15, 16381) = Acc;
	Acc = LINE(4, 5889, 1) / 2 + LINE(15, 16381, 3276) / 2;
	WRITE_LINE(4, 5889) = Acc;
	Acc = LINE(3, 5886, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(4, 5889, 1) / 8 + tmp1;
	WRITE_LINE(3, 5886) = Acc;
	Acc = LINE(3, 5886, 1);
	tmp1 = -Acc;
	Acc = LINE(4, 5889, 1) * 9 / 4 + tmp1 * 9 / 4;
	WRITE_LINE(14, 13103) = Acc;
	Acc = LINE(2, 5883, 1) / 2 + LINE(14, 13103, 3276) / 2;
	WRITE_LINE(2, 5883) = Acc;
	*out_left = tmp5;
	Acc = LINE(1, 5880, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(2, 5883, 1) / 8 + tmp1;
	WRITE_LINE(1, 5880) = Acc;
	Acc = LINE(1, 5880, 1);
	tmp1 = -Acc;
	*out_right = tmp3;
	Acc = LINE(2, 5883, 1) * 9 / 4 + tmp1 * 9 / 4;
	WRITE_LINE(13, 9825) = Acc;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=63, taps=[63]
// Delay line 5: length=195, taps=[195]
// Delay line 6: length=41, taps=[41]
// Delay line 7: length=178, taps=[178]
// Delay line 8: length=114, taps=[114]
// Delay line 9: length=49, taps=[49]
// Delay line 10: length=2808, taps=[2808]
// Delay line 11: length=2808, taps=[2808]
// Delay line 12: length=2808, taps=[2808]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_99(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 10761, 2808) / 2 + LINE(11, 13571, 2808) / 2 + LINE(12, 16381, 2808) / 2 + LINE(6, 7604, 41) / 2;
	WRITE_LINE(6, 7604) = -Acc;
	Acc = -Acc / 2 + LINE(6, 7604, 41) + LINE(5, 7561, 195) / 2;
	WRITE_LINE(5, 7561) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7561, 195) + LINE(4, 7364, 63) / 2;
	WRITE_LINE(4, 7364) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7364, 63);
	tmp5 = Acc;
	Acc = tmp5 * 21 / 32;
	tmp5 = Acc;
	Acc = LINE(12, 16381, 2808) / 2 + LINE(11, 13571, 2808) / 2 + LINE(10, 10761, 2808) / 2 + LINE(9, 7951, 49) / 2;
	WRITE_LINE(9, 7951) = -Acc;
	Acc = -Acc / 2 + LINE(9, 7951, 49) + LINE(8, 7900, 114) / 2;
	WRITE_LINE(8, 7900) = -Acc;
	Acc = -Acc / 2 + LINE(8, 7900, 114) + LINE(7, 7784, 178) / 2;
	WRITE_LINE(7, 7784) = -Acc;
	Acc = -Acc / 2 + LINE(7, 7784, 178);
	tmp3 = Acc;
	Acc = tmp3 * 21 / 32;
	tmp3 = Acc;
	Acc = LINE(3, 7299, 1) * 15 / 16;
	tmp1 = Acc;
	Acc = LINE(0, 0, 1) / 16 + tmp1;
	WRITE_LINE(3, 7299) = Acc;
	Acc = LINE(3, 7299, 1);
	tmp1 = -Acc;
	Acc = LINE(0, 0, 1) * 3 / 2 + tmp1 * 3 / 2;
	WRITE_LINE(12, 16381) = Acc;
	Acc = LINE(2, 7296, 1) * 15 / 16;
	tmp1 = Acc;
	Acc = Acc * -3 / 16 + LINE(12, 16381, 2808) / 8 + tmp1;
	WRITE_LINE(2, 7296) = Acc;
	Acc = LINE(2, 7296, 1);
	tmp1 = -Acc;
	Acc = LINE(12, 16381, 2808) + tmp1;
	WRITE_LINE(11, 13571) = Acc;
	*out_left = tmp5;
	Acc = LINE(1, 7293, 1) * 13 / 16;
	tmp1 = Acc;
	Acc = LINE(11, 13571, 2808) * 3 / 16 + tmp1;
	WRITE_LINE(1, 7293) = Acc;
	Acc = LINE(1, 7293, 1);
	tmp1 = -Acc;
	*out_right = tmp3;
	Acc = LINE(11, 13571, 2808) * 3 / 2 + tmp1 * 3 / 2;
	WRITE_LINE(10, 10761) = Acc;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=7027, taps=[2343, 4685, 7027]
// Delay line 1: length=63, taps=[63]
// Delay line 2: length=195, taps=[195]
// Delay line 3: length=41, taps=[41]
// Delay line 4: length=178, taps=[178]
// Delay line 5: length=114, taps=[114]
// Delay line 6: length=49, taps=[49]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_100(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 7027) / 2 + LINE(0, 0, 4685) / 2 + LINE(0, 0, 2343) / 2 + LINE(3, 9008, 41) / 2;
	WRITE_LINE(3, 9008) = -Acc;
	Acc = -Acc / 2 + LINE(3, 9008, 41) + LINE(2, 8965, 195) / 2;
	WRITE_LINE(2, 8965) = -Acc;
	Acc = -Acc / 2 + LINE(2, 8965, 195) + LINE(1, 8768, 63) / 2;
	WRITE_LINE(1, 8768) = -Acc;
	Acc = -Acc / 2 + LINE(1, 8768, 63);
	tmp5 = Acc;
	Acc = tmp5 * 21 / 32;
	tmp5 = Acc;
	Acc = LINE(0, 0, 2343) / 2 + LINE(0, 0, 4685) / 2 + LINE(0, 0, 7027) / 2 + LINE(6, 9355, 49) / 2;
	WRITE_LINE(6, 9355) = -Acc;
	Acc = -Acc / 2 + LINE(6, 9355, 49) + LINE(5, 9304, 114) / 2;
	WRITE_LINE(5, 9304) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9304, 114) + LINE(4, 9188, 178) / 2;
	WRITE_LINE(4, 9188) = -Acc;
	Acc = -Acc / 2 + LINE(4, 9188, 178);
	tmp3 = Acc;
	Acc = tmp3 * 21 / 32;
	tmp3 = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=2, taps=[2]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=14000, taps=[14000]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_101(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 16380, 14000);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(2, 16380, 14000);
	tmp5 = Acc;
	Acc = LINE(0, 0, 2) + LINE(2, 16380, 14000) / 2;
	WRITE_LINE(2, 16380) = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=63, taps=[63]
// Delay line 1: length=195, taps=[195]
// Delay line 2: length=41, taps=[41]
// Delay line 3: length=178, taps=[178]
// Delay line 4: length=114, taps=[114]
// Delay line 5: length=49, taps=[49]
// Delay line 6: length=1, taps=[1]
// Delay line 7: length=8171, taps=[8171]
// Delay line 8: length=0, taps=[0]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_102(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp0, tmp1, tmp3, tmp5;
	Acc = LINE(7, 16380, 8171) / 2 + LINE(5, 8201, 49) / 2;
	WRITE_LINE(5, 8201) = -Acc;
	Acc = -Acc / 2 + LINE(5, 8201, 49) + LINE(4, 8150, 114) / 2;
	WRITE_LINE(4, 8150) = -Acc;
	Acc = -Acc / 2 + LINE(4, 8150, 114) + LINE(3, 8034, 178) / 2;
	WRITE_LINE(3, 8034) = -Acc;
	Acc = -Acc / 2 + LINE(3, 8034, 178);
	tmp3 = Acc;
	Acc = LINE(7, 16380, 8171) / 2 + LINE(2, 7854, 41) / 2;
	WRITE_LINE(2, 7854) = -Acc;
	Acc = -Acc / 2 + LINE(2, 7854, 41) + LINE(1, 7811, 195) / 2;
	WRITE_LINE(1, 7811) = -Acc;
	Acc = -Acc / 2 + LINE(1, 7811, 195) + LINE(0, 7614, 63) / 2;
	WRITE_LINE(0, 7614) = -Acc;
	Acc = -Acc / 2 + LINE(0, 7614, 63);
	tmp5 = Acc;
	Acc = LINE(7, 16380, 8171) / 2 + LINE(8, 16382, 0) * 3 / 2;
	LINE(8, 16382, 0) = Acc;
	Acc = LINE(8, 16382, 0) / 2;
	WRITE_LINE(6, 8207) = Acc;
	Acc = LINE(6, 8207, 1);
	tmp1 = -Acc;
	Acc = LINE(8, 16382, 0) + tmp1;
	WRITE_LINE(7, 16380) = Acc;
	Acc = WRITE_LINE(7, 16380) * 3 / 4;
	WRITE_LINE(7, 16380) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=7, taps=[1, 6, 7]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=63, taps=[63]
// Delay line 3: length=195, taps=[195]
// Delay line 4: length=41, taps=[41]
// Delay line 5: length=178, taps=[178]
// Delay line 6: length=114, taps=[114]
// Delay line 7: length=49, taps=[49]
// Delay line 8: length=1, taps=[1]
// Delay line 9: length=1, taps=[1]
// Delay line 10: length=7020, taps=[7020]
// Delay line 11: length=0, taps=[0]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_103(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp0, tmp1, tmp2, tmp3, tmp5;
	Acc = LINE(10, 16380, 7020) / 2 + LINE(7, 9352, 49) / 2;
	WRITE_LINE(7, 9352) = -Acc;
	Acc = -Acc / 2 + LINE(7, 9352, 49) + LINE(6, 9301, 114) / 2;
	WRITE_LINE(6, 9301) = -Acc;
	Acc = -Acc / 2 + LINE(6, 9301, 114) + LINE(5, 9185, 178) / 2;
	WRITE_LINE(5, 9185) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9185, 178);
	tmp3 = Acc;
	Acc = LINE(10, 16380, 7020) / 2 + LINE(4, 9005, 41) / 2;
	WRITE_LINE(4, 9005) = -Acc;
	Acc = -Acc / 2 + LINE(4, 9005, 41) + LINE(3, 8962, 195) / 2;
	WRITE_LINE(3, 8962) = -Acc;
	Acc = -Acc / 2 + LINE(3, 8962, 195) + LINE(2, 8765, 63) / 2;
	WRITE_LINE(2, 8765) = -Acc;
	Acc = -Acc / 2 + LINE(2, 8765, 63);
	tmp5 = Acc;
	Acc = -LINE(11, 16382, 0) + -LINE(10, 16380, 7020) / 4;
	LINE(11, 16382, 0) = Acc;
	Acc = LINE(11, 16382, 0) / 2 + LINE(9, 9358, 1) / 2;
	WRITE_LINE(9, 9358) = Acc;
	Acc = LINE(8, 9355, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(9, 9358, 1) / 8 + tmp1;
	WRITE_LINE(8, 9355) = Acc;
	Acc = LINE(8, 9355, 1);
	tmp1 = -Acc;
	Acc = LINE(9, 9358, 1) * 3 / 2 + tmp1 * 3 / 2;
	WRITE_LINE(10, 16380) = Acc;
	Acc = LINE(0, 8688, 6) / 2 + LINE(1, 8691, 1) / 2;
	WRITE_LINE(1, 8691) = Acc;
	Acc = LINE(0, 8688, 1) * 7 / 8;
	tmp1 = Acc;
	Acc = LINE(0, 8688, 7) / 8 + tmp1;
	WRITE_LINE(0, 8688) = Acc;
	Acc = WRITE_LINE(10, 16380) * 11 / 8;
	WRITE_LINE(10, 16380) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=121, taps=[121]
// Delay line 1: length=187, taps=[187]
// Delay line 2: length=45, taps=[45]
// Delay line 3: length=139, taps=[139]
// Delay line 4: length=117, taps=[117]
// Delay line 5: length=59, taps=[59]
// Delay line 6: length=1, taps=[1]
// Delay line 7: length=5002, taps=[0, 5002]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_104(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp0, tmp1, tmp2, tmp3, tmp5;
	Acc = LINE(7, 16382, 5002) / 2 + LINE(5, 11375, 59) / 2;
	WRITE_LINE(5, 11375) = -Acc;
	Acc = -Acc / 2 + LINE(5, 11375, 59) + LINE(4, 11314, 117) / 2;
	WRITE_LINE(4, 11314) = -Acc;
	Acc = -Acc / 2 + LINE(4, 11314, 117) + LINE(3, 11195, 139) / 2;
	WRITE_LINE(3, 11195) = -Acc;
	Acc = -Acc / 2 + LINE(3, 11195, 139);
	tmp3 = Acc;
	Acc = LINE(7, 16382, 5002) / 2 + LINE(2, 11054, 45) / 2;
	WRITE_LINE(2, 11054) = -Acc;
	Acc = -Acc / 2 + LINE(2, 11054, 45) + LINE(1, 11007, 187) / 2;
	WRITE_LINE(1, 11007) = -Acc;
	Acc = -Acc / 2 + LINE(1, 11007, 187) + LINE(0, 10818, 121) / 2;
	WRITE_LINE(0, 10818) = -Acc;
	Acc = -Acc / 2 + LINE(0, 10818, 121);
	tmp5 = Acc;
	Acc = LINE(7, 16382, 0) * 9 / 8 + LINE(6, 11378, 1) * 3 / 4;
	LINE(7, 16382, 0) = Acc;
	Acc = LINE(6, 11378, 1) / 2 + LINE(7, 16382, 5002) / 2;
	WRITE_LINE(6, 11378) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=2, taps=[2]
// Delay line 1: length=4500, taps=[4500]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_105(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 16380, 4500) / 2;
	tmp3 = Acc;
	Acc = LINE(1, 16380, 4500) / 2;
	tmp5 = Acc;
	Acc = -LINE(1, 16380, 4500) / 4 + LINE(0, 0, 2);
	WRITE_LINE(1, 16380) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=2, taps=[2]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=3000, taps=[3000]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_106(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 16380, 3000);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(2, 16380, 3000);
	tmp5 = Acc;
	Acc = LINE(0, 0, 2) + LINE(2, 16380, 3000) / 2;
	WRITE_LINE(2, 16380) = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=588, taps=[588]
// Delay line 1: length=2, taps=[2]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_107(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 588);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 588);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=940, taps=[940]
// Delay line 1: length=2, taps=[2]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_108(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 940);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 940);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1409, taps=[1409]
// Delay line 1: length=2, taps=[2]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_109(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 1409);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 1409);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1760, taps=[1760]
// Delay line 1: length=2, taps=[2]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_110(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 1760);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 1760);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=2346, taps=[2346]
// Delay line 1: length=2, taps=[2]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_111(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 2346);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 2346);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1000, taps=[163, 233, 412, 534, 761, 875, 1000]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=233, taps=[233]
// Delay line 5: length=181, taps=[181]
// Delay line 6: length=32, taps=[32]
// Delay line 7: length=273, taps=[273]
// Delay line 8: length=153, taps=[153]
// Delay line 9: length=21, taps=[21]
// Delay line 10: length=8094, taps=[64, 118, 232, 433, 554, 741, 861, 1045, 1148, 1255, 1442, 1578, 1720, 1872, 2035, 2120, 2266, 2450, 2568, 2724, 2888, 3033, 3151, 3256, 3491, 3555, 3618, 3799, 3920, 4045, 4209, 4338, 4550, 4626, 4733, 4957, 5018, 5260, 5318, 5494, 5656, 5727, 5966, 6017, 6153, 6363, 6418, 6656, 6726, 6864, 7091, 7138, 7378, 7461, 7514, 7792, 7848, 8094]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_112(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(9, 2298, 21) / 2;
	WRITE_LINE(9, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(9, 2298, 21) + LINE(8, 2275, 153) / 2;
	WRITE_LINE(8, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2275, 153) + LINE(7, 2120, 273) / 2;
	WRITE_LINE(7, 2120) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2120, 273);
	tmp3 = Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(6, 1845, 32) / 2;
	WRITE_LINE(6, 1845) = -Acc;
	Acc = -Acc / 2 + LINE(6, 1845, 32) + LINE(5, 1811, 181) / 2;
	WRITE_LINE(5, 1811) = -Acc;
	Acc = -Acc / 2 + LINE(5, 1811, 181) + LINE(4, 1628, 233) / 2;
	WRITE_LINE(4, 1628) = -Acc;
	Acc = -Acc / 2 + LINE(4, 1628, 233);
	tmp5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(10, 15383, 64) / 2 + LINE(10, 15383, 118) / 2 + LINE(10, 15383, 232) / 2 + LINE(10, 15383, 433) / 2 + LINE(10, 15383, 554) / 2 + LINE(10, 15383, 741) / 2 + LINE(10, 15383, 861) / 2 + LINE(10, 15383, 1045) / 2 + LINE(10, 15383, 1148) / 2 + LINE(10, 15383, 1255) / 2 + LINE(10, 15383, 1442) / 2 + LINE(10, 15383, 1578) / 2 + LINE(10, 15383, 1720) / 2 + LINE(10, 15383, 1872) / 2 + LINE(10, 15383, 2035) / 2 + LINE(10, 15383, 2120) / 2 + LINE(10, 15383, 2266) / 2 + LINE(10, 15383, 2450) / 2 + LINE(10, 15383, 2568) / 2 + LINE(10, 15383, 2724) / 2 + LINE(10, 15383, 2888) / 2 + LINE(10, 15383, 3033) / 2 + LINE(10, 15383, 3151) / 2 + LINE(10, 15383, 3256) / 2 + LINE(10, 15383, 3491) / 2 + LINE(10, 15383, 3555) / 2;
	WRITE_LINE(1, 11) = Acc;
	*out_left = tmp5;
	Acc = -LINE(10, 15383, 8094) / 16 + -LINE(10, 15383, 7848) / 16 + -LINE(10, 15383, 7792) / 16 + -LINE(10, 15383, 7514) / 16 + -LINE(10, 15383, 7461) / 16 + -LINE(10, 15383, 7378) / 16 + -LINE(10, 15383, 7138) / 16 + -LINE(10, 15383, 7091) / 16 + LINE(10, 15383, 6864) / 8 + LINE(10, 15383, 6726) / 8 + LINE(10, 15383, 6656) / 8 + LINE(10, 15383, 6418) / 8 + LINE(10, 15383, 6363) / 8 + LINE(10, 15383, 6153) / 8 + LINE(10, 15383, 6017) / 8 + LINE(10, 15383, 5966) / 8 + -LINE(10, 15383, 5727) / 4 + -LINE(10, 15383, 5656) / 4 + -LINE(10, 15383, 5494) / 4 + -LINE(10, 15383, 5318) / 4 + -LINE(10, 15383, 5260) / 4 + -LINE(10, 15383, 5018) / 4 + -LINE(10, 15383, 4957) / 4 + -LINE(10, 15383, 4733) / 4 + LINE(10, 15383, 4626) / 2 + LINE(10, 15383, 4550) / 2 + LINE(10, 15383, 4338) / 2 + LINE(10, 15383, 4209) / 2 + LINE(10, 15383, 4045) / 2 + LINE(10, 15383, 3920) / 2 + LINE(10, 15383, 3799) / 2 + LINE(10, 15383, 3618) / 2 + LINE(3, 1393, 1) / 2;
	WRITE_LINE(3, 1393) = Acc;
	Acc = -LINE(3, 1393, 1) / 4 + WRITE_LINE(1, 11);
	WRITE_LINE(1, 11) = Acc;
	Acc = LINE(0, 0, 1000) / 2 + LINE(2, 1390, 1) / 2;
	WRITE_LINE(2, 1390) = Acc;
	Acc = LINE(2, 1390, 1);
	WRITE_LINE(10, 15383) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1298, taps=[1298]
// Delay line 4: length=1017, taps=[151, 539, 1017]
// Delay line 5: length=1016, taps=[1016]
// Delay line 6: length=912, taps=[912]
// Delay line 7: length=1320, taps=[1320]
// Delay line 8: length=1441, taps=[167, 696, 1441]
// Delay line 9: length=1121, taps=[1121]
// Delay line 10: length=845, taps=[64, 503, 845]
// Delay line 11: length=467, taps=[467]
// Delay line 12: length=321, taps=[172, 321]
// Delay line 13: length=183, taps=[24, 183]
// Delay line 14: length=89, taps=[89]
// Delay line 15: length=58, taps=[58]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_113(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp11, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 15253, 64) / 2 + LINE(8, 13283, 696) / 2 + LINE(4, 8586, 539) / 2 + LINE(13, 16230, 24) / 2;
	tmp5 = Acc;
	Acc = LINE(10, 15253, 503) / 2 + LINE(8, 13283, 167) / 2 + LINE(4, 8586, 151) / 2 + LINE(12, 16045, 172) / 2;
	tmp3 = Acc;
	Acc = LINE(15, 16381, 58) * 5 / 8 + LINE(0, 0, 1) * 3 / 2;
	WRITE_LINE(15, 16381) = -Acc;
	Acc = LINE(14, 16321, 89) * 5 / 8 + WRITE_LINE(15, 16381) * 5 / 8 + LINE(15, 16381, 58);
	WRITE_LINE(14, 16321) = -Acc;
	Acc = LINE(13, 16230, 183) * 5 / 8 + WRITE_LINE(14, 16321) * 5 / 8 + LINE(14, 16321, 89);
	WRITE_LINE(13, 16230) = -Acc;
	Acc = LINE(12, 16045, 321) * 5 / 8 + WRITE_LINE(13, 16230) * 5 / 8 + LINE(13, 16230, 183);
	WRITE_LINE(12, 16045) = -Acc;
	Acc = LINE(11, 15722, 467) * 5 / 8 + WRITE_LINE(12, 16045) * 5 / 8 + LINE(12, 16045, 321);
	WRITE_LINE(11, 15722) = -Acc;
	Acc = -Acc / 8 + WRITE_LINE(11, 15722) / 2 + LINE(11, 15722, 467);
	tmp11 = Acc;
	Acc = LINE(10, 15253, 845) * 3 / 4 + LINE(9, 14406, 1121) / 2;
	WRITE_LINE(9, 14406) = -Acc;
	Acc = -Acc / 2 + LINE(9, 14406, 1121);
	WRITE_LINE(8, 13283) = Acc;
	Acc = LINE(8, 13283, 1441) * 3 / 4 + LINE(7, 11840, 1320) / 2;
	WRITE_LINE(7, 11840) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11840, 1320);
	tmp1 = Acc;
	Acc = LINE(2, 6264, 1) / 2 + tmp1 / 2;
	WRITE_LINE(2, 6264) = Acc;
	Acc = LINE(2, 6264, 1) + tmp11;
	WRITE_LINE(10, 15253) = Acc;
	Acc = LINE(6, 10518, 912) * 3 / 4 + LINE(5, 9604, 1016) / 2;
	WRITE_LINE(5, 9604) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9604, 1016);
	WRITE_LINE(4, 8586) = Acc;
	Acc = LINE(4, 8586, 1017) * 3 / 4 + LINE(3, 7567, 1298) / 2;
	WRITE_LINE(3, 7567) = -Acc;
	*out_left = tmp5;
	Acc = -Acc / 2 + LINE(3, 7567, 1298);
	tmp1 = Acc;
	Acc = LINE(1, 6261, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 6261) = Acc;
	Acc = LINE(1, 6261, 1) + tmp11;
	WRITE_LINE(6, 10518) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=1, taps=[1]
// Delay line 5: length=1, taps=[1]
// Delay line 6: length=249, taps=[249]
// Delay line 7: length=48, taps=[48]
// Delay line 8: length=21, taps=[21]
// Delay line 9: length=147, taps=[147]
// Delay line 10: length=55, taps=[55]
// Delay line 11: length=43, taps=[43]
// Delay line 12: length=2083, taps=[2083]
// Delay line 13: length=2001, taps=[2001]
// Delay line 14: length=1841, taps=[1841]
// Delay line 15: length=1563, taps=[1563]
// Delay line 16: length=1347, taps=[1347]
// Delay line 17: length=1100, taps=[1100]
// Delay line 18: length=999, taps=[999]
// Delay line 19: length=823, taps=[823]
// Delay line 20: length=555, taps=[555]
// Delay line 21: length=481, taps=[481]
// Delay line 22: length=339, taps=[339]
// Delay line 23: length=239, taps=[239]
// Delay line 24: length=116, taps=[116]
// Delay line 25: length=83, taps=[83]
// Delay line 26: length=13, taps=[13]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_114(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(4, 2190, 1) / 2;
	tmp3 = Acc;
	Acc = LINE(3, 2187, 1) / 2;
	tmp5 = Acc;
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
	WRITE_LINE(1, 11) = Acc;
	Acc = WRITE_LINE(1, 11) + LINE(9, 2666, 147) / 2;
	WRITE_LINE(9, 2666) = -Acc;
	Acc = -Acc / 2 + LINE(9, 2666, 147) + LINE(11, 2768, 43) / 2;
	WRITE_LINE(11, 2768) = -Acc;
	Acc = -Acc / 2 + LINE(11, 2768, 43) + LINE(10, 2723, 55) / 2;
	WRITE_LINE(10, 2723) = -Acc;
	Acc = -Acc / 2 + LINE(10, 2723, 55);
	WRITE_LINE(4, 2190) = Acc;
	Acc = WRITE_LINE(1, 11) + LINE(6, 2444, 249) / 2;
	WRITE_LINE(6, 2444) = -Acc;
	*out_left = tmp5;
	Acc = -Acc / 2 + LINE(6, 2444, 249) + LINE(7, 2494, 48) / 2;
	WRITE_LINE(7, 2494) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2494, 48) + LINE(8, 2517, 21) / 2;
	WRITE_LINE(8, 2517) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2517, 21);
	WRITE_LINE(3, 2187) = Acc;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=1, taps=[1]
// Delay line 4: length=2312, taps=[2312]
// Delay line 5: length=2157, taps=[41, 173, 342, 460, 595, 671, 780, 907, 1066, 1110, 1344, 1408, 1660, 1762, 1941, 2003, 2005, 2157]
// Delay line 6: length=2371, taps=[2371]
// Delay line 7: length=2110, taps=[105, 269, 414, 532, 637, 872, 890, 936, 1107, 1229, 1414, 1509, 1615, 1801, 1891, 1914, 2110]
// Delay line 8: length=1992, taps=[1992]
// Delay line 9: length=1624, taps=[21, 1010, 1065, 1119, 1233, 1434, 1555, 1624]
// Delay line 10: length=154, taps=[154]
// Delay line 11: length=234, taps=[234]
// Delay line 12: length=1620, taps=[1620]
// Delay line 13: length=968, taps=[968]
// Delay line 14: length=431, taps=[431]
// Delay line 15: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_115(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp7;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(9, 12641, 1065) * 3 / 64 + LINE(9, 12641, 1233) * 3 / 64 + LINE(9, 12641, 1555) * 3 / 64 + LINE(7, 9021, 269) * 3 / 64 + LINE(5, 4536, 2003) * -3 / 32 + LINE(7, 9021, 1891) * -3 / 32 + LINE(9, 12641, 21) * -3 / 32 + LINE(7, 9021, 532) * -3 / 32 + LINE(7, 9021, 872) * -3 / 32 + LINE(7, 9021, 1107) * -3 / 32 + LINE(7, 9021, 1414) * -3 / 32 + LINE(7, 9021, 1615) * -3 / 32 + LINE(7, 9021, 1914) * -3 / 32 + LINE(5, 4536, 173) * -3 / 32 + LINE(5, 4536, 460) * -3 / 32 + LINE(5, 4536, 780) * 3 / 16 + LINE(5, 4536, 1066) * 3 / 16 + LINE(5, 4536, 1344) * 3 / 16 + LINE(5, 4536, 1660) * 3 / 16 + LINE(5, 4536, 1941) * 3 / 16;
	WRITE_LINE(1, 4) = -Acc;
	Acc = -LINE(5, 4536, 2005) / 16 + -LINE(5, 4536, 1762) / 16 + -LINE(5, 4536, 1408) / 16 + -LINE(5, 4536, 1110) / 16 + LINE(5, 4536, 671) / 8 + LINE(7, 9021, 890) / 8 + LINE(9, 12641, 1010) / 8 + LINE(5, 4536, 907) / 8 + LINE(5, 4536, 595) / 8 + LINE(5, 4536, 342) / 8 + LINE(5, 4536, 41) / 8 + LINE(7, 9021, 1801) / 8 + LINE(7, 9021, 1509) / 8 + LINE(7, 9021, 1229) / 8 + LINE(7, 9021, 936) / 8 + -LINE(7, 9021, 637) / 4 + -LINE(7, 9021, 414) / 4 + -LINE(7, 9021, 105) / 4 + -LINE(9, 12641, 1434) / 4 + -LINE(9, 12641, 1119) / 4;
	WRITE_LINE(2, 6) = -Acc;
	Acc = LINE(0, 0, 1) * 81 / 32 + LINE(15, 16381, 321) / 2;
	WRITE_LINE(15, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(15, 16381, 321) + LINE(14, 16058, 431) / 2;
	WRITE_LINE(14, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16058, 431) + LINE(13, 15625, 968) / 2;
	WRITE_LINE(13, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(13, 15625, 968) + LINE(12, 14655, 1620) / 2;
	WRITE_LINE(12, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(12, 14655, 1620) + LINE(11, 13033, 234) / 2;
	WRITE_LINE(11, 13033) = -Acc;
	Acc = -Acc / 2 + LINE(11, 13033, 234) + LINE(10, 12797, 154) / 2;
	WRITE_LINE(10, 12797) = -Acc;
	Acc = -Acc / 2 + LINE(10, 12797, 154);
	tmp2 = Acc;
	Acc = LINE(9, 12641, 1624) + LINE(8, 11015, 1992) / 2;
	WRITE_LINE(8, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(8, 11015, 1992);
	WRITE_LINE(7, 9021) = Acc;
	Acc = LINE(7, 9021, 2110) * 15 / 16 + LINE(6, 6909, 2371) / 2;
	WRITE_LINE(6, 6909) = -Acc;
	*out_left = LINE(2, 6, 1);
	Acc = -Acc / 2 + LINE(6, 6909, 2371);
	WRITE_LINE(5, 4536) = Acc;
	Acc = LINE(5, 4536, 2157) / 2 + LINE(4, 2377, 2312) / 2;
	WRITE_LINE(4, 2377) = -Acc;
	Acc = Acc * -3 / 4 + LINE(4, 2377, 2312) * 3 / 2;
	tmp1 = Acc;
	Acc = LINE(3, 63, 1) / 4 + tmp1 / 2;
	WRITE_LINE(3, 63) = Acc;
	*out_right = LINE(1, 4, 1);
	Acc = WRITE_LINE(3, 63) + tmp2;
	WRITE_LINE(9, 12641) = Acc;
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
// Delay line 7: length=1892, taps=[1892]
// Delay line 8: length=1624, taps=[21, 801, 1624]
// Delay line 9: length=154, taps=[154]
// Delay line 10: length=234, taps=[234]
// Delay line 11: length=1620, taps=[1620]
// Delay line 12: length=968, taps=[968]
// Delay line 13: length=431, taps=[431]
// Delay line 14: length=321, taps=[321]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_116(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp2, tmp3, tmp5, tmp7, tmp9;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 12641, 21) / 2 + LINE(6, 9121, 1891) / 2 + LINE(4, 4636, 2003) / 2;
	tmp3 = Acc;
	Acc = LINE(8, 12641, 801) / 2 + LINE(6, 9121, 890) / 2 + LINE(4, 4636, 671) / 2;
	tmp5 = Acc;
	Acc = LINE(0, 0, 1) + LINE(14, 16381, 321) / 2;
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
	Acc = LINE(8, 12641, 1624) + LINE(7, 11015, 1892) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1892);
	WRITE_LINE(6, 9121) = Acc;
	Acc = LINE(6, 9121, 2110) * -27 / 32 + LINE(5, 7009, 2371) / 2;
	WRITE_LINE(5, 7009) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7009, 2371);
	WRITE_LINE(4, 4636) = Acc;
	Acc = LINE(4, 4636, 2157) * 9 / 8 + LINE(3, 2477, 2312) / 2;
	WRITE_LINE(3, 2477) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2477, 2312);
	tmp1 = Acc;
	Acc = LINE(1, 157, 1) / 2 + tmp1 / 2;
	WRITE_LINE(1, 157) = Acc;
	Acc = WRITE_LINE(1, 157) + tmp2;
	tmp7 = Acc;
	Acc = LINE(2, 163, 1) * 15 / 16;
	tmp9 = Acc;
	Acc = tmp7 / 16 + tmp9;
	WRITE_LINE(2, 163) = Acc;
	Acc = WRITE_LINE(2, 163);
	tmp9 = -Acc;
	Acc = tmp7 + tmp9;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=14000, taps=[1065, 1119, 1233, 1434, 1555, 1742, 1862, 2046, 2149, 2256, 2443, 2579, 2721, 2873, 3036, 3121, 3267, 3451, 3569, 3725, 3889, 4034, 4152, 4257, 4492, 4556, 4727, 4849, 5034, 5129, 5235, 5421, 5534, 5759, 5837, 6035, 6159, 6223, 6446, 6534, 6782, 6859, 7039, 7126, 7221, 7439, 7534, 7736, 7891, 8034, 8146, 8278, 8447, 8565, 8700, 8885, 9012, 9171, 9215, 9449, 9513, 9765, 9867, 10046, 10110, 10285, 10428, 10578, 10734, 10815, 11023, 11185, 11254, 11479, 11546, 11715, 11847, 12074, 12112, 12279, 12415, 12516, 12746, 12815, 13046, 13217, 13378, 13534, 14000]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=233, taps=[233]
// Delay line 3: length=175, taps=[175]
// Delay line 4: length=32, taps=[32]
// Delay line 5: length=273, taps=[273]
// Delay line 6: length=153, taps=[153]
// Delay line 7: length=21, taps=[21]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_117(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(7, 2298, 21) / 2;
	WRITE_LINE(7, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2298, 21) + LINE(6, 2275, 153) / 2;
	WRITE_LINE(6, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2275, 153) + LINE(5, 2120, 273) / 2;
	WRITE_LINE(5, 2120) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2120, 273) + LINE(0, 0, 14000);
	tmp3 = Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(4, 1845, 32) / 2;
	WRITE_LINE(4, 1845) = -Acc;
	Acc = -Acc / 2 + LINE(4, 1845, 32) + LINE(3, 1811, 175) / 2;
	WRITE_LINE(3, 1811) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1811, 175) + LINE(2, 1634, 233) / 2;
	WRITE_LINE(2, 1634) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1634, 233) + LINE(0, 0, 14000);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
	Acc = Acc * 3 / 32 + LINE(0, 0, 1065) / 32 + LINE(0, 0, 1119) / 32 + LINE(0, 0, 1233) / 32 + LINE(0, 0, 1434) / 32 + LINE(0, 0, 1555) / 32 + LINE(0, 0, 1742) / 32 + LINE(0, 0, 1862) / 32 + LINE(0, 0, 2046) / 32 + LINE(0, 0, 3569) / 32 + LINE(0, 0, 2256) / 32 + LINE(0, 0, 2443) / 32 + LINE(0, 0, 3121) / 32 + LINE(0, 0, 2721) / 32 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 3036) / 16 + -LINE(0, 0, 2579) / 16 + -LINE(0, 0, 3267) / 16 + -LINE(0, 0, 3451) / 16 + -LINE(0, 0, 2149) / 16 + -LINE(0, 0, 3725) / 16 + -LINE(0, 0, 3889) / 16 + -LINE(0, 0, 4034) / 16 + -LINE(0, 0, 4152) / 16 + -LINE(0, 0, 4257) / 16 + -LINE(0, 0, 4492) / 16 + -LINE(0, 0, 4556) / 16 + -LINE(0, 0, 4727) / 16 + -LINE(0, 0, 4849) / 16 + -LINE(0, 0, 6035) / 16 + -LINE(0, 0, 5129) / 16 + -LINE(0, 0, 5235) / 16 + -LINE(0, 0, 6223) / 16 + -LINE(0, 0, 5534) / 16 + LINE(0, 0, 5759) / 8 + LINE(0, 0, 5837) / 8 + LINE(0, 0, 5034) / 8 + LINE(0, 0, 6159) / 8 + LINE(0, 0, 5421) / 8 + LINE(0, 0, 6446) / 8 + LINE(0, 0, 6534) / 8 + LINE(0, 0, 6782) / 8 + LINE(0, 0, 6859) / 8 + LINE(0, 0, 7039) / 8 + LINE(0, 0, 7126) / 8 + LINE(0, 0, 7221) / 8 + LINE(0, 0, 8565) / 8 + LINE(0, 0, 7534) / 8 + LINE(0, 0, 7736) / 8 + LINE(0, 0, 7891) / 8 + LINE(0, 0, 9215) / 8 + LINE(0, 0, 8146) / 8 + LINE(0, 0, 8278) / 8 + -LINE(0, 0, 8447) / 4 + -LINE(0, 0, 7439) / 4 + -LINE(0, 0, 8700) / 4 + -LINE(0, 0, 8885) / 4 + -LINE(0, 0, 9012) / 4 + -LINE(0, 0, 9171) / 4 + -LINE(0, 0, 8034) / 4 + -LINE(0, 0, 9449) / 4 + -LINE(0, 0, 9513) / 4 + -LINE(0, 0, 9765) / 4 + -LINE(0, 0, 9867) / 4 + -LINE(0, 0, 10046) / 4 + -LINE(0, 0, 10110) / 4 + -LINE(0, 0, 10285) / 4 + -LINE(0, 0, 12074) / 4 + -LINE(0, 0, 10578) / 4 + -LINE(0, 0, 10734) / 4 + -LINE(0, 0, 11715) / 4 + -LINE(0, 0, 11023) / 4 + -LINE(0, 0, 11185) / 4 + LINE(0, 0, 11254) / 2 + LINE(0, 0, 11479) / 2 + LINE(0, 0, 11546) / 2 + LINE(0, 0, 10815) / 2 + LINE(0, 0, 11847) / 2 + LINE(0, 0, 10428) / 2 + LINE(0, 0, 12112) / 2 + LINE(0, 0, 12279) / 2 + LINE(0, 0, 12415) / 2 + LINE(0, 0, 12516) / 2 + LINE(0, 0, 12746) / 2 + LINE(0, 0, 12815) / 2 + LINE(0, 0, 13046) / 2 + LINE(0, 0, 13217) / 2 + LINE(0, 0, 13378) / 2 + LINE(0, 0, 13534) / 2;
	WRITE_LINE(1, 11) = Acc;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=233, taps=[233]
// Delay line 3: length=175, taps=[175]
// Delay line 4: length=32, taps=[32]
// Delay line 5: length=273, taps=[273]
// Delay line 6: length=153, taps=[153]
// Delay line 7: length=21, taps=[21]
// Delay line 8: length=14084, taps=[1065, 1119, 1233, 1434, 1555, 1742, 1862, 2046, 2149, 2256, 2443, 2579, 2721, 2873, 3036, 3121, 3267, 3451, 3569, 3725, 3889, 4034, 4152, 4257, 4492, 4556, 4727, 4849, 5034, 5129, 5235, 5421, 5534, 5759, 5837, 6035, 6159, 6223, 6446, 6534, 6782, 6859, 7039, 7126, 7221, 7439, 7534, 7736, 7891, 8034, 8146, 8278, 8447, 8565, 8700, 8885, 9012, 9171, 9215, 9449, 9513, 9765, 9867, 10046, 10110, 10285, 10428, 10578, 10734, 10815, 11023, 11185, 11254, 11479, 11546, 11715, 11847, 12000, 12074, 14084]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_118(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(7, 2295, 21) / 2;
	WRITE_LINE(7, 2295) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2295, 21) + LINE(6, 2272, 153) / 2;
	WRITE_LINE(6, 2272) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2272, 153) + LINE(5, 2117, 273) / 2;
	WRITE_LINE(5, 2117) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2117, 273) + LINE(8, 16381, 12000) / 2;
	tmp3 = Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(4, 1842, 32) / 2;
	WRITE_LINE(4, 1842) = -Acc;
	Acc = -Acc / 2 + LINE(4, 1842, 32) + LINE(3, 1808, 175) / 2;
	WRITE_LINE(3, 1808) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1808, 175) + LINE(2, 1631, 233) / 2;
	WRITE_LINE(2, 1631) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1631, 233) + LINE(8, 16381, 12000) / 2;
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
	Acc = Acc * -3 / 64 + -LINE(8, 16381, 1065) / 64 + -LINE(8, 16381, 1119) / 64 + -LINE(8, 16381, 1233) / 64 + -LINE(8, 16381, 1434) / 64 + -LINE(8, 16381, 1555) / 64 + -LINE(8, 16381, 1742) / 64 + -LINE(8, 16381, 1862) / 64 + -LINE(8, 16381, 2046) / 64 + -LINE(8, 16381, 3569) / 64 + -LINE(8, 16381, 2256) / 64 + -LINE(8, 16381, 2443) / 64 + -LINE(8, 16381, 3121) / 64 + -LINE(8, 16381, 2721) / 64 + LINE(8, 16381, 2873) / 32 + LINE(8, 16381, 3036) / 32 + LINE(8, 16381, 2579) / 32 + LINE(8, 16381, 3267) / 32 + LINE(8, 16381, 3451) / 32 + LINE(8, 16381, 2149) / 32 + LINE(8, 16381, 3725) / 32 + LINE(8, 16381, 3889) / 32 + LINE(8, 16381, 4034) / 32 + LINE(8, 16381, 4152) / 32 + -LINE(8, 16381, 4257) / 16 + -LINE(8, 16381, 4492) / 16 + -LINE(8, 16381, 4556) / 16 + -LINE(8, 16381, 4727) / 16 + -LINE(8, 16381, 4849) / 16 + -LINE(8, 16381, 6035) / 16 + -LINE(8, 16381, 5129) / 16 + -LINE(8, 16381, 5235) / 16 + -LINE(8, 16381, 6223) / 16 + -LINE(8, 16381, 5534) / 16 + LINE(8, 16381, 5759) / 8 + LINE(8, 16381, 5837) / 8 + LINE(8, 16381, 5034) / 8 + LINE(8, 16381, 6159) / 8 + LINE(8, 16381, 5421) / 8 + LINE(8, 16381, 6446) / 8 + LINE(8, 16381, 6534) / 8 + LINE(8, 16381, 6782) / 8 + LINE(8, 16381, 6859) / 8 + LINE(8, 16381, 7039) / 8 + LINE(8, 16381, 7126) / 8 + LINE(8, 16381, 7221) / 8 + LINE(8, 16381, 8565) / 8 + LINE(8, 16381, 7534) / 8 + LINE(8, 16381, 7736) / 8 + LINE(8, 16381, 7891) / 8 + LINE(8, 16381, 9215) / 8 + LINE(8, 16381, 8146) / 8 + LINE(8, 16381, 8278) / 8 + -LINE(8, 16381, 8447) / 4 + -LINE(8, 16381, 7439) / 4 + -LINE(8, 16381, 8700) / 4 + -LINE(8, 16381, 8885) / 4 + -LINE(8, 16381, 9012) / 4 + -LINE(8, 16381, 9171) / 4 + -LINE(8, 16381, 8034) / 4 + -LINE(8, 16381, 9449) / 4 + -LINE(8, 16381, 9513) / 4 + -LINE(8, 16381, 9765) / 4 + -LINE(8, 16381, 9867) / 4 + -LINE(8, 16381, 10046) / 4 + -LINE(8, 16381, 10110) / 4 + -LINE(8, 16381, 10285) / 4 + -LINE(8, 16381, 12074) / 4 + -LINE(8, 16381, 10578) / 4 + -LINE(8, 16381, 10734) / 4 + -LINE(8, 16381, 11715) / 4 + -LINE(8, 16381, 11023) / 4 + -LINE(8, 16381, 11185) / 4 + LINE(8, 16381, 11254) / 2 + LINE(8, 16381, 11479) / 2 + LINE(8, 16381, 11546) / 2 + LINE(8, 16381, 10815) / 2 + LINE(8, 16381, 11847) / 2 + LINE(8, 16381, 10428) / 2;
	WRITE_LINE(1, 11) = Acc;
	Acc = LINE(8, 16381, 14084) / 2 + LINE(0, 0, 1);
	WRITE_LINE(8, 16381) = Acc;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=9012, taps=[2315, 3378, 4000, 5321, 6352, 8922, 9012]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_119(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(0, 0, 8922) / 4 + LINE(0, 0, 5321) / 2 + LINE(0, 0, 4000) / 2 + LINE(0, 0, 2315) / 2;
	tmp3 = Acc;
	Acc = -LINE(0, 0, 9012) / 4 + LINE(0, 0, 6352) / 2 + LINE(0, 0, 4000) / 2 + LINE(0, 0, 3378) / 2;
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=13998, taps=[781, 1121, 2724, 3041, 4048, 4501, 5194, 6873, 8775, 8913, 9145, 9450, 9835, 10160, 10683, 10981, 11361, 11571, 11919, 12016, 12338, 12449, 12656, 12727, 12927, 13071, 13185, 13289, 13319, 13457, 13519, 13552, 13619, 13676, 13727, 13749, 13756, 13807, 13815, 13819, 13854, 13918, 13919, 13955, 13957, 13968, 13972, 13986, 13998]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_120(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 13998) / 128 + LINE(0, 0, 13968) / 128 + LINE(0, 0, 13955) / 128 + LINE(0, 0, 13957) / 128 + LINE(0, 0, 13815) / 128 + -LINE(0, 0, 13819) / 64 + -LINE(0, 0, 13749) / 64 + -LINE(0, 0, 13756) / 64 + -LINE(0, 0, 13676) / 64 + LINE(0, 0, 13552) / 32 + LINE(0, 0, 13319) / 32 + LINE(0, 0, 13185) / 32 + LINE(0, 0, 12927) / 32 + LINE(0, 0, 12656) / 32 + -LINE(0, 0, 12338) / 16 + -LINE(0, 0, 11919) / 16 + -LINE(0, 0, 11361) / 16 + -LINE(0, 0, 10683) / 16 + LINE(0, 0, 9835) / 8 + LINE(0, 0, 8775) / 8 + -LINE(0, 0, 9450) / 4 + -LINE(0, 0, 5194) / 4 + LINE(0, 0, 4501) / 2 + LINE(0, 0, 2724) / 2 + LINE(0, 0, 781) / 2;
	tmp3 = Acc;
	Acc = LINE(0, 0, 13986) / 128 + LINE(0, 0, 13919) / 128 + LINE(0, 0, 13918) / 128 + LINE(0, 0, 13972) / 128 + LINE(0, 0, 13807) / 128 + LINE(0, 0, 13854) / 128 + -LINE(0, 0, 13727) / 64 + -LINE(0, 0, 13619) / 64 + -LINE(0, 0, 13519) / 64 + LINE(0, 0, 13457) / 32 + LINE(0, 0, 13289) / 32 + LINE(0, 0, 13071) / 32 + -LINE(0, 0, 12727) / 16 + -LINE(0, 0, 12449) / 16 + -LINE(0, 0, 12016) / 16 + -LINE(0, 0, 11571) / 16 + LINE(0, 0, 10981) / 8 + LINE(0, 0, 10160) / 8 + LINE(0, 0, 9145) / 8 + LINE(0, 0, 8913) / 8 + -LINE(0, 0, 6873) / 4 + -LINE(0, 0, 4048) / 4 + LINE(0, 0, 3041) / 2 + LINE(0, 0, 1121) / 2;
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=14000, taps=[1065, 1233, 1555, 1862, 2443, 2579, 2721, 2873, 3451, 3569, 3725, 3889, 4152, 4492, 5034, 5235, 5421, 5534, 5759, 5837, 6035, 6159, 6446, 6534, 6782, 6859, 7039, 7126, 7221, 7439, 7534, 7736, 7891, 8034, 8146, 8278, 8447, 8565, 8700, 8885, 9012, 9123, 9171, 9215, 9449, 9513, 9765, 9867, 10046, 10110, 10211, 10285, 10428, 10578, 10734, 10815, 11023, 11111, 11185, 11254, 11479, 11546, 11715, 11847, 12074, 12112, 12279, 12345, 12415, 12516, 12746, 12781, 12815, 13046, 13112, 13217, 13378, 13534, 14000]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=98, taps=[98]
// Delay line 4: length=45, taps=[45]
// Delay line 5: length=121, taps=[121]
// Delay line 6: length=67, taps=[67]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_121(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 12, 1) / 2 + LINE(6, 2298, 67) / 2;
	WRITE_LINE(6, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2298, 67) + LINE(5, 2229, 121) / 2;
	WRITE_LINE(5, 2229) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2229, 121) + LINE(0, 0, 14000);
	tmp3 = Acc;
	Acc = LINE(1, 10, 1) / 2 + LINE(4, 1931, 45) / 2;
	WRITE_LINE(4, 1931) = -Acc;
	Acc = -Acc / 2 + LINE(4, 1931, 45) + LINE(3, 1884, 98) / 2;
	WRITE_LINE(3, 1884) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1884, 98);
	tmp5 = Acc;
	Acc = LINE(0, 0, 1065) / 32 + LINE(0, 0, 1233) / 32 + LINE(0, 0, 1555) / 32 + LINE(0, 0, 1862) / 32 + LINE(0, 0, 3569) / 32 + LINE(0, 0, 2443) / 32 + LINE(0, 0, 2721) / 32 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 2579) / 16 + -LINE(0, 0, 3451) / 16 + -LINE(0, 0, 13112) / 16 + -LINE(0, 0, 3725) / 16 + -LINE(0, 0, 3889) / 16 + LINE(0, 0, 4152) / 8 + LINE(0, 0, 4492) / 8 + LINE(0, 0, 6035) / 8 + LINE(0, 0, 12345) / 8 + LINE(0, 0, 11111) / 8 + LINE(0, 0, 5235) / 8 + LINE(0, 0, 5534) / 8 + -LINE(0, 0, 5759) / 4 + -LINE(0, 0, 5034) / 4 + -LINE(0, 0, 10211) / 4 + -LINE(0, 0, 9123) / 4 + -LINE(0, 0, 12781) / 4 + -LINE(0, 0, 5421) / 4 + -LINE(0, 0, 6534) / 4 + LINE(0, 0, 6859) / 2 + LINE(0, 0, 7126) / 2 + LINE(0, 0, 8565) / 2 + LINE(0, 0, 7736) / 2 + LINE(0, 0, 9215) / 2 + LINE(0, 0, 8146) / 2;
	WRITE_LINE(1, 10) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
	Acc = LINE(0, 0, 5759) / 8 + LINE(0, 0, 5837) / 8 + LINE(0, 0, 5034) / 8 + LINE(0, 0, 6159) / 8 + LINE(0, 0, 5421) / 8 + LINE(0, 0, 6446) / 8 + LINE(0, 0, 6534) / 8 + LINE(0, 0, 6782) / 8 + LINE(0, 0, 6859) / 8 + LINE(0, 0, 7039) / 8 + LINE(0, 0, 7126) / 8 + LINE(0, 0, 7221) / 8 + LINE(0, 0, 8565) / 8 + LINE(0, 0, 7534) / 8 + LINE(0, 0, 7736) / 8 + LINE(0, 0, 7891) / 8 + LINE(0, 0, 9215) / 8 + LINE(0, 0, 8146) / 8 + LINE(0, 0, 8278) / 8 + -LINE(0, 0, 8447) / 4 + -LINE(0, 0, 7439) / 4 + -LINE(0, 0, 8700) / 4 + -LINE(0, 0, 8885) / 4 + -LINE(0, 0, 9012) / 4 + -LINE(0, 0, 9171) / 4 + -LINE(0, 0, 8034) / 4 + -LINE(0, 0, 9449) / 4 + -LINE(0, 0, 9513) / 4 + -LINE(0, 0, 9765) / 4 + -LINE(0, 0, 9867) / 4 + -LINE(0, 0, 10046) / 4 + -LINE(0, 0, 10110) / 4 + -LINE(0, 0, 10285) / 4 + -LINE(0, 0, 12074) / 4 + -LINE(0, 0, 10578) / 4 + -LINE(0, 0, 10734) / 4 + -LINE(0, 0, 11715) / 4 + -LINE(0, 0, 11023) / 4 + -LINE(0, 0, 11185) / 4 + LINE(0, 0, 11254) / 2 + LINE(0, 0, 11479) / 2 + LINE(0, 0, 11546) / 2 + LINE(0, 0, 10815) / 2 + LINE(0, 0, 11847) / 2 + LINE(0, 0, 10428) / 2 + LINE(0, 0, 12112) / 2 + LINE(0, 0, 12279) / 2 + LINE(0, 0, 12415) / 2 + LINE(0, 0, 12516) / 2 + LINE(0, 0, 12746) / 2 + LINE(0, 0, 12815) / 2 + LINE(0, 0, 13046) / 2 + LINE(0, 0, 13217) / 2 + LINE(0, 0, 13378) / 2 + LINE(0, 0, 13534) / 2;
	WRITE_LINE(2, 12) = Acc;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=7, taps=[7]
// Delay line 1: length=3, taps=[1, 3]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=31, taps=[31]
// Delay line 4: length=35, taps=[35]
// Delay line 5: length=439, taps=[439]
// Delay line 6: length=363, taps=[363]
// Delay line 7: length=308, taps=[308]
// Delay line 8: length=257, taps=[257]
// Delay line 9: length=210, taps=[210]
// Delay line 10: length=179, taps=[179]
// Delay line 11: length=149, taps=[149]
// Delay line 12: length=126, taps=[126]
// Delay line 13: length=102, taps=[102]
// Delay line 14: length=87, taps=[87]
// Delay line 15: length=75, taps=[75]
// Delay line 16: length=63, taps=[63]
// Delay line 17: length=50, taps=[50]
// Delay line 18: length=43, taps=[43]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_122(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp13;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 7) + LINE(18, 16375, 43) / 2;
	WRITE_LINE(18, 16375) = -Acc;
	Acc = -Acc / 2 + LINE(18, 16375, 43) + LINE(17, 16330, 50) / 2;
	WRITE_LINE(17, 16330) = -Acc;
	Acc = -Acc / 2 + LINE(17, 16330, 50) + LINE(16, 16278, 63) / 2;
	WRITE_LINE(16, 16278) = -Acc;
	Acc = -Acc / 2 + LINE(16, 16278, 63) + LINE(15, 16213, 75) / 2;
	WRITE_LINE(15, 16213) = -Acc;
	Acc = -Acc / 2 + LINE(15, 16213, 75) + LINE(14, 16136, 87) / 2;
	WRITE_LINE(14, 16136) = -Acc;
	Acc = -Acc / 2 + LINE(14, 16136, 87) + LINE(13, 16047, 102) / 2;
	WRITE_LINE(13, 16047) = -Acc;
	Acc = -Acc / 2 + LINE(13, 16047, 102) + LINE(12, 15943, 126) / 2;
	WRITE_LINE(12, 15943) = -Acc;
	Acc = -Acc / 2 + LINE(12, 15943, 126) + LINE(11, 15815, 149) / 2;
	WRITE_LINE(11, 15815) = -Acc;
	Acc = -Acc / 2 + LINE(11, 15815, 149) + LINE(10, 15664, 179) / 2;
	WRITE_LINE(10, 15664) = -Acc;
	Acc = -Acc / 2 + LINE(10, 15664, 179) + LINE(9, 15483, 210) / 2;
	WRITE_LINE(9, 15483) = -Acc;
	Acc = -Acc / 2 + LINE(9, 15483, 210) + LINE(8, 15271, 257) / 2;
	WRITE_LINE(8, 15271) = -Acc;
	Acc = -Acc / 2 + LINE(8, 15271, 257) + LINE(7, 15012, 308) / 2;
	WRITE_LINE(7, 15012) = -Acc;
	Acc = -Acc / 2 + LINE(7, 15012, 308) + LINE(6, 14702, 363) / 2;
	WRITE_LINE(6, 14702) = -Acc;
	Acc = -Acc / 2 + LINE(6, 14702, 363) + LINE(5, 14337, 439) / 2;
	WRITE_LINE(5, 14337) = -Acc;
	Acc = -Acc / 2 + LINE(5, 14337, 439);
	tmp13 = Acc;
	Acc = tmp13 + LINE(4, 13896, 35) / 2;
	WRITE_LINE(4, 13896) = -Acc;
	Acc = -Acc / 2 + LINE(4, 13896, 35);
	WRITE_LINE(2, 6) = -Acc;
	Acc = tmp13 + LINE(3, 13859, 31) / 2;
	WRITE_LINE(3, 13859) = -Acc;
	Acc = -Acc / 2 + LINE(3, 13859, 31);
	WRITE_LINE(1, 4) = -Acc;
	*out_left = LINE(2, 6, 1);
	*out_right = LINE(1, 4, 1);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=2, taps=[2]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=120, taps=[120]
// Delay line 4: length=101, taps=[101]
// Delay line 5: length=89, taps=[89]
// Delay line 6: length=67, taps=[67]
// Delay line 7: length=45, taps=[45]
// Delay line 8: length=34, taps=[34]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_123(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 1) + LINE(2, 5, 1) / 2 + LINE(8, 16381, 34) / 2;
	WRITE_LINE(8, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(8, 16381, 34) + LINE(7, 16345, 45) / 2;
	WRITE_LINE(7, 16345) = -Acc;
	Acc = -Acc / 2 + LINE(7, 16345, 45) + LINE(6, 16298, 67) / 2;
	WRITE_LINE(6, 16298) = -Acc;
	Acc = -Acc / 2 + LINE(6, 16298, 67) + LINE(5, 16229, 89) / 2;
	WRITE_LINE(5, 16229) = -Acc;
	Acc = -Acc / 2 + LINE(5, 16229, 89) + LINE(4, 16138, 101) / 2;
	WRITE_LINE(4, 16138) = -Acc;
	Acc = -Acc / 2 + LINE(4, 16138, 101) + LINE(3, 16035, 120) / 2;
	WRITE_LINE(3, 16035) = -Acc;
	Acc = -Acc / 2 + LINE(3, 16035, 120);
	WRITE_LINE(1, 3) = Acc;
	Acc = WRITE_LINE(1, 3);
	WRITE_LINE(2, 5) = Acc;
	*out_left = WRITE_LINE(2, 5);
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=2, taps=[2]
// Delay line 1: length=393, taps=[393]
// Delay line 2: length=121, taps=[121]
// Delay line 3: length=337, taps=[337]
// Delay line 4: length=187, taps=[187]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_124(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp0, tmp5;
	tmp0 = input;
	Acc = tmp0 + LINE(4, 16381, 187) / 2;
	WRITE_LINE(4, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(4, 16381, 187) + LINE(3, 16192, 337) / 2;
	WRITE_LINE(3, 16192) = -Acc;
	Acc = -Acc / 2 + LINE(3, 16192, 337);
	WRITE_LINE(0, 3) = Acc;
	Acc = tmp0 + LINE(2, 15853, 121) / 2;
	WRITE_LINE(2, 15853) = -Acc;
	Acc = -Acc / 2 + LINE(2, 15853, 121) + LINE(1, 15730, 393) / 2;
	WRITE_LINE(1, 15730) = -Acc;
	Acc = -Acc / 2 + LINE(1, 15730, 393);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(0, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=1, taps=[1]
// Delay line 1: length=300, taps=[296, 298, 300]
// Delay line 2: length=215, taps=[215]
// Delay line 3: length=89, taps=[89]
// Delay line 4: length=47, taps=[47]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_125(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp601, tmp2001;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 1) + LINE(4, 16381, 47) / 2;
	WRITE_LINE(4, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(4, 16381, 47) + LINE(3, 16332, 89) / 2;
	WRITE_LINE(3, 16332) = -Acc;
	Acc = -Acc / 2 + LINE(3, 16332, 89) + LINE(2, 16241, 215) / 2;
	WRITE_LINE(2, 16241) = -Acc;
	Acc = -Acc / 2 + LINE(2, 16241, 215);
	tmp2001 = Acc;
	Acc = tmp2001;
	WRITE_LINE(1, 301) = Acc;
	*out_left = LINE(1, 301, 296);
	*out_right = LINE(1, 301, 298);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=300, taps=[150, 300]
// Delay line 1: length=2, taps=[2]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_126(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 150);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 300);
	tmp5 = Acc;
	*out_left = tmp5;
	*out_right = WRITE_LINE(1, 3);
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=3, taps=[3]
// Delay line 1: length=1, taps=[1]
// Delay line 2: length=1, taps=[1]
// Delay line 3: length=258, taps=[258]
// Delay line 4: length=213, taps=[213]
// Delay line 5: length=149, taps=[149]
// Delay line 6: length=105, taps=[105]
// Delay line 7: length=74, taps=[74]
// Delay line 8: length=52, taps=[52]
// Delay line 9: length=35, taps=[35]
// Delay line 10: length=25, taps=[25]
// Delay line 11: length=17, taps=[17]
// Delay line 12: length=304, taps=[304]
// Delay line 13: length=174, taps=[174]
// Delay line 14: length=123, taps=[123]
// Delay line 15: length=88, taps=[88]
// Delay line 16: length=61, taps=[61]
// Delay line 17: length=45, taps=[45]
// Delay line 18: length=29, taps=[29]
// Delay line 19: length=22, taps=[22]
// Delay line 20: length=15, taps=[15]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_127(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
	int16_t Acc, tmp1, tmp3, tmp5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(1, 14261, 1) / 4 + LINE(2, 14264, 1);
	tmp3 = Acc;
	Acc = -LINE(2, 14264, 1) / 4 + LINE(1, 14261, 1);
	tmp5 = Acc;
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
	WRITE_LINE(2, 14264) = Acc;
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
	WRITE_LINE(1, 14261) = Acc;
	*out_left = tmp5;
	*out_right = tmp3;
}
#undef LINE
#undef WRITE_LINE
// Delay line 0: length=137, taps=[135, 137]
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void effect_128(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
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
	effect_65,
	effect_66,
	effect_67,
	effect_68,
	effect_69,
	effect_70,
	effect_71,
	effect_72,
	effect_73,
	effect_74,
	effect_75,
	effect_76,
	effect_77,
	effect_78,
	effect_79,
	effect_80,
	effect_81,
	effect_82,
	effect_83,
	effect_84,
	effect_85,
	effect_86,
	effect_87,
	effect_88,
	effect_89,
	effect_90,
	effect_91,
	effect_92,
	effect_93,
	effect_94,
	effect_95,
	effect_96,
	effect_97,
	effect_98,
	effect_99,
	effect_100,
	effect_101,
	effect_102,
	effect_103,
	effect_104,
	effect_105,
	effect_106,
	effect_107,
	effect_108,
	effect_109,
	effect_110,
	effect_111,
	effect_112,
	effect_113,
	effect_114,
	effect_115,
	effect_116,
	effect_117,
	effect_118,
	effect_119,
	effect_120,
	effect_121,
	effect_122,
	effect_123,
	effect_124,
	effect_125,
	effect_126,
	effect_127,
	effect_128,
};
