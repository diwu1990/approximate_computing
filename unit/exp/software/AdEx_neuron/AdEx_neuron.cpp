#include "AdEx_neuron.hpp"

void ADEX_NEURON::Init(vector<double> param0, vector<double> param1, vector<double> param2, uint64_t param3, double param4, string param5)
{
    if (param0.size() != 12)
    {
        printf("Error: The number of Neuron Parameters is wrong. (Expected: 12; Actual: %lu)\n", param0.size());
    }
    Cm = param0[0];
    gL = param0[1];
    eLeak = param0[2];
    vThresh = param0[3];
    slopeFac = param0[4];
    a = param0[5];
    tW = param0[6];
    b = param0[7];
    vReset = param0[8];
    iCurrent = param0[9];
    vPeak = param0[10];
    dT = param0[11];

    coeff = param1;
    order = param2;
    fracWidth = param3;
    threshold = param4;
    fixed_sim = param5;

    iVoltage = 0;
    oVoltage = 0;
    iAdapt = 0;
    oAdapt = 0;
    oSpike = 0;

    exp_poly_appr.Init(coeff, order, fracWidth, threshold, fixed_sim);
    truncation.Init(fracWidth);
    shiftadd.Init(fracWidth);

}

void ADEX_NEURON::Help()
{
    printf("**********************************************************\n");
    printf("**********************************************************\n");
    printf("\nCalling ADEX_NEURON Help. Following are instructions to ADEX_NEURON Instance Usage:\n");
    printf("\n1. inst.Init() method:\n");
    printf("Configure the ADEX_NEURON inst.\n");
    printf("Parameters: Vector of Neuron Parameters, Vector of Coefficients, Vector of Orders, Data Fraction Width, Operating Mode\n");
    printf("Vector of Neuron Parameters: Cm, gL, eLeak, vThresh, slopeFac, a, tW, b, vReset, vPeak, iCurrent, dT\n");

    printf("\n2. inst.Out() method:\n");
    printf("Return the output for given input to method Inst.Out().\n\n");
    printf("**********************************************************\n");
    printf("**********************************************************\n");
}

