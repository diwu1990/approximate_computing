#pragma once
#ifndef EXP_POLY_APPR_H
#define EXP_POLY_APPR_H

#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <random>
#include "poly_appr.hpp"
using namespace std;

class EXP_POLY_APPR
{
    vector<double> coeff;
    vector<double> order;
    uint64_t fracWidth;
    string fixed_sim;
    double threshold;

    uint64_t term_cnt;

    double input;
    double output;
    double mae; // Mean Absolute Error
    double mse; // Mean Square Error
    double mre; // Mean Relative Error
    double wce; // Worst Case Error
    double wcre; // Worst Case Relative Error

    double temp;
    double intPart;
    double fracPart;
    double exp1;

    POLY_APPR poly_appr;

    int totalCnt;
    int N;
    vector<int> weight;

    public:
        void Help();
        void Init(vector<double>, vector<double>, uint64_t, double, string);
        void Report();
        double Out(double);
        void Eval();
        double MAE();
        double MSE();
        double MRE();
        double WCE();
        double WCRE();
};

#endif