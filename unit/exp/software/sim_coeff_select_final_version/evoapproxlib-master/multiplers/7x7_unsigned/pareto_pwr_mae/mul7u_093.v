/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, S. S. Sarwar, L. Sekanina, Z. Vasicek and K. Roy, "Design of power-efficient approximate multipliers for approximate artificial neural networks," 2016 IEEE/ACM International Conference on Computer-Aided Design (ICCAD), Austin, TX, 2016, pp. 1-7. doi: 10.1145/2966986.2967021 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mae parameters
***/
// MAE% = 0.24 %
// MAE = 40 
// WCE% = 0.99 %
// WCE = 162 
// WCRE% = 3100.00 %
// EP% = 95.40 %
// MRE% = 5.32 %
// MSE = 2487 
// PDK45_PWR = 0.161 mW
// PDK45_AREA = 351.5 um2
// PDK45_DELAY = 1.30 ns


module mul7u_093(A, B, O);
  input [6:0] A, B;
  output [13:0] O;
  wire [6:0] A, B;
  wire [13:0] O;
  wire sig_27, sig_54, sig_55, sig_56, sig_62, sig_63;
  wire sig_82, sig_83, sig_85, sig_86, sig_87, sig_88;
  wire sig_89, sig_90, sig_91, sig_92, sig_93, sig_94;
  wire sig_95, sig_100, sig_101, sig_102, sig_114, sig_115;
  wire sig_116, sig_117, sig_118, sig_119, sig_120, sig_121;
  wire sig_122, sig_123, sig_124, sig_125, sig_126, sig_127;
  wire sig_128, sig_129, sig_130, sig_131, sig_132, sig_133;
  wire sig_134, sig_138, sig_140, sig_141, sig_150, sig_153;
  wire sig_154, sig_156, sig_157, sig_158, sig_159, sig_160;
  wire sig_161, sig_162, sig_163, sig_164, sig_165, sig_166;
  wire sig_167, sig_168, sig_169, sig_170, sig_171, sig_172;
  wire sig_173, sig_177, sig_178, sig_179, sig_180, sig_186;
  wire sig_188, sig_189, sig_191, sig_192, sig_193, sig_194;
  wire sig_196, sig_197, sig_198, sig_199, sig_200, sig_201;
  wire sig_202, sig_203, sig_204, sig_205, sig_206, sig_207;
  wire sig_208, sig_209, sig_210, sig_211, sig_212, sig_213;
  wire sig_214, sig_215, sig_216, sig_217, sig_218, sig_219;
  wire sig_222, sig_223, sig_224, sig_226, sig_227, sig_228;
  wire sig_229, sig_231, sig_232, sig_233, sig_234, sig_236;
  wire sig_237, sig_238, sig_239, sig_241, sig_242, sig_243;
  wire sig_244, sig_246, sig_247, sig_248, sig_249;
  assign sig_27 = A[6] & B[1];
  assign sig_54 = B[1] & A[5];
  assign sig_55 = sig_54 ^ sig_27;
  assign sig_56 = sig_54 & A[6];
  assign sig_62 = A[5] & B[2];
  assign sig_63 = A[6] & B[2];
  assign sig_82 = A[4] & B[2];
  assign sig_83 = B[5] & A[1];
  assign sig_85 = sig_82 | sig_83;
  assign sig_86 = sig_55 ^ sig_62;
  assign sig_87 = sig_55 & sig_62;
  assign sig_88 = sig_86 & sig_85;
  assign sig_89 = sig_86 ^ sig_85;
  assign sig_90 = sig_87 ^ sig_88;
  assign sig_91 = sig_56 ^ sig_63;
  assign sig_92 = sig_56 & B[2];
  assign sig_93 = sig_91 & sig_90;
  assign sig_94 = sig_91 ^ sig_90;
  assign sig_95 = sig_92 | sig_93;
  assign sig_100 = A[4] & B[3];
  assign sig_101 = A[5] & B[3];
  assign sig_102 = A[6] & B[3];
  assign sig_114 = B[3] & A[2];
  assign sig_115 = !(A[3] & B[3]);
  assign sig_116 = B[3] & A[3];
  assign sig_117 = B[4] & sig_114;
  assign sig_118 = !(sig_115 & B[3]);
  assign sig_119 = sig_116 | sig_117;
  assign sig_120 = sig_89 ^ sig_100;
  assign sig_121 = sig_89 & sig_100;
  assign sig_122 = sig_120 & sig_119;
  assign sig_123 = sig_120 ^ sig_119;
  assign sig_124 = sig_121 ^ sig_122;
  assign sig_125 = sig_94 ^ sig_101;
  assign sig_126 = sig_94 & sig_101;
  assign sig_127 = sig_125 & sig_124;
  assign sig_128 = sig_125 ^ sig_124;
  assign sig_129 = sig_126 | sig_127;
  assign sig_130 = sig_95 ^ sig_102;
  assign sig_131 = sig_95 & B[3];
  assign sig_132 = A[6] & sig_129;
  assign sig_133 = sig_130 ^ sig_129;
  assign sig_134 = sig_131 | sig_132;
  assign O[5] = A[0] & B[0];
  assign sig_138 = A[3] & B[4];
  assign O[4] = A[4] & B[4];
  assign sig_140 = A[5] & B[4];
  assign sig_141 = A[6] & B[4];
  assign sig_150 = sig_118 & A[2];
  assign sig_153 = sig_150 & B[4];
  assign sig_154 = sig_123 ^ sig_138;
  assign O[0] = sig_123 & sig_138;
  assign sig_156 = sig_154 & sig_153;
  assign sig_157 = sig_154 ^ sig_153;
  assign sig_158 = O[0] ^ sig_156;
  assign sig_159 = sig_128 ^ O[4];
  assign sig_160 = sig_128 & O[4];
  assign sig_161 = sig_159 & sig_158;
  assign sig_162 = sig_159 ^ sig_158;
  assign sig_163 = sig_160 | sig_161;
  assign sig_164 = sig_133 ^ sig_140;
  assign sig_165 = sig_133 & sig_140;
  assign sig_166 = sig_164 & sig_163;
  assign sig_167 = sig_164 ^ sig_163;
  assign sig_168 = sig_165 ^ sig_166;
  assign sig_169 = sig_134 ^ sig_141;
  assign sig_170 = sig_134 & B[4];
  assign sig_171 = A[6] & sig_168;
  assign sig_172 = sig_169 ^ sig_168;
  assign sig_173 = sig_170 | sig_171;
  assign O[3] = A[2] & B[5];
  assign sig_177 = A[3] & B[5];
  assign sig_178 = A[4] & B[5];
  assign sig_179 = A[5] & B[5];
  assign sig_180 = A[6] & B[5];
  assign sig_186 = A[6] & B[0];
  assign sig_188 = sig_157 ^ O[3];
  assign sig_189 = sig_157 & A[2];
  assign sig_191 = sig_188;
  assign sig_192 = sig_189 & B[5];
  assign sig_193 = sig_162 ^ sig_177;
  assign sig_194 = sig_162 & sig_177;
  assign O[2] = sig_193 & sig_192;
  assign sig_196 = sig_193 ^ sig_192;
  assign sig_197 = sig_194 | O[2];
  assign sig_198 = sig_167 ^ sig_178;
  assign sig_199 = sig_167 & sig_178;
  assign sig_200 = sig_198 & sig_197;
  assign sig_201 = sig_198 ^ sig_197;
  assign sig_202 = sig_199 | sig_200;
  assign sig_203 = sig_172 ^ sig_179;
  assign sig_204 = sig_172 & sig_179;
  assign sig_205 = sig_203 & sig_202;
  assign sig_206 = sig_203 ^ sig_202;
  assign sig_207 = sig_204 ^ sig_205;
  assign sig_208 = sig_173 ^ sig_180;
  assign sig_209 = sig_173 & B[5];
  assign sig_210 = A[6] & sig_207;
  assign sig_211 = sig_208 ^ sig_207;
  assign sig_212 = sig_209 | sig_210;
  assign sig_213 = A[0] & B[6];
  assign sig_214 = A[1] & B[6];
  assign sig_215 = A[2] & B[6];
  assign sig_216 = A[3] & B[6];
  assign sig_217 = A[4] & B[6];
  assign sig_218 = A[5] & B[6];
  assign sig_219 = A[6] & B[6];
  assign O[6] = sig_186 ^ sig_213;
  assign O[1] = sig_186 & sig_213;
  assign sig_222 = sig_191 ^ sig_214;
  assign sig_223 = sig_191 & sig_214;
  assign sig_224 = sig_222 & O[1];
  assign O[7] = sig_222 ^ O[1];
  assign sig_226 = sig_223 | sig_224;
  assign sig_227 = sig_196 ^ sig_215;
  assign sig_228 = sig_196 & sig_215;
  assign sig_229 = sig_227 & sig_226;
  assign O[8] = sig_227 ^ sig_226;
  assign sig_231 = sig_228 ^ sig_229;
  assign sig_232 = sig_201 ^ sig_216;
  assign sig_233 = sig_201 & sig_216;
  assign sig_234 = sig_232 & sig_231;
  assign O[9] = sig_232 ^ sig_231;
  assign sig_236 = sig_233 | sig_234;
  assign sig_237 = sig_206 ^ sig_217;
  assign sig_238 = sig_206 & sig_217;
  assign sig_239 = sig_237 & sig_236;
  assign O[10] = sig_237 ^ sig_236;
  assign sig_241 = sig_238 | sig_239;
  assign sig_242 = sig_211 ^ sig_218;
  assign sig_243 = sig_211 & sig_218;
  assign sig_244 = sig_242 & sig_241;
  assign O[11] = sig_242 ^ sig_241;
  assign sig_246 = sig_243 ^ sig_244;
  assign sig_247 = sig_212 ^ sig_219;
  assign sig_248 = sig_212 & B[6];
  assign sig_249 = A[6] & sig_246;
  assign O[12] = sig_247 ^ sig_246;
  assign O[13] = sig_248 | sig_249;
endmodule

