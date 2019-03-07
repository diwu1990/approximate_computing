// #include <cstdlib>
// #include <ctime>
// #include "poly_appr.hpp"

// int main()
// {
//     // x^2 *1 + x^2 *2 + x^3 /2 + x^3 /8 + x^4 /16 + x^4 /32
//     // vector<double> coeff = {(double)1, (double)1/8, (double)1/2, (double)1/8, (double)1/256, (double)1/32};
//     // vector<double> order = {0,1,2,2,3,4};

//     vector<double> coeff = {(double)1, (double)1, (double)1/2, (double)1/4, (double)-1/16, (double)-1/64, (double)-1/256};
//     vector<double> order = {0,1,2,3,3,3,3};

//     uint64_t fracWidth = 8;
//     // string fixed_sim = "fixed";
//     string fixed_sim = "float";

//     // for (int i = 0; i < pow(2,fracWidth); ++i)
//     // {
//     //     double in = (double)i/(1UL<<fracWidth);
//     //     POLY_APPR poly_appr;
//     //     poly_appr.Init(coeff, order, fracWidth, "fixed");
//     //     // poly_appr.Help();
//     //     // poly_appr.Report();
//     //     printf("%.10lf <==> ", poly_appr.Out(in));
//     //     poly_appr.Init(coeff, order, fracWidth, "float");
//     //     printf("%.10lf\n", poly_appr.Out(in));
//     //     /* code */
//     // }

//     double in = (double)192/(1UL<<fracWidth)-1;
//     POLY_APPR poly_appr;
//     poly_appr.Init(coeff, order, fracWidth, "fixed");
//     // poly_appr.Help();
//     // poly_appr.Report();
//     printf("%.10lf <==> ", poly_appr.Out(in)*exp(1));
//     poly_appr.Init(coeff, order, fracWidth, "float");
//     printf("%.10lf\n", poly_appr.Out(in)*exp(1));
//     /* code */
    

// }