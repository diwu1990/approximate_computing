#include "exp_error_model.hpp"

void EXP_ERROR_MODEL::Init(vector<double> param1, vector<double> param2, uint64_t param3, double param4)
{
    coeff = param1;
    order = param2;
    fracWidth = param3;
    threshold = param4;
    iWMRE = 0;
    fixed_sim = "fixed";
    term_cnt = coeff.size();
    if (term_cnt != order.size())
    {
        printf("Error: Input dimension does not match.\n");
    }
    totalCnt = 1UL<<fracWidth;
    oWMRE = 0;
    truncation.Init(fracWidth);
}

void EXP_ERROR_MODEL::Eval(double param1)
{
    iWMRE = param1;
    err_pos = 0;
    err_neg = 0;
    for (int i = 0; i < totalCnt; ++i)
    {
        in = (double)(i/pow(2,fracWidth)) - (1 - threshold);
        orig = exp(in);

        appr_pos = 1 + truncation.Out(in);
        appr_neg = appr_pos;
        bypass_order = 0;

        for (int j = 2; j < term_cnt; ++j)
        {
            if (order[j] == (order[j-1] + 1))
            {
                if (coeff[j] >= 0)
                {
                    appr_pos += truncation.Out(coeff[j] * pow(in, order[j])) * pow(1+iWMRE, order[j]-1);
                    appr_neg += truncation.Out(coeff[j] * pow(in, order[j])) * pow(1-iWMRE, order[j]-1);
                }
                else
                {
                    appr_pos += truncation.Out(coeff[j] * pow(in, order[j])) * pow(1-iWMRE, order[j]-1);
                    appr_neg += truncation.Out(coeff[j] * pow(in, order[j])) * pow(1+iWMRE, order[j]-1);
                }
                bypass_order = order[j]-1;
            }
            else
            {
                if (coeff[j] >= 0)
                {
                    appr_pos += truncation.Out(coeff[j] * pow(in, order[j])) * pow(1+iWMRE, bypass_order);
                    appr_neg += truncation.Out(coeff[j] * pow(in, order[j])) * pow(1-iWMRE, bypass_order);
                }
                else
                {
                    appr_pos += truncation.Out(coeff[j] * pow(in, order[j])) * pow(1-iWMRE, bypass_order);
                    appr_neg += truncation.Out(coeff[j] * pow(in, order[j])) * pow(1+iWMRE, bypass_order);
                }
            }
        }
        if (in < 0)
        {
            appr_pos *= (1+iWMRE);
            appr_neg *= (1-iWMRE);
        }
        // printf("in: %.6f, appr_pos: %.6f, appr_neg: %.6f, err_pos: %.6f, err_neg: %.6f\n", in, appr_pos, appr_neg, abs((appr_pos - orig)/orig), abs((appr_neg - orig)/orig));
        err_pos += abs((appr_pos - orig)/orig);
        err_neg += abs((appr_neg - orig)/orig);
    }
    err_pos /= totalCnt;
    err_neg /= totalCnt;
    oWMRE = max(err_pos, err_neg);
}

double EXP_ERROR_MODEL::OWMRE()
{
    return oWMRE;
}
