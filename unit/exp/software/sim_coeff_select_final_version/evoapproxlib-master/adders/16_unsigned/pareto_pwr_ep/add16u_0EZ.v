/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s):  
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and ep parameters
***/
// MAE% = 0.39 %
// MAE = 512 
// WCE% = 0.78 %
// WCE = 1024 
// WCRE% = 100.00 %
// EP% = 50.00 %
// MRE% = 1.07 %
// MSE = 524288 
// PDK45_PWR = 0.065 mW
// PDK45_AREA = 132.8 um2
// PDK45_DELAY = 0.81 ns


module add16u_0EZ(A, B, O);
  input [15:0] A, B;
  output [16:0] O;
  wire sig_33, sig_34, sig_35, sig_36, sig_38, sig_39;
  wire sig_40, sig_41, sig_43, sig_44, sig_45, sig_46;
  wire sig_48, sig_49, sig_50, sig_51, sig_53, sig_54;
  wire sig_55, sig_56, sig_58, sig_59, sig_60, sig_61;
  wire sig_63, sig_64, sig_65, sig_66, sig_68, sig_69;
  wire sig_70, sig_71, sig_73, sig_74, sig_84, sig_85;
  wire sig_86, sig_88, sig_89, sig_90, sig_91, sig_93;
  wire sig_94, sig_95, sig_96, sig_98, sig_99, sig_100;
  wire sig_101, sig_103, sig_104, sig_105, sig_106;
  assign sig_33 = A[0] & B[0];
  assign sig_34 = A[1] ^ B[1];
  assign sig_35 = A[1] & B[1];
  assign sig_36 = sig_34 & sig_33;
  assign O[1] = sig_34 ^ sig_33;
  assign sig_38 = sig_35 | sig_36;
  assign sig_39 = A[2] ^ B[2];
  assign sig_40 = A[2] & B[2];
  assign sig_41 = sig_39 & sig_38;
  assign O[2] = sig_39 ^ sig_38;
  assign sig_43 = sig_40 | sig_41;
  assign sig_44 = A[3] ^ B[3];
  assign sig_45 = A[3] & B[3];
  assign sig_46 = sig_44 & sig_43;
  assign O[3] = sig_44 ^ sig_43;
  assign sig_48 = sig_45 | sig_46;
  assign sig_49 = A[4] ^ B[4];
  assign sig_50 = A[4] & B[4];
  assign sig_51 = sig_49 & sig_48;
  assign O[4] = sig_49 ^ sig_48;
  assign sig_53 = sig_50 | sig_51;
  assign sig_54 = A[5] ^ B[5];
  assign sig_55 = A[5] & B[5];
  assign sig_56 = sig_54 & sig_53;
  assign O[5] = sig_54 ^ sig_53;
  assign sig_58 = sig_55 | sig_56;
  assign sig_59 = A[6] ^ B[6];
  assign sig_60 = A[6] & B[6];
  assign sig_61 = sig_59 & sig_58;
  assign O[6] = sig_59 ^ sig_58;
  assign sig_63 = sig_60 | sig_61;
  assign sig_64 = A[7] ^ B[7];
  assign sig_65 = A[7] & B[7];
  assign sig_66 = sig_64 & sig_63;
  assign O[7] = sig_64 ^ sig_63;
  assign sig_68 = sig_65 | sig_66;
  assign sig_69 = A[8] ^ B[8];
  assign sig_70 = A[8] & B[8];
  assign sig_71 = sig_69 & sig_68;
  assign O[8] = sig_69 ^ sig_68;
  assign sig_73 = sig_70 | sig_71;
  assign sig_74 = A[9] ^ B[9];
  assign O[9] = sig_74 ^ sig_73;
  assign O[0] = B[0] ^ A[0];
  assign sig_84 = A[11] ^ B[11];
  assign sig_85 = A[11] & B[11];
  assign sig_86 = sig_84 & A[10];
  assign O[11] = sig_84 ^ A[10];
  assign sig_88 = sig_85 | sig_86;
  assign sig_89 = A[12] ^ B[12];
  assign sig_90 = A[12] & B[12];
  assign sig_91 = sig_89 & sig_88;
  assign O[12] = sig_89 ^ sig_88;
  assign sig_93 = sig_90 | sig_91;
  assign sig_94 = A[13] ^ B[13];
  assign sig_95 = A[13] & B[13];
  assign sig_96 = sig_94 & sig_93;
  assign O[13] = sig_94 ^ sig_93;
  assign sig_98 = sig_95 | sig_96;
  assign sig_99 = A[14] ^ B[14];
  assign sig_100 = A[14] & B[14];
  assign sig_101 = sig_99 & sig_98;
  assign O[14] = sig_99 ^ sig_98;
  assign sig_103 = sig_100 | sig_101;
  assign sig_104 = A[15] ^ B[15];
  assign sig_105 = A[15] & B[15];
  assign sig_106 = sig_104 & sig_103;
  assign O[15] = sig_104 ^ sig_103;
  assign O[16] = sig_105 | sig_106;
  assign O[10] = B[10];
endmodule
