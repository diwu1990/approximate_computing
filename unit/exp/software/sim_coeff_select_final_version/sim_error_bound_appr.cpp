// #include <cstdlib>
// #include <ctime>
// #include "exp_poly_appr.hpp"

// int main()
// {
//     // partially configurable
//     // this contains constrains to the shift offset

//     // the max amount of terms
//     // shift between adjacent coefficients can be from right 4 bits to left 4 bits, but can be negative or positive.
//     // order is always larger than previous by one.

//     FILE *out_fp = fopen("sim_error_bound_appr.csv", "w+");

//     string fixed_sim = "fixed";
//     double threshold;
//     uint64_t fracWidth = 8;
//     vector<double> coeff = {(double)1, (double)1, (double)1/2, (double)1/8};
//     vector<double> order = {0, 1, 2, 3};

//     EXP_POLY_APPR exp_poly_appr;
//     exp_poly_appr.Init(coeff, order, fracWidth, threshold, fixed_sim);
//     exp_poly_appr.Eval();
// }