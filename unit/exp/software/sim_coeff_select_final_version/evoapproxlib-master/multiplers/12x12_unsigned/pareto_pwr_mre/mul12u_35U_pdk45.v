/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, Z. Vasicek, L. Sekanina, H. Jiang and J. Han, "Scalable Construction of Approximate Multipliers With Formally Guaranteed Worst Case Error" in IEEE Transactions on Very Large Scale Integration (VLSI) Systems, vol. 26, no. 11, pp. 2572-2576, Nov. 2018. doi: 10.1109/TVLSI.2018.2856362 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mre parameters
***/
// MAE% = 1.53 %
// MAE = 256000 
// WCE% = 6.10 %
// WCE = 1024001 
// WCRE% = 100.00 %
// EP% = 99.95 %
// MRE% = 15.79 %
// MSE = 92062.713e6 
// PDK45_PWR = 0.106 mW
// PDK45_AREA = 267.0 um2
// PDK45_DELAY = 0.81 ns


module mul12u_35U ( A, B, O );
  input [11:0] A;
  input [11:0] B;
  output [23:0] O;

  wire C_10_10,C_10_7,C_10_8,C_10_9,C_11_10,C_11_7,C_11_8,C_11_9,C_12_10,C_12_7,C_12_8,C_12_9,C_8_10,C_8_7,C_8_8,C_8_9,C_9_10,C_9_7,C_9_8,C_9_9,S_10_10,S_10_11,S_10_4,S_10_5,S_10_6,S_10_7,S_10_8,S_10_9,S_11_10,S_11_11,S_11_3,S_11_4,S_11_5,S_11_6,S_11_7,S_11_8,S_11_9,S_12_10,S_12_11,S_12_2,S_12_3,S_12_4,S_12_5,S_12_6,S_12_7,S_12_8,S_12_9,S_7_10,S_7_11,S_7_7,S_7_8,S_7_9,S_8_10,S_8_11,S_8_6,S_8_7,S_8_8,S_8_9,S_9_10,S_9_11,S_9_5,S_9_6,S_9_7,S_9_8,S_9_9;

  assign S_7_7 = (A[7] & B[7]);
  assign S_7_8 = (A[7] & B[8]);
  assign S_7_9 = (A[7] & B[9]);
  assign S_7_10 = (A[7] & B[10]);
  assign S_7_11 = (A[7] & B[11]);
  assign S_8_6 = S_7_7;
  HAX1 U3440 (.A(S_7_8), .B((A[8] & B[7])), .YS(S_8_7), .YC(C_8_7));
  HAX1 U3441 (.A(S_7_9), .B((A[8] & B[8])), .YS(S_8_8), .YC(C_8_8));
  HAX1 U3442 (.A(S_7_10), .B((A[8] & B[9])), .YS(S_8_9), .YC(C_8_9));
  HAX1 U3443 (.A(S_7_11), .B((A[8] & B[10])), .YS(S_8_10), .YC(C_8_10));
  assign S_8_11 = (A[8] & B[11]);
  assign S_9_5 = S_8_6;
  assign S_9_6 = S_8_7;
  FAX1 U3452 (.A(S_8_8), .B(C_8_7), .C((A[9] & B[7])), .YS(S_9_7), .YC(C_9_7));
  FAX1 U3453 (.A(S_8_9), .B(C_8_8), .C((A[9] & B[8])), .YS(S_9_8), .YC(C_9_8));
  FAX1 U3454 (.A(S_8_10), .B(C_8_9), .C((A[9] & B[9])), .YS(S_9_9), .YC(C_9_9));
  FAX1 U3455 (.A(S_8_11), .B(C_8_10), .C((A[9] & B[10])), .YS(S_9_10), .YC(C_9_10));
  assign S_9_11 = (A[9] & B[11]);
  assign S_10_4 = S_9_5;
  assign S_10_5 = S_9_6;
  assign S_10_6 = S_9_7;
  FAX1 U3464 (.A(S_9_8), .B(C_9_7), .C((A[10] & B[7])), .YS(S_10_7), .YC(C_10_7));
  FAX1 U3465 (.A(S_9_9), .B(C_9_8), .C((A[10] & B[8])), .YS(S_10_8), .YC(C_10_8));
  FAX1 U3466 (.A(S_9_10), .B(C_9_9), .C((A[10] & B[9])), .YS(S_10_9), .YC(C_10_9));
  FAX1 U3467 (.A(S_9_11), .B(C_9_10), .C((A[10] & B[10])), .YS(S_10_10), .YC(C_10_10));
  assign S_10_11 = (A[10] & B[11]);
  assign S_11_3 = S_10_4;
  assign S_11_4 = S_10_5;
  assign S_11_5 = S_10_6;
  assign S_11_6 = S_10_7;
  FAX1 U3476 (.A(S_10_8), .B(C_10_7), .C((A[11] & B[7])), .YS(S_11_7), .YC(C_11_7));
  FAX1 U3477 (.A(S_10_9), .B(C_10_8), .C((A[11] & B[8])), .YS(S_11_8), .YC(C_11_8));
  FAX1 U3478 (.A(S_10_10), .B(C_10_9), .C((A[11] & B[9])), .YS(S_11_9), .YC(C_11_9));
  FAX1 U3479 (.A(S_10_11), .B(C_10_10), .C((A[11] & B[10])), .YS(S_11_10), .YC(C_11_10));
  assign S_11_11 = (A[11] & B[11]);
  assign S_12_2 = S_11_3;
  assign S_12_3 = S_11_4;
  assign S_12_4 = S_11_5;
  assign S_12_5 = S_11_6;
  assign S_12_6 = S_11_7;
  HAX1 U3488 (.A(S_11_8), .B(C_11_7), .YS(S_12_7), .YC(C_12_7));
  FAX1 U3489 (.A(S_11_9), .B(C_12_7), .C(C_11_8), .YS(S_12_8), .YC(C_12_8));
  FAX1 U3490 (.A(S_11_10), .B(C_12_8), .C(C_11_9), .YS(S_12_9), .YC(C_12_9));
  FAX1 U3491 (.A(S_11_11), .B(C_12_9), .C(C_11_10), .YS(S_12_10), .YC(C_12_10));
  assign S_12_11 = C_12_10;
  assign O = {S_12_11,S_12_10,S_12_9,S_12_8,S_12_7,S_12_6,S_12_5,S_12_4,S_12_3,S_12_2,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0};

endmodule

