#pragma once
#ifndef EXP_ERROR_MODEL_H
#define EXP_ERROR_MODEL_H

#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <random>
#include "truncation.hpp"
using namespace std;

class EXP_ERROR_MODEL
{
    vector<double> coeff;
    vector<double> order;
    uint64_t fracWidth;
    string fixed_sim;
    double threshold;
    double in;
    double orig;

    uint64_t totalCnt;
    uint64_t term_cnt;
    double iWMRE; // input Mean Relative Error of MUL
    double oWMRE; // output Mean Relative Error of exp
    double appr_neg;
    double appr_pos;

    double err_neg;
    double err_pos;
    double bypass_order;

    TRUNCATION truncation;

    public:
        void Init(vector<double>, vector<double>, uint64_t, double);
        void Eval(double);
        double OWMRE();
};

#endif