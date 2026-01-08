#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_1(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_5;
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
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_2(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_d;
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
	tmp_d = Acc;
	Acc = tmp_d + LINE(4, 3173, 36) / 2;
	WRITE_LINE(4, 3173) = -Acc;
	Acc = -Acc / 2 + LINE(4, 3173, 36);
	WRITE_LINE(2, 6) = -Acc;
	Acc = tmp_d + LINE(3, 3135, 30) / 2;
	WRITE_LINE(3, 3135) = -Acc;
	Acc = -Acc / 2 + LINE(3, 3135, 30);
	WRITE_LINE(1, 4) = -Acc;
	*out_left = LINE(2, 6, 1);
	*out_right = LINE(1, 4, 1);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_3(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(3, 6080, 1);
	tmp_5 = Acc;
	Acc = LINE(3, 6080, 1);
	tmp_3 = Acc;
	Acc = LINE(4, 6083, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(0, 0, 10299) / 8 + tmp_1;
	WRITE_LINE(4, 6083) = Acc;
	Acc = LINE(4, 6083, 1);
	tmp_1 = -Acc;
	Acc = LINE(0, 0, 10299) + tmp_1;
	WRITE_LINE(1, 6074) = Acc;
	Acc = LINE(2, 6077, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(1, 6074, 1) / 8 + tmp_1;
	WRITE_LINE(2, 6077) = Acc;
	Acc = LINE(2, 6077, 1);
	tmp_1 = -Acc;
	Acc = LINE(1, 6074, 1) + tmp_1;
	WRITE_LINE(3, 6080) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_4(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1cd0, tmp_1;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(5, 7379, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(0, 0, 9003) / 8 + tmp_1;
	WRITE_LINE(5, 7379) = Acc;
	Acc = LINE(5, 7379, 1);
	tmp_1 = -Acc;
	Acc = LINE(0, 0, 9003) + tmp_1;
	WRITE_LINE(3, 7355) = Acc;
	Acc = LINE(4, 7373, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(3, 7355, 1) / 8 + tmp_1;
	WRITE_LINE(4, 7373) = Acc;
	Acc = LINE(4, 7373, 1);
	tmp_1 = -Acc;
	Acc = LINE(3, 7355, 1) + tmp_1;
	tmp_1cd0 = Acc;
	Acc = tmp_1cd0;
	WRITE_LINE(1, 4) = Acc;
	Acc = tmp_1cd0;
	WRITE_LINE(2, 201) = Acc;
	*out_left = LINE(2, 201, 196);
	*out_right = LINE(1, 4, 1);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_5(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(9, 16381, 8424) + LINE(5, 7608, 41) / 2;
	WRITE_LINE(5, 7608) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7608, 41) + LINE(4, 7565, 195) / 2;
	WRITE_LINE(4, 7565) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7565, 195) + LINE(3, 7368, 63) / 2;
	WRITE_LINE(3, 7368) = -Acc;
	Acc = -Acc / 2 + LINE(3, 7368, 63);
	tmp_5 = Acc;
	Acc = LINE(9, 16381, 8424) + LINE(8, 7955, 49) / 2;
	WRITE_LINE(8, 7955) = -Acc;
	Acc = -Acc / 2 + LINE(8, 7955, 49) + LINE(7, 7904, 114) / 2;
	WRITE_LINE(7, 7904) = -Acc;
	Acc = -Acc / 2 + LINE(7, 7904, 114) + LINE(6, 7788, 178) / 2;
	WRITE_LINE(6, 7788) = -Acc;
	Acc = -Acc / 2 + LINE(6, 7788, 178);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 7303, 1) / 2;
	WRITE_LINE(2, 7303) = Acc;
	Acc = LINE(1, 7300, 1) * 0.9375;
	tmp_1 = Acc;
	Acc = Acc * -0.1875 + LINE(2, 7303, 1) / 8 + tmp_1;
	WRITE_LINE(1, 7300) = Acc;
	Acc = LINE(1, 7300, 1);
	tmp_1 = -Acc;
	Acc = LINE(2, 7303, 1) * 1.5 + tmp_1 * 1.5;
	WRITE_LINE(9, 16381) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_6(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(23, 16381, 7722) * 1.5 + LINE(22, 8657, 15) / 2;
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
	Acc = LINE(23, 16381, 7722) * 1.5 + LINE(13, 7778, 17) / 2;
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
	Acc = LINE(4, 6832, 1) * 0.375;
	tmp_1 = Acc;
	Acc = LINE(0, 0, 1) * 0.625 + tmp_1;
	WRITE_LINE(4, 6832) = Acc;
	*out_left = LINE(2, 601, 596);
	Acc = LINE(3, 6826, 1) * 0.625;
	tmp_1 = Acc;
	Acc = LINE(4, 6832, 1) * 0.375 + tmp_1;
	WRITE_LINE(3, 6826) = Acc;
	Acc = LINE(3, 6826, 1);
	WRITE_LINE(23, 16381) = Acc;
	*out_right = LINE(1, 4, 1);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_7(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_5;
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
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_8(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 7566, 600) / 8 + -LINE(2, 7569, 1) / 2;
	tmp_3 = Acc;
	Acc = LINE(2, 7569, 1) / 8 + -LINE(1, 7566, 600) / 2;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 6698) * 1.5 + LINE(20, 9394, 15) / 2;
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
	Acc = LINE(0, 0, 6698) * 1.5 + LINE(11, 8561, 17) / 2;
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
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_9(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 16381, 6328) + LINE(6, 9704, 41) / 2;
	WRITE_LINE(6, 9704) = -Acc;
	Acc = -Acc / 2 + LINE(6, 9704, 41) + LINE(5, 9661, 195) / 2;
	WRITE_LINE(5, 9661) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9661, 195) + LINE(4, 9464, 63) / 2;
	WRITE_LINE(4, 9464) = -Acc;
	Acc = -Acc / 2 + LINE(4, 9464, 63);
	tmp_5 = Acc;
	Acc = LINE(10, 16381, 6328) + LINE(9, 10051, 49) / 2;
	WRITE_LINE(9, 10051) = -Acc;
	Acc = -Acc / 2 + LINE(9, 10051, 49) + LINE(8, 10000, 114) / 2;
	WRITE_LINE(8, 10000) = -Acc;
	Acc = -Acc / 2 + LINE(8, 10000, 114) + LINE(7, 9884, 178) / 2;
	WRITE_LINE(7, 9884) = -Acc;
	Acc = -Acc / 2 + LINE(7, 9884, 178);
	tmp_3 = Acc;
	Acc = LINE(3, 9399, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(0, 0, 1) / 8 + tmp_1;
	WRITE_LINE(3, 9399) = Acc;
	Acc = LINE(3, 9399, 1);
	tmp_1 = -Acc;
	Acc = LINE(0, 0, 1) + tmp_1;
	WRITE_LINE(1, 9384) = Acc;
	Acc = LINE(2, 9393, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(1, 9384, 1) / 8 + tmp_1;
	WRITE_LINE(2, 9393) = Acc;
	Acc = LINE(2, 9393, 1);
	tmp_1 = -Acc;
	Acc = LINE(1, 9384, 1) + tmp_1;
	WRITE_LINE(10, 16381) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_10(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(9, 16381, 5625) + LINE(5, 10407, 41) / 2;
	WRITE_LINE(5, 10407) = -Acc;
	Acc = -Acc / 2 + LINE(5, 10407, 41) + LINE(4, 10364, 195) / 2;
	WRITE_LINE(4, 10364) = -Acc;
	Acc = -Acc / 2 + LINE(4, 10364, 195) + LINE(3, 10167, 63) / 2;
	WRITE_LINE(3, 10167) = -Acc;
	Acc = -Acc / 2 + LINE(3, 10167, 63);
	tmp_5 = Acc;
	Acc = LINE(9, 16381, 5625) + LINE(8, 10754, 49) / 2;
	WRITE_LINE(8, 10754) = -Acc;
	Acc = -Acc / 2 + LINE(8, 10754, 49) + LINE(7, 10703, 114) / 2;
	WRITE_LINE(7, 10703) = -Acc;
	Acc = -Acc / 2 + LINE(7, 10703, 114) + LINE(6, 10587, 178) / 2;
	WRITE_LINE(6, 10587) = -Acc;
	Acc = -Acc / 2 + LINE(6, 10587, 178);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 10102, 1) / 2;
	WRITE_LINE(2, 10102) = Acc;
	Acc = LINE(1, 10099, 1) * 0.9375;
	tmp_1 = Acc;
	Acc = Acc * -0.1875 + LINE(2, 10102, 1) / 8 + tmp_1;
	WRITE_LINE(1, 10099) = Acc;
	Acc = LINE(1, 10099, 1);
	tmp_1 = -Acc;
	Acc = LINE(2, 10102, 1) + tmp_1;
	WRITE_LINE(9, 16381) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_11(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(9, 16381, 5156) + LINE(5, 10876, 41) / 2;
	WRITE_LINE(5, 10876) = -Acc;
	Acc = -Acc / 2 + LINE(5, 10876, 41) + LINE(4, 10833, 195) / 2;
	WRITE_LINE(4, 10833) = -Acc;
	Acc = -Acc / 2 + LINE(4, 10833, 195) + LINE(3, 10636, 63) / 2;
	WRITE_LINE(3, 10636) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 10636, 63) * 1.5;
	tmp_5 = Acc;
	Acc = LINE(9, 16381, 5156) + LINE(8, 11223, 49) / 2;
	WRITE_LINE(8, 11223) = -Acc;
	Acc = -Acc / 2 + LINE(8, 11223, 49) + LINE(7, 11172, 114) / 2;
	WRITE_LINE(7, 11172) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11172, 114) + LINE(6, 11056, 178) / 2;
	WRITE_LINE(6, 11056) = -Acc;
	Acc = Acc * -0.75 + LINE(6, 11056, 178) * 1.5;
	tmp_3 = Acc;
	Acc = LINE(2, 10571, 1) * 0.375;
	tmp_1 = Acc;
	Acc = LINE(0, 0, 1) * 0.625 + tmp_1;
	WRITE_LINE(2, 10571) = Acc;
	Acc = LINE(1, 10568, 1) * 0.625;
	tmp_1 = Acc;
	Acc = LINE(2, 10571, 1) * 0.375 + tmp_1;
	WRITE_LINE(1, 10568) = Acc;
	Acc = LINE(1, 10568, 1);
	WRITE_LINE(9, 16381) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_12(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 9855, 1);
	tmp_3 = Acc;
	Acc = LINE(1, 9852, 600);
	tmp_5 = Acc;
	Acc = LINE(23, 16381, 4687) * 1.5 + LINE(22, 11692, 15) / 2;
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
	Acc = LINE(23, 16381, 4687) * 1.5 + LINE(13, 10813, 17) / 2;
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
	Acc = LINE(4, 9867, 1) * 0.375;
	tmp_1 = Acc;
	*out_left = tmp_5;
	Acc = LINE(0, 0, 1) * 0.625 + tmp_1;
	WRITE_LINE(4, 9867) = Acc;
	Acc = LINE(3, 9861, 1) * 0.625;
	tmp_1 = Acc;
	Acc = LINE(4, 9867, 1) * 0.375 + tmp_1;
	WRITE_LINE(3, 9861) = Acc;
	*out_right = tmp_3;
	Acc = LINE(3, 9861, 1);
	WRITE_LINE(23, 16381) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_13(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_d;
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
	tmp_d = Acc;
	Acc = tmp_d + LINE(4, 10223, 36) / 2;
	WRITE_LINE(4, 10223) = -Acc;
	Acc = -Acc / 2 + LINE(4, 10223, 36);
	WRITE_LINE(2, 6) = -Acc;
	Acc = tmp_d + LINE(3, 10185, 30) / 2;
	WRITE_LINE(3, 10185) = -Acc;
	Acc = -Acc / 2 + LINE(3, 10185, 30);
	WRITE_LINE(1, 4) = -Acc;
	*out_left = LINE(2, 6, 1);
	*out_right = LINE(1, 4, 1);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_14(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 3753);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 3753);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_15(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(9, 16381, 3515) + LINE(5, 9174, 41) / 2;
	WRITE_LINE(5, 9174) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9174, 41) + LINE(4, 9131, 195) / 2;
	WRITE_LINE(4, 9131) = -Acc;
	Acc = -Acc / 2 + LINE(4, 9131, 195) + LINE(3, 8934, 63) / 2;
	WRITE_LINE(3, 8934) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 8934, 63) * 1.5;
	tmp_5 = Acc;
	Acc = LINE(9, 16381, 3515) + LINE(8, 9521, 49) / 2;
	WRITE_LINE(8, 9521) = -Acc;
	Acc = -Acc / 2 + LINE(8, 9521, 49) + LINE(7, 9470, 114) / 2;
	WRITE_LINE(7, 9470) = -Acc;
	Acc = -Acc / 2 + LINE(7, 9470, 114) + LINE(6, 9354, 178) / 2;
	WRITE_LINE(6, 9354) = -Acc;
	Acc = Acc * -0.75 + LINE(6, 9354, 178) * 1.5;
	tmp_3 = Acc;
	Acc = LINE(2, 8869, 1) * 0.375;
	tmp_1 = Acc;
	Acc = LINE(0, 0, 1) * 0.625 + tmp_1;
	WRITE_LINE(2, 8869) = Acc;
	Acc = LINE(1, 8866, 1) * 0.625;
	tmp_1 = Acc;
	Acc = LINE(2, 8869, 1) * 0.375 + tmp_1;
	WRITE_LINE(1, 8866) = Acc;
	Acc = LINE(1, 8866, 1);
	WRITE_LINE(9, 16381) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_16(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1;
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
	Acc = LINE(5, 12446, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(0, 0, 1) / 8 + tmp_1;
	WRITE_LINE(5, 12446) = Acc;
	Acc = LINE(5, 12446, 1);
	tmp_1 = -Acc;
	Acc = LINE(0, 0, 1) + tmp_1;
	WRITE_LINE(3, 12431) = Acc;
	Acc = LINE(4, 12443, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(3, 12431, 1) / 8 + tmp_1;
	WRITE_LINE(4, 12443) = Acc;
	Acc = LINE(4, 12443, 1);
	tmp_1 = -Acc;
	Acc = LINE(3, 12431, 1) + tmp_1;
	WRITE_LINE(12, 16381) = Acc;
	*out_left = LINE(2, 6, 1);
	*out_right = LINE(1, 4, 1);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_17(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(9, 16381, 3046) + LINE(5, 12986, 41) / 2;
	WRITE_LINE(5, 12986) = -Acc;
	Acc = -Acc / 2 + LINE(5, 12986, 41) + LINE(4, 12943, 195) / 2;
	WRITE_LINE(4, 12943) = -Acc;
	Acc = -Acc / 2 + LINE(4, 12943, 195) + LINE(3, 12746, 63) / 2;
	WRITE_LINE(3, 12746) = -Acc;
	Acc = -Acc / 2 + LINE(3, 12746, 63);
	tmp_5 = Acc;
	Acc = LINE(9, 16381, 3046) + LINE(8, 13333, 49) / 2;
	WRITE_LINE(8, 13333) = -Acc;
	Acc = -Acc / 2 + LINE(8, 13333, 49) + LINE(7, 13282, 114) / 2;
	WRITE_LINE(7, 13282) = -Acc;
	Acc = -Acc / 2 + LINE(7, 13282, 114) + LINE(6, 13166, 178) / 2;
	WRITE_LINE(6, 13166) = -Acc;
	Acc = -Acc / 2 + LINE(6, 13166, 178);
	tmp_3 = Acc;
	Acc = LINE(0, 0, 1) / 2 + LINE(2, 12681, 1) / 2;
	WRITE_LINE(2, 12681) = Acc;
	Acc = LINE(1, 12678, 1) * 0.9375;
	tmp_1 = Acc;
	Acc = Acc * -0.1875 + LINE(2, 12681, 1) / 8 + tmp_1;
	WRITE_LINE(1, 12678) = Acc;
	Acc = LINE(1, 12678, 1);
	tmp_1 = -Acc;
	Acc = LINE(2, 12681, 1) * 1.5 + tmp_1 * 1.5;
	WRITE_LINE(9, 16381) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_18(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 2815);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 2815);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_19(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(1, 11684, 1) / 4 + LINE(2, 11687, 1);
	tmp_3 = Acc;
	Acc = -LINE(2, 11687, 1) / 4 + LINE(1, 11684, 1);
	tmp_5 = Acc;
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
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_20(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 2346);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 2346);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_21(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(1, 13597, 1) / 4 + LINE(2, 13600, 1);
	tmp_3 = Acc;
	Acc = -LINE(2, 13600, 1) / 4 + LINE(1, 13597, 1);
	tmp_5 = Acc;
	Acc = LINE(19, 16381, 2109) * 1.5 + LINE(18, 14229, 29) / 2;
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
	Acc = LINE(19, 16381, 2109) * 1.5 + LINE(11, 13923, 35) / 2;
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
	Acc = LINE(3, 13609, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(4, 13612, 1) / 8 + tmp_1;
	WRITE_LINE(3, 13609) = Acc;
	Acc = LINE(3, 13609, 1);
	tmp_1 = -Acc;
	*out_left = tmp_5;
	Acc = LINE(4, 13612, 1) * 1.5 + tmp_1 * 1.5;
	WRITE_LINE(19, 16381) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_22(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 15705) / 2 + LINE(0, 0, 7853) + LINE(4, 330, 41) / 2;
	WRITE_LINE(4, 330) = -Acc;
	Acc = -Acc / 2 + LINE(4, 330, 41) + LINE(3, 287, 195) / 2;
	WRITE_LINE(3, 287) = -Acc;
	Acc = -Acc / 2 + LINE(3, 287, 195) + LINE(2, 90, 63) / 2;
	WRITE_LINE(2, 90) = -Acc;
	Acc = -Acc / 2 + LINE(2, 90, 63);
	tmp_5 = Acc;
	Acc = LINE(0, 0, 15705) / 2 + LINE(0, 0, 7853) + LINE(7, 677, 49) / 2;
	WRITE_LINE(7, 677) = -Acc;
	Acc = -Acc / 2 + LINE(7, 677, 49) + LINE(6, 626, 114) / 2;
	WRITE_LINE(6, 626) = -Acc;
	Acc = -Acc / 2 + LINE(6, 626, 114) + LINE(5, 510, 178) / 2;
	WRITE_LINE(5, 510) = -Acc;
	Acc = -Acc / 2 + LINE(5, 510, 178);
	WRITE_LINE(1, 3) = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_23(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(11, 16381, 6093) / 2 + LINE(10, 10286, 6093) / 2 + LINE(6, 3844, 41) / 2;
	WRITE_LINE(6, 3844) = -Acc;
	Acc = -Acc / 2 + LINE(6, 3844, 41) + LINE(5, 3801, 195) / 2;
	WRITE_LINE(5, 3801) = -Acc;
	Acc = -Acc / 2 + LINE(5, 3801, 195) + LINE(4, 3604, 63) / 2;
	WRITE_LINE(4, 3604) = -Acc;
	Acc = -Acc / 2 + LINE(4, 3604, 63);
	tmp_5 = Acc;
	Acc = tmp_5 * 0.65625;
	tmp_5 = Acc;
	Acc = LINE(11, 16381, 6093) / 2 + LINE(10, 10286, 6093) / 2 + LINE(9, 4191, 49) / 2;
	WRITE_LINE(9, 4191) = -Acc;
	Acc = -Acc / 2 + LINE(9, 4191, 49) + LINE(8, 4140, 114) / 2;
	WRITE_LINE(8, 4140) = -Acc;
	Acc = -Acc / 2 + LINE(8, 4140, 114) + LINE(7, 4024, 178) / 2;
	WRITE_LINE(7, 4024) = -Acc;
	Acc = -Acc / 2 + LINE(7, 4024, 178);
	tmp_3 = Acc;
	Acc = tmp_3 * 0.65625;
	tmp_3 = Acc;
	Acc = LINE(3, 3539, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(0, 0, 1) / 8 + tmp_1;
	WRITE_LINE(3, 3539) = Acc;
	Acc = LINE(3, 3539, 1);
	tmp_1 = -Acc;
	Acc = LINE(0, 0, 1) * 1.5 + tmp_1 * 1.5;
	WRITE_LINE(11, 16381) = Acc;
	Acc = LINE(2, 3536, 1) * 0.8125;
	tmp_1 = Acc;
	Acc = LINE(11, 16381, 6093) * 0.1875 + tmp_1;
	WRITE_LINE(2, 3536) = Acc;
	Acc = LINE(2, 3536, 1);
	tmp_1 = -Acc;
	Acc = LINE(11, 16381, 6093) * 1.5 + tmp_1 * 1.5;
	WRITE_LINE(10, 10286) = Acc;
	Acc = LINE(1, 3533, 1) / 4;
	tmp_1 = Acc;
	*out_left = tmp_5;
	Acc = LINE(1, 3533, 7) * 0.75 + tmp_1;
	WRITE_LINE(1, 3533) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_24(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(12, 16381, 5390) / 2 + LINE(11, 10989, 5390) / 2 + LINE(7, 5250, 41) / 2;
	WRITE_LINE(7, 5250) = -Acc;
	Acc = -Acc / 2 + LINE(7, 5250, 41) + LINE(6, 5207, 195) / 2;
	WRITE_LINE(6, 5207) = -Acc;
	Acc = -Acc / 2 + LINE(6, 5207, 195) + LINE(5, 5010, 63) / 2;
	WRITE_LINE(5, 5010) = -Acc;
	Acc = Acc * -0.75 + LINE(5, 5010, 63) * 1.5;
	tmp_5 = Acc;
	Acc = LINE(12, 16381, 5390) / 2 + LINE(11, 10989, 5390) / 2 + LINE(10, 5597, 49) / 2;
	WRITE_LINE(10, 5597) = -Acc;
	Acc = -Acc / 2 + LINE(10, 5597, 49) + LINE(9, 5546, 114) / 2;
	WRITE_LINE(9, 5546) = -Acc;
	Acc = -Acc / 2 + LINE(9, 5546, 114) + LINE(8, 5430, 178) / 2;
	WRITE_LINE(8, 5430) = -Acc;
	Acc = Acc * -0.75 + LINE(8, 5430, 178) * 1.5;
	tmp_3 = Acc;
	Acc = LINE(4, 4945, 1) * 0.375;
	tmp_1 = Acc;
	Acc = LINE(0, 0, 1) * 0.625 + tmp_1;
	WRITE_LINE(4, 4945) = Acc;
	Acc = LINE(3, 4942, 1) * 0.9375;
	tmp_1 = Acc;
	Acc = Acc * -0.1875 + LINE(4, 4945, 1) / 8 + tmp_1;
	WRITE_LINE(3, 4942) = Acc;
	Acc = LINE(3, 4942, 1);
	tmp_1 = -Acc;
	Acc = LINE(4, 4945, 1) + tmp_1;
	WRITE_LINE(12, 16381) = Acc;
	Acc = LINE(12, 16381, 5390) / 2 + LINE(2, 4939, 1) / 2;
	WRITE_LINE(2, 4939) = Acc;
	Acc = LINE(1, 4936, 1) * 0.9375;
	tmp_1 = Acc;
	Acc = Acc * -0.1875 + LINE(2, 4939, 1) / 8 + tmp_1;
	WRITE_LINE(1, 4936) = Acc;
	Acc = LINE(1, 4936, 1);
	tmp_1 = -Acc;
	Acc = LINE(2, 4939, 1) * 1.5 + tmp_1 * 1.5;
	WRITE_LINE(11, 10989) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_25(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_d;
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
	tmp_d = Acc;
	Acc = tmp_d + LINE(6, 5469, 175) / 2;
	WRITE_LINE(6, 5469) = -Acc;
	Acc = -Acc / 2 + LINE(6, 5469, 175) + LINE(4, 5133, 36) / 2;
	WRITE_LINE(4, 5133) = -Acc;
	Acc = -Acc / 2 + LINE(4, 5133, 36);
	WRITE_LINE(2, 6) = -Acc;
	Acc = tmp_d + LINE(5, 5292, 157) / 2;
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
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_26(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 4101) + LINE(0, 0, 8204) / 2;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 3890) + LINE(0, 0, 8626) / 2;
	WRITE_LINE(1, 3) = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_27(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 16381, 3515) + LINE(5, 9000, 41) / 2;
	WRITE_LINE(5, 9000) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9000, 41) + LINE(4, 8957, 195) / 2;
	WRITE_LINE(4, 8957) = -Acc;
	Acc = -Acc / 2 + LINE(4, 8957, 195) + LINE(3, 8760, 63) / 2;
	WRITE_LINE(3, 8760) = -Acc;
	Acc = Acc * -0.75 + LINE(3, 8760, 63) * 1.5;
	tmp_5 = Acc;
	Acc = LINE(9, 12864, 3515) + LINE(8, 9347, 49) / 2;
	WRITE_LINE(8, 9347) = -Acc;
	Acc = -Acc / 2 + LINE(8, 9347, 49) + LINE(7, 9296, 114) / 2;
	WRITE_LINE(7, 9296) = -Acc;
	Acc = -Acc / 2 + LINE(7, 9296, 114) + LINE(6, 9180, 178) / 2;
	WRITE_LINE(6, 9180) = -Acc;
	Acc = Acc * -0.75 + LINE(6, 9180, 178) * 1.5;
	tmp_3 = Acc;
	Acc = tmp_3 * 0.65625;
	tmp_3 = Acc;
	Acc = LINE(2, 8695, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(0, 0, 1) / 8 + tmp_1;
	WRITE_LINE(2, 8695) = Acc;
	Acc = LINE(2, 8695, 1);
	tmp_1 = -Acc;
	Acc = LINE(0, 0, 1) + tmp_1;
	WRITE_LINE(10, 16381) = Acc;
	Acc = LINE(1, 8692, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(10, 16381, 3515) / 8 + tmp_1;
	WRITE_LINE(1, 8692) = Acc;
	Acc = LINE(1, 8692, 1);
	tmp_1 = -Acc;
	Acc = LINE(10, 16381, 3515) + tmp_1;
	WRITE_LINE(9, 12864) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_28(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3;
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
	tmp_3 = Acc;
	Acc = LINE(5, 9661, 1) * 0.375;
	tmp_1 = Acc;
	Acc = LINE(0, 0, 1) * 0.625 + tmp_1;
	WRITE_LINE(5, 9661) = Acc;
	Acc = LINE(4, 9658, 1) * 0.9375;
	tmp_1 = Acc;
	Acc = LINE(5, 9661, 1) / 16 + tmp_1;
	WRITE_LINE(4, 9658) = Acc;
	Acc = LINE(4, 9658, 1);
	tmp_1 = -Acc;
	Acc = LINE(5, 9661, 1) + tmp_1;
	WRITE_LINE(13, 16381) = Acc;
	Acc = LINE(13, 16381, 3046) / 2 + LINE(3, 9655, 1) / 2;
	WRITE_LINE(3, 9655) = Acc;
	Acc = LINE(2, 9652, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(3, 9655, 1) / 8 + tmp_1;
	WRITE_LINE(2, 9652) = Acc;
	Acc = LINE(2, 9652, 1);
	tmp_1 = -Acc;
	Acc = LINE(3, 9655, 1) * 1.5 + tmp_1 * 1.5;
	WRITE_LINE(12, 13333) = Acc;
	*out_left = LINE(1, 401, 396);
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_29(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1;
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
	Acc = LINE(4, 10335, 1) * 0.375;
	tmp_1 = Acc;
	Acc = LINE(0, 0, 1) * 0.625 + tmp_1;
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
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_30(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 2343) * 0.75 + LINE(0, 0, 4688) * 0.75;
	tmp_3 = Acc;
	Acc = LINE(0, 0, 2343) * 0.75 + LINE(0, 0, 4688) * 0.75;
	WRITE_LINE(1, 551) = Acc;
	*out_left = LINE(1, 551, 546);
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_31(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 5460) + LINE(0, 0, 16378) / 2;
	tmp_5 = Acc;
	Acc = tmp_5 * 0.65625;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 10919) + LINE(0, 0, 16378) / 2;
	tmp_3 = Acc;
	Acc = tmp_3 * 0.65625;
	tmp_3 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_32(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 4247) + LINE(0, 0, 12739) / 2;
	tmp_5 = Acc;
	Acc = tmp_5 * 0.65625;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 8493) + LINE(0, 0, 12739) / 2;
	tmp_3 = Acc;
	Acc = tmp_3 * 0.65625;
	tmp_3 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_33(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(12, 16381, 4244) / 2 + LINE(11, 12135, 4244) / 2 + LINE(10, 7889, 4244) / 2 + LINE(6, 3296, 41) / 2;
	WRITE_LINE(6, 3296) = -Acc;
	Acc = -Acc / 2 + LINE(6, 3296, 41) + LINE(5, 3253, 195) / 2;
	WRITE_LINE(5, 3253) = -Acc;
	Acc = -Acc / 2 + LINE(5, 3253, 195) + LINE(4, 3056, 63) / 2;
	WRITE_LINE(4, 3056) = -Acc;
	Acc = -Acc / 2 + LINE(4, 3056, 63);
	tmp_5 = Acc;
	Acc = LINE(10, 7889, 4244) / 2 + LINE(11, 12135, 4244) / 2 + LINE(12, 16381, 4244) / 2 + LINE(9, 3643, 49) / 2;
	WRITE_LINE(9, 3643) = -Acc;
	Acc = -Acc / 2 + LINE(9, 3643, 49) + LINE(8, 3592, 114) / 2;
	WRITE_LINE(8, 3592) = -Acc;
	Acc = -Acc / 2 + LINE(8, 3592, 114) + LINE(7, 3476, 178) / 2;
	WRITE_LINE(7, 3476) = -Acc;
	Acc = -Acc / 2 + LINE(7, 3476, 178);
	tmp_3 = Acc;
	Acc = LINE(1, 2985, 1) * 0.375;
	tmp_1 = Acc;
	Acc = LINE(0, 0, 1) * 0.625 + tmp_1;
	WRITE_LINE(1, 2985) = Acc;
	Acc = Acc * 1.5;
	WRITE_LINE(10, 7889) = Acc;
	Acc = LINE(2, 2988, 1) / 2 + LINE(10, 7889, 4244) / 2;
	WRITE_LINE(2, 2988) = Acc;
	Acc = LINE(2, 2988, 1);
	WRITE_LINE(11, 12135) = Acc;
	Acc = LINE(3, 2991, 1) / 2 + LINE(11, 12135, 4244) / 2;
	WRITE_LINE(3, 2991) = Acc;
	Acc = LINE(3, 2991, 0);
	WRITE_LINE(12, 16381) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_34(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(15, 16381, 3276) / 2 + LINE(14, 13103, 3276) / 2 + LINE(13, 9825, 3276) / 2 + LINE(9, 6200, 41) / 2;
	WRITE_LINE(9, 6200) = -Acc;
	Acc = -Acc / 2 + LINE(9, 6200, 41) + LINE(8, 6157, 195) / 2;
	WRITE_LINE(8, 6157) = -Acc;
	Acc = -Acc / 2 + LINE(8, 6157, 195) + LINE(7, 5960, 63) / 2;
	WRITE_LINE(7, 5960) = -Acc;
	Acc = -Acc / 2 + LINE(7, 5960, 63);
	tmp_5 = Acc;
	Acc = LINE(15, 16381, 3276) / 2 + LINE(14, 13103, 3276) / 2 + LINE(13, 9825, 3276) / 2 + LINE(12, 6547, 49) / 2;
	WRITE_LINE(12, 6547) = -Acc;
	Acc = -Acc / 2 + LINE(12, 6547, 49) + LINE(11, 6496, 114) / 2;
	WRITE_LINE(11, 6496) = -Acc;
	Acc = -Acc / 2 + LINE(11, 6496, 114) + LINE(10, 6380, 178) / 2;
	WRITE_LINE(10, 6380) = -Acc;
	Acc = -Acc / 2 + LINE(10, 6380, 178);
	tmp_3 = Acc;
	Acc = LINE(6, 5895, 1) * 0.375;
	tmp_1 = Acc;
	Acc = LINE(0, 0, 1) * 0.625 + tmp_1;
	WRITE_LINE(6, 5895) = Acc;
	Acc = LINE(5, 5892, 1) * 0.9375;
	tmp_1 = Acc;
	Acc = LINE(6, 5895, 1) / 16 + tmp_1;
	WRITE_LINE(5, 5892) = Acc;
	Acc = LINE(5, 5892, 1);
	tmp_1 = -Acc;
	Acc = LINE(6, 5895, 1) + tmp_1;
	WRITE_LINE(15, 16381) = Acc;
	Acc = LINE(4, 5889, 1) / 2 + LINE(15, 16381, 3276) / 2;
	WRITE_LINE(4, 5889) = Acc;
	Acc = LINE(3, 5886, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(4, 5889, 1) / 8 + tmp_1;
	WRITE_LINE(3, 5886) = Acc;
	Acc = LINE(3, 5886, 1);
	tmp_1 = -Acc;
	Acc = LINE(4, 5889, 1) * 2.25 + tmp_1 * 2.25;
	WRITE_LINE(14, 13103) = Acc;
	Acc = LINE(2, 5883, 1) / 2 + LINE(14, 13103, 3276) / 2;
	WRITE_LINE(2, 5883) = Acc;
	*out_left = tmp_5;
	Acc = LINE(1, 5880, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(2, 5883, 1) / 8 + tmp_1;
	WRITE_LINE(1, 5880) = Acc;
	Acc = LINE(1, 5880, 1);
	tmp_1 = -Acc;
	*out_right = tmp_3;
	Acc = LINE(2, 5883, 1) * 2.25 + tmp_1 * 2.25;
	WRITE_LINE(13, 9825) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_35(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 10761, 2808) / 2 + LINE(11, 13571, 2808) / 2 + LINE(12, 16381, 2808) / 2 + LINE(6, 7604, 41) / 2;
	WRITE_LINE(6, 7604) = -Acc;
	Acc = -Acc / 2 + LINE(6, 7604, 41) + LINE(5, 7561, 195) / 2;
	WRITE_LINE(5, 7561) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7561, 195) + LINE(4, 7364, 63) / 2;
	WRITE_LINE(4, 7364) = -Acc;
	Acc = -Acc / 2 + LINE(4, 7364, 63);
	tmp_5 = Acc;
	Acc = tmp_5 * 0.65625;
	tmp_5 = Acc;
	Acc = LINE(12, 16381, 2808) / 2 + LINE(11, 13571, 2808) / 2 + LINE(10, 10761, 2808) / 2 + LINE(9, 7951, 49) / 2;
	WRITE_LINE(9, 7951) = -Acc;
	Acc = -Acc / 2 + LINE(9, 7951, 49) + LINE(8, 7900, 114) / 2;
	WRITE_LINE(8, 7900) = -Acc;
	Acc = -Acc / 2 + LINE(8, 7900, 114) + LINE(7, 7784, 178) / 2;
	WRITE_LINE(7, 7784) = -Acc;
	Acc = -Acc / 2 + LINE(7, 7784, 178);
	tmp_3 = Acc;
	Acc = tmp_3 * 0.65625;
	tmp_3 = Acc;
	Acc = LINE(3, 7299, 1) * 0.9375;
	tmp_1 = Acc;
	Acc = LINE(0, 0, 1) / 16 + tmp_1;
	WRITE_LINE(3, 7299) = Acc;
	Acc = LINE(3, 7299, 1);
	tmp_1 = -Acc;
	Acc = LINE(0, 0, 1) * 1.5 + tmp_1 * 1.5;
	WRITE_LINE(12, 16381) = Acc;
	Acc = LINE(2, 7296, 1) * 0.9375;
	tmp_1 = Acc;
	Acc = Acc * -0.1875 + LINE(12, 16381, 2808) / 8 + tmp_1;
	WRITE_LINE(2, 7296) = Acc;
	Acc = LINE(2, 7296, 1);
	tmp_1 = -Acc;
	Acc = LINE(12, 16381, 2808) + tmp_1;
	WRITE_LINE(11, 13571) = Acc;
	*out_left = tmp_5;
	Acc = LINE(1, 7293, 1) * 0.8125;
	tmp_1 = Acc;
	Acc = LINE(11, 13571, 2808) * 0.1875 + tmp_1;
	WRITE_LINE(1, 7293) = Acc;
	Acc = LINE(1, 7293, 1);
	tmp_1 = -Acc;
	*out_right = tmp_3;
	Acc = LINE(11, 13571, 2808) * 1.5 + tmp_1 * 1.5;
	WRITE_LINE(10, 10761) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_36(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 7027) / 2 + LINE(0, 0, 4685) / 2 + LINE(0, 0, 2343) / 2 + LINE(3, 9008, 41) / 2;
	WRITE_LINE(3, 9008) = -Acc;
	Acc = -Acc / 2 + LINE(3, 9008, 41) + LINE(2, 8965, 195) / 2;
	WRITE_LINE(2, 8965) = -Acc;
	Acc = -Acc / 2 + LINE(2, 8965, 195) + LINE(1, 8768, 63) / 2;
	WRITE_LINE(1, 8768) = -Acc;
	Acc = -Acc / 2 + LINE(1, 8768, 63);
	tmp_5 = Acc;
	Acc = tmp_5 * 0.65625;
	tmp_5 = Acc;
	Acc = LINE(0, 0, 2343) / 2 + LINE(0, 0, 4685) / 2 + LINE(0, 0, 7027) / 2 + LINE(6, 9355, 49) / 2;
	WRITE_LINE(6, 9355) = -Acc;
	Acc = -Acc / 2 + LINE(6, 9355, 49) + LINE(5, 9304, 114) / 2;
	WRITE_LINE(5, 9304) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9304, 114) + LINE(4, 9188, 178) / 2;
	WRITE_LINE(4, 9188) = -Acc;
	Acc = -Acc / 2 + LINE(4, 9188, 178);
	tmp_3 = Acc;
	Acc = tmp_3 * 0.65625;
	tmp_3 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_37(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 16380, 14000);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(2, 16380, 14000);
	tmp_5 = Acc;
	Acc = LINE(0, 0, 2) + LINE(2, 16380, 14000) / 2;
	WRITE_LINE(2, 16380) = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_38(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5, tmp_3ffe;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 16380, 8171) / 2 + LINE(6, 8201, 49) / 2;
	WRITE_LINE(6, 8201) = -Acc;
	Acc = -Acc / 2 + LINE(6, 8201, 49) + LINE(5, 8150, 114) / 2;
	WRITE_LINE(5, 8150) = -Acc;
	Acc = -Acc / 2 + LINE(5, 8150, 114) + LINE(4, 8034, 178) / 2;
	WRITE_LINE(4, 8034) = -Acc;
	Acc = -Acc / 2 + LINE(4, 8034, 178);
	tmp_3 = Acc;
	Acc = LINE(8, 16380, 8171) / 2 + LINE(3, 7854, 41) / 2;
	WRITE_LINE(3, 7854) = -Acc;
	Acc = -Acc / 2 + LINE(3, 7854, 41) + LINE(2, 7811, 195) / 2;
	WRITE_LINE(2, 7811) = -Acc;
	Acc = -Acc / 2 + LINE(2, 7811, 195) + LINE(1, 7614, 63) / 2;
	WRITE_LINE(1, 7614) = -Acc;
	Acc = -Acc / 2 + LINE(1, 7614, 63);
	tmp_5 = Acc;
	Acc = LINE(8, 16380, 8171) / 2 + LINE(0, 0, 2) * 1.5;
	tmp_3ffe = Acc;
	Acc = tmp_3ffe / 2;
	WRITE_LINE(7, 8207) = Acc;
	Acc = LINE(7, 8207, 1);
	tmp_1 = -Acc;
	Acc = tmp_3ffe + tmp_1;
	WRITE_LINE(8, 16380) = Acc;
	Acc = LINE(8, 16380, 0) * 0.75;
	WRITE_LINE(8, 16380) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_39(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_3, tmp_5, tmp_3ffe;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(11, 16380, 7020) / 2 + LINE(8, 9352, 49) / 2;
	WRITE_LINE(8, 9352) = -Acc;
	Acc = -Acc / 2 + LINE(8, 9352, 49) + LINE(7, 9301, 114) / 2;
	WRITE_LINE(7, 9301) = -Acc;
	Acc = -Acc / 2 + LINE(7, 9301, 114) + LINE(6, 9185, 178) / 2;
	WRITE_LINE(6, 9185) = -Acc;
	Acc = -Acc / 2 + LINE(6, 9185, 178);
	tmp_3 = Acc;
	Acc = LINE(11, 16380, 7020) / 2 + LINE(5, 9005, 41) / 2;
	WRITE_LINE(5, 9005) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9005, 41) + LINE(4, 8962, 195) / 2;
	WRITE_LINE(4, 8962) = -Acc;
	Acc = -Acc / 2 + LINE(4, 8962, 195) + LINE(3, 8765, 63) / 2;
	WRITE_LINE(3, 8765) = -Acc;
	Acc = -Acc / 2 + LINE(3, 8765, 63);
	tmp_5 = Acc;
	Acc = -LINE(0, 0, 2) + -LINE(11, 16380, 7020) / 4;
	tmp_3ffe = Acc;
	Acc = tmp_3ffe / 2 + LINE(10, 9358, 1) / 2;
	WRITE_LINE(10, 9358) = Acc;
	Acc = LINE(9, 9355, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(10, 9358, 1) / 8 + tmp_1;
	WRITE_LINE(9, 9355) = Acc;
	Acc = LINE(9, 9355, 1);
	tmp_1 = -Acc;
	Acc = LINE(10, 9358, 1) * 1.5 + tmp_1 * 1.5;
	WRITE_LINE(11, 16380) = Acc;
	Acc = LINE(1, 8688, 6) / 2 + LINE(2, 8691, 1) / 2;
	WRITE_LINE(2, 8691) = Acc;
	Acc = LINE(1, 8688, 1) * 0.875;
	tmp_1 = Acc;
	Acc = LINE(1, 8688, 7) / 8 + tmp_1;
	WRITE_LINE(1, 8688) = Acc;
	Acc = LINE(11, 16380, 0) * 1.375;
	WRITE_LINE(11, 16380) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_40(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 16382, 5002) / 2 + LINE(6, 11375, 59) / 2;
	WRITE_LINE(6, 11375) = -Acc;
	Acc = -Acc / 2 + LINE(6, 11375, 59) + LINE(5, 11314, 117) / 2;
	WRITE_LINE(5, 11314) = -Acc;
	Acc = -Acc / 2 + LINE(5, 11314, 117) + LINE(4, 11195, 139) / 2;
	WRITE_LINE(4, 11195) = -Acc;
	Acc = -Acc / 2 + LINE(4, 11195, 139);
	tmp_3 = Acc;
	Acc = LINE(8, 16382, 5002) / 2 + LINE(3, 11054, 45) / 2;
	WRITE_LINE(3, 11054) = -Acc;
	Acc = -Acc / 2 + LINE(3, 11054, 45) + LINE(2, 11007, 187) / 2;
	WRITE_LINE(2, 11007) = -Acc;
	Acc = -Acc / 2 + LINE(2, 11007, 187) + LINE(1, 10818, 121) / 2;
	WRITE_LINE(1, 10818) = -Acc;
	Acc = -Acc / 2 + LINE(1, 10818, 121);
	tmp_5 = Acc;
	Acc = LINE(0, 0, 2) * 1.125 + LINE(7, 11378, 1) * 0.75;
	WRITE_LINE(8, 16382) = Acc;
	Acc = LINE(7, 11378, 1) / 2 + LINE(8, 16382, 5002) / 2;
	WRITE_LINE(7, 11378) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_41(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 16380, 4500) / 2;
	tmp_3 = Acc;
	Acc = LINE(1, 16380, 4500) / 2;
	tmp_5 = Acc;
	Acc = -LINE(1, 16380, 4500) / 4 + LINE(0, 0, 2);
	WRITE_LINE(1, 16380) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_42(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 16380, 3000);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(2, 16380, 3000);
	tmp_5 = Acc;
	Acc = LINE(0, 0, 2) + LINE(2, 16380, 3000) / 2;
	WRITE_LINE(2, 16380) = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_43(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 588);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 588);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_44(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 940);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 940);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_45(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 1409);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 1409);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_46(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 1760);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 1760);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_47(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 2346);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 2346);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_48(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(9, 2298, 21) / 2;
	WRITE_LINE(9, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(9, 2298, 21) + LINE(8, 2275, 153) / 2;
	WRITE_LINE(8, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2275, 153) + LINE(7, 2120, 273) / 2;
	WRITE_LINE(7, 2120) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2120, 273);
	tmp_3 = Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(6, 1845, 32) / 2;
	WRITE_LINE(6, 1845) = -Acc;
	Acc = -Acc / 2 + LINE(6, 1845, 32) + LINE(5, 1811, 181) / 2;
	WRITE_LINE(5, 1811) = -Acc;
	Acc = -Acc / 2 + LINE(5, 1811, 181) + LINE(4, 1628, 233) / 2;
	WRITE_LINE(4, 1628) = -Acc;
	Acc = -Acc / 2 + LINE(4, 1628, 233);
	tmp_5 = Acc;
	Acc = LINE(0, 0, 163) / 2 + LINE(0, 0, 233) / 2 + LINE(0, 0, 412) / 2 + LINE(0, 0, 534) / 2 + LINE(0, 0, 761) / 2 + LINE(0, 0, 875) / 2 + LINE(10, 15383, 64) / 2 + LINE(10, 15383, 118) / 2 + LINE(10, 15383, 232) / 2 + LINE(10, 15383, 433) / 2 + LINE(10, 15383, 554) / 2 + LINE(10, 15383, 741) / 2 + LINE(10, 15383, 861) / 2 + LINE(10, 15383, 1045) / 2 + LINE(10, 15383, 1148) / 2 + LINE(10, 15383, 1255) / 2 + LINE(10, 15383, 1442) / 2 + LINE(10, 15383, 1578) / 2 + LINE(10, 15383, 1720) / 2 + LINE(10, 15383, 1872) / 2 + LINE(10, 15383, 2035) / 2 + LINE(10, 15383, 2120) / 2 + LINE(10, 15383, 2266) / 2 + LINE(10, 15383, 2450) / 2 + LINE(10, 15383, 2568) / 2 + LINE(10, 15383, 2724) / 2 + LINE(10, 15383, 2888) / 2 + LINE(10, 15383, 3033) / 2 + LINE(10, 15383, 3151) / 2 + LINE(10, 15383, 3256) / 2 + LINE(10, 15383, 3491) / 2 + LINE(10, 15383, 3555) / 2;
	WRITE_LINE(1, 11) = Acc;
	*out_left = tmp_5;
	Acc = -LINE(10, 15383, 8094) / 16 + -LINE(10, 15383, 7848) / 16 + -LINE(10, 15383, 7792) / 16 + -LINE(10, 15383, 7514) / 16 + -LINE(10, 15383, 7461) / 16 + -LINE(10, 15383, 7378) / 16 + -LINE(10, 15383, 7138) / 16 + -LINE(10, 15383, 7091) / 16 + LINE(10, 15383, 6864) / 8 + LINE(10, 15383, 6726) / 8 + LINE(10, 15383, 6656) / 8 + LINE(10, 15383, 6418) / 8 + LINE(10, 15383, 6363) / 8 + LINE(10, 15383, 6153) / 8 + LINE(10, 15383, 6017) / 8 + LINE(10, 15383, 5966) / 8 + -LINE(10, 15383, 5727) / 4 + -LINE(10, 15383, 5656) / 4 + -LINE(10, 15383, 5494) / 4 + -LINE(10, 15383, 5318) / 4 + -LINE(10, 15383, 5260) / 4 + -LINE(10, 15383, 5018) / 4 + -LINE(10, 15383, 4957) / 4 + -LINE(10, 15383, 4733) / 4 + LINE(10, 15383, 4626) / 2 + LINE(10, 15383, 4550) / 2 + LINE(10, 15383, 4338) / 2 + LINE(10, 15383, 4209) / 2 + LINE(10, 15383, 4045) / 2 + LINE(10, 15383, 3920) / 2 + LINE(10, 15383, 3799) / 2 + LINE(10, 15383, 3618) / 2 + LINE(3, 1393, 1) / 2;
	WRITE_LINE(3, 1393) = Acc;
	Acc = -LINE(3, 1393, 1) / 4 + LINE(1, 11, 0);
	WRITE_LINE(1, 11) = Acc;
	Acc = LINE(0, 0, 1000) / 2 + LINE(2, 1390, 1) / 2;
	WRITE_LINE(2, 1390) = Acc;
	Acc = LINE(2, 1390, 1);
	WRITE_LINE(10, 15383) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_49(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(10, 15253, 64) / 2 + LINE(8, 13283, 696) / 2 + LINE(4, 8586, 539) / 2 + LINE(13, 16230, 24) / 2;
	tmp_5 = Acc;
	Acc = LINE(10, 15253, 503) / 2 + LINE(8, 13283, 167) / 2 + LINE(4, 8586, 151) / 2 + LINE(12, 16045, 172) / 2;
	tmp_3 = Acc;
	Acc = LINE(15, 16381, 58) * 0.625 + LINE(0, 0, 1) * 1.5;
	WRITE_LINE(15, 16381) = -Acc;
	Acc = LINE(14, 16321, 89) * 0.625 + LINE(15, 16381, 0) * 0.625 + LINE(15, 16381, 58);
	WRITE_LINE(14, 16321) = -Acc;
	Acc = LINE(13, 16230, 183) * 0.625 + LINE(14, 16321, 0) * 0.625 + LINE(14, 16321, 89);
	WRITE_LINE(13, 16230) = -Acc;
	Acc = LINE(12, 16045, 321) * 0.625 + LINE(13, 16230, 0) * 0.625 + LINE(13, 16230, 183);
	WRITE_LINE(12, 16045) = -Acc;
	Acc = LINE(11, 15722, 467) * 0.625 + LINE(12, 16045, 0) * 0.625 + LINE(12, 16045, 321);
	WRITE_LINE(11, 15722) = -Acc;
	Acc = -Acc / 8 + LINE(11, 15722, 0) / 2 + LINE(11, 15722, 467);
	tmp_b = Acc;
	Acc = LINE(10, 15253, 845) * 0.75 + LINE(9, 14406, 1121) / 2;
	WRITE_LINE(9, 14406) = -Acc;
	Acc = -Acc / 2 + LINE(9, 14406, 1121);
	WRITE_LINE(8, 13283) = Acc;
	Acc = LINE(8, 13283, 1441) * 0.75 + LINE(7, 11840, 1320) / 2;
	WRITE_LINE(7, 11840) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11840, 1320);
	tmp_1 = Acc;
	Acc = LINE(2, 6264, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(2, 6264) = Acc;
	Acc = LINE(2, 6264, 1) + tmp_b;
	WRITE_LINE(10, 15253) = Acc;
	Acc = LINE(6, 10518, 912) * 0.75 + LINE(5, 9604, 1016) / 2;
	WRITE_LINE(5, 9604) = -Acc;
	Acc = -Acc / 2 + LINE(5, 9604, 1016);
	WRITE_LINE(4, 8586) = Acc;
	Acc = LINE(4, 8586, 1017) * 0.75 + LINE(3, 7567, 1298) / 2;
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
void midifex_f_effect_50(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(4, 2190, 1) / 2;
	tmp_3 = Acc;
	Acc = LINE(3, 2187, 1) / 2;
	tmp_5 = Acc;
	Acc = LINE(5, 2193, 1) / 2 + LINE(0, 0, 1) / 2;
	WRITE_LINE(5, 2193) = Acc;
	Acc = -LINE(1, 11, 1) / 4 + LINE(2, 2184, 1) / 2;
	WRITE_LINE(2, 2184) = Acc;
	Acc = Acc * 1.5 + LINE(5, 2193, 1) + LINE(26, 16381, 13) / 2;
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
	Acc = LINE(1, 11, 0) + LINE(9, 2666, 147) / 2;
	WRITE_LINE(9, 2666) = -Acc;
	Acc = -Acc / 2 + LINE(9, 2666, 147) + LINE(11, 2768, 43) / 2;
	WRITE_LINE(11, 2768) = -Acc;
	Acc = -Acc / 2 + LINE(11, 2768, 43) + LINE(10, 2723, 55) / 2;
	WRITE_LINE(10, 2723) = -Acc;
	Acc = -Acc / 2 + LINE(10, 2723, 55);
	WRITE_LINE(4, 2190) = Acc;
	Acc = LINE(1, 11, 0) + LINE(6, 2444, 249) / 2;
	WRITE_LINE(6, 2444) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + LINE(6, 2444, 249) + LINE(7, 2494, 48) / 2;
	WRITE_LINE(7, 2494) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2494, 48) + LINE(8, 2517, 21) / 2;
	WRITE_LINE(8, 2517) = -Acc;
	Acc = -Acc / 2 + LINE(8, 2517, 21);
	WRITE_LINE(3, 2187) = Acc;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_51(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_2;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(9, 12641, 1065) * 0.046875 + LINE(9, 12641, 1233) * 0.046875 + LINE(9, 12641, 1555) * 0.046875 + LINE(7, 9021, 269) * 0.046875 + LINE(5, 4536, 2003) * -0.09375 + LINE(7, 9021, 1891) * -0.09375 + LINE(9, 12641, 21) * -0.09375 + LINE(7, 9021, 532) * -0.09375 + LINE(7, 9021, 872) * -0.09375 + LINE(7, 9021, 1107) * -0.09375 + LINE(7, 9021, 1414) * -0.09375 + LINE(7, 9021, 1615) * -0.09375 + LINE(7, 9021, 1914) * -0.09375 + LINE(5, 4536, 173) * -0.09375 + LINE(5, 4536, 460) * -0.09375 + LINE(5, 4536, 780) * 0.1875 + LINE(5, 4536, 1066) * 0.1875 + LINE(5, 4536, 1344) * 0.1875 + LINE(5, 4536, 1660) * 0.1875 + LINE(5, 4536, 1941) * 0.1875;
	WRITE_LINE(1, 4) = -Acc;
	Acc = -LINE(5, 4536, 2005) / 16 + -LINE(5, 4536, 1762) / 16 + -LINE(5, 4536, 1408) / 16 + -LINE(5, 4536, 1110) / 16 + LINE(5, 4536, 671) / 8 + LINE(7, 9021, 890) / 8 + LINE(9, 12641, 1010) / 8 + LINE(5, 4536, 907) / 8 + LINE(5, 4536, 595) / 8 + LINE(5, 4536, 342) / 8 + LINE(5, 4536, 41) / 8 + LINE(7, 9021, 1801) / 8 + LINE(7, 9021, 1509) / 8 + LINE(7, 9021, 1229) / 8 + LINE(7, 9021, 936) / 8 + -LINE(7, 9021, 637) / 4 + -LINE(7, 9021, 414) / 4 + -LINE(7, 9021, 105) / 4 + -LINE(9, 12641, 1434) / 4 + -LINE(9, 12641, 1119) / 4;
	WRITE_LINE(2, 6) = -Acc;
	Acc = LINE(0, 0, 1) * 2.53125 + LINE(15, 16381, 321) / 2;
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
	tmp_2 = Acc;
	Acc = LINE(9, 12641, 1624) + LINE(8, 11015, 1992) / 2;
	WRITE_LINE(8, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(8, 11015, 1992);
	WRITE_LINE(7, 9021) = Acc;
	Acc = LINE(7, 9021, 2110) * 0.9375 + LINE(6, 6909, 2371) / 2;
	WRITE_LINE(6, 6909) = -Acc;
	*out_left = LINE(2, 6, 1);
	Acc = -Acc / 2 + LINE(6, 6909, 2371);
	WRITE_LINE(5, 4536) = Acc;
	Acc = LINE(5, 4536, 2157) / 2 + LINE(4, 2377, 2312) / 2;
	WRITE_LINE(4, 2377) = -Acc;
	Acc = Acc * -0.75 + LINE(4, 2377, 2312) * 1.5;
	tmp_1 = Acc;
	Acc = LINE(3, 63, 1) / 4 + tmp_1 / 2;
	WRITE_LINE(3, 63) = Acc;
	*out_right = LINE(1, 4, 1);
	Acc = LINE(3, 63, 0) + tmp_2;
	WRITE_LINE(9, 12641) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_52(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_1, tmp_2, tmp_3, tmp_5, tmp_7, tmp_9;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(8, 12641, 21) / 2 + LINE(6, 9121, 1891) / 2 + LINE(4, 4636, 2003) / 2;
	tmp_3 = Acc;
	Acc = LINE(8, 12641, 801) / 2 + LINE(6, 9121, 890) / 2 + LINE(4, 4636, 671) / 2;
	tmp_5 = Acc;
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
	tmp_2 = Acc;
	Acc = LINE(8, 12641, 1624) + LINE(7, 11015, 1892) / 2;
	WRITE_LINE(7, 11015) = -Acc;
	Acc = -Acc / 2 + LINE(7, 11015, 1892);
	WRITE_LINE(6, 9121) = Acc;
	Acc = LINE(6, 9121, 2110) * -0.84375 + LINE(5, 7009, 2371) / 2;
	WRITE_LINE(5, 7009) = -Acc;
	Acc = -Acc / 2 + LINE(5, 7009, 2371);
	WRITE_LINE(4, 4636) = Acc;
	Acc = LINE(4, 4636, 2157) * 1.125 + LINE(3, 2477, 2312) / 2;
	WRITE_LINE(3, 2477) = -Acc;
	Acc = -Acc / 2 + LINE(3, 2477, 2312);
	tmp_1 = Acc;
	Acc = LINE(1, 157, 1) / 2 + tmp_1 / 2;
	WRITE_LINE(1, 157) = Acc;
	Acc = LINE(1, 157, 0) + tmp_2;
	tmp_7 = Acc;
	Acc = LINE(2, 163, 1) * 0.9375;
	tmp_9 = Acc;
	Acc = tmp_7 / 16 + tmp_9;
	WRITE_LINE(2, 163) = Acc;
	Acc = LINE(2, 163, 0);
	tmp_9 = -Acc;
	Acc = tmp_7 + tmp_9;
	WRITE_LINE(8, 12641) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_53(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(7, 2298, 21) / 2;
	WRITE_LINE(7, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2298, 21) + LINE(6, 2275, 153) / 2;
	WRITE_LINE(6, 2275) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2275, 153) + LINE(5, 2120, 273) / 2;
	WRITE_LINE(5, 2120) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2120, 273) + LINE(0, 0, 14000);
	tmp_3 = Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(4, 1845, 32) / 2;
	WRITE_LINE(4, 1845) = -Acc;
	Acc = -Acc / 2 + LINE(4, 1845, 32) + LINE(3, 1811, 175) / 2;
	WRITE_LINE(3, 1811) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1811, 175) + LINE(2, 1634, 233) / 2;
	WRITE_LINE(2, 1634) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1634, 233) + LINE(0, 0, 14000);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
	Acc = Acc * 0.09375 + LINE(0, 0, 1065) / 32 + LINE(0, 0, 1119) / 32 + LINE(0, 0, 1233) / 32 + LINE(0, 0, 1434) / 32 + LINE(0, 0, 1555) / 32 + LINE(0, 0, 1742) / 32 + LINE(0, 0, 1862) / 32 + LINE(0, 0, 2046) / 32 + LINE(0, 0, 3569) / 32 + LINE(0, 0, 2256) / 32 + LINE(0, 0, 2443) / 32 + LINE(0, 0, 3121) / 32 + LINE(0, 0, 2721) / 32 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 3036) / 16 + -LINE(0, 0, 2579) / 16 + -LINE(0, 0, 3267) / 16 + -LINE(0, 0, 3451) / 16 + -LINE(0, 0, 2149) / 16 + -LINE(0, 0, 3725) / 16 + -LINE(0, 0, 3889) / 16 + -LINE(0, 0, 4034) / 16 + -LINE(0, 0, 4152) / 16 + -LINE(0, 0, 4257) / 16 + -LINE(0, 0, 4492) / 16 + -LINE(0, 0, 4556) / 16 + -LINE(0, 0, 4727) / 16 + -LINE(0, 0, 4849) / 16 + -LINE(0, 0, 6035) / 16 + -LINE(0, 0, 5129) / 16 + -LINE(0, 0, 5235) / 16 + -LINE(0, 0, 6223) / 16 + -LINE(0, 0, 5534) / 16 + LINE(0, 0, 5759) / 8 + LINE(0, 0, 5837) / 8 + LINE(0, 0, 5034) / 8 + LINE(0, 0, 6159) / 8 + LINE(0, 0, 5421) / 8 + LINE(0, 0, 6446) / 8 + LINE(0, 0, 6534) / 8 + LINE(0, 0, 6782) / 8 + LINE(0, 0, 6859) / 8 + LINE(0, 0, 7039) / 8 + LINE(0, 0, 7126) / 8 + LINE(0, 0, 7221) / 8 + LINE(0, 0, 8565) / 8 + LINE(0, 0, 7534) / 8 + LINE(0, 0, 7736) / 8 + LINE(0, 0, 7891) / 8 + LINE(0, 0, 9215) / 8 + LINE(0, 0, 8146) / 8 + LINE(0, 0, 8278) / 8 + -LINE(0, 0, 8447) / 4 + -LINE(0, 0, 7439) / 4 + -LINE(0, 0, 8700) / 4 + -LINE(0, 0, 8885) / 4 + -LINE(0, 0, 9012) / 4 + -LINE(0, 0, 9171) / 4 + -LINE(0, 0, 8034) / 4 + -LINE(0, 0, 9449) / 4 + -LINE(0, 0, 9513) / 4 + -LINE(0, 0, 9765) / 4 + -LINE(0, 0, 9867) / 4 + -LINE(0, 0, 10046) / 4 + -LINE(0, 0, 10110) / 4 + -LINE(0, 0, 10285) / 4 + -LINE(0, 0, 12074) / 4 + -LINE(0, 0, 10578) / 4 + -LINE(0, 0, 10734) / 4 + -LINE(0, 0, 11715) / 4 + -LINE(0, 0, 11023) / 4 + -LINE(0, 0, 11185) / 4 + LINE(0, 0, 11254) / 2 + LINE(0, 0, 11479) / 2 + LINE(0, 0, 11546) / 2 + LINE(0, 0, 10815) / 2 + LINE(0, 0, 11847) / 2 + LINE(0, 0, 10428) / 2 + LINE(0, 0, 12112) / 2 + LINE(0, 0, 12279) / 2 + LINE(0, 0, 12415) / 2 + LINE(0, 0, 12516) / 2 + LINE(0, 0, 12746) / 2 + LINE(0, 0, 12815) / 2 + LINE(0, 0, 13046) / 2 + LINE(0, 0, 13217) / 2 + LINE(0, 0, 13378) / 2 + LINE(0, 0, 13534) / 2;
	WRITE_LINE(1, 11) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_54(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(1, 11, 2) / 2 + LINE(7, 2295, 21) / 2;
	WRITE_LINE(7, 2295) = -Acc;
	Acc = -Acc / 2 + LINE(7, 2295, 21) + LINE(6, 2272, 153) / 2;
	WRITE_LINE(6, 2272) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2272, 153) + LINE(5, 2117, 273) / 2;
	WRITE_LINE(5, 2117) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2117, 273) + LINE(8, 16381, 12000) / 2;
	tmp_3 = Acc;
	Acc = LINE(1, 11, 2) / 2 + LINE(4, 1842, 32) / 2;
	WRITE_LINE(4, 1842) = -Acc;
	Acc = -Acc / 2 + LINE(4, 1842, 32) + LINE(3, 1808, 175) / 2;
	WRITE_LINE(3, 1808) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1808, 175) + LINE(2, 1631, 233) / 2;
	WRITE_LINE(2, 1631) = -Acc;
	Acc = -Acc / 2 + LINE(2, 1631, 233) + LINE(8, 16381, 12000) / 2;
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
	Acc = Acc * -0.046875 + -LINE(8, 16381, 1065) / 64 + -LINE(8, 16381, 1119) / 64 + -LINE(8, 16381, 1233) / 64 + -LINE(8, 16381, 1434) / 64 + -LINE(8, 16381, 1555) / 64 + -LINE(8, 16381, 1742) / 64 + -LINE(8, 16381, 1862) / 64 + -LINE(8, 16381, 2046) / 64 + -LINE(8, 16381, 3569) / 64 + -LINE(8, 16381, 2256) / 64 + -LINE(8, 16381, 2443) / 64 + -LINE(8, 16381, 3121) / 64 + -LINE(8, 16381, 2721) / 64 + LINE(8, 16381, 2873) / 32 + LINE(8, 16381, 3036) / 32 + LINE(8, 16381, 2579) / 32 + LINE(8, 16381, 3267) / 32 + LINE(8, 16381, 3451) / 32 + LINE(8, 16381, 2149) / 32 + LINE(8, 16381, 3725) / 32 + LINE(8, 16381, 3889) / 32 + LINE(8, 16381, 4034) / 32 + LINE(8, 16381, 4152) / 32 + -LINE(8, 16381, 4257) / 16 + -LINE(8, 16381, 4492) / 16 + -LINE(8, 16381, 4556) / 16 + -LINE(8, 16381, 4727) / 16 + -LINE(8, 16381, 4849) / 16 + -LINE(8, 16381, 6035) / 16 + -LINE(8, 16381, 5129) / 16 + -LINE(8, 16381, 5235) / 16 + -LINE(8, 16381, 6223) / 16 + -LINE(8, 16381, 5534) / 16 + LINE(8, 16381, 5759) / 8 + LINE(8, 16381, 5837) / 8 + LINE(8, 16381, 5034) / 8 + LINE(8, 16381, 6159) / 8 + LINE(8, 16381, 5421) / 8 + LINE(8, 16381, 6446) / 8 + LINE(8, 16381, 6534) / 8 + LINE(8, 16381, 6782) / 8 + LINE(8, 16381, 6859) / 8 + LINE(8, 16381, 7039) / 8 + LINE(8, 16381, 7126) / 8 + LINE(8, 16381, 7221) / 8 + LINE(8, 16381, 8565) / 8 + LINE(8, 16381, 7534) / 8 + LINE(8, 16381, 7736) / 8 + LINE(8, 16381, 7891) / 8 + LINE(8, 16381, 9215) / 8 + LINE(8, 16381, 8146) / 8 + LINE(8, 16381, 8278) / 8 + -LINE(8, 16381, 8447) / 4 + -LINE(8, 16381, 7439) / 4 + -LINE(8, 16381, 8700) / 4 + -LINE(8, 16381, 8885) / 4 + -LINE(8, 16381, 9012) / 4 + -LINE(8, 16381, 9171) / 4 + -LINE(8, 16381, 8034) / 4 + -LINE(8, 16381, 9449) / 4 + -LINE(8, 16381, 9513) / 4 + -LINE(8, 16381, 9765) / 4 + -LINE(8, 16381, 9867) / 4 + -LINE(8, 16381, 10046) / 4 + -LINE(8, 16381, 10110) / 4 + -LINE(8, 16381, 10285) / 4 + -LINE(8, 16381, 12074) / 4 + -LINE(8, 16381, 10578) / 4 + -LINE(8, 16381, 10734) / 4 + -LINE(8, 16381, 11715) / 4 + -LINE(8, 16381, 11023) / 4 + -LINE(8, 16381, 11185) / 4 + LINE(8, 16381, 11254) / 2 + LINE(8, 16381, 11479) / 2 + LINE(8, 16381, 11546) / 2 + LINE(8, 16381, 10815) / 2 + LINE(8, 16381, 11847) / 2 + LINE(8, 16381, 10428) / 2;
	WRITE_LINE(1, 11) = Acc;
	Acc = LINE(8, 16381, 14084) / 2 + LINE(0, 0, 1);
	WRITE_LINE(8, 16381) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_55(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(0, 0, 8922) / 4 + LINE(0, 0, 5321) / 2 + LINE(0, 0, 4000) / 2 + LINE(0, 0, 2315) / 2;
	tmp_3 = Acc;
	Acc = -LINE(0, 0, 9012) / 4 + LINE(0, 0, 6352) / 2 + LINE(0, 0, 4000) / 2 + LINE(0, 0, 3378) / 2;
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_56(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 13998) / 128 + LINE(0, 0, 13968) / 128 + LINE(0, 0, 13955) / 128 + LINE(0, 0, 13957) / 128 + LINE(0, 0, 13815) / 128 + -LINE(0, 0, 13819) / 64 + -LINE(0, 0, 13749) / 64 + -LINE(0, 0, 13756) / 64 + -LINE(0, 0, 13676) / 64 + LINE(0, 0, 13552) / 32 + LINE(0, 0, 13319) / 32 + LINE(0, 0, 13185) / 32 + LINE(0, 0, 12927) / 32 + LINE(0, 0, 12656) / 32 + -LINE(0, 0, 12338) / 16 + -LINE(0, 0, 11919) / 16 + -LINE(0, 0, 11361) / 16 + -LINE(0, 0, 10683) / 16 + LINE(0, 0, 9835) / 8 + LINE(0, 0, 8775) / 8 + -LINE(0, 0, 9450) / 4 + -LINE(0, 0, 5194) / 4 + LINE(0, 0, 4501) / 2 + LINE(0, 0, 2724) / 2 + LINE(0, 0, 781) / 2;
	tmp_3 = Acc;
	Acc = LINE(0, 0, 13986) / 128 + LINE(0, 0, 13919) / 128 + LINE(0, 0, 13918) / 128 + LINE(0, 0, 13972) / 128 + LINE(0, 0, 13807) / 128 + LINE(0, 0, 13854) / 128 + -LINE(0, 0, 13727) / 64 + -LINE(0, 0, 13619) / 64 + -LINE(0, 0, 13519) / 64 + LINE(0, 0, 13457) / 32 + LINE(0, 0, 13289) / 32 + LINE(0, 0, 13071) / 32 + -LINE(0, 0, 12727) / 16 + -LINE(0, 0, 12449) / 16 + -LINE(0, 0, 12016) / 16 + -LINE(0, 0, 11571) / 16 + LINE(0, 0, 10981) / 8 + LINE(0, 0, 10160) / 8 + LINE(0, 0, 9145) / 8 + LINE(0, 0, 8913) / 8 + -LINE(0, 0, 6873) / 4 + -LINE(0, 0, 4048) / 4 + LINE(0, 0, 3041) / 2 + LINE(0, 0, 1121) / 2;
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_57(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(2, 12, 1) / 2 + LINE(6, 2298, 67) / 2;
	WRITE_LINE(6, 2298) = -Acc;
	Acc = -Acc / 2 + LINE(6, 2298, 67) + LINE(5, 2229, 121) / 2;
	WRITE_LINE(5, 2229) = -Acc;
	Acc = -Acc / 2 + LINE(5, 2229, 121) + LINE(0, 0, 14000);
	tmp_3 = Acc;
	Acc = LINE(1, 10, 1) / 2 + LINE(4, 1931, 45) / 2;
	WRITE_LINE(4, 1931) = -Acc;
	Acc = -Acc / 2 + LINE(4, 1931, 45) + LINE(3, 1884, 98) / 2;
	WRITE_LINE(3, 1884) = -Acc;
	Acc = -Acc / 2 + LINE(3, 1884, 98);
	tmp_5 = Acc;
	Acc = LINE(0, 0, 1065) / 32 + LINE(0, 0, 1233) / 32 + LINE(0, 0, 1555) / 32 + LINE(0, 0, 1862) / 32 + LINE(0, 0, 3569) / 32 + LINE(0, 0, 2443) / 32 + LINE(0, 0, 2721) / 32 + -LINE(0, 0, 2873) / 16 + -LINE(0, 0, 2579) / 16 + -LINE(0, 0, 3451) / 16 + -LINE(0, 0, 13112) / 16 + -LINE(0, 0, 3725) / 16 + -LINE(0, 0, 3889) / 16 + LINE(0, 0, 4152) / 8 + LINE(0, 0, 4492) / 8 + LINE(0, 0, 6035) / 8 + LINE(0, 0, 12345) / 8 + LINE(0, 0, 11111) / 8 + LINE(0, 0, 5235) / 8 + LINE(0, 0, 5534) / 8 + -LINE(0, 0, 5759) / 4 + -LINE(0, 0, 5034) / 4 + -LINE(0, 0, 10211) / 4 + -LINE(0, 0, 9123) / 4 + -LINE(0, 0, 12781) / 4 + -LINE(0, 0, 5421) / 4 + -LINE(0, 0, 6534) / 4 + LINE(0, 0, 6859) / 2 + LINE(0, 0, 7126) / 2 + LINE(0, 0, 8565) / 2 + LINE(0, 0, 7736) / 2 + LINE(0, 0, 9215) / 2 + LINE(0, 0, 8146) / 2;
	WRITE_LINE(1, 10) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
	Acc = LINE(0, 0, 5759) / 8 + LINE(0, 0, 5837) / 8 + LINE(0, 0, 5034) / 8 + LINE(0, 0, 6159) / 8 + LINE(0, 0, 5421) / 8 + LINE(0, 0, 6446) / 8 + LINE(0, 0, 6534) / 8 + LINE(0, 0, 6782) / 8 + LINE(0, 0, 6859) / 8 + LINE(0, 0, 7039) / 8 + LINE(0, 0, 7126) / 8 + LINE(0, 0, 7221) / 8 + LINE(0, 0, 8565) / 8 + LINE(0, 0, 7534) / 8 + LINE(0, 0, 7736) / 8 + LINE(0, 0, 7891) / 8 + LINE(0, 0, 9215) / 8 + LINE(0, 0, 8146) / 8 + LINE(0, 0, 8278) / 8 + -LINE(0, 0, 8447) / 4 + -LINE(0, 0, 7439) / 4 + -LINE(0, 0, 8700) / 4 + -LINE(0, 0, 8885) / 4 + -LINE(0, 0, 9012) / 4 + -LINE(0, 0, 9171) / 4 + -LINE(0, 0, 8034) / 4 + -LINE(0, 0, 9449) / 4 + -LINE(0, 0, 9513) / 4 + -LINE(0, 0, 9765) / 4 + -LINE(0, 0, 9867) / 4 + -LINE(0, 0, 10046) / 4 + -LINE(0, 0, 10110) / 4 + -LINE(0, 0, 10285) / 4 + -LINE(0, 0, 12074) / 4 + -LINE(0, 0, 10578) / 4 + -LINE(0, 0, 10734) / 4 + -LINE(0, 0, 11715) / 4 + -LINE(0, 0, 11023) / 4 + -LINE(0, 0, 11185) / 4 + LINE(0, 0, 11254) / 2 + LINE(0, 0, 11479) / 2 + LINE(0, 0, 11546) / 2 + LINE(0, 0, 10815) / 2 + LINE(0, 0, 11847) / 2 + LINE(0, 0, 10428) / 2 + LINE(0, 0, 12112) / 2 + LINE(0, 0, 12279) / 2 + LINE(0, 0, 12415) / 2 + LINE(0, 0, 12516) / 2 + LINE(0, 0, 12746) / 2 + LINE(0, 0, 12815) / 2 + LINE(0, 0, 13046) / 2 + LINE(0, 0, 13217) / 2 + LINE(0, 0, 13378) / 2 + LINE(0, 0, 13534) / 2;
	WRITE_LINE(2, 12) = Acc;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_58(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_d;
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
	tmp_d = Acc;
	Acc = tmp_d + LINE(4, 13896, 35) / 2;
	WRITE_LINE(4, 13896) = -Acc;
	Acc = -Acc / 2 + LINE(4, 13896, 35);
	WRITE_LINE(2, 6) = -Acc;
	Acc = tmp_d + LINE(3, 13859, 31) / 2;
	WRITE_LINE(3, 13859) = -Acc;
	Acc = -Acc / 2 + LINE(3, 13859, 31);
	WRITE_LINE(1, 4) = -Acc;
	*out_left = LINE(2, 6, 1);
	*out_right = LINE(1, 4, 1);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_59(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc;
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
	Acc = LINE(1, 3, 0);
	WRITE_LINE(2, 5) = Acc;
	*out_left = LINE(2, 5, 0);
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_60(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_0, tmp_5;
	tmp_0 = input;
	Acc = tmp_0 + LINE(4, 16381, 187) / 2;
	WRITE_LINE(4, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(4, 16381, 187) + LINE(3, 16192, 337) / 2;
	WRITE_LINE(3, 16192) = -Acc;
	Acc = -Acc / 2 + LINE(3, 16192, 337);
	WRITE_LINE(0, 3) = Acc;
	Acc = tmp_0 + LINE(2, 15853, 121) / 2;
	WRITE_LINE(2, 15853) = -Acc;
	Acc = -Acc / 2 + LINE(2, 15853, 121) + LINE(1, 15730, 393) / 2;
	WRITE_LINE(1, 15730) = -Acc;
	Acc = -Acc / 2 + LINE(1, 15730, 393);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = LINE(0, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_61(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_7d1;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 1) + LINE(4, 16381, 47) / 2;
	WRITE_LINE(4, 16381) = -Acc;
	Acc = -Acc / 2 + LINE(4, 16381, 47) + LINE(3, 16332, 89) / 2;
	WRITE_LINE(3, 16332) = -Acc;
	Acc = -Acc / 2 + LINE(3, 16332, 89) + LINE(2, 16241, 215) / 2;
	WRITE_LINE(2, 16241) = -Acc;
	Acc = -Acc / 2 + LINE(2, 16241, 215);
	tmp_7d1 = Acc;
	Acc = tmp_7d1;
	WRITE_LINE(1, 301) = Acc;
	*out_left = LINE(1, 301, 296);
	*out_right = LINE(1, 301, 298);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_62(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = LINE(0, 0, 150);
	WRITE_LINE(1, 3) = Acc;
	Acc = LINE(0, 0, 300);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = LINE(1, 3, 0);
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_63(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc, tmp_3, tmp_5;
	WRITE_LINE(0, 0) = input;
	Acc = -LINE(1, 14261, 1) / 4 + LINE(2, 14264, 1);
	tmp_3 = Acc;
	Acc = -LINE(2, 14264, 1) / 4 + LINE(1, 14261, 1);
	tmp_5 = Acc;
	Acc = LINE(0, 0, 3) * 1.5 + LINE(20, 16089, 15) / 2;
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
	Acc = LINE(0, 0, 3) * 1.5 + LINE(11, 15210, 17) / 2;
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
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef LINE
#undef WRITE_LINE
#define LINE(id,w_addr,r_offset) (DRAM[(ptr + w_addr - r_offset) & 0x3fff])
#define WRITE_LINE(id,w_addr) (DRAM[(ptr + w_addr) & 0x3fff])
void midifex_f_effect_64(float input, float *out_left, float *out_right, float DRAM[0x4000], int ptr) {
	float Acc;
	*out_left = LINE(0, 140, 135);
	*out_right = LINE(0, 140, 137);
	Acc = 0;
	WRITE_LINE(0, 140) = -Acc;
}
#undef LINE
#undef WRITE_LINE
void (*midifex_f_effects[])(float input, float *out_left, float *out_right, float *DRAM, int ptr) = {
	midifex_f_effect_1,
	midifex_f_effect_2,
	midifex_f_effect_3,
	midifex_f_effect_4,
	midifex_f_effect_5,
	midifex_f_effect_6,
	midifex_f_effect_7,
	midifex_f_effect_8,
	midifex_f_effect_9,
	midifex_f_effect_10,
	midifex_f_effect_11,
	midifex_f_effect_12,
	midifex_f_effect_13,
	midifex_f_effect_14,
	midifex_f_effect_15,
	midifex_f_effect_16,
	midifex_f_effect_17,
	midifex_f_effect_18,
	midifex_f_effect_19,
	midifex_f_effect_20,
	midifex_f_effect_21,
	midifex_f_effect_22,
	midifex_f_effect_23,
	midifex_f_effect_24,
	midifex_f_effect_25,
	midifex_f_effect_26,
	midifex_f_effect_27,
	midifex_f_effect_28,
	midifex_f_effect_29,
	midifex_f_effect_30,
	midifex_f_effect_31,
	midifex_f_effect_32,
	midifex_f_effect_33,
	midifex_f_effect_34,
	midifex_f_effect_35,
	midifex_f_effect_36,
	midifex_f_effect_37,
	midifex_f_effect_38,
	midifex_f_effect_39,
	midifex_f_effect_40,
	midifex_f_effect_41,
	midifex_f_effect_42,
	midifex_f_effect_43,
	midifex_f_effect_44,
	midifex_f_effect_45,
	midifex_f_effect_46,
	midifex_f_effect_47,
	midifex_f_effect_48,
	midifex_f_effect_49,
	midifex_f_effect_50,
	midifex_f_effect_51,
	midifex_f_effect_52,
	midifex_f_effect_53,
	midifex_f_effect_54,
	midifex_f_effect_55,
	midifex_f_effect_56,
	midifex_f_effect_57,
	midifex_f_effect_58,
	midifex_f_effect_59,
	midifex_f_effect_60,
	midifex_f_effect_61,
	midifex_f_effect_62,
	midifex_f_effect_63,
	midifex_f_effect_64,
};
