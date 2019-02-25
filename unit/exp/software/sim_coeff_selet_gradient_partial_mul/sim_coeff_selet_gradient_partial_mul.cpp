#include <cstdlib>
#include <ctime>
#include "exp_poly_appr.hpp"

int main()
{
    // fully configurable
    // theoretically, this contains all possible combinations

    // the max amount of terms
    // shift between adjacent coefficients can be from right 4 bits to left 4 bits.
    // order can be the same as previous or larger than previous by one.

    FILE *out_fp = fopen("sim_coeff_selet_gradient_partial_mul.csv", "w+");

    int max_term_up = 8;
    int order_variance = 1;
    int coeff_variance = 4;
    vector<string> fixed_sim = {"float", "fixed"};
    vector<double> threshold = {0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875};
    vector<uint64_t> fracWidth = {8,12,16};
    vector<double> coeff = {(double)1, (double)1, (double)1/2};
    vector<double> order = {0, 1, 2};

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
        for (int max_term = 4; max_term <= max_term_up; ++max_term)
        {
            fprintf(out_fp, "\n");
            for (int j = 0; j < fracWidth.size(); ++j)
            {
                fprintf(out_fp, "=========================================================================================\n");
                for (int k = 0; k < threshold.size(); ++k)
                {
                    // repete the same process under different configuration
                    coeff = {(double)1, (double)1, (double)1/2};
                    order = {0, 1, 2};
                    min_MRE = 10000000000000000000000.0;
                    for (int l = coeff.size(); l < max_term; ++l)
                    {
                        coeff.push_back(coeff[coeff.size()-1] / pow(2,coeff_variance+1));
                        order.push_back(order[order.size()-1]);
                        update = 0;
                        // positive coeff
                        for (int m = 0; m < 2*coeff_variance+1; ++m)
                        {
                            coeff[coeff.size()-1] *= 2;
                            order[order.size()-1] = order[order.size()-2];
                            for (int n = 0; n < order_variance+1; ++n)
                            {
                                if (l <= partial_mul)
                                {
                                    order[order.size()-1] += n;
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
                                // printf("\n%lf, %llu\n", threshold[j], fracWidth[k]);
                                // for (int x = 0; x < order.size(); ++x)
                                // {
                                //     printf("%lf, ", coeff[x]);
                                // }
                                // printf("\n");
                                // for (int x = 0; x < order.size(); ++x)
                                // {
                                //     printf("%lf, ", order[x]);
                                // }
                                // printf("\n");
                            }
                        }
                        coeff[coeff.size()-1] = 0 - coeff[coeff.size()-2] / pow(2,coeff_variance+1);
                        order[order.size()-1] = order[order.size()-2];
                        
                        // negative coeff
                        for (int m = 0; m < 2*coeff_variance+1; ++m)
                        {
                            coeff[coeff.size()-1] *= 2;
                            order[order.size()-1] = order[order.size()-2];
                            for (int n = 0; n < order_variance+1; ++n)
                            {
                                if (l <= partial_mul)
                                {
                                    order[order.size()-1] += n;
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
                                // printf("\n%lf, %llu\n", threshold[j], fracWidth[k]);
                                // for (int x = 0; x < order.size(); ++x)
                                // {
                                //     printf("%lf, ", coeff[x]);
                                // }
                                // printf("\n");
                                // for (int x = 0; x < order.size(); ++x)
                                // {
                                //     printf("%lf, ", order[x]);
                                // }
                                // printf("\n");
                            }
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