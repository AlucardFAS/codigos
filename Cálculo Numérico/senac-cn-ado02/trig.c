#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <math.h>

int main() 
{
    FILE *op;
    op = fopen("seno.dat", "w");
    op = fopen("seno.dat", "a");   
	
    int i = 0;
	for(i=0; i<=720; i++)
    {
        double radianos=i*(PI/180);
        double absoluto=fabs(sin(radianos)-seno(radianos));
        double relativo=fabs(absoluto/seno(radianos));
        
		fprintf(op, "%d\t%f\t%f\t%f\n", i,seno(radianos),absoluto,relativo);
    }
    fclose(op);

    op = fopen("cosseno.dat", "w");
    op = fopen("cosseno.dat", "a");
    for(i=0; i<=720; i++)
    {
        double radianos=i*(PI/180);
        double absoluto=fabs(sin(radianos)-cosseno(radianos));
        double relativo=fabs(absoluto/cosseno(radianos));

		fprintf(op, "%d\t%f\t%f\t%f\n", i,cosseno(radianos),absoluto,relativo);
    }

    fclose(op);
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    fprintf(gnuplot, "%s\n%s", "set terminal png size 400,300\nset output 'seno.png'", "plot 'seno.dat'\n");
    fprintf(gnuplot, "%s\n%s", "set terminal png size 400,300\nset output 'cosseno.png'", "plot 'cosseno.dat'");
    exit(0);
}
