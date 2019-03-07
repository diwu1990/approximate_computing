#pragma once
#ifndef POLY_APPR_H
#define POLY_APPR_H

#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include "mul_fixed.hpp"
using namespace std;

class POLY_APPR
{
    vector<double> coeff;
    vector<double> order;
    uint64_t fracWidth;
    string fixed_sim;

    uint64_t term_cnt;

    double input;
    double output;

    double prod;
    double shift;
    double shift_temp;
    double temp;
    double intPart;
    double fracPart;

    MUL_FIXED mul_fixed;

    public:
        void Help();
        void Init(vector<double>, vector<double>, uint64_t, string);
        void Report();
        double Out(double);
};

#endif