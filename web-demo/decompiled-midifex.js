// Auto-generated JavaScript DSP code from disasm.py
// These functions share the same DRAM array with the emulator

/* Midifex effect 1: ECHO LONG FLAT AMBI */
function midifex_effect_1(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 15714) + ((LINE(7, 668, 49) / 2) | 0);
  WRITE_LINE(0, 668, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 668, 49) + ((LINE(6, 617, 114) / 2) | 0);
  WRITE_LINE(0, 617, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 617, 114) + ((LINE(5, 501, 178) / 2) | 0);
  WRITE_LINE(0, 501, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 501, 178);
  WRITE_LINE(0, 3, Acc);
  Acc = LINE(0, 0, 15714) + ((LINE(4, 321, 41) / 2) | 0);
  WRITE_LINE(0, 321, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 321, 41) + ((LINE(3, 278, 195) / 2) | 0);
  WRITE_LINE(0, 278, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 278, 195) + ((LINE(2, 81, 63) / 2) | 0);
  WRITE_LINE(0, 81, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(2, 81, 63);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 2: ECHO LONG FLAT THICK */
function midifex_effect_2(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_d, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 11257) + ((LINE(18, 5125, 87) / 2) | 0);
  WRITE_LINE(0, 5125, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(18, 5125, 87) + ((LINE(17, 5036, 103) / 2) | 0);
  WRITE_LINE(0, 5036, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(17, 5036, 103) + ((LINE(16, 4931, 127) / 2) | 0);
  WRITE_LINE(0, 4931, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(16, 4931, 127) + ((LINE(15, 4802, 143) / 2) | 0);
  WRITE_LINE(0, 4802, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(15, 4802, 143) + ((LINE(14, 4657, 174) / 2) | 0);
  WRITE_LINE(0, 4657, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(14, 4657, 174) + ((LINE(13, 4481, 215) / 2) | 0);
  WRITE_LINE(0, 4481, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(13, 4481, 215) + ((LINE(12, 4264, 251) / 2) | 0);
  WRITE_LINE(0, 4264, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(12, 4264, 251) + ((LINE(11, 4011, 300) / 2) | 0);
  WRITE_LINE(0, 4011, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 4011, 300) + ((LINE(10, 3709, 369) / 2) | 0);
  WRITE_LINE(0, 3709, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 3709, 369) + ((LINE(9, 3338, 4) / 2) | 0);
  WRITE_LINE(0, 3338, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 3338, 4) + ((LINE(8, 3332, 5) / 2) | 0);
  WRITE_LINE(0, 3332, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 3332, 5) + ((LINE(7, 3325, 62) / 2) | 0);
  WRITE_LINE(0, 3325, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 3325, 62) + ((LINE(6, 3261, 75) / 2) | 0);
  WRITE_LINE(0, 3261, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 3261, 75) + ((LINE(5, 3184, 9) / 2) | 0);
  WRITE_LINE(0, 3184, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 3184, 9);
  tmp_d = Acc;
  Acc = tmp_d + ((LINE(4, 3173, 36) / 2) | 0);
  WRITE_LINE(0, 3173, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 3173, 36);
  WRITE_LINE(0, 6, -Acc);
  Acc = tmp_d + ((LINE(3, 3135, 30) / 2) | 0);
  WRITE_LINE(0, 3135, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 3135, 30);
  WRITE_LINE(0, 4, -Acc);
  out_left = LINE(2, 6, 1);
  out_right = LINE(1, 4, 1);
  return [out_left, out_right];
}
/* Midifex effect 3: ECHO LONG HPF */
function midifex_effect_3(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(3, 6080, 1);
  tmp_5 = Acc;
  Acc = LINE(3, 6080, 1);
  tmp_3 = Acc;
  Acc = ((LINE(4, 6083, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(0, 0, 10299) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 6083, Acc);
  Acc = LINE(4, 6083, 1);
  tmp_1 = -Acc;
  Acc = LINE(0, 0, 10299) + tmp_1;
  WRITE_LINE(0, 6074, Acc);
  Acc = ((LINE(2, 6077, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(1, 6074, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 6077, Acc);
  Acc = LINE(2, 6077, 1);
  tmp_1 = -Acc;
  Acc = LINE(1, 6074, 1) + tmp_1;
  WRITE_LINE(0, 6080, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 4: ECHO LONG HPF WIDE */
function midifex_effect_4(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1cd0, tmp_1, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(5, 7379, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(0, 0, 9003) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 7379, Acc);
  Acc = LINE(5, 7379, 1);
  tmp_1 = -Acc;
  Acc = LINE(0, 0, 9003) + tmp_1;
  WRITE_LINE(0, 7355, Acc);
  Acc = ((LINE(4, 7373, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(3, 7355, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 7373, Acc);
  Acc = LINE(4, 7373, 1);
  tmp_1 = -Acc;
  Acc = LINE(3, 7355, 1) + tmp_1;
  tmp_1cd0 = Acc;
  Acc = tmp_1cd0;
  WRITE_LINE(0, 4, Acc);
  Acc = tmp_1cd0;
  WRITE_LINE(0, 201, Acc);
  out_left = LINE(2, 201, 196);
  out_right = LINE(1, 4, 1);
  return [out_left, out_right];
}
/* Midifex effect 5: ECHO LONG BPF AMBI */
function midifex_effect_5(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(9, 16381, 8424) + ((LINE(5, 7608, 41) / 2) | 0);
  WRITE_LINE(0, 7608, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 7608, 41) + ((LINE(4, 7565, 195) / 2) | 0);
  WRITE_LINE(0, 7565, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 7565, 195) + ((LINE(3, 7368, 63) / 2) | 0);
  WRITE_LINE(0, 7368, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 7368, 63);
  tmp_5 = Acc;
  Acc = LINE(9, 16381, 8424) + ((LINE(8, 7955, 49) / 2) | 0);
  WRITE_LINE(0, 7955, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 7955, 49) + ((LINE(7, 7904, 114) / 2) | 0);
  WRITE_LINE(0, 7904, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 7904, 114) + ((LINE(6, 7788, 178) / 2) | 0);
  WRITE_LINE(0, 7788, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 7788, 178);
  tmp_3 = Acc;
  Acc = ((LINE(0, 0, 1) / 2) | 0) + ((LINE(2, 7303, 1) / 2) | 0);
  WRITE_LINE(0, 7303, Acc);
  Acc = ((LINE(1, 7300, 1) * 15 / 16) | 0);
  tmp_1 = Acc;
  Acc = ((Acc * -3 / 16) | 0) + ((LINE(2, 7303, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 7300, Acc);
  Acc = LINE(1, 7300, 1);
  tmp_1 = -Acc;
  Acc = ((LINE(2, 7303, 1) * 3 / 2) | 0) + ((tmp_1 * 3 / 2) | 0);
  WRITE_LINE(0, 16381, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 6: ECHO LONG LPF WIDE */
function midifex_effect_6(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(23, 16381, 7722) * 3 / 2) | 0) + ((LINE(22, 8657, 15) / 2) | 0);
  WRITE_LINE(0, 8657, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(22, 8657, 15) + ((LINE(21, 8640, 22) / 2) | 0);
  WRITE_LINE(0, 8640, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(21, 8640, 22) + ((LINE(20, 8616, 29) / 2) | 0);
  WRITE_LINE(0, 8616, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(20, 8616, 29) + ((LINE(19, 8585, 45) / 2) | 0);
  WRITE_LINE(0, 8585, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(19, 8585, 45) + ((LINE(18, 8538, 61) / 2) | 0);
  WRITE_LINE(0, 8538, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(18, 8538, 61) + ((LINE(8, 7565, 105) / 2) | 0);
  WRITE_LINE(0, 7565, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 7565, 105) + ((LINE(7, 7458, 149) / 2) | 0);
  WRITE_LINE(0, 7458, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 7458, 149) + ((LINE(6, 7307, 213) / 2) | 0);
  WRITE_LINE(0, 7307, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 7307, 213) + ((LINE(5, 7092, 258) / 2) | 0);
  WRITE_LINE(0, 7092, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 7092, 258);
  WRITE_LINE(0, 4, Acc);
  Acc = ((LINE(23, 16381, 7722) * 3 / 2) | 0) + ((LINE(13, 7778, 17) / 2) | 0);
  WRITE_LINE(0, 7778, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(13, 7778, 17) + ((LINE(12, 7759, 25) / 2) | 0);
  WRITE_LINE(0, 7759, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(12, 7759, 25) + ((LINE(11, 7732, 35) / 2) | 0);
  WRITE_LINE(0, 7732, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 7732, 35) + ((LINE(10, 7695, 52) / 2) | 0);
  WRITE_LINE(0, 7695, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 7695, 52) + ((LINE(9, 7641, 74) / 2) | 0);
  WRITE_LINE(0, 7641, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 7641, 74) + ((LINE(17, 8475, 88) / 2) | 0);
  WRITE_LINE(0, 8475, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(17, 8475, 88) + ((LINE(16, 8385, 123) / 2) | 0);
  WRITE_LINE(0, 8385, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(16, 8385, 123) + ((LINE(15, 8260, 174) / 2) | 0);
  WRITE_LINE(0, 8260, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(15, 8260, 174) + ((LINE(14, 8084, 304) / 2) | 0);
  WRITE_LINE(0, 8084, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(14, 8084, 304);
  WRITE_LINE(0, 601, Acc);
  Acc = ((LINE(4, 6832, 1) * 3 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(0, 0, 1) * 5 / 8) | 0) + tmp_1;
  WRITE_LINE(0, 6832, Acc);
  out_left = LINE(2, 601, 596);
  Acc = ((LINE(3, 6826, 1) * 5 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(4, 6832, 1) * 3 / 8) | 0) + tmp_1;
  WRITE_LINE(0, 6826, Acc);
  Acc = LINE(3, 6826, 1);
  WRITE_LINE(0, 16381, Acc);
  out_right = LINE(1, 4, 1);
  return [out_left, out_right];
}
/* Midifex effect 7: ECHO MED FLAT AMBI */
function midifex_effect_7(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 7385) + ((LINE(7, 8997, 49) / 2) | 0);
  WRITE_LINE(0, 8997, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 8997, 49) + ((LINE(6, 8946, 114) / 2) | 0);
  WRITE_LINE(0, 8946, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 8946, 114) + ((LINE(5, 8830, 178) / 2) | 0);
  WRITE_LINE(0, 8830, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 8830, 178);
  WRITE_LINE(0, 3, Acc);
  Acc = LINE(0, 0, 7385) + ((LINE(4, 8650, 41) / 2) | 0);
  WRITE_LINE(0, 8650, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 8650, 41) + ((LINE(3, 8607, 195) / 2) | 0);
  WRITE_LINE(0, 8607, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 8607, 195) + ((LINE(2, 8410, 63) / 2) | 0);
  WRITE_LINE(0, 8410, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(2, 8410, 63);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 8: ECHO MED FLAT WIDE */
function midifex_effect_8(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(1, 7566, 600) / 8) | 0) + ((-LINE(2, 7569, 1) / 2) | 0);
  tmp_3 = Acc;
  Acc = ((LINE(2, 7569, 1) / 8) | 0) + ((-LINE(1, 7566, 600) / 2) | 0);
  tmp_5 = Acc;
  Acc = ((LINE(0, 0, 6698) * 3 / 2) | 0) + ((LINE(20, 9394, 15) / 2) | 0);
  WRITE_LINE(0, 9394, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(20, 9394, 15) + ((LINE(19, 9377, 22) / 2) | 0);
  WRITE_LINE(0, 9377, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(19, 9377, 22) + ((LINE(18, 9353, 29) / 2) | 0);
  WRITE_LINE(0, 9353, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(18, 9353, 29) + ((LINE(17, 9322, 45) / 2) | 0);
  WRITE_LINE(0, 9322, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(17, 9322, 45) + ((LINE(16, 9275, 61) / 2) | 0);
  WRITE_LINE(0, 9275, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(16, 9275, 61) + ((LINE(6, 8348, 105) / 2) | 0);
  WRITE_LINE(0, 8348, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 8348, 105) + ((LINE(5, 8241, 149) / 2) | 0);
  WRITE_LINE(0, 8241, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 8241, 149) + ((LINE(4, 8090, 213) / 2) | 0);
  WRITE_LINE(0, 8090, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 8090, 213) + ((LINE(3, 7875, 304) / 2) | 0);
  WRITE_LINE(0, 7875, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 7875, 304);
  WRITE_LINE(0, 7569, Acc);
  Acc = ((LINE(0, 0, 6698) * 3 / 2) | 0) + ((LINE(11, 8561, 17) / 2) | 0);
  WRITE_LINE(0, 8561, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 8561, 17) + ((LINE(10, 8542, 25) / 2) | 0);
  WRITE_LINE(0, 8542, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 8542, 25) + ((LINE(9, 8515, 35) / 2) | 0);
  WRITE_LINE(0, 8515, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 8515, 35) + ((LINE(8, 8478, 52) / 2) | 0);
  WRITE_LINE(0, 8478, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 8478, 52) + ((LINE(7, 8424, 74) / 2) | 0);
  WRITE_LINE(0, 8424, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 8424, 74) + ((LINE(15, 9212, 88) / 2) | 0);
  WRITE_LINE(0, 9212, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(15, 9212, 88) + ((LINE(14, 9122, 123) / 2) | 0);
  WRITE_LINE(0, 9122, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(14, 9122, 123) + ((LINE(13, 8997, 174) / 2) | 0);
  WRITE_LINE(0, 8997, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(13, 8997, 174) + ((LINE(12, 8821, 258) / 2) | 0);
  WRITE_LINE(0, 8821, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(12, 8821, 258);
  WRITE_LINE(0, 7566, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 9: ECHO MED HPF AMBI */
function midifex_effect_9(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(10, 16381, 6328) + ((LINE(6, 9704, 41) / 2) | 0);
  WRITE_LINE(0, 9704, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 9704, 41) + ((LINE(5, 9661, 195) / 2) | 0);
  WRITE_LINE(0, 9661, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 9661, 195) + ((LINE(4, 9464, 63) / 2) | 0);
  WRITE_LINE(0, 9464, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 9464, 63);
  tmp_5 = Acc;
  Acc = LINE(10, 16381, 6328) + ((LINE(9, 10051, 49) / 2) | 0);
  WRITE_LINE(0, 10051, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 10051, 49) + ((LINE(8, 10000, 114) / 2) | 0);
  WRITE_LINE(0, 10000, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 10000, 114) + ((LINE(7, 9884, 178) / 2) | 0);
  WRITE_LINE(0, 9884, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 9884, 178);
  tmp_3 = Acc;
  Acc = ((LINE(3, 9399, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(0, 0, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 9399, Acc);
  Acc = LINE(3, 9399, 1);
  tmp_1 = -Acc;
  Acc = LINE(0, 0, 1) + tmp_1;
  WRITE_LINE(0, 9384, Acc);
  Acc = ((LINE(2, 9393, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(1, 9384, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 9393, Acc);
  Acc = LINE(2, 9393, 1);
  tmp_1 = -Acc;
  Acc = LINE(1, 9384, 1) + tmp_1;
  WRITE_LINE(0, 16381, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 10: ECHO MED BPF AMBI */
function midifex_effect_10(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(9, 16381, 5625) + ((LINE(5, 10407, 41) / 2) | 0);
  WRITE_LINE(0, 10407, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 10407, 41) + ((LINE(4, 10364, 195) / 2) | 0);
  WRITE_LINE(0, 10364, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 10364, 195) + ((LINE(3, 10167, 63) / 2) | 0);
  WRITE_LINE(0, 10167, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 10167, 63);
  tmp_5 = Acc;
  Acc = LINE(9, 16381, 5625) + ((LINE(8, 10754, 49) / 2) | 0);
  WRITE_LINE(0, 10754, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 10754, 49) + ((LINE(7, 10703, 114) / 2) | 0);
  WRITE_LINE(0, 10703, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 10703, 114) + ((LINE(6, 10587, 178) / 2) | 0);
  WRITE_LINE(0, 10587, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 10587, 178);
  tmp_3 = Acc;
  Acc = ((LINE(0, 0, 1) / 2) | 0) + ((LINE(2, 10102, 1) / 2) | 0);
  WRITE_LINE(0, 10102, Acc);
  Acc = ((LINE(1, 10099, 1) * 15 / 16) | 0);
  tmp_1 = Acc;
  Acc = ((Acc * -3 / 16) | 0) + ((LINE(2, 10102, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 10099, Acc);
  Acc = LINE(1, 10099, 1);
  tmp_1 = -Acc;
  Acc = LINE(2, 10102, 1) + tmp_1;
  WRITE_LINE(0, 16381, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 11: ECHO MED LPF AMBI */
function midifex_effect_11(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(9, 16381, 5156) + ((LINE(5, 10876, 41) / 2) | 0);
  WRITE_LINE(0, 10876, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 10876, 41) + ((LINE(4, 10833, 195) / 2) | 0);
  WRITE_LINE(0, 10833, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 10833, 195) + ((LINE(3, 10636, 63) / 2) | 0);
  WRITE_LINE(0, 10636, -Acc);
  Acc = ((Acc * -3 / 4) | 0) + ((LINE(3, 10636, 63) * 3 / 2) | 0);
  tmp_5 = Acc;
  Acc = LINE(9, 16381, 5156) + ((LINE(8, 11223, 49) / 2) | 0);
  WRITE_LINE(0, 11223, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 11223, 49) + ((LINE(7, 11172, 114) / 2) | 0);
  WRITE_LINE(0, 11172, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 11172, 114) + ((LINE(6, 11056, 178) / 2) | 0);
  WRITE_LINE(0, 11056, -Acc);
  Acc = ((Acc * -3 / 4) | 0) + ((LINE(6, 11056, 178) * 3 / 2) | 0);
  tmp_3 = Acc;
  Acc = ((LINE(2, 10571, 1) * 3 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(0, 0, 1) * 5 / 8) | 0) + tmp_1;
  WRITE_LINE(0, 10571, Acc);
  Acc = ((LINE(1, 10568, 1) * 5 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(2, 10571, 1) * 3 / 8) | 0) + tmp_1;
  WRITE_LINE(0, 10568, Acc);
  Acc = LINE(1, 10568, 1);
  WRITE_LINE(0, 16381, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 12: ECHO MED LPF WIDE */
function midifex_effect_12(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(2, 9855, 1);
  tmp_3 = Acc;
  Acc = LINE(1, 9852, 600);
  tmp_5 = Acc;
  Acc = ((LINE(23, 16381, 4687) * 3 / 2) | 0) + ((LINE(22, 11692, 15) / 2) | 0);
  WRITE_LINE(0, 11692, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(22, 11692, 15) + ((LINE(21, 11675, 22) / 2) | 0);
  WRITE_LINE(0, 11675, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(21, 11675, 22) + ((LINE(20, 11651, 29) / 2) | 0);
  WRITE_LINE(0, 11651, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(20, 11651, 29) + ((LINE(19, 11620, 45) / 2) | 0);
  WRITE_LINE(0, 11620, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(19, 11620, 45) + ((LINE(18, 11573, 61) / 2) | 0);
  WRITE_LINE(0, 11573, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(18, 11573, 61) + ((LINE(8, 10600, 105) / 2) | 0);
  WRITE_LINE(0, 10600, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 10600, 105) + ((LINE(7, 10493, 149) / 2) | 0);
  WRITE_LINE(0, 10493, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 10493, 149) + ((LINE(6, 10342, 213) / 2) | 0);
  WRITE_LINE(0, 10342, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 10342, 213) + ((LINE(5, 10127, 258) / 2) | 0);
  WRITE_LINE(0, 10127, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 10127, 258);
  WRITE_LINE(0, 9855, Acc);
  Acc = ((LINE(23, 16381, 4687) * 3 / 2) | 0) + ((LINE(13, 10813, 17) / 2) | 0);
  WRITE_LINE(0, 10813, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(13, 10813, 17) + ((LINE(12, 10794, 25) / 2) | 0);
  WRITE_LINE(0, 10794, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(12, 10794, 25) + ((LINE(11, 10767, 35) / 2) | 0);
  WRITE_LINE(0, 10767, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 10767, 35) + ((LINE(10, 10730, 52) / 2) | 0);
  WRITE_LINE(0, 10730, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 10730, 52) + ((LINE(9, 10676, 74) / 2) | 0);
  WRITE_LINE(0, 10676, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 10676, 74) + ((LINE(17, 11510, 88) / 2) | 0);
  WRITE_LINE(0, 11510, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(17, 11510, 88) + ((LINE(16, 11420, 123) / 2) | 0);
  WRITE_LINE(0, 11420, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(16, 11420, 123) + ((LINE(15, 11295, 174) / 2) | 0);
  WRITE_LINE(0, 11295, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(15, 11295, 174) + ((LINE(14, 11119, 304) / 2) | 0);
  WRITE_LINE(0, 11119, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(14, 11119, 304);
  WRITE_LINE(0, 9852, Acc);
  Acc = ((LINE(4, 9867, 1) * 3 / 8) | 0);
  tmp_1 = Acc;
  out_left = tmp_5;
  Acc = ((LINE(0, 0, 1) * 5 / 8) | 0) + tmp_1;
  WRITE_LINE(0, 9867, Acc);
  Acc = ((LINE(3, 9861, 1) * 5 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(4, 9867, 1) * 3 / 8) | 0) + tmp_1;
  WRITE_LINE(0, 9861, Acc);
  out_right = tmp_3;
  Acc = LINE(3, 9861, 1);
  WRITE_LINE(0, 16381, Acc);
  return [out_left, out_right];
}
/* Midifex effect 13: ECHO MED FLAT THICK */
function midifex_effect_13(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_d, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 4224) + ((LINE(18, 12158, 87) / 2) | 0);
  WRITE_LINE(0, 12158, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(18, 12158, 87) + ((LINE(17, 12069, 103) / 2) | 0);
  WRITE_LINE(0, 12069, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(17, 12069, 103) + ((LINE(16, 11964, 127) / 2) | 0);
  WRITE_LINE(0, 11964, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(16, 11964, 127) + ((LINE(15, 11835, 143) / 2) | 0);
  WRITE_LINE(0, 11835, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(15, 11835, 143) + ((LINE(14, 11690, 174) / 2) | 0);
  WRITE_LINE(0, 11690, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(14, 11690, 174) + ((LINE(13, 11514, 215) / 2) | 0);
  WRITE_LINE(0, 11514, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(13, 11514, 215) + ((LINE(12, 11297, 251) / 2) | 0);
  WRITE_LINE(0, 11297, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(12, 11297, 251) + ((LINE(11, 11044, 300) / 2) | 0);
  WRITE_LINE(0, 11044, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 11044, 300) + ((LINE(10, 10742, 369) / 2) | 0);
  WRITE_LINE(0, 10742, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 10742, 369) + ((LINE(9, 10371, 4) / 2) | 0);
  WRITE_LINE(0, 10371, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 10371, 4) + ((LINE(8, 10365, 52) / 2) | 0);
  WRITE_LINE(0, 10365, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 10365, 52) + ((LINE(7, 10311, 62) / 2) | 0);
  WRITE_LINE(0, 10311, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 10311, 62) + ((LINE(6, 10247, 7) / 2) | 0);
  WRITE_LINE(0, 10247, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 10247, 7) + ((LINE(5, 10238, 13) / 2) | 0);
  WRITE_LINE(0, 10238, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 10238, 13);
  tmp_d = Acc;
  Acc = tmp_d + ((LINE(4, 10223, 36) / 2) | 0);
  WRITE_LINE(0, 10223, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 10223, 36);
  WRITE_LINE(0, 6, -Acc);
  Acc = tmp_d + ((LINE(3, 10185, 30) / 2) | 0);
  WRITE_LINE(0, 10185, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 10185, 30);
  WRITE_LINE(0, 4, -Acc);
  out_left = LINE(2, 6, 1);
  out_right = LINE(1, 4, 1);
  return [out_left, out_right];
}
/* Midifex effect 14: ECHO SHORT FLAT */
function midifex_effect_14(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 3753);
  WRITE_LINE(0, 3, Acc);
  Acc = LINE(0, 0, 3753);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 15: ECHO SHORT LPF AMBI */
function midifex_effect_15(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(9, 16381, 3515) + ((LINE(5, 9174, 41) / 2) | 0);
  WRITE_LINE(0, 9174, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 9174, 41) + ((LINE(4, 9131, 195) / 2) | 0);
  WRITE_LINE(0, 9131, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 9131, 195) + ((LINE(3, 8934, 63) / 2) | 0);
  WRITE_LINE(0, 8934, -Acc);
  Acc = ((Acc * -3 / 4) | 0) + ((LINE(3, 8934, 63) * 3 / 2) | 0);
  tmp_5 = Acc;
  Acc = LINE(9, 16381, 3515) + ((LINE(8, 9521, 49) / 2) | 0);
  WRITE_LINE(0, 9521, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 9521, 49) + ((LINE(7, 9470, 114) / 2) | 0);
  WRITE_LINE(0, 9470, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 9470, 114) + ((LINE(6, 9354, 178) / 2) | 0);
  WRITE_LINE(0, 9354, -Acc);
  Acc = ((Acc * -3 / 4) | 0) + ((LINE(6, 9354, 178) * 3 / 2) | 0);
  tmp_3 = Acc;
  Acc = ((LINE(2, 8869, 1) * 3 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(0, 0, 1) * 5 / 8) | 0) + tmp_1;
  WRITE_LINE(0, 8869, Acc);
  Acc = ((LINE(1, 8866, 1) * 5 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(2, 8869, 1) * 3 / 8) | 0) + tmp_1;
  WRITE_LINE(0, 8866, Acc);
  Acc = LINE(1, 8866, 1);
  WRITE_LINE(0, 16381, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 16: ECHO SHORT HPF AMBI */
function midifex_effect_16(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(12, 16381, 3281) + ((LINE(8, 12751, 41) / 2) | 0);
  WRITE_LINE(0, 12751, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 12751, 41) + ((LINE(7, 12708, 195) / 2) | 0);
  WRITE_LINE(0, 12708, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 12708, 195) + ((LINE(6, 12511, 63) / 2) | 0);
  WRITE_LINE(0, 12511, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 12511, 63);
  WRITE_LINE(0, 6, Acc);
  Acc = LINE(12, 16381, 3281) + ((LINE(11, 13098, 49) / 2) | 0);
  WRITE_LINE(0, 13098, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 13098, 49) + ((LINE(10, 13047, 114) / 2) | 0);
  WRITE_LINE(0, 13047, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 13047, 114) + ((LINE(9, 12931, 178) / 2) | 0);
  WRITE_LINE(0, 12931, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 12931, 178);
  WRITE_LINE(0, 4, Acc);
  Acc = ((LINE(5, 12446, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(0, 0, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 12446, Acc);
  Acc = LINE(5, 12446, 1);
  tmp_1 = -Acc;
  Acc = LINE(0, 0, 1) + tmp_1;
  WRITE_LINE(0, 12431, Acc);
  Acc = ((LINE(4, 12443, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(3, 12431, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 12443, Acc);
  Acc = LINE(4, 12443, 1);
  tmp_1 = -Acc;
  Acc = LINE(3, 12431, 1) + tmp_1;
  WRITE_LINE(0, 16381, Acc);
  out_left = LINE(2, 6, 1);
  out_right = LINE(1, 4, 1);
  return [out_left, out_right];
}
/* Midifex effect 17: ECHO SHORT BPF AMBI */
function midifex_effect_17(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(9, 16381, 3046) + ((LINE(5, 12986, 41) / 2) | 0);
  WRITE_LINE(0, 12986, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 12986, 41) + ((LINE(4, 12943, 195) / 2) | 0);
  WRITE_LINE(0, 12943, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 12943, 195) + ((LINE(3, 12746, 63) / 2) | 0);
  WRITE_LINE(0, 12746, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 12746, 63);
  tmp_5 = Acc;
  Acc = LINE(9, 16381, 3046) + ((LINE(8, 13333, 49) / 2) | 0);
  WRITE_LINE(0, 13333, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 13333, 49) + ((LINE(7, 13282, 114) / 2) | 0);
  WRITE_LINE(0, 13282, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 13282, 114) + ((LINE(6, 13166, 178) / 2) | 0);
  WRITE_LINE(0, 13166, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 13166, 178);
  tmp_3 = Acc;
  Acc = ((LINE(0, 0, 1) / 2) | 0) + ((LINE(2, 12681, 1) / 2) | 0);
  WRITE_LINE(0, 12681, Acc);
  Acc = ((LINE(1, 12678, 1) * 15 / 16) | 0);
  tmp_1 = Acc;
  Acc = ((Acc * -3 / 16) | 0) + ((LINE(2, 12681, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 12678, Acc);
  Acc = LINE(1, 12678, 1);
  tmp_1 = -Acc;
  Acc = ((LINE(2, 12681, 1) * 3 / 2) | 0) + ((tmp_1 * 3 / 2) | 0);
  WRITE_LINE(0, 16381, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 18: ECHO SHORT FLAT */
function midifex_effect_18(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 2815);
  WRITE_LINE(0, 3, Acc);
  Acc = LINE(0, 0, 2815);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 19: ECHO SHORT FLAT WIDE */
function midifex_effect_19(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((-LINE(1, 11684, 1) / 4) | 0) + LINE(2, 11687, 1);
  tmp_3 = Acc;
  Acc = ((-LINE(2, 11687, 1) / 4) | 0) + LINE(1, 11684, 1);
  tmp_5 = Acc;
  Acc = LINE(0, 0, 2580) + ((LINE(20, 13512, 15) / 2) | 0);
  WRITE_LINE(0, 13512, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(20, 13512, 15) + ((LINE(19, 13495, 22) / 2) | 0);
  WRITE_LINE(0, 13495, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(19, 13495, 22) + ((LINE(18, 13471, 29) / 2) | 0);
  WRITE_LINE(0, 13471, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(18, 13471, 29) + ((LINE(17, 13440, 45) / 2) | 0);
  WRITE_LINE(0, 13440, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(17, 13440, 45) + ((LINE(16, 13393, 61) / 2) | 0);
  WRITE_LINE(0, 13393, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(16, 13393, 61) + ((LINE(6, 12466, 105) / 2) | 0);
  WRITE_LINE(0, 12466, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 12466, 105) + ((LINE(5, 12359, 149) / 2) | 0);
  WRITE_LINE(0, 12359, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 12359, 149) + ((LINE(4, 12208, 213) / 2) | 0);
  WRITE_LINE(0, 12208, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 12208, 213) + ((LINE(3, 11993, 304) / 2) | 0);
  WRITE_LINE(0, 11993, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 11993, 304);
  WRITE_LINE(0, 11687, Acc);
  Acc = LINE(0, 0, 2580) + ((LINE(11, 12679, 17) / 2) | 0);
  WRITE_LINE(0, 12679, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 12679, 17) + ((LINE(10, 12660, 25) / 2) | 0);
  WRITE_LINE(0, 12660, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 12660, 25) + ((LINE(9, 12633, 35) / 2) | 0);
  WRITE_LINE(0, 12633, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 12633, 35) + ((LINE(8, 12596, 52) / 2) | 0);
  WRITE_LINE(0, 12596, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 12596, 52) + ((LINE(7, 12542, 74) / 2) | 0);
  WRITE_LINE(0, 12542, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 12542, 74) + ((LINE(15, 13330, 88) / 2) | 0);
  WRITE_LINE(0, 13330, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(15, 13330, 88) + ((LINE(14, 13240, 123) / 2) | 0);
  WRITE_LINE(0, 13240, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(14, 13240, 123) + ((LINE(13, 13115, 174) / 2) | 0);
  WRITE_LINE(0, 13115, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(13, 13115, 174) + ((LINE(12, 12939, 258) / 2) | 0);
  WRITE_LINE(0, 12939, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(12, 12939, 258);
  WRITE_LINE(0, 11684, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 20: ECHO XSHORT FLAT */
function midifex_effect_20(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 2346);
  WRITE_LINE(0, 3, Acc);
  Acc = LINE(0, 0, 2346);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 21: ECHO XSHORT BPF WIDE */
function midifex_effect_21(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((-LINE(1, 13597, 1) / 4) | 0) + LINE(2, 13600, 1);
  tmp_3 = Acc;
  Acc = ((-LINE(2, 13600, 1) / 4) | 0) + LINE(1, 13597, 1);
  tmp_5 = Acc;
  Acc = ((LINE(19, 16381, 2109) * 3 / 2) | 0) + ((LINE(18, 14229, 29) / 2) | 0);
  WRITE_LINE(0, 14229, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(18, 14229, 29) + ((LINE(17, 14198, 45) / 2) | 0);
  WRITE_LINE(0, 14198, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(17, 14198, 45) + ((LINE(16, 14151, 61) / 2) | 0);
  WRITE_LINE(0, 14151, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(16, 14151, 61) + ((LINE(8, 13756, 99) / 2) | 0);
  WRITE_LINE(0, 13756, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 13756, 99) + ((LINE(7, 13655, 14) / 2) | 0);
  WRITE_LINE(0, 13655, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 13655, 14) + ((LINE(6, 13639, 21) / 2) | 0);
  WRITE_LINE(0, 13639, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 13639, 21) + ((LINE(5, 13616, 2) / 2) | 0);
  WRITE_LINE(0, 13616, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 13616, 2);
  WRITE_LINE(0, 13600, Acc);
  Acc = ((LINE(19, 16381, 2109) * 3 / 2) | 0) + ((LINE(11, 13923, 35) / 2) | 0);
  WRITE_LINE(0, 13923, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 13923, 35) + ((LINE(10, 13886, 52) / 2) | 0);
  WRITE_LINE(0, 13886, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 13886, 52) + ((LINE(9, 13832, 74) / 2) | 0);
  WRITE_LINE(0, 13832, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 13832, 74) + ((LINE(15, 14088, 88) / 2) | 0);
  WRITE_LINE(0, 14088, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(15, 14088, 88) + ((LINE(14, 13998, 12) / 2) | 0);
  WRITE_LINE(0, 13998, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(14, 13998, 12) + ((LINE(13, 13984, 8) / 2) | 0);
  WRITE_LINE(0, 13984, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(13, 13984, 8) + ((LINE(12, 13974, 3) / 2) | 0);
  WRITE_LINE(0, 13974, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(12, 13974, 3);
  WRITE_LINE(0, 13597, Acc);
  Acc = ((LINE(0, 0, 1) / 2) | 0) + ((LINE(4, 13612, 1) / 2) | 0);
  WRITE_LINE(0, 13612, Acc);
  Acc = ((LINE(3, 13609, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(4, 13612, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 13609, Acc);
  Acc = LINE(3, 13609, 1);
  tmp_1 = -Acc;
  out_left = tmp_5;
  Acc = ((LINE(4, 13612, 1) * 3 / 2) | 0) + ((tmp_1 * 3 / 2) | 0);
  WRITE_LINE(0, 16381, Acc);
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 22: 2TAP MED FLAT AMBI */
function midifex_effect_22(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(0, 0, 15705) / 2) | 0) + LINE(0, 0, 7853) + ((LINE(4, 330, 41) / 2) | 0);
  WRITE_LINE(0, 330, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 330, 41) + ((LINE(3, 287, 195) / 2) | 0);
  WRITE_LINE(0, 287, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 287, 195) + ((LINE(2, 90, 63) / 2) | 0);
  WRITE_LINE(0, 90, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(2, 90, 63);
  tmp_5 = Acc;
  Acc = ((LINE(0, 0, 15705) / 2) | 0) + LINE(0, 0, 7853) + ((LINE(7, 677, 49) / 2) | 0);
  WRITE_LINE(0, 677, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 677, 49) + ((LINE(6, 626, 114) / 2) | 0);
  WRITE_LINE(0, 626, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 626, 114) + ((LINE(5, 510, 178) / 2) | 0);
  WRITE_LINE(0, 510, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 510, 178);
  WRITE_LINE(0, 3, Acc);
  out_left = tmp_5;
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 23: 2TAP MED HPF AMBI */
function midifex_effect_23(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(11, 16381, 6093) / 2) | 0) + ((LINE(10, 10286, 6093) / 2) | 0) + ((LINE(6, 3844, 41) / 2) | 0);
  WRITE_LINE(0, 3844, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 3844, 41) + ((LINE(5, 3801, 195) / 2) | 0);
  WRITE_LINE(0, 3801, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 3801, 195) + ((LINE(4, 3604, 63) / 2) | 0);
  WRITE_LINE(0, 3604, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 3604, 63);
  tmp_5 = Acc;
  Acc = ((tmp_5 * 21 / 32) | 0);
  tmp_5 = Acc;
  Acc = ((LINE(11, 16381, 6093) / 2) | 0) + ((LINE(10, 10286, 6093) / 2) | 0) + ((LINE(9, 4191, 49) / 2) | 0);
  WRITE_LINE(0, 4191, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 4191, 49) + ((LINE(8, 4140, 114) / 2) | 0);
  WRITE_LINE(0, 4140, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 4140, 114) + ((LINE(7, 4024, 178) / 2) | 0);
  WRITE_LINE(0, 4024, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 4024, 178);
  tmp_3 = Acc;
  Acc = ((tmp_3 * 21 / 32) | 0);
  tmp_3 = Acc;
  Acc = ((LINE(3, 3539, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(0, 0, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 3539, Acc);
  Acc = LINE(3, 3539, 1);
  tmp_1 = -Acc;
  Acc = ((LINE(0, 0, 1) * 3 / 2) | 0) + ((tmp_1 * 3 / 2) | 0);
  WRITE_LINE(0, 16381, Acc);
  Acc = ((LINE(2, 3536, 1) * 13 / 16) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(11, 16381, 6093) * 3 / 16) | 0) + tmp_1;
  WRITE_LINE(0, 3536, Acc);
  Acc = LINE(2, 3536, 1);
  tmp_1 = -Acc;
  Acc = ((LINE(11, 16381, 6093) * 3 / 2) | 0) + ((tmp_1 * 3 / 2) | 0);
  WRITE_LINE(0, 10286, Acc);
  Acc = ((LINE(1, 3533, 1) / 4) | 0);
  tmp_1 = Acc;
  out_left = tmp_5;
  Acc = ((LINE(1, 3533, 7) * 3 / 4) | 0) + tmp_1;
  WRITE_LINE(0, 3533, Acc);
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 24: 2TAP MED BPF AMBI */
function midifex_effect_24(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(12, 16381, 5390) / 2) | 0) + ((LINE(11, 10989, 5390) / 2) | 0) + ((LINE(7, 5250, 41) / 2) | 0);
  WRITE_LINE(0, 5250, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 5250, 41) + ((LINE(6, 5207, 195) / 2) | 0);
  WRITE_LINE(0, 5207, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 5207, 195) + ((LINE(5, 5010, 63) / 2) | 0);
  WRITE_LINE(0, 5010, -Acc);
  Acc = ((Acc * -3 / 4) | 0) + ((LINE(5, 5010, 63) * 3 / 2) | 0);
  tmp_5 = Acc;
  Acc = ((LINE(12, 16381, 5390) / 2) | 0) + ((LINE(11, 10989, 5390) / 2) | 0) + ((LINE(10, 5597, 49) / 2) | 0);
  WRITE_LINE(0, 5597, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 5597, 49) + ((LINE(9, 5546, 114) / 2) | 0);
  WRITE_LINE(0, 5546, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 5546, 114) + ((LINE(8, 5430, 178) / 2) | 0);
  WRITE_LINE(0, 5430, -Acc);
  Acc = ((Acc * -3 / 4) | 0) + ((LINE(8, 5430, 178) * 3 / 2) | 0);
  tmp_3 = Acc;
  Acc = ((LINE(4, 4945, 1) * 3 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(0, 0, 1) * 5 / 8) | 0) + tmp_1;
  WRITE_LINE(0, 4945, Acc);
  Acc = ((LINE(3, 4942, 1) * 15 / 16) | 0);
  tmp_1 = Acc;
  Acc = ((Acc * -3 / 16) | 0) + ((LINE(4, 4945, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 4942, Acc);
  Acc = LINE(3, 4942, 1);
  tmp_1 = -Acc;
  Acc = LINE(4, 4945, 1) + tmp_1;
  WRITE_LINE(0, 16381, Acc);
  Acc = ((LINE(12, 16381, 5390) / 2) | 0) + ((LINE(2, 4939, 1) / 2) | 0);
  WRITE_LINE(0, 4939, Acc);
  Acc = ((LINE(1, 4936, 1) * 15 / 16) | 0);
  tmp_1 = Acc;
  Acc = ((Acc * -3 / 16) | 0) + ((LINE(2, 4939, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 4936, Acc);
  Acc = LINE(1, 4936, 1);
  tmp_1 = -Acc;
  Acc = ((LINE(2, 4939, 1) * 3 / 2) | 0) + ((tmp_1 * 3 / 2) | 0);
  WRITE_LINE(0, 10989, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 25: 2TAP MED FLAT THICK */
function midifex_effect_25(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_d, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((-LINE(0, 0, 8919) / 4) | 0) + ((LINE(0, 0, 4210) / 2) | 0) + ((LINE(15, 7463, 87) / 2) | 0);
  WRITE_LINE(0, 7463, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(15, 7463, 87) + ((LINE(14, 7374, 103) / 2) | 0);
  WRITE_LINE(0, 7374, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(14, 7374, 103) + ((LINE(13, 7269, 127) / 2) | 0);
  WRITE_LINE(0, 7269, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(13, 7269, 127) + ((LINE(12, 7140, 143) / 2) | 0);
  WRITE_LINE(0, 7140, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(12, 7140, 143) + ((LINE(11, 6995, 174) / 2) | 0);
  WRITE_LINE(0, 6995, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 6995, 174) + ((LINE(10, 6819, 215) / 2) | 0);
  WRITE_LINE(0, 6819, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 6819, 215) + ((LINE(9, 6602, 251) / 2) | 0);
  WRITE_LINE(0, 6602, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 6602, 251) + ((LINE(8, 6349, 300) / 2) | 0);
  WRITE_LINE(0, 6349, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 6349, 300) + ((LINE(7, 6047, 369) / 2) | 0);
  WRITE_LINE(0, 6047, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 6047, 369);
  tmp_d = Acc;
  Acc = tmp_d + ((LINE(6, 5469, 175) / 2) | 0);
  WRITE_LINE(0, 5469, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 5469, 175) + ((LINE(4, 5133, 36) / 2) | 0);
  WRITE_LINE(0, 5133, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 5133, 36);
  WRITE_LINE(0, 6, -Acc);
  Acc = tmp_d + ((LINE(5, 5292, 157) / 2) | 0);
  WRITE_LINE(0, 5292, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 5292, 157) + ((LINE(3, 5095, 30) / 2) | 0);
  WRITE_LINE(0, 5095, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 5095, 30);
  WRITE_LINE(0, 4, -Acc);
  out_left = LINE(2, 6, 1);
  out_right = LINE(1, 4, 1);
  return [out_left, out_right];
}
/* Midifex effect 26: 2TAP SHORT FLAT WIDE */
function midifex_effect_26(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 4101) + ((LINE(0, 0, 8204) / 2) | 0);
  tmp_5 = Acc;
  Acc = LINE(0, 0, 3890) + ((LINE(0, 0, 8626) / 2) | 0);
  WRITE_LINE(0, 3, Acc);
  out_left = tmp_5;
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 27: 2TAP SHORT HPF PAN */
function midifex_effect_27(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(10, 16381, 3515) + ((LINE(5, 9000, 41) / 2) | 0);
  WRITE_LINE(0, 9000, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 9000, 41) + ((LINE(4, 8957, 195) / 2) | 0);
  WRITE_LINE(0, 8957, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 8957, 195) + ((LINE(3, 8760, 63) / 2) | 0);
  WRITE_LINE(0, 8760, -Acc);
  Acc = ((Acc * -3 / 4) | 0) + ((LINE(3, 8760, 63) * 3 / 2) | 0);
  tmp_5 = Acc;
  Acc = LINE(9, 12864, 3515) + ((LINE(8, 9347, 49) / 2) | 0);
  WRITE_LINE(0, 9347, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 9347, 49) + ((LINE(7, 9296, 114) / 2) | 0);
  WRITE_LINE(0, 9296, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 9296, 114) + ((LINE(6, 9180, 178) / 2) | 0);
  WRITE_LINE(0, 9180, -Acc);
  Acc = ((Acc * -3 / 4) | 0) + ((LINE(6, 9180, 178) * 3 / 2) | 0);
  tmp_3 = Acc;
  Acc = ((tmp_3 * 21 / 32) | 0);
  tmp_3 = Acc;
  Acc = ((LINE(2, 8695, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(0, 0, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 8695, Acc);
  Acc = LINE(2, 8695, 1);
  tmp_1 = -Acc;
  Acc = LINE(0, 0, 1) + tmp_1;
  WRITE_LINE(0, 16381, Acc);
  Acc = ((LINE(1, 8692, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(10, 16381, 3515) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 8692, Acc);
  Acc = LINE(1, 8692, 1);
  tmp_1 = -Acc;
  Acc = LINE(10, 16381, 3515) + tmp_1;
  WRITE_LINE(0, 12864, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 28: 2TAP SHORT BPF AMBI */
function midifex_effect_28(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(13, 16381, 3046) + ((LINE(12, 13333, 3046) / 2) | 0) + ((LINE(8, 9938, 13) / 2) | 0);
  WRITE_LINE(0, 9938, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 9938, 13) + ((LINE(7, 9923, 195) / 2) | 0);
  WRITE_LINE(0, 9923, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 9923, 195) + ((LINE(6, 9726, 63) / 2) | 0);
  WRITE_LINE(0, 9726, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 9726, 63);
  WRITE_LINE(0, 401, Acc);
  Acc = LINE(13, 16381, 3046) + ((LINE(12, 13333, 3046) / 2) | 0) + ((LINE(11, 10285, 49) / 2) | 0);
  WRITE_LINE(0, 10285, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 10285, 49) + ((LINE(10, 10234, 114) / 2) | 0);
  WRITE_LINE(0, 10234, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 10234, 114) + ((LINE(9, 10118, 178) / 2) | 0);
  WRITE_LINE(0, 10118, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 10118, 178);
  tmp_3 = Acc;
  Acc = ((LINE(5, 9661, 1) * 3 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(0, 0, 1) * 5 / 8) | 0) + tmp_1;
  WRITE_LINE(0, 9661, Acc);
  Acc = ((LINE(4, 9658, 1) * 15 / 16) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(5, 9661, 1) / 16) | 0) + tmp_1;
  WRITE_LINE(0, 9658, Acc);
  Acc = LINE(4, 9658, 1);
  tmp_1 = -Acc;
  Acc = LINE(5, 9661, 1) + tmp_1;
  WRITE_LINE(0, 16381, Acc);
  Acc = ((LINE(13, 16381, 3046) / 2) | 0) + ((LINE(3, 9655, 1) / 2) | 0);
  WRITE_LINE(0, 9655, Acc);
  Acc = ((LINE(2, 9652, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(3, 9655, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 9652, Acc);
  Acc = LINE(2, 9652, 1);
  tmp_1 = -Acc;
  Acc = ((LINE(3, 9655, 1) * 3 / 2) | 0) + ((tmp_1 * 3 / 2) | 0);
  WRITE_LINE(0, 13333, Acc);
  out_left = LINE(1, 401, 396);
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 29: 2TAP SHORT LPF AMBI */
function midifex_effect_29(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(12, 16381, 2695) + LINE(11, 13684, 2695) + ((LINE(7, 10640, 41) / 2) | 0);
  WRITE_LINE(0, 10640, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 10640, 41) + ((LINE(6, 10597, 195) / 2) | 0);
  WRITE_LINE(0, 10597, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 10597, 195) + ((LINE(5, 10400, 63) / 2) | 0);
  WRITE_LINE(0, 10400, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 10400, 63);
  WRITE_LINE(0, 6, Acc);
  Acc = LINE(12, 16381, 2695) + LINE(11, 13684, 2695) + ((LINE(10, 10987, 49) / 2) | 0);
  WRITE_LINE(0, 10987, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 10987, 49) + ((LINE(9, 10936, 114) / 2) | 0);
  WRITE_LINE(0, 10936, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 10936, 114) + ((LINE(8, 10820, 178) / 2) | 0);
  WRITE_LINE(0, 10820, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 10820, 178);
  WRITE_LINE(0, 4, Acc);
  Acc = ((LINE(4, 10335, 1) * 3 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(0, 0, 1) * 5 / 8) | 0) + tmp_1;
  WRITE_LINE(0, 10335, Acc);
  Acc = LINE(4, 10335, 1);
  WRITE_LINE(0, 16381, Acc);
  Acc = ((LINE(3, 10332, 1) / 2) | 0) + ((LINE(12, 16381, 2695) / 2) | 0);
  WRITE_LINE(0, 10332, Acc);
  Acc = LINE(3, 10332, 1);
  WRITE_LINE(0, 13684, Acc);
  out_left = LINE(2, 6, 1);
  out_right = LINE(1, 4, 1);
  return [out_left, out_right];
}
/* Midifex effect 30: 2TAP XSHORT FLAT WIDE */
function midifex_effect_30(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(0, 0, 2343) * 3 / 4) | 0) + ((LINE(0, 0, 4688) * 3 / 4) | 0);
  tmp_3 = Acc;
  Acc = ((LINE(0, 0, 2343) * 3 / 4) | 0) + ((LINE(0, 0, 4688) * 3 / 4) | 0);
  WRITE_LINE(0, 551, Acc);
  out_left = LINE(1, 551, 546);
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 31: 3TAP MED FLAT PAN */
function midifex_effect_31(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 5460) + ((LINE(0, 0, 16378) / 2) | 0);
  tmp_5 = Acc;
  Acc = ((tmp_5 * 21 / 32) | 0);
  tmp_5 = Acc;
  Acc = LINE(0, 0, 10919) + ((LINE(0, 0, 16378) / 2) | 0);
  tmp_3 = Acc;
  Acc = ((tmp_3 * 21 / 32) | 0);
  tmp_3 = Acc;
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 32: 3TAP SHORT FLAT PAN */
function midifex_effect_32(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 4247) + ((LINE(0, 0, 12739) / 2) | 0);
  tmp_5 = Acc;
  Acc = ((tmp_5 * 21 / 32) | 0);
  tmp_5 = Acc;
  Acc = LINE(0, 0, 8493) + ((LINE(0, 0, 12739) / 2) | 0);
  tmp_3 = Acc;
  Acc = ((tmp_3 * 21 / 32) | 0);
  tmp_3 = Acc;
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 33: 3TAP SHORT LPF AMBI */
function midifex_effect_33(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(12, 16381, 4244) / 2) | 0) + ((LINE(11, 12135, 4244) / 2) | 0) + ((LINE(10, 7889, 4244) / 2) | 0) + ((LINE(6, 3296, 41) / 2) | 0);
  WRITE_LINE(0, 3296, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 3296, 41) + ((LINE(5, 3253, 195) / 2) | 0);
  WRITE_LINE(0, 3253, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 3253, 195) + ((LINE(4, 3056, 63) / 2) | 0);
  WRITE_LINE(0, 3056, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 3056, 63);
  tmp_5 = Acc;
  Acc = ((LINE(10, 7889, 4244) / 2) | 0) + ((LINE(11, 12135, 4244) / 2) | 0) + ((LINE(12, 16381, 4244) / 2) | 0) + ((LINE(9, 3643, 49) / 2) | 0);
  WRITE_LINE(0, 3643, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 3643, 49) + ((LINE(8, 3592, 114) / 2) | 0);
  WRITE_LINE(0, 3592, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 3592, 114) + ((LINE(7, 3476, 178) / 2) | 0);
  WRITE_LINE(0, 3476, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 3476, 178);
  tmp_3 = Acc;
  Acc = ((LINE(1, 2985, 1) * 3 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(0, 0, 1) * 5 / 8) | 0) + tmp_1;
  WRITE_LINE(0, 2985, Acc);
  Acc = ((Acc * 3 / 2) | 0);
  WRITE_LINE(0, 7889, Acc);
  Acc = ((LINE(2, 2988, 1) / 2) | 0) + ((LINE(10, 7889, 4244) / 2) | 0);
  WRITE_LINE(0, 2988, Acc);
  Acc = LINE(2, 2988, 1);
  WRITE_LINE(0, 12135, Acc);
  Acc = ((LINE(3, 2991, 1) / 2) | 0) + ((LINE(11, 12135, 4244) / 2) | 0);
  WRITE_LINE(0, 2991, Acc);
  Acc = LINE(3, 2991, 0);
  WRITE_LINE(0, 16381, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 34: 3TAP SHORT BPF AMBI */
function midifex_effect_34(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(15, 16381, 3276) / 2) | 0) + ((LINE(14, 13103, 3276) / 2) | 0) + ((LINE(13, 9825, 3276) / 2) | 0) + ((LINE(9, 6200, 41) / 2) | 0);
  WRITE_LINE(0, 6200, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 6200, 41) + ((LINE(8, 6157, 195) / 2) | 0);
  WRITE_LINE(0, 6157, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 6157, 195) + ((LINE(7, 5960, 63) / 2) | 0);
  WRITE_LINE(0, 5960, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 5960, 63);
  tmp_5 = Acc;
  Acc = ((LINE(15, 16381, 3276) / 2) | 0) + ((LINE(14, 13103, 3276) / 2) | 0) + ((LINE(13, 9825, 3276) / 2) | 0) + ((LINE(12, 6547, 49) / 2) | 0);
  WRITE_LINE(0, 6547, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(12, 6547, 49) + ((LINE(11, 6496, 114) / 2) | 0);
  WRITE_LINE(0, 6496, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 6496, 114) + ((LINE(10, 6380, 178) / 2) | 0);
  WRITE_LINE(0, 6380, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 6380, 178);
  tmp_3 = Acc;
  Acc = ((LINE(6, 5895, 1) * 3 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(0, 0, 1) * 5 / 8) | 0) + tmp_1;
  WRITE_LINE(0, 5895, Acc);
  Acc = ((LINE(5, 5892, 1) * 15 / 16) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(6, 5895, 1) / 16) | 0) + tmp_1;
  WRITE_LINE(0, 5892, Acc);
  Acc = LINE(5, 5892, 1);
  tmp_1 = -Acc;
  Acc = LINE(6, 5895, 1) + tmp_1;
  WRITE_LINE(0, 16381, Acc);
  Acc = ((LINE(4, 5889, 1) / 2) | 0) + ((LINE(15, 16381, 3276) / 2) | 0);
  WRITE_LINE(0, 5889, Acc);
  Acc = ((LINE(3, 5886, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(4, 5889, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 5886, Acc);
  Acc = LINE(3, 5886, 1);
  tmp_1 = -Acc;
  Acc = ((LINE(4, 5889, 1) * 9 / 4) | 0) + ((tmp_1 * 9 / 4) | 0);
  WRITE_LINE(0, 13103, Acc);
  Acc = ((LINE(2, 5883, 1) / 2) | 0) + ((LINE(14, 13103, 3276) / 2) | 0);
  WRITE_LINE(0, 5883, Acc);
  out_left = tmp_5;
  Acc = ((LINE(1, 5880, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(2, 5883, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 5880, Acc);
  Acc = LINE(1, 5880, 1);
  tmp_1 = -Acc;
  out_right = tmp_3;
  Acc = ((LINE(2, 5883, 1) * 9 / 4) | 0) + ((tmp_1 * 9 / 4) | 0);
  WRITE_LINE(0, 9825, Acc);
  return [out_left, out_right];
}
/* Midifex effect 35: 3TAP SHORT HPF AMBI */
function midifex_effect_35(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(10, 10761, 2808) / 2) | 0) + ((LINE(11, 13571, 2808) / 2) | 0) + ((LINE(12, 16381, 2808) / 2) | 0) + ((LINE(6, 7604, 41) / 2) | 0);
  WRITE_LINE(0, 7604, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 7604, 41) + ((LINE(5, 7561, 195) / 2) | 0);
  WRITE_LINE(0, 7561, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 7561, 195) + ((LINE(4, 7364, 63) / 2) | 0);
  WRITE_LINE(0, 7364, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 7364, 63);
  tmp_5 = Acc;
  Acc = ((tmp_5 * 21 / 32) | 0);
  tmp_5 = Acc;
  Acc = ((LINE(12, 16381, 2808) / 2) | 0) + ((LINE(11, 13571, 2808) / 2) | 0) + ((LINE(10, 10761, 2808) / 2) | 0) + ((LINE(9, 7951, 49) / 2) | 0);
  WRITE_LINE(0, 7951, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 7951, 49) + ((LINE(8, 7900, 114) / 2) | 0);
  WRITE_LINE(0, 7900, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 7900, 114) + ((LINE(7, 7784, 178) / 2) | 0);
  WRITE_LINE(0, 7784, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 7784, 178);
  tmp_3 = Acc;
  Acc = ((tmp_3 * 21 / 32) | 0);
  tmp_3 = Acc;
  Acc = ((LINE(3, 7299, 1) * 15 / 16) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(0, 0, 1) / 16) | 0) + tmp_1;
  WRITE_LINE(0, 7299, Acc);
  Acc = LINE(3, 7299, 1);
  tmp_1 = -Acc;
  Acc = ((LINE(0, 0, 1) * 3 / 2) | 0) + ((tmp_1 * 3 / 2) | 0);
  WRITE_LINE(0, 16381, Acc);
  Acc = ((LINE(2, 7296, 1) * 15 / 16) | 0);
  tmp_1 = Acc;
  Acc = ((Acc * -3 / 16) | 0) + ((LINE(12, 16381, 2808) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 7296, Acc);
  Acc = LINE(2, 7296, 1);
  tmp_1 = -Acc;
  Acc = LINE(12, 16381, 2808) + tmp_1;
  WRITE_LINE(0, 13571, Acc);
  out_left = tmp_5;
  Acc = ((LINE(1, 7293, 1) * 13 / 16) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(11, 13571, 2808) * 3 / 16) | 0) + tmp_1;
  WRITE_LINE(0, 7293, Acc);
  Acc = LINE(1, 7293, 1);
  tmp_1 = -Acc;
  out_right = tmp_3;
  Acc = ((LINE(11, 13571, 2808) * 3 / 2) | 0) + ((tmp_1 * 3 / 2) | 0);
  WRITE_LINE(0, 10761, Acc);
  return [out_left, out_right];
}
/* Midifex effect 36: 3TAP XSHORT FLAT AMBI */
function midifex_effect_36(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(0, 0, 7027) / 2) | 0) + ((LINE(0, 0, 4685) / 2) | 0) + ((LINE(0, 0, 2343) / 2) | 0) + ((LINE(3, 9008, 41) / 2) | 0);
  WRITE_LINE(0, 9008, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 9008, 41) + ((LINE(2, 8965, 195) / 2) | 0);
  WRITE_LINE(0, 8965, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(2, 8965, 195) + ((LINE(1, 8768, 63) / 2) | 0);
  WRITE_LINE(0, 8768, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(1, 8768, 63);
  tmp_5 = Acc;
  Acc = ((tmp_5 * 21 / 32) | 0);
  tmp_5 = Acc;
  Acc = ((LINE(0, 0, 2343) / 2) | 0) + ((LINE(0, 0, 4685) / 2) | 0) + ((LINE(0, 0, 7027) / 2) | 0) + ((LINE(6, 9355, 49) / 2) | 0);
  WRITE_LINE(0, 9355, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 9355, 49) + ((LINE(5, 9304, 114) / 2) | 0);
  WRITE_LINE(0, 9304, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 9304, 114) + ((LINE(4, 9188, 178) / 2) | 0);
  WRITE_LINE(0, 9188, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 9188, 178);
  tmp_3 = Acc;
  Acc = ((tmp_3 * 21 / 32) | 0);
  tmp_3 = Acc;
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 37: REGEN MED FLAT */
function midifex_effect_37(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(2, 16380, 14000);
  WRITE_LINE(0, 3, Acc);
  Acc = LINE(2, 16380, 14000);
  tmp_5 = Acc;
  Acc = LINE(0, 0, 2) + ((LINE(2, 16380, 14000) / 2) | 0);
  WRITE_LINE(0, 16380, Acc);
  out_left = tmp_5;
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 38: REGEN MED HPF AMBI */
function midifex_effect_38(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, tmp_3ffe, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(8, 16380, 8171) / 2) | 0) + ((LINE(6, 8201, 49) / 2) | 0);
  WRITE_LINE(0, 8201, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 8201, 49) + ((LINE(5, 8150, 114) / 2) | 0);
  WRITE_LINE(0, 8150, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 8150, 114) + ((LINE(4, 8034, 178) / 2) | 0);
  WRITE_LINE(0, 8034, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 8034, 178);
  tmp_3 = Acc;
  Acc = ((LINE(8, 16380, 8171) / 2) | 0) + ((LINE(3, 7854, 41) / 2) | 0);
  WRITE_LINE(0, 7854, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 7854, 41) + ((LINE(2, 7811, 195) / 2) | 0);
  WRITE_LINE(0, 7811, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(2, 7811, 195) + ((LINE(1, 7614, 63) / 2) | 0);
  WRITE_LINE(0, 7614, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(1, 7614, 63);
  tmp_5 = Acc;
  Acc = ((LINE(8, 16380, 8171) / 2) | 0) + ((LINE(0, 0, 2) * 3 / 2) | 0);
  tmp_3ffe = Acc;
  Acc = ((tmp_3ffe / 2) | 0);
  WRITE_LINE(0, 8207, Acc);
  Acc = LINE(7, 8207, 1);
  tmp_1 = -Acc;
  Acc = tmp_3ffe + tmp_1;
  WRITE_LINE(0, 16380, Acc);
  Acc = ((LINE(8, 16380, 0) * 3 / 4) | 0);
  WRITE_LINE(0, 16380, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 39: REGEN MED BPF AMBI */
function midifex_effect_39(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_3, tmp_5, tmp_3ffe, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(11, 16380, 7020) / 2) | 0) + ((LINE(8, 9352, 49) / 2) | 0);
  WRITE_LINE(0, 9352, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 9352, 49) + ((LINE(7, 9301, 114) / 2) | 0);
  WRITE_LINE(0, 9301, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 9301, 114) + ((LINE(6, 9185, 178) / 2) | 0);
  WRITE_LINE(0, 9185, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 9185, 178);
  tmp_3 = Acc;
  Acc = ((LINE(11, 16380, 7020) / 2) | 0) + ((LINE(5, 9005, 41) / 2) | 0);
  WRITE_LINE(0, 9005, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 9005, 41) + ((LINE(4, 8962, 195) / 2) | 0);
  WRITE_LINE(0, 8962, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 8962, 195) + ((LINE(3, 8765, 63) / 2) | 0);
  WRITE_LINE(0, 8765, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 8765, 63);
  tmp_5 = Acc;
  Acc = ((-LINE(0, 0, 2)) | 0) + ((-LINE(11, 16380, 7020) / 4) | 0);
  tmp_3ffe = Acc;
  Acc = ((tmp_3ffe / 2) | 0) + ((LINE(10, 9358, 1) / 2) | 0);
  WRITE_LINE(0, 9358, Acc);
  Acc = ((LINE(9, 9355, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(10, 9358, 1) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 9355, Acc);
  Acc = LINE(9, 9355, 1);
  tmp_1 = -Acc;
  Acc = ((LINE(10, 9358, 1) * 3 / 2) | 0) + ((tmp_1 * 3 / 2) | 0);
  WRITE_LINE(0, 16380, Acc);
  Acc = ((LINE(1, 8688, 6) / 2) | 0) + ((LINE(2, 8691, 1) / 2) | 0);
  WRITE_LINE(0, 8691, Acc);
  Acc = ((LINE(1, 8688, 1) * 7 / 8) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(1, 8688, 7) / 8) | 0) + tmp_1;
  WRITE_LINE(0, 8688, Acc);
  Acc = ((LINE(11, 16380, 0) * 11 / 8) | 0);
  WRITE_LINE(0, 16380, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 40: REGEN MED LPF AMBI */
function midifex_effect_40(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(8, 16382, 5002) / 2) | 0) + ((LINE(6, 11375, 59) / 2) | 0);
  WRITE_LINE(0, 11375, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 11375, 59) + ((LINE(5, 11314, 117) / 2) | 0);
  WRITE_LINE(0, 11314, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 11314, 117) + ((LINE(4, 11195, 139) / 2) | 0);
  WRITE_LINE(0, 11195, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 11195, 139);
  tmp_3 = Acc;
  Acc = ((LINE(8, 16382, 5002) / 2) | 0) + ((LINE(3, 11054, 45) / 2) | 0);
  WRITE_LINE(0, 11054, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 11054, 45) + ((LINE(2, 11007, 187) / 2) | 0);
  WRITE_LINE(0, 11007, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(2, 11007, 187) + ((LINE(1, 10818, 121) / 2) | 0);
  WRITE_LINE(0, 10818, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(1, 10818, 121);
  tmp_5 = Acc;
  Acc = ((LINE(0, 0, 2) * 9 / 8) | 0) + ((LINE(7, 11378, 1) * 3 / 4) | 0);
  WRITE_LINE(0, 16382, Acc);
  Acc = ((LINE(7, 11378, 1) / 2) | 0) + ((LINE(8, 16382, 5002) / 2) | 0);
  WRITE_LINE(0, 11378, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 41: REGEN SHORT FLAT */
function midifex_effect_41(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(1, 16380, 4500) / 2) | 0);
  tmp_3 = Acc;
  Acc = ((LINE(1, 16380, 4500) / 2) | 0);
  tmp_5 = Acc;
  Acc = ((-LINE(1, 16380, 4500) / 4) | 0) + LINE(0, 0, 2);
  WRITE_LINE(0, 16380, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 42: REGEN XSHORT FLAT */
function midifex_effect_42(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(2, 16380, 3000);
  WRITE_LINE(0, 3, Acc);
  Acc = LINE(2, 16380, 3000);
  tmp_5 = Acc;
  Acc = LINE(0, 0, 2) + ((LINE(2, 16380, 3000) / 2) | 0);
  WRITE_LINE(0, 16380, Acc);
  out_left = tmp_5;
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 43: SLAP1 */
function midifex_effect_43(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 588);
  WRITE_LINE(0, 3, Acc);
  Acc = LINE(0, 0, 588);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 44: SLAP2 */
function midifex_effect_44(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 940);
  WRITE_LINE(0, 3, Acc);
  Acc = LINE(0, 0, 940);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 45: SLAP3 */
function midifex_effect_45(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 1409);
  WRITE_LINE(0, 3, Acc);
  Acc = LINE(0, 0, 1409);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 46: SLAP4 */
function midifex_effect_46(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 1760);
  WRITE_LINE(0, 3, Acc);
  Acc = LINE(0, 0, 1760);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 47: SLAP5 */
function midifex_effect_47(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 2346);
  WRITE_LINE(0, 3, Acc);
  Acc = LINE(0, 0, 2346);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 48: REVERB SHORT GATE */
function midifex_effect_48(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(1, 11, 2) / 2) | 0) + ((LINE(9, 2298, 21) / 2) | 0);
  WRITE_LINE(0, 2298, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 2298, 21) + ((LINE(8, 2275, 153) / 2) | 0);
  WRITE_LINE(0, 2275, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 2275, 153) + ((LINE(7, 2120, 273) / 2) | 0);
  WRITE_LINE(0, 2120, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 2120, 273);
  tmp_3 = Acc;
  Acc = ((LINE(1, 11, 2) / 2) | 0) + ((LINE(6, 1845, 32) / 2) | 0);
  WRITE_LINE(0, 1845, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 1845, 32) + ((LINE(5, 1811, 181) / 2) | 0);
  WRITE_LINE(0, 1811, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 1811, 181) + ((LINE(4, 1628, 233) / 2) | 0);
  WRITE_LINE(0, 1628, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 1628, 233);
  tmp_5 = Acc;
  Acc = ((LINE(0, 0, 163) / 2) | 0) + ((LINE(0, 0, 233) / 2) | 0) + ((LINE(0, 0, 412) / 2) | 0) + ((LINE(0, 0, 534) / 2) | 0) + ((LINE(0, 0, 761) / 2) | 0) + ((LINE(0, 0, 875) / 2) | 0) + ((LINE(10, 15383, 64) / 2) | 0) + ((LINE(10, 15383, 118) / 2) | 0) + ((LINE(10, 15383, 232) / 2) | 0) + ((LINE(10, 15383, 433) / 2) | 0) + ((LINE(10, 15383, 554) / 2) | 0) + ((LINE(10, 15383, 741) / 2) | 0) + ((LINE(10, 15383, 861) / 2) | 0) + ((LINE(10, 15383, 1045) / 2) | 0) + ((LINE(10, 15383, 1148) / 2) | 0) + ((LINE(10, 15383, 1255) / 2) | 0) + ((LINE(10, 15383, 1442) / 2) | 0) + ((LINE(10, 15383, 1578) / 2) | 0) + ((LINE(10, 15383, 1720) / 2) | 0) + ((LINE(10, 15383, 1872) / 2) | 0) + ((LINE(10, 15383, 2035) / 2) | 0) + ((LINE(10, 15383, 2120) / 2) | 0) + ((LINE(10, 15383, 2266) / 2) | 0) + ((LINE(10, 15383, 2450) / 2) | 0) + ((LINE(10, 15383, 2568) / 2) | 0) + ((LINE(10, 15383, 2724) / 2) | 0) + ((LINE(10, 15383, 2888) / 2) | 0) + ((LINE(10, 15383, 3033) / 2) | 0) + ((LINE(10, 15383, 3151) / 2) | 0) + ((LINE(10, 15383, 3256) / 2) | 0) + ((LINE(10, 15383, 3491) / 2) | 0) + ((LINE(10, 15383, 3555) / 2) | 0);
  WRITE_LINE(0, 11, Acc);
  out_left = tmp_5;
  Acc = ((-LINE(10, 15383, 8094) / 16) | 0) + ((-LINE(10, 15383, 7848) / 16) | 0) + ((-LINE(10, 15383, 7792) / 16) | 0) + ((-LINE(10, 15383, 7514) / 16) | 0) + ((-LINE(10, 15383, 7461) / 16) | 0) + ((-LINE(10, 15383, 7378) / 16) | 0) + ((-LINE(10, 15383, 7138) / 16) | 0) + ((-LINE(10, 15383, 7091) / 16) | 0) + ((LINE(10, 15383, 6864) / 8) | 0) + ((LINE(10, 15383, 6726) / 8) | 0) + ((LINE(10, 15383, 6656) / 8) | 0) + ((LINE(10, 15383, 6418) / 8) | 0) + ((LINE(10, 15383, 6363) / 8) | 0) + ((LINE(10, 15383, 6153) / 8) | 0) + ((LINE(10, 15383, 6017) / 8) | 0) + ((LINE(10, 15383, 5966) / 8) | 0) + ((-LINE(10, 15383, 5727) / 4) | 0) + ((-LINE(10, 15383, 5656) / 4) | 0) + ((-LINE(10, 15383, 5494) / 4) | 0) + ((-LINE(10, 15383, 5318) / 4) | 0) + ((-LINE(10, 15383, 5260) / 4) | 0) + ((-LINE(10, 15383, 5018) / 4) | 0) + ((-LINE(10, 15383, 4957) / 4) | 0) + ((-LINE(10, 15383, 4733) / 4) | 0) + ((LINE(10, 15383, 4626) / 2) | 0) + ((LINE(10, 15383, 4550) / 2) | 0) + ((LINE(10, 15383, 4338) / 2) | 0) + ((LINE(10, 15383, 4209) / 2) | 0) + ((LINE(10, 15383, 4045) / 2) | 0) + ((LINE(10, 15383, 3920) / 2) | 0) + ((LINE(10, 15383, 3799) / 2) | 0) + ((LINE(10, 15383, 3618) / 2) | 0) + ((LINE(3, 1393, 1) / 2) | 0);
  WRITE_LINE(0, 1393, Acc);
  Acc = ((-LINE(3, 1393, 1) / 4) | 0) + LINE(1, 11, 0);
  WRITE_LINE(0, 11, Acc);
  Acc = ((LINE(0, 0, 1000) / 2) | 0) + ((LINE(2, 1390, 1) / 2) | 0);
  WRITE_LINE(0, 1390, Acc);
  Acc = LINE(2, 1390, 1);
  WRITE_LINE(0, 15383, Acc);
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 49: REVERB MEDIUM WARM */
function midifex_effect_49(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_b, tmp_1, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(10, 15253, 64) / 2) | 0) + ((LINE(8, 13283, 696) / 2) | 0) + ((LINE(4, 8586, 539) / 2) | 0) + ((LINE(13, 16230, 24) / 2) | 0);
  tmp_5 = Acc;
  Acc = ((LINE(10, 15253, 503) / 2) | 0) + ((LINE(8, 13283, 167) / 2) | 0) + ((LINE(4, 8586, 151) / 2) | 0) + ((LINE(12, 16045, 172) / 2) | 0);
  tmp_3 = Acc;
  Acc = ((LINE(15, 16381, 58) * 5 / 8) | 0) + ((LINE(0, 0, 1) * 3 / 2) | 0);
  WRITE_LINE(0, 16381, -Acc);
  Acc = ((LINE(14, 16321, 89) * 5 / 8) | 0) + ((LINE(15, 16381, 0) * 5 / 8) | 0) + LINE(15, 16381, 58);
  WRITE_LINE(0, 16321, -Acc);
  Acc = ((LINE(13, 16230, 183) * 5 / 8) | 0) + ((LINE(14, 16321, 0) * 5 / 8) | 0) + LINE(14, 16321, 89);
  WRITE_LINE(0, 16230, -Acc);
  Acc = ((LINE(12, 16045, 321) * 5 / 8) | 0) + ((LINE(13, 16230, 0) * 5 / 8) | 0) + LINE(13, 16230, 183);
  WRITE_LINE(0, 16045, -Acc);
  Acc = ((LINE(11, 15722, 467) * 5 / 8) | 0) + ((LINE(12, 16045, 0) * 5 / 8) | 0) + LINE(12, 16045, 321);
  WRITE_LINE(0, 15722, -Acc);
  Acc = ((-Acc / 8) | 0) + ((LINE(11, 15722, 0) / 2) | 0) + LINE(11, 15722, 467);
  tmp_b = Acc;
  Acc = ((LINE(10, 15253, 845) * 3 / 4) | 0) + ((LINE(9, 14406, 1121) / 2) | 0);
  WRITE_LINE(0, 14406, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 14406, 1121);
  WRITE_LINE(0, 13283, Acc);
  Acc = ((LINE(8, 13283, 1441) * 3 / 4) | 0) + ((LINE(7, 11840, 1320) / 2) | 0);
  WRITE_LINE(0, 11840, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 11840, 1320);
  tmp_1 = Acc;
  Acc = ((LINE(2, 6264, 1) / 2) | 0) + ((tmp_1 / 2) | 0);
  WRITE_LINE(0, 6264, Acc);
  Acc = LINE(2, 6264, 1) + tmp_b;
  WRITE_LINE(0, 15253, Acc);
  Acc = ((LINE(6, 10518, 912) * 3 / 4) | 0) + ((LINE(5, 9604, 1016) / 2) | 0);
  WRITE_LINE(0, 9604, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 9604, 1016);
  WRITE_LINE(0, 8586, Acc);
  Acc = ((LINE(4, 8586, 1017) * 3 / 4) | 0) + ((LINE(3, 7567, 1298) / 2) | 0);
  WRITE_LINE(0, 7567, -Acc);
  out_left = tmp_5;
  Acc = ((-Acc / 2) | 0) + LINE(3, 7567, 1298);
  tmp_1 = Acc;
  Acc = ((LINE(1, 6261, 1) / 2) | 0) + ((tmp_1 / 2) | 0);
  WRITE_LINE(0, 6261, Acc);
  Acc = LINE(1, 6261, 1) + tmp_b;
  WRITE_LINE(0, 10518, Acc);
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 50: REVERB MEDIUM BLOOM */
function midifex_effect_50(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(4, 2190, 1) / 2) | 0);
  tmp_3 = Acc;
  Acc = ((LINE(3, 2187, 1) / 2) | 0);
  tmp_5 = Acc;
  Acc = ((LINE(5, 2193, 1) / 2) | 0) + ((LINE(0, 0, 1) / 2) | 0);
  WRITE_LINE(0, 2193, Acc);
  Acc = ((-LINE(1, 11, 1) / 4) | 0) + ((LINE(2, 2184, 1) / 2) | 0);
  WRITE_LINE(0, 2184, Acc);
  Acc = ((Acc * 3 / 2) | 0) + LINE(5, 2193, 1) + ((LINE(26, 16381, 13) / 2) | 0);
  WRITE_LINE(0, 16381, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(26, 16381, 13) + ((LINE(25, 16366, 83) / 2) | 0);
  WRITE_LINE(0, 16366, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(25, 16366, 83) + ((LINE(24, 16281, 116) / 2) | 0);
  WRITE_LINE(0, 16281, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(24, 16281, 116) + ((LINE(23, 16163, 239) / 2) | 0);
  WRITE_LINE(0, 16163, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(23, 16163, 239) + ((LINE(22, 15922, 339) / 2) | 0);
  WRITE_LINE(0, 15922, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(22, 15922, 339) + ((LINE(21, 15581, 481) / 2) | 0);
  WRITE_LINE(0, 15581, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(21, 15581, 481) + ((LINE(20, 15098, 555) / 2) | 0);
  WRITE_LINE(0, 15098, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(20, 15098, 555) + ((LINE(19, 14541, 823) / 2) | 0);
  WRITE_LINE(0, 14541, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(19, 14541, 823) + ((LINE(18, 13716, 999) / 2) | 0);
  WRITE_LINE(0, 13716, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(18, 13716, 999) + ((LINE(17, 12715, 1100) / 2) | 0);
  WRITE_LINE(0, 12715, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(17, 12715, 1100) + ((LINE(16, 11613, 1347) / 2) | 0);
  WRITE_LINE(0, 11613, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(16, 11613, 1347) + ((LINE(15, 10264, 1563) / 2) | 0);
  WRITE_LINE(0, 10264, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(15, 10264, 1563) + ((LINE(14, 8699, 1841) / 2) | 0);
  WRITE_LINE(0, 8699, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(14, 8699, 1841) + ((LINE(13, 6856, 2001) / 2) | 0);
  WRITE_LINE(0, 6856, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(13, 6856, 2001) + ((LINE(12, 4853, 2083) / 2) | 0);
  WRITE_LINE(0, 4853, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(12, 4853, 2083);
  WRITE_LINE(0, 11, Acc);
  Acc = LINE(1, 11, 0) + ((LINE(9, 2666, 147) / 2) | 0);
  WRITE_LINE(0, 2666, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 2666, 147) + ((LINE(11, 2768, 43) / 2) | 0);
  WRITE_LINE(0, 2768, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 2768, 43) + ((LINE(10, 2723, 55) / 2) | 0);
  WRITE_LINE(0, 2723, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 2723, 55);
  WRITE_LINE(0, 2190, Acc);
  Acc = LINE(1, 11, 0) + ((LINE(6, 2444, 249) / 2) | 0);
  WRITE_LINE(0, 2444, -Acc);
  out_left = tmp_5;
  Acc = ((-Acc / 2) | 0) + LINE(6, 2444, 249) + ((LINE(7, 2494, 48) / 2) | 0);
  WRITE_LINE(0, 2494, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 2494, 48) + ((LINE(8, 2517, 21) / 2) | 0);
  WRITE_LINE(0, 2517, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 2517, 21);
  WRITE_LINE(0, 2187, Acc);
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 51: REVERB MEDIUM PAN */
function midifex_effect_51(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_2, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(9, 12641, 1065) * 3 / 64) | 0) + ((LINE(9, 12641, 1233) * 3 / 64) | 0) + ((LINE(9, 12641, 1555) * 3 / 64) | 0) + ((LINE(7, 9021, 269) * 3 / 64) | 0) + ((LINE(5, 4536, 2003) * -3 / 32) | 0) + ((LINE(7, 9021, 1891) * -3 / 32) | 0) + ((LINE(9, 12641, 21) * -3 / 32) | 0) + ((LINE(7, 9021, 532) * -3 / 32) | 0) + ((LINE(7, 9021, 872) * -3 / 32) | 0) + ((LINE(7, 9021, 1107) * -3 / 32) | 0) + ((LINE(7, 9021, 1414) * -3 / 32) | 0) + ((LINE(7, 9021, 1615) * -3 / 32) | 0) + ((LINE(7, 9021, 1914) * -3 / 32) | 0) + ((LINE(5, 4536, 173) * -3 / 32) | 0) + ((LINE(5, 4536, 460) * -3 / 32) | 0) + ((LINE(5, 4536, 780) * 3 / 16) | 0) + ((LINE(5, 4536, 1066) * 3 / 16) | 0) + ((LINE(5, 4536, 1344) * 3 / 16) | 0) + ((LINE(5, 4536, 1660) * 3 / 16) | 0) + ((LINE(5, 4536, 1941) * 3 / 16) | 0);
  WRITE_LINE(0, 4, -Acc);
  Acc = ((-LINE(5, 4536, 2005) / 16) | 0) + ((-LINE(5, 4536, 1762) / 16) | 0) + ((-LINE(5, 4536, 1408) / 16) | 0) + ((-LINE(5, 4536, 1110) / 16) | 0) + ((LINE(5, 4536, 671) / 8) | 0) + ((LINE(7, 9021, 890) / 8) | 0) + ((LINE(9, 12641, 1010) / 8) | 0) + ((LINE(5, 4536, 907) / 8) | 0) + ((LINE(5, 4536, 595) / 8) | 0) + ((LINE(5, 4536, 342) / 8) | 0) + ((LINE(5, 4536, 41) / 8) | 0) + ((LINE(7, 9021, 1801) / 8) | 0) + ((LINE(7, 9021, 1509) / 8) | 0) + ((LINE(7, 9021, 1229) / 8) | 0) + ((LINE(7, 9021, 936) / 8) | 0) + ((-LINE(7, 9021, 637) / 4) | 0) + ((-LINE(7, 9021, 414) / 4) | 0) + ((-LINE(7, 9021, 105) / 4) | 0) + ((-LINE(9, 12641, 1434) / 4) | 0) + ((-LINE(9, 12641, 1119) / 4) | 0);
  WRITE_LINE(0, 6, -Acc);
  Acc = ((LINE(0, 0, 1) * 81 / 32) | 0) + ((LINE(15, 16381, 321) / 2) | 0);
  WRITE_LINE(0, 16381, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(15, 16381, 321) + ((LINE(14, 16058, 431) / 2) | 0);
  WRITE_LINE(0, 16058, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(14, 16058, 431) + ((LINE(13, 15625, 968) / 2) | 0);
  WRITE_LINE(0, 15625, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(13, 15625, 968) + ((LINE(12, 14655, 1620) / 2) | 0);
  WRITE_LINE(0, 14655, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(12, 14655, 1620) + ((LINE(11, 13033, 234) / 2) | 0);
  WRITE_LINE(0, 13033, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 13033, 234) + ((LINE(10, 12797, 154) / 2) | 0);
  WRITE_LINE(0, 12797, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 12797, 154);
  tmp_2 = Acc;
  Acc = LINE(9, 12641, 1624) + ((LINE(8, 11015, 1992) / 2) | 0);
  WRITE_LINE(0, 11015, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 11015, 1992);
  WRITE_LINE(0, 9021, Acc);
  Acc = ((LINE(7, 9021, 2110) * 15 / 16) | 0) + ((LINE(6, 6909, 2371) / 2) | 0);
  WRITE_LINE(0, 6909, -Acc);
  out_left = LINE(2, 6, 1);
  Acc = ((-Acc / 2) | 0) + LINE(6, 6909, 2371);
  WRITE_LINE(0, 4536, Acc);
  Acc = ((LINE(5, 4536, 2157) / 2) | 0) + ((LINE(4, 2377, 2312) / 2) | 0);
  WRITE_LINE(0, 2377, -Acc);
  Acc = ((Acc * -3 / 4) | 0) + ((LINE(4, 2377, 2312) * 3 / 2) | 0);
  tmp_1 = Acc;
  Acc = ((LINE(3, 63, 1) / 4) | 0) + ((tmp_1 / 2) | 0);
  WRITE_LINE(0, 63, Acc);
  out_right = LINE(1, 4, 1);
  Acc = LINE(3, 63, 0) + tmp_2;
  WRITE_LINE(0, 12641, Acc);
  return [out_left, out_right];
}
/* Midifex effect 52: REVERB LONG HPF */
function midifex_effect_52(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_1, tmp_2, tmp_3, tmp_5, tmp_7, tmp_9, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(8, 12641, 21) / 2) | 0) + ((LINE(6, 9121, 1891) / 2) | 0) + ((LINE(4, 4636, 2003) / 2) | 0);
  tmp_3 = Acc;
  Acc = ((LINE(8, 12641, 801) / 2) | 0) + ((LINE(6, 9121, 890) / 2) | 0) + ((LINE(4, 4636, 671) / 2) | 0);
  tmp_5 = Acc;
  Acc = LINE(0, 0, 1) + ((LINE(14, 16381, 321) / 2) | 0);
  WRITE_LINE(0, 16381, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(14, 16381, 321) + ((LINE(13, 16058, 431) / 2) | 0);
  WRITE_LINE(0, 16058, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(13, 16058, 431) + ((LINE(12, 15625, 968) / 2) | 0);
  WRITE_LINE(0, 15625, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(12, 15625, 968) + ((LINE(11, 14655, 1620) / 2) | 0);
  WRITE_LINE(0, 14655, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 14655, 1620) + ((LINE(10, 13033, 234) / 2) | 0);
  WRITE_LINE(0, 13033, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 13033, 234) + ((LINE(9, 12797, 154) / 2) | 0);
  WRITE_LINE(0, 12797, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 12797, 154);
  tmp_2 = Acc;
  Acc = LINE(8, 12641, 1624) + ((LINE(7, 11015, 1892) / 2) | 0);
  WRITE_LINE(0, 11015, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 11015, 1892);
  WRITE_LINE(0, 9121, Acc);
  Acc = ((LINE(6, 9121, 2110) * -27 / 32) | 0) + ((LINE(5, 7009, 2371) / 2) | 0);
  WRITE_LINE(0, 7009, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 7009, 2371);
  WRITE_LINE(0, 4636, Acc);
  Acc = ((LINE(4, 4636, 2157) * 9 / 8) | 0) + ((LINE(3, 2477, 2312) / 2) | 0);
  WRITE_LINE(0, 2477, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 2477, 2312);
  tmp_1 = Acc;
  Acc = ((LINE(1, 157, 1) / 2) | 0) + ((tmp_1 / 2) | 0);
  WRITE_LINE(0, 157, Acc);
  Acc = LINE(1, 157, 0) + tmp_2;
  tmp_7 = Acc;
  Acc = ((LINE(2, 163, 1) * 15 / 16) | 0);
  tmp_9 = Acc;
  Acc = ((tmp_7 / 16) | 0) + tmp_9;
  WRITE_LINE(0, 163, Acc);
  Acc = LINE(2, 163, 0);
  tmp_9 = -Acc;
  Acc = tmp_7 + tmp_9;
  WRITE_LINE(0, 12641, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 53: REVERB REVERSE */
function midifex_effect_53(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(1, 11, 2) / 2) | 0) + ((LINE(7, 2298, 21) / 2) | 0);
  WRITE_LINE(0, 2298, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 2298, 21) + ((LINE(6, 2275, 153) / 2) | 0);
  WRITE_LINE(0, 2275, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 2275, 153) + ((LINE(5, 2120, 273) / 2) | 0);
  WRITE_LINE(0, 2120, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 2120, 273) + LINE(0, 0, 14000);
  tmp_3 = Acc;
  Acc = ((LINE(1, 11, 2) / 2) | 0) + ((LINE(4, 1845, 32) / 2) | 0);
  WRITE_LINE(0, 1845, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 1845, 32) + ((LINE(3, 1811, 175) / 2) | 0);
  WRITE_LINE(0, 1811, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 1811, 175) + ((LINE(2, 1634, 233) / 2) | 0);
  WRITE_LINE(0, 1634, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(2, 1634, 233) + LINE(0, 0, 14000);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = tmp_3;
  Acc = ((Acc * 3 / 32) | 0) + ((LINE(0, 0, 1065) / 32) | 0) + ((LINE(0, 0, 1119) / 32) | 0) + ((LINE(0, 0, 1233) / 32) | 0) + ((LINE(0, 0, 1434) / 32) | 0) + ((LINE(0, 0, 1555) / 32) | 0) + ((LINE(0, 0, 1742) / 32) | 0) + ((LINE(0, 0, 1862) / 32) | 0) + ((LINE(0, 0, 2046) / 32) | 0) + ((LINE(0, 0, 3569) / 32) | 0) + ((LINE(0, 0, 2256) / 32) | 0) + ((LINE(0, 0, 2443) / 32) | 0) + ((LINE(0, 0, 3121) / 32) | 0) + ((LINE(0, 0, 2721) / 32) | 0) + ((-LINE(0, 0, 2873) / 16) | 0) + ((-LINE(0, 0, 3036) / 16) | 0) + ((-LINE(0, 0, 2579) / 16) | 0) + ((-LINE(0, 0, 3267) / 16) | 0) + ((-LINE(0, 0, 3451) / 16) | 0) + ((-LINE(0, 0, 2149) / 16) | 0) + ((-LINE(0, 0, 3725) / 16) | 0) + ((-LINE(0, 0, 3889) / 16) | 0) + ((-LINE(0, 0, 4034) / 16) | 0) + ((-LINE(0, 0, 4152) / 16) | 0) + ((-LINE(0, 0, 4257) / 16) | 0) + ((-LINE(0, 0, 4492) / 16) | 0) + ((-LINE(0, 0, 4556) / 16) | 0) + ((-LINE(0, 0, 4727) / 16) | 0) + ((-LINE(0, 0, 4849) / 16) | 0) + ((-LINE(0, 0, 6035) / 16) | 0) + ((-LINE(0, 0, 5129) / 16) | 0) + ((-LINE(0, 0, 5235) / 16) | 0) + ((-LINE(0, 0, 6223) / 16) | 0) + ((-LINE(0, 0, 5534) / 16) | 0) + ((LINE(0, 0, 5759) / 8) | 0) + ((LINE(0, 0, 5837) / 8) | 0) + ((LINE(0, 0, 5034) / 8) | 0) + ((LINE(0, 0, 6159) / 8) | 0) + ((LINE(0, 0, 5421) / 8) | 0) + ((LINE(0, 0, 6446) / 8) | 0) + ((LINE(0, 0, 6534) / 8) | 0) + ((LINE(0, 0, 6782) / 8) | 0) + ((LINE(0, 0, 6859) / 8) | 0) + ((LINE(0, 0, 7039) / 8) | 0) + ((LINE(0, 0, 7126) / 8) | 0) + ((LINE(0, 0, 7221) / 8) | 0) + ((LINE(0, 0, 8565) / 8) | 0) + ((LINE(0, 0, 7534) / 8) | 0) + ((LINE(0, 0, 7736) / 8) | 0) + ((LINE(0, 0, 7891) / 8) | 0) + ((LINE(0, 0, 9215) / 8) | 0) + ((LINE(0, 0, 8146) / 8) | 0) + ((LINE(0, 0, 8278) / 8) | 0) + ((-LINE(0, 0, 8447) / 4) | 0) + ((-LINE(0, 0, 7439) / 4) | 0) + ((-LINE(0, 0, 8700) / 4) | 0) + ((-LINE(0, 0, 8885) / 4) | 0) + ((-LINE(0, 0, 9012) / 4) | 0) + ((-LINE(0, 0, 9171) / 4) | 0) + ((-LINE(0, 0, 8034) / 4) | 0) + ((-LINE(0, 0, 9449) / 4) | 0) + ((-LINE(0, 0, 9513) / 4) | 0) + ((-LINE(0, 0, 9765) / 4) | 0) + ((-LINE(0, 0, 9867) / 4) | 0) + ((-LINE(0, 0, 10046) / 4) | 0) + ((-LINE(0, 0, 10110) / 4) | 0) + ((-LINE(0, 0, 10285) / 4) | 0) + ((-LINE(0, 0, 12074) / 4) | 0) + ((-LINE(0, 0, 10578) / 4) | 0) + ((-LINE(0, 0, 10734) / 4) | 0) + ((-LINE(0, 0, 11715) / 4) | 0) + ((-LINE(0, 0, 11023) / 4) | 0) + ((-LINE(0, 0, 11185) / 4) | 0) + ((LINE(0, 0, 11254) / 2) | 0) + ((LINE(0, 0, 11479) / 2) | 0) + ((LINE(0, 0, 11546) / 2) | 0) + ((LINE(0, 0, 10815) / 2) | 0) + ((LINE(0, 0, 11847) / 2) | 0) + ((LINE(0, 0, 10428) / 2) | 0) + ((LINE(0, 0, 12112) / 2) | 0) + ((LINE(0, 0, 12279) / 2) | 0) + ((LINE(0, 0, 12415) / 2) | 0) + ((LINE(0, 0, 12516) / 2) | 0) + ((LINE(0, 0, 12746) / 2) | 0) + ((LINE(0, 0, 12815) / 2) | 0) + ((LINE(0, 0, 13046) / 2) | 0) + ((LINE(0, 0, 13217) / 2) | 0) + ((LINE(0, 0, 13378) / 2) | 0) + ((LINE(0, 0, 13534) / 2) | 0);
  WRITE_LINE(0, 11, Acc);
  return [out_left, out_right];
}
/* Midifex effect 54: REVERB REVERSE REGEN */
function midifex_effect_54(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(1, 11, 2) / 2) | 0) + ((LINE(7, 2295, 21) / 2) | 0);
  WRITE_LINE(0, 2295, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 2295, 21) + ((LINE(6, 2272, 153) / 2) | 0);
  WRITE_LINE(0, 2272, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 2272, 153) + ((LINE(5, 2117, 273) / 2) | 0);
  WRITE_LINE(0, 2117, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 2117, 273) + ((LINE(8, 16381, 12000) / 2) | 0);
  tmp_3 = Acc;
  Acc = ((LINE(1, 11, 2) / 2) | 0) + ((LINE(4, 1842, 32) / 2) | 0);
  WRITE_LINE(0, 1842, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 1842, 32) + ((LINE(3, 1808, 175) / 2) | 0);
  WRITE_LINE(0, 1808, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 1808, 175) + ((LINE(2, 1631, 233) / 2) | 0);
  WRITE_LINE(0, 1631, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(2, 1631, 233) + ((LINE(8, 16381, 12000) / 2) | 0);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = tmp_3;
  Acc = ((Acc * -3 / 64) | 0) + ((-LINE(8, 16381, 1065) / 64) | 0) + ((-LINE(8, 16381, 1119) / 64) | 0) + ((-LINE(8, 16381, 1233) / 64) | 0) + ((-LINE(8, 16381, 1434) / 64) | 0) + ((-LINE(8, 16381, 1555) / 64) | 0) + ((-LINE(8, 16381, 1742) / 64) | 0) + ((-LINE(8, 16381, 1862) / 64) | 0) + ((-LINE(8, 16381, 2046) / 64) | 0) + ((-LINE(8, 16381, 3569) / 64) | 0) + ((-LINE(8, 16381, 2256) / 64) | 0) + ((-LINE(8, 16381, 2443) / 64) | 0) + ((-LINE(8, 16381, 3121) / 64) | 0) + ((-LINE(8, 16381, 2721) / 64) | 0) + ((LINE(8, 16381, 2873) / 32) | 0) + ((LINE(8, 16381, 3036) / 32) | 0) + ((LINE(8, 16381, 2579) / 32) | 0) + ((LINE(8, 16381, 3267) / 32) | 0) + ((LINE(8, 16381, 3451) / 32) | 0) + ((LINE(8, 16381, 2149) / 32) | 0) + ((LINE(8, 16381, 3725) / 32) | 0) + ((LINE(8, 16381, 3889) / 32) | 0) + ((LINE(8, 16381, 4034) / 32) | 0) + ((LINE(8, 16381, 4152) / 32) | 0) + ((-LINE(8, 16381, 4257) / 16) | 0) + ((-LINE(8, 16381, 4492) / 16) | 0) + ((-LINE(8, 16381, 4556) / 16) | 0) + ((-LINE(8, 16381, 4727) / 16) | 0) + ((-LINE(8, 16381, 4849) / 16) | 0) + ((-LINE(8, 16381, 6035) / 16) | 0) + ((-LINE(8, 16381, 5129) / 16) | 0) + ((-LINE(8, 16381, 5235) / 16) | 0) + ((-LINE(8, 16381, 6223) / 16) | 0) + ((-LINE(8, 16381, 5534) / 16) | 0) + ((LINE(8, 16381, 5759) / 8) | 0) + ((LINE(8, 16381, 5837) / 8) | 0) + ((LINE(8, 16381, 5034) / 8) | 0) + ((LINE(8, 16381, 6159) / 8) | 0) + ((LINE(8, 16381, 5421) / 8) | 0) + ((LINE(8, 16381, 6446) / 8) | 0) + ((LINE(8, 16381, 6534) / 8) | 0) + ((LINE(8, 16381, 6782) / 8) | 0) + ((LINE(8, 16381, 6859) / 8) | 0) + ((LINE(8, 16381, 7039) / 8) | 0) + ((LINE(8, 16381, 7126) / 8) | 0) + ((LINE(8, 16381, 7221) / 8) | 0) + ((LINE(8, 16381, 8565) / 8) | 0) + ((LINE(8, 16381, 7534) / 8) | 0) + ((LINE(8, 16381, 7736) / 8) | 0) + ((LINE(8, 16381, 7891) / 8) | 0) + ((LINE(8, 16381, 9215) / 8) | 0) + ((LINE(8, 16381, 8146) / 8) | 0) + ((LINE(8, 16381, 8278) / 8) | 0) + ((-LINE(8, 16381, 8447) / 4) | 0) + ((-LINE(8, 16381, 7439) / 4) | 0) + ((-LINE(8, 16381, 8700) / 4) | 0) + ((-LINE(8, 16381, 8885) / 4) | 0) + ((-LINE(8, 16381, 9012) / 4) | 0) + ((-LINE(8, 16381, 9171) / 4) | 0) + ((-LINE(8, 16381, 8034) / 4) | 0) + ((-LINE(8, 16381, 9449) / 4) | 0) + ((-LINE(8, 16381, 9513) / 4) | 0) + ((-LINE(8, 16381, 9765) / 4) | 0) + ((-LINE(8, 16381, 9867) / 4) | 0) + ((-LINE(8, 16381, 10046) / 4) | 0) + ((-LINE(8, 16381, 10110) / 4) | 0) + ((-LINE(8, 16381, 10285) / 4) | 0) + ((-LINE(8, 16381, 12074) / 4) | 0) + ((-LINE(8, 16381, 10578) / 4) | 0) + ((-LINE(8, 16381, 10734) / 4) | 0) + ((-LINE(8, 16381, 11715) / 4) | 0) + ((-LINE(8, 16381, 11023) / 4) | 0) + ((-LINE(8, 16381, 11185) / 4) | 0) + ((LINE(8, 16381, 11254) / 2) | 0) + ((LINE(8, 16381, 11479) / 2) | 0) + ((LINE(8, 16381, 11546) / 2) | 0) + ((LINE(8, 16381, 10815) / 2) | 0) + ((LINE(8, 16381, 11847) / 2) | 0) + ((LINE(8, 16381, 10428) / 2) | 0);
  WRITE_LINE(0, 11, Acc);
  Acc = ((LINE(8, 16381, 14084) / 2) | 0) + LINE(0, 0, 1);
  WRITE_LINE(0, 16381, Acc);
  return [out_left, out_right];
}
/* Midifex effect 55: MULTITAP PAN */
function midifex_effect_55(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((-LINE(0, 0, 8922) / 4) | 0) + ((LINE(0, 0, 5321) / 2) | 0) + ((LINE(0, 0, 4000) / 2) | 0) + ((LINE(0, 0, 2315) / 2) | 0);
  tmp_3 = Acc;
  Acc = ((-LINE(0, 0, 9012) / 4) | 0) + ((LINE(0, 0, 6352) / 2) | 0) + ((LINE(0, 0, 4000) / 2) | 0) + ((LINE(0, 0, 3378) / 2) | 0);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 56: MULTITAP REVERB */
function midifex_effect_56(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(0, 0, 13998) / 128) | 0) + ((LINE(0, 0, 13968) / 128) | 0) + ((LINE(0, 0, 13955) / 128) | 0) + ((LINE(0, 0, 13957) / 128) | 0) + ((LINE(0, 0, 13815) / 128) | 0) + ((-LINE(0, 0, 13819) / 64) | 0) + ((-LINE(0, 0, 13749) / 64) | 0) + ((-LINE(0, 0, 13756) / 64) | 0) + ((-LINE(0, 0, 13676) / 64) | 0) + ((LINE(0, 0, 13552) / 32) | 0) + ((LINE(0, 0, 13319) / 32) | 0) + ((LINE(0, 0, 13185) / 32) | 0) + ((LINE(0, 0, 12927) / 32) | 0) + ((LINE(0, 0, 12656) / 32) | 0) + ((-LINE(0, 0, 12338) / 16) | 0) + ((-LINE(0, 0, 11919) / 16) | 0) + ((-LINE(0, 0, 11361) / 16) | 0) + ((-LINE(0, 0, 10683) / 16) | 0) + ((LINE(0, 0, 9835) / 8) | 0) + ((LINE(0, 0, 8775) / 8) | 0) + ((-LINE(0, 0, 9450) / 4) | 0) + ((-LINE(0, 0, 5194) / 4) | 0) + ((LINE(0, 0, 4501) / 2) | 0) + ((LINE(0, 0, 2724) / 2) | 0) + ((LINE(0, 0, 781) / 2) | 0);
  tmp_3 = Acc;
  Acc = ((LINE(0, 0, 13986) / 128) | 0) + ((LINE(0, 0, 13919) / 128) | 0) + ((LINE(0, 0, 13918) / 128) | 0) + ((LINE(0, 0, 13972) / 128) | 0) + ((LINE(0, 0, 13807) / 128) | 0) + ((LINE(0, 0, 13854) / 128) | 0) + ((-LINE(0, 0, 13727) / 64) | 0) + ((-LINE(0, 0, 13619) / 64) | 0) + ((-LINE(0, 0, 13519) / 64) | 0) + ((LINE(0, 0, 13457) / 32) | 0) + ((LINE(0, 0, 13289) / 32) | 0) + ((LINE(0, 0, 13071) / 32) | 0) + ((-LINE(0, 0, 12727) / 16) | 0) + ((-LINE(0, 0, 12449) / 16) | 0) + ((-LINE(0, 0, 12016) / 16) | 0) + ((-LINE(0, 0, 11571) / 16) | 0) + ((LINE(0, 0, 10981) / 8) | 0) + ((LINE(0, 0, 10160) / 8) | 0) + ((LINE(0, 0, 9145) / 8) | 0) + ((LINE(0, 0, 8913) / 8) | 0) + ((-LINE(0, 0, 6873) / 4) | 0) + ((-LINE(0, 0, 4048) / 4) | 0) + ((LINE(0, 0, 3041) / 2) | 0) + ((LINE(0, 0, 1121) / 2) | 0);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 57: MULTITAP REVERSE PAN */
function midifex_effect_57(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((LINE(2, 12, 1) / 2) | 0) + ((LINE(6, 2298, 67) / 2) | 0);
  WRITE_LINE(0, 2298, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 2298, 67) + ((LINE(5, 2229, 121) / 2) | 0);
  WRITE_LINE(0, 2229, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 2229, 121) + LINE(0, 0, 14000);
  tmp_3 = Acc;
  Acc = ((LINE(1, 10, 1) / 2) | 0) + ((LINE(4, 1931, 45) / 2) | 0);
  WRITE_LINE(0, 1931, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 1931, 45) + ((LINE(3, 1884, 98) / 2) | 0);
  WRITE_LINE(0, 1884, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 1884, 98);
  tmp_5 = Acc;
  Acc = ((LINE(0, 0, 1065) / 32) | 0) + ((LINE(0, 0, 1233) / 32) | 0) + ((LINE(0, 0, 1555) / 32) | 0) + ((LINE(0, 0, 1862) / 32) | 0) + ((LINE(0, 0, 3569) / 32) | 0) + ((LINE(0, 0, 2443) / 32) | 0) + ((LINE(0, 0, 2721) / 32) | 0) + ((-LINE(0, 0, 2873) / 16) | 0) + ((-LINE(0, 0, 2579) / 16) | 0) + ((-LINE(0, 0, 3451) / 16) | 0) + ((-LINE(0, 0, 13112) / 16) | 0) + ((-LINE(0, 0, 3725) / 16) | 0) + ((-LINE(0, 0, 3889) / 16) | 0) + ((LINE(0, 0, 4152) / 8) | 0) + ((LINE(0, 0, 4492) / 8) | 0) + ((LINE(0, 0, 6035) / 8) | 0) + ((LINE(0, 0, 12345) / 8) | 0) + ((LINE(0, 0, 11111) / 8) | 0) + ((LINE(0, 0, 5235) / 8) | 0) + ((LINE(0, 0, 5534) / 8) | 0) + ((-LINE(0, 0, 5759) / 4) | 0) + ((-LINE(0, 0, 5034) / 4) | 0) + ((-LINE(0, 0, 10211) / 4) | 0) + ((-LINE(0, 0, 9123) / 4) | 0) + ((-LINE(0, 0, 12781) / 4) | 0) + ((-LINE(0, 0, 5421) / 4) | 0) + ((-LINE(0, 0, 6534) / 4) | 0) + ((LINE(0, 0, 6859) / 2) | 0) + ((LINE(0, 0, 7126) / 2) | 0) + ((LINE(0, 0, 8565) / 2) | 0) + ((LINE(0, 0, 7736) / 2) | 0) + ((LINE(0, 0, 9215) / 2) | 0) + ((LINE(0, 0, 8146) / 2) | 0);
  WRITE_LINE(0, 10, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  Acc = ((LINE(0, 0, 5759) / 8) | 0) + ((LINE(0, 0, 5837) / 8) | 0) + ((LINE(0, 0, 5034) / 8) | 0) + ((LINE(0, 0, 6159) / 8) | 0) + ((LINE(0, 0, 5421) / 8) | 0) + ((LINE(0, 0, 6446) / 8) | 0) + ((LINE(0, 0, 6534) / 8) | 0) + ((LINE(0, 0, 6782) / 8) | 0) + ((LINE(0, 0, 6859) / 8) | 0) + ((LINE(0, 0, 7039) / 8) | 0) + ((LINE(0, 0, 7126) / 8) | 0) + ((LINE(0, 0, 7221) / 8) | 0) + ((LINE(0, 0, 8565) / 8) | 0) + ((LINE(0, 0, 7534) / 8) | 0) + ((LINE(0, 0, 7736) / 8) | 0) + ((LINE(0, 0, 7891) / 8) | 0) + ((LINE(0, 0, 9215) / 8) | 0) + ((LINE(0, 0, 8146) / 8) | 0) + ((LINE(0, 0, 8278) / 8) | 0) + ((-LINE(0, 0, 8447) / 4) | 0) + ((-LINE(0, 0, 7439) / 4) | 0) + ((-LINE(0, 0, 8700) / 4) | 0) + ((-LINE(0, 0, 8885) / 4) | 0) + ((-LINE(0, 0, 9012) / 4) | 0) + ((-LINE(0, 0, 9171) / 4) | 0) + ((-LINE(0, 0, 8034) / 4) | 0) + ((-LINE(0, 0, 9449) / 4) | 0) + ((-LINE(0, 0, 9513) / 4) | 0) + ((-LINE(0, 0, 9765) / 4) | 0) + ((-LINE(0, 0, 9867) / 4) | 0) + ((-LINE(0, 0, 10046) / 4) | 0) + ((-LINE(0, 0, 10110) / 4) | 0) + ((-LINE(0, 0, 10285) / 4) | 0) + ((-LINE(0, 0, 12074) / 4) | 0) + ((-LINE(0, 0, 10578) / 4) | 0) + ((-LINE(0, 0, 10734) / 4) | 0) + ((-LINE(0, 0, 11715) / 4) | 0) + ((-LINE(0, 0, 11023) / 4) | 0) + ((-LINE(0, 0, 11185) / 4) | 0) + ((LINE(0, 0, 11254) / 2) | 0) + ((LINE(0, 0, 11479) / 2) | 0) + ((LINE(0, 0, 11546) / 2) | 0) + ((LINE(0, 0, 10815) / 2) | 0) + ((LINE(0, 0, 11847) / 2) | 0) + ((LINE(0, 0, 10428) / 2) | 0) + ((LINE(0, 0, 12112) / 2) | 0) + ((LINE(0, 0, 12279) / 2) | 0) + ((LINE(0, 0, 12415) / 2) | 0) + ((LINE(0, 0, 12516) / 2) | 0) + ((LINE(0, 0, 12746) / 2) | 0) + ((LINE(0, 0, 12815) / 2) | 0) + ((LINE(0, 0, 13046) / 2) | 0) + ((LINE(0, 0, 13217) / 2) | 0) + ((LINE(0, 0, 13378) / 2) | 0) + ((LINE(0, 0, 13534) / 2) | 0);
  WRITE_LINE(0, 12, Acc);
  return [out_left, out_right];
}
/* Midifex effect 58: THICKENER */
function midifex_effect_58(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_d, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 7) + ((LINE(18, 16375, 43) / 2) | 0);
  WRITE_LINE(0, 16375, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(18, 16375, 43) + ((LINE(17, 16330, 50) / 2) | 0);
  WRITE_LINE(0, 16330, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(17, 16330, 50) + ((LINE(16, 16278, 63) / 2) | 0);
  WRITE_LINE(0, 16278, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(16, 16278, 63) + ((LINE(15, 16213, 75) / 2) | 0);
  WRITE_LINE(0, 16213, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(15, 16213, 75) + ((LINE(14, 16136, 87) / 2) | 0);
  WRITE_LINE(0, 16136, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(14, 16136, 87) + ((LINE(13, 16047, 102) / 2) | 0);
  WRITE_LINE(0, 16047, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(13, 16047, 102) + ((LINE(12, 15943, 126) / 2) | 0);
  WRITE_LINE(0, 15943, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(12, 15943, 126) + ((LINE(11, 15815, 149) / 2) | 0);
  WRITE_LINE(0, 15815, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 15815, 149) + ((LINE(10, 15664, 179) / 2) | 0);
  WRITE_LINE(0, 15664, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 15664, 179) + ((LINE(9, 15483, 210) / 2) | 0);
  WRITE_LINE(0, 15483, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 15483, 210) + ((LINE(8, 15271, 257) / 2) | 0);
  WRITE_LINE(0, 15271, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 15271, 257) + ((LINE(7, 15012, 308) / 2) | 0);
  WRITE_LINE(0, 15012, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 15012, 308) + ((LINE(6, 14702, 363) / 2) | 0);
  WRITE_LINE(0, 14702, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 14702, 363) + ((LINE(5, 14337, 439) / 2) | 0);
  WRITE_LINE(0, 14337, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 14337, 439);
  tmp_d = Acc;
  Acc = tmp_d + ((LINE(4, 13896, 35) / 2) | 0);
  WRITE_LINE(0, 13896, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 13896, 35);
  WRITE_LINE(0, 6, -Acc);
  Acc = tmp_d + ((LINE(3, 13859, 31) / 2) | 0);
  WRITE_LINE(0, 13859, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 13859, 31);
  WRITE_LINE(0, 4, -Acc);
  out_left = LINE(2, 6, 1);
  out_right = LINE(1, 4, 1);
  return [out_left, out_right];
}
/* Midifex effect 59: THICKENER DENSE */
function midifex_effect_59(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 1) + ((LINE(2, 5, 1) / 2) | 0) + ((LINE(8, 16381, 34) / 2) | 0);
  WRITE_LINE(0, 16381, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 16381, 34) + ((LINE(7, 16345, 45) / 2) | 0);
  WRITE_LINE(0, 16345, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 16345, 45) + ((LINE(6, 16298, 67) / 2) | 0);
  WRITE_LINE(0, 16298, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 16298, 67) + ((LINE(5, 16229, 89) / 2) | 0);
  WRITE_LINE(0, 16229, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 16229, 89) + ((LINE(4, 16138, 101) / 2) | 0);
  WRITE_LINE(0, 16138, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 16138, 101) + ((LINE(3, 16035, 120) / 2) | 0);
  WRITE_LINE(0, 16035, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 16035, 120);
  WRITE_LINE(0, 3, Acc);
  Acc = LINE(1, 3, 0);
  WRITE_LINE(0, 5, Acc);
  out_left = LINE(2, 5, 0);
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 60: STEREOGEN AMBIENT */
function midifex_effect_60(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_0, tmp_5, out_left, out_right;
  tmp_0 = input;
  Acc = tmp_0 + ((LINE(4, 16381, 187) / 2) | 0);
  WRITE_LINE(0, 16381, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 16381, 187) + ((LINE(3, 16192, 337) / 2) | 0);
  WRITE_LINE(0, 16192, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 16192, 337);
  WRITE_LINE(0, 3, Acc);
  Acc = tmp_0 + ((LINE(2, 15853, 121) / 2) | 0);
  WRITE_LINE(0, 15853, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(2, 15853, 121) + ((LINE(1, 15730, 393) / 2) | 0);
  WRITE_LINE(0, 15730, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(1, 15730, 393);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = LINE(0, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 61: STEREOGEN THICK */
function midifex_effect_61(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_7d1, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 1) + ((LINE(4, 16381, 47) / 2) | 0);
  WRITE_LINE(0, 16381, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 16381, 47) + ((LINE(3, 16332, 89) / 2) | 0);
  WRITE_LINE(0, 16332, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 16332, 89) + ((LINE(2, 16241, 215) / 2) | 0);
  WRITE_LINE(0, 16241, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(2, 16241, 215);
  tmp_7d1 = Acc;
  Acc = tmp_7d1;
  WRITE_LINE(0, 301, Acc);
  out_left = LINE(1, 301, 296);
  out_right = LINE(1, 301, 298);
  return [out_left, out_right];
}
/* Midifex effect 62: STEREOGEN WIDE */
function midifex_effect_62(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = LINE(0, 0, 150);
  WRITE_LINE(0, 3, Acc);
  Acc = LINE(0, 0, 300);
  tmp_5 = Acc;
  out_left = tmp_5;
  out_right = LINE(1, 3, 0);
  return [out_left, out_right];
}
/* Midifex effect 63: STEREOGEN XWIDE */
function midifex_effect_63(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, tmp_3, tmp_5, out_left, out_right;
  WRITE_LINE(0, 0, input);
  Acc = ((-LINE(1, 14261, 1) / 4) | 0) + LINE(2, 14264, 1);
  tmp_3 = Acc;
  Acc = ((-LINE(2, 14264, 1) / 4) | 0) + LINE(1, 14261, 1);
  tmp_5 = Acc;
  Acc = ((LINE(0, 0, 3) * 3 / 2) | 0) + ((LINE(20, 16089, 15) / 2) | 0);
  WRITE_LINE(0, 16089, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(20, 16089, 15) + ((LINE(19, 16072, 22) / 2) | 0);
  WRITE_LINE(0, 16072, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(19, 16072, 22) + ((LINE(18, 16048, 29) / 2) | 0);
  WRITE_LINE(0, 16048, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(18, 16048, 29) + ((LINE(17, 16017, 45) / 2) | 0);
  WRITE_LINE(0, 16017, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(17, 16017, 45) + ((LINE(16, 15970, 61) / 2) | 0);
  WRITE_LINE(0, 15970, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(16, 15970, 61) + ((LINE(6, 14997, 105) / 2) | 0);
  WRITE_LINE(0, 14997, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(6, 14997, 105) + ((LINE(5, 14890, 149) / 2) | 0);
  WRITE_LINE(0, 14890, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(5, 14890, 149) + ((LINE(4, 14739, 213) / 2) | 0);
  WRITE_LINE(0, 14739, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(4, 14739, 213) + ((LINE(3, 14524, 258) / 2) | 0);
  WRITE_LINE(0, 14524, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(3, 14524, 258);
  WRITE_LINE(0, 14264, Acc);
  Acc = ((LINE(0, 0, 3) * 3 / 2) | 0) + ((LINE(11, 15210, 17) / 2) | 0);
  WRITE_LINE(0, 15210, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(11, 15210, 17) + ((LINE(10, 15191, 25) / 2) | 0);
  WRITE_LINE(0, 15191, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(10, 15191, 25) + ((LINE(9, 15164, 35) / 2) | 0);
  WRITE_LINE(0, 15164, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(9, 15164, 35) + ((LINE(8, 15127, 52) / 2) | 0);
  WRITE_LINE(0, 15127, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(8, 15127, 52) + ((LINE(7, 15073, 74) / 2) | 0);
  WRITE_LINE(0, 15073, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(7, 15073, 74) + ((LINE(15, 15907, 88) / 2) | 0);
  WRITE_LINE(0, 15907, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(15, 15907, 88) + ((LINE(14, 15817, 123) / 2) | 0);
  WRITE_LINE(0, 15817, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(14, 15817, 123) + ((LINE(13, 15692, 174) / 2) | 0);
  WRITE_LINE(0, 15692, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(13, 15692, 174) + ((LINE(12, 15516, 304) / 2) | 0);
  WRITE_LINE(0, 15516, -Acc);
  Acc = ((-Acc / 2) | 0) + LINE(12, 15516, 304);
  WRITE_LINE(0, 14261, Acc);
  out_left = tmp_5;
  out_right = tmp_3;
  return [out_left, out_right];
}
/* Midifex effect 64: DEFEAT */
function midifex_effect_64(input, DRAM, ptr, lfo1_value, lfo2_value) {
  const LINE = (id, w_addr, r_offset) => DRAM[(ptr + w_addr - r_offset) & 0x3fff];
  const WRITE_LINE = (id, w_addr, val) => { DRAM[(ptr + w_addr) & 0x3fff] = val; };
  let Acc, out_left, out_right;
  out_left = LINE(0, 140, 135);
  out_right = LINE(0, 140, 137);
  Acc = 0;
  WRITE_LINE(0, 140, -Acc);
  return [out_left, out_right];
}

const midifex_effects = {
  1: midifex_effect_1,
  2: midifex_effect_2,
  3: midifex_effect_3,
  4: midifex_effect_4,
  5: midifex_effect_5,
  6: midifex_effect_6,
  7: midifex_effect_7,
  8: midifex_effect_8,
  9: midifex_effect_9,
  10: midifex_effect_10,
  11: midifex_effect_11,
  12: midifex_effect_12,
  13: midifex_effect_13,
  14: midifex_effect_14,
  15: midifex_effect_15,
  16: midifex_effect_16,
  17: midifex_effect_17,
  18: midifex_effect_18,
  19: midifex_effect_19,
  20: midifex_effect_20,
  21: midifex_effect_21,
  22: midifex_effect_22,
  23: midifex_effect_23,
  24: midifex_effect_24,
  25: midifex_effect_25,
  26: midifex_effect_26,
  27: midifex_effect_27,
  28: midifex_effect_28,
  29: midifex_effect_29,
  30: midifex_effect_30,
  31: midifex_effect_31,
  32: midifex_effect_32,
  33: midifex_effect_33,
  34: midifex_effect_34,
  35: midifex_effect_35,
  36: midifex_effect_36,
  37: midifex_effect_37,
  38: midifex_effect_38,
  39: midifex_effect_39,
  40: midifex_effect_40,
  41: midifex_effect_41,
  42: midifex_effect_42,
  43: midifex_effect_43,
  44: midifex_effect_44,
  45: midifex_effect_45,
  46: midifex_effect_46,
  47: midifex_effect_47,
  48: midifex_effect_48,
  49: midifex_effect_49,
  50: midifex_effect_50,
  51: midifex_effect_51,
  52: midifex_effect_52,
  53: midifex_effect_53,
  54: midifex_effect_54,
  55: midifex_effect_55,
  56: midifex_effect_56,
  57: midifex_effect_57,
  58: midifex_effect_58,
  59: midifex_effect_59,
  60: midifex_effect_60,
  61: midifex_effect_61,
  62: midifex_effect_62,
  63: midifex_effect_63,
  64: midifex_effect_64,
};
