#pragma once
#ifndef SHIFTADD_H
#define SHIFTADD_H

#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <random>
#include "truncation.hpp"
using namespace std;

class SHIFTADD
{
    double remainder;
    double input;
    int sign;
    uint64_t fracWidth;
    double output;
    double msb;
    double precision;

    TRUNCATION truncation;

    public:
        void Init(uint64_t);
        double Out(double, double);
};

#endif