#include <cstdlib>
#include <ctime>
#include "exp_error_model.hpp"

int main()
{
    uint64_t fracWidth;
    string fixed_sim;
    fixed_sim = "fixed";
    double threshold;
    vector<double> coeff;
    vector<double> order;
    vector<double> iWMRE;
    
    // fracWidth = 8;
    // threshold = 0.875;
    // coeff = {1, 1,   0.5, 0.25,    -0.125,  0.0625,  0.03125};
    // order = {0, 1,   2,   3,   4,   4,   4};
    // iWMRE = {0,0.00052,0.0018,0.0051,0.019,0.0473,0.1214,0.2842,0.5781,1};
    // // iWMRE = {0.5781};

    // fracWidth = 12;
    // threshold = 0.25;
    // coeff = {1,  1,   0.5, 0.125,   -0.0625, -0.03125,    -0.015625,   -0.007812};
    // order = {0,  1,   2,   3,   4,   5,   5,   5};
    // iWMRE = {0,0.0000062,0.00005,0.00026,0.0012,0.0046,0.0189,0.0784,0.2671,0.8798};
    // // iWMRE = {0.8798};

    // for neuron, the resultant MRE of MUL for 1% exp accracy is 0.0312
    // fracWidth = 16;
    // threshold = 0.75;
    // coeff = {1,  1,   0.5, 0.125,   0.0625,  0.03125, 0.015625};
    // order = {0,  1,   2,   3,   4,   4,   4};
    // iWMRE = {0.005,0.,0.01,0.02,0.0312};

    EXP_ERROR_MODEL exp_error_model;

    for (int i = 0; i < iWMRE.size(); ++i)
    {
        exp_error_model.Init(coeff, order, fracWidth, threshold);
        exp_error_model.Eval(iWMRE[i]);
        printf("%.6lf\n", exp_error_model.OWMRE());
        // printf("\n");
    }
}