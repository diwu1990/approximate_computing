/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, R. Hrbacek, Z. Vasicek and L. Sekanina, "EvoApprox8b: Library of approximate adders and multipliers for circuit design and benchmarking of approximation methods". Design, Automation & Test in Europe Conference & Exhibition (DATE), 2017, Lausanne, 2017, pp. 258-261. doi: 10.23919/DATE.2017.7926993 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mse parameters
***/
// MAE% = 0.78 %
// MAE = 4.0 
// WCE% = 2.93 %
// WCE = 15 
// WCRE% = 500.00 %
// EP% = 90.62 %
// MRE% = 2.08 %
// MSE = 27 
// PDK45_PWR = 0.014 mW
// PDK45_AREA = 37.1 um2
// PDK45_DELAY = 0.31 ns


module add8u_5G5(A, B, O);
  input [7:0] A;
  input [7:0] B;
  output [8:0] O;
  wire [2031:0] N;
  assign N[0] = A[0];
  assign N[1] = A[0];
  assign N[2] = A[1];
  assign N[3] = A[1];
  assign N[4] = A[2];
  assign N[5] = A[2];
  assign N[6] = A[3];
  assign N[7] = A[3];
  assign N[8] = A[4];
  assign N[9] = A[4];
  assign N[10] = A[5];
  assign N[11] = A[5];
  assign N[12] = A[6];
  assign N[13] = A[6];
  assign N[14] = A[7];
  assign N[15] = A[7];
  assign N[16] = B[0];
  assign N[17] = B[0];
  assign N[18] = B[1];
  assign N[19] = B[1];
  assign N[20] = B[2];
  assign N[21] = B[2];
  assign N[22] = B[3];
  assign N[23] = B[3];
  assign N[24] = B[4];
  assign N[25] = B[4];
  assign N[26] = B[5];
  assign N[27] = B[5];
  assign N[28] = B[6];
  assign N[29] = B[6];
  assign N[30] = B[7];
  assign N[31] = B[7];
  XNOR2X1 n36(.A(N[4]), .B(N[4]), .Y(N[36]));
  NOR2X1 n52(.A(N[6]), .B(N[36]), .Y(N[52]));
  BUFX2 n66(.A(N[52]), .Y(N[66]));
  BUFX2 n74(.A(N[66]), .Y(N[74]));
  assign N[75] = N[74];
  BUFX2 n78(.A(N[75]), .Y(N[78]));
  assign N[79] = N[78];
  INVX1 n126(.A(N[79]), .Y(N[126]));
  assign N[127] = N[126];
  OR2X1 n182(.A(N[6]), .B(N[22]), .Y(N[182]));
  assign N[183] = N[182];
  FAX1 n232(.A(N[8]), .B(N[24]), .C(N[78]), .YS(N[232]), .YC(N[233]));
  FAX1 n282(.A(N[10]), .B(N[26]), .C(N[233]), .YS(N[282]), .YC(N[283]));
  FAX1 n332(.A(N[12]), .B(N[28]), .C(N[283]), .YS(N[332]), .YC(N[333]));
  FAX1 n382(.A(N[14]), .B(N[30]), .C(N[333]), .YS(N[382]), .YC(N[383]));
  assign O[0] = N[4];
  assign O[1] = N[126];
  assign O[2] = N[127];
  assign O[3] = N[183];
  assign O[4] = N[232];
  assign O[5] = N[282];
  assign O[6] = N[332];
  assign O[7] = N[382];
  assign O[8] = N[383];
endmodule


