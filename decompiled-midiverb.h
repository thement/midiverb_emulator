/* Effect 1: .2 Sec SMALL BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_1(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 15992, 64) / 2 + LINE(7, 15290, 131) / 2 + LINE(5, 14835, 120) / 2 + LINE(4, 14696, 179) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = LINE(9, 15729, 40) / 2 + LINE(8, 15555, 167) / 2 + LINE(6, 15054, 151) / 2 + LINE(3, 14397, 213) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = LINE(13, 16381, 58) * 5 / 8 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 5 / 8 + LINE(13, 16381, 0) * 5 / 8 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 113) * 5 / 8 + LINE(12, 16321, 0) * 5 / 8 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -LINE(11, 16230, 0) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + LINE(11, 16230, 0) / 2 + LINE(11, 16230, 113) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = LINE(10, 15992, 261) / 2 + LINE(9, 15729, 172) / 2;
	WRITE_LINE(9, 15729) = -Acc;
	Acc = -Acc / 2 + LINE(9, 15729, 172);
	WRITE_LINE(8, 15555) = Acc;
	Acc = LINE(8, 15555, 263) / 2 + LINE(7, 15290, 234) / 2;
	WRITE_LINE(7, 15290) = -Acc;
	Acc = -Acc / 2 + LINE(7, 15290, 234);
	tmp_1 = Acc;
	Acc = LINE(2, 14107, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(2, 14107) = Acc;
	Acc = LINE(2, 14107, 1) + tmp_b;
	WRITE_LINE(10, 15992) = Acc;
	Acc = LINE(6, 15054, 217) / 2 + LINE(5, 14835, 137) / 2;
	WRITE_LINE(5, 14835) = -Acc;
	Acc = -Acc / 2 + LINE(5, 14835, 137);
	WRITE_LINE(4, 14696) = Acc;
	Acc = LINE(4, 14696, 297) / 2 + LINE(3, 14397, 285) / 2;
	WRITE_LINE(3, 14397) = -Acc;
	Acc = -Acc / 2 + LINE(3, 14397, 285);
	tmp_1 = Acc;
	Acc = LINE(1, 14104, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 14104) = Acc;
	Acc = LINE(1, 14104, 1) + tmp_b;
	WRITE_LINE(6, 15054) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 2: .2 Sec SMALL WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_2(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(11, 15992, 64) / 2 + LINE(8, 15290, 131) / 2 + LINE(6, 14835, 120) / 2 + LINE(5, 14696, 179) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = LINE(10, 15729, 40) / 2 + LINE(9, 15555, 167) / 2 + LINE(7, 15054, 151) / 2 + LINE(4, 14397, 213) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = LINE(3, 14110, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(3, 14110) = Acc;
	Acc = LINE(14, 16381, 58) * 5 / 8 + LINE(3, 14110, 1) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = LINE(13, 16321, 89) * 5 / 8 + LINE(14, 16381, 0) * 5 / 8 + LINE(14, 16381, 58);
	WRITE_LINE(13, 16321) = -Acc;
	Acc = LINE(12, 16230, 113) * 5 / 8 + LINE(13, 16321, 0) * 5 / 8 + LINE(13, 16321, 89);
	WRITE_LINE(12, 16230) = -Acc;
	Acc = -LINE(12, 16230, 0) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + LINE(12, 16230, 0) / 2 + LINE(12, 16230, 113) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = LINE(11, 15992, 261) / 2 + LINE(10, 15729, 172) / 2;
	WRITE_LINE(10, 15729) = -Acc;
	Acc = -Acc / 2 + LINE(10, 15729, 172);
	WRITE_LINE(9, 15555) = Acc;
	Acc = LINE(9, 15555, 263) / 2 + LINE(8, 15290, 234) / 2;
	WRITE_LINE(8, 15290) = -Acc;
	Acc = -Acc / 2 + LINE(8, 15290, 234);
	tmp_1 = Acc;
	Acc = LINE(2, 14107, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(2, 14107) = Acc;
	Acc = LINE(2, 14107, 1) + tmp_b;
	WRITE_LINE(11, 15992) = Acc;
	Acc = LINE(7, 15054, 217) / 2 + LINE(6, 14835, 137) / 2;
	WRITE_LINE(6, 14835) = -Acc;
	Acc = -Acc / 2 + LINE(6, 14835, 137);
	WRITE_LINE(5, 14696) = Acc;
	Acc = LINE(5, 14696, 297) / 2 + LINE(4, 14397, 285) / 2;
	WRITE_LINE(4, 14397) = -Acc;
	Acc = -Acc / 2 + LINE(4, 14397, 285);
	tmp_1 = Acc;
	Acc = LINE(1, 14104, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 14104) = Acc;
	Acc = LINE(1, 14104, 1) + tmp_b;
	WRITE_LINE(7, 15054) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 3: .2 Sec MEDIUM BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_3(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 15812, 64) / 2 + LINE(8, 14975, 396) / 2 + LINE(6, 13974, 339) / 2 + LINE(4, 13216, 179) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = LINE(10, 15812, 303) / 2 + LINE(8, 14975, 167) / 2 + LINE(6, 13974, 151) / 2 + LINE(4, 13216, 512) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = LINE(13, 16381, 58) * 5 / 8 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 5 / 8 + LINE(13, 16381, 0) * 5 / 8 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 183) * 5 / 8 + LINE(12, 16321, 0) * 5 / 8 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -LINE(11, 16230, 0) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + LINE(11, 16230, 0) / 2 + LINE(11, 16230, 183) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = LINE(10, 15812, 461) / 2 + LINE(9, 15349, 372) / 2;
	WRITE_LINE(9, 15349) = -Acc;
	Acc = -Acc / 2 + LINE(9, 15349, 372);
	WRITE_LINE(8, 14975) = Acc;
	Acc = -LINE(8, 14975, 563) / 4 + LINE(7, 14410, 434) / 2;
	WRITE_LINE(7, 14410) = -Acc;
	Acc = -Acc / 2 + LINE(7, 14410, 434);
	tmp_1 = Acc;
	Acc = LINE(2, 12127, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(2, 12127) = Acc;
	Acc = LINE(2, 12127, 1) + tmp_b;
	WRITE_LINE(10, 15812) = Acc;
	Acc = LINE(6, 13974, 417) / 2 + LINE(5, 13555, 337) / 2;
	WRITE_LINE(5, 13555) = -Acc;
	Acc = -Acc / 2 + LINE(5, 13555, 337);
	WRITE_LINE(4, 13216) = Acc;
	Acc = -LINE(4, 13216, 597) / 4 + LINE(3, 12617, 485) / 2;
	WRITE_LINE(3, 12617) = -Acc;
	Acc = -Acc / 2 + LINE(3, 12617, 485);
	tmp_1 = Acc;
	Acc = LINE(1, 12124, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 12124) = Acc;
	Acc = LINE(1, 12124, 1) + tmp_b;
	WRITE_LINE(6, 13974) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 4: .3 Sec SMALL BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_4(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 15992, 64) / 2 + LINE(8, 15255, 396) / 2 + LINE(6, 14554, 339) / 2 + LINE(4, 13796, 179) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = LINE(10, 15992, 303) / 2 + LINE(8, 15255, 167) / 2 + LINE(6, 14554, 151) / 2 + LINE(3, 13397, 113) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = LINE(13, 16381, 58) * 5 / 8 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 5 / 8 + LINE(13, 16381, 0) * 5 / 8 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 103) * 5 / 8 + LINE(12, 16321, 0) * 5 / 8 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -LINE(11, 16230, 0) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + LINE(11, 16230, 0) / 2 + LINE(11, 16230, 103) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = LINE(10, 15992, 461) / 2 + LINE(9, 15529, 272) / 2;
	WRITE_LINE(9, 15529) = -Acc;
	Acc = -Acc / 2 + LINE(9, 15529, 272);
	WRITE_LINE(8, 15255) = Acc;
	Acc = LINE(8, 15255, 463) / 2 + LINE(7, 14790, 234) / 2;
	WRITE_LINE(7, 14790) = -Acc;
	Acc = -Acc / 2 + LINE(7, 14790, 234);
	tmp_1 = Acc;
	Acc = LINE(2, 13007, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(2, 13007) = Acc;
	Acc = LINE(2, 13007, 1) + tmp_b;
	WRITE_LINE(10, 15992) = Acc;
	Acc = LINE(6, 14554, 417) / 2 + LINE(5, 14135, 337) / 2;
	WRITE_LINE(5, 14135) = -Acc;
	Acc = -Acc / 2 + LINE(5, 14135, 337);
	WRITE_LINE(4, 13796) = Acc;
	Acc = LINE(4, 13796, 397) / 2 + LINE(3, 13397, 385) / 2;
	WRITE_LINE(3, 13397) = -Acc;
	Acc = -Acc / 2 + LINE(3, 13397, 385);
	tmp_1 = Acc;
	Acc = LINE(1, 13004, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 13004) = Acc;
	Acc = LINE(1, 13004, 1) + tmp_b;
	WRITE_LINE(6, 14554) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 5: .3 Sec SMALL WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_5(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(11, 15978, 64) / 2 + LINE(9, 15141, 196) / 2 + LINE(7, 14340, 339) / 2 + LINE(5, 13582, 179) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = LINE(11, 15978, 303) / 2 + LINE(9, 15141, 167) / 2 + LINE(7, 14340, 151) / 2 + LINE(5, 13582, 212) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = LINE(3, 12696, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(3, 12696) = Acc;
	Acc = LINE(14, 16381, 58) * 5 / 8 + LINE(3, 12696, 1) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = LINE(13, 16321, 89) * 5 / 8 + LINE(14, 16381, 0) * 5 / 8 + LINE(14, 16381, 58);
	WRITE_LINE(13, 16321) = -Acc;
	Acc = LINE(12, 16230, 103) * 5 / 8 + LINE(13, 16321, 0) * 5 / 8 + LINE(13, 16321, 89);
	WRITE_LINE(12, 16230) = -Acc;
	Acc = -LINE(12, 16230, 0) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + LINE(12, 16230, 0) / 2 + LINE(12, 16230, 103) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = LINE(11, 15978, 461) / 2 + LINE(10, 15515, 372) / 2;
	WRITE_LINE(10, 15515) = -Acc;
	Acc = -Acc / 2 + LINE(10, 15515, 372);
	WRITE_LINE(9, 15141) = Acc;
	Acc = LINE(9, 15141, 363) / 2 + LINE(8, 14776, 434) / 2;
	WRITE_LINE(8, 14776) = -Acc;
	Acc = -Acc / 2 + LINE(8, 14776, 434);
	tmp_1 = Acc;
	Acc = LINE(2, 12693, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(2, 12693) = Acc;
	Acc = LINE(2, 12693, 1) + tmp_b;
	WRITE_LINE(11, 15978) = Acc;
	Acc = LINE(7, 14340, 417) / 2 + LINE(6, 13921, 337) / 2;
	WRITE_LINE(6, 13921) = -Acc;
	Acc = -Acc / 2 + LINE(6, 13921, 337);
	WRITE_LINE(5, 13582) = Acc;
	Acc = LINE(5, 13582, 397) / 2 + LINE(4, 13183, 485) / 2;
	WRITE_LINE(4, 13183) = -Acc;
	Acc = -Acc / 2 + LINE(4, 13183, 485);
	tmp_1 = Acc;
	Acc = LINE(1, 12690, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 12690) = Acc;
	Acc = LINE(1, 12690, 1) + tmp_b;
	WRITE_LINE(7, 14340) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 6: .4 Sec MEDIUM BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_6(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 15812, 64) / 2 + LINE(8, 14975, 396) / 2 + LINE(6, 13974, 339) / 2 + LINE(4, 13216, 179) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = LINE(10, 15812, 303) / 2 + LINE(8, 14975, 167) / 2 + LINE(6, 13974, 151) / 2 + LINE(4, 13216, 512) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = LINE(13, 16381, 58) * 5 / 8 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 5 / 8 + LINE(13, 16381, 0) * 5 / 8 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 183) * 5 / 8 + LINE(12, 16321, 0) * 5 / 8 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -LINE(11, 16230, 0) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + LINE(11, 16230, 0) / 2 + LINE(11, 16230, 183) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = LINE(10, 15812, 461) / 2 + LINE(9, 15349, 372) / 2;
	WRITE_LINE(9, 15349) = -Acc;
	Acc = -Acc / 2 + LINE(9, 15349, 372);
	WRITE_LINE(8, 14975) = Acc;
	Acc = LINE(8, 14975, 563) / 2 + LINE(7, 14410, 434) / 2;
	WRITE_LINE(7, 14410) = -Acc;
	Acc = -Acc / 2 + LINE(7, 14410, 434);
	tmp_1 = Acc;
	Acc = LINE(2, 12127, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(2, 12127) = Acc;
	Acc = LINE(2, 12127, 1) + tmp_b;
	WRITE_LINE(10, 15812) = Acc;
	Acc = LINE(6, 13974, 417) / 2 + LINE(5, 13555, 337) / 2;
	WRITE_LINE(5, 13555) = -Acc;
	Acc = -Acc / 2 + LINE(5, 13555, 337);
	WRITE_LINE(4, 13216) = Acc;
	Acc = LINE(4, 13216, 597) / 2 + LINE(3, 12617, 485) / 2;
	WRITE_LINE(3, 12617) = -Acc;
	Acc = -Acc / 2 + LINE(3, 12617, 485);
	tmp_1 = Acc;
	Acc = LINE(1, 12124, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 12124) = Acc;
	Acc = LINE(1, 12124, 1) + tmp_b;
	WRITE_LINE(6, 13974) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 7: .4 Sec MEDIUM WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_7(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(11, 15812, 64) / 4 + -LINE(9, 14975, 396) / 4 + -LINE(7, 13974, 339) / 4 + -LINE(5, 13216, 179) / 4;
	tmp_5 = -Acc;
	Acc = -LINE(11, 15812, 303) / 4 + -LINE(9, 14975, 167) / 4 + -LINE(7, 13974, 151) / 4 + -LINE(5, 13216, 512) / 4;
	tmp_3 = -Acc;
	Acc = LINE(3, 12130, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(3, 12130) = Acc;
	Acc = LINE(14, 16381, 58) * 5 / 8 + LINE(3, 12130, 1) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = LINE(13, 16321, 89) * 5 / 8 + LINE(14, 16381, 0) * 5 / 8 + LINE(14, 16381, 58);
	WRITE_LINE(13, 16321) = -Acc;
	Acc = LINE(12, 16230, 183) * 5 / 8 + LINE(13, 16321, 0) * 5 / 8 + LINE(13, 16321, 89);
	WRITE_LINE(12, 16230) = -Acc;
	Acc = -LINE(12, 16230, 0) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + LINE(12, 16230, 0) / 2 + LINE(12, 16230, 183) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = LINE(11, 15812, 461) / 2 + LINE(10, 15349, 372) / 2;
	WRITE_LINE(10, 15349) = -Acc;
	Acc = -Acc / 2 + LINE(10, 15349, 372);
	WRITE_LINE(9, 14975) = Acc;
	Acc = LINE(9, 14975, 563) / 2 + LINE(8, 14410, 434) / 2;
	WRITE_LINE(8, 14410) = -Acc;
	Acc = -Acc / 2 + LINE(8, 14410, 434);
	tmp_1 = Acc;
	Acc = LINE(2, 12127, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(2, 12127) = Acc;
	Acc = LINE(2, 12127, 1) + tmp_b;
	WRITE_LINE(11, 15812) = Acc;
	Acc = LINE(7, 13974, 417) / 2 + LINE(6, 13555, 337) / 2;
	WRITE_LINE(6, 13555) = -Acc;
	Acc = -Acc / 2 + LINE(6, 13555, 337);
	WRITE_LINE(5, 13216) = Acc;
	Acc = LINE(5, 13216, 597) / 2 + LINE(4, 12617, 485) / 2;
	WRITE_LINE(4, 12617) = -Acc;
	Acc = -Acc / 2 + LINE(4, 12617, 485);
	tmp_1 = Acc;
	Acc = LINE(1, 12124, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 12124) = Acc;
	Acc = LINE(1, 12124, 1) + tmp_b;
	WRITE_LINE(7, 13974) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 8: .6 Sec SMALL BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_8(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 15645, 64) / 2 + LINE(8, 14568, 496) / 2 + LINE(4, 11989, 339) / 2 + LINE(11, 16230, 24) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = LINE(10, 15645, 403) / 2 + LINE(8, 14568, 167) / 2 + LINE(4, 11989, 151) / 2 + LINE(11, 16230, 357) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = LINE(13, 16381, 58) * 5 / 8 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 5 / 8 + LINE(13, 16381, 0) * 5 / 8 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 183) * 5 / 8 + LINE(12, 16321, 0) * 5 / 8 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -LINE(11, 16230, 0) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + LINE(11, 16230, 0) / 2 + LINE(11, 16230, 183) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = LINE(10, 15645, 601) / 2 + LINE(9, 15042, 472) / 2;
	WRITE_LINE(9, 15042) = -Acc;
	Acc = -Acc / 2 + LINE(9, 15042, 472);
	WRITE_LINE(8, 14568) = Acc;
	Acc = LINE(8, 14568, 683) / 2 + LINE(7, 13883, 634) / 2;
	WRITE_LINE(7, 13883) = -Acc;
	Acc = Acc * -3 / 4 + LINE(7, 13883, 634) * 3 / 2;
	tmp_1 = Acc;
	Acc = LINE(2, 10730, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(2, 10730) = Acc;
	Acc = LINE(2, 10730, 1) + tmp_b;
	WRITE_LINE(10, 15645) = Acc;
	Acc = LINE(6, 13247, 617) / 2 + LINE(5, 12628, 637) / 2;
	WRITE_LINE(5, 12628) = -Acc;
	Acc = -Acc / 2 + LINE(5, 12628, 637);
	WRITE_LINE(4, 11989) = Acc;
	Acc = LINE(4, 11989, 597) / 2 + LINE(3, 11390, 655) / 2;
	WRITE_LINE(3, 11390) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 11390, 655) * 3 / 2;
	tmp_1 = Acc;
	Acc = LINE(1, 10727, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 10727) = Acc;
	*out_left = tmp_5;
	Acc = LINE(1, 10727, 1) + tmp_b;
	WRITE_LINE(6, 13247) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 9: .6 Sec MEDIUM WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_9(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(11, 14322, 123) / 4 + -LINE(9, 11770, 987) / 4 + -LINE(5, 6614, 678) / 4 + -LINE(14, 16182, 142) / 4;
	tmp_5 = -Acc;
	Acc = -LINE(11, 14322, 803) / 4 + -LINE(9, 11770, 342) / 4 + -LINE(5, 6614, 301) / 4 + -LINE(13, 15982, 620) / 4;
	tmp_3 = -Acc;
	Acc = LINE(3, 3742, 1) / 2 + LINE(0, 0, 100) / 2;
	WRITE_LINE(3, 3742) = Acc;
	Acc = LINE(15, 16282, 98) * 5 / 8 + LINE(3, 3742, 1) / 2;
	WRITE_LINE(15, 16282) = -Acc;
	Acc = LINE(14, 16182, 198) * 5 / 8 + LINE(15, 16282, 0) * 5 / 8 + LINE(15, 16282, 98);
	WRITE_LINE(14, 16182) = -Acc;
	Acc = LINE(13, 15982, 367) * 5 / 8 + LINE(14, 16182, 0) * 5 / 8 + LINE(14, 16182, 198);
	WRITE_LINE(13, 15982) = -Acc;
	Acc = LINE(13, 15982, 0) * 5 / 8 + LINE(13, 15982, 367) + LINE(12, 15113, 789) / 2;
	WRITE_LINE(12, 15113) = -Acc;
	Acc = Acc * -27 / 16 + LINE(12, 15113, 789) * 27 / 8;
	tmp_b = Acc;
	Acc = -LINE(11, 14322, 1203) / 4 + LINE(10, 13117, 1345) / 2;
	WRITE_LINE(10, 13117) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13117, 1345);
	WRITE_LINE(9, 11770) = Acc;
	Acc = -LINE(9, 11770, 1369) / 4 + LINE(8, 10399, 1289) / 2;
	WRITE_LINE(8, 10399) = -Acc;
	Acc = Acc * -3 / 4 + LINE(8, 10399, 1289) * 3 / 2;
	tmp_1 = Acc;
	Acc = LINE(2, 3739, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(2, 3739) = Acc;
	Acc = LINE(2, 3739, 1) + tmp_b;
	WRITE_LINE(11, 14322) = Acc;
	Acc = -LINE(7, 9108, 1034) / 4 + LINE(6, 8072, 1456) / 2;
	WRITE_LINE(6, 8072) = -Acc;
	Acc = -Acc / 2 + LINE(6, 8072, 1456);
	WRITE_LINE(5, 6614) = Acc;
	Acc = -LINE(5, 6614, 1483) / 4 + LINE(4, 5129, 1385) / 2;
	WRITE_LINE(4, 5129) = -Acc;
	Acc = Acc * -3 / 4 + LINE(4, 5129, 1385) * 3 / 2;
	tmp_1 = Acc;
	*out_left = tmp_5;
	Acc = LINE(1, 3736, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 3736) = Acc;
	Acc = LINE(1, 3736, 1) + tmp_b;
	WRITE_LINE(7, 9108) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 10: .6 Sec MEDIUM DARK */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_10(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(11, 14322, 123) / 4 + -LINE(9, 11770, 987) / 4 + -LINE(5, 6614, 678) / 4 + -LINE(14, 16182, 142) / 4;
	tmp_5 = -Acc;
	Acc = -LINE(11, 14322, 503) / 4 + -LINE(9, 11770, 342) / 4 + -LINE(5, 6614, 301) / 4 + -LINE(13, 15982, 620) / 4;
	tmp_3 = -Acc;
	Acc = LINE(3, 3742, 1) * 3 / 4 + LINE(0, 0, 100) / 2;
	WRITE_LINE(3, 3742) = Acc;
	Acc = LINE(15, 16282, 98) * 5 / 8 + LINE(3, 3742, 1) / 2;
	WRITE_LINE(15, 16282) = -Acc;
	Acc = LINE(14, 16182, 198) * 5 / 8 + LINE(15, 16282, 0) * 5 / 8 + LINE(15, 16282, 98);
	WRITE_LINE(14, 16182) = -Acc;
	Acc = LINE(13, 15982, 367) * 5 / 8 + LINE(14, 16182, 0) * 5 / 8 + LINE(14, 16182, 198);
	WRITE_LINE(13, 15982) = -Acc;
	Acc = LINE(13, 15982, 0) * 5 / 8 + LINE(13, 15982, 367) + LINE(12, 15113, 789) / 2;
	WRITE_LINE(12, 15113) = -Acc;
	Acc = Acc * -27 / 16 + LINE(12, 15113, 789) * 27 / 8;
	tmp_b = Acc;
	Acc = -LINE(11, 14322, 1203) / 4 + LINE(10, 13117, 1345) / 2;
	WRITE_LINE(10, 13117) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13117, 1345);
	WRITE_LINE(9, 11770) = Acc;
	Acc = -LINE(9, 11770, 1369) / 4 + LINE(8, 10399, 1289) / 2;
	WRITE_LINE(8, 10399) = -Acc;
	Acc = Acc * -3 / 4 + LINE(8, 10399, 1289) * 3 / 2;
	tmp_1 = Acc;
	Acc = LINE(2, 3739, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(2, 3739) = Acc;
	Acc = LINE(2, 3739, 1) + tmp_b;
	WRITE_LINE(11, 14322) = Acc;
	Acc = -LINE(7, 9108, 1034) / 4 + LINE(6, 8072, 1456) / 2;
	WRITE_LINE(6, 8072) = -Acc;
	Acc = -Acc / 2 + LINE(6, 8072, 1456);
	WRITE_LINE(5, 6614) = Acc;
	Acc = -LINE(5, 6614, 1483) / 4 + LINE(4, 5129, 1385) / 2;
	WRITE_LINE(4, 5129) = -Acc;
	Acc = Acc * -3 / 4 + LINE(4, 5129, 1385) * 3 / 2;
	tmp_1 = Acc;
	*out_left = tmp_5;
	Acc = LINE(1, 3736, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 3736) = Acc;
	Acc = LINE(1, 3736, 1) + tmp_b;
	WRITE_LINE(7, 9108) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 11: .8 Sec SMALL BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_11(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(10, 15645, 64) / 4 + -LINE(8, 14468, 496) / 4 + -LINE(4, 11789, 339) / 4 + -LINE(11, 16230, 24) / 4;
	tmp_5 = -Acc;
	Acc = -LINE(10, 15645, 403) / 4 + -LINE(8, 14468, 167) / 4 + -LINE(4, 11789, 151) / 4 + -LINE(11, 16230, 357) / 4;
	tmp_3 = -Acc;
	Acc = LINE(13, 16381, 58) * 5 / 8 + LINE(0, 0, 1) / 2;
	WRITE_LINE(13, 16381) = -Acc;
	Acc = LINE(12, 16321, 89) * 5 / 8 + LINE(13, 16381, 0) * 5 / 8 + LINE(13, 16381, 58);
	WRITE_LINE(12, 16321) = -Acc;
	Acc = LINE(11, 16230, 183) * 5 / 8 + LINE(12, 16321, 0) * 5 / 8 + LINE(12, 16321, 89);
	WRITE_LINE(11, 16230) = -Acc;
	Acc = -LINE(11, 16230, 0) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + LINE(11, 16230, 0) / 2 + LINE(11, 16230, 183) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = LINE(10, 15645, 701) * 5 / 8 + LINE(9, 14942, 472) / 2;
	WRITE_LINE(9, 14942) = -Acc;
	Acc = -Acc / 2 + LINE(9, 14942, 472);
	WRITE_LINE(8, 14468) = Acc;
	Acc = LINE(8, 14468, 783) * 5 / 8 + LINE(7, 13683, 634) / 2;
	WRITE_LINE(7, 13683) = -Acc;
	Acc = Acc * -3 / 4 + LINE(7, 13683, 634) * 3 / 2;
	tmp_1 = Acc;
	Acc = LINE(2, 10560, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(2, 10560) = Acc;
	Acc = LINE(2, 10560, 1) + tmp_b;
	WRITE_LINE(10, 15645) = Acc;
	Acc = LINE(6, 13047, 617) * 5 / 8 + LINE(5, 12428, 637) / 2;
	WRITE_LINE(5, 12428) = -Acc;
	Acc = -Acc / 2 + LINE(5, 12428, 637);
	WRITE_LINE(4, 11789) = Acc;
	Acc = LINE(4, 11789, 567) * 5 / 8 + LINE(3, 11220, 655) / 2;
	WRITE_LINE(3, 11220) = -Acc;
	*out_left = tmp_5;
	Acc = Acc * -3 / 4 + LINE(3, 11220, 655) * 3 / 2;
	tmp_1 = Acc;
	Acc = LINE(1, 10557, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 10557) = Acc;
	Acc = LINE(1, 10557, 1) + tmp_b;
	WRITE_LINE(6, 13047) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 12: .8 Sec LARGE WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_12(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 13241, 21) / 2 + LINE(6, 9821, 1591) / 2 + LINE(4, 5436, 1203) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = LINE(8, 13241, 801) / 2 + LINE(6, 9821, 890) / 2 + LINE(4, 5436, 671) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
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
	tmp_2 = Acc;
	Acc = -LINE(8, 13241, 1424) / 4 + LINE(7, 11815, 1992) / 2;
	WRITE_LINE(7, 11815) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11815, 1992) + LINE(1, 760, 1) / 2;
	WRITE_LINE(1, 760) = Acc;
	Acc = LINE(1, 760, 0);
	WRITE_LINE(6, 9821) = Acc;
	Acc = -LINE(6, 9821, 2010) / 4 + LINE(5, 7809, 2371) / 2;
	WRITE_LINE(5, 7809) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7809, 2371);
	WRITE_LINE(4, 5436) = Acc;
	Acc = -LINE(4, 5436, 2057) / 4 + LINE(3, 3377, 2612) / 2;
	WRITE_LINE(3, 3377) = -Acc;
	Acc = -Acc / 2 + LINE(3, 3377, 2612) + tmp_2;
	WRITE_LINE(8, 13241) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 13: 1.0 Sec SMALL WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_13(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(11, 15785, 64) / 4 + -LINE(9, 14908, 496) / 4 + -LINE(5, 12759, 339) / 4 + -LINE(12, 16230, 24) / 4;
	tmp_5 = -Acc;
	Acc = -LINE(11, 15785, 403) / 4 + -LINE(9, 14908, 167) / 4 + -LINE(5, 12759, 151) / 4 + -LINE(12, 16230, 357) / 4;
	tmp_3 = -Acc;
	Acc = LINE(3, 11503, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(3, 11503) = Acc;
	Acc = LINE(14, 16381, 58) * 5 / 8 + LINE(3, 11503, 1) / 2;
	WRITE_LINE(14, 16381) = -Acc;
	Acc = LINE(13, 16321, 89) * 5 / 8 + LINE(14, 16381, 0) * 5 / 8 + LINE(14, 16381, 58);
	WRITE_LINE(13, 16321) = -Acc;
	Acc = LINE(12, 16230, 183) * 5 / 8 + LINE(13, 16321, 0) * 5 / 8 + LINE(13, 16321, 89);
	WRITE_LINE(12, 16230) = -Acc;
	Acc = -LINE(12, 16230, 0) / 4;
	tmp_1 = -Acc;
	Acc = -Acc / 2 + LINE(12, 16230, 0) / 2 + LINE(12, 16230, 183) + tmp_1 / 2;
	tmp_1 = -Acc;
	Acc = Acc * -27 / 16 + tmp_1 * 27 / 8;
	tmp_b = Acc;
	Acc = LINE(11, 15785, 501) * 3 / 4 + LINE(10, 15282, 372) / 2;
	WRITE_LINE(10, 15282) = -Acc;
	Acc = -Acc / 2 + LINE(10, 15282, 372);
	WRITE_LINE(9, 14908) = Acc;
	Acc = LINE(9, 14908, 683) * 3 / 4 + LINE(8, 14223, 534) / 2;
	WRITE_LINE(8, 14223) = -Acc;
	Acc = Acc * -3 / 4 + LINE(8, 14223, 534) * 3 / 2;
	tmp_1 = Acc;
	Acc = LINE(2, 11500, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(2, 11500) = Acc;
	Acc = LINE(2, 11500, 1) + tmp_b;
	WRITE_LINE(11, 15785) = Acc;
	Acc = LINE(7, 13687, 417) * 3 / 4 + LINE(6, 13268, 507) / 2;
	WRITE_LINE(6, 13268) = -Acc;
	Acc = -Acc / 2 + LINE(6, 13268, 507);
	WRITE_LINE(5, 12759) = Acc;
	Acc = LINE(5, 12759, 697) * 3 / 4 + LINE(4, 12060, 555) / 2;
	WRITE_LINE(4, 12060) = -Acc;
	Acc = Acc * -3 / 4 + LINE(4, 12060, 555) * 3 / 2;
	tmp_1 = Acc;
	*out_left = tmp_5;
	Acc = LINE(1, 11497, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 11497) = Acc;
	Acc = LINE(1, 11497, 1) + tmp_b;
	WRITE_LINE(7, 13687) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 14: 1.0 Sec MEDIUM WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_14(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(11, 14236, 123) / 2 + LINE(9, 11884, 987) / 2 + LINE(5, 6908, 678) / 2 + LINE(14, 16182, 142) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = LINE(11, 14236, 803) / 2 + LINE(9, 11884, 342) / 2 + LINE(5, 6908, 301) / 2 + LINE(13, 15982, 620) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
	Acc = LINE(3, 3836, 1) / 2 + LINE(0, 0, 100) / 2;
	WRITE_LINE(3, 3836) = Acc;
	Acc = LINE(15, 16282, 98) * 5 / 8 + LINE(3, 3836, 1) / 2;
	WRITE_LINE(15, 16282) = -Acc;
	Acc = LINE(14, 16182, 198) * 5 / 8 + LINE(15, 16282, 0) * 5 / 8 + LINE(15, 16282, 98);
	WRITE_LINE(14, 16182) = -Acc;
	Acc = LINE(13, 15982, 367) * 5 / 8 + LINE(14, 16182, 0) * 5 / 8 + LINE(14, 16182, 198);
	WRITE_LINE(13, 15982) = -Acc;
	Acc = LINE(13, 15982, 0) * 5 / 8 + LINE(13, 15982, 367) + LINE(12, 15113, 875) / 2;
	WRITE_LINE(12, 15113) = -Acc;
	Acc = Acc * -27 / 16 + LINE(12, 15113, 875) * 27 / 8;
	tmp_b = Acc;
	Acc = LINE(11, 14236, 1203) / 2 + LINE(10, 13031, 1145) / 2;
	WRITE_LINE(10, 13031) = -Acc;
	Acc = -Acc / 2 + LINE(10, 13031, 1145);
	WRITE_LINE(9, 11884) = Acc;
	Acc = LINE(9, 11884, 1569) / 2 + LINE(8, 10313, 1339) / 2;
	WRITE_LINE(8, 10313) = -Acc;
	Acc = Acc * -3 / 4 + LINE(8, 10313, 1339) * 3 / 2;
	tmp_1 = Acc;
	Acc = LINE(2, 3833, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(2, 3833) = Acc;
	Acc = LINE(2, 3833, 1) + tmp_b;
	WRITE_LINE(11, 14236) = Acc;
	Acc = LINE(7, 8972, 1004) / 2 + LINE(6, 7966, 1056) / 2;
	WRITE_LINE(6, 7966) = -Acc;
	Acc = -Acc / 2 + LINE(6, 7966, 1056);
	WRITE_LINE(5, 6908) = Acc;
	Acc = LINE(5, 6908, 1683) / 2 + LINE(4, 5223, 1385) / 2;
	WRITE_LINE(4, 5223) = -Acc;
	Acc = Acc * -3 / 4 + LINE(4, 5223, 1385) * 3 / 2;
	tmp_1 = Acc;
	*out_left = tmp_5;
	Acc = LINE(1, 3830, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 3830) = Acc;
	Acc = LINE(1, 3830, 1) + tmp_b;
	WRITE_LINE(7, 8972) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 15: 1.0 Sec LARGE BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_15(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(10, 13855, 123) / 4 + -LINE(8, 11303, 987) / 4 + -LINE(4, 5447, 678) / 4 + -LINE(13, 16182, 142) / 4;
	tmp_5 = -Acc;
	Acc = -LINE(10, 13855, 803) / 4 + -LINE(8, 11303, 342) / 4 + -LINE(4, 5447, 301) / 4 + -LINE(12, 15982, 620) / 4;
	tmp_3 = -Acc;
	Acc = LINE(14, 16282, 98) * 5 / 8 + LINE(0, 0, 100) / 2;
	WRITE_LINE(14, 16282) = -Acc;
	Acc = LINE(13, 16182, 198) * 5 / 8 + LINE(14, 16282, 0) * 5 / 8 + LINE(14, 16282, 98);
	WRITE_LINE(13, 16182) = -Acc;
	Acc = LINE(12, 15982, 367) * 5 / 8 + LINE(13, 16182, 0) * 5 / 8 + LINE(13, 16182, 198);
	WRITE_LINE(12, 15982) = -Acc;
	Acc = LINE(12, 15982, 0) * 5 / 8 + LINE(12, 15982, 367) + LINE(11, 15113, 1256) / 2;
	WRITE_LINE(11, 15113) = -Acc;
	Acc = Acc * -27 / 16 + LINE(11, 15113, 1256) * 27 / 8;
	tmp_b = Acc;
	Acc = LINE(10, 13855, 1203) + LINE(9, 12650, 1345) / 2;
	WRITE_LINE(9, 12650) = -Acc;
	Acc = -Acc / 2 + LINE(9, 12650, 1345);
	WRITE_LINE(8, 11303) = Acc;
	Acc = -LINE(8, 11303, 1569) / 4 + LINE(7, 9732, 1789) / 2;
	WRITE_LINE(7, 9732) = -Acc;
	Acc = Acc * -3 / 4 + LINE(7, 9732, 1789) * 3 / 2;
	tmp_1 = Acc;
	Acc = LINE(2, 1672, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(2, 1672) = Acc;
	Acc = LINE(2, 1672, 1) + tmp_b;
	WRITE_LINE(10, 13855) = Acc;
	Acc = LINE(6, 7941, 1034) + LINE(5, 6905, 1456) / 2;
	WRITE_LINE(5, 6905) = -Acc;
	Acc = -Acc / 2 + LINE(5, 6905, 1456);
	WRITE_LINE(4, 5447) = Acc;
	Acc = -LINE(4, 5447, 1983) / 4 + LINE(3, 3462, 1785) / 2;
	WRITE_LINE(3, 3462) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 3462, 1785) * 3 / 2;
	tmp_1 = Acc;
	Acc = LINE(1, 1669, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 1669) = Acc;
	*out_left = tmp_5;
	Acc = LINE(1, 1669, 1) + tmp_b;
	WRITE_LINE(6, 7941) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 16: 1.2 Sec MEDIUM WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_16(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(11, 14124, 123) / 4 + -LINE(9, 11572, 987) / 4 + -LINE(5, 5716, 678) / 4 + -LINE(14, 16182, 142) / 4;
	tmp_5 = -Acc;
	Acc = -LINE(11, 14124, 803) / 4 + -LINE(9, 11572, 342) / 4 + -LINE(5, 5716, 301) / 4 + -LINE(13, 15982, 620) / 4;
	tmp_3 = -Acc;
	Acc = LINE(3, 1944, 1) / 2 + LINE(0, 0, 100) / 2;
	WRITE_LINE(3, 1944) = Acc;
	Acc = LINE(15, 16282, 98) * 5 / 8 + LINE(3, 1944, 0) / 2;
	WRITE_LINE(15, 16282) = -Acc;
	Acc = LINE(14, 16182, 198) * 5 / 8 + LINE(15, 16282, 0) * 5 / 8 + LINE(15, 16282, 98);
	WRITE_LINE(14, 16182) = -Acc;
	Acc = LINE(13, 15982, 367) * 5 / 8 + LINE(14, 16182, 0) * 5 / 8 + LINE(14, 16182, 198);
	WRITE_LINE(13, 15982) = -Acc;
	Acc = LINE(13, 15982, 0) * 5 / 8 + LINE(13, 15982, 367) + LINE(12, 15113, 987) / 2;
	WRITE_LINE(12, 15113) = -Acc;
	Acc = Acc * -27 / 16 + LINE(12, 15113, 987) * 27 / 8;
	tmp_b = Acc;
	Acc = LINE(11, 14124, 1203) * 3 / 4 + LINE(10, 12919, 1345) / 2;
	WRITE_LINE(10, 12919) = -Acc;
	Acc = -Acc / 2 + LINE(10, 12919, 1345);
	WRITE_LINE(9, 11572) = Acc;
	Acc = LINE(9, 11572, 1569) / 2 + LINE(8, 10001, 1789) / 2;
	WRITE_LINE(8, 10001) = -Acc;
	Acc = Acc * -3 / 4 + LINE(8, 10001, 1789) * 3 / 2;
	tmp_1 = Acc;
	Acc = LINE(2, 1941, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(2, 1941) = Acc;
	Acc = LINE(2, 1941, 1) + tmp_b;
	WRITE_LINE(11, 14124) = Acc;
	Acc = LINE(7, 8210, 1034) * 3 / 4 + LINE(6, 7174, 1456) / 2;
	WRITE_LINE(6, 7174) = -Acc;
	Acc = -Acc / 2 + LINE(6, 7174, 1456);
	WRITE_LINE(5, 5716) = Acc;
	Acc = LINE(5, 5716, 1983) / 2 + LINE(4, 3731, 1785) / 2;
	WRITE_LINE(4, 3731) = -Acc;
	Acc = Acc * -3 / 4 + LINE(4, 3731, 1785) * 3 / 2;
	tmp_1 = Acc;
	*out_left = tmp_5;
	Acc = LINE(1, 1938, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 1938) = Acc;
	Acc = LINE(1, 1938, 1) + tmp_b;
	WRITE_LINE(7, 8210) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 17: 1.2 Sec SMALL WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_17(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(11, 15084, 12) / 4 + -LINE(9, 13237, 987) / 4 + -LINE(7, 10675, 978) / 4 + -LINE(5, 8381, 745) / 4;
	tmp_5 = -Acc;
	Acc = -LINE(11, 15084, 523) / 4 + -LINE(9, 13237, 342) / 4 + -LINE(7, 10675, 12) / 4 + -LINE(5, 8381, 301) / 4;
	tmp_3 = -Acc;
	Acc = LINE(3, 6209, 1) / 2 + LINE(0, 0, 100) / 2;
	WRITE_LINE(3, 6209) = Acc;
	Acc = LINE(14, 16282, 78) * 5 / 8 + LINE(3, 6209, 1) / 2;
	WRITE_LINE(14, 16282) = -Acc;
	Acc = LINE(13, 16202, 147) * 5 / 8 + LINE(14, 16282, 0) * 5 / 8 + LINE(14, 16282, 78);
	WRITE_LINE(13, 16202) = -Acc;
	Acc = LINE(12, 16053, 367) * 5 / 8 + LINE(13, 16202, 0) * 5 / 8 + LINE(13, 16202, 147);
	WRITE_LINE(12, 16053) = -Acc;
	Acc = LINE(12, 16053, 0) * 135 / 64 + LINE(12, 16053, 367) * 27 / 8;
	tmp_b = Acc;
	Acc = LINE(11, 15084, 798) * 3 / 4 + LINE(10, 14284, 1045) / 2;
	WRITE_LINE(10, 14284) = -Acc;
	Acc = -Acc / 2 + LINE(10, 14284, 1045);
	WRITE_LINE(9, 13237) = Acc;
	Acc = LINE(9, 13237, 1269) * 3 / 4 + LINE(8, 11966, 1289) / 2;
	WRITE_LINE(8, 11966) = -Acc;
	Acc = Acc * -3 / 4 + LINE(8, 11966, 1289) * 3 / 2;
	tmp_1 = Acc;
	Acc = LINE(2, 6206, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(2, 6206) = Acc;
	Acc = LINE(2, 6206, 1) + tmp_b;
	WRITE_LINE(11, 15084) = Acc;
	Acc = LINE(7, 10675, 1034) * 3 / 4 + LINE(6, 9639, 1256) / 2;
	WRITE_LINE(6, 9639) = -Acc;
	Acc = -Acc / 2 + LINE(6, 9639, 1256);
	WRITE_LINE(5, 8381) = Acc;
	Acc = LINE(5, 8381, 1183) * 3 / 4 + LINE(4, 7196, 985) / 2;
	WRITE_LINE(4, 7196) = -Acc;
	Acc = Acc * -3 / 4 + LINE(4, 7196, 985) * 3 / 2;
	tmp_1 = Acc;
	Acc = LINE(1, 6203, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 6203) = Acc;
	*out_left = tmp_5;
	Acc = LINE(1, 6203, 1) + tmp_b;
	WRITE_LINE(7, 10675) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 18: 1.2 Sec SMALL BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_18(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_3, tmp_5, tmp_b;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(10, 15084, 12) / 4 + -LINE(8, 13237, 987) / 4 + -LINE(6, 10675, 978) / 4 + -LINE(4, 8381, 745) / 4;
	tmp_5 = -Acc;
	Acc = -LINE(10, 15084, 523) / 4 + -LINE(8, 13237, 342) / 4 + -LINE(6, 10675, 12) / 4 + -LINE(4, 8381, 301) / 4;
	tmp_3 = -Acc;
	Acc = LINE(13, 16282, 78) * 5 / 8 + LINE(0, 0, 100) / 2;
	WRITE_LINE(13, 16282) = -Acc;
	Acc = LINE(12, 16202, 147) * 5 / 8 + LINE(13, 16282, 0) * 5 / 8 + LINE(13, 16282, 78);
	WRITE_LINE(12, 16202) = -Acc;
	Acc = LINE(11, 16053, 367) * 5 / 8 + LINE(12, 16202, 0) * 5 / 8 + LINE(12, 16202, 147);
	WRITE_LINE(11, 16053) = -Acc;
	Acc = LINE(11, 16053, 0) * 135 / 64 + LINE(11, 16053, 367) * 27 / 8;
	tmp_b = Acc;
	Acc = LINE(10, 15084, 798) * 3 / 4 + LINE(9, 14284, 1045) / 2;
	WRITE_LINE(9, 14284) = -Acc;
	Acc = -Acc / 2 + LINE(9, 14284, 1045);
	WRITE_LINE(8, 13237) = Acc;
	Acc = LINE(8, 13237, 1269) * 3 / 4 + LINE(7, 11966, 1289) / 2;
	WRITE_LINE(7, 11966) = -Acc;
	Acc = Acc * -3 / 4 + LINE(7, 11966, 1289) * 3 / 2;
	tmp_1 = Acc;
	Acc = LINE(2, 6206, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(2, 6206) = Acc;
	Acc = LINE(2, 6206, 1) + tmp_b;
	WRITE_LINE(10, 15084) = Acc;
	Acc = LINE(6, 10675, 1034) * 3 / 4 + LINE(5, 9639, 1256) / 2;
	WRITE_LINE(5, 9639) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9639, 1256);
	WRITE_LINE(4, 8381) = Acc;
	Acc = LINE(4, 8381, 1183) * 3 / 4 + LINE(3, 7196, 985) / 2;
	WRITE_LINE(3, 7196) = -Acc;
	Acc = Acc * -3 / 4 + LINE(3, 7196, 985) * 3 / 2;
	tmp_1 = Acc;
	Acc = LINE(1, 6203, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 6203) = Acc;
	*out_left = tmp_5;
	Acc = LINE(1, 6203, 1) + tmp_b;
	WRITE_LINE(6, 10675) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 19: 1.4 Sec LARGE WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_19(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 13793, 211) / 4 + -LINE(6, 10473, 1391) / 4 + -LINE(4, 6488, 1403) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 13793, 1101) / 4 + -LINE(6, 10473, 690) / 4 + -LINE(4, 6488, 471) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = -Acc;
	Acc = -Acc / 2 + LINE(1, 2412, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 2412) = Acc;
	Acc = LINE(1, 2412, 0) + tmp_2;
	WRITE_LINE(8, 13793) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 20: 1.4 Sec LARGE DARK */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_20(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12941, 211) / 4 + -LINE(6, 9021, 1391) / 4 + -LINE(4, 4636, 1403) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 12941, 1101) / 4 + -LINE(6, 9021, 690) / 4 + -LINE(4, 4636, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 360, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 360) = Acc;
	Acc = LINE(1, 360, 0) + tmp_2;
	WRITE_LINE(8, 12941) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 21: 1.4 Sec MEDIUM WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_21(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 13306, 21) / 2 + LINE(6, 10886, 1391) / 2 + LINE(4, 7601, 1503) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_5 = Acc;
	Acc = LINE(8, 13306, 876) / 2 + LINE(6, 10886, 890) / 2 + LINE(4, 7601, 671) / 2;
	tmp_1 = Acc;
	Acc = tmp_1 / 2;
	tmp_3 = Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 3725, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 3725) = Acc;
	Acc = LINE(1, 3725, 0) + tmp_2;
	WRITE_LINE(8, 13306) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 22: 1.6 Sec SMALL DARK */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_22(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 14810, 11) / 4 + -LINE(6, 13099, 796) / 4 + -LINE(4, 10902, 1001) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 14810, 11) / 4 + -LINE(6, 13099, 445) / 4 + -LINE(4, 10902, 336) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 8561, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 8561) = Acc;
	Acc = LINE(1, 8561, 0) + tmp_2;
	WRITE_LINE(8, 14810) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 23: 1.6 Sec LARGE BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_23(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 13409, 21) / 4 + -LINE(5, 10389, 1491) / 4 + -LINE(3, 6804, 1703) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(7, 13409, 876) / 4 + -LINE(5, 10389, 390) / 4 + -LINE(3, 6804, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 2228, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 2228) = Acc;
	Acc = LINE(1, 2228, 0) + tmp_2;
	WRITE_LINE(7, 13409) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 24: 1.6 Sec MEDIUM BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_24(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12841, 21) / 4 + -LINE(5, 9821, 1491) / 4 + -LINE(3, 6236, 1703) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(7, 12841, 876) / 4 + -LINE(5, 9821, 890) / 4 + -LINE(3, 6236, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 1660, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 1660) = Acc;
	Acc = LINE(1, 1660, 0) + tmp_2;
	WRITE_LINE(7, 12841) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 25: 1.8 Sec LARGE DARK */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_25(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12941, 211) / 4 + -LINE(6, 9221, 1591) / 4 + -LINE(4, 4836, 1403) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 12941, 1101) / 4 + -LINE(6, 9221, 890) / 4 + -LINE(4, 4836, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 360, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 360) = Acc;
	Acc = LINE(1, 360, 0) + tmp_2;
	WRITE_LINE(8, 12941) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 26: 1.8 Sec LARGE BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_26(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12941, 211) / 4 + -LINE(5, 9221, 1591) / 4 + -LINE(3, 4836, 1403) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(7, 12941, 1101) / 4 + -LINE(5, 9221, 890) / 4 + -LINE(3, 4836, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 360, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 360) = Acc;
	Acc = LINE(1, 360, 0) + tmp_2;
	WRITE_LINE(7, 12941) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 27: 1.8 Sec MEDIUM WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_27(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12741, 21) / 4 + -LINE(6, 9621, 1491) / 4 + -LINE(4, 5536, 1703) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 12741, 876) / 4 + -LINE(6, 9621, 890) / 4 + -LINE(4, 5536, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 960, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 960) = Acc;
	Acc = LINE(1, 960, 0) + tmp_2;
	WRITE_LINE(8, 12741) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 28: 2.0 Sec LARGE BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_28(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12941, 211) / 4 + -LINE(5, 9721, 1591) / 4 + -LINE(3, 5336, 403) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(7, 12941, 801) / 4 + -LINE(5, 9721, 890) / 4 + -LINE(3, 5336, 1234) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 360, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 360) = Acc;
	Acc = LINE(1, 360, 0) + tmp_2;
	WRITE_LINE(7, 12941) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 29: 2.0 Sec MEDIUM WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_29(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9421, 1891) / 4 + -LINE(4, 5136, 1403) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 12641, 789) / 4 + -LINE(6, 9421, 890) / 4 + -LINE(4, 5136, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 660, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 660) = Acc;
	Acc = LINE(1, 660, 0) + tmp_2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 30: 2.0 Sec LARGE WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_30(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 13241, 21) / 4 + -LINE(6, 9821, 1591) / 4 + -LINE(4, 5436, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 13241, 801) / 4 + -LINE(6, 9821, 890) / 4 + -LINE(4, 5436, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 760, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 760) = Acc;
	Acc = LINE(1, 760, 0) + tmp_2;
	WRITE_LINE(8, 13241) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 31: 2.5 Sec MEDIUM WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_31(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9021, 1891) / 4 + -LINE(4, 4536, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 12641, 1010) / 4 + -LINE(6, 9021, 890) / 4 + -LINE(4, 4536, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = LINE(1, 60, 0) + tmp_2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 32: 2.5 Sec LARGE BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_32(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 13241, 21) / 4 + -LINE(5, 9621, 1591) / 4 + -LINE(3, 5036, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(7, 13241, 801) / 4 + -LINE(5, 9621, 890) / 4 + -LINE(3, 5036, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 160, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 160) = Acc;
	Acc = LINE(1, 160, 0) + tmp_2;
	WRITE_LINE(7, 13241) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 33: 2.5 Sec MEDIUM DARK */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_33(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 13241, 21) / 4 + -LINE(6, 9821, 1591) / 4 + -LINE(4, 5436, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 13241, 801) / 4 + -LINE(6, 9821, 890) / 4 + -LINE(4, 5436, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 760, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 760) = Acc;
	Acc = LINE(1, 760, 0) + tmp_2;
	WRITE_LINE(8, 13241) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 34: 2.8 Sec SMALL BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_34(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 14377, 21) / 4 + -LINE(4, 10748, 79) / 4 + -LINE(3, 8945, 1356) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(7, 14377, 501) / 4 + -LINE(5, 12060, 890) / 4 + -LINE(3, 8945, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 5905, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 5905) = Acc;
	Acc = LINE(1, 5905, 0) + tmp_2;
	WRITE_LINE(7, 14377) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 35: 2.8 Sec MEDIUM BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_35(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12641, 21) / 4 + -LINE(5, 9621, 1691) / 4 + -LINE(3, 5836, 1903) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(7, 12641, 801) / 4 + -LINE(5, 9621, 890) / 4 + -LINE(3, 5836, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 1560, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 1560) = Acc;
	Acc = LINE(1, 1560, 0) + tmp_2;
	WRITE_LINE(7, 12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 36: 3.0 Sec LARGE BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_36(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12641, 21) / 4 + -LINE(5, 9021, 1891) / 4 + -LINE(3, 4536, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(7, 12641, 1010) / 4 + -LINE(5, 9021, 890) / 4 + -LINE(3, 4536, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = LINE(1, 60, 0) + tmp_2;
	WRITE_LINE(7, 12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 37: 3.0 Sec LARGE WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_37(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9021, 1891) / 4 + -LINE(4, 4536, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 12641, 1010) / 4 + -LINE(6, 9021, 890) / 4 + -LINE(4, 4536, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = LINE(1, 60, 0) + tmp_2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 38: 3.0 Sec MEDIUM DARK */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_38(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 13441, 21) / 4 + -LINE(6, 9821, 1591) / 4 + -LINE(4, 5736, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 13441, 801) / 4 + -LINE(6, 9821, 890) / 4 + -LINE(4, 5736, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 760, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 760) = Acc;
	Acc = LINE(1, 760, 0) + tmp_2;
	WRITE_LINE(8, 13441) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 39: 3.5 Sec LARGE BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_39(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12641, 21) / 4 + -LINE(5, 9021, 1891) / 4 + -LINE(3, 4536, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(7, 12641, 801) / 4 + -LINE(5, 9021, 890) / 4 + -LINE(3, 4536, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = LINE(1, 60, 0) + tmp_2;
	WRITE_LINE(7, 12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 40: 3.5 Sec MEDIUM WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_40(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9021, 1891) / 4 + -LINE(4, 4536, 1703) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 12641, 901) / 4 + -LINE(6, 9021, 990) / 4 + -LINE(4, 4536, 571) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = LINE(1, 60, 0) + tmp_2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 41: 4.0 Sec LARGE DARK */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_41(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9021, 1891) / 4 + -LINE(4, 4536, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 12641, 1010) / 4 + -LINE(6, 9021, 890) / 4 + -LINE(4, 4536, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 60, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = LINE(1, 60, 0) + tmp_2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 42: 4.0 Sec MEDIUM BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_42(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12641, 21) / 4 + -LINE(5, 9021, 1891) / 4 + -LINE(3, 4536, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(7, 12641, 801) / 4 + -LINE(5, 9021, 890) / 4 + -LINE(3, 4536, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = LINE(1, 60, 0) + tmp_2;
	WRITE_LINE(7, 12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 43: 5 Sec LARGE WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_43(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9321, 1891) / 4 + -LINE(4, 4836, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 12641, 1010) / 4 + -LINE(6, 9321, 890) / 4 + -LINE(4, 4836, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = LINE(1, 60, 0) + tmp_2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 44: 8 Sec LARGE BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_44(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12641, 21) / 4 + -LINE(5, 9021, 1891) / 4 + -LINE(3, 4536, 1703) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(7, 12641, 901) / 4 + -LINE(5, 9021, 990) / 4 + -LINE(3, 4536, 571) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = LINE(1, 60, 0) + tmp_2;
	WRITE_LINE(7, 12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 45: 8 Sec LARGE WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_45(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9021, 1891) / 4 + -LINE(4, 4536, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 12641, 1010) / 4 + -LINE(6, 9021, 890) / 4 + -LINE(4, 4536, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 60, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 60) = Acc;
	Acc = LINE(1, 60, 0) + tmp_2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 46: 10 Sec LARGE BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_46(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 12641, 21) / 4 + -LINE(5, 9021, 1891) / 4 + -LINE(3, 4536, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(7, 12641, 1010) / 4 + -LINE(5, 9021, 890) / 4 + -LINE(3, 4536, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 63, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 63) = Acc;
	Acc = LINE(1, 63, 0) + tmp_2;
	WRITE_LINE(7, 12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 47: 10 Sec LARGE WARM */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_47(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12641, 21) / 4 + -LINE(6, 9021, 1591) / 4 + -LINE(4, 4436, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 12641, 812) / 4 + -LINE(6, 9021, 890) / 4 + -LINE(4, 4436, 871) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 90, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 90) = Acc;
	Acc = LINE(1, 90, 0) + tmp_2;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 48: 16 Sec LARGE DARK */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_48(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 12665, 21) / 4 + -LINE(6, 9345, 1591) / 4 + -LINE(4, 5360, 1403) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 12665, 1010) / 4 + -LINE(6, 9345, 890) / 4 + -LINE(4, 5360, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	Acc = LINE(1, 784, 0) + tmp_2;
	WRITE_LINE(8, 12665) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 49: 18 Sec EX. LARGE BRIGHT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_49(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_1, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(7, 13033, 21) / 4 + -LINE(5, 9413, 1891) / 4 + -LINE(3, 4928, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(7, 13033, 1010) / 4 + -LINE(5, 9413, 890) / 4 + -LINE(3, 4928, 671) / 4;
	tmp_5 = -Acc;
	Acc = LINE(0, 0, 1) * 81 / 32 + LINE(11, 16381, 321) / 2;
	WRITE_LINE(11, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(11, 16381, 321) + LINE(10, 16058, 431) / 2;
	WRITE_LINE(10, 16058) = -Acc;
	Acc = -Acc / 2 + LINE(10, 16058, 431) + LINE(9, 15625, 968) / 2;
	WRITE_LINE(9, 15625) = -Acc;
	Acc = -Acc / 2 + LINE(9, 15625, 968) + LINE(8, 14655, 1620) / 2;
	WRITE_LINE(8, 14655) = -Acc;
	Acc = -Acc / 2 + LINE(8, 14655, 1620);
	tmp_2 = Acc;
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
	tmp_1 = Acc;
	Acc = LINE(1, 55, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(1, 55) = Acc;
	Acc = LINE(1, 55, 0) + tmp_2;
	WRITE_LINE(7, 13033) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 50: 20 Sec EX. LARGE DARK */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_50(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_2, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(8, 13033, 21) / 4 + -LINE(6, 9413, 1891) / 4 + -LINE(4, 4928, 2003) / 4;
	tmp_3 = -Acc;
	Acc = -LINE(8, 13033, 1010) / 4 + -LINE(6, 9413, 890) / 4 + -LINE(4, 4928, 671) / 4;
	tmp_5 = -Acc;
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
	tmp_2 = Acc;
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
	Acc = LINE(1, 52, 0) + tmp_2;
	WRITE_LINE(8, 13033) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 51: Gated 100 MS */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_51(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_5;
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
	tmp_5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
/* Effect 52: Gated 150 MS */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_52(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_5;
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
	tmp_5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
/* Effect 53: Gated 200 MS */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_53(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_5;
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
	tmp_5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2 + LINE(0, 0, 3725) / 2 + LINE(0, 0, 3889) / 2 + LINE(0, 0, 4034) / 2 + LINE(0, 0, 4152) / 2 + LINE(0, 0, 4257) / 2 + LINE(0, 0, 4492) / 2 + LINE(0, 0, 4556) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
/* Effect 54: Gated 250 MS */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_54(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_5;
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
	tmp_5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2 + LINE(0, 0, 3725) / 2 + LINE(0, 0, 3889) / 2 + LINE(0, 0, 4034) / 2 + LINE(0, 0, 4152) / 2 + LINE(0, 0, 4257) / 2 + LINE(0, 0, 4492) / 2 + LINE(0, 0, 4556) / 2 + LINE(0, 0, 4727) / 2 + LINE(0, 0, 4849) / 2 + LINE(0, 0, 5034) / 2 + LINE(0, 0, 5129) / 2 + LINE(0, 0, 5235) / 2 + LINE(0, 0, 5421) / 2 + LINE(0, 0, 5534) / 2 + LINE(0, 0, 5759) / 2 + LINE(0, 0, 5837) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
/* Effect 55: Gated 300 MS */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_55(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_5;
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
	tmp_5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2 + LINE(0, 0, 3725) / 2 + LINE(0, 0, 3889) / 2 + LINE(0, 0, 4034) / 2 + LINE(0, 0, 4152) / 2 + LINE(0, 0, 4257) / 2 + LINE(0, 0, 4492) / 2 + LINE(0, 0, 4556) / 2 + LINE(0, 0, 4727) / 2 + LINE(0, 0, 4849) / 2 + LINE(0, 0, 5034) / 2 + LINE(0, 0, 5129) / 2 + LINE(0, 0, 5235) / 2 + LINE(0, 0, 5421) / 2 + LINE(0, 0, 5534) / 2 + LINE(0, 0, 5759) / 2 + LINE(0, 0, 5837) / 2 + LINE(0, 0, 6035) / 2 + LINE(0, 0, 6159) / 2 + LINE(0, 0, 6223) / 2 + LINE(0, 0, 6446) / 2 + LINE(0, 0, 6534) / 2 + LINE(0, 0, 6782) / 2 + LINE(0, 0, 6859) / 2 + LINE(0, 0, 7039) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
/* Effect 56: Gated 350 MS */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_56(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_5;
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
	tmp_5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2 + LINE(0, 0, 3725) / 2 + LINE(0, 0, 3889) / 2 + LINE(0, 0, 4034) / 2 + LINE(0, 0, 4152) / 2 + LINE(0, 0, 4257) / 2 + LINE(0, 0, 4492) / 2 + LINE(0, 0, 4556) / 2 + LINE(0, 0, 4727) / 2 + LINE(0, 0, 4849) / 2 + LINE(0, 0, 5034) / 2 + LINE(0, 0, 5129) / 2 + LINE(0, 0, 5235) / 2 + LINE(0, 0, 5421) / 2 + LINE(0, 0, 5534) / 2 + LINE(0, 0, 5759) / 2 + LINE(0, 0, 5837) / 2 + LINE(0, 0, 6035) / 2 + LINE(0, 0, 6159) / 2 + LINE(0, 0, 6223) / 2 + LINE(0, 0, 6446) / 2 + LINE(0, 0, 6534) / 2 + LINE(0, 0, 6782) / 2 + LINE(0, 0, 6859) / 2 + LINE(0, 0, 7039) / 2 + LINE(0, 0, 7126) / 2 + LINE(0, 0, 7221) / 2 + LINE(0, 0, 7439) / 2 + LINE(0, 0, 7534) / 2 + LINE(0, 0, 7736) / 2 + LINE(0, 0, 7891) / 2 + LINE(0, 0, 8034) / 2 + LINE(0, 0, 8146) / 2 + LINE(0, 0, 8278) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
/* Effect 57: Gated 400 MS */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_57(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_5;
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
	tmp_5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2 + LINE(0, 0, 3725) / 2 + LINE(0, 0, 3889) / 2 + LINE(0, 0, 4034) / 2 + LINE(0, 0, 4152) / 2 + LINE(0, 0, 4257) / 2 + LINE(0, 0, 4492) / 2 + LINE(0, 0, 4556) / 2 + LINE(0, 0, 4727) / 2 + LINE(0, 0, 4849) / 2 + LINE(0, 0, 5034) / 2 + LINE(0, 0, 5129) / 2 + LINE(0, 0, 5235) / 2 + LINE(0, 0, 5421) / 2 + LINE(0, 0, 5534) / 2 + LINE(0, 0, 5759) / 2 + LINE(0, 0, 5837) / 2 + LINE(0, 0, 6035) / 2 + LINE(0, 0, 6159) / 2 + LINE(0, 0, 6223) / 2 + LINE(0, 0, 6446) / 2 + LINE(0, 0, 6534) / 2 + LINE(0, 0, 6782) / 2 + LINE(0, 0, 6859) / 2 + LINE(0, 0, 7039) / 2 + LINE(0, 0, 7126) / 2 + LINE(0, 0, 7221) / 2 + LINE(0, 0, 7439) / 2 + LINE(0, 0, 7534) / 2 + LINE(0, 0, 7736) / 2 + LINE(0, 0, 7891) / 2 + LINE(0, 0, 8034) / 2 + LINE(0, 0, 8146) / 2 + LINE(0, 0, 8278) / 2 + LINE(0, 0, 8447) / 2 + LINE(0, 0, 8565) / 2 + LINE(0, 0, 8700) / 2 + LINE(0, 0, 8885) / 2 + LINE(0, 0, 9012) / 2 + LINE(0, 0, 9171) / 2 + LINE(0, 0, 9215) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
/* Effect 58: Gated 500 MS */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_58(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_5;
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
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2 + LINE(0, 0, 3725) / 2 + LINE(0, 0, 3889) / 2 + LINE(0, 0, 4034) / 2 + LINE(0, 0, 4152) / 2 + LINE(0, 0, 4257) / 2 + LINE(0, 0, 4492) / 2 + LINE(0, 0, 4556) / 2 + LINE(0, 0, 4727) / 2 + LINE(0, 0, 4849) / 2 + LINE(0, 0, 5034) / 2 + LINE(0, 0, 5129) / 2 + LINE(0, 0, 5235) / 2 + LINE(0, 0, 5421) / 2 + LINE(0, 0, 5534) / 2 + LINE(0, 0, 5759) / 2 + LINE(0, 0, 5837) / 2 + LINE(0, 0, 6035) / 2 + LINE(0, 0, 6159) / 2 + LINE(0, 0, 6223) / 2 + LINE(0, 0, 6446) / 2 + LINE(0, 0, 6534) / 2 + LINE(0, 0, 6782) / 2 + LINE(0, 0, 6859) / 2 + LINE(0, 0, 7039) / 2 + LINE(0, 0, 7126) / 2 + LINE(0, 0, 7221) / 2 + LINE(0, 0, 7439) / 2 + LINE(0, 0, 7534) / 2 + LINE(0, 0, 7736) / 2 + LINE(0, 0, 7891) / 2 + LINE(0, 0, 8034) / 2 + LINE(0, 0, 8146) / 2 + LINE(0, 0, 8278) / 2 + LINE(0, 0, 8447) / 2 + LINE(0, 0, 8565) / 2 + LINE(0, 0, 8700) / 2 + LINE(0, 0, 8885) / 2 + LINE(0, 0, 9012) / 2 + LINE(0, 0, 9171) / 2 + LINE(0, 0, 9215) / 2 + LINE(0, 0, 9449) / 2 + LINE(0, 0, 9513) / 2 + LINE(0, 0, 9765) / 2 + LINE(0, 0, 9867) / 2 + LINE(0, 0, 10046) / 2 + LINE(0, 0, 10110) / 2 + LINE(0, 0, 10285) / 2 + LINE(0, 0, 10428) / 2 + LINE(0, 0, 10578) / 2 + LINE(0, 0, 10734) / 2 + LINE(0, 0, 10815) / 2 + LINE(0, 0, 11023) / 2 + LINE(0, 0, 11185) / 2 + LINE(0, 0, 11254) / 2 + LINE(0, 0, 11479) / 2;
	WRITE_LINE(2, 11) = Acc;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
/* Effect 59: Gated 600 MS */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_59(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_5;
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
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(0, 0, 1065) / 2 + LINE(0, 0, 1119) / 2 + LINE(0, 0, 1233) / 2 + LINE(0, 0, 1434) / 2 + LINE(0, 0, 1555) / 2 + LINE(0, 0, 1742) / 2 + LINE(0, 0, 1862) / 2 + LINE(0, 0, 2046) / 2 + LINE(0, 0, 2149) / 2 + LINE(0, 0, 2256) / 2 + LINE(0, 0, 2443) / 2 + LINE(0, 0, 2579) / 2 + LINE(0, 0, 2721) / 2 + LINE(0, 0, 2873) / 2 + LINE(0, 0, 3036) / 2 + LINE(0, 0, 3121) / 2 + LINE(0, 0, 3267) / 2 + LINE(0, 0, 3451) / 2 + LINE(0, 0, 3569) / 2 + LINE(0, 0, 3725) / 2 + LINE(0, 0, 3889) / 2 + LINE(0, 0, 4034) / 2 + LINE(0, 0, 4152) / 2 + LINE(0, 0, 4257) / 2 + LINE(0, 0, 4492) / 2 + LINE(0, 0, 4556) / 2 + LINE(0, 0, 4727) / 2 + LINE(0, 0, 4849) / 2 + LINE(0, 0, 5034) / 2 + LINE(0, 0, 5129) / 2 + LINE(0, 0, 5235) / 2 + LINE(0, 0, 5421) / 2 + LINE(0, 0, 5534) / 2 + LINE(0, 0, 5759) / 2 + LINE(0, 0, 5837) / 2 + LINE(0, 0, 6035) / 2 + LINE(0, 0, 6159) / 2 + LINE(0, 0, 6223) / 2 + LINE(0, 0, 6446) / 2 + LINE(0, 0, 6534) / 2 + LINE(0, 0, 6782) / 2 + LINE(0, 0, 6859) / 2 + LINE(0, 0, 7039) / 2 + LINE(0, 0, 7126) / 2 + LINE(0, 0, 7221) / 2 + LINE(0, 0, 7439) / 2 + LINE(0, 0, 7534) / 2 + LINE(0, 0, 7736) / 2 + LINE(0, 0, 7891) / 2 + LINE(0, 0, 8034) / 2 + LINE(0, 0, 8146) / 2 + LINE(0, 0, 8278) / 2 + LINE(0, 0, 8447) / 2 + LINE(0, 0, 8565) / 2 + LINE(0, 0, 8700) / 2 + LINE(0, 0, 8885) / 2 + LINE(0, 0, 9012) / 2 + LINE(0, 0, 9171) / 2 + LINE(0, 0, 9215) / 2 + LINE(0, 0, 9449) / 2 + LINE(0, 0, 9513) / 2 + LINE(0, 0, 9765) / 2 + LINE(0, 0, 9867) / 2 + LINE(0, 0, 10046) / 2 + LINE(0, 0, 10110) / 2 + LINE(0, 0, 10285) / 2 + LINE(0, 0, 10428) / 2 + LINE(0, 0, 10578) / 2 + LINE(0, 0, 10734) / 2 + LINE(0, 0, 10815) / 2 + LINE(0, 0, 11023) / 2 + LINE(0, 0, 11185) / 2 + LINE(0, 0, 11254) / 2 + LINE(0, 0, 11479) / 2 + LINE(0, 0, 11546) / 2 + LINE(0, 0, 11715) / 2 + LINE(0, 0, 11847) / 2 + LINE(0, 0, 12074) / 2 + LINE(0, 0, 12112) / 2 + LINE(0, 0, 12279) / 2 + LINE(0, 0, 12415) / 2 + LINE(0, 0, 12516) / 2 + LINE(0, 0, 12746) / 2 + LINE(0, 0, 12815) / 2 + LINE(0, 0, 13046) / 2;
	WRITE_LINE(2, 11) = Acc;
}
#undef LINE
#undef WRITE_LINE
/* Effect 60: REVERSE - 300 MS */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_60(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(7, 2298, 21) / 2;
	WRITE_LINE(7, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2298, 21) + LINE(6, 2275, 53) / 2;
	WRITE_LINE(6, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2275, 53) + LINE(5, 2220, 173) / 2;
	WRITE_LINE(5, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2220, 173) + LINE(0, 0, 7031);
	tmp_3 = Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(4, 2045, 32) / 2;
	WRITE_LINE(4, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2045, 32) + LINE(3, 2011, 75) / 2;
	WRITE_LINE(3, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2011, 75) + LINE(2, 1934, 133) / 2;
	WRITE_LINE(2, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1934, 133) + LINE(0, 0, 7031);
	tmp_5 = Acc;
	Acc = LINE(0, 0, 163) / 32 + LINE(0, 0, 233) / 32 + LINE(0, 0, 412) / 32 + LINE(0, 0, 534) / 32 + LINE(0, 0, 761) / 32 + LINE(0, 0, 875) / 32 + LINE(0, 0, 1434) / 32 + LINE(0, 0, 1119) / 32 + LINE(0, 0, 1862) / 32 + -LINE(0, 0, 1065) / 16 + -LINE(0, 0, 1555) / 16 + -LINE(0, 0, 1742) / 16 + -LINE(0, 0, 1233) / 16 + -LINE(0, 0, 2046) / 16 + -LINE(0, 0, 2149) / 16 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 2443) / 16 + -LINE(0, 0, 3121) / 16 + -LINE(0, 0, 2721) / 16 + LINE(0, 0, 2256) / 8 + LINE(0, 0, 3036) / 8 + LINE(0, 0, 2579) / 8 + LINE(0, 0, 3267) / 8 + LINE(0, 0, 3451) / 8 + LINE(0, 0, 3569) / 8 + LINE(0, 0, 4492) / 8 + LINE(0, 0, 3889) / 8 + LINE(0, 0, 4034) / 8 + LINE(0, 0, 4152) / 8 + LINE(0, 0, 4849) / 8 + -LINE(0, 0, 3725) / 4 + -LINE(0, 0, 4556) / 4 + -LINE(0, 0, 4727) / 4 + -LINE(0, 0, 4257) / 4 + -LINE(0, 0, 5034) / 4 + -LINE(0, 0, 5837) / 4 + -LINE(0, 0, 5235) / 4 + -LINE(0, 0, 5421) / 4 + -LINE(0, 0, 6159) / 4 + LINE(0, 0, 5759) / 2 + LINE(0, 0, 5129) / 2 + LINE(0, 0, 6035) / 2 + LINE(0, 0, 5534) / 2 + LINE(0, 0, 6223) / 2 + LINE(0, 0, 6446) / 2;
	WRITE_LINE(1, 11) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 61: REVERSE - 400 MS */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_61(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(7, 2298, 21) / 2;
	WRITE_LINE(7, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2298, 21) + LINE(6, 2275, 53) / 2;
	WRITE_LINE(6, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2275, 53) + LINE(5, 2220, 173) / 2;
	WRITE_LINE(5, 2220) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2220, 173) + LINE(0, 0, 9375);
	tmp_3 = Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(4, 2045, 32) / 2;
	WRITE_LINE(4, 2045) = -Acc;
	Acc = -Acc / 2 + LINE(4, 2045, 32) + LINE(3, 2011, 75) / 2;
	WRITE_LINE(3, 2011) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2011, 75) + LINE(2, 1934, 133) / 2;
	WRITE_LINE(2, 1934) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1934, 133) + LINE(0, 0, 9375);
	tmp_5 = Acc;
	*out_left = tmp_5;
	Acc = LINE(0, 0, 163) / 32 + LINE(0, 0, 233) / 32 + LINE(0, 0, 412) / 32 + LINE(0, 0, 534) / 32 + LINE(0, 0, 761) / 32 + LINE(0, 0, 875) / 32 + LINE(0, 0, 2721) / 32 + LINE(0, 0, 1119) / 32 + LINE(0, 0, 1233) / 32 + LINE(0, 0, 1434) / 32 + LINE(0, 0, 2443) / 32 + LINE(0, 0, 1742) / 32 + LINE(0, 0, 1862) / 32 + -LINE(0, 0, 2046) / 16 + -LINE(0, 0, 2149) / 16 + -LINE(0, 0, 2256) / 16 + -LINE(0, 0, 1555) / 16 + -LINE(0, 0, 2579) / 16 + -LINE(0, 0, 1065) / 16 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 3036) / 16 + -LINE(0, 0, 4152) / 16 + -LINE(0, 0, 3267) / 16 + -LINE(0, 0, 3451) / 16 + -LINE(0, 0, 4492) / 16 + -LINE(0, 0, 3725) / 16 + LINE(0, 0, 3889) / 8 + LINE(0, 0, 4034) / 8 + LINE(0, 0, 3121) / 8 + LINE(0, 0, 4257) / 8 + LINE(0, 0, 3569) / 8 + LINE(0, 0, 4556) / 8 + LINE(0, 0, 4727) / 8 + LINE(0, 0, 4849) / 8 + LINE(0, 0, 5837) / 8 + LINE(0, 0, 5129) / 8 + LINE(0, 0, 5235) / 8 + LINE(0, 0, 5421) / 8 + LINE(0, 0, 6159) / 8 + -LINE(0, 0, 5759) / 4 + -LINE(0, 0, 5034) / 4 + -LINE(0, 0, 6035) / 4 + -LINE(0, 0, 5534) / 4 + -LINE(0, 0, 6223) / 4 + -LINE(0, 0, 6446) / 4 + -LINE(0, 0, 6534) / 4 + -LINE(0, 0, 8034) / 4 + -LINE(0, 0, 6859) / 4 + -LINE(0, 0, 7039) / 4 + -LINE(0, 0, 7736) / 4 + -LINE(0, 0, 7221) / 4 + -LINE(0, 0, 7439) / 4 + LINE(0, 0, 7534) / 2 + LINE(0, 0, 7126) / 2 + LINE(0, 0, 7891) / 2 + LINE(0, 0, 6782) / 2 + LINE(0, 0, 8146) / 2 + LINE(0, 0, 8278) / 2 + LINE(0, 0, 8447) / 2 + LINE(0, 0, 8565) / 2 + LINE(0, 0, 8700) / 2;
	WRITE_LINE(1, 11) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
/* Effect 62: REVERSE - 500 MS */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_62(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
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
/* Effect 63: REVERSE - 600 MS */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_63(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
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
/* Effect 64: DEFEAT */
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midiverb_effect_64(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc;
	*out_left = LINE(0, 140, 135);
	*out_right = LINE(0, 140, 137);
	Acc = 0;
	WRITE_LINE(0, 140) = -Acc;
}
#undef LINE
#undef WRITE_LINE
void (*midiverb_effects[])(int16_t input, int16_t *out_left, int16_t *out_right, int16_t *DRAM, int ptr, uint32_t lfo1_value, uint32_t lfo2_value) = {
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
