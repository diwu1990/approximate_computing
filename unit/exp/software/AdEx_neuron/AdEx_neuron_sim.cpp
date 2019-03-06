#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "AdEx_neuron.hpp"
using std::vector;



int main()
{
    int nSteps = 2000;
    double membrane_potential[nSteps], adaptive_term[nSteps], spiking[nSteps];

    FILE *fp;

    // neuron config
    // Vector of Neuron Parameters: {Cm, gL, eLeak, vThresh, slopeFac, a, tW, b, vReset, iCurrent, vPeak, dT}
    // // tonic spiking
    // fp = fopen("neuron_spiking_out_tonic_spiking_fixed_exp.txt", "w+");
    // fp = fopen("neuron_spiking_out_tonic_spiking_precise_mul.txt", "w+");
    // fp = fopen("neuron_spiking_out_tonic_spiking_appr_mul_049.txt", "w+");
    // fp = fopen("neuron_spiking_out_tonic_spiking_appr_mul_061.txt", "w+");
    // fp = fopen("neuron_spiking_out_tonic_spiking_appr_mul_034.txt", "w+");
    fp = fopen("neuron_spiking_out_tonic_spiking_float.txt", "w+");
    vector<double> neuron_param = {200, 10, -70, -50, 2,   2,  30,   0, -58, 500, 0, 0.1};
    // // inital burst
    // fp = fopen("neuron_spiking_out_initial_burst_fixed_exp.txt", "w+");
    // fp = fopen("neuron_spiking_out_initial_burst_precise_mul.txt", "w+");
    // fp = fopen("neuron_spiking_out_initial_burst_appr_mul_049.txt", "w+");
    // fp = fopen("neuron_spiking_out_initial_burst_appr_mul_061.txt", "w+");
    // fp = fopen("neuron_spiking_out_initial_burst_appr_mul_034.txt", "w+");
    // fp = fopen("neuron_spiking_out_initial_burst_float.txt", "w+");
    // vector<double> neuron_param = {130, 18, -58, -50, 2,   4, 150, 120, -58, 400, 0, 0.1};
    // // regular bursting
    // fp = fopen("neuron_spiking_out_regular_bursting_fixed_exp.txt", "w+");
    // fp = fopen("neuron_spiking_out_regular_bursting_precise_mul.txt", "w+");
    // fp = fopen("neuron_spiking_out_regular_bursting_appr_mul_049.txt", "w+");
    // fp = fopen("neuron_spiking_out_regular_bursting_appr_mul_061.txt", "w+");
    // fp = fopen("neuron_spiking_out_regular_bursting_appr_mul_034.txt", "w+");
    // fp = fopen("neuron_spiking_out_regular_bursting_float.txt", "w+");
    // vector<double> neuron_param = {200, 10, -58, -50, 2,   2, 120, 100, -46, 210, 0, 0.1};
    // // delayed accelerating
    // fp = fopen("neuron_spiking_out_delayed_accelerating_fixed_exp.txt", "w+");
    // fp = fopen("neuron_spiking_out_delayed_accelerating_precise_mul.txt", "w+");
    // fp = fopen("neuron_spiking_out_delayed_accelerating_appr_mul_049.txt", "w+");
    // fp = fopen("neuron_spiking_out_delayed_accelerating_appr_mul_061.txt", "w+");
    // fp = fopen("neuron_spiking_out_delayed_accelerating_appr_mul_034.txt", "w+");
    // fp = fopen("neuron_spiking_out_delayed_accelerating_float.txt", "w+");
    // vector<double> neuron_param = {200, 12, -70, -50, 2, -10, 300,   0, -58, 300, 0, 0.1};

    membrane_potential[0] = neuron_param[2];
    adaptive_term[0] = 0;
    spiking[0] = 0;

    // membrane_potential[0] = -54.2989120000000;
    // adaptive_term[0] = 0.0609010000000000;

    // exp config
    uint64_t fracWidth = 31;
    string fixed_sim;
    // fixed_sim = "fixed";
    fixed_sim = "float";
    double threshold;
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // uniform 16 bit
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    threshold = 0.75;
    vector<double> coeff = {1,   1,   0.5, 0.125,   0.0625,  0.03125, 0.015625};
    vector<double> order = {0,   1,     2,     3,        4,        4,        4};

    ADEX_NEURON neuron;
    neuron.Init(neuron_param, coeff, order, fracWidth, threshold, fixed_sim);

    for (int i = 0; i < nSteps-1; i++ ) {
        neuron.Calc(membrane_potential[i],adaptive_term[i]);
        // printf("checkpoint: %6d\n", i);
        membrane_potential[i+1] = neuron.oV();
        adaptive_term[i+1] = neuron.oW();
        spiking[i+1] = neuron.oS();
    }
    for (int k = 0; k < nSteps; k++){
        fprintf(fp, "%d,%f,%f,%f\n", k, membrane_potential[k], adaptive_term[k], spiking[k]);
    }
    fclose(fp);
}