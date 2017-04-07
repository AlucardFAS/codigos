#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

typedef struct cor
{
	char cor;
}cor;

typedef struct grafo
{
    int vertices;//Quantidade de vertices da matriz(tipo as cidades)
    int **adj;//Matriz de adjacencias(tipo a ligação entres as cidades, vertices)
    char cor;//cor do vertice
}grafo;

void criagrafo(grafo *g, cor *c, int v)
{
	//aloca memória para um ponteiro de um ponteiro de um inteiro e multiplica por v, gerando,assim, a matriz
    g -> adj = (int**)malloc(v * sizeof (int**));
    //"anota" a quantidade de vertices
    g -> vertices = v;

	//aloca a memória para cada inteiro do vetor, criando um segundo vetor para a geração da matriz
    for(int i = 0; i < g -> vertices; i++)
    {
        g->adj[i] = (int*)malloc(v * sizeof(int*));
    }
    
	//zera a matriz
	for(int i=0; i < v; i++)
    {
    	for(int j=0; j<v;j++)
    	{
    		g -> adj[i][j] = 0;
		}
	}
}

void grauv(int vertice, int numvertices, grafo *g)
{
	int result=0;
	if(vertice >= numvertices)
	{
		printf("Nao existe vertice %d\n",vertice);
	}
	else
	{
		for(int i=0; i<numvertices; i++)
		{
			if (g -> adj[vertice][i] != 0)
			{
				result++;
			}
		}
		printf("O grau do vertice %d eh %d\n",vertice,result);
	}
}

void matrizpadrao(grafo *g, int v)
{
	g -> adj[1][0] = 1;
	g -> adj[0][1] = 1;
	g -> adj[4][3] = 1;
	g -> adj[3][4] = 1;
	g -> adj[2][3] = 1;
	g -> adj[3][2] = 1;
	g -> adj[4][0] = 1;
	g -> adj[0][4] = 1;
}

void printamatriz(grafo *g, int v)
{
	int j=0;
	while(j<v)
	{
		for(int i=0; i<v; i++)
		{
			printf("%d ", g -> adj[j][i]);
		}
		j++;
		printf("\n");
	}
}
