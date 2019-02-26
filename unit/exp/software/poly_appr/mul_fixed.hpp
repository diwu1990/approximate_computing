#pragma once
#ifndef MUL_FIXED_H
#define MUL_FIXED_H

#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

class MUL_FIXED
{
    double a;
    double a_int;
    double a_frac;
    double b;
    double b_int;
    double b_frac;
    uint64_t fracWidth;
    double c;
    double c_int;
    double c_frac;

    public:
        double Out(double, double, uint64_t);
};

#endif