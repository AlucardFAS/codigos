#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <locale.h>


#define TAM_MEMORIA 4096

typedef enum { false, true } bool;

uint8_t memoria[TAM_MEMORIA];

void* aloca(unsigned int t)
{
    void* vl;
    int endereco = posicao(sizeof(t));
    printf("Encontrado espaço de x[%d] até x[%d](valor em bytes)\n", endereco,endereco+sizeof(t));
    //void* vl = &memoria[endereco+1];
    //*(uint8_t*) vl = t;



    return vl;
}

int posicao(int tamanho)
{
    bool confirma = false;
    int count = 0, save_pos = 0, memoria_salva = 0, espaco = 0, guarda_memoria = 0;

    while(confirma != true)
    {
        if(count >= TAM_MEMORIA - 1)
        {
            printf("Erro: Sem espaço na memória\n");
            confirma = true;
            return -1;
        }
        else if(espaco == tamanho)
        {
            memoria[guarda_memoria] = tamanho + 1;
            return guarda_memoria;
        }
        else if(memoria[count] != 0)
        {
            count += memoria[count];
            guarda_memoria = count;
            espaco = 0;
        }
        else
        {
            count++;
            espaco++;
        }
    }
    return 0;
}
//void libera(void*)

void print_memoria();

int main()
{
    uint8_t *p = aloca(10);
    uint8_t *t = aloca(12);
    uint8_t *j = aloca(50);
    print_memoria();

    return 0;
}

void print_memoria()
{
    printf("\n\n");
    for(int i=0; i<TAM_MEMORIA; i++)
    {
        printf("[%d] ", memoria[i]);
    }
    printf("\n\n");
}
