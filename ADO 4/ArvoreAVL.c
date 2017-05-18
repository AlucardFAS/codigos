#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

//================================================
//===================Estruturas===================
//================================================

typedef struct noh
{
    struct noh *esq;
    struct noh *dir;
    int h;//altura
    int dado;//valor
}noh;

noh *filhos(noh *novaraiz)//estrutura auxiliar remoção
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

//================================================
//===============inserção e remoção===============
//================================================

int inserir(noh **raiz,int elemento,int altura)
{
	int retorno;
	if((*raiz) == NULL)
    {
        noh *aux = (noh *)malloc(sizeof(noh));
        aux -> dado = elemento;
        aux -> esq = NULL;
        aux -> dir = NULL;
        aux -> h = altura;
        *raiz = aux;
        printf("%d inserido! A altura eh %d\n",elemento,(*raiz) -> h);
        retorno = 1;
		return retorno;
    }
    else if(elemento < (*raiz)->dado)
    {
    	altura++;
        inserir(&(*raiz)->esq,elemento,altura);
        return retorno;
    }
    else if(elemento > (*raiz)->dado)
    {
    	altura++;
        inserir(&(*raiz)->dir,elemento,altura);
        return retorno;
    }

	printf("teste\n");
	struct noh *atual = *raiz;
    if(elemento < atual -> dado)
    {
        if(retorno==1)
        {
	        if(balanceia(atual) >=2)
    	    {
        		if(elemento < (*raiz) -> esq -> dado)
        		{
        			girarEE(raiz);
				}
				else
				{
					girarED(raiz);
				}
			}
		}
	}

}

void remover(noh **raiz,int elemento)
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

//=================================================
//====================Impressão====================
//=================================================

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

//==================================================
//=====================Rotações=====================
//==================================================

void girarEE(noh **raiz)
{
	struct noh *no;
	no = (*raiz) -> esq;
	(*raiz) -> esq = no -> dir;
	no -> dir = (*raiz);
	(*raiz) -> h = maior(alt((*raiz) -> esq), alt((*raiz) -> dir)) + 1;
	no -> h = maior(alt(no->esq), (*raiz) -> h) + 1;
	(*raiz) = no;
}


void girarDD(noh **raiz)
{
	struct noh *no;
	no = (*raiz) -> dir;
	(*raiz) -> dir = no -> esq;
	no -> esq = (*raiz);
	(*raiz) -> h = maior(alt((*raiz) -> esq), alt((*raiz) -> dir)) + 1;
	no -> h = maior(alt(no->dir), (*raiz) -> h) + 1;
	(*raiz) = no;
}

void girarED(noh **raiz)
{
	girarDD(&(*raiz) -> esq);
	girarEE(raiz);
}

void girarDE(noh **raiz)
{
	girarEE(&(*raiz) -> dir);
	girarDD(raiz);
}

//==================================================
//================Funções auxiliares================
//==================================================

int alt(struct noh **no)
{
	if(no == NULL)
	{
		return -1;
	}
	else
	{
		return (*no)-> h;
	}
}

int balanceia(struct noh *no)
{
	return labs(alt(&no->esq - alt(&no->dir)));
}

int maior(int x, int y)
{
	return x > y ? x : y;
}
