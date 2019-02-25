#include "mul_fixed.hpp"

double MUL_FIXED::Out(double param1, double param2, uint64_t param3)
{
    fracWidth = param3;
    
    a = param1 * pow(2, fracWidth);
    a_frac = modf(a, &a_int);
    // printf("%lf\n", a_int);

    b = param2 * pow(2, fracWidth);
    b_frac = modf(b, &b_int);
    // printf("%lf\n", b_int);

    c = a_int * b_int / pow(2, fracWidth);
    c_frac = modf(c, &c_int);

    return (c_int / pow(2, fracWidth));
}


