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
    
    // for neuron, the resultant MRE of MUL for 1% exp accracy is 0.0312
    // fracWidth = 16;
    // threshold = 0.75;
    // coeff = {1,  1,   0.5, 0.125,   0.0625,  0.03125, 0.015625};
    // order = {0,  1,   2,   3,   4,   4,   4};
    // iWMRE = {0.005,0.,0.01,0.02,0.0312};


    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    // uniform, 8 bit, 12 bit, 16 bit
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    // fracWidth = 8;
    // threshold = 0.875;
    // coeff = {1, 1,   0.5, 0.25,    -0.125,  0.0625,  0.03125, 0.015625};
    // order = {0, 1,     2,    3,         4,       4,        4,        4};
    // iWMRE = {0.016,0.038,0.08,0.16,0.32,0.625};

    // fracWidth = 12;
    // threshold = 0.875;
    // coeff = {1, 1,   0.5, 0.25,    -0.125,  0.0625,  0.03125};
    // order = {0, 1,     2,    3,         4,       5,        5};
    // iWMRE = {0.018,0.038,0.08,0.155,0.306,0.59};

    // fracWidth = 16;
    // threshold = 0.75;
    // coeff = {1,   1,   0.5, 0.125,   0.0625,  0.03125, 0.015625};
    // order = {0,   1,     2,     3,        4,        4,        4};
    // iWMRE = {0.016,0.033,0.065,0.13,0.255,0.5};


    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 8 bit, uniform, N(0.75, 0.1), N(0.5, 0.1), N(0.25, 0.1)
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    // uniform
    // fracWidth = 8;
    // threshold = 0.875;
    // coeff = {1, 1,   0.5, 0.25,    -0.125,  0.0625,  0.03125, 0.015625};
    // order = {0, 1,     2,    3,         4,       4,        4,        4};
    // iWMRE = {0.016,0.038,0.08,0.16,0.32,0.625};

    // N(0.75, 0.1), the same as uniform
    // fracWidth = 8;
    // threshold = 0.875;
    // coeff = {1, 1,   0.5, 0.25,    -0.125,  0.0625,  0.03125, 0.015625};
    // order = {0, 1,     2,    3,         4,       4,        4,        4};
    // iWMRE = {0.016,0.038,0.08,0.16,0.32,0.625};

    // N(0.5, 0.1)
    // fracWidth = 8;
    // threshold = 0.875;
    // coeff = {1, 1,   0.5, 0.25,     0.125, -0.0625, -0.03125,-0.015625};
    // order = {0, 1,     2,    3,         4,       4,        4,        4};
    // iWMRE = {0.0015,0.024,0.065,0.147,0.305,0.6};

    // N(0.25, 0.1)
    fracWidth = 8;
    threshold = 0.75;
    coeff = {1, 1,   0.5, 0.25,     0.125, -0.0625};
    order = {0, 1,     2,    3,         4,       4};
    iWMRE = {0.0028,0.024,0.055,0.116,0.238,0.476};

    EXP_ERROR_MODEL exp_error_model;

    for (int i = 0; i < iWMRE.size(); ++i)
    {
        exp_error_model.Init(coeff, order, fracWidth, threshold);
        exp_error_model.Eval(iWMRE[i]);
        printf("%.6lf\n", exp_error_model.OWMRE());
        // printf("\n");
    }
}