#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

int para10(char c) 
{
    if (c >= '0' && c <= '9')
        return (int) c - '0';
    else 
        return (int) c - 'A' + 10;
}

long int converte10(char *NumberToConvert, int currentBase) 
{
    long int i = 0, decimalValue = 0, toConvert = strlen(NumberToConvert);
    for (i = 0; i < toConvert; i++)
        decimalValue += para10(NumberToConvert[toConvert - 1 - i]) * MakePow(currentBase, i);

    return decimalValue;
}

char *ConvertToBaseM(long int decimalValue, int newBase, char alphabet[])
{
    long int newValue = decimalValue;

    char *newString = (char*) calloc(1000, 1000 * sizeof(char));

    int i = 0;
    while(newValue > 0)
    {
        int rest = newValue % newBase;
        newValue /= newBase;
        newString[i] = alphabet[rest];
        i++;
    }
    int j = 0;
    int sizeStr = strlen(newString);
    char *outValue = (char*) calloc(sizeStr, sizeStr * sizeof(char));
    for(j = 0; j < sizeStr; j++)
    {
        outValue[j] = newString[sizeStr- (j+1)];
    }

    return outValue;
}

long int MakePow(int a, int b)
{
    int i = 0;
    long int newValue = 1;
    while(i < b)
    {
        newValue *= a;
        i++;
    }

    return newValue;
}
