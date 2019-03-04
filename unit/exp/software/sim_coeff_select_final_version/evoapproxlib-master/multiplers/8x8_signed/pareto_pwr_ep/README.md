
Selected circuits
===================
 - **Circuit**: 8-bit signed multiplier
 - **Selection criteria**: pareto optimal sub-set wrt. pwr and ep parameters

Parameters of selected circuits
----------------------------

| Circuit name | MAE<sub>%</sub> | WCE<sub>%</sub> | EP<sub>%</sub> | MRE<sub>%</sub> | MSE | Download |
| --- |  --- | --- | --- | --- | --- | --- | 
| mul8s_1KV8 | 0.00 | 0.00 | 0.00 | 0.00 | 0 |  [[Verilog](mul8s_1KV8.v)] [[Verilog<sub>PDK45</sub>](mul8s_1KV8_pdk45.v)] [[C](mul8s_1KV8.c)] |
| mul8s_1KR8 | 0.049 | 0.20 | 49.80 | 2.40 | 2731 |  [[Verilog](mul8s_1KR8.v)] [[Verilog<sub>PDK45</sub>](mul8s_1KR8_pdk45.v)] [[C](mul8s_1KR8.c)] |
| mul8s_1L2H | 0.081 | 0.39 | 74.61 | 4.41 | 5462 |  [[Verilog](mul8s_1L2H.v)] [[Verilog<sub>PDK45</sub>](mul8s_1L2H_pdk45.v)] [[C](mul8s_1L2H.c)] |
| mul8s_1KTY | 0.34 | 1.37 | 87.16 | 15.72 | 95576 |  [[Verilog](mul8s_1KTY.v)] [[Verilog<sub>PDK45</sub>](mul8s_1KTY_pdk45.v)] [[C](mul8s_1KTY.c)] |
| mul8s_1KR3 | 3.08 | 12.30 | 98.05 | 135.77 | 72829.102e2 |  [[Verilog](mul8s_1KR3.v)] [[Verilog<sub>PDK45</sub>](mul8s_1KR3_pdk45.v)] [[C](mul8s_1KR3.c)] |
    
Parameters
--------------
![Parameters figure](fig.png)

References
--------------
   - V. Mrazek, Z. Vasicek, L. Sekanina, H. Jiang and J. Han, "Scalable Construction of Approximate Multipliers With Formally Guaranteed Worst Case Error" in IEEE Transactions on Very Large Scale Integration (VLSI) Systems, vol. 26, no. 11, pp. 2572-2576, Nov. 2018. doi: [10.1109/TVLSI.2018.2856362](https://dx.doi.org/10.1109/TVLSI.2018.2856362)

             