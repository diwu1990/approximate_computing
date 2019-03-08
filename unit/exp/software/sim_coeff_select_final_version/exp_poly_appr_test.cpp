// #include <cstdlib>
// #include <ctime>
// #include "exp_poly_appr.hpp"

// int main()
// {
//     uint64_t fracWidth;
//     string fixed_sim;
//     fixed_sim = "fixed";
//     double threshold;
    
//     fracWidth = 8;
//     threshold = 0.875;
//     vector<double> total_coeff = {1, 1,   0.5, 0.25,    -0.125,  0.0625,  0.03125, 0.015625};
//     vector<double> total_order = {0, 1,   2,   3,   4,   4,   4,   4};

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
//         printf("%.6lf, ", exp_poly_appr.MRE());
//         // printf("\n");
//     }
//     printf("\n");

// }