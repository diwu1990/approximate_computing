#include <cstdlib>
#include <ctime>
#include "exp_poly_appr.hpp"

int main()
{
    vector<double> coeff;
    vector<double> order;
    uint64_t fracWidth = 8;
    string fixed_sim;
    double in;
    double threshold;
    
    fixed_sim = "fixed";
    // fixed_sim = "float";
    in = 0.95;
    threshold = 0.375;
    EXP_POLY_APPR exp_poly_appr;

    coeff = {1 , 1};
    order = {0  ,1};
    exp_poly_appr.Init(coeff, order, fracWidth, threshold, fixed_sim);
    exp_poly_appr.Eval();
    printf("MAE(%.6lf), MSE(%.6lf), MRE(%.6lf), WCE(%.6lf), WCRE(%.6lf)\n", exp_poly_appr.MAE(), exp_poly_appr.MSE(), exp_poly_appr.MRE(), exp_poly_appr.WCE(), exp_poly_appr.WCRE());
    printf("\n");

    coeff = {1 , 1 ,  0.5};
    order = {0  ,1  , 2};
    exp_poly_appr.Init(coeff, order, fracWidth, threshold, fixed_sim);
    exp_poly_appr.Eval();
    printf("MAE(%.6lf), MSE(%.6lf), MRE(%.6lf), WCE(%.6lf), WCRE(%.6lf)\n", exp_poly_appr.MAE(), exp_poly_appr.MSE(), exp_poly_appr.MRE(), exp_poly_appr.WCE(), exp_poly_appr.WCRE());
    printf("\n");

    coeff = {1 , 1 ,  0.5, 0.125};
    order = {0  ,1  , 2  , 3};
    exp_poly_appr.Init(coeff, order, fracWidth, threshold, fixed_sim);
    exp_poly_appr.Eval();
    printf("MAE(%.6lf), MSE(%.6lf), MRE(%.6lf), WCE(%.6lf), WCRE(%.6lf)\n", exp_poly_appr.MAE(), exp_poly_appr.MSE(), exp_poly_appr.MRE(), exp_poly_appr.WCE(), exp_poly_appr.WCRE());
    printf("\n");

    coeff = {1 , 1 ,  0.5, 0.125,   -0.0625};
    order = {0  ,1  , 2  , 3 ,  4 };
    exp_poly_appr.Init(coeff, order, fracWidth, threshold, fixed_sim);
    exp_poly_appr.Eval();
    printf("MAE(%.6lf), MSE(%.6lf), MRE(%.6lf), WCE(%.6lf), WCRE(%.6lf)\n", exp_poly_appr.MAE(), exp_poly_appr.MSE(), exp_poly_appr.MRE(), exp_poly_appr.WCE(), exp_poly_appr.WCRE());
    printf("\n");

}