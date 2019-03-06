#include "truncation.hpp"

void TRUNCATION::Init(uint64_t param1)
{
    fracWidth = param1;
}

double TRUNCATION::Out(double param1)
{
    temp = param1 * pow(2, fracWidth);
    fracPart = modf(temp, &intPart);

    return intPart / pow(2, fracWidth);
}

            
            

