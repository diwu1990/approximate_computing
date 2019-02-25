// #include <cstdlib>
// #include <ctime>
// #include "exp_poly_appr.hpp"

// int main()
// {
//     vector<double> coeff;
//     vector<double> order;
//     uint64_t fracWidth = 8;
//     string fixed_sim;
//     double in;
//     double threshold;
    
//     // fixed_sim = "fixed";
//     fixed_sim = "float";
//     in = 0.95;
//     threshold = 0.75;
//     EXP_POLY_APPR exp_poly_appr;


//     // coeff = {(double)1, (double)1, (double)1/2, (double)1/4, (double)-1/16, (double)-1/64, (double)-1/256};
//     // order = {0,1,2,3,3,3,3};
//     // // order = {0,1,2,3,3,3,4};
//     // exp_poly_appr.Init(coeff, order, fracWidth, threshold, fixed_sim);
//     // printf("%lf\n", (exp(in) - exp_poly_appr.Out(in)) / exp(in));
//     // exp_poly_appr.Eval();
//     // printf("MAE(%.15lf), MSE(%.15lf), MRE(%.15lf), WCE(%.15lf), WCRE(%.15lf)\n", exp_poly_appr.MAE(), exp_poly_appr.MSE(), exp_poly_appr.MRE(), exp_poly_appr.WCE(), exp_poly_appr.WCRE());
//     // printf("\n");


//     coeff = {(double)1, (double)1, (double)1/2, (double)1/8, (double)1/16, (double)1/32, (double)1/64};
//     order = {0,1,2,3,4,4,5};
//     exp_poly_appr.Init(coeff, order, fracWidth, threshold, fixed_sim);
//     printf("%lf\n", (exp(in) - exp_poly_appr.Out(in)) / exp(in));
//     exp_poly_appr.Eval();
//     printf("MAE(%.15lf), MSE(%.15lf), MRE(%.15lf), WCE(%.15lf), WCRE(%.15lf)\n", exp_poly_appr.MAE(), exp_poly_appr.MSE(), exp_poly_appr.MRE(), exp_poly_appr.WCE(), exp_poly_appr.WCRE());
//     printf("\n");


//     // coeff = {(double)1, (double)1, (double)1/2, (double)1/6, (double)1/24, (double)1/120, (double)1/720};
//     // order = {0,1,2,3,4,5,6};
//     // exp_poly_appr.Init(coeff, order, fracWidth, threshold, fixed_sim);
//     // printf("%lf\n", (exp(in) - exp_poly_appr.Out(in)) / exp(in));
//     // exp_poly_appr.Eval();
//     // printf("MAE(%.15lf), MSE(%.15lf), MRE(%.15lf), WCE(%.15lf), WCRE(%.15lf)\n", exp_poly_appr.MAE(), exp_poly_appr.MSE(), exp_poly_appr.MRE(), exp_poly_appr.WCE(), exp_poly_appr.WCRE());
// }