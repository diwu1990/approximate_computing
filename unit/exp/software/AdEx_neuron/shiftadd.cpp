#include "shiftadd.hpp"

void SHIFTADD::Init(uint64_t param1)
{
    fracWidth = param1;
    truncation.Init(fracWidth);
}

double SHIFTADD::Out(double param1, double param2)
{
    remainder = param1;
    input = truncation.Out(param2);
    if (remainder < 0)
    {
        sign = -1;
    }
    else
    {
        sign = 1;
    }
    remainder = abs(remainder);
    output = 0;
    msb = floor(log2(remainder));

    precision = 1/pow(2,(double)fracWidth);

    while (remainder >= precision)
    {
        // printf("working!\n");
        if (remainder >= pow(2, msb))
        {
            output += truncation.Out((input * pow(2, msb)));
            output = truncation.Out(output);
            remainder = remainder - pow(2, msb);
        }
        // printf("%lf\n", output);
        msb--;
    }

    return output*sign;
}
