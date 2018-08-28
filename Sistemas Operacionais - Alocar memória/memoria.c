/*
Made by AlucardFAS
Made in Code::Blocks 17.12
Debugger: GDB/CDB Debugger
Compiler: GNU GCC Compiler || mingw32-gcc
*/

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
    //busca o endere�o em que t deve  ser guardado
    int endereco = posicao(t);

    //se t for encontrado, demonstra o local
    if(endereco != -1)
    {
        printf("Encontrado espa�o de x[%d] at� x[%d] para o valor de %d Bytes. Utilizados %d Bytes para o armazenamento.\n", endereco,endereco+t,memoria[endereco]-1,memoria[endereco]);
    }

    return endereco;
}

int posicao(int tamanho)
{
    //inicializa vari�veis necess�rias para teste
    bool confirma = false;
    int count = 0, save_pos = 0, memoria_salva = 0, espaco = 0, guarda_memoria = 0;

    //checa se a mem�ria esta dentro dos limites de TAM_MEMORIA
    if(tamanho >= TAM_MEMORIA || tamanho < 0)
    {
        printf("Erro: Entrada inadequada.\n");
        return -1;
    }

    //la�o para encontrar a posi��o
    while(confirma != true)
    {
        //verifica se o contador do la�o j� alcan�ou a ultima posi��o ou se o contador somado ao tamanho almejado estouram o limite de mem�ria
        if(count >= TAM_MEMORIA - 1 || count + tamanho >= TAM_MEMORIA)
        {
            printf("Erro: Sem espa�o na mem�ria\n");
            confirma = true;
            return -1;
        }
        //Checa se o espa�o buscado foi encontrado, guarda o tamanho deste espa�o como cabe�alho na mem�ria e retorna
        else if(espaco == tamanho)
        {
            memoria[guarda_memoria] = tamanho + 1;
            return guarda_memoria;
        }
        //se encontrar mem�ria alocada, pula para outra �rea de acordo com cabe�alho
        else if(memoria[count] != 0)
        {
            count += memoria[count];
            guarda_memoria = count;
            espaco = 0;
        }
        //aumenta o contador e a quantidade de espa�os n�o alocados encontrados
        else
        {
            count++;
            espaco++;
        }
    }
}

void libera(void* valor)
{
    //em caso de uma vari�vel n�o alocada na mem�ria ser recebida
    if(valor < 0 || valor > 4096)
    {
        printf("A vari�vel solicitada n�o est� alocada.\n");
        return -1;
    }

    //Converte ponteiro para int
    int valor_int = (int *)valor;

    int fim_memoria = memoria[valor_int];

    //itera o espa�o alocado e zera
    for(int i = valor_int; i < valor_int + fim_memoria; i++)
    {
        memoria[i] = 0;
    }

    printf("Espa�o iniciado em x[%d] e terminado em x[%d] liberado!\n", valor_int, valor_int + fim_memoria);
    return 0;
}

void print_memoria();

int main()
{
    //Aceita acentos e cecidilha como entrada
    setlocale(LC_ALL, "Portuguese");

    /*=====================================================================
    =============================DEMONSTRA��O==============================
    =====================================================================*/

    //aloca alguns valores em bytes
    uint8_t *var1 = aloca(8);
    uint8_t *var2 = aloca(12);
    uint8_t *var3 = aloca(4);
    uint8_t *var4 = aloca(46);
    uint8_t *var5 = aloca(4095);
    uint8_t *var6 = aloca(8);

    //demonstra mem�ria ap�s aloca��o
    print_memoria();

    //libera toda mem�ria, com exce��o da vari�vel 3
    libera(var1);
    libera(var2);
    libera(var3);
    libera(var4);
    libera(var5);

    //demonstra mem�ria ap�s libera��o
    print_memoria();

    //aloca mais 8 bytes como teste
    uint8_t *var7 = aloca(8);

    //demonstra mem�ria ap�s nova aloca��o
    print_memoria();

    getchar();

    return 0;
}

void print_memoria()
{
    //printa todo o vetor de mem�ria
    printf("\n\n=======================SITUA��O DA MEM�RIA=======================\n");
    for(int i=0; i<TAM_MEMORIA; i++)
    {
        printf("[%d] ", memoria[i]);
    }
    printf("\n\n=====================================================================\n");
}
