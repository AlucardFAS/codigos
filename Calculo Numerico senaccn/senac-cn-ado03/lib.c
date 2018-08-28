#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <math.h>

void float()
{
    FILE *fp = popen("gnuplot -persistent", "w");
    fprintf(fp, "set terminal png\n");
    fprintf(fp, "set output 'euler_flt.png'\n");
    fprintf(fp, "set logscale x\n");
    fprintf(fp, "plot '-' w l\n");
    
    float euler, x;
    euler = 0.0;
    int i;

    for(i = 0; i < 20; i++)
    {
        x = powf(10, i);
        euler = powf((1 + 1 / x), x);
        fprintf(fp, "%f %f\n", x, euler);
    }
    fprintf(fp, "e");
    pclose(fp);
}

void double()
{
    FILE *fp = popen("gnuplot -persistent", "w");
    fprintf(fp, "set terminal png\n");
    fprintf(fp, "set output 'euler_dbl.png'\n");
    fprintf(fp, "set logscale x\n");
    fprintf(fp, "plot '-' w l\n");
    
    double euler,y;
    euler=0.0;
    int i;

    for(i = 1; i <= 20; i++)
    {
        y = pow(10, i);
        euler = pow((1 + 1 / y), y);
        fprintf(fp, "%lf %lf\n", y, euler);
    }
    fprintf(fp, "e");
    pclose(fp);
}

void long()
{
    FILE *fp = popen("gnuplot -persistent", "w");
    fprintf(fp, "set terminal png\n");
    fprintf(fp, "set output 'euler_ldbl.png'\n");
    fprintf(fp, "set logscale x\n");
    fprintf(fp, "plot '-' w l\n");
    
    long double euler,z;
    euler = 0.0;
    int i;

    for(i = 1; i <= 20; i++) //float
    {
        z = powl(10, i);
        euler = powl((1 + 1 / z), z);
        fprintf(fp, "%LF %LF\n", z, euler);
    }
    fprintf(fp, "e");
    pclose(fp);
}