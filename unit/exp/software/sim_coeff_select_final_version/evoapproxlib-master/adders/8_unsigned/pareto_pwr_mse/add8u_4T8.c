/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, Z. Vasicek and R. Hrbacek, "Role of circuit representation in evolutionary design of energy-efficient approximate circuits" in IET Computers & Digital Techniques, vol. 12, no. 4, pp. 139-149, 7 2018. doi: 10.1049/iet-cdt.2017.0188 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mse parameters
***/
// MAE% = 0.098 %
// MAE = 0.5 
// WCE% = 0.20 %
// WCE = 1.0 
// WCRE% = 100.00 %
// EP% = 50.00 %
// MRE% = 0.27 %
// MSE = 0.5 
// PDK45_PWR = 0.028 mW
// PDK45_AREA = 61.5 um2
// PDK45_DELAY = 0.55 ns
#include <stdint.h>
#include <stdlib.h>

uint64_t add8u_4T8(uint64_t a, uint64_t b) {
  uint64_t o = 0;
  int n_196=0, n_192=0, n_23=0, n_46=0, n_27=0, n_42=0, n_85=0, n_69=0, n_166=0, n_89=0;
  int n_66=0, n_62=0, n_200=0, n_108=0, n_204=0, n_208=0, n_127=0, n_100=0, n_189=0, n_104=0;
  int n_8=0, n_9=0, n_185=0, n_4=0, n_5=0, n_6=0, n_7=0, n_0=0, n_1=0, n_2=0;
  int n_3=0, n_31=0, n_35=0, n_16=0, n_39=0, n_14=0, n_15=0, n_12=0, n_13=0, n_10=0;
  int n_11=0, n_96=0, n_173=0, n_58=0, n_92=0, n_177=0, n_50=0, n_77=0, n_154=0, n_119=0;
  int n_54=0, n_73=0, n_169=0, n_212=0, n_139=0, n_135=0, n_131=0;
  n_0 = (a >> 0) & 0x1;
  n_1 = (a >> 1) & 0x1;
  n_2 = (a >> 2) & 0x1;
  n_3 = (a >> 3) & 0x1;
  n_4 = (a >> 4) & 0x1;
  n_5 = (a >> 5) & 0x1;
  n_6 = (a >> 6) & 0x1;
  n_7 = (a >> 7) & 0x1;
  n_8 = (b >> 0) & 0x1;
  n_9 = (b >> 1) & 0x1;
  n_10 = (b >> 2) & 0x1;
  n_11 = (b >> 3) & 0x1;
  n_12 = (b >> 4) & 0x1;
  n_13 = (b >> 5) & 0x1;
  n_14 = (b >> 6) & 0x1;
  n_15 = (b >> 7) & 0x1;
  n_16 = n_3 | n_11;
  n_23 = n_1 ^ n_9;
  n_27 = n_1 & n_9;
  n_31 = n_10 ^ n_2;
  n_35 = n_2 & n_10;
  n_39 = n_3 ^ n_11;
  n_42 = n_3 & n_11;
  n_46 = n_4 ^ n_12;
  n_50 = n_4 & n_12;
  n_54 = n_5 ^ n_13;
  n_58 = n_13 & n_5;
  n_62 = n_6 ^ n_14;
  n_66 = n_6 & n_14;
  n_69 = n_7 ^ n_15;
  n_73 = n_7 & n_15;
  n_77 = n_31 & n_27;
  n_85 = n_35 | n_77;
  n_89 = n_46 & n_42;
  n_92 = n_46 & n_39;
  n_96 = n_50 | n_89;
  n_100 = n_62 & n_58;
  n_104 = n_62 & n_54;
  n_108 = n_66 | n_100;
  n_119 = n_92 & n_85;
  n_127 = n_96 | n_119;
  n_131 = n_104 & n_96;
  n_135 = n_104 & n_119;
  n_139 = n_108 | n_131;
  n_154 = n_139 | n_135;
  n_166 = n_16 & n_85;
  n_169 = n_42 | n_166;
  n_173 = n_54 & n_127;
  n_177 = n_58 | n_173;
  n_185 = n_31 ^ n_27;
  n_189 = n_39 ^ n_85;
  n_192 = n_46 ^ n_169;
  n_196 = n_54 ^ n_127;
  n_200 = n_62 ^ n_177;
  n_204 = n_69 ^ n_154;
  n_208 = n_69 & n_154;
  n_212 = n_73 | n_208;
  o |= (n_0 & 0x01) << 0;
  o |= (n_23 & 0x01) << 1;
  o |= (n_185 & 0x01) << 2;
  o |= (n_189 & 0x01) << 3;
  o |= (n_192 & 0x01) << 4;
  o |= (n_196 & 0x01) << 5;
  o |= (n_200 & 0x01) << 6;
  o |= (n_204 & 0x01) << 7;
  o |= (n_212 & 0x01) << 8;
  return o;
}
