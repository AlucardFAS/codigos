#include <stdio.h>
#include <stdlib.h>

#define PRETO 0
#define VERMELHO 1
#define TRUE 4
#define FALSE 5

typedef struct no{
    struct no *esquerdo;
    struct no *direito;
    struct no *pai;
    int chave;
    int cor;
}nohrn;

nohrn *nil, *auxFather;
int count, Opcoes;
nohrn *ProcuraNo(nohrn *raiz, int elemento);

nohrn *createNil(nohrn *node)
{
    node->esquerdo = nil;
    node->direito = nil;
    node->pai = nil;
    
    return node;
}

nohrn *CriarNo(int elemento)
{
    nohrn *novo = (nohrn*)malloc(sizeof(nohrn));
    if(novo == nil) return nil;

    novo->pai = nil;
    novo->esquerdo = nil;
    novo->direito = nil;
    novo->chave = elemento;
    novo->cor = VERMELHO;
    return novo;
}

nohrn *RotacaoEsquerda(nohrn *raiz, nohrn *No_A)
{
    nohrn *No_B = No_A->direito;
    No_A->direito = No_B->esquerdo;
    if(No_B->esquerdo != nil) No_B->esquerdo->pai = No_A;
    
	No_B->pai = No_A->pai;
    if(No_A->pai == nil) raiz = No_B;
    
	else
	{
        if(No_A == No_A->pai->esquerdo) No_A->pai->esquerdo = No_B;
        else No_A->pai->direito = No_B;
    }
    No_B->esquerdo = No_A;
    No_A->pai = No_B;
    return raiz;
}

nohrn *RotacaoDireita(nohrn *raiz, nohrn *No_A)
{
    nohrn *No_B = No_A->esquerdo;
    No_A->esquerdo = No_B->direito;
    if(No_B->direito != nil) No_B->direito->pai = No_A;
    
	No_B->pai = No_A->pai;
	if(No_A->pai == nil) raiz = No_B;

    else
	{
        if(No_A == No_A->pai->direito) No_A->pai->direito = No_B;
        else No_A->pai->esquerdo = No_B;
    }
    No_B->direito = No_A;
    No_A->pai = No_B;
    return raiz;
}

int compara(int key1, int key2)
{
    if (key1 == key2) return 0;
    else if (key2 < key1) return -1;
    else return 1;
        
}

int eVermelho(nohrn *node)
{
    if (node != nil && node->cor == VERMELHO) return TRUE;
    else return FALSE;
}


int eFilhoEsquerdo(nohrn *node)
{
    if (node == node->pai->esquerdo) return TRUE;
    else return FALSE;
}

void raizNegra(nohrn *root)
{
    if (root) root->cor = PRETO;
}

nohrn *recebeTio(nohrn *node)
{
    if (node->pai != nil && node->pai == node->pai->pai->esquerdo) return node->pai->pai->direito;
    else if (node->pai != nil) return node->pai->pai->esquerdo;
    
    return nil;
}

nohrn *insere(nohrn *root, nohrn *node)
{
    int aux;
    
    if (root == nil)
    {
        node->pai = auxFather;
		printf("%d inserido\n",node -> chave);
		return node;
    }
    else
    {
        aux = compara(root->chave, node->chave);
        if (aux ==  0) printf("Valor repetido\n");
        else if (aux < 0)
        {
            auxFather = root;
            root->esquerdo = insere(root->esquerdo, node);
        }
        else
        {
            auxFather = root;
            root->direito = insere(root->direito, node);
        }
        
    }
    
    return root;
}

nohrn *caso_1(nohrn *root, nohrn *node, nohrn *nodeAux)
{
    node->pai->cor = PRETO;
    nodeAux->cor = PRETO;
    node->pai->pai->cor = VERMELHO;
    node = node->pai->pai;
    
    return root;
}

nohrn *caso_2(nohrn *root, nohrn *node)
{
    node->pai->cor = PRETO;
    node->pai->pai->cor = node->cor;
    if (eFilhoEsquerdo(node) == TRUE) root = RotacaoDireita(root, node->pai->pai);
    else if (eFilhoEsquerdo(node) == FALSE) root = RotacaoEsquerda(root, node->pai->pai);
    
    return root;
}

