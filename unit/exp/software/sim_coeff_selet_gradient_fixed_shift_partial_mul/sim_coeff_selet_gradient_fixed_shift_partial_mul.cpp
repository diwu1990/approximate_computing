#include <cstdlib>
#include <ctime>
#include "exp_poly_appr.hpp"

int main()
{
    // partially configurable
    // this contains constrains to the shift offset

    // the max amount of terms
    // shift between adjacent coefficients can be from right 4 bits to left 4 bits, but can be negative or positive.
    // order is always larger than previous by one.

    FILE *out_fp = fopen("sim_coeff_selet_gradient_fixed_shift_partial_mul.csv", "w+");

    int max_term_up = 8;
    int order_variance = 0;
    int coeff_variance = 4;
    vector<string> fixed_sim = {"float", "fixed"};
    vector<double> threshold = {0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875};
    vector<uint64_t> fracWidth = {8,12,16};
    vector<double> coeff = {(double)1, (double)1, (double)1/2, (double)1/4};
    vector<double> order = {0, 1, 2, 3};

    int partial_mul = 5;

    double select_coeff;
    double select_order;
    double min_MRE;
    int update;

    EXP_POLY_APPR exp_poly_appr;

    for (int i = 0; i < fixed_sim.size(); ++i)
    {
        if (fixed_sim[i] == "fixed")
        {
            printf("Fixed:\n");
            fprintf(out_fp, "\n\nFixed:,\n");
        }
        else
        {
            printf("Float:\n");
            fprintf(out_fp, "\n\nFloat:,\n");
        }
        for (int max_term = 5; max_term <= max_term_up; ++max_term)
        {
            fprintf(out_fp, "\n");
            for (int j = 0; j < fracWidth.size(); ++j)
            {
                fprintf(out_fp, "=========================================================================================\n");
                for (int k = 0; k < threshold.size(); ++k)
                {
                    // repete the same process under different configuration
                    // coeff = {(double)1, (double)1, (double)1/2, (double)1/8};
                    coeff = {(double)1, (double)1, (double)1/2, (double)1/4};
                    order = {0, 1, 2, 3};
                    min_MRE = 10000000000000000000000.0;

                    // iterate with the same shift offset
                    // keep the shift offset unchanged, increase the term to max_term, order in each term is added by 1
                    for (int m = 0; m < coeff_variance+1; ++m)
                    {
                        for (int l = coeff.size(); l < max_term; ++l)
                        {
                            update = 0;
                            // positive coeff
                            // add new coeff to the end
                            coeff.push_back(coeff[coeff.size()-1]);
                            order.push_back(order[order.size()-1]);

                            // coeff won't be larger than previous
                            // printf("%lf\n", coeff[coeff.size()-1]);
                            coeff[coeff.size()-1] /= double(2^m);
                            // printf("%lf\n", coeff[coeff.size()-1]);
                            if (l > partial_mul)
                            {
                                order[order.size()-1] += 0;
                            }
                            else
                            {
                                order[order.size()-1] += 1;
                            }
                            exp_poly_appr.Init(coeff, order, fracWidth[j], threshold[k], fixed_sim[i]);
                            exp_poly_appr.Eval();
                            if (exp_poly_appr.MRE() < min_MRE)
                            {
                                update = 1;
                                min_MRE = exp_poly_appr.MRE();
                                select_coeff = coeff[coeff.size() - 1];
                                select_order = order[order.size() - 1];
                            }

                            // negative coeff
                            coeff[coeff.size()-1] = 0 - coeff[coeff.size()-2];
                            order[order.size()-1] = order[order.size()-2];

                            coeff[coeff.size()-1] /= double(2^m);
                            if (l > partial_mul)
                            {
                                order[order.size()-1] += 0;
                            }
                            else
                            {
                                order[order.size()-1] += 1;
                            }
                            exp_poly_appr.Init(coeff, order, fracWidth[j], threshold[k], fixed_sim[i]);
                            exp_poly_appr.Eval();
                            if (exp_poly_appr.MRE() < min_MRE)
                            {
                                update = 1;
                                min_MRE = exp_poly_appr.MRE();
                                select_coeff = coeff[coeff.size() - 1];
                                select_order = order[order.size() - 1];
                            }
                            if (update == 1)
                            {
                                coeff[coeff.size() - 1] = select_coeff;
                                order[order.size() - 1] = select_order;
                            }
                            else
                            {
                                coeff[coeff.size() - 1] = 0;
                                order[order.size() - 1] = select_order;
                            }
                        }
                    }

                    // record the coeff and order
                
                    printf("Term: %d, Threshold: %lf, Fraction Width: %llu\n", max_term, threshold[k], fracWidth[j]);
                    fprintf(out_fp, "Term:, %d, Threshold:, %lf, Fraction Width:, %llu, MRE:, %lf, ", max_term, threshold[k], fracWidth[j], min_MRE);

                    printf("Coefficient: ");
                    fprintf(out_fp, "Coefficient:, ");

                    for (int x = 0; x < order.size(); ++x)
                    {
                        printf("%lf, ", coeff[x]);
                        fprintf(out_fp, "%lf, ", coeff[x]);
                    }
                    if (order.size() < max_term_up)
                    {
                        for (int x = 0; x < max_term_up - order.size(); ++x)
                        {
                            fprintf(out_fp, ", ");
                        }
                    }
                    printf("\n");
                    printf("Order: ");
                    fprintf(out_fp, "Order:, ");
                    for (int x = 0; x < order.size(); ++x)
                    {
                        printf("%lf, ", order[x]);
                        fprintf(out_fp, "%lf, ", order[x]);
                    }
                    if (order.size() < max_term_up)
                    {
                        for (int x = 0; x < max_term_up - order.size(); ++x)
                        {
                            fprintf(out_fp, ", ");
                        }
                    }
                    printf("\n");
                    printf("MRE: %lf\n", min_MRE);
                    printf("\n");
                    fprintf(out_fp, "\n");
                }
                fprintf(out_fp, "\n\n");
            }
            fprintf(out_fp, "\n\n");
        }
    }
    fclose(out_fp);
    return 0;
}