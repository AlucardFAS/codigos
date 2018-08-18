#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include "main.c"
#include "memoria.h"

void* aloca(unsigned int t)
{
    void* vl = &memoria[0];
    *(uint8_t*) vl = t;

    return vl;
}

//void libera(void*)

