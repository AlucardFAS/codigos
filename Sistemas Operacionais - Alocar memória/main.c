#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include "memoria.h"

uint8_t memoria[4096];

int main()
{
    uint8_t *p = aloca(10);
    printf("Alocado: %d\n", p[0]);

}
