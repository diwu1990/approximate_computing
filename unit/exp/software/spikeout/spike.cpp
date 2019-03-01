#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
using std::vector;

#include <math.h>

// void printArray(float * array, FILE * fout, int MAX)
// { 
//      int i;
//      fout = fopen("out.txt","a+");      /* open the file in append mode */
//      for (i=0; i<MAX; i++)
//           fprintf(fout,"%f",*(array+i)); /* write */ 
//      fclose(file);                       /* close the file pointer */ 
//      return 0; 
// };

int main()
{
    float dT, eLeak, vThresh, b, vReset;
    int nSteps;
    nSteps = 10000;
    vector<double> t;
    float V[nSteps] = {NAN}, w[nSteps] = {NAN}, I[nSteps] = {0}, Vfract[nSteps] = {NAN}, Vinput[nSteps] = {NAN};
    int Cm, gL, slopeFac, a, tW, vPeak;
    int stimStart, stimEnd, stimAmplitude, stim2Start, stim2End, stim2Amplitude;
    double fractELeak, intpart, fractVplus1;
    FILE *fp_vfrac, *fp_v, *fp_exp_in;
    fp_vfrac = fopen("vfrac.txt", "w");
    fp_v  = fopen("v.txt", "w");
    fp_exp_in = fopen("exp_in.txt", "w");
    dT = .1;
    Cm = 281;
    gL = 30;
    eLeak = -70.6;
    slopeFac = 2;
    vThresh = -50.4;
    b = 80.5;
    vPeak = 20;
    a = 4;
    tW = 144;
    vReset = eLeak;

    stimStart = 10;
    stimEnd = 200;
    stimAmplitude = 500;
    stim2Start = 500;
    stim2End = 1000;
    stim2Amplitude = 800;
    fractELeak = modf(eLeak, &intpart);
    Vfract[1] = fractELeak;

    V[1] = eLeak;
    Vinput[1] = (V[1] - vThresh )/ (slopeFac);
    w[1] = 0;

    for(int i = 0; i < 10001; i++)
    {
        if ((i >= stimStart) && (i <= stimEnd)){
            I[i] = stimAmplitude;
        }
        if ((i >= stim2Start) && (i <= stim2End)) {
            I[i] = stim2Amplitude;
        }
    }


    for (int i = 1; i < nSteps; i++ ) {
        V[i + 1] = V[i] + (-gL*(V[i]-eLeak)+gL*slopeFac*exp((V[i]-vThresh)/slopeFac)-w[i]+I[i])/Cm*dT;
        Vinput[i +1] = (V[i] - vThresh)/slopeFac;
        fractVplus1 = modf(V[i+1], &intpart);
        Vfract[i + 1] = fractVplus1;
        w[i+1] = w[i] + (a*(V[i]-eLeak)-w[i])/tW*dT;

        if (V[i] >= vPeak) { 
            V[i + 1] = vReset;
            fractVplus1 = modf(vReset, &intpart);
       		Vfract[i + 1] = fractVplus1;
            w[i + 1] = w[i + 1] + b;
            for (int q = 1; q < nSteps; q++) {
                w[q] = w[q] + b;
            }
        }
        if (V[i + 1] >= vPeak) {
            fractVplus1 = modf(vPeak, &intpart);
       		Vfract[i + 1] = fractVplus1;
            V[i + 1] = vPeak;
        }
    }
    for (int k = 0; k < nSteps; k++){
        fprintf(fp_vfrac, "%d,%f\n", k, Vfract[k]);
    }
    fclose(fp_vfrac);
    for (int k = 0; k < nSteps; k++){
        fprintf(fp_v, "%d,%f\n", k, V[k]);
    }
    fclose(fp_v);
    for (int k = 0; k < nSteps; k++){
        fprintf(fp_exp_in, "%d,%f\n", k, Vinput[k]);
    }
    fclose(fp_exp_in);
}
