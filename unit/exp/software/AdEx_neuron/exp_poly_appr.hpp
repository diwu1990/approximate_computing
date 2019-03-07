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
#include "truncation.hpp"
#include "mul_fixed.hpp"
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

    double exp1;

    POLY_APPR poly_appr;
    TRUNCATION truncation;
    MUL_FIXED mul_fixed;

    public:
        void Help();
        void Init(vector<double>, vector<double>, uint64_t, double, string);
        void Report();
        double Out(double);
};

#endif