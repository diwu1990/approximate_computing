/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s):  
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and wce parameters
***/
// MAE% = 0.20 %
// MAE = 258 
// WCE% = 0.46 %
// WCE = 605 
// WCRE% = 700.00 %
// EP% = 99.90 %
// MRE% = 0.55 %
// MSE = 89374 
// PDK45_PWR = 0.027 mW
// PDK45_AREA = 55.8 um2
// PDK45_DELAY = 0.54 ns


module add16u_0KY(A, B, O);
  input [15:0] A, B;
  output [16:0] O;
  wire sig_78, sig_79, sig_80, sig_81, sig_83, sig_84;
  wire sig_85, sig_86, sig_89, sig_90, sig_91, sig_93;
  wire sig_94, sig_95, sig_96, sig_99, sig_100, sig_101;
  wire sig_103, sig_104, sig_105, sig_106;
  assign O[9] = 1'b0;
  assign sig_78 = A[9] | B[9];
  assign sig_79 = A[10] ^ B[10];
  assign sig_80 = A[10] & B[10];
  assign sig_81 = sig_79 & sig_78;
  assign O[10] = sig_79 ^ sig_78;
  assign sig_83 = sig_80 | sig_81;
  assign sig_84 = A[11] ^ B[11];
  assign sig_85 = A[11] & B[11];
  assign sig_86 = sig_84 & sig_83;
  assign O[11] = sig_84 ^ sig_83;
  assign O[3] = sig_85 | sig_86;
  assign sig_89 = A[12] ^ B[12];
  assign sig_90 = A[12] & B[12];
  assign sig_91 = sig_89 & O[3];
  assign O[12] = sig_89 ^ O[3];
  assign sig_93 = sig_90 | sig_91;
  assign sig_94 = A[13] ^ B[13];
  assign sig_95 = A[13] & B[13];
  assign sig_96 = sig_94 & sig_93;
  assign O[13] = sig_94 ^ sig_93;
  assign O[0] = sig_95 | sig_96;
  assign sig_99 = A[14] ^ B[14];
  assign sig_100 = A[14] & B[14];
  assign sig_101 = sig_99 & O[0];
  assign O[2] = sig_99 ^ O[0];
  assign sig_103 = sig_100 | sig_101;
  assign sig_104 = A[15] ^ B[15];
  assign sig_105 = A[15] & B[15];
  assign sig_106 = sig_104 & sig_103;
  assign O[15] = sig_104 ^ sig_103;
  assign O[16] = sig_105 | sig_106;
  assign O[1] = A[12];
  assign O[4] = B[1];
  assign O[5] = A[12];
  assign O[6] = B[5];
  assign O[7] = A[7];
  assign O[8] = B[8];
  assign O[14] = O[2];
endmodule

