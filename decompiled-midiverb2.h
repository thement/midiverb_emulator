#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_0(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc;
	*out_left = MEM(5);
	*out_right = MEM(3);
	Acc = 0;
	MEM(140) = -Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_1(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15960) * 3 / 4 + MEM(15315) * 3 / 4 + MEM(14783) * 3 / 4 + MEM(14099) * 3 / 4 + MEM(12643) * 3 / 4 + MEM(12176) * 3 / 4 + MEM(11469) * 3 / 4;
	tmp_3 = Acc;
	Acc = MEM(15827) * 3 / 4 + MEM(15419) * 3 / 4 + MEM(14576) * 3 / 4 + MEM(14200) * 3 / 4 + MEM(12709) * 3 / 4 + MEM(12167) * 3 / 4 + MEM(10728) * 3 / 4;
	tmp_5 = Acc;
	Acc = MEM(16362) * 3 / 4 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16315) * 3 / 4 + MEM(16362);
	MEM(16360) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16229) * 3 / 4 + MEM(16315);
	MEM(16313) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16112) * 3 / 4 + MEM(16229);
	MEM(16227) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15974) * 3 / 4 + MEM(16112);
	MEM(16110) = -Acc;
	Acc = Acc * -9 / 8 + MEM(15974) * 3 / 2;
	tmp_b = Acc;
	Acc = MEM(15551) / 2 + MEM(13519) / 2;
	MEM(13797) = -Acc;
	Acc = -Acc / 2 + MEM(13519);
	MEM(15549) = Acc;
	Acc = -MEM(15037) / 4 + -MEM(15036) / 4 + MEM(13305) / 2;
	MEM(13517) = -Acc;
	Acc = -Acc / 2 + MEM(13305);
	MEM(15035) = Acc;
	Acc = MEM(14479) / 2 + MEM(13047) / 2;
	MEM(13303) = -Acc;
	Acc = -Acc / 2 + MEM(13047);
	MEM(14477) = Acc;
	Acc = MEM(13799) / 2 + MEM(12814) / 2;
	MEM(13045) = -Acc;
	Acc = -Acc / 2 + MEM(12814) + MEM(9693) / 2;
	MEM(9694) = Acc;
	Acc = MEM(9694) / 2 + tmp_b;
	MEM(15972) = Acc;
	Acc = MEM(12377) / 2 + MEM(10452) / 2;
	MEM(10744) = -Acc;
	Acc = -Acc / 2 + MEM(10452);
	MEM(12375) = Acc;
	Acc = -MEM(11894) / 4 + -MEM(11893) / 4 + MEM(10169) / 2;
	MEM(10450) = -Acc;
	Acc = -Acc / 2 + MEM(10169);
	MEM(11892) = Acc;
	Acc = MEM(11321) / 2 + MEM(9933) / 2;
	MEM(10167) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + MEM(9933);
	MEM(11319) = Acc;
	Acc = MEM(10746) / 2 + MEM(9699) / 2;
	MEM(9931) = -Acc;
	Acc = -Acc / 2 + MEM(9699) + MEM(9690) / 2;
	MEM(9691) = Acc;
	Acc = MEM(9691) / 2 + tmp_b;
	MEM(12812) = Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_2(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15842) * 3 / 4 + MEM(14758) * 3 / 4 + MEM(12499) * 3 / 4 + MEM(10881) * 3 / 4 + MEM(9088) * 3 / 4 + MEM(7983) * 3 / 4 + MEM(5679) * 3 / 4 + MEM(5415) * 3 / 4;
	tmp_3 = Acc;
	Acc = MEM(15833) * 3 / 4 + MEM(14962) * 3 / 4 + MEM(12292) * 3 / 4 + MEM(11082) * 3 / 4 + MEM(9094) * 3 / 4 + MEM(8274) * 3 / 4 + MEM(5981) * 3 / 4 + MEM(4738) * 3 / 4;
	tmp_5 = Acc;
	Acc = MEM(16362) * 3 / 4 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16315) * 3 / 4 + MEM(16362);
	MEM(16360) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16229) * 3 / 4 + MEM(16315);
	MEM(16313) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16112) * 3 / 4 + MEM(16229);
	MEM(16227) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15964) * 3 / 4 + MEM(16112);
	MEM(16110) = -Acc;
	Acc = Acc * -9 / 8 + MEM(15964) * 3 / 2;
	tmp_b = Acc;
	Acc = MEM(15094) / 2 + MEM(13067) / 2;
	MEM(13745) = -Acc;
	Acc = -Acc / 2 + MEM(13067);
	MEM(15092) = Acc;
	Acc = MEM(13747) / 2 + MEM(12753) / 2;
	MEM(13065) = -Acc;
	Acc = -Acc / 2 + MEM(12753) + MEM(3635) / 2;
	MEM(3636) = Acc;
	Acc = MEM(3636) / 2 + tmp_b / 2;
	MEM(15962) = Acc;
	Acc = MEM(11361) / 2 + MEM(9892) / 2;
	MEM(10568) = -Acc;
	Acc = -Acc / 2 + MEM(9892);
	MEM(11359) = Acc;
	Acc = MEM(10570) / 2 + MEM(9459) / 2;
	MEM(9890) = -Acc;
	Acc = -Acc / 2 + MEM(9459) + MEM(3632) / 2;
	MEM(3633) = Acc;
	Acc = MEM(3633) / 2 + tmp_b / 2;
	MEM(12751) = Acc;
	Acc = MEM(8484) / 2 + MEM(6787) / 2;
	MEM(7499) = -Acc;
	Acc = -Acc / 2 + MEM(6787);
	MEM(8482) = Acc;
	Acc = MEM(7501) / 2 + MEM(6404) / 2;
	MEM(6785) = -Acc;
	Acc = -Acc / 2 + MEM(6404) + MEM(3629) / 2;
	MEM(3630) = Acc;
	*out_left = tmp_5;
	Acc = MEM(3630) / 2 + tmp_b;
	MEM(9457) = Acc;
	Acc = MEM(5631) / 2 + MEM(3972) / 2;
	MEM(4606) = -Acc;
	Acc = -Acc / 2 + MEM(3972);
	MEM(5629) = Acc;
	Acc = MEM(4608) / 2 + MEM(3638) / 2;
	MEM(3970) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + MEM(3638) + MEM(3626) / 2;
	MEM(3627) = Acc;
	Acc = MEM(3627) / 2 + tmp_b;
	MEM(6402) = Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_3(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15642) * 3 / 4 + MEM(14358) * 3 / 4 + MEM(12299) * 3 / 4 + MEM(10681) * 3 / 4 + MEM(8488) * 3 / 4 + MEM(7122) * 3 / 4 + MEM(4718) * 3 / 4 + MEM(4254) * 3 / 4;
	tmp_3 = Acc;
	Acc = MEM(15833) * 3 / 4 + MEM(14962) * 3 / 4 + MEM(11692) * 3 / 4 + MEM(10882) * 3 / 4 + MEM(8294) * 3 / 4 + MEM(7413) * 3 / 4 + MEM(5020) * 3 / 4 + MEM(3577) * 3 / 4;
	tmp_5 = Acc;
	Acc = MEM(16362) * 3 / 4 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16315) * 3 / 4 + MEM(16362);
	MEM(16360) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16229) * 3 / 4 + MEM(16315);
	MEM(16313) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16112) * 3 / 4 + MEM(16229);
	MEM(16227) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15964) * 3 / 4 + MEM(16112);
	MEM(16110) = -Acc;
	Acc = Acc * -9 / 8 + MEM(15964) * 3 / 2;
	tmp_b = Acc;
	Acc = MEM(15094) / 2 + MEM(13067) / 2;
	MEM(13745) = -Acc;
	Acc = -Acc / 2 + MEM(13067);
	MEM(15092) = Acc;
	Acc = MEM(13747) / 2 + MEM(12553) / 2;
	MEM(13065) = -Acc;
	Acc = -Acc / 2 + MEM(12553) + MEM(2474) / 2;
	MEM(2475) = Acc;
	Acc = MEM(2475) / 2 + tmp_b / 2;
	MEM(15962) = Acc;
	Acc = MEM(11161) / 2 + MEM(9492) / 2;
	MEM(10168) = -Acc;
	Acc = -Acc / 2 + MEM(9492);
	MEM(11159) = Acc;
	Acc = MEM(10170) / 2 + MEM(8859) / 2;
	MEM(9490) = -Acc;
	Acc = -Acc / 2 + MEM(8859) + MEM(2471) / 2;
	MEM(2472) = Acc;
	Acc = MEM(2472) / 2 + tmp_b / 2;
	MEM(12551) = Acc;
	Acc = MEM(7623) / 2 + MEM(5926) / 2;
	MEM(6638) = -Acc;
	Acc = -Acc / 2 + MEM(5926);
	MEM(7621) = Acc;
	Acc = MEM(6640) / 2 + MEM(5443) / 2;
	MEM(5924) = -Acc;
	Acc = -Acc / 2 + MEM(5443) + MEM(2468) / 2;
	MEM(2469) = Acc;
	*out_left = tmp_5;
	Acc = MEM(2469) / 2 + tmp_b;
	MEM(8857) = Acc;
	Acc = MEM(4470) / 2 + MEM(2811) / 2;
	MEM(3445) = -Acc;
	Acc = -Acc / 2 + MEM(2811);
	MEM(4468) = Acc;
	Acc = MEM(3447) / 2 + MEM(2477) / 2;
	MEM(2809) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + MEM(2477) + MEM(2465) / 2;
	MEM(2466) = Acc;
	Acc = MEM(2466) / 2 + tmp_b;
	MEM(5441) = Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_4(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(14524) * 9 / 8 + MEM(11076) * 9 / 8 + MEM(6177) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(14309) * 9 / 8 + MEM(11475) * 9 / 8 + MEM(7209) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(3606) / 2 + MEM(16383) / 2;
	MEM(3607) = Acc;
	Acc = MEM(3607) / 2 + MEM(16345) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16345) + MEM(16264) / 2;
	MEM(16343) = -Acc;
	Acc = -Acc / 2 + MEM(16264) + MEM(16104) / 2;
	MEM(16262) = -Acc;
	Acc = -Acc / 2 + MEM(16104) + MEM(15833) / 2;
	MEM(16102) = -Acc;
	Acc = -Acc / 2 + MEM(15833) + MEM(15487) / 2;
	MEM(15831) = -Acc;
	Acc = -Acc / 2 + MEM(15487) + MEM(14887) / 2;
	MEM(15485) = -Acc;
	Acc = Acc * -3 / 4 + MEM(14887) * 3 / 2;
	tmp_b = Acc;
	Acc = MEM(13261) / 2 + MEM(13260) / 2 + MEM(11867) / 2;
	MEM(13259) = -Acc;
	Acc = -Acc / 2 + MEM(11867);
	MEM(11865) = Acc;
	Acc = -MEM(9455) / 4 + MEM(7882) / 2;
	MEM(9453) = -Acc;
	Acc = -Acc / 2 + MEM(7882);
	MEM(7880) = Acc;
	Acc = MEM(5223) * 3 / 4 + MEM(3609) / 2;
	MEM(5221) = -Acc;
	Acc = -Acc / 2 + MEM(3609) + MEM(3603) / 2;
	MEM(3604) = Acc;
	Acc = MEM(3604) / 2 + tmp_b;
	MEM(14885) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_5(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15832) * 9 / 8 + MEM(14948) * 9 / 8 + MEM(14316) * 9 / 8 + MEM(13232) * 9 / 8 + MEM(10876) * 9 / 8 + MEM(10171) * 9 / 8 + MEM(9264) * 9 / 8 + MEM(8907) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(15823) * 9 / 8 + MEM(15152) * 9 / 8 + MEM(14109) * 9 / 8 + MEM(13433) * 9 / 8 + MEM(10882) * 9 / 8 + MEM(10462) * 9 / 8 + MEM(9536) * 9 / 8 + MEM(8223) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(6811) / 2 + MEM(16383) / 2;
	MEM(6812) = Acc;
	Acc = MEM(16362) * 3 / 4 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16315) * 3 / 4 + MEM(16362);
	MEM(16360) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16229) * 3 / 4 + MEM(16315);
	MEM(16313) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16112) * 3 / 4 + MEM(16229);
	MEM(16227) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15954) * 3 / 4 + MEM(16112);
	MEM(16110) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15954);
	tmp_b = Acc;
	Acc = MEM(15284) * 3 / 4 + MEM(12352) / 2;
	MEM(12830) = -Acc;
	Acc = -Acc / 2 + MEM(12352);
	MEM(15282) = Acc;
	Acc = MEM(14570) * 3 / 4 + MEM(12038) / 2;
	MEM(12350) = -Acc;
	Acc = -Acc / 2 + MEM(12038);
	MEM(14568) = Acc;
	Acc = MEM(13712) * 3 / 4 + MEM(11580) / 2;
	MEM(12036) = -Acc;
	Acc = -Acc / 2 + MEM(11580);
	MEM(13710) = Acc;
	Acc = MEM(12832) * 3 / 4 + MEM(11247) / 2;
	MEM(11578) = -Acc;
	Acc = -Acc / 2 + MEM(11247) + MEM(6808) / 2;
	MEM(6809) = Acc;
	Acc = MEM(6809) / 2 + tmp_b;
	MEM(15952) = Acc;
	Acc = MEM(10672) * 3 / 4 + MEM(7867) / 2;
	MEM(8279) = -Acc;
	Acc = -Acc / 2 + MEM(7867);
	MEM(10670) = Acc;
	*out_left = tmp_5;
	Acc = MEM(9989) * 3 / 4 + MEM(7484) / 2;
	MEM(7865) = -Acc;
	Acc = -Acc / 2 + MEM(7484);
	MEM(9987) = Acc;
	Acc = MEM(9116) * 3 / 4 + MEM(7048) / 2;
	MEM(7482) = -Acc;
	Acc = -Acc / 2 + MEM(7048);
	MEM(9114) = Acc;
	*out_right = tmp_3;
	Acc = MEM(8281) * 3 / 4 + MEM(6814) / 2;
	MEM(7046) = -Acc;
	Acc = -Acc / 2 + MEM(6814) + MEM(6805) / 2;
	MEM(6806) = Acc;
	Acc = MEM(6806) / 2 + tmp_b;
	MEM(11245) = Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_6(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(14321) * 9 / 8 + MEM(9847) * 9 / 8 + MEM(3057) * 9 / 8 + MEM(7027) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(13981) * 9 / 8 + MEM(10492) * 9 / 8 + MEM(3395) * 9 / 8 + MEM(6349) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(16184) * 5 / 8 + MEM(16284) / 2;
	MEM(16282) = -Acc;
	Acc = -Acc / 8 + MEM(15984) * 5 / 8 + MEM(16282) / 2 + MEM(16184);
	MEM(16182) = -Acc;
	Acc = -Acc / 8 + MEM(15615) * 5 / 8 + MEM(16182) / 2 + MEM(15984);
	MEM(15982) = -Acc;
	Acc = -Acc / 8 + MEM(15015) * 5 / 8 + MEM(15982) / 2 + MEM(15615);
	MEM(15613) = -Acc;
	Acc = -Acc / 8 + MEM(15613) / 2 + MEM(15015) + MEM(14668) / 2;
	MEM(15013) = -Acc;
	Acc = -Acc / 2 + MEM(14668);
	tmp_b = Acc;
	Acc = MEM(12463) / 2 + MEM(12462) / 2 + MEM(10836) / 2;
	MEM(12461) = -Acc;
	Acc = -Acc / 2 + MEM(10836);
	MEM(10834) = Acc;
	Acc = -MEM(8865) / 4 + MEM(7374) / 2;
	MEM(8863) = -Acc;
	Acc = -Acc / 2 + MEM(7374) + MEM(159) / 2;
	MEM(160) = Acc;
	Acc = MEM(160) / 2 + tmp_b;
	MEM(14666) = Acc;
	Acc = MEM(5438) / 2 + MEM(5437) / 2 + MEM(3737) / 2;
	MEM(5436) = -Acc;
	Acc = -Acc / 2 + MEM(3737);
	MEM(3735) = Acc;
	Acc = -MEM(1552) / 4 + MEM(165) / 2;
	MEM(1550) = -Acc;
	Acc = -Acc / 2 + MEM(165) + MEM(156) / 2;
	MEM(157) = Acc;
	Acc = MEM(157) / 2 + tmp_b;
	MEM(7372) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_7(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(13457) * 9 / 8 + MEM(9847) * 9 / 8 + MEM(3057) * 9 / 8 + MEM(6585) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(13981) * 9 / 8 + MEM(10492) * 9 / 8 + MEM(3395) * 9 / 8 + MEM(6349) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(16284) / 2 + MEM(162) / 2;
	MEM(163) = Acc;
	Acc = MEM(16184) * 5 / 8 + MEM(162) / 2;
	MEM(16282) = -Acc;
	Acc = -Acc / 8 + MEM(15984) * 5 / 8 + MEM(16282) / 2 + MEM(16184);
	MEM(16182) = -Acc;
	Acc = -Acc / 8 + MEM(15615) * 5 / 8 + MEM(16182) / 2 + MEM(15984);
	MEM(15982) = -Acc;
	Acc = -Acc / 8 + MEM(15015) * 5 / 8 + MEM(15982) / 2 + MEM(15615);
	MEM(15613) = -Acc;
	Acc = -Acc / 8 + MEM(15613) / 2 + MEM(15015) + MEM(14668) / 2;
	MEM(15013) = -Acc;
	Acc = -Acc / 2 + MEM(14668);
	tmp_b = Acc;
	Acc = MEM(12463) / 2 + MEM(12462) / 2 + MEM(10836) / 2;
	MEM(12461) = -Acc;
	Acc = -Acc / 2 + MEM(10836);
	MEM(10834) = Acc;
	Acc = -MEM(8865) / 4 + MEM(7374) / 2;
	MEM(8863) = -Acc;
	Acc = -Acc / 2 + MEM(7374) + MEM(159) / 2;
	MEM(160) = Acc;
	Acc = MEM(160) / 2 + tmp_b;
	MEM(14666) = Acc;
	Acc = MEM(5438) / 2 + MEM(5437) / 2 + MEM(3737) / 2;
	MEM(5436) = -Acc;
	Acc = -Acc / 2 + MEM(3737);
	MEM(3735) = Acc;
	Acc = -MEM(1552) / 4 + MEM(165) / 2;
	MEM(1550) = -Acc;
	Acc = -Acc / 2 + MEM(165) + MEM(156) / 2;
	MEM(157) = Acc;
	Acc = MEM(157) / 2 + tmp_b;
	MEM(7372) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_8(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15832) * 9 / 8 + MEM(14948) * 9 / 8 + MEM(14316) * 9 / 8 + MEM(13232) * 9 / 8 + MEM(10876) * 9 / 8 + MEM(10171) * 9 / 8 + MEM(9264) * 9 / 8 + MEM(8907) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(15823) * 9 / 8 + MEM(15152) * 9 / 8 + MEM(14109) * 9 / 8 + MEM(13433) * 9 / 8 + MEM(10882) * 9 / 8 + MEM(10462) * 9 / 8 + MEM(9536) * 9 / 8 + MEM(8223) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(6811) / 2 + MEM(16383) / 2;
	MEM(6812) = Acc;
	Acc = MEM(16362) * 3 / 4 + MEM(6812) / 2;
	MEM(16381) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16315) * 3 / 4 + MEM(16362);
	MEM(16360) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16229) * 3 / 4 + MEM(16315);
	MEM(16313) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16112) * 3 / 4 + MEM(16229);
	MEM(16227) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15954) * 3 / 4 + MEM(16112);
	MEM(16110) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15954);
	tmp_b = Acc;
	Acc = MEM(15284) * 3 / 4 + MEM(12352) / 2;
	MEM(12830) = -Acc;
	Acc = -Acc / 2 + MEM(12352);
	MEM(15282) = Acc;
	Acc = MEM(14570) * 3 / 4 + MEM(12038) / 2;
	MEM(12350) = -Acc;
	Acc = -Acc / 2 + MEM(12038);
	MEM(14568) = Acc;
	Acc = MEM(13712) * 3 / 4 + MEM(11580) / 2;
	MEM(12036) = -Acc;
	Acc = -Acc / 2 + MEM(11580);
	MEM(13710) = Acc;
	Acc = MEM(12832) * 3 / 4 + MEM(11247) / 2;
	MEM(11578) = -Acc;
	Acc = -Acc / 2 + MEM(11247) + MEM(6808) / 2;
	MEM(6809) = Acc;
	Acc = MEM(6809) / 2 + tmp_b;
	MEM(15952) = Acc;
	Acc = MEM(10672) * 3 / 4 + MEM(7867) / 2;
	MEM(8279) = -Acc;
	Acc = -Acc / 2 + MEM(7867);
	MEM(10670) = Acc;
	*out_left = tmp_5;
	Acc = MEM(9989) * 3 / 4 + MEM(7484) / 2;
	MEM(7865) = -Acc;
	Acc = -Acc / 2 + MEM(7484);
	MEM(9987) = Acc;
	Acc = MEM(9116) * 3 / 4 + MEM(7048) / 2;
	MEM(7482) = -Acc;
	Acc = -Acc / 2 + MEM(7048);
	MEM(9114) = Acc;
	*out_right = tmp_3;
	Acc = MEM(8281) * 3 / 4 + MEM(6814) / 2;
	MEM(7046) = -Acc;
	Acc = -Acc / 2 + MEM(6814) + MEM(6805) / 2;
	MEM(6806) = Acc;
	Acc = MEM(6806) / 2 + tmp_b;
	MEM(11245) = Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_9(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15802) * 9 / 8 + MEM(14618) * 9 / 8 + MEM(13886) * 9 / 8 + MEM(12702) * 9 / 8 + MEM(9278) * 9 / 8 + MEM(8273) * 9 / 8 + MEM(7566) * 9 / 8;
	tmp_3 = -Acc;
	Acc = MEM(15793) * 9 / 8 + MEM(14822) * 9 / 8 + MEM(13679) * 9 / 8 + MEM(12903) * 9 / 8 + MEM(9284) * 9 / 8 + MEM(8564) * 9 / 8 + MEM(6425) * 9 / 8;
	tmp_5 = -Acc;
	Acc = MEM(16383) / 2 + MEM(3036) / 2;
	MEM(3037) = Acc;
	Acc = MEM(16362) * 3 / 4 + MEM(3037) / 2;
	MEM(16381) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16315) * 3 / 4 + MEM(16362);
	MEM(16360) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16229) * 3 / 4 + MEM(16315);
	MEM(16313) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16102) * 3 / 4 + MEM(16229);
	MEM(16227) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15924) * 3 / 4 + MEM(16102);
	MEM(16100) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15924);
	tmp_b = -Acc;
	Acc = MEM(14954) * 5 / 8 + MEM(11754) / 2;
	MEM(12432) = -Acc;
	Acc = -Acc / 2 + MEM(11754);
	MEM(14952) = Acc;
	Acc = MEM(14140) / 2 + MEM(11240) / 2;
	MEM(11752) = -Acc;
	Acc = -Acc / 2 + MEM(11240);
	MEM(14138) = Acc;
	Acc = MEM(13182) * 5 / 8 + MEM(10482) / 2;
	MEM(11238) = -Acc;
	Acc = -Acc / 2 + MEM(10482);
	MEM(13180) = Acc;
	Acc = MEM(12434) * 5 / 8 + MEM(9649) / 2;
	MEM(10480) = -Acc;
	Acc = -Acc / 2 + MEM(9649) + tmp_b;
	MEM(15922) = Acc;
	Acc = MEM(8774) * 5 / 8 + MEM(5392) / 2;
	MEM(5904) = -Acc;
	Acc = -Acc / 2 + MEM(5392);
	MEM(8772) = Acc;
	*out_left = tmp_5;
	Acc = MEM(7891) / 2 + MEM(4609) / 2;
	MEM(5390) = -Acc;
	Acc = -Acc / 2 + MEM(4609);
	MEM(7889) = Acc;
	Acc = MEM(6918) * 5 / 8 + MEM(3973) / 2;
	MEM(4607) = -Acc;
	Acc = -Acc / 2 + MEM(3973);
	MEM(6916) = Acc;
	*out_right = tmp_3;
	Acc = MEM(5906) * 5 / 8 + MEM(3039) / 2;
	MEM(3971) = -Acc;
	Acc = -Acc / 2 + MEM(3039) + tmp_b;
	MEM(9647) = Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_10(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15802) * 9 / 8 + MEM(14618) * 9 / 8 + MEM(13886) * 9 / 8 + MEM(12702) * 9 / 8 + MEM(9278) * 9 / 8 + MEM(8273) * 9 / 8 + MEM(7566) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(15793) * 9 / 8 + MEM(14822) * 9 / 8 + MEM(13679) * 9 / 8 + MEM(12903) * 9 / 8 + MEM(9284) * 9 / 8 + MEM(8564) * 9 / 8 + MEM(6425) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(16362) * 3 / 4 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16315) * 3 / 4 + MEM(16362);
	MEM(16360) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16229) * 3 / 4 + MEM(16315);
	MEM(16313) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16102) * 3 / 4 + MEM(16229);
	MEM(16227) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15924) * 3 / 4 + MEM(16102);
	MEM(16100) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15924);
	tmp_b = Acc;
	Acc = MEM(14954) * 5 / 8 + MEM(11754) / 2;
	MEM(12432) = -Acc;
	Acc = -Acc / 2 + MEM(11754);
	MEM(14952) = Acc;
	Acc = MEM(14140) * 5 / 8 + MEM(11240) / 2;
	MEM(11752) = -Acc;
	Acc = -Acc / 2 + MEM(11240);
	MEM(14138) = Acc;
	Acc = MEM(13182) * 5 / 8 + MEM(10482) / 2;
	MEM(11238) = -Acc;
	Acc = -Acc / 2 + MEM(10482);
	MEM(13180) = Acc;
	Acc = MEM(12434) * 5 / 8 + MEM(9649) / 2;
	MEM(10480) = -Acc;
	Acc = -Acc / 2 + MEM(9649) + tmp_b;
	MEM(15922) = Acc;
	Acc = MEM(8774) * 5 / 8 + MEM(5392) / 2;
	MEM(5904) = -Acc;
	Acc = -Acc / 2 + MEM(5392);
	MEM(8772) = Acc;
	*out_left = tmp_5;
	Acc = MEM(7891) * 5 / 8 + MEM(4609) / 2;
	MEM(5390) = -Acc;
	Acc = -Acc / 2 + MEM(4609);
	MEM(7889) = Acc;
	Acc = MEM(6918) * 5 / 8 + MEM(3973) / 2;
	MEM(4607) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + MEM(3973);
	MEM(6916) = Acc;
	Acc = MEM(5906) * 5 / 8 + MEM(3039) / 2;
	MEM(3971) = -Acc;
	Acc = -Acc / 2 + MEM(3039) + tmp_b;
	MEM(9647) = Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_11(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15802) * 9 / 8 + MEM(14618) * 9 / 8 + MEM(13886) * 9 / 8 + MEM(12702) * 9 / 8 + MEM(9278) * 9 / 8 + MEM(8273) * 9 / 8 + MEM(7566) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(15793) * 9 / 8 + MEM(14822) * 9 / 8 + MEM(13679) * 9 / 8 + MEM(12903) * 9 / 8 + MEM(9284) * 9 / 8 + MEM(8564) * 9 / 8 + MEM(6425) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(16362) * 3 / 4 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16315) * 3 / 4 + MEM(16362);
	MEM(16360) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16229) * 3 / 4 + MEM(16315);
	MEM(16313) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16102) * 3 / 4 + MEM(16229);
	MEM(16227) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15924) * 3 / 4 + MEM(16102);
	MEM(16100) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15924);
	tmp_b = Acc;
	Acc = MEM(14954) * 3 / 4 + MEM(11754) / 2;
	MEM(12432) = -Acc;
	Acc = -Acc / 2 + MEM(11754);
	MEM(14952) = Acc;
	Acc = MEM(14140) * 3 / 4 + MEM(11240) / 2;
	MEM(11752) = -Acc;
	Acc = -Acc / 2 + MEM(11240);
	MEM(14138) = Acc;
	Acc = MEM(13182) * 5 / 8 + MEM(10482) / 2;
	MEM(11238) = -Acc;
	Acc = -Acc / 2 + MEM(10482);
	MEM(13180) = Acc;
	Acc = MEM(12434) * 5 / 8 + MEM(9649) / 2;
	MEM(10480) = -Acc;
	Acc = -Acc / 2 + MEM(9649) + MEM(3033) / 2;
	MEM(3034) = Acc;
	Acc = MEM(3034) / 2 + tmp_b;
	MEM(15922) = Acc;
	Acc = MEM(8774) * 3 / 4 + MEM(5392) / 2;
	MEM(5904) = -Acc;
	Acc = -Acc / 2 + MEM(5392);
	MEM(8772) = Acc;
	*out_left = tmp_5;
	Acc = MEM(7891) * 3 / 4 + MEM(4609) / 2;
	MEM(5390) = -Acc;
	Acc = -Acc / 2 + MEM(4609);
	MEM(7889) = Acc;
	Acc = MEM(6918) * 5 / 8 + MEM(3973) / 2;
	MEM(4607) = -Acc;
	Acc = -Acc / 2 + MEM(3973);
	MEM(6916) = Acc;
	*out_right = tmp_3;
	Acc = MEM(5906) * 5 / 8 + MEM(3039) / 2;
	MEM(3971) = -Acc;
	Acc = -Acc / 2 + MEM(3039) + MEM(3030) / 2;
	MEM(3031) = Acc;
	Acc = MEM(3031) / 2 + tmp_b;
	MEM(9647) = Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_12(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15380) * 3 / 4 + MEM(14258) * 3 / 4 + MEM(13526) * 3 / 4 + MEM(12744) * 3 / 4 + MEM(9255) * 3 / 4 + MEM(8388) * 3 / 4 + MEM(7181) * 3 / 4 + MEM(6640) * 3 / 4;
	tmp_3 = Acc;
	Acc = MEM(15047) * 3 / 4 + MEM(14364) * 3 / 4 + MEM(13523) * 3 / 4 + MEM(12745) * 3 / 4 + MEM(9255) * 3 / 4 + MEM(8679) * 3 / 4 + MEM(7681) * 3 / 4 + MEM(6140) * 3 / 4;
	tmp_5 = Acc;
	Acc = MEM(3851) / 2 + MEM(15933) / 2;
	MEM(3852) = Acc;
	Acc = MEM(15924) * 3 / 4 + MEM(15933) / 2;
	MEM(15931) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15907) * 3 / 4 + MEM(15924);
	MEM(15922) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15871) * 3 / 4 + MEM(15907);
	MEM(15905) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15794) * 3 / 4 + MEM(15871);
	MEM(15869) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15657) * 3 / 4 + MEM(15794);
	MEM(15792) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15419) * 3 / 4 + MEM(15657);
	MEM(15655) = -Acc;
	Acc = Acc * -9 / 8 + MEM(15419) * 3 / 2;
	tmp_b = Acc;
	Acc = MEM(14596) / 2 + MEM(14595) / 2 + MEM(11453) / 2;
	MEM(12242) = -Acc;
	Acc = -Acc / 2 + MEM(11453);
	MEM(14594) = Acc;
	Acc = MEM(13982) / 2 + MEM(13981) / 2 + MEM(11039) / 2;
	MEM(11451) = -Acc;
	Acc = -Acc / 2 + MEM(11039);
	MEM(13980) = Acc;
	Acc = MEM(13224) * -3 / 8 + MEM(13223) * -3 / 8 + MEM(10359) / 2;
	MEM(11037) = -Acc;
	Acc = -Acc / 2 + MEM(10359);
	MEM(13222) = Acc;
	Acc = MEM(12244) / 2 + MEM(9826) / 2;
	MEM(10357) = -Acc;
	Acc = -Acc / 2 + MEM(9826);
	MEM(9824) = Acc;
	Acc = MEM(8889) * 3 / 4 + MEM(5207) / 2;
	MEM(5819) = -Acc;
	Acc = -Acc / 2 + MEM(5207);
	MEM(8887) = Acc;
	*out_left = tmp_5;
	Acc = MEM(7906) * -3 / 8 + MEM(7905) * -3 / 8 + MEM(4824) / 2;
	MEM(5205) = -Acc;
	Acc = -Acc / 2 + MEM(4824);
	MEM(7904) = Acc;
	Acc = MEM(7033) * 3 / 4 + MEM(4288) / 2;
	MEM(4822) = -Acc;
	Acc = -Acc / 2 + MEM(4288);
	MEM(7031) = Acc;
	*out_right = tmp_3;
	Acc = MEM(5821) * 3 / 4 + MEM(3854) / 2;
	MEM(4286) = -Acc;
	Acc = Acc / 4 + -MEM(3854) / 2 + MEM(3845) / 2;
	MEM(3846) = Acc;
	Acc = MEM(3846) + tmp_b;
	MEM(15417) = Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_13(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15380) * 3 / 4 + MEM(14558) * 3 / 4 + MEM(13926) * 3 / 4 + MEM(13444) * 3 / 4 + MEM(9512) * 3 / 4 + MEM(8645) * 3 / 4 + MEM(7438) * 3 / 4 + MEM(6897) * 3 / 4;
	tmp_3 = Acc;
	Acc = MEM(15380) * 3 / 4 + MEM(14564) * 3 / 4 + MEM(13923) * 3 / 4 + MEM(13445) * 3 / 4 + MEM(9512) * 3 / 4 + MEM(8636) * 3 / 4 + MEM(7938) * 3 / 4 + MEM(6397) * 3 / 4;
	tmp_5 = Acc;
	Acc = MEM(3508) / 2 + MEM(15933) / 2;
	MEM(3509) = Acc;
	Acc = MEM(15924) * 3 / 4 + MEM(15933) / 2;
	MEM(15931) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15907) * 3 / 4 + MEM(15924);
	MEM(15922) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15871) * 3 / 4 + MEM(15907);
	MEM(15905) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15794) * 3 / 4 + MEM(15871);
	MEM(15869) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15657) * 3 / 4 + MEM(15794);
	MEM(15792) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15419) * 3 / 4 + MEM(15657);
	MEM(15655) = -Acc;
	Acc = Acc * -9 / 8 + MEM(15419) * 3 / 2;
	tmp_b = Acc;
	Acc = MEM(14796) / 2 + MEM(14795) / 2 + MEM(12553) / 2;
	MEM(13342) = -Acc;
	Acc = -Acc / 2 + MEM(12553);
	MEM(14794) = Acc;
	Acc = MEM(14382) / 2 + MEM(14381) / 2 + MEM(11639) / 2;
	MEM(12551) = -Acc;
	Acc = -Acc / 2 + MEM(11639);
	MEM(14380) = Acc;
	Acc = MEM(13924) * -3 / 8 + MEM(13923) * -3 / 8 + MEM(10616) / 2;
	MEM(11637) = -Acc;
	Acc = -Acc / 2 + MEM(10616);
	MEM(13922) = Acc;
	Acc = MEM(13344) / 2 + MEM(10083) / 2;
	MEM(10614) = -Acc;
	Acc = -Acc / 2 + MEM(10083);
	MEM(10081) = Acc;
	Acc = MEM(9146) * 3 / 4 + MEM(5364) / 2;
	MEM(6076) = -Acc;
	Acc = -Acc / 2 + MEM(5364);
	MEM(9144) = Acc;
	*out_left = tmp_5;
	Acc = MEM(8163) * -3 / 8 + MEM(8162) * -3 / 8 + MEM(4981) / 2;
	MEM(5362) = -Acc;
	Acc = -Acc / 2 + MEM(4981);
	MEM(8161) = Acc;
	Acc = MEM(7290) * 3 / 4 + MEM(4345) / 2;
	MEM(4979) = -Acc;
	Acc = -Acc / 2 + MEM(4345);
	MEM(7288) = Acc;
	*out_right = tmp_3;
	Acc = MEM(6078) * 3 / 4 + MEM(3511) / 2;
	MEM(4343) = -Acc;
	Acc = Acc / 4 + -MEM(3511) / 2 + MEM(3502) / 2;
	MEM(3503) = Acc;
	Acc = MEM(3503) + tmp_b;
	MEM(15417) = Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_14(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15802) * 9 / 8 + MEM(14918) * 9 / 8 + MEM(14186) * 9 / 8 + MEM(13002) * 9 / 8 + MEM(9314) * 9 / 8 + MEM(8509) * 9 / 8 + MEM(7402) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(15793) * 9 / 8 + MEM(15122) * 9 / 8 + MEM(13979) * 9 / 8 + MEM(13203) * 9 / 8 + MEM(9320) * 9 / 8 + MEM(8800) * 9 / 8 + MEM(6261) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(3072) / 2 + MEM(16383) / 2;
	MEM(3073) = Acc;
	Acc = MEM(16362) * 3 / 4 + MEM(3072) / 2;
	MEM(16381) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16315) * 3 / 4 + MEM(16362);
	MEM(16360) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16229) * 3 / 4 + MEM(16315);
	MEM(16313) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16102) * 3 / 4 + MEM(16229);
	MEM(16227) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15924) * 3 / 4 + MEM(16102);
	MEM(16100) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15924);
	tmp_b = Acc;
	Acc = MEM(15254) * 3 / 4 + MEM(11790) / 2;
	MEM(12468) = -Acc;
	Acc = -Acc / 2 + MEM(11790);
	MEM(15252) = Acc;
	Acc = MEM(14440) * 3 / 4 + MEM(11276) / 2;
	MEM(11788) = -Acc;
	Acc = -Acc / 2 + MEM(11276);
	MEM(14438) = Acc;
	Acc = MEM(13482) * 3 / 4 + MEM(10518) / 2;
	MEM(11274) = -Acc;
	Acc = -Acc / 2 + MEM(10518);
	MEM(13480) = Acc;
	Acc = MEM(12470) * 3 / 4 + MEM(9685) / 2;
	MEM(10516) = -Acc;
	Acc = -Acc / 2 + MEM(9685) + tmp_b;
	MEM(15922) = Acc;
	Acc = MEM(9010) * 3 / 4 + MEM(5428) / 2;
	MEM(5940) = -Acc;
	Acc = -Acc / 2 + MEM(5428);
	MEM(9008) = Acc;
	Acc = MEM(8127) * 3 / 4 + MEM(4645) / 2;
	MEM(5426) = -Acc;
	Acc = -Acc / 2 + MEM(4645);
	MEM(8125) = Acc;
	*out_left = tmp_5;
	Acc = MEM(7154) * 3 / 4 + MEM(4009) / 2;
	MEM(4643) = -Acc;
	Acc = -Acc / 2 + MEM(4009);
	MEM(7152) = Acc;
	Acc = MEM(5942) * 3 / 4 + MEM(3075) / 2;
	MEM(4007) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + MEM(3075) + tmp_b;
	MEM(9683) = Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_15(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15402) * 9 / 8 + MEM(14618) * 9 / 8 + MEM(13886) * 9 / 8 + MEM(12702) * 9 / 8 + MEM(8814) * 9 / 8 + MEM(7909) * 9 / 8 + MEM(6802) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(15793) * 9 / 8 + MEM(14822) * 9 / 8 + MEM(13679) * 9 / 8 + MEM(12903) * 9 / 8 + MEM(8820) * 9 / 8 + MEM(8200) * 9 / 8 + MEM(5661) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(2472) / 2 + MEM(16383) / 2;
	MEM(2473) = Acc;
	Acc = MEM(16362) * 3 / 4 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16315) * 3 / 4 + MEM(16362);
	MEM(16360) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16229) * 3 / 4 + MEM(16315);
	MEM(16313) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16102) * 3 / 4 + MEM(16229);
	MEM(16227) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15924) * 3 / 4 + MEM(16102);
	MEM(16100) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15924);
	tmp_b = Acc;
	Acc = MEM(14954) * 3 / 4 + MEM(11390) / 2;
	MEM(12068) = -Acc;
	Acc = -Acc / 2 + MEM(11390);
	MEM(14952) = Acc;
	Acc = MEM(14140) * 3 / 4 + MEM(10776) / 2;
	MEM(11388) = -Acc;
	Acc = -Acc / 2 + MEM(10776);
	MEM(14138) = Acc;
	Acc = MEM(13182) * 3 / 4 + MEM(10018) / 2;
	MEM(10774) = -Acc;
	Acc = -Acc / 2 + MEM(10018);
	MEM(13180) = Acc;
	Acc = MEM(12070) * 3 / 4 + MEM(9185) / 2;
	MEM(10016) = -Acc;
	Acc = -Acc / 2 + MEM(9185) + MEM(2469) / 2;
	MEM(2470) = Acc;
	Acc = MEM(2470) / 2 + tmp_b;
	MEM(15922) = Acc;
	Acc = MEM(8410) * 3 / 4 + MEM(4828) / 2;
	MEM(5340) = -Acc;
	Acc = -Acc / 2 + MEM(4828);
	MEM(8408) = Acc;
	Acc = MEM(7527) * 3 / 4 + MEM(4045) / 2;
	MEM(4826) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + MEM(4045);
	MEM(7525) = Acc;
	Acc = MEM(6554) * 3 / 4 + MEM(3409) / 2;
	MEM(4043) = -Acc;
	Acc = -Acc / 2 + MEM(3409);
	MEM(6552) = Acc;
	Acc = MEM(5342) * 3 / 4 + MEM(2475) / 2;
	MEM(3407) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + MEM(2475) + MEM(2466) / 2;
	MEM(2467) = Acc;
	Acc = MEM(2467) / 2 + tmp_b;
	MEM(9183) = Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_16(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15802) * 9 / 8 + MEM(14918) * 9 / 8 + MEM(14186) * 9 / 8 + MEM(13002) * 9 / 8 + MEM(9314) * 9 / 8 + MEM(8509) * 9 / 8 + MEM(7402) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(15793) * 9 / 8 + MEM(15122) * 9 / 8 + MEM(13979) * 9 / 8 + MEM(13203) * 9 / 8 + MEM(9320) * 9 / 8 + MEM(8800) * 9 / 8 + MEM(6261) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(3072) / 2 + MEM(16383) / 2;
	MEM(3073) = Acc;
	Acc = MEM(16362) * 3 / 4 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16315) * 3 / 4 + MEM(16362);
	MEM(16360) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16229) * 3 / 4 + MEM(16315);
	MEM(16313) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16102) * 3 / 4 + MEM(16229);
	MEM(16227) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15924) * 3 / 4 + MEM(16102);
	MEM(16100) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15924);
	tmp_b = Acc;
	Acc = MEM(15254) * 3 / 4 + MEM(11790) / 2;
	MEM(12468) = -Acc;
	Acc = -Acc / 2 + MEM(11790);
	MEM(15252) = Acc;
	Acc = MEM(14440) * 3 / 4 + MEM(11276) / 2;
	MEM(11788) = -Acc;
	Acc = -Acc / 2 + MEM(11276);
	MEM(14438) = Acc;
	Acc = MEM(13482) * 3 / 4 + MEM(10518) / 2;
	MEM(11274) = -Acc;
	Acc = -Acc / 2 + MEM(10518);
	MEM(13480) = Acc;
	Acc = MEM(12470) * 3 / 4 + MEM(9685) / 2;
	MEM(10516) = -Acc;
	Acc = -Acc / 2 + MEM(9685) + tmp_b;
	MEM(15922) = Acc;
	Acc = MEM(9010) * 3 / 4 + MEM(5428) / 2;
	MEM(5940) = -Acc;
	Acc = -Acc / 2 + MEM(5428);
	MEM(9008) = Acc;
	Acc = MEM(8127) * 3 / 4 + MEM(4645) / 2;
	MEM(5426) = -Acc;
	Acc = -Acc / 2 + MEM(4645);
	MEM(8125) = Acc;
	*out_left = tmp_5;
	Acc = MEM(7154) * 3 / 4 + MEM(4009) / 2;
	MEM(4643) = -Acc;
	Acc = -Acc / 2 + MEM(4009);
	MEM(7152) = Acc;
	Acc = MEM(5942) * 3 / 4 + MEM(3075) / 2;
	MEM(4007) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + MEM(3075) + tmp_b;
	MEM(9683) = Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_17(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(13126) * 3 / 4 + MEM(9026) * 3 / 4 + MEM(5429) * 3 / 4;
	tmp_3 = Acc;
	Acc = MEM(13126) * 3 / 4 + MEM(9727) * 3 / 4 + MEM(6361) * 3 / 4;
	tmp_5 = Acc;
	Acc = MEM(15927) / 2 + MEM(3758) / 2;
	MEM(3759) = Acc;
	Acc = MEM(15927) / 2 + MEM(15604) / 2;
	MEM(15925) = -Acc;
	Acc = -Acc / 2 + MEM(15604) + MEM(15171) / 2;
	MEM(15602) = -Acc;
	Acc = -Acc / 2 + MEM(15171) + MEM(14501) / 2;
	MEM(15169) = -Acc;
	Acc = -Acc / 2 + MEM(14501) + MEM(13691) / 2;
	MEM(14499) = -Acc;
	Acc = -Acc / 2 + MEM(13691) + MEM(13485) / 2;
	MEM(13689) = -Acc;
	Acc = -Acc / 2 + MEM(13485) + MEM(13339) / 2;
	MEM(13483) = -Acc;
	Acc = Acc * -9 / 8 + MEM(13339) * 9 / 4;
	tmp_b = Acc;
	Acc = MEM(11613) * 3 / 4 + MEM(10419) / 2;
	MEM(11611) = -Acc;
	Acc = -Acc / 2 + MEM(10419);
	MEM(10417) = Acc;
	Acc = MEM(7907) * 5 / 8 + MEM(6834) / 2;
	MEM(7905) = -Acc;
	Acc = -Acc / 2 + MEM(6834);
	MEM(6832) = Acc;
	Acc = MEM(4975) * 5 / 8 + MEM(3761) / 2;
	MEM(4973) = -Acc;
	Acc = -Acc / 2 + MEM(3761) + MEM(3755) / 2;
	MEM(3756) = Acc;
	Acc = MEM(3756) / 2 + tmp_b;
	MEM(13337) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_18(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(13582) * 3 / 4 + MEM(9282) * 3 / 4 + MEM(5385) * 3 / 4;
	tmp_3 = Acc;
	Acc = MEM(12692) * 3 / 4 + MEM(9983) * 3 / 4 + MEM(6317) * 3 / 4;
	tmp_5 = Acc;
	Acc = MEM(16383) / 2 + MEM(3414) / 2;
	MEM(3415) = Acc;
	Acc = MEM(3415) / 2 + MEM(16060) / 2;
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
	Acc = Acc * -9 / 8 + MEM(13795) * 9 / 4;
	tmp_b = Acc;
	Acc = MEM(12069) * 3 / 4 + MEM(10675) / 2;
	MEM(12067) = -Acc;
	Acc = -Acc / 2 + MEM(10675);
	MEM(10673) = Acc;
	Acc = MEM(8163) * 5 / 8 + MEM(6790) / 2;
	MEM(8161) = -Acc;
	Acc = -Acc / 2 + MEM(6790);
	MEM(6788) = Acc;
	Acc = MEM(4931) * 5 / 8 + MEM(3417) / 2;
	MEM(4929) = -Acc;
	Acc = -Acc / 2 + MEM(3417) + MEM(3411) / 2;
	MEM(3412) = Acc;
	Acc = MEM(3412) / 2 + tmp_b;
	MEM(13793) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_19(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(13190) * 3 / 4 + MEM(10048) * 3 / 4 + MEM(5417) * 3 / 4 + MEM(16206) * 3 / 4;
	tmp_5 = Acc;
	Acc = MEM(12751) * 3 / 4 + MEM(10577) * 3 / 4 + MEM(5805) * 3 / 4 + MEM(15873) * 3 / 4;
	tmp_3 = Acc;
	Acc = MEM(14324) * 5 / 8 + MEM(14384) / 2;
	MEM(14382) = -Acc;
	Acc = MEM(14233) * 5 / 8 + MEM(14382) * 5 / 8 + MEM(14324);
	MEM(14322) = -Acc;
	Acc = MEM(14048) * 5 / 8 + MEM(14322) * 5 / 8 + MEM(14233);
	MEM(14231) = -Acc;
	Acc = MEM(13725) * 5 / 8 + MEM(14231) * 5 / 8 + MEM(14048);
	MEM(14046) = -Acc;
	Acc = MEM(13256) * 5 / 8 + MEM(14046) * 5 / 8 + MEM(13725);
	MEM(13723) = -Acc;
	Acc = Acc * -3 / 16 + MEM(13723) * 3 / 4 + MEM(13256) * 3 / 2;
	tmp_b = Acc;
	Acc = MEM(11869) * 3 / 4 + MEM(10746) / 2;
	MEM(11867) = -Acc;
	Acc = -Acc / 2 + MEM(10746);
	MEM(10744) = Acc;
	Acc = MEM(9103) * 3 / 4 + MEM(8081) / 2;
	MEM(9101) = -Acc;
	Acc = -Acc / 2 + MEM(8081);
	tmp_1 = Acc;
	Acc = MEM(3433) / 2 + tmp_1 / 2;
	MEM(3434) = Acc;
	Acc = MEM(3433) + tmp_b;
	MEM(13254) = Acc;
	Acc = MEM(6868) * 3 / 4 + MEM(5958) / 2;
	MEM(6866) = -Acc;
	Acc = -Acc / 2 + MEM(5958);
	MEM(5956) = Acc;
	Acc = MEM(4539) * 3 / 4 + MEM(3439) / 2;
	MEM(4537) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + MEM(3439);
	tmp_1 = Acc;
	Acc = MEM(3430) / 2 + tmp_1 / 2;
	MEM(3431) = Acc;
	Acc = MEM(3430) + tmp_b;
	MEM(8079) = Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_20(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_1, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15189) * 3 / 4 + MEM(12587) * 3 / 4 + MEM(8047) * 3 / 4 + MEM(16206) * 3 / 4;
	tmp_5 = Acc;
	Acc = MEM(14750) * 3 / 4 + MEM(13116) * 3 / 4 + MEM(8435) * 3 / 4 + MEM(15873) * 3 / 4;
	tmp_3 = Acc;
	Acc = MEM(16323) * 5 / 8 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = MEM(16232) * 5 / 8 + MEM(16381) * 5 / 8 + MEM(16323);
	MEM(16321) = -Acc;
	Acc = MEM(16047) * 5 / 8 + MEM(16321) * 5 / 8 + MEM(16232);
	MEM(16230) = -Acc;
	Acc = MEM(15724) * 5 / 8 + MEM(16230) * 5 / 8 + MEM(16047);
	MEM(16045) = -Acc;
	Acc = MEM(15255) * 5 / 8 + MEM(16045) * 5 / 8 + MEM(15724);
	MEM(15722) = -Acc;
	Acc = Acc * -3 / 16 + MEM(15722) * 3 / 4 + MEM(15255) * 3 / 2;
	tmp_b = Acc;
	Acc = MEM(14408) * 3 / 4 + MEM(13285) / 2;
	MEM(14406) = -Acc;
	Acc = -Acc / 2 + MEM(13285);
	MEM(13283) = Acc;
	Acc = MEM(11842) * 3 / 4 + MEM(10520) / 2;
	MEM(11840) = -Acc;
	Acc = -Acc / 2 + MEM(10520);
	tmp_1 = Acc;
	Acc = MEM(6263) / 2 + tmp_1 / 2;
	MEM(6264) = Acc;
	Acc = MEM(6263) + tmp_b;
	MEM(15253) = Acc;
	Acc = MEM(9606) * 3 / 4 + MEM(8588) / 2;
	MEM(9604) = -Acc;
	Acc = -Acc / 2 + MEM(8588);
	MEM(8586) = Acc;
	Acc = MEM(7569) * 3 / 4 + MEM(6269) / 2;
	MEM(7567) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + MEM(6269);
	tmp_1 = Acc;
	Acc = MEM(6260) / 2 + tmp_1 / 2;
	MEM(6261) = Acc;
	Acc = MEM(6260) + tmp_b;
	MEM(10518) = Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_21(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15702) * 3 / 4 + MEM(14318) * 3 / 4 + MEM(13353) * 3 / 4 + MEM(12291) * 3 / 4 + MEM(7856) * 3 / 4 + MEM(6974) * 3 / 4 + MEM(5476) * 3 / 4;
	tmp_3 = Acc;
	Acc = MEM(15693) * 3 / 4 + MEM(14822) * 3 / 4 + MEM(13546) * 3 / 4 + MEM(12492) * 3 / 4 + MEM(7862) * 3 / 4 + MEM(6683) * 3 / 4 + MEM(4205) * 3 / 4;
	tmp_5 = Acc;
	Acc = MEM(364) / 2 + MEM(16383) / 2;
	MEM(365) = Acc;
	Acc = MEM(16362) * 3 / 4 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16315) * 3 / 4 + MEM(16362);
	MEM(16360) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16229) * 3 / 4 + MEM(16315);
	MEM(16313) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16102) * 3 / 4 + MEM(16229);
	MEM(16227) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15824) * 3 / 4 + MEM(16102);
	MEM(16100) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15824);
	tmp_b = Acc;
	Acc = MEM(14954) * 3 / 4 + MEM(10922) / 2;
	MEM(11800) = -Acc;
	Acc = -Acc / 2 + MEM(10922);
	MEM(14952) = Acc;
	Acc = MEM(13907) * 3 / 4 + MEM(10208) / 2;
	MEM(10920) = -Acc;
	Acc = -Acc / 2 + MEM(10208);
	MEM(13905) = Acc;
	Acc = MEM(12771) / 2 + MEM(12770) / 2 + MEM(9250) / 2;
	MEM(10206) = -Acc;
	Acc = -Acc / 2 + MEM(9250);
	MEM(12769) = Acc;
	Acc = MEM(11802) / 2 + MEM(11801) / 2 + MEM(8227) / 2;
	MEM(9248) = -Acc;
	Acc = -Acc / 2 + MEM(8227) + tmp_b;
	MEM(15822) = Acc;
	Acc = MEM(7184) * 3 / 4 + MEM(3272) / 2;
	MEM(4084) = -Acc;
	Acc = -Acc / 2 + MEM(3272);
	MEM(7182) = Acc;
	Acc = MEM(6201) * 3 / 4 + MEM(2289) / 2;
	MEM(3270) = -Acc;
	Acc = -Acc / 2 + MEM(2289);
	MEM(6199) = Acc;
	*out_left = tmp_5;
	Acc = MEM(5098) / 2 + MEM(5097) / 2 + MEM(1353) / 2;
	MEM(2287) = -Acc;
	Acc = -Acc / 2 + MEM(1353);
	MEM(5096) = Acc;
	Acc = MEM(4086) / 2 + MEM(4085) / 2 + MEM(367) / 2;
	MEM(1351) = -Acc;
	Acc = -Acc / 2 + MEM(367) + tmp_b;
	MEM(8225) = Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_22(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15402) * 3 / 4 + MEM(13983) * 3 / 4 + MEM(13018) * 3 / 4 + MEM(11956) * 3 / 4 + MEM(8830) * 3 / 4 + MEM(7848) * 3 / 4 + MEM(6350) * 3 / 4;
	tmp_3 = Acc;
	Acc = MEM(15693) * 3 / 4 + MEM(14487) * 3 / 4 + MEM(13211) * 3 / 4 + MEM(12157) * 3 / 4 + MEM(8736) * 3 / 4 + MEM(7557) * 3 / 4 + MEM(5079) * 3 / 4;
	tmp_5 = Acc;
	Acc = MEM(2618) / 2 + MEM(16383) / 2;
	MEM(2619) = Acc;
	Acc = MEM(16362) * 3 / 4 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16315) * 3 / 4 + MEM(16362);
	MEM(16360) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16229) * 3 / 4 + MEM(16315);
	MEM(16313) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16102) * 3 / 4 + MEM(16229);
	MEM(16227) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15824) * 3 / 4 + MEM(16102);
	MEM(16100) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15824);
	tmp_b = Acc;
	Acc = MEM(14619) * 3 / 4 + MEM(10887) / 2;
	MEM(11465) = -Acc;
	Acc = -Acc / 2 + MEM(10887);
	MEM(14617) = Acc;
	Acc = MEM(13572) * 3 / 4 + MEM(10173) / 2;
	MEM(10885) = -Acc;
	Acc = -Acc / 2 + MEM(10173);
	MEM(13570) = Acc;
	Acc = MEM(12436) / 2 + MEM(12435) / 2 + MEM(9415) / 2;
	MEM(10171) = -Acc;
	Acc = -Acc / 2 + MEM(9415);
	MEM(12434) = Acc;
	Acc = MEM(11467) / 2 + MEM(11466) / 2 + MEM(9101) / 2;
	MEM(9413) = -Acc;
	Acc = -Acc / 2 + MEM(9101) + tmp_b;
	MEM(15822) = Acc;
	Acc = MEM(8058) * 3 / 4 + MEM(4346) / 2;
	MEM(4958) = -Acc;
	Acc = -Acc / 2 + MEM(4346);
	MEM(8056) = Acc;
	Acc = MEM(7075) * 3 / 4 + MEM(3563) / 2;
	MEM(4344) = -Acc;
	Acc = -Acc / 2 + MEM(3563);
	MEM(7073) = Acc;
	*out_left = tmp_5;
	Acc = MEM(5972) / 2 + MEM(5971) / 2 + MEM(2927) / 2;
	MEM(3561) = -Acc;
	Acc = -Acc / 2 + MEM(2927);
	MEM(5970) = Acc;
	Acc = MEM(4960) / 2 + MEM(4959) / 2 + MEM(2621) / 2;
	MEM(2925) = -Acc;
	Acc = -Acc / 2 + MEM(2621) + tmp_b;
	MEM(9099) = Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_23(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(12759) * 9 / 8 + MEM(7615) * 9 / 8 + MEM(3618) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(12136) * 9 / 8 + MEM(8616) * 9 / 8 + MEM(4950) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(16383) / 2 + MEM(1147) / 2;
	MEM(1148) = Acc;
	Acc = MEM(16383) / 2 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14957) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14957) + MEM(13720) / 2;
	MEM(14955) = -Acc;
	Acc = -Acc / 2 + MEM(13720) + MEM(13484) / 2;
	MEM(13718) = -Acc;
	Acc = -Acc / 2 + MEM(13484) + MEM(13328) / 2;
	MEM(13482) = -Acc;
	Acc = Acc * -3 / 4 + MEM(13328) * 3 / 2;
	tmp_b = Acc;
	Acc = MEM(11102) / 2 + MEM(9508) / 2;
	MEM(11100) = -Acc;
	Acc = -Acc / 2 + MEM(9508);
	MEM(9506) = Acc;
	Acc = MEM(6896) * 3 / 4 + MEM(5623) / 2;
	MEM(6894) = -Acc;
	Acc = -Acc / 2 + MEM(5623);
	MEM(5621) = Acc;
	Acc = MEM(2264) / 2 + MEM(1150) / 2;
	MEM(2262) = -Acc;
	Acc = -Acc / 2 + MEM(1150) + MEM(1144) / 2;
	MEM(1145) = Acc;
	Acc = MEM(1145) / 2 + tmp_b;
	MEM(13326) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_24(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(11760) * 9 / 8 + MEM(7116) * 9 / 8 + MEM(3156) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(11760) * 9 / 8 + MEM(8117) * 9 / 8 + MEM(4488) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(15384) / 2 + MEM(1011) / 2;
	MEM(1012) = Acc;
	Acc = MEM(1011) / 2 + MEM(15061) / 2;
	MEM(15382) = -Acc;
	Acc = -Acc / 2 + MEM(15061) + MEM(14628) / 2;
	MEM(15059) = -Acc;
	Acc = -Acc / 2 + MEM(14628) + MEM(13958) / 2;
	MEM(14626) = -Acc;
	Acc = -Acc / 2 + MEM(13958) + MEM(12721) / 2;
	MEM(13956) = -Acc;
	Acc = -Acc / 2 + MEM(12721) + MEM(12485) / 2;
	MEM(12719) = -Acc;
	Acc = -Acc / 2 + MEM(12485) + MEM(12329) / 2;
	MEM(12483) = -Acc;
	Acc = Acc * -3 / 4 + MEM(12329) * 3 / 2;
	tmp_b = Acc;
	Acc = MEM(10103) + MEM(9009) / 2;
	MEM(10101) = -Acc;
	Acc = -Acc / 2 + MEM(9009);
	MEM(9007) = Acc;
	Acc = MEM(6397) * 3 / 4 + MEM(5161) / 2;
	MEM(6395) = -Acc;
	Acc = -Acc / 2 + MEM(5161);
	MEM(5159) = Acc;
	Acc = MEM(1802) / 2 + MEM(1014) / 2;
	MEM(1800) = -Acc;
	Acc = -Acc / 2 + MEM(1014) + MEM(1008) / 2;
	MEM(1009) = Acc;
	Acc = MEM(1009) / 2 + tmp_b;
	MEM(12327) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_25(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(12759) * 9 / 8 + MEM(7615) * 9 / 8 + MEM(3618) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(12136) * 9 / 8 + MEM(8616) * 9 / 8 + MEM(4950) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(16383) / 2 + MEM(1147) / 2;
	MEM(1148) = Acc;
	Acc = MEM(1147) / 2 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14957) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14957) + MEM(13720) / 2;
	MEM(14955) = -Acc;
	Acc = -Acc / 2 + MEM(13720) + MEM(13484) / 2;
	MEM(13718) = -Acc;
	Acc = -Acc / 2 + MEM(13484) + MEM(13328) / 2;
	MEM(13482) = -Acc;
	Acc = Acc * -3 / 4 + MEM(13328) * 3 / 2;
	tmp_b = Acc;
	Acc = MEM(11102) + MEM(9508) / 2;
	MEM(11100) = -Acc;
	Acc = -Acc / 2 + MEM(9508);
	MEM(9506) = Acc;
	Acc = MEM(6896) * 3 / 4 + MEM(5623) / 2;
	MEM(6894) = -Acc;
	Acc = -Acc / 2 + MEM(5623);
	MEM(5621) = Acc;
	Acc = MEM(2264) / 2 + MEM(1150) / 2;
	MEM(2262) = -Acc;
	Acc = -Acc / 2 + MEM(1150) + MEM(1144) / 2;
	MEM(1145) = Acc;
	Acc = MEM(1145) / 2 + tmp_b;
	MEM(13326) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_26(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(12959) * 9 / 8 + MEM(8315) * 9 / 8 + MEM(4318) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(12959) * 9 / 8 + MEM(9316) * 9 / 8 + MEM(5650) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(16383) / 2 + MEM(1847) / 2;
	MEM(1848) = Acc;
	Acc = MEM(16383) / 2 + MEM(16060) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14957) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14957) + MEM(13920) / 2;
	MEM(14955) = -Acc;
	Acc = -Acc / 2 + MEM(13920) + MEM(13684) / 2;
	MEM(13918) = -Acc;
	Acc = -Acc / 2 + MEM(13684) + MEM(13528) / 2;
	MEM(13682) = -Acc;
	Acc = Acc * -3 / 4 + MEM(13528) * 3 / 2;
	tmp_b = Acc;
	Acc = MEM(11302) + MEM(10208) / 2;
	MEM(11300) = -Acc;
	Acc = -Acc / 2 + MEM(10208);
	MEM(10206) = Acc;
	Acc = MEM(7596) * 3 / 4 + MEM(6323) / 2;
	MEM(7594) = -Acc;
	Acc = -Acc / 2 + MEM(6323);
	MEM(6321) = Acc;
	Acc = MEM(2964) / 2 + MEM(1850) / 2;
	MEM(2962) = -Acc;
	Acc = -Acc / 2 + MEM(1850) + MEM(1844) / 2;
	MEM(1845) = Acc;
	Acc = MEM(1845) / 2 + tmp_b;
	MEM(13526) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_27(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15502) * 9 / 8 + MEM(14618) * 9 / 8 + MEM(13611) * 9 / 8 + MEM(11974) * 9 / 8 + MEM(8214) * 9 / 8 + MEM(7209) * 9 / 8 + MEM(6149) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(15793) * 9 / 8 + MEM(14822) * 9 / 8 + MEM(13404) * 9 / 8 + MEM(12175) * 9 / 8 + MEM(8220) * 9 / 8 + MEM(7500) * 9 / 8 + MEM(4534) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(16362) * 3 / 4 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16315) * 3 / 4 + MEM(16362);
	MEM(16360) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16229) * 3 / 4 + MEM(16315);
	MEM(16313) = -Acc;
	Acc = Acc * -3 / 4 + MEM(16102) * 3 / 4 + MEM(16229);
	MEM(16227) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15924) * 3 / 4 + MEM(16102);
	MEM(16100) = -Acc;
	Acc = Acc * -3 / 4 + MEM(15924);
	tmp_b = Acc;
	Acc = MEM(14954) + MEM(9990) / 2;
	MEM(11046) = -Acc;
	Acc = -Acc / 2 + MEM(9990);
	MEM(14952) = Acc;
	Acc = MEM(13865) / 2 + MEM(13864) / 2 + MEM(9376) / 2;
	MEM(9988) = -Acc;
	Acc = -Acc / 2 + MEM(9376);
	MEM(13863) = Acc;
	Acc = MEM(12454) * 3 / 4 + MEM(9018) / 2;
	MEM(9374) = -Acc;
	Acc = -Acc / 2 + MEM(9018);
	MEM(12452) = Acc;
	Acc = MEM(11048) * 3 / 4 + MEM(8585) / 2;
	MEM(9016) = -Acc;
	Acc = -Acc / 2 + MEM(8585) + tmp_b;
	MEM(15922) = Acc;
	Acc = MEM(7710) + MEM(2426) / 2;
	MEM(3413) = -Acc;
	Acc = -Acc / 2 + MEM(2426);
	MEM(7708) = Acc;
	Acc = MEM(6473) / 2 + MEM(1743) / 2;
	MEM(2424) = -Acc;
	Acc = -Acc / 2 + MEM(1743);
	MEM(6472) = Acc;
	*out_left = tmp_5;
	Acc = MEM(5027) * 3 / 4 + MEM(1107) / 2;
	MEM(1741) = -Acc;
	Acc = -Acc / 2 + MEM(1107);
	MEM(5025) = Acc;
	Acc = MEM(3415) * 3 / 4 + MEM(673) / 2;
	MEM(1105) = -Acc;
	Acc = -Acc / 2 + MEM(673) + tmp_b;
	MEM(8583) = Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_28(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(13320) * 9 / 8 + MEM(7430) * 9 / 8 + MEM(3233) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(12331) * 9 / 8 + MEM(8431) * 9 / 8 + MEM(4565) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(16060) / 2 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(13343) / 2;
	MEM(14363) = -Acc;
	Acc = -Acc / 2 + MEM(13343) + MEM(14632) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(14632) + MEM(14574) / 2;
	MEM(14630) = -Acc;
	Acc = -Acc / 2 + MEM(14574) + MEM(14494) / 2;
	MEM(14572) = -Acc;
	Acc = -Acc / 2 + MEM(14494) + MEM(14365) / 2;
	MEM(14492) = -Acc;
	Acc = -Acc / 2 + MEM(14365);
	tmp_b = Acc;
	Acc = MEM(10717) / 2 + MEM(10716) / 2 + MEM(9323) / 2;
	MEM(10715) = -Acc;
	Acc = -Acc / 2 + MEM(9323);
	MEM(9321) = Acc;
	Acc = MEM(6511) * 15 / 16 + MEM(5238) / 2;
	MEM(6509) = -Acc;
	Acc = -Acc / 2 + MEM(5238);
	MEM(5236) = Acc;
	Acc = MEM(1379) * 3 / 4 + MEM(265) / 2;
	MEM(1377) = -Acc;
	Acc = -Acc / 2 + MEM(265) + MEM(259) / 2;
	MEM(260) = Acc;
	Acc = MEM(260) / 2 + tmp_b;
	MEM(13341) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_29(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_b, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(12720) * 9 / 8 + MEM(7230) * 9 / 8 + MEM(2633) * 9 / 8;
	tmp_3 = Acc;
	Acc = MEM(11731) * 9 / 8 + MEM(8231) * 9 / 8 + MEM(3965) * 9 / 8;
	tmp_5 = Acc;
	Acc = MEM(16060) / 2 + MEM(16383) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16060) + MEM(15627) / 2;
	MEM(16058) = -Acc;
	Acc = -Acc / 2 + MEM(15627) + MEM(14657) / 2;
	MEM(15625) = -Acc;
	Acc = -Acc / 2 + MEM(14657) + MEM(12743) / 2;
	MEM(14363) = -Acc;
	Acc = -Acc / 2 + MEM(12743) + MEM(14632) / 2;
	MEM(14655) = -Acc;
	Acc = -Acc / 2 + MEM(14632) + MEM(14574) / 2;
	MEM(14630) = -Acc;
	Acc = -Acc / 2 + MEM(14574) + MEM(14494) / 2;
	MEM(14572) = -Acc;
	Acc = -Acc / 2 + MEM(14494) + MEM(14365) / 2;
	MEM(14492) = -Acc;
	Acc = -Acc / 2 + MEM(14365);
	tmp_b = Acc;
	Acc = MEM(11117) / 2 + MEM(11116) / 2 + MEM(9123) / 2;
	MEM(11115) = -Acc;
	Acc = -Acc / 2 + MEM(9123);
	MEM(9121) = Acc;
	Acc = MEM(7011) * 15 / 16 + MEM(4638) / 2;
	MEM(7009) = -Acc;
	Acc = -Acc / 2 + MEM(4638);
	MEM(4636) = Acc;
	Acc = MEM(2479) * 15 / 16 + MEM(265) / 2;
	MEM(2477) = -Acc;
	Acc = -Acc / 2 + MEM(265) + MEM(259) / 2;
	MEM(260) = Acc;
	Acc = MEM(260) / 2 + tmp_b;
	MEM(12741) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_30(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5, tmp_b, tmp_15;
	MEM(0) = input;
	Acc = MEM(6104) / 2 + MEM(5014) / 2 + MEM(3952) / 2 + MEM(2361) / 2;
	tmp_3 = Acc;
	Acc = MEM(5983) / 2 + MEM(4478) / 2 + MEM(4071) / 2 + MEM(2866) / 2;
	tmp_5 = Acc;
	Acc = MEM(0) / 2 + MEM(16139) / 2 + MEM(15861) / 2 + MEM(15493) / 2 + MEM(15184) / 2 + MEM(14816) / 2 + MEM(14397) / 2 + MEM(13817) / 2 + MEM(13491) / 2 + MEM(13280) / 2;
	tmp_b = -Acc;
	Acc = -Acc / 8 + MEM(7137) * 5 / 8 + tmp_b / 2;
	MEM(7382) = -Acc;
	Acc = -Acc / 8 + MEM(6946) * 5 / 8 + MEM(7382) / 2 + MEM(7137);
	MEM(7135) = -Acc;
	Acc = -Acc / 8 + MEM(6799) * 5 / 8 + MEM(7135) / 2 + MEM(6946);
	MEM(6944) = -Acc;
	Acc = -Acc / 8 + MEM(6674) * 5 / 8 + MEM(6944) / 2 + MEM(6799);
	MEM(6797) = -Acc;
	Acc = -Acc / 8 + MEM(6474) * 5 / 8 + MEM(6797) / 2 + MEM(6674);
	MEM(6672) = -Acc;
	Acc = -Acc / 8 + MEM(6672) / 2 + MEM(6474) + MEM(6438) / 2;
	MEM(6472) = -Acc;
	Acc = -Acc / 2 + MEM(6438) + MEM(6367) / 2;
	MEM(6436) = -Acc;
	Acc = -Acc / 2 + MEM(6367) + MEM(6261) / 2;
	MEM(6365) = -Acc;
	Acc = -Acc / 2 + MEM(6261) + MEM(6111) / 2;
	MEM(6259) = -Acc;
	Acc = -Acc / 2 + MEM(6111);
	tmp_15 = -Acc;
	Acc = MEM(5612) / 2 + MEM(5377) / 2;
	MEM(5610) = -Acc;
	Acc = -Acc / 2 + MEM(5377);
	MEM(5375) = Acc;
	Acc = MEM(4365) * 3 / 4 + MEM(4074) / 2;
	MEM(4363) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + MEM(4074) + tmp_15;
	MEM(4072) = -Acc;
	Acc = MEM(3482) / 2 + MEM(3224) / 2;
	MEM(3480) = -Acc;
	Acc = -Acc / 2 + MEM(3224);
	MEM(3222) = Acc;
	Acc = MEM(2151) * 3 / 4 + MEM(1924) / 2;
	MEM(2149) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + MEM(1924) + tmp_15;
	MEM(6109) = -Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_31(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5, tmp_b, tmp_15;
	MEM(0) = input;
	Acc = MEM(5986) / 2 + MEM(4388) / 2 + MEM(3241) / 2 + MEM(1335) / 2;
	tmp_3 = Acc;
	Acc = MEM(5983) / 2 + MEM(3852) / 2 + MEM(3244) / 2 + MEM(1840) / 2;
	tmp_5 = Acc;
	Acc = MEM(0) / 2 + MEM(16139) / 2 + MEM(15493) / 2 + MEM(14816) / 2 + MEM(14397) / 2 + MEM(13638) / 2 + MEM(13139) / 2;
	tmp_b = -Acc;
	Acc = -Acc / 8 + MEM(7137) * 5 / 8 + tmp_b / 2;
	MEM(7382) = -Acc;
	Acc = -Acc / 8 + MEM(6946) * 5 / 8 + MEM(7382) / 2 + MEM(7137);
	MEM(7135) = -Acc;
	Acc = -Acc / 8 + MEM(6799) * 5 / 8 + MEM(7135) / 2 + MEM(6946);
	MEM(6944) = -Acc;
	Acc = -Acc / 8 + MEM(6674) * 5 / 8 + MEM(6944) / 2 + MEM(6799);
	MEM(6797) = -Acc;
	Acc = -Acc / 8 + MEM(6474) * 5 / 8 + MEM(6797) / 2 + MEM(6674);
	MEM(6672) = -Acc;
	Acc = -Acc / 8 + MEM(6672) / 2 + MEM(6474) + MEM(6438) / 2;
	MEM(6472) = -Acc;
	Acc = -Acc / 2 + MEM(6438) + MEM(6367) / 2;
	MEM(6436) = -Acc;
	Acc = -Acc / 2 + MEM(6367) + MEM(6261) / 2;
	MEM(6365) = -Acc;
	Acc = -Acc / 2 + MEM(6261) + MEM(6111) / 2;
	MEM(6259) = -Acc;
	Acc = -Acc / 2 + MEM(6111);
	tmp_15 = -Acc;
	Acc = MEM(4986) * 3 / 4 + MEM(4751) / 2;
	MEM(4984) = -Acc;
	Acc = -Acc / 2 + MEM(4751);
	MEM(4749) = Acc;
	Acc = -MEM(3739) / 4 + -MEM(3738) / 4 + MEM(3448) / 2;
	MEM(3737) = -Acc;
	Acc = -Acc / 2 + MEM(3448) + tmp_15;
	MEM(6109) = -Acc;
	*out_left = tmp_5;
	Acc = MEM(2456) * 3 / 4 + MEM(2198) / 2;
	MEM(2454) = -Acc;
	Acc = -Acc / 2 + MEM(2198);
	MEM(2196) = Acc;
	Acc = -MEM(825) / 4 + -MEM(824) / 4 + MEM(598) / 2;
	MEM(823) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + MEM(598) + tmp_15;
	MEM(3446) = -Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_32(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5, tmp_b, tmp_15;
	MEM(0) = input;
	Acc = MEM(8742) / 2 + MEM(6867) / 2 + MEM(5420) / 2 + MEM(3784) / 2;
	tmp_3 = Acc;
	Acc = MEM(8239) / 2 + MEM(6331) / 2 + MEM(5869) / 2 + MEM(3889) / 2;
	tmp_5 = Acc;
	Acc = MEM(15384) / 2 + MEM(15385) / 2;
	MEM(15384) = Acc;
	Acc = MEM(10961) / 2 + MEM(11397) / 2 + MEM(12153) / 2 + MEM(12495) / 2 + MEM(13163) / 2 + MEM(13638) / 2 + MEM(14043) / 2 + MEM(14461) / 2 + MEM(14861) / 2 + MEM(15275) / 2 + MEM(15508) / 2 + MEM(15949) / 2 + MEM(16149) / 2 + MEM(0) / 2;
	tmp_b = -Acc;
	Acc = -Acc / 8 + MEM(10137) * 5 / 8 + tmp_b / 2;
	MEM(10382) = -Acc;
	Acc = -Acc / 8 + MEM(9946) * 5 / 8 + MEM(10382) / 2 + MEM(10137);
	MEM(10135) = -Acc;
	Acc = -Acc / 8 + MEM(9755) * 5 / 8 + MEM(10135) / 2 + MEM(9946);
	MEM(9944) = -Acc;
	Acc = -Acc / 8 + MEM(9530) * 5 / 8 + MEM(9944) / 2 + MEM(9755);
	MEM(9753) = -Acc;
	Acc = -Acc / 8 + MEM(9230) * 5 / 8 + MEM(9753) / 2 + MEM(9530);
	MEM(9528) = -Acc;
	Acc = -Acc / 8 + MEM(9528) / 2 + MEM(9230) + MEM(9194) / 2;
	MEM(9228) = -Acc;
	Acc = -Acc / 2 + MEM(9194) + MEM(9123) / 2;
	MEM(9192) = -Acc;
	Acc = -Acc / 2 + MEM(9123) + MEM(9017) / 2;
	MEM(9121) = -Acc;
	Acc = -Acc / 2 + MEM(9017) + MEM(8867) / 2;
	MEM(9015) = -Acc;
	Acc = -Acc / 2 + MEM(8867);
	tmp_15 = -Acc;
	Acc = MEM(7555) / 2 + MEM(7230) / 2;
	MEM(7553) = -Acc;
	Acc = -Acc / 2 + MEM(7230);
	MEM(7228) = Acc;
	*out_left = tmp_5;
	Acc = MEM(6218) / 2 + MEM(5927) / 2;
	MEM(6216) = -Acc;
	Acc = -Acc / 2 + MEM(5927) + tmp_15;
	MEM(5925) = -Acc;
	Acc = MEM(4905) / 2;
	MEM(4903) = -Acc;
	Acc = -Acc / 2 + MEM(4647);
	MEM(4645) = Acc;
	Acc = MEM(3574) / 2 + MEM(3447) / 2;
	MEM(3572) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + MEM(3447) + tmp_15;
	MEM(8865) = -Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_33(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5, tmp_b, tmp_15;
	MEM(0) = input;
	Acc = MEM(6136) / 2 + MEM(4538) / 2 + MEM(3391) / 2 + MEM(1485) / 2;
	tmp_3 = Acc;
	Acc = MEM(6133) / 2 + MEM(4002) / 2 + MEM(3394) / 2 + MEM(1990) / 2;
	tmp_5 = Acc;
	Acc = MEM(0) / 2 + MEM(16139) / 2 + MEM(15493) / 2 + MEM(14816) / 2 + MEM(14397) / 2 + MEM(13638) / 2 + MEM(13139) / 2 + MEM(12706) / 2 + MEM(12152) / 2 + MEM(11404) / 2 + MEM(11261) / 2 + MEM(10619) / 2 + MEM(10039) / 2 + MEM(9339) / 2 + MEM(8795) / 2 + MEM(8139) / 2 + MEM(7853) / 2 + MEM(7463) / 2;
	tmp_b = -Acc;
	Acc = -Acc / 8 + MEM(7137) * 5 / 8 + tmp_b / 2;
	MEM(7382) = -Acc;
	Acc = -Acc / 8 + MEM(6946) * 5 / 8 + MEM(7382) / 2 + MEM(7137);
	MEM(7135) = -Acc;
	Acc = -Acc / 8 + MEM(6799) * 5 / 8 + MEM(7135) / 2 + MEM(6946);
	MEM(6944) = -Acc;
	Acc = -Acc / 8 + MEM(6674) * 5 / 8 + MEM(6944) / 2 + MEM(6799);
	MEM(6797) = -Acc;
	Acc = -Acc / 8 + MEM(6474) * 5 / 8 + MEM(6797) / 2 + MEM(6674);
	MEM(6672) = -Acc;
	Acc = -Acc / 8 + MEM(6672) / 2 + MEM(6474) + MEM(6438) / 2;
	MEM(6472) = -Acc;
	Acc = -Acc / 2 + MEM(6438) + MEM(6367) / 2;
	MEM(6436) = -Acc;
	Acc = -Acc / 2 + MEM(6367) + MEM(6261) / 2;
	MEM(6365) = -Acc;
	Acc = -Acc / 2 + MEM(6261);
	tmp_15 = -Acc;
	Acc = MEM(5136) / 2 + MEM(4901) / 2;
	MEM(5134) = -Acc;
	Acc = -Acc / 2 + MEM(4901);
	MEM(4899) = Acc;
	Acc = MEM(3889) / 2 + MEM(3598) / 2;
	MEM(3887) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + MEM(3598) + MEM(745) / 2;
	MEM(746) = Acc;
	Acc = Acc * -3 / 4 + tmp_15;
	MEM(6259) = -Acc;
	Acc = MEM(2606) / 2 + MEM(2348) / 2;
	MEM(2604) = -Acc;
	Acc = -Acc / 2 + MEM(2348);
	MEM(2346) = Acc;
	*out_right = tmp_3;
	Acc = MEM(975) / 2 + MEM(748) / 2;
	MEM(973) = -Acc;
	Acc = -Acc / 2 + MEM(748) + MEM(742) / 2;
	MEM(743) = Acc;
	Acc = Acc * -3 / 4 + tmp_15;
	MEM(3596) = -Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_34(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5, tmp_b, tmp_15;
	MEM(0) = input;
	Acc = MEM(5986) / 2 + MEM(4388) / 2 + MEM(3241) / 2 + MEM(1335) / 2;
	tmp_3 = Acc;
	Acc = MEM(5983) / 2 + MEM(3852) / 2 + MEM(3244) / 2 + MEM(1840) / 2;
	tmp_5 = Acc;
	Acc = MEM(0) / 2 + MEM(16139) / 2 + MEM(15493) / 2 + MEM(14816) / 2 + MEM(14397) / 2 + MEM(13638) / 2 + MEM(13139) / 2 + MEM(12706) / 2 + MEM(12152) / 2 + MEM(11404) / 2 + MEM(11261) / 2 + MEM(10619) / 2 + MEM(10039) / 2 + MEM(9339) / 2 + MEM(8795) / 2 + MEM(8139) / 2 + MEM(7853) / 2 + MEM(7463) / 2;
	tmp_b = -Acc;
	Acc = -Acc / 8 + MEM(7137) * 5 / 8 + tmp_b / 2;
	MEM(7382) = -Acc;
	Acc = -Acc / 8 + MEM(6946) * 5 / 8 + MEM(7382) / 2 + MEM(7137);
	MEM(7135) = -Acc;
	Acc = -Acc / 8 + MEM(6799) * 5 / 8 + MEM(7135) / 2 + MEM(6946);
	MEM(6944) = -Acc;
	Acc = -Acc / 8 + MEM(6674) * 5 / 8 + MEM(6944) / 2 + MEM(6799);
	MEM(6797) = -Acc;
	Acc = -Acc / 8 + MEM(6474) * 5 / 8 + MEM(6797) / 2 + MEM(6674);
	MEM(6672) = -Acc;
	Acc = -Acc / 8 + MEM(6672) / 2 + MEM(6474) + MEM(6438) / 2;
	MEM(6472) = -Acc;
	Acc = -Acc / 2 + MEM(6438) + MEM(6367) / 2;
	MEM(6436) = -Acc;
	Acc = -Acc / 2 + MEM(6367) + MEM(6261) / 2;
	MEM(6365) = -Acc;
	Acc = -Acc / 2 + MEM(6261) + MEM(6111) / 2;
	MEM(6259) = -Acc;
	Acc = -Acc / 2 + MEM(6111);
	tmp_15 = -Acc;
	Acc = MEM(4986) * 3 / 4 + MEM(4751) / 2;
	MEM(4984) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + MEM(4751);
	MEM(4749) = Acc;
	Acc = -MEM(3739) / 4 + -MEM(3738) / 4 + MEM(3448) / 2;
	MEM(3737) = -Acc;
	Acc = -Acc / 2 + MEM(3448) + tmp_15;
	MEM(3446) = -Acc;
	Acc = MEM(2456) * 3 / 4 + MEM(2198) / 2;
	MEM(2454) = -Acc;
	*out_right = tmp_3;
	Acc = -Acc / 2 + MEM(2198);
	MEM(2196) = Acc;
	Acc = -MEM(825) / 4 + -MEM(824) / 4 + MEM(598) / 2;
	MEM(823) = -Acc;
	Acc = -Acc / 2 + MEM(598) + tmp_15;
	MEM(6109) = -Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_35(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) + MEM(2267) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2267) + MEM(2112) / 2;
	MEM(2265) = -Acc;
	Acc = -Acc / 2 + MEM(2112) + MEM(1837) / 2;
	MEM(2110) = -Acc;
	Acc = Acc * -9 / 8 + MEM(1837) * 9 / 4;
	tmp_3 = -Acc;
	Acc = MEM(9) + MEM(1793) / 2;
	MEM(1835) = -Acc;
	Acc = -Acc / 2 + MEM(1793) + MEM(1610) / 2;
	MEM(1791) = -Acc;
	Acc = -Acc / 2 + MEM(1610) + MEM(1375) / 2;
	MEM(1608) = -Acc;
	Acc = Acc * -9 / 8 + MEM(1375) * 9 / 4;
	tmp_5 = -Acc;
	Acc = MEM(0) / 2 + MEM(16383) / 2;
	MEM(0) = Acc;
	Acc = MEM(16374) * -3 / 8;
	MEM(16373) = -Acc;
	Acc = MEM(16153) / 2 + MEM(15972) / 2 + MEM(15850) / 2 + MEM(15623) / 2 + MEM(15509) / 2 + MEM(15319) / 2 + MEM(15265) / 2 + MEM(15151) / 2 + MEM(14950) / 2 + MEM(14829) / 2 + MEM(14642) / 2 + MEM(14522) / 2 + MEM(14338) / 2 + MEM(14235) / 2 + MEM(14128) / 2 + MEM(13941) / 2 + MEM(13805) / 2 + MEM(13663) / 2 + MEM(13511) / 2 + MEM(13348) / 2 + MEM(13263) / 2 + MEM(13117) / 2 + MEM(12933) / 2 + MEM(12815) / 2 + MEM(12659) / 2 + MEM(12495) / 2 + MEM(12350) / 2 + MEM(12232) / 2 + MEM(12127) / 2 + MEM(11892) / 2 + MEM(11828) / 2;
	MEM(11) = -Acc;
	*out_left = tmp_5;
	Acc = -MEM(7289) / 16 + -MEM(7535) / 16 + -MEM(7591) / 16 + -MEM(7869) / 16 + -MEM(7922) / 16 + -MEM(8005) / 16 + -MEM(8245) / 16 + -MEM(8292) / 16 + MEM(8519) / 8 + MEM(8657) / 8 + MEM(8727) / 8 + MEM(8965) / 8 + MEM(9020) / 8 + MEM(9230) / 8 + MEM(9366) / 8 + MEM(9417) / 8 + -MEM(9656) / 4 + -MEM(9727) / 4 + -MEM(9889) / 4 + -MEM(10065) / 4 + -MEM(10123) / 4 + -MEM(10365) / 4 + -MEM(10426) / 4 + -MEM(10650) / 4 + MEM(10757) / 2 + MEM(10833) / 2 + MEM(11045) / 2 + MEM(11174) / 2 + MEM(11338) / 2 + MEM(11463) / 2 + MEM(11584) / 2 + MEM(11765) / 2 + MEM(1372) / 2;
	MEM(1373) = Acc;
	*out_right = tmp_3;
	Acc = -MEM(1372) / 4 + MEM(11);
	MEM(11) = -Acc;
	Acc = MEM(15384) / 2 + MEM(1369) / 2;
	MEM(1370) = -Acc;
	Acc = MEM(1369);
	MEM(15383) = -Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_36(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(1796) = Acc;
	Acc = MEM(296);
	MEM(16383) = -Acc;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = Acc * -3 / 4 + MEM(2047) * 3 / 2;
	tmp_3 = Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = Acc * -3 / 4 + MEM(1801) * 3 / 2;
	tmp_5 = Acc;
	Acc = MEM(16379) / 2 + MEM(16378) / 2;
	MEM(16379) = Acc;
	Acc = MEM(16374) / 2;
	MEM(16373) = Acc;
	Acc = MEM(16221) / 2 + MEM(16151) / 2 + MEM(15972) / 2 + MEM(15850) / 2 + MEM(15623) / 2 + MEM(15509) / 2 + MEM(15319) / 2 + MEM(15265) / 2 + MEM(15151) / 2 + MEM(14950) / 2 + MEM(14829) / 2 + MEM(14642) / 2 + MEM(14522) / 2 + MEM(14338) / 2 + MEM(14235) / 2 + MEM(14128) / 2 + MEM(13941) / 2 + MEM(13805) / 2 + MEM(13663) / 2 + MEM(13511) / 2 + MEM(13348) / 2 + MEM(13263) / 2 + MEM(13117) / 2 + MEM(12933) / 2 + MEM(12815) / 2;
	MEM(11) = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_37(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5;
	tmp_0 = input;
	Acc = MEM(9) + MEM(6267) / 2;
	MEM(6298) = -Acc;
	Acc = -Acc / 2 + MEM(6267) + MEM(6112) / 2;
	MEM(6265) = -Acc;
	Acc = -Acc / 2 + MEM(6112) + MEM(5837) / 2;
	MEM(6110) = -Acc;
	Acc = Acc * -9 / 8 + MEM(5837) * 9 / 4;
	tmp_3 = -Acc;
	Acc = MEM(9) + MEM(5793) / 2;
	MEM(5835) = -Acc;
	Acc = -Acc / 2 + MEM(5793) + MEM(5610) / 2;
	MEM(5791) = -Acc;
	Acc = -Acc / 2 + MEM(5610) + MEM(5375) / 2;
	MEM(5608) = -Acc;
	Acc = Acc * -9 / 8 + MEM(5375) * 9 / 4;
	tmp_5 = -Acc;
	Acc = tmp_0;
	MEM(5364) = -Acc;
	Acc = MEM(3864);
	MEM(16382) = -Acc;
	Acc = MEM(16380) / 2 + MEM(16379) / 2;
	MEM(16380) = Acc;
	Acc = MEM(16374) * -3 / 8;
	MEM(16373) = -Acc;
	Acc = -Acc / 2 + MEM(15850) / 2 + MEM(15623) / 2 + MEM(15509) / 2 + MEM(15319) / 2 + MEM(15265) / 2 + MEM(15151) / 2 + MEM(14950) / 2 + MEM(14829) / 2 + MEM(14642) / 2 + MEM(14522) / 2 + MEM(14338) / 2 + MEM(14235) / 2 + MEM(14128) / 2 + MEM(13941) / 2 + MEM(13805) / 2 + MEM(13663) / 2 + MEM(13511) / 2 + MEM(13348) / 2 + MEM(13263) / 2 + MEM(13117) / 2 + MEM(12933) / 2 + MEM(12815) / 2 + MEM(12659) / 2 + MEM(12495) / 2 + MEM(12350) / 2 + MEM(12232) / 2 + MEM(12127) / 2 + MEM(11892) / 2 + MEM(11828) / 2;
	MEM(11) = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
	Acc = -MEM(7289) / 16 + -MEM(7535) / 16 + -MEM(7591) / 16 + -MEM(7869) / 16 + -MEM(7922) / 16 + -MEM(8005) / 16 + -MEM(8245) / 16 + -MEM(8292) / 16 + MEM(8519) / 8 + MEM(8657) / 8 + MEM(8727) / 8 + MEM(8965) / 8 + MEM(9020) / 8 + MEM(9230) / 8 + MEM(9366) / 8 + MEM(9417) / 8 + -MEM(9656) / 4 + -MEM(9727) / 4 + -MEM(9889) / 4 + -MEM(10065) / 4 + -MEM(10123) / 4 + -MEM(10365) / 4 + -MEM(10426) / 4 + -MEM(10650) / 4 + MEM(10757) / 2 + MEM(10833) / 2 + MEM(11045) / 2 + MEM(11174) / 2 + MEM(11338) / 2 + MEM(11463) / 2 + MEM(11584) / 2 + MEM(11765) / 2 + MEM(5372) / 2;
	MEM(5373) = Acc;
	Acc = -MEM(5372) / 4 + MEM(11);
	MEM(11) = -Acc;
	Acc = MEM(15384) / 2 + MEM(5369) / 2;
	MEM(5370) = -Acc;
	Acc = MEM(5369);
	MEM(15383) = -Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_38(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5;
	tmp_0 = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = Acc * -3 / 4 + MEM(2047) * 3 / 2;
	tmp_3 = Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = Acc * -3 / 4 + MEM(1801) * 3 / 2;
	tmp_5 = Acc;
	Acc = MEM(16381) * 3 / 4 + tmp_0 / 2;
	MEM(16382) = Acc;
	Acc = MEM(16374) / 2;
	MEM(16373) = Acc;
	Acc = MEM(16221) / 2 + MEM(16151) / 2 + MEM(15972) / 2 + MEM(15850) / 2 + MEM(15623) / 2 + MEM(15509) / 2 + MEM(15319) / 2 + MEM(15265) / 2 + MEM(15151) / 2 + MEM(14950) / 2 + MEM(14829) / 2 + MEM(14642) / 2 + MEM(14522) / 2 + MEM(14338) / 2 + MEM(14235) / 2 + MEM(14128) / 2 + MEM(13941) / 2 + MEM(13805) / 2 + MEM(13663) / 2 + MEM(13511) / 2 + MEM(13348) / 2 + MEM(13263) / 2 + MEM(13117) / 2 + MEM(12933) / 2 + MEM(12815) / 2;
	MEM(11) = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_39(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5;
	tmp_0 = input;
	Acc = MEM(9) + MEM(2267) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2267) + MEM(2112) / 2;
	MEM(2265) = -Acc;
	Acc = -Acc / 2 + MEM(2112) + MEM(1837) / 2;
	MEM(2110) = -Acc;
	Acc = Acc * -9 / 8 + MEM(1837) * 9 / 4;
	tmp_3 = -Acc;
	Acc = MEM(9) + MEM(1793) / 2;
	MEM(1835) = -Acc;
	Acc = -Acc / 2 + MEM(1793) + MEM(1610) / 2;
	MEM(1791) = -Acc;
	Acc = -Acc / 2 + MEM(1610) + MEM(1375) / 2;
	MEM(1608) = -Acc;
	Acc = Acc * -9 / 8 + MEM(1375) * 9 / 4;
	tmp_5 = -Acc;
	Acc = MEM(16381) * 3 / 4 + tmp_0 / 2;
	MEM(16382) = Acc;
	Acc = MEM(16374) * -3 / 8;
	MEM(16373) = -Acc;
	Acc = MEM(16153) / 2 + MEM(15972) / 2 + MEM(15850) / 2 + MEM(15623) / 2 + MEM(15509) / 2 + MEM(15319) / 2 + MEM(15265) / 2 + MEM(15151) / 2 + MEM(14950) / 2 + MEM(14829) / 2 + MEM(14642) / 2 + MEM(14522) / 2 + MEM(14338) / 2 + MEM(14235) / 2 + MEM(14128) / 2 + MEM(13941) / 2 + MEM(13805) / 2 + MEM(13663) / 2 + MEM(13511) / 2 + MEM(13348) / 2 + MEM(13263) / 2 + MEM(13117) / 2 + MEM(12933) / 2 + MEM(12815) / 2 + MEM(12659) / 2 + MEM(12495) / 2 + MEM(12350) / 2 + MEM(12232) / 2 + MEM(12127) / 2 + MEM(11892) / 2 + MEM(11828) / 2;
	MEM(11) = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
	Acc = -MEM(7289) / 16 + -MEM(7535) / 16 + -MEM(7591) / 16 + -MEM(7869) / 16 + -MEM(7922) / 16 + -MEM(8005) / 16 + -MEM(8245) / 16 + -MEM(8292) / 16 + MEM(8519) / 8 + MEM(8657) / 8 + MEM(8727) / 8 + MEM(8965) / 8 + MEM(9020) / 8 + MEM(9230) / 8 + MEM(9366) / 8 + MEM(9417) / 8 + -MEM(9656) / 4 + -MEM(9727) / 4 + -MEM(9889) / 4 + -MEM(10065) / 4 + -MEM(10123) / 4 + -MEM(10365) / 4 + -MEM(10426) / 4 + -MEM(10650) / 4 + MEM(10757) / 2 + MEM(10833) / 2 + MEM(11045) / 2 + MEM(11174) / 2 + MEM(11338) / 2 + MEM(11463) / 2 + MEM(11584) / 2 + MEM(11765) / 2 + MEM(1372) / 2;
	MEM(1373) = Acc;
	Acc = -MEM(1372) / 4 + MEM(11);
	MEM(11) = -Acc;
	Acc = MEM(15384) / 2 + MEM(1369) / 2;
	MEM(1370) = -Acc;
	Acc = MEM(1369);
	MEM(15383) = -Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_40(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5;
	tmp_0 = input;
	Acc = MEM(9) / 2 + MEM(2247) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2247) + MEM(2114) / 2;
	MEM(2245) = -Acc;
	Acc = -Acc / 2 + MEM(2114) + MEM(1899) / 2;
	MEM(2112) = -Acc;
	Acc = Acc * -9 / 8 + MEM(1899) * 9 / 4 + MEM(5066) * 9 / 4;
	tmp_3 = -Acc;
	Acc = MEM(9) / 2 + MEM(1835) / 2;
	MEM(1897) = -Acc;
	Acc = -Acc / 2 + MEM(1835) + MEM(1728) / 2;
	MEM(1833) = -Acc;
	Acc = -Acc / 2 + MEM(1728) + MEM(1537) / 2;
	MEM(1726) = -Acc;
	Acc = Acc * -9 / 8 + MEM(1537) * 9 / 4 + MEM(5066) * 9 / 4;
	tmp_5 = -Acc;
	Acc = tmp_0 / 2;
	MEM(16382) = Acc;
	Acc = -MEM(16151) / 16 + -MEM(15972) / 16 + -MEM(15623) / 16 + -MEM(15319) / 16 + MEM(15151) / 8 + MEM(14950) / 8 + MEM(14642) / 8 + MEM(14522) / 8 + MEM(13348) / 8 + MEM(14235) / 8 + -MEM(14128) / 4 + -MEM(13941) / 4 + -MEM(14829) / 4 + -MEM(13663) / 4 + -MEM(13511) / 4 + -MEM(14338) / 4 + MEM(1534) / 2;
	MEM(1535) = Acc;
	Acc = Acc * 3 / 32 + MEM(13263) / 32 + MEM(13117) / 32 + MEM(12933) / 32 + MEM(12815) / 32 + MEM(11350) / 32 + MEM(12495) / 32 + MEM(12350) / 32 + -MEM(11657) / 16 + -MEM(12127) / 16 + -MEM(11892) / 16 + -MEM(11828) / 16 + -MEM(11535) / 16 + -MEM(12659) / 16 + MEM(11255) / 8 + MEM(11149) / 8 + MEM(10963) / 8 + MEM(10850) / 8 + MEM(10625) / 8 + MEM(9525) / 8 + -MEM(10349) / 4 + -MEM(10225) / 4 + -MEM(10161) / 4 + -MEM(9258) / 4 + MEM(1531) / 2;
	MEM(1532) = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 8 + MEM(9850) / 8 + MEM(9602) / 8 + MEM(10547) / 8 + MEM(9345) / 8 + MEM(9938) / 8 + MEM(9163) / 8 + MEM(8945) / 8 + -MEM(8648) / 4 + -MEM(8493) / 4 + -MEM(8350) / 4 + -MEM(7169) / 4 + -MEM(7937) / 4 + -MEM(7819) / 4 + -MEM(6871) / 4 + MEM(1528) / 2;
	MEM(1529) = Acc;
	*out_right = tmp_3;
	Acc = Acc * -3 / 4 + -MEM(7499) / 4 + -MEM(7372) / 4 + -MEM(7213) / 4 + -MEM(8238) / 4 + -MEM(6935) / 4 + -MEM(7684) / 4 + -MEM(6619) / 4 + -MEM(6517) / 4 + -MEM(6338) / 4 + -MEM(6274) / 4 + MEM(6099) / 2 + MEM(5956) / 2 + MEM(5806) / 2 + MEM(5650) / 2 + MEM(5569) / 2 + MEM(5361) / 2 + MEM(5130) / 2;
	MEM(11) = Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_41(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
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
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_42(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
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
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_43(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = -Acc / 2 + MEM(2047) + MEM(7009);
	tmp_3 = -Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = -Acc / 2 + MEM(1801) + MEM(7009);
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = MEM(16221) / 32 + MEM(16151) / 32 + MEM(15972) / 32 + MEM(15850) / 32 + MEM(15623) / 32 + MEM(15509) / 32 + MEM(13663) / 32 + MEM(15265) / 32 + MEM(15151) / 32 + MEM(14950) / 32 + MEM(13941) / 32 + MEM(14642) / 32 + MEM(14522) / 32 + -MEM(14338) / 16 + -MEM(14235) / 16 + -MEM(14128) / 16 + -MEM(14829) / 16 + -MEM(13805) / 16 + -MEM(15319) / 16 + -MEM(13511) / 16 + -MEM(13348) / 16 + -MEM(12232) / 16 + -MEM(13117) / 16 + -MEM(12933) / 16 + -MEM(11892) / 16 + -MEM(12659) / 16 + MEM(12495) / 8 + MEM(12350) / 8 + MEM(13263) / 8 + MEM(12127) / 8 + MEM(12815) / 8 + MEM(11828) / 8 + MEM(11657) / 8 + MEM(11535) / 8 + MEM(10547) / 8 + MEM(11255) / 8 + MEM(11149) / 8 + MEM(10963) / 8 + MEM(10225) / 8 + -MEM(10625) / 4 + -MEM(11350) / 4 + -MEM(10349) / 4 + -MEM(10850) / 4 + -MEM(10161) / 4 + -MEM(9938) / 4 + -MEM(9850) / 4 + -MEM(8350) / 4 + -MEM(9525) / 4 + -MEM(9345) / 4 + -MEM(8648) / 4 + -MEM(9163) / 4 + -MEM(8945) / 4 + MEM(8850) / 2 + MEM(9258) / 2 + MEM(8493) / 2 + MEM(9602) / 2 + MEM(8238) / 2 + MEM(8106) / 2 + MEM(7937) / 2 + MEM(7819) / 2 + MEM(7684) / 2;
	MEM(11) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_44(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2277) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2277) + MEM(2222) / 2;
	MEM(2275) = -Acc;
	Acc = -Acc / 2 + MEM(2222) + MEM(2047) / 2;
	MEM(2220) = -Acc;
	Acc = -Acc / 2 + MEM(2047) + MEM(9353);
	tmp_3 = -Acc;
	Acc = MEM(9) / 2 + MEM(2013) / 2;
	MEM(2045) = -Acc;
	Acc = -Acc / 2 + MEM(2013) + MEM(1936) / 2;
	MEM(2011) = -Acc;
	Acc = -Acc / 2 + MEM(1936) + MEM(1801) / 2;
	MEM(1934) = -Acc;
	Acc = -Acc / 2 + MEM(1801) + MEM(9353);
	tmp_5 = -Acc;
	Acc = MEM(16221) / 32 + MEM(16151) / 32 + MEM(15972) / 32 + MEM(15850) / 32 + MEM(15623) / 32 + MEM(15509) / 32 + MEM(14950) / 32 + MEM(15265) / 32 + MEM(14522) / 32 + -MEM(15319) / 16 + -MEM(14829) / 16 + -MEM(14642) / 16 + -MEM(15151) / 16 + -MEM(14338) / 16 + -MEM(14235) / 16 + -MEM(13511) / 16 + -MEM(13941) / 16 + -MEM(13263) / 16 + -MEM(13663) / 16 + MEM(14128) / 8 + MEM(13348) / 8 + MEM(13805) / 8 + MEM(13117) / 8 + MEM(12933) / 8 + MEM(12815) / 8 + MEM(11892) / 8 + MEM(12495) / 8 + MEM(12350) / 8 + MEM(12232) / 8 + MEM(11535) / 8 + -MEM(12659) / 4 + -MEM(11828) / 4 + -MEM(11657) / 4 + -MEM(12127) / 4 + -MEM(11350) / 4 + -MEM(10547) / 4 + -MEM(11149) / 4 + -MEM(10963) / 4 + -MEM(10225) / 4 + MEM(10625) / 2 + MEM(11255) / 2 + MEM(10349) / 2 + MEM(10850) / 2 + MEM(10161) / 2 + MEM(9938) / 2;
	MEM(11) = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_45(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(2189);
	tmp_3 = -Acc;
	Acc = MEM(2186);
	tmp_5 = -Acc;
	Acc = MEM(2192) / 2 + MEM(16383) / 2;
	MEM(2193) = Acc;
	Acc = -MEM(10) / 4 + MEM(2183) / 2;
	MEM(2184) = Acc;
	Acc = Acc * 3 / 2 + MEM(2192) + MEM(16368) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16368) + MEM(16283) / 2;
	MEM(16366) = -Acc;
	Acc = -Acc / 2 + MEM(16283) + MEM(16165) / 2;
	MEM(16281) = -Acc;
	Acc = -Acc / 2 + MEM(16165) + MEM(15924) / 2;
	MEM(16163) = -Acc;
	Acc = -Acc / 2 + MEM(15924) + MEM(15583) / 2;
	MEM(15922) = -Acc;
	Acc = -Acc / 2 + MEM(15583) + MEM(15100) / 2;
	MEM(15581) = -Acc;
	Acc = -Acc / 2 + MEM(15100) + MEM(14543) / 2;
	MEM(15098) = -Acc;
	Acc = -Acc / 2 + MEM(14543) + MEM(13718) / 2;
	MEM(14541) = -Acc;
	Acc = -Acc / 2 + MEM(13718) + MEM(12717) / 2;
	MEM(13716) = -Acc;
	Acc = -Acc / 2 + MEM(12717) + MEM(11615) / 2;
	MEM(12715) = -Acc;
	Acc = -Acc / 2 + MEM(11615) + MEM(10266) / 2;
	MEM(11613) = -Acc;
	Acc = -Acc / 2 + MEM(10266) + MEM(8701) / 2;
	MEM(10264) = -Acc;
	Acc = -Acc / 2 + MEM(8701) + MEM(6858) / 2;
	MEM(8699) = -Acc;
	Acc = -Acc / 2 + MEM(6858) + MEM(4855) / 2;
	MEM(6856) = -Acc;
	Acc = -Acc / 2 + MEM(4855) + MEM(2770) / 2;
	MEM(4853) = -Acc;
	Acc = -Acc / 2 + MEM(2770);
	MEM(11) = -Acc;
	Acc = MEM(11) + MEM(2519) / 2;
	MEM(2666) = -Acc;
	Acc = -Acc / 2 + MEM(2519) + MEM(2725) / 2;
	MEM(2768) = -Acc;
	Acc = -Acc / 2 + MEM(2725) + MEM(2668) / 2;
	MEM(2723) = -Acc;
	Acc = -Acc / 2 + MEM(2668);
	MEM(2190) = -Acc;
	Acc = MEM(11) + MEM(2195) / 2;
	MEM(2444) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + MEM(2195) + MEM(2446) / 2;
	MEM(2494) = -Acc;
	Acc = -Acc / 2 + MEM(2446) + MEM(2496) / 2;
	MEM(2517) = -Acc;
	Acc = -Acc / 2 + MEM(2496);
	MEM(2187) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_46(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(0);
	MEM(3166) = -Acc;
	Acc = MEM(1166);
	MEM(0) = -Acc;
	Acc = MEM(9) / 2 + MEM(4247) / 2;
	MEM(4298) = -Acc;
	Acc = -Acc / 2 + MEM(4247) + MEM(4014) / 2;
	MEM(4245) = -Acc;
	Acc = -Acc / 2 + MEM(4014) + MEM(3699) / 2;
	MEM(4012) = -Acc;
	Acc = Acc * -9 / 8 + MEM(3699) * 9 / 4 + MEM(5066) * 9 / 4;
	tmp_3 = -Acc;
	Acc = MEM(9) / 2 + MEM(3635) / 2;
	MEM(3697) = -Acc;
	Acc = -Acc / 2 + MEM(3635) + MEM(3468) / 2;
	MEM(3633) = -Acc;
	Acc = -Acc / 2 + MEM(3468) + MEM(3177) / 2;
	MEM(3466) = -Acc;
	Acc = Acc * -9 / 8 + MEM(3177) * 9 / 4 + MEM(5066) * 9 / 4;
	tmp_5 = -Acc;
	Acc = MEM(16374) / 2;
	MEM(16373) = Acc;
	Acc = Acc * -3 / 16 + -MEM(15972) / 16 + -MEM(15623) / 16 + -MEM(15319) / 16 + MEM(15151) / 8 + MEM(14950) / 8 + MEM(14642) / 8 + MEM(14522) / 8 + MEM(14235) / 8 + -MEM(14128) / 4 + -MEM(13941) / 4 + -MEM(14829) / 4 + -MEM(13663) / 4 + -MEM(13511) / 4 + -MEM(14338) / 4 + MEM(3174) / 2;
	MEM(3175) = Acc;
	Acc = Acc * 3 / 32 + MEM(13263) / 32 + MEM(13117) / 32 + MEM(12815) / 32 + MEM(11350) / 32 + MEM(12495) / 32 + MEM(12350) / 32 + -MEM(11657) / 16 + -MEM(12127) / 16 + -MEM(11892) / 16 + -MEM(11535) / 16 + -MEM(12659) / 16 + MEM(11255) / 8 + MEM(11149) / 8 + MEM(10963) / 8 + MEM(10850) / 8 + MEM(10625) / 8 + MEM(9525) / 8 + -MEM(10349) / 4 + -MEM(10161) / 4 + -MEM(9258) / 4 + MEM(3171) / 2;
	MEM(3172) = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 8 + MEM(9850) / 8 + MEM(10547) / 8 + MEM(9345) / 8 + MEM(9938) / 8 + MEM(9163) / 8 + MEM(8945) / 8 + -MEM(8648) / 4 + -MEM(8493) / 4 + -MEM(8350) / 4 + -MEM(7169) / 4 + -MEM(7937) / 4 + -MEM(7819) / 4 + -MEM(6871) / 4 + MEM(3168) / 2;
	MEM(3169) = Acc;
	*out_right = tmp_3;
	Acc = Acc * -3 / 4 + -MEM(7499) / 4 + -MEM(7372) / 4 + -MEM(7213) / 4 + -MEM(8238) / 4 + -MEM(6935) / 4 + -MEM(7684) / 4 + -MEM(6619) / 4 + -MEM(6517) / 4 + -MEM(6338) / 4 + -MEM(6274) / 4 + MEM(6099) / 2 + MEM(5956) / 2 + MEM(5806) / 2 + MEM(5650) / 2 + MEM(5569) / 2 + MEM(5361) / 2 + MEM(5130) / 2;
	MEM(11) = -Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_47(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5;
	tmp_0 = input;
	Acc = MEM(9) / 2 + MEM(2247) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2247) + MEM(2114) / 2;
	MEM(2245) = -Acc;
	Acc = -Acc / 2 + MEM(2114) + MEM(1899) / 2;
	MEM(2112) = -Acc;
	Acc = Acc * -9 / 8 + MEM(1899) * 9 / 4 + MEM(5066) * 9 / 4;
	tmp_3 = -Acc;
	Acc = MEM(9) / 2 + MEM(1835) / 2;
	MEM(1897) = -Acc;
	Acc = -Acc / 2 + MEM(1835) + MEM(1728) / 2;
	MEM(1833) = -Acc;
	Acc = -Acc / 2 + MEM(1728) + MEM(1537) / 2;
	MEM(1726) = -Acc;
	Acc = Acc * -9 / 8 + MEM(1537) * 9 / 4 + MEM(5066) * 9 / 4;
	tmp_5 = -Acc;
	Acc = tmp_0 / 2 + MEM(5066) / 2;
	MEM(16383) = -Acc;
	Acc = MEM(16374) / 2;
	MEM(16373) = Acc;
	Acc = MEM(15151) / 8 + MEM(14950) / 8 + MEM(14642) / 8 + MEM(14522) / 8 + MEM(13348) / 8 + MEM(14235) / 8 + -MEM(14128) / 4 + -MEM(13941) / 4 + -MEM(14829) / 4 + -MEM(13663) / 4 + -MEM(13511) / 4 + -MEM(14338) / 4 + MEM(1534) / 2;
	MEM(1535) = Acc;
	Acc = Acc * 3 / 32 + MEM(13263) / 32 + MEM(13117) / 32 + MEM(12933) / 32 + MEM(12815) / 32 + MEM(11350) / 32 + MEM(12495) / 32 + MEM(12350) / 32 + -MEM(11657) / 16 + -MEM(12127) / 16 + -MEM(11892) / 16 + -MEM(11828) / 16 + -MEM(11535) / 16 + -MEM(12659) / 16 + MEM(11255) / 8 + MEM(11149) / 8 + MEM(10963) / 8 + MEM(10850) / 8 + MEM(10625) / 8 + MEM(9525) / 8 + -MEM(10349) / 4 + -MEM(10225) / 4 + -MEM(10161) / 4 + -MEM(9258) / 4 + MEM(1531) / 2;
	MEM(1532) = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 8 + MEM(9850) / 8 + MEM(9602) / 8 + MEM(10547) / 8 + MEM(9345) / 8 + MEM(9938) / 8 + MEM(9163) / 8 + MEM(8945) / 8 + -MEM(8648) / 4 + -MEM(8493) / 4 + -MEM(8350) / 4 + -MEM(7169) / 4 + -MEM(7937) / 4 + -MEM(7819) / 4 + -MEM(6871) / 4 + MEM(1528) / 2;
	MEM(1529) = Acc;
	*out_right = tmp_3;
	Acc = Acc * -3 / 4 + -MEM(7499) / 4 + -MEM(7372) / 4 + -MEM(7213) / 4 + -MEM(8238) / 4 + -MEM(6935) / 4 + -MEM(7684) / 4 + -MEM(6619) / 4 + -MEM(6517) / 4 + -MEM(6338) / 4 + -MEM(6274) / 4 + MEM(6099) / 2 + MEM(5956) / 2 + MEM(5806) / 2 + MEM(5650) / 2 + MEM(5569) / 2 + MEM(5361) / 2 + MEM(5130) / 2;
	MEM(11) = Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_48(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(9) / 2 + MEM(2247) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2247) + MEM(2114) / 2;
	MEM(2245) = -Acc;
	Acc = -Acc / 2 + MEM(2114) + MEM(1899) / 2;
	MEM(2112) = -Acc;
	Acc = Acc * -9 / 8 + MEM(1899) * 9 / 4 + MEM(5066) * 9 / 4;
	tmp_3 = -Acc;
	Acc = MEM(9) / 2 + MEM(1835) / 2;
	MEM(1897) = -Acc;
	Acc = -Acc / 2 + MEM(1835) + MEM(1728) / 2;
	MEM(1833) = -Acc;
	Acc = -Acc / 2 + MEM(1728) + MEM(1537) / 2;
	MEM(1726) = -Acc;
	Acc = Acc * -9 / 8 + MEM(1537) * 9 / 4 + MEM(5066) * 9 / 4;
	tmp_5 = -Acc;
	Acc = MEM(16381);
	MEM(1526) = -Acc;
	Acc = MEM(226);
	MEM(16380) = -Acc;
	Acc = MEM(5066) * 3 / 4 + MEM(0) / 2;
	MEM(16364) = -Acc;
	Acc = MEM(15151) / 8 + MEM(14235) / 8 + -MEM(14128) / 4 + -MEM(13511) / 4 + -MEM(14338) / 4 + MEM(1534) / 2;
	MEM(1535) = Acc;
	Acc = Acc * 3 / 32 + MEM(13263) / 32 + MEM(12815) / 32 + MEM(11350) / 32 + MEM(12495) / 32 + MEM(12350) / 32 + -MEM(11657) / 16 + -MEM(12127) / 16 + -MEM(11892) / 16 + -MEM(11828) / 16 + -MEM(11535) / 16 + -MEM(12659) / 16 + MEM(11255) / 8 + MEM(11149) / 8 + MEM(10963) / 8 + MEM(10850) / 8 + MEM(10625) / 8 + MEM(9525) / 8 + -MEM(10349) / 4 + -MEM(10225) / 4 + -MEM(10161) / 4 + -MEM(9258) / 4 + MEM(1531) / 2;
	MEM(1532) = Acc;
	*out_left = tmp_5;
	Acc = Acc * 3 / 8 + MEM(9850) / 8 + MEM(9602) / 8 + MEM(10547) / 8 + MEM(9345) / 8 + MEM(9938) / 8 + MEM(9163) / 8 + MEM(8945) / 8 + -MEM(8648) / 4 + -MEM(8493) / 4 + -MEM(8350) / 4 + -MEM(7169) / 4 + -MEM(7937) / 4 + -MEM(7819) / 4 + -MEM(6871) / 4 + MEM(1528) / 2;
	MEM(1529) = Acc;
	*out_right = tmp_3;
	Acc = Acc * -3 / 4 + -MEM(7499) / 4 + -MEM(7372) / 4 + -MEM(7213) / 4 + -MEM(8238) / 4 + -MEM(6935) / 4 + -MEM(7684) / 4 + -MEM(6619) / 4 + -MEM(6517) / 4 + -MEM(6338) / 4 + -MEM(6274) / 4 + MEM(6099) / 2 + MEM(5956) / 2 + MEM(5806) / 2 + MEM(5650) / 2 + MEM(5569) / 2 + MEM(5361) / 2 + MEM(5130) / 2;
	MEM(11) = Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_49(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(190);
	tmp_3 = -Acc;
	Acc = MEM(187);
	tmp_5 = -Acc;
	Acc = MEM(193) / 2 + MEM(14384) / 2;
	MEM(194) = Acc;
	Acc = -MEM(10) / 4 + MEM(184) / 2;
	MEM(185) = Acc;
	Acc = Acc * 3 / 2 + MEM(193) + MEM(14369) / 2;
	MEM(14382) = -Acc;
	Acc = -Acc / 2 + MEM(14369) + MEM(14284) / 2;
	MEM(14367) = -Acc;
	Acc = -Acc / 2 + MEM(14284) + MEM(14166) / 2;
	MEM(14282) = -Acc;
	Acc = -Acc / 2 + MEM(14166) + MEM(13925) / 2;
	MEM(14164) = -Acc;
	Acc = -Acc / 2 + MEM(13925) + MEM(13584) / 2;
	MEM(13923) = -Acc;
	Acc = -Acc / 2 + MEM(13584) + MEM(13101) / 2;
	MEM(13582) = -Acc;
	Acc = -Acc / 2 + MEM(13101) + MEM(12544) / 2;
	MEM(13099) = -Acc;
	Acc = -Acc / 2 + MEM(12544) + MEM(11719) / 2;
	MEM(12542) = -Acc;
	Acc = -Acc / 2 + MEM(11719) + MEM(10718) / 2;
	MEM(11717) = -Acc;
	Acc = -Acc / 2 + MEM(10718) + MEM(9616) / 2;
	MEM(10716) = -Acc;
	Acc = -Acc / 2 + MEM(9616) + MEM(8267) / 2;
	MEM(9614) = -Acc;
	Acc = -Acc / 2 + MEM(8267) + MEM(6702) / 2;
	MEM(8265) = -Acc;
	Acc = -Acc / 2 + MEM(6702) + MEM(4859) / 2;
	MEM(6700) = -Acc;
	Acc = -Acc / 2 + MEM(4859) + MEM(2856) / 2;
	MEM(4857) = -Acc;
	Acc = -Acc / 2 + MEM(2856) + MEM(771) / 2;
	MEM(2854) = -Acc;
	Acc = -Acc / 2 + MEM(771);
	MEM(11) = -Acc;
	Acc = MEM(11) + MEM(520) / 2;
	MEM(667) = -Acc;
	Acc = -Acc / 2 + MEM(520) + MEM(726) / 2;
	MEM(769) = -Acc;
	Acc = -Acc / 2 + MEM(726) + MEM(669) / 2;
	MEM(724) = -Acc;
	Acc = -Acc / 2 + MEM(669);
	MEM(191) = -Acc;
	Acc = MEM(11) + MEM(196) / 2;
	MEM(445) = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 2 + MEM(196) + MEM(447) / 2;
	MEM(495) = -Acc;
	Acc = -Acc / 2 + MEM(447) + MEM(497) / 2;
	MEM(518) = -Acc;
	Acc = -Acc / 2 + MEM(497);
	MEM(188) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_50(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_51(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_52(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_53(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_54(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_55(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_56(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_57(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_58(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_59(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_60(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_61(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_62(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_63(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_64(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_65(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_66(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_67(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_68(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_69(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_0, tmp_3, tmp_5, tmp_fa7, tmp_fa8, tmp_fa9, tmp_faa, tmp_fab, tmp_fac, tmp_fad, tmp_1f47, tmp_1f48, tmp_1f49, tmp_1f4a, tmp_1f4b, tmp_1f4c, tmp_1f4d;
	tmp_0 = input;
	Acc = tmp_0;
	MEM(16282) = Acc;
	Acc = MEM(16286 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16277 - (lfo1_value >> 8)) * 27 / 1024 + MEM(16285 - (lfo1_value >> 8)) * -27 / 512 + MEM(16278 - (lfo1_value >> 8)) * -27 / 512 + MEM(16284 - (lfo1_value >> 8)) * 27 / 256 + MEM(16279 - (lfo1_value >> 8)) * 27 / 256 + MEM(16283 - (lfo1_value >> 8)) * -27 / 128 + MEM(16280 - (lfo1_value >> 8)) * -27 / 128 + MEM(16282 - (lfo1_value >> 8)) * 81 / 128 + MEM(16281 - (lfo1_value >> 8)) * 81 / 128;
	tmp_1f4a = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f48 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4a / 2;
	tmp_1f4c = Acc;
	Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f48 / 2;
	tmp_1f47 = Acc;
	Acc = tmp_1f48 / 2 + tmp_1f4a / 2;
	tmp_1f49 = Acc;
	Acc = MEM(16281 - (lfo1_value >> 8)) / 2 + tmp_1f4c / 2;
	tmp_1f4d = Acc;
	Acc = tmp_1f4c / 2 + tmp_1f4a / 2;
	tmp_1f4b = Acc;
	switch ((lfo1_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo1_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo1_value >> 8)) / 2 + tmp_1f47 / 2;
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
		Acc = tmp_1f4d / 2 + MEM(16281 - (lfo1_value >> 8)) / 2;
		break;
	}
	tmp_3 = -Acc;
	Acc = MEM(16286 - (lfo2_value >> 8)) * 9 / 512 + MEM(16277 - (lfo2_value >> 8)) * 9 / 512 + MEM(16285 - (lfo2_value >> 8)) * -9 / 256 + MEM(16278 - (lfo2_value >> 8)) * -9 / 256 + MEM(16284 - (lfo2_value >> 8)) * 9 / 128 + MEM(16279 - (lfo2_value >> 8)) * 9 / 128 + MEM(16283 - (lfo2_value >> 8)) * -9 / 64 + MEM(16280 - (lfo2_value >> 8)) * -9 / 64 + MEM(16282 - (lfo2_value >> 8)) * 27 / 64 + MEM(16281 - (lfo2_value >> 8)) * 27 / 64;
	MEM(4006 - (lfo2_value >> 8)) = Acc;
	Acc = Acc * 3 / 2;
	tmp_faa = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fa8 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_faa / 2;
	tmp_fac = Acc;
	Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa8 / 2;
	tmp_fa7 = Acc;
	Acc = tmp_fa8 / 2 + tmp_faa / 2;
	tmp_fa9 = Acc;
	Acc = MEM(16281 - (lfo2_value >> 8)) / 2 + tmp_fac / 2;
	tmp_fad = Acc;
	Acc = tmp_fac / 2 + tmp_faa / 2;
	tmp_fab = Acc;
	switch ((lfo2_value >> 4) & 15) {
	case 0:
		Acc = MEM(16282 - (lfo2_value >> 8));
		break;
	case 1:
		Acc = MEM(16282 - (lfo2_value >> 8)) / 2 + tmp_fa7 / 2;
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
		Acc = tmp_fad / 2 + MEM(16281 - (lfo2_value >> 8)) / 2;
		break;
	}
	tmp_5 = -Acc;
	*out_left = tmp_5;
	Acc = -Acc / 32768;
	MEM(16374) = -Acc;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_70(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(15212);
	tmp_3 = Acc;
	Acc = MEM(15212);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_71(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(14626);
	tmp_3 = Acc;
	Acc = MEM(14626);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_72(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(14040);
	tmp_3 = Acc;
	Acc = MEM(14040);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_73(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(12868);
	tmp_3 = Acc;
	Acc = MEM(12868);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_74(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(11696);
	tmp_3 = Acc;
	Acc = MEM(11696);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_75(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(11462);
	tmp_3 = Acc;
	Acc = MEM(11462);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_76(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(11228);
	tmp_3 = Acc;
	Acc = MEM(11228);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_77(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(10993);
	tmp_3 = Acc;
	Acc = MEM(10993);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_78(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(10759);
	tmp_3 = Acc;
	Acc = MEM(10759);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_79(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(10525);
	tmp_3 = Acc;
	Acc = MEM(10525);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_80(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(10290);
	tmp_3 = Acc;
	Acc = MEM(10290);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_81(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(10056);
	tmp_3 = Acc;
	Acc = MEM(10056);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_82(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(9821);
	tmp_3 = Acc;
	Acc = MEM(9821);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_83(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(9587);
	tmp_3 = Acc;
	Acc = MEM(9587);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_84(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(9353);
	tmp_3 = Acc;
	Acc = MEM(9353);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_85(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(8884);
	tmp_3 = Acc;
	Acc = MEM(8884);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_86(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(8415);
	tmp_3 = Acc;
	Acc = MEM(8415);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_87(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(7243);
	tmp_3 = Acc;
	Acc = MEM(7243);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_88(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(4665);
	tmp_3 = Acc;
	Acc = MEM(4665);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_89(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(2321);
	tmp_3 = Acc;
	Acc = MEM(2321);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_90(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(679) / 2 + MEM(8531) + MEM(289) / 2;
	MEM(330) = -Acc;
	Acc = -Acc / 2 + MEM(289) + MEM(92) / 2;
	MEM(287) = -Acc;
	Acc = -Acc / 2 + MEM(92) + MEM(27) / 2;
	MEM(90) = -Acc;
	Acc = -Acc / 2 + MEM(27);
	tmp_5 = -Acc;
	Acc = MEM(679) / 2 + MEM(8531) + MEM(628) / 2;
	MEM(677) = -Acc;
	Acc = -Acc / 2 + MEM(628) + MEM(512) / 2;
	MEM(626) = -Acc;
	Acc = -Acc / 2 + MEM(512) + MEM(332) / 2;
	MEM(510) = -Acc;
	Acc = -Acc / 2 + MEM(332);
	tmp_3 = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_91(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(10924) + MEM(6) / 2;
	tmp_5 = Acc;
	Acc = tmp_5 * 21 / 32;
	tmp_5 = -Acc;
	Acc = MEM(5465) + MEM(6) / 2;
	tmp_3 = Acc;
	Acc = tmp_3 * 21 / 32;
	tmp_3 = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_92(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(2386) / 128 + MEM(2416) / 128 + MEM(2429) / 128 + MEM(2427) / 128 + MEM(2569) / 128 + -MEM(2565) / 64 + -MEM(2635) / 64 + -MEM(2628) / 64 + -MEM(2708) / 64 + MEM(2832) / 32 + MEM(3065) / 32 + MEM(3199) / 32 + MEM(3457) / 32 + MEM(3728) / 32 + -MEM(4046) / 16 + -MEM(4465) / 16 + -MEM(5023) / 16 + -MEM(5701) / 16 + MEM(6549) / 8 + MEM(7609) / 8 + -MEM(6934) / 4 + -MEM(11190) / 4 + MEM(11883) / 2 + MEM(13660) / 2 + MEM(15603) / 2;
	tmp_3 = -Acc;
	Acc = MEM(2398) / 128 + MEM(2465) / 128 + MEM(2466) / 128 + MEM(2412) / 128 + MEM(2577) / 128 + MEM(2530) / 128 + -MEM(2657) / 64 + -MEM(2765) / 64 + -MEM(2865) / 64 + MEM(2927) / 32 + MEM(3095) / 32 + MEM(3313) / 32 + -MEM(3657) / 16 + -MEM(3935) / 16 + -MEM(4368) / 16 + -MEM(4813) / 16 + MEM(5403) / 8 + MEM(6224) / 8 + MEM(7239) / 8 + MEM(7471) / 8 + -MEM(9511) / 4 + -MEM(12336) / 4 + MEM(13343) / 2 + MEM(15263) / 2;
	tmp_5 = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_93(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(11) / 2 + MEM(2231) / 2;
	MEM(2298) = -Acc;
	Acc = -Acc / 2 + MEM(2231) + MEM(2108) / 2;
	MEM(2229) = -Acc;
	Acc = -Acc / 2 + MEM(2108) + MEM(2384);
	tmp_3 = -Acc;
	Acc = MEM(9) / 2 + MEM(1886) / 2;
	MEM(1931) = -Acc;
	Acc = -Acc / 2 + MEM(1886) + MEM(1786) / 2;
	MEM(1884) = -Acc;
	Acc = -Acc / 2 + MEM(1786);
	tmp_5 = -Acc;
	Acc = MEM(15319) / 32 + MEM(15151) / 32 + MEM(14829) / 32 + MEM(14522) / 32 + MEM(12815) / 32 + MEM(13941) / 32 + MEM(13663) / 32 + -MEM(13511) / 16 + -MEM(13805) / 16 + -MEM(12933) / 16 + -MEM(3272) / 16 + -MEM(12659) / 16 + -MEM(12495) / 16 + MEM(12232) / 8 + MEM(11892) / 8 + MEM(10349) / 8 + MEM(4039) / 8 + MEM(5273) / 8 + MEM(11149) / 8 + MEM(10850) / 8 + -MEM(10625) / 4 + -MEM(11350) / 4 + -MEM(6173) / 4 + -MEM(7261) / 4 + -MEM(3603) / 4 + -MEM(10963) / 4 + -MEM(9850) / 4 + MEM(9525) / 2 + MEM(9258) / 2 + MEM(7819) / 2 + MEM(8648) / 2 + MEM(7169) / 2 + MEM(8238) / 2;
	MEM(10) = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
	Acc = MEM(10625) / 8 + MEM(10547) / 8 + MEM(11350) / 8 + MEM(10225) / 8 + MEM(10963) / 8 + MEM(9938) / 8 + MEM(9850) / 8 + MEM(9602) / 8 + MEM(9525) / 8 + MEM(9345) / 8 + MEM(9258) / 8 + MEM(9163) / 8 + MEM(7819) / 8 + MEM(8850) / 8 + MEM(8648) / 8 + MEM(8493) / 8 + MEM(7169) / 8 + MEM(8238) / 8 + MEM(8106) / 8 + -MEM(7937) / 4 + -MEM(8945) / 4 + -MEM(7684) / 4 + -MEM(7499) / 4 + -MEM(7372) / 4 + -MEM(7213) / 4 + -MEM(8350) / 4 + -MEM(6935) / 4 + -MEM(6871) / 4 + -MEM(6619) / 4 + -MEM(6517) / 4 + -MEM(6338) / 4 + -MEM(6274) / 4 + -MEM(6099) / 4 + -MEM(4310) / 4 + -MEM(5806) / 4 + -MEM(5650) / 4 + -MEM(4669) / 4 + -MEM(5361) / 4 + -MEM(5199) / 4 + MEM(5130) / 2 + MEM(4905) / 2 + MEM(4838) / 2 + MEM(5569) / 2 + MEM(4537) / 2 + MEM(5956) / 2 + MEM(4272) / 2 + MEM(4105) / 2 + MEM(3969) / 2 + MEM(3868) / 2 + MEM(3638) / 2 + MEM(3569) / 2 + MEM(3338) / 2 + MEM(3167) / 2 + MEM(3006) / 2 + MEM(2850) / 2;
	MEM(12) = -Acc;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_94(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3;
	MEM(0) = input;
	Acc = MEM(16383) + MEM(4) / 2 + MEM(16347) / 2;
	MEM(16381) = -Acc;
	Acc = -Acc / 2 + MEM(16347) + MEM(16300) / 2;
	MEM(16345) = -Acc;
	Acc = -Acc / 2 + MEM(16300) + MEM(16231) / 2;
	MEM(16298) = -Acc;
	Acc = -Acc / 2 + MEM(16231) + MEM(16140) / 2;
	MEM(16229) = -Acc;
	Acc = -Acc / 2 + MEM(16140) + MEM(16037) / 2;
	MEM(16138) = -Acc;
	Acc = -Acc / 2 + MEM(16037) + MEM(15915) / 2;
	MEM(16035) = -Acc;
	Acc = -Acc / 2 + MEM(15915);
	tmp_3 = -Acc;
	Acc = tmp_3;
	MEM(5) = -Acc;
	*out_left = MEM(5);
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_95(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(16234);
	tmp_3 = Acc;
	Acc = MEM(16084);
	tmp_5 = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_96(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = -MEM(14260) / 4 + MEM(14263);
	tmp_3 = -Acc;
	Acc = -MEM(14263) / 4 + MEM(14260);
	tmp_5 = -Acc;
	Acc = MEM(16381) * 3 / 2 + MEM(16074) / 2;
	MEM(16089) = -Acc;
	Acc = -Acc / 2 + MEM(16074) + MEM(16050) / 2;
	MEM(16072) = -Acc;
	Acc = -Acc / 2 + MEM(16050) + MEM(16019) / 2;
	MEM(16048) = -Acc;
	Acc = -Acc / 2 + MEM(16019) + MEM(15972) / 2;
	MEM(16017) = -Acc;
	Acc = -Acc / 2 + MEM(15972) + MEM(15909) / 2;
	MEM(15970) = -Acc;
	Acc = -Acc / 2 + MEM(15909) + MEM(14892) / 2;
	MEM(14997) = -Acc;
	Acc = -Acc / 2 + MEM(14892) + MEM(14741) / 2;
	MEM(14890) = -Acc;
	Acc = -Acc / 2 + MEM(14741) + MEM(14526) / 2;
	MEM(14739) = -Acc;
	Acc = -Acc / 2 + MEM(14526) + MEM(14266) / 2;
	MEM(14524) = -Acc;
	Acc = -Acc / 2 + MEM(14266);
	MEM(14264) = -Acc;
	Acc = MEM(16381) * 3 / 2 + MEM(15193) / 2;
	MEM(15210) = -Acc;
	Acc = -Acc / 2 + MEM(15193) + MEM(15166) / 2;
	MEM(15191) = -Acc;
	Acc = -Acc / 2 + MEM(15166) + MEM(15129) / 2;
	MEM(15164) = -Acc;
	Acc = -Acc / 2 + MEM(15129) + MEM(15075) / 2;
	MEM(15127) = -Acc;
	Acc = -Acc / 2 + MEM(15075) + MEM(14999) / 2;
	MEM(15073) = -Acc;
	Acc = -Acc / 2 + MEM(14999) + MEM(15819) / 2;
	MEM(15907) = -Acc;
	Acc = -Acc / 2 + MEM(15819) + MEM(15694) / 2;
	MEM(15817) = -Acc;
	Acc = -Acc / 2 + MEM(15694) + MEM(15518) / 2;
	MEM(15692) = -Acc;
	Acc = -Acc / 2 + MEM(15518) + MEM(15212) / 2;
	MEM(15516) = -Acc;
	Acc = -Acc / 2 + MEM(15212);
	MEM(14261) = -Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_97(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(10521);
	tmp_3 = -Acc;
	Acc = MEM(10521);
	tmp_5 = -Acc;
	Acc = MEM(16382) + MEM(10521) / 2;
	MEM(16380) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_98(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(7591);
	tmp_3 = -Acc;
	Acc = MEM(7591);
	tmp_5 = -Acc;
	Acc = MEM(16382) + MEM(7591) / 2;
	MEM(16380) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
#include <stdint.h>
#define MEM(a) (DRAM[(ptr + a) & 0x3fff])
void midiverb2_effect_99(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr, uint32_t lfo1_value, uint32_t lfo2_value) {
	int16_t Acc, tmp_3, tmp_5;
	MEM(0) = input;
	Acc = MEM(4662);
	tmp_3 = -Acc;
	Acc = MEM(4662);
	tmp_5 = -Acc;
	Acc = MEM(16382) + MEM(4662) / 2;
	MEM(16380) = Acc;
	*out_left = tmp_5;
	*out_right = tmp_3;
}
#undef MEM
void (*midiverb2_effects[])(int16_t input, int16_t *out_left, int16_t *out_right, int16_t *DRAM, int ptr) = {
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
