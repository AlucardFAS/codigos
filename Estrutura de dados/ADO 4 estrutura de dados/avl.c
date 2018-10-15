#include <stdlib.h>
#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

typedef struct noh
{
	int dado;
	struct noh *esq;
	struct noh *dir;
	struct noh *parent;
	int h;
} noh_t;

noh_t *encontre(noh_t *raiz, int dado)
{
	if (raiz == NULL)
	{
		printf("O elemento %d nao esta na arvore!\n",dado);
		return NULL;
	}
	if (raiz -> dado == dado)
	{
		printf("O elemento %d esta na arvore!\n",dado);
	}
	if (dado < raiz->dado)
		return encontre(raiz->esq, dado);
	else if (dado > raiz->dado)
		return encontre(raiz->dir, dado);
	else
		return raiz;
}

int altura(noh_t *raiz)
{
    return raiz ? raiz->h : 0;
}

void ajuste_h(noh_t *raiz)
{
	raiz->h = 1 + max(altura(raiz->esq), altura(raiz->dir));
}

noh_t *girarD(noh_t *raiz)
{
	noh_t *no = raiz->esq;
	if (raiz->parent)
	{
		if (raiz->parent->esq == raiz) raiz->parent->esq = no;
		else raiz->parent->dir = no;
	}
	no->parent = raiz->parent;
	raiz->parent = no;
	raiz->esq = no->dir;
    if (raiz->esq) raiz->esq->parent = raiz;
	no->dir = raiz;


	ajuste_h(raiz);
	ajuste_h(no);
	return no;
}

noh_t *girarE(noh_t *raiz)
{
	noh_t *no = raiz->dir;
	if (raiz->parent)
	{
		if (raiz->parent->dir == raiz) raiz->parent->dir = no;
		else raiz->parent->esq = no;
	}
	no->parent = raiz->parent;
	raiz->parent = no;
	raiz->dir = no->esq;
    if (raiz->dir) raiz->dir->parent = raiz;
	no->esq = raiz;


	ajuste_h(raiz);
	ajuste_h(no);
	return no;
}

noh_t *cria_noh(int dado, noh_t *parent)
{
	noh_t *n = malloc(sizeof(noh_t));
	n->dado = dado;
    n->parent = parent;
	n->h = 1;
	n->esq = NULL;
	n->dir = NULL;
	
	printf("%d Inserido!\n",dado);

	return n;
}

noh_t *balanceia(noh_t *raiz)
{
    if (altura(raiz->esq) - altura(raiz->dir) > 1)
    {
        if (altura(raiz->esq->esq) > altura(raiz->esq->dir))
        {
            raiz = girarD(raiz);
        }
        else
        {
            girarE(raiz->esq);
            raiz = girarD(raiz);
        }
    }
    else if (altura(raiz->dir) - altura(raiz->esq) > 1)
    {
        if (altura(raiz->dir->dir) > altura(raiz->dir->esq))
        {
            raiz = girarE(raiz);
        }
        else
        {
            girarD(raiz->dir);
            raiz = girarE(raiz);
		}
    }
    return raiz;
}

noh_t *inserir(noh_t *raiz, int dado)
{
	int inserido=0;
    noh_t *atual = raiz;
    while (atual->dado != dado)
    {
        if (dado < atual->dado)
        {
            if (atual->esq) 
            {
				atual = atual->esq;
			}
			else
            {
                atual->esq = cria_noh(dado, atual);
                atual = atual->esq;
                inserido=1;
            }
        }
        else if (dado > atual->dado)
        {
            if (atual->dir) 
            {
				atual = atual->dir;
			}
            else
            {
                atual->dir = cria_noh(dado, atual);
                atual = atual->dir;
                inserido = 1;
            }
        }
        else return raiz;
    }
    if(dado == atual->dado && inserido == 0)
    {
    	printf("O elemento %d ja foi inserido!\n",dado);
	}
    
    do
    {
        atual = atual->parent;
        ajuste_h(atual);
        atual = balanceia(atual);
    } while (atual->parent);
    
    return atual;
}

void checkavl(noh_t *raiz)
{
	if(altura(raiz->esq) - altura(raiz->dir) > 1 && altura(raiz->dir) - altura(raiz->esq) > 1)
	{
		printf("Arvore desbalanceada!\n");		
	}
	else
	{
		printf("Arvore balanceada!\n");
	}
}

void print_avl(noh_t *noh, int elemento)
{
    int ix;
    for (ix = 0; ix < elemento; ix++) printf(" ");
    if (!noh) printf("Filho vazio\n");
    else
    {
        printf("valor %d h = %d\n", noh->dado, noh->h);
        print_avl(noh->esq, elemento + 4);
        print_avl(noh->dir, elemento + 4);
    }
}

void print_arvore(noh_t *noh)
{
    print_avl(noh, 0);
}

int main(int argc, char *argv[])
{
    noh_t *raiz = cria_noh(1, NULL);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 9);
    raiz = inserir(raiz, 9);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 11);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 13);
    encontre(raiz,3);
	encontre(raiz,19);
	checkavl(raiz);

	printf("\n\n\n\n");

    	
    print_arvore(raiz);
    
    return 0;
}
