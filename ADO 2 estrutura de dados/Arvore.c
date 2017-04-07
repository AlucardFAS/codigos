#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

typedef struct noh
{
    struct noh *esq;
    struct noh *dir;
    int dado;
}noh;

noh *filhos(noh *novaraiz)
{
	if(novaraiz==NULL)
	{
		return NULL;
	}
	else if(novaraiz->esq == NULL)
	{
		return novaraiz;
	}
	else
	{
		return filhos(novaraiz -> esq);
	}
}

int buscaRecursiva(noh **raiz,int elemento)
{
	int i=0;
	if ((*raiz) != NULL)
	{
		i=1;
		if(elemento < (*raiz) -> dado)
		{
			buscaRecursiva(&(*raiz) -> esq, elemento);
		}
		else if(elemento > (*raiz) -> dado)
		{
			buscaRecursiva(&(*raiz) -> dir, elemento);
		}
		else if(elemento == (*raiz) -> dado)
        {
            printf("O elemento %d esta na arvore!\n",(*raiz) -> dado);
			return ((*raiz) -> dado);
        }
	}
	if(i==0)
	{
		printf("O elemento %d nao esta na arvore!\n",elemento);
	}
	return 0;
}

void buscaIterativa(noh **raiz, int elemento)
{
	noh *q = NULL;
	noh *p = (*raiz);
	int i = 1;
	while((p) != NULL)
	{
		(q) = (p);
		if((p) -> dado == elemento)
		{
			printf("o elemento %d esta na arvore!\n", elemento);
			i=2;
			break;
			return;
		}
		else if((p) -> dado < elemento)
		{
			(p) = (p) -> dir;
		}
		else
		{
			(p) = (p) -> esq;
		}
	}
	if(i==1)
	{
		printf("o elemento %d nao esta na arvore!\n", elemento);
	}		
}

void inserirIterativo(noh **raiz, int elemento)
{
    noh *q = NULL;
    noh *p = (*raiz);
    while((p) != NULL)
    {
        (q) = (p);
        if(elemento == (p) -> dado)
        {
            printf("O elemento %d ja esta na arvore!\n", (p) -> dado);
            return;
        }
        else if(elemento < (p) -> dado)
        {
            (p) = (p) -> esq;
        }
        else
        {
            (p) = (p) -> dir;
        }
    }

    noh *novo = ((noh *)malloc(sizeof(noh)));

    novo -> dado = elemento;
    novo -> esq = NULL;
    novo -> dir = NULL;

    if((*raiz) == NULL)
    {
        (*raiz) = novo;
        printf("Elemento %d inserido!\n", (*raiz) -> dado);
        return;
    }
    else
    {
        if(elemento < q -> dado)
        {
            q -> esq = novo;
            printf("Elemento %d inserido!\n", (*raiz) -> dado);
            return;
        }
        else
        {
            q -> dir = novo;
            printf("Elemento %d inserido!\n", (novo) -> dado);
            return;
        }
    }
}

void inserirRecursivo(noh **raiz, int elemento)
{
    if((*raiz) == NULL)
    {
        noh *aux = (noh *)malloc(sizeof(noh));
        aux -> dado = elemento;
        aux -> esq = NULL;
        aux -> dir = NULL;
        *raiz = aux;
        printf("%d inserido!\n",elemento);
        return;
    }
    else if(elemento < (*raiz)->dado)
    {
        inserirRecursivo(&(*raiz)->esq,elemento);
        //printf("%d inserido!\n",elemento);
        return;
    }
    else if(elemento > (*raiz)->dado)
    {
        inserirRecursivo(&(*raiz)->dir,elemento);
        //printf("%d inserido!\n",elemento);
        return;
    }
    printf("O numero %d ja foi inserido!\n",elemento);
}

void remover(noh **raiz, int elemento)
{
    if(*raiz == NULL)
    {
        printf("Sem elementos!\n");
        return;
    }
    if(elemento < (*raiz) -> dado)
    {
        remover(&(*raiz) -> esq,elemento);
    }
    else if(elemento > (*raiz) -> dado)
    {
        remover(&(*raiz) -> dir,elemento);
    }
    else if((*raiz) -> esq != NULL && (*raiz) -> dir != NULL)
    {
        noh *aux = NULL;
        aux = filhos((*raiz) -> dir);
        (*raiz) -> dado = aux -> dado;
        remover(&(*raiz) -> dir,(*raiz) -> dado);
    }
    else
    {
    	printf("Removido com sucesso!\n");
    	noh *aux = (*raiz);
    	if((*raiz) -> esq == NULL)
    		{
    		(*raiz) = (*raiz) -> dir;
		}
		else
		{
			*raiz = (*raiz) -> esq;
		}
		free(aux);
	}

}

void in(noh **raiz)
{
	if((*raiz) != NULL)
	{
		in(&(*raiz) -> esq);
		printf("%d ", (*raiz) -> dado);
		in(&(*raiz) -> dir);	
	}
}

void pre(noh **raiz)
{
	if((*raiz) != NULL)
	{
		printf("%d ", (*raiz) -> dado);
		pre(&(*raiz) -> esq);
		pre(&(*raiz) -> dir);	
	}
}

void pos(noh **raiz)
{
	if((*raiz) != NULL)
	{
		pos(&(*raiz) -> esq);
		pos(&(*raiz) -> dir);	
		printf("%d ", (*raiz) -> dado);
	}
}
