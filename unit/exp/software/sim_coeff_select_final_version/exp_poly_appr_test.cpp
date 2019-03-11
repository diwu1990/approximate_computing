// #include <cstdlib>
// #include <ctime>
// #include "exp_poly_appr.hpp"

// int main()
// {
//     uint64_t fracWidth;
//     string fixed_sim;
//     fixed_sim = "fixed";
//     double threshold;
    
//     vector<double> total_coeff;
//     vector<double> total_order;

//     ////////////////////////////////////////////////////////////////////////////////////////////////////////
//     // uniform, 8 bit, 12 bit, 16 bit
//     ////////////////////////////////////////////////////////////////////////////////////////////////////////
//     // fracWidth = 8;
//     // threshold = 0.875;
//     // total_coeff = {1, 1,   0.5, 0.25,    -0.125,  0.0625,  0.03125, 0.015625};
//     // total_order = {0, 1,     2,    3,         4,       4,        4,        4};
//     // // iWMRE = {0.016,0.038,0.08,0.16,0.32,0.625};
//     // // mul8_265, mul8_431, mul8_234, mul8u_YX7, mul8u_18DU, mul8u_17QU
//     // iWMRE = {0.016,0.0809,0.2842};


//     // fracWidth = 12;
//     // threshold = 0.875;
//     // total_coeff = {1, 1,   0.5, 0.25,    -0.125,  0.0625,  0.03125};
//     // total_order = {0, 1,     2,    3,         4,       5,        5};
//     // // iWMRE = {0.018,0.038,0.08,0.155,0.306,0.59};
//     // // mul12x12_045, mul12x12_091, mul12x12_175, mul12x12_151, mul12x12_177, mul12x12_190
//     // iWMRE = {0.0199,0.0754,0.3055};


//     fracWidth = 16;
//     threshold = 0.75;
//     total_coeff = {1,   1,   0.5, 0.125,   0.0625,  0.03125, 0.015625};
//     total_order = {0,   1,     2,     3,        4,        4,        4};
//     // // iWMRE = {0.016,0.033,0.065,0.13,0.255,0.5};
//     // // mul16x16_021, mul16x16_023, mul16x16_030, mul16x16_032, mul16x16_034, mul16x16_040
//     // iWMRE = {0.0233,0.0645,0.2353};

//     ////////////////////////////////////////////////////////////////////////////////////////////////////////
//     // 8 bit, uniform, N(0.75, 0.1), N(0.5, 0.1), N(0.25, 0.1)
//     ////////////////////////////////////////////////////////////////////////////////////////////////////////
//     // uniform
//     // fracWidth = 8;
//     // threshold = 0.875;
//     // total_coeff = {1, 1,   0.5, 0.25,    -0.125,  0.0625,  0.03125, 0.015625};
//     // total_order = {0, 1,     2,    3,         4,       4,        4,        4};
//     // // iWMRE = {0.016,0.038,0.08,0.16,0.32,0.625};
//     // iWMRE = {0.016,0.0809,0.2842};

//     // N(0.75, 0.1), the same as uniform
//     // fracWidth = 8;
//     // threshold = 0.875;
//     // total_coeff = {1, 1,   0.5, 0.25,    -0.125,  0.0625,  0.03125, 0.015625};
//     // total_order = {0, 1,     2,    3,         4,       4,        4,        4};
//     // // iWMRE = {0.016,0.038,0.08,0.16,0.32,0.625};
//     // iWMRE = {0.016,0.0809,0.2842};

//     // N(0.5, 0.1)
//     // fracWidth = 8;
//     // threshold = 0.875;
//     // total_coeff = {1, 1,   0.5, 0.25,     0.125, -0.0625, -0.03125,-0.015625};
//     // total_order = {0, 1,     2,    3,         4,       4,        4,        4};
//     // // iWMRE = {0.0015,0.024,0.065,0.147,0.305,0.6};
//     // // mul8_165, mul8_285, mul8_185, mul8u_FTA, mul8u_18DU, mul8u_17QU
//     // iWMRE = {0.016,0.065,0.2842};

//     // N(0.25, 0.1)
//     // fracWidth = 8;
//     // threshold = 0.75;
//     // total_coeff = {1, 1,   0.5, 0.25,     0.125, -0.0625};
//     // total_order = {0, 1,     2,    3,         4,       4};
//     // // iWMRE = {0.0057,0.024,0.055,0.116,0.238,0.476};
//     // // mul8_083, mul8_285, mul8_412, mul8u_17KS, mul8u_QKX, mul8u_13QR
//     // iWMRE = {0.0051,0.0551,0.2195};



//     int max_term = total_coeff.size();
//     vector<double> coeff = {1};
//     vector<double> order = {0};
//     EXP_POLY_APPR exp_poly_appr;

//     for (int i = coeff.size(); i < max_term; ++i)
//     {
//         coeff.push_back(total_coeff[i]);
//         order.push_back(total_order[i]);
//         exp_poly_appr.Init(coeff, order, fracWidth, threshold, fixed_sim);
//         exp_poly_appr.Eval();
//         // printf("%lf\n", exp_poly_appr.Out(0.95));
//         // printf("Length(%lu): MRE(%.6lf), MSE(%.6lf), MAE(%.6lf), WCE(%.6lf), WCRE(%.6lf)\n", coeff.size(), exp_poly_appr.MRE(), exp_poly_appr.MSE(), exp_poly_appr.MAE(), exp_poly_appr.WCE(), exp_poly_appr.WCRE());
//         printf("%.6lf\n", exp_poly_appr.MRE());
//         // printf("\n");
//     }
//     printf("\n");

// }