nohrn *caso_3(nohrn *root, nohrn *node, nohrn *nodeAux)
{
    if (eFilhoEsquerdo(node) == FALSE && eFilhoEsquerdo(nodeAux) == TRUE)
    {
        node->cor = PRETO;
        node->pai->pai->cor = VERMELHO;
        root = RotacaoEsquerda(root, nodeAux);
        root = RotacaoDireita(root, node->pai);
    }
    else if (eFilhoEsquerdo(node) == TRUE && eFilhoEsquerdo(nodeAux) == FALSE)
    {
        node->cor = PRETO;
        node->pai->pai->cor = VERMELHO;
        root = RotacaoDireita(root, nodeAux);
        root = RotacaoEsquerda(root, node->pai);
    }
    
    return root;
}


nohrn *insere_RN(nohrn *root, int value)
{
    root = insere(root, CriarNo(value));
    raizNegra(root);
    
    nohrn *node = ProcuraNo(root, value);
    nohrn *auxiliar = recebeTio(node);
    
    if (node->pai != nil && eVermelho(node->pai) == TRUE)
    {
        if (auxiliar != nil && eVermelho(auxiliar) == TRUE)
        {
            root = caso_1(root, node, auxiliar);
        }
        else
        {
            if (eFilhoEsquerdo(node) != eFilhoEsquerdo(node->pai)) root = caso_3(root, node, node->pai);
            else root = caso_2(root, node);
        }
	}
    return root;
}

nohrn *MenorDosMaiores(nohrn *raiz)
{
    nohrn *aux = raiz->direito;
    while(aux->esquerdo != nil) aux = aux->esquerdo;
    return aux;
}

nohrn *RemoverNaArvore(nohrn *raiz, nohrn *No)
{
    nohrn *aux;
    
    while(No != raiz && No->cor == PRETO)
	{
        if(No == No->pai->esquerdo)
		{
            aux = No->pai->direito;
            if(aux->cor == VERMELHO)
			{ 
                aux->cor = PRETO;
                No->pai->cor = VERMELHO;
                raiz = RotacaoEsquerda(raiz, No->pai);
                aux = No->pai->direito;
            }
            if(aux->esquerdo->cor == PRETO && aux->direito->cor == PRETO)
			{
                aux->cor = VERMELHO;
                No = No->pai;
            }
            else{
                if(aux->direito->cor == PRETO)
				{ 
                    aux->esquerdo->cor = PRETO;
                    aux->cor = VERMELHO;
                    raiz = RotacaoDireita(raiz, aux);
                    aux = No->pai->direito;
                }
                aux->cor = No->pai->cor; 
                No->pai->cor = PRETO;
                aux->direito->cor = PRETO;
                raiz = RotacaoEsquerda(raiz, No->pai);
                No = raiz;
            }
        }
        else
		{
            aux = No->pai->esquerdo;
            if(aux->cor == VERMELHO)
			{
                aux->cor = PRETO;
                No->pai->cor = VERMELHO;
                raiz = RotacaoDireita(raiz, No->pai);
                aux = No->pai->esquerdo;
            }
            if(aux->direito->cor == PRETO && aux->esquerdo->cor == PRETO)
			{
                aux->cor = VERMELHO;
                No = No->pai;
            }
            else
			{
                if(aux->esquerdo->cor == PRETO)
				{
                    aux->direito->cor = PRETO;
                    aux->cor = VERMELHO;
                    raiz = RotacaoEsquerda(raiz, aux);
                    aux = No->pai->esquerdo;
                }
                aux->cor = No->pai->cor;
                No->pai->cor = PRETO;
                aux->esquerdo->cor = PRETO;
                raiz = RotacaoDireita(raiz, No->pai);
                No = raiz;
            }
        }
    }
    No->cor = PRETO;
    return raiz;
}

