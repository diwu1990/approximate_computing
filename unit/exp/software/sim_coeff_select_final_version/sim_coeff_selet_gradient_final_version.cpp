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

    FILE *out_fp = fopen("sim_coeff_selet_gradient_final_version.csv", "w+");

    int max_term_up = 8;
    int order_variance = 0;
    int coeff_variance = 4;
    // vector<string> fixed_sim = {"float", "fixed"};
    string fixed_sim = "fixed";
    vector<double> threshold = {0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875};
    vector<uint64_t> fracWidth = {8,12,16};
    vector<double> coeff = {(double)1, (double)1, (double)1/2, (double)1/8};
    vector<double> order = {0, 1, 2, 3};

    int init_len = coeff.size();

    vector<int> partial_mul_vec = {4, 5};
    vector<double> fixed_shift_vec = {0.125, 0.25};

    double select_coeff;
    double select_order;
    double min_MRE;
    int update;

    EXP_POLY_APPR exp_poly_appr;

    // the final value according to different configuration.
    // record all the data for final plot
    // the dimension is
    // 1. partial mul
    // 2. fixed shift
    // 3. fraction width
    // 4. term count
    // 5. threshold

    // finally just care about mre for different fracWidth at max term;
    vector<vector<vector<vector<vector<double>>>>> final_coeff;
    vector<vector<vector<vector<vector<double>>>>> final_order;
    vector<vector<vector<vector<vector<double>>>>> final_mre;

    final_coeff.resize(partial_mul_vec.size());
    final_order.resize(partial_mul_vec.size());
    final_mre.resize(partial_mul_vec.size());

    for (int i = 0; i < partial_mul_vec.size(); ++i)
    {
        final_coeff[i].resize(fixed_shift_vec.size());
        final_order[i].resize(fixed_shift_vec.size());
        final_mre[i].resize(fixed_shift_vec.size());

        for (int j = 0; j < fixed_shift_vec.size(); ++j)
        {
            final_coeff[i][j].resize(fracWidth.size());
            final_order[i][j].resize(fracWidth.size());
            final_mre[i][j].resize(fracWidth.size());

            for (int k = 0; k < fracWidth.size(); ++k)
            {
                final_coeff[i][j][k].resize(max_term_up);
                final_order[i][j][k].resize(max_term_up);
                final_mre[i][j][k].resize(max_term_up);

                for (int l = 0; l < max_term_up; ++l)
                {
                    // ps, fs, frac, term, th
                    final_coeff[i][j][k][l].resize(threshold.size());
                    final_order[i][j][k][l].resize(threshold.size());
                    final_mre[i][j][k][l].resize(threshold.size());

                }
            }
        }
    }

    for (int i = 0; i < partial_mul_vec.size(); ++i)
    {
        for (int j = 0; j < fixed_shift_vec.size(); ++j)
        {
            for (int k = 0; k < fracWidth.size(); ++k)
            {
                for (int l = 0; l < init_len; ++l)
                {
                    for (int m = 0; m < threshold.size(); ++m)
                    {
                        // ps, fs, frac, term, th
                        final_coeff[i][j][k][l][m] = coeff[l];
                        // printf("%lf,", final_coeff[i][j][k][l][m]);
                        final_order[i][j][k][l][m] = order[l];
                        final_mre[i][j][k][l][m] = 100000000000000.0;
                    }
                }
            }
        }
    }


    // ps(i), fs(n), frac(j), term(max_term), th(k)
    for (int i = 0; i < partial_mul_vec.size(); ++i)
    {
        int partial_mul = partial_mul_vec[i];
        printf("Multiplication is disabled after: %d,\n", partial_mul);
        fprintf(out_fp, "Multiplication is disabled after:, %d,\n", partial_mul);

        for (int n = 0; n < fixed_shift_vec.size(); ++n)
        {
            double fixed_shift = fixed_shift_vec[n];
            printf("Fixed shift starts with %f,\n", fixed_shift);
            fprintf(out_fp, "Fixed shift starts with, %f,\n", fixed_shift);

            for (int max_term = init_len+1; max_term <= max_term_up; ++max_term)
            {
                fprintf(out_fp, "\n");
                for (int j = 0; j < fracWidth.size(); ++j)
                {
                    fprintf(out_fp, "=========================================================================================\n");
                    for (int k = 0; k < threshold.size(); ++k)
                    {
                        printf("partial_mul(%d), fixed_shift(%lf), current_term(%d), fracWidth(%llu), threshold(%lf)\n", partial_mul, fixed_shift, max_term, fracWidth[j], threshold[k]);
                        // repete the same process under different configuration
                        if (fixed_shift == 0.125)
                        {
                            coeff = {(double)1, (double)1, (double)1/2, (double)1/8};
                        }
                        else
                        {
                            coeff = {(double)1, (double)1, (double)1/2, (double)1/4};
                        }
                        order = {0, 1, 2, 3};
                        min_MRE = 10000000000000000000000.0;


                        // initialization
                        // replace the last term with the expected
                        final_coeff[i][n][j][init_len-1][k] = coeff[coeff.size() - 1];
                        final_order[i][n][j][init_len-1][k] = order[order.size() - 1];

                        vector<double> coeff_c1 = {1.0, 1.0};
                        vector<double> order_c1 = {0, 1};
                        exp_poly_appr.Init(coeff_c1, order_c1, fracWidth[j], threshold[k], fixed_sim);
                        exp_poly_appr.Eval();
                        final_mre[i][n][j][1][k] = exp_poly_appr.MRE();

                        vector<double> coeff_c2 = {1.0, 1.0, 0.5};
                        vector<double> order_c2 = {0, 1, 2};
                        exp_poly_appr.Init(coeff_c2, order_c2, fracWidth[j], threshold[k], fixed_sim);
                        exp_poly_appr.Eval();
                        final_mre[i][n][j][2][k] = exp_poly_appr.MRE();

                        exp_poly_appr.Init(coeff, order, fracWidth[j], threshold[k], fixed_sim);
                        exp_poly_appr.Eval();
                        final_mre[i][n][j][init_len-1][k] = exp_poly_appr.MRE();

                        // for (int cur_term = 0; cur_term < max_term; ++cur_term)
                        // {
                        //     printf("%lf, ", final_coeff[i][n][j][cur_term][k]);
                        // }
                        // printf("\n");

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
                                exp_poly_appr.Init(coeff, order, fracWidth[j], threshold[k], fixed_sim);
                                exp_poly_appr.Eval();
                                if (exp_poly_appr.MRE() < min_MRE)
                                {
                                    update = 1;
                                    min_MRE = exp_poly_appr.MRE();
                                    // printf("%lf\n", min_MRE);
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
                                exp_poly_appr.Init(coeff, order, fracWidth[j], threshold[k], fixed_sim);
                                exp_poly_appr.Eval();
                                if (exp_poly_appr.MRE() < min_MRE)
                                {
                                    update = 1;
                                    min_MRE = exp_poly_appr.MRE();
                                    // printf("%lf\n", min_MRE);
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

                        // for (int cur_term = 0; cur_term < max_term; ++cur_term)
                        // {
                        //     printf("%lf, ", final_coeff[i][n][j][cur_term][k]);
                        // }
                        // printf("\n");
                        // printf("flag final1\n");
                        // printf("%lf, %lf\n", coeff[coeff.size() - 1],order[order.size() - 1]);
                        // printf("flag final2\n");

                        // ps(i), fs(n), frac(j), term(max_term), th(k)
                        final_coeff[i][n][j][max_term-1][k] = coeff[coeff.size() - 1];
                        // printf("flag final3\n");
                        final_order[i][n][j][max_term-1][k] = order[order.size() - 1];
                        // printf("flag final4\n");
                        // printf("%lf\n", min_MRE);
                        // for (int cur_term = 0; cur_term < max_term; ++cur_term)
                        // {
                        //     printf("%lf, ", final_mre[i][n][j][cur_term][k]);
                        // }
                        // printf("\n");
                        final_mre[i][n][j][max_term-1][k] = min_MRE;
                        // printf("%u,%u,%u,%u,%u\n", final_coeff[0].size(), final_coeff[0][1].size(), final_coeff[0].size());
                        // printf("flag final5\n");
                        // printf("pm(%d), fs(%lf), fracWidth(%llu), term(%d), th(%lf), %lf\n", partial_mul_vec[i], fixed_shift_vec[n], fracWidth[j], max_term, threshold[k], final_coeff[i][n][j][max_term-1][k]);
                        // printf("flag final6\n");
                        // printf("%lf\n", final_order[i][n][j][max_term-1][k]);
                        // printf("flag final7\n");
                        // printf("%lf\n", final_mre[i][n][j][max_term-1][k]);
                        // printf("flag final8\n");

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
        
    }
    fclose(out_fp);


    // printf("flag final one\n");
    FILE *out_fp1 = fopen("sim_coeff_selet_gradient_final_version_summary.csv", "w+");


    vector<vector<double>> min_coeff(fracWidth.size());
    vector<vector<double>> min_order(fracWidth.size());
    vector<vector<double>> min_mretotal(fracWidth.size());
    for (int i = 0; i < fracWidth.size(); ++i)
    {
        min_coeff[i].resize(max_term_up);
        min_order[i].resize(max_term_up);
        min_mretotal[i].resize(max_term_up);
    }

    // printf("flag final two\n");
    fprintf(out_fp1, "Bit Width:, ");
    fprintf(out_fp1, "Partial Mul Starts at:, Fixed Shift Start Value:, Threshold:, ");
    for (int i = 0; i < max_term_up; ++i)
    {
        fprintf(out_fp1, "Coeff %d, ", i);
    }
    for (int i = 0; i < max_term_up; ++i)
    {
        fprintf(out_fp1, "Order %d, ", i);
    }
    for (int i = 0; i < max_term_up; ++i)
    {
        fprintf(out_fp1, "MRE %d, ", i);
    }
    fprintf(out_fp1, "\n");

    for (int j = 0; j < fracWidth.size(); ++j)
    {
        double min_mre_last_term = 10000000000000.0;
        int pm_idx = 0;
        int fs_idx = 0;
        int th_idx = 0;
        for (int i = 0; i < partial_mul_vec.size(); ++i)
        {
            for (int n = 0; n < fixed_shift_vec.size(); ++n)
            {
                for (int k = 0; k < threshold.size(); ++k)
                {
                    // printf("%d, %d, %d, %d\n", j, i, n, k);
                    // printf("%lf\n", final_mre[i][n][j][max_term_up-1][k]);
                    if (min_mre_last_term > final_mre[i][n][j][max_term_up-1][k])
                    {
                        min_mre_last_term = final_mre[i][n][j][max_term_up-1][k];
                        pm_idx = i;
                        fs_idx = n;
                        th_idx = k;
                    }
                }
            }
        }
        

        fprintf(out_fp1, "%llu, ", fracWidth[j]);
        fprintf(out_fp1, "%d, %lf, %lf, ", partial_mul_vec[pm_idx], fixed_shift_vec[fs_idx], threshold[th_idx]);
    
        // printf("flag final three\n");

        // printf("min pm(%d), fs(%d), th(%d)\n", pm_idx, fs_idx, th_idx);

        for (int term = 0; term < max_term_up; ++term)
        {
            min_coeff[j][term] = final_coeff[pm_idx][fs_idx][j][term][th_idx];
            fprintf(out_fp1, "%lf, ", min_coeff[j][term]);
        }

        // printf("flag final four\n");

        for (int term = 0; term < max_term_up; ++term)
        {
            min_order[j][term] = final_order[pm_idx][fs_idx][j][term][th_idx];
            fprintf(out_fp1, "%lf, ", min_order[j][term]);
        }

        // printf("flag final five\n");

        for (int term = 0; term < max_term_up; ++term)
        {
            min_mretotal[j][term] = final_mre[pm_idx][fs_idx][j][term][th_idx];
            fprintf(out_fp1, "%lf, ", min_mretotal[j][term]);
        }

        fprintf(out_fp1, "\n");

    }

    fclose(out_fp1);
    return 0;
}