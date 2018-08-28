#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

double seno(double valor)
{
    int i = 0;
    double result = 0;
    
    for(i=0; i<16; i++)
    {
        result+=(MakePow(-1,i)*MakePow(valor,2*i+1))/fat(2*i+1);
    }

    return result;
}

double cosseno(double valor)
{
    double result=0;
    int i=0;
    
    for(i=0;i<16;i++)
    {
        result+=(MakePow(-1,i)*MakePow(valor,2*i))/fat(2*i);
    }

    return result;
}

double MakePow(double x, double y)
{
    int i=0;
    double novoValor=1;
    while(i<y)
    {
        novoValor*=x;
        i++;
    }

    return novoValor;
}

double fat(int x)
{
    int atual=x;
    double result=1;

    while(atual > 0)
    {
        result*=atual;
        atual--;
    }

    return result;
}