nohrn *ProcuraNo(nohrn *raiz, int elemento)
{
    nohrn *aux = raiz;
    while(aux != nil)
	{
        if(elemento < aux->chave) aux = aux->esquerdo;
        else if (elemento > aux->chave) aux = aux->direito;
        else return aux;
    }
    return NULL;
}

nohrn *RemoverNo(nohrn *raiz, int elemento) 
{
    nohrn *No = ProcuraNo(raiz, elemento);
    if(No == NULL)
	{
        printf("Nao existe noh %d!\n",elemento);
        return raiz;
    }
    nohrn *aux1;
    nohrn *aux2;
    if(No->esquerdo == nil || No->direito == nil) aux1 = No;
    else aux1 = MenorDosMaiores(No);
    
    if(aux1->esquerdo != nil) aux2 = aux1->esquerdo;
    else aux2 = aux1->direito;
    
    aux2->pai = aux1->pai;
    if(aux1->pai == nil) raiz = aux2;
    else
	{
        if(aux1 == aux1->pai->esquerdo) aux1->pai->esquerdo = aux2;
        else aux1->pai->direito = aux2;
    }
    
    if(aux1 != No) No->chave = aux1->chave;
    if(aux1->cor == PRETO) raiz = RemoverNaArvore(raiz, aux2);
    
    return raiz;
}

void Inserir(nohrn **raiz,int elemento)
{
    *raiz = insere_RN(*raiz, elemento);
    raizNegra(*raiz);
}

void Remover(nohrn **raiz,int elemento)
{
	printf("%d removido\n",elemento);
    *raiz = RemoverNo(*raiz, elemento);
}

void Procura(nohrn *raiz,int elemento)
{
    nohrn *No = ProcuraNo(raiz, elemento);
    if(No == NULL) printf("%d nao esta na arvore!\n",elemento);
    else printf("%d esta na arvore!\n",No->chave);
}

void addEspaco(int altura)
{
    int k = 0;    
    while(k < altura)
	{
        if(k == altura - 1) printf("    ");
        else printf("    ");
        k++;
    }
}

int eIgual(nohrn *p, nohrn *q)
{
    if (p == NULL && q == NULL) return TRUE;
    else if (p->chave == q->chave) return TRUE;
    else return FALSE;
}

int recebeAltura(nohrn *treep, nohrn *p)
{
    if(treep == nil || p == nil) return 0;
    if(eIgual(treep, p) == TRUE) return 0;
    else if(treep->chave > p->chave) return recebeAltura(treep->esquerdo, p) + 1;
    else return recebeAltura(treep->direito, p) + 1;
}

void Imprime(nohrn *p, nohrn *treep, int altura)
{
    if(treep == nil) return;
    if(p == nil)
	{
        addEspaco(altura + 1);
        printf("Filho vazio\n");
        return;
    }
    altura = recebeAltura(treep, p);
    addEspaco(altura);
    
	if (p->cor == PRETO) printf("%i - %s\n", p->chave, "B");
    else printf("%d - %s\n", p->chave, "R");
    
    Imprime(p->direito, treep, altura);
    Imprime(p->esquerdo, treep, altura);
}

int main(){
    nil = (nohrn*)malloc(sizeof(nohrn));
    auxFather = nil;
    nohrn *raiz = nil;
    Inserir(&raiz,8);
    Inserir(&raiz,15);
    Inserir(&raiz,65);
    Inserir(&raiz,80);
    Inserir(&raiz,60);
    Inserir(&raiz,75);
    Inserir(&raiz,100);
    Inserir(&raiz,2);
    Inserir(&raiz,7);
    Inserir(&raiz,31);
    Inserir(&raiz,800);
    Inserir(&raiz,90);
    Inserir(&raiz,1);
    Inserir(&raiz,0);
    Inserir(&raiz,8);
    Inserir(&raiz,65);
    Inserir(&raiz,1);
    Remover(&raiz,1);
    Procura(raiz,65);
    Procura(raiz,100);

	if((raiz) == nil)
	{
		printf("Arvore vazia!\n");
	}
    else
	{
        Imprime(raiz, raiz, -1);
        printf("\n");
    }
	
	return 0;
}
