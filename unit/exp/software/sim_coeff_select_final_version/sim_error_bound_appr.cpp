// #include <cstdlib>
// #include <ctime>
// #include "exp_poly_appr.hpp"

// int main()
// {

//     // FILE *out_fp = fopen("sim_error_bound_appr.csv", "w+");

//     string fixed_sim = "fixed";
//     double threshold;
//     uint64_t fracWidth;
//     vector<double> coeff;
//     vector<double> order;
//     EXP_POLY_APPR exp_poly_appr;

//     // 8 bit
//     fracWidth = 8;
//     threshold = 0.875;
//     coeff = {1,   1,   0.5, 0.25,    -0.125,  0.0625,  0.03125};
//     order = {0,   1,     2,    3,         4,       4,        4};

//     exp_poly_appr.Init(coeff, order, fracWidth, threshold, fixed_sim);
//     exp_poly_appr.Eval();
//     printf("%lf\n", exp_poly_appr.MRE());


//     // // 12 bit
//     // fracWidth = 12;
//     // threshold = 0.25;
//     // coeff = {1,  1,   0.5, 0.125,   -0.0625, -0.03125,    -0.015625,   -0.007812};
//     // order = {0,  1,     2,     3,         4,        5,            5,           5};

//     // exp_poly_appr.Init(coeff, order, fracWidth, threshold, fixed_sim);
//     // exp_poly_appr.Eval();
//     // printf("%lf\n", exp_poly_appr.MRE());



//     // // 16 bit
//     // fracWidth = 16;
//     // threshold = 0.75;
//     // coeff = {1, 1,  0.5,    0.125,  0.0625, 0.03125,    0.015625};
//     // order = {0, 1,    2,        3,       4,       4,           4};

//     // exp_poly_appr.Init(coeff, order, fracWidth, threshold, fixed_sim);
//     // exp_poly_appr.Eval();
//     // printf("%lf\n", exp_poly_appr.MRE());
// }