void ADEX_NEURON::Calc(double param1, double param2)
{
    iVoltage = param1;
    iAdapt = param2;
    oSpike = 0;

    if (fixed_sim == "fixed")
    {

        double iAdapt_fxp = truncation.Out(iAdapt);
        
        double iVoltage_fxp = truncation.Out(iVoltage);
        
        double vThresh_fxp = truncation.Out(vThresh);

        double iCurrent_fxp = truncation.Out(iCurrent);

        double b_fxp = truncation.Out(b);
        
        double vReset_fxp = truncation.Out(vReset);
        
        double eLeak_fxp = truncation.Out(eLeak);
        
        double vPeak_fxp = truncation.Out(vPeak);

        double exp_in = truncation.Out(truncation.Out(iVoltage_fxp-vThresh_fxp)/slopeFac);

        double exp_in_frac;

        double exp_in_int;

        exp_in_frac = modf(exp_in, &exp_in_int);

        if (exp_in_frac < 0)
        {
            exp_in_frac++;
            exp_in_int--;
        }

        double expout = truncation.Out(exp_poly_appr.Out(exp_in_frac) * truncation.Out(exp(exp_in_int)));
        // double expout = truncation.Out(exp(exp_in));

        double gLslopeFacexp = shiftadd.Out(truncation.Out(gL*slopeFac), expout);

        double iVoltageeLeak = truncation.Out(iVoltage_fxp - eLeak_fxp);

        double gLiVoltageeLeak = shiftadd.Out(gL, iVoltageeLeak);

        double gLslopeFacexp_gLiVoltageeLeak = truncation.Out(gLslopeFacexp - gLiVoltageeLeak);

        double iCurrentiAdapt = truncation.Out(iCurrent_fxp - iAdapt_fxp);

        double gLslopeFacexp_gLiVoltageeLeak_iCurrentiAdapt = truncation.Out(gLslopeFacexp_gLiVoltageeLeak + iCurrentiAdapt);

        double dTCm_gLslopeFacexp_gLiVoltageeLeak_iCurrentiAdapt = shiftadd.Out(dT/Cm, gLslopeFacexp_gLiVoltageeLeak_iCurrentiAdapt);

        // output voltage
        oVoltage = truncation.Out(dTCm_gLslopeFacexp_gLiVoltageeLeak_iCurrentiAdapt + iVoltage_fxp);

        // output adaptive term
        double aiVoltageeLeak = shiftadd.Out(a, iVoltageeLeak);

        double aiVoltageeLeak_iAdapt = truncation.Out(aiVoltageeLeak - iAdapt_fxp);

        double dTtW_aiVoltageeLeak_iAdapt = shiftadd.Out(dT/tW, aiVoltageeLeak_iAdapt);

        oAdapt = truncation.Out(dTtW_aiVoltageeLeak_iAdapt + iAdapt_fxp);

        if (iVoltage_fxp >= vPeak_fxp)
        {
            oVoltage = vReset_fxp;
            oAdapt = truncation.Out((oAdapt + b_fxp));
        }
        if (oVoltage >= vPeak_fxp)
        {
            oVoltage = vPeak_fxp;
            oSpike = 1;
        }

        // printf("iAdapt_fxp %lf\n", iAdapt_fxp);
        // printf("iVoltage_fxp %lf\n", iVoltage_fxp);
        // printf("vThresh_fxp %lf\n", vThresh_fxp);
        // printf("iCurrent_fxp %lf\n", iCurrent_fxp);
        // printf("b_fxp %lf\n", b_fxp);
        // printf("vReset_fxp %lf\n", vReset_fxp);
        // printf("eLeak_fxp %lf\n", eLeak_fxp);
        // printf("vPeak_fxp %lf\n", vPeak_fxp);
        // printf("exp_in %lf\n", exp_in);
        // printf("expout %lf\n", expout);
        // printf("gLslopeFacexp %lf\n", gLslopeFacexp);
        // printf("iVoltageeLeak %lf\n", iVoltageeLeak);
        // printf("gLiVoltageeLeak %lf\n", gLiVoltageeLeak);
        // printf("gLslopeFacexp_gLiVoltageeLeak %lf\n", gLslopeFacexp_gLiVoltageeLeak);
        // printf("iCurrentiAdapt %lf\n", iCurrentiAdapt);
        // printf("gLslopeFacexp_gLiVoltageeLeak_iCurrentiAdapt %lf\n", gLslopeFacexp_gLiVoltageeLeak_iCurrentiAdapt);
        // printf("dTCm_gLslopeFacexp_gLiVoltageeLeak_iCurrentiAdapt %lf\n", dTCm_gLslopeFacexp_gLiVoltageeLeak_iCurrentiAdapt);
        // printf("======================\n");
        // printf("aiVoltageeLeak %lf\n", aiVoltageeLeak);
        // printf("aiVoltageeLeak_iAdapt %lf\n", aiVoltageeLeak_iAdapt);
        // printf("dTtW_aiVoltageeLeak_iAdapt %lf\n", dTtW_aiVoltageeLeak_iAdapt);
        // printf("oVoltage %lf\n", oVoltage);
        // printf("oAdapt %lf\n", oAdapt);

    }
    else
    {
        oVoltage = iVoltage + (-gL * (iVoltage - eLeak) + gL*slopeFac*exp((iVoltage-vThresh)/slopeFac)-iAdapt+iCurrent)/Cm*dT;
        oAdapt = iAdapt + (a*(iVoltage - eLeak)-iAdapt)/tW*dT;


        
        if (iVoltage >= vPeak)
        {
            oVoltage = vReset;
            oAdapt = oAdapt + b;
        }
        if (oVoltage >= vPeak)
        {
            oVoltage = vPeak;
            oSpike = 1;
        }
        // printf("======================\n");
        // printf("aiVoltageeLeak %f\n", a*(iVoltage - eLeak));
        // printf("aiVoltageeLeak_iAdapt %f\n", (a*(iVoltage - eLeak)-iAdapt));
        // printf("dTtW_aiVoltageeLeak_iAdapt %f\n", (a*(iVoltage - eLeak)-iAdapt)/tW*dT);
        // printf("oVoltage %f\n", oVoltage);
        // printf("oAdapt %f\n", oAdapt);
    }
}

double ADEX_NEURON::oV()
{
    return oVoltage;
}

double ADEX_NEURON::oW()
{
    return oAdapt;
}

double ADEX_NEURON::oS()
{
    return oSpike;
}