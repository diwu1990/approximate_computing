#pragma once
#ifndef TRUNCATION_H
#define TRUNCATION_H

#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <random>
using namespace std;

class TRUNCATION
{
    double temp;

    double intPart;
    double fracPart;
    double fracWidth;
    public:
        void Init(uint64_t);
        double Out(double);
};

#endif