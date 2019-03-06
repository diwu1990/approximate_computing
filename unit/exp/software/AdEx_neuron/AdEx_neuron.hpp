#pragma once
#ifndef ADEX_NEURON_H
#define ADEX_NEURON_H

#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <random>
#include "exp_poly_appr.hpp"
#include "truncation.hpp"
#include "shiftadd.hpp"
using namespace std;

class ADEX_NEURON
{
    vector<double> coeff;
    vector<double> order;
    uint64_t fracWidth;
    string fixed_sim;
    double threshold;

    double iVoltage;
    double oVoltage;
    double iAdapt;
    double oAdapt;
    double oSpike;

    double Cm;
    double gL;
    double eLeak;
    double vThresh;
    double slopeFac;
    double a;
    double tW;
    double b;
    double vReset;
    double vPeak;
    double iCurrent;
    double dT;

    EXP_POLY_APPR exp_poly_appr;
    TRUNCATION truncation;
    SHIFTADD shiftadd;

    public:
        void Help();
        void Init(vector<double>, vector<double>, vector<double>, uint64_t, double, string);
        void Calc(double, double);
        double oV();
        double oW();
        double oS();
};

#endif