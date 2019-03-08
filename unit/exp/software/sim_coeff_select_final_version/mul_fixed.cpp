#include "mul_fixed.hpp"
#include "mul8u_appr.c"
#include "mul12u_appr.c"
#include "mul16u_appr.c"

double MUL_FIXED::Out(double param1, double param2, uint64_t param3)
{
    fracWidth = param3;
    
    a = param1 * pow(2, fracWidth);
    a_frac = modf(a, &a_int);

    b = param2 * pow(2, fracWidth);
    b_frac = modf(b, &b_int);
    // printf("%lf, %lf\n", a_int, b_int);

    c = a_int * b_int / pow(2, fracWidth);
    c_frac = modf(c, &c_int);

    return (c_int / pow(2, fracWidth));

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // fracWidth = param3;
    
    // a = param1 * pow(2, fracWidth);
    // a_frac = modf(a, &a_int);
    // // printf("%lf\n", a_int);

    // b = param2 * pow(2, fracWidth);
    // b_frac = modf(b, &b_int);
    // // printf("%lf\n", b_int);

    // sign = 1-2*((a<0) ^ (b<0));
    // // printf("%d\n", sign);

    // ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // // c = (double) mul8u_appr((uint64_t)abs(a_int), (uint64_t)abs(b_int)) * (double)sign / pow(2, fracWidth);
    // // c = (double) mul8u_appr((uint64_t)abs(b_int), (uint64_t)abs(a_int)) * (double)sign / pow(2, fracWidth);

    // // c = (double) mul12u_appr((uint64_t)abs(a_int), (uint64_t)abs(b_int)) * (double)sign / pow(2, fracWidth);
    // // c = (double) mul12u_appr((uint64_t)abs(b_int), (uint64_t)abs(a_int)) * (double)sign / pow(2, fracWidth);

    // // c = (double) mul16u_appr((uint64_t)abs(a_int), (uint64_t)abs(b_int)) * (double)sign / pow(2, fracWidth);
    // c = (double) mul16u_appr((uint64_t)abs(b_int), (uint64_t)abs(a_int)) * (double)sign / pow(2, fracWidth);

    // ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // c_frac = modf(c, &c_int);
    // // printf("c: %lf, c_int: %lf\n\n", c, c_int);

    // return (c_int / pow(2, fracWidth));
}

