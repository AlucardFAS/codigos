#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char *argv[]) 
{
    if(argc != 4)
    {
        printf("Numero de argumentos invalidos\n");
        exit(1);
    }

    char alfabeto[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char* enterValue = argv[1];
    int baseN = atoi(argv[2]);
    int baseM = atoi(argv[3]);

    long int limit = MakePow(2, 32);
    long int valueInDecimal = converte10(enterValue, baseN);

    if(valueInDecimal == 0)
    {
        printf("0\n");
        exit(0);
    }
    if(valueInDecimal < 0 || valueInDecimal > limit)
    {
        exit(1);
    }
    if(baseN < 2 || baseN > 36)
    {
        exit(1);
    }
    if(baseM < 2 || baseM > 36)
    {
        exit(1);
    }
    printf("%s\n", ConvertToBaseM(valueInDecimal, baseM, alfabeto));
    exit(0);
}
