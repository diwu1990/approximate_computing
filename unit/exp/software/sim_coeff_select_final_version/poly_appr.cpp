#include "poly_appr.hpp"

void POLY_APPR::Init(vector<double> param1, vector<double> param2, uint64_t param3, string param4)
{
    coeff = param1;
    order = param2;
    fracWidth = param3;
    fixed_sim = param4;
    if (fixed_sim != "fixed" && fixed_sim != "float")
    {
        printf("Error: Operating mode is invalid, and should be \"fixed\" or \"float\".\n");
    }
    input = 0;
    output = 0;
    term_cnt = coeff.size();
    if(term_cnt != order.size())
    {
        printf("Error: Coefficient (length %lu) and order (length %lu) does not match in size.\n", coeff.size(), order.size());
    }
    else
    {
        // no negative order
        for (int i = 0; i < term_cnt; ++i)
        {
            if (order[i] < 0)
            {
                printf("Error: Negative order.\n");
                break;
            }
        }
        // no inverse-magnitue order
        for (int i = 0; i < term_cnt-1; ++i)
        {
            if (order[i] != order[i+1] && order[i]+1 != order[i+1])
            {
                printf("Error: Current order is neither equal to (later order) nor (later order - 1).\n");
                break;
            }
        }
        // single zero order
        int one_zero = 0;
        for (int i = 0; i < term_cnt; ++i)
        {
            if (order[i] == 0 && one_zero == 0)
            {
                one_zero = 1;
            }
            else if (order[i] == 0 && one_zero == 1)
            {
                // check constant, only one zero-order (constant) is allowed.
                printf("Error: Two zero-order terms.\n");
                break;
            }
        }
        for (int i = 0; i < term_cnt; ++i)
        {
            if (abs(coeff[i]) > 1)
            {
                printf("Caution: Coefficient larger than 1 may lead to overflow with 32 bit fraction width.\n");
                break;
            }
        }
    }
    prod = 0;
    shift = 0;
    shift_temp = 0;
    truncation.Init(fracWidth);
}

void POLY_APPR::Report()
{
    printf("Current POLY_APPR:\n");
    std::cout << "Instance Mode:          " << fixed_sim << std::endl;
    printf("Number of Term:         %-5llu\n", term_cnt);
    printf("Operand Fraction Width: %-5llu\n", fracWidth);
}

void POLY_APPR::Help()
{
    printf("**********************************************************\n");
    printf("**********************************************************\n");
    printf("\nCalling POLY_APPR Help. Following are instructions to POLY_APPR Instance Usage:\n");
    printf("\n1. inst.Init() method:\n");
    printf("Configure the POLY_APPR inst.\n");
    printf("Parameters: Vector of Coefficients, Vector of Orders, Data Fraction Width, Operating Mode\n");

    printf("\n2. inst.Report() method:\n");
    printf("Report Instance Configuration.\n");

    printf("\n3. inst.Out() method:\n");
    printf("Return the output for given input to method Inst.Out().\n\n");
    printf("**********************************************************\n");
    printf("**********************************************************\n");
}

double POLY_APPR::Out(double param1)
{
    input = param1;
    output = 0;
    if (fixed_sim == "fixed")
    {
        // fixed point caculation with dedicated architecture
        
        if (order[0] == 0)
        {
            // constant equals to the coeff
            prod = coeff[0];
        }
        else
        {
            // 1st order equals to the shift of input
            // get the fixed point value via truncation
            prod = truncation.Out(input * coeff[0]);
        }
        
        // use mul_appr to calculate high order
        if (order[0] > 1)
        {
            for (int i = 0; i < order[0]-1; ++i)
            {
                prod = mul_fixed.Out(input,prod,fracWidth);
            }
        }

        shift_temp = truncation.Out(prod * abs(coeff[1] / coeff[0]));
        if (coeff[1] * coeff[0] >= 0)
        {
            shift = shift_temp;
        }
        else
        {
            shift = 0 - shift_temp;
        }

        for (int i = 1; i < term_cnt; ++i)
        {
            output += prod;
            // printf("i=%d: sum(%lf), prod(%lf), shift(%lf).\n", i, output, prod, shift);
            if (i == 1 && order[0] == 0)
            {
                prod = truncation.Out(input * coeff[1]);
            }
            else if (order[i-1] == order[i])
            {
                prod = shift;
            }
            else
            {
                // all the internel multiplication has the format of {2-bit.fracWidth-bit}
                prod = mul_fixed.Out(input,shift,fracWidth);
            }

            if (i < term_cnt-1)
            {
                shift_temp = truncation.Out(prod * abs(coeff[i+1] / coeff[i]));
                if (coeff[i+1] * coeff[i] >= 0)
                {
                    shift = shift_temp;
                }
                else
                {
                    shift = 0 - shift_temp;
                }
            }
        }
        output += prod;
        // printf("%.10lf\n", output);
    }
    else
    {

        // // floating point calculation for poly
        // for (int i = 0; i < term_cnt; ++i)
        // {
        //     output += coeff[i] * pow(input, order[i]);
        //     // printf("%.15lf ", output);
        // }

        // floating point caculation with dedicated architecture

        if (order[0] == 0)
        {
            // constant equals to the coeff
            prod = coeff[0];
        }
        else
        {
            // 1st order equals to the shift of input
            // get the fixed point value via truncation
            prod = input * coeff[0];
        }
        
        // use mul_appr to calculate high order
        if (order[0] > 1)
        {
            for (int i = 0; i < order[0]-1; ++i)
            {
                prod *= input;
            }
        }

        // shift is the shifted value of the current prod
        shift_temp = prod * abs(coeff[1] / coeff[0]);
        if (coeff[1] * coeff[0] >= 0)
        {
            shift = shift_temp;
        }
        else
        {
            shift = 0 - shift_temp;
        }
        // printf("%lf, %lf\n", prod, shift);

        for (int i = 1; i < term_cnt; ++i)
        {
            output += prod;
            // printf("i=%d: sum(%lf), prod(%lf), shift(%lf).\n", i, output, prod, shift);
            if (i == 1 && order[0] == 0)
            {
                prod = input * coeff[1];
            }
            else if (order[i-1] == order[i])
            {
                prod = shift;
            }
            else
            {
                prod = input*shift;
            }

            if (i < term_cnt-1)
            {
                shift_temp = prod * abs(coeff[i+1] / coeff[i]);
                if (coeff[i+1] * coeff[i] >= 0)
                {
                    shift = shift_temp;
                }
                else
                {
                    shift = 0 - shift_temp;
                }
            }
        }
        output += prod;
        // printf("%.10lf\n", output);
    }
    
    return output;
}

