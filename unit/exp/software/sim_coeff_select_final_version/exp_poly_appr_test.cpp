#include <cstdlib>
#include <ctime>
#include "exp_poly_appr.hpp"

int main()
{
    vector<double> coeff;
    vector<double> order;
    uint64_t fracWidth = 12;
    string fixed_sim;
    double in;
    double threshold;
    
    fixed_sim = "fixed";
    // fixed_sim = "float";
    in = 0.95;
    threshold = 0.25;
    EXP_POLY_APPR exp_poly_appr;

    // coeff = {1 , 1  , 0.5 ,0.125 ,  -0.0625};
    // order = {0  ,1   ,2  , 3 ,  4};
    
    // coeff = {1 , 1  , 0.5 ,0.125 ,  -0.0625, -0.03125};
    // order = {0  ,1   ,2  , 3 ,  4 ,  5};
    
    // coeff = {1 , 1  , 0.5 ,0.125 ,  -0.0625, -0.03125  ,  -0.015625};
    // order = {0  ,1   ,2  , 3 ,  4 ,  5, 5};

    coeff = {1 , 1  , 0.5 ,0.125 ,  -0.0625, -0.03125  ,  -0.015625 ,  -0.007812};
    order = {0  ,1   ,2  , 3 ,  4 ,  5, 5, 5};
    exp_poly_appr.Init(coeff, order, fracWidth, threshold, fixed_sim);
    // printf("%lf\n", (exp(in) - exp_poly_appr.Out(in)) / exp(in));
    exp_poly_appr.Eval();
    printf("MAE(%.6lf), MSE(%.6lf), MRE(%.6lf), WCE(%.6lf), WCRE(%.6lf)\n", exp_poly_appr.MAE(), exp_poly_appr.MSE(), exp_poly_appr.MRE(), exp_poly_appr.WCE(), exp_poly_appr.WCRE());
    printf("\n");

}