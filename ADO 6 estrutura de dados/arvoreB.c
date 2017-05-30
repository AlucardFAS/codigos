#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

typedef struct Node{
    int n_chaves;
    int *chaves;
    struct Node **ptr_noh;
    bool folha;
} noh;

noh* criaNoh(noh* no, int ordem)
{
    no = malloc(sizeof(noh));
    no->folha = true;
    no->n_chaves = 0;
    no->chaves = (int*) malloc((ordem-1)* sizeof(int)); 
    for(int i = 0; i < ordem - 1; i++) no->chaves[i] = -1;
    no->ptr_noh = (noh**) malloc(ordem* sizeof(struct noh*));
    for(int i = 0; i < ordem; i++) no->ptr_noh[i] = NULL;
    return no;
}

void copiaNoh(noh *sourc, noh *dest, int ordem, int m)
{
    int j = 0;
    for(int i = m; i < ordem - 1; i++)
	{
        dest->chaves[j] = sourc->chaves[i];
        dest->ptr_noh[j + 1] = sourc->ptr_noh[i + 1];
        sourc->chaves[i] = -1;
        sourc->ptr_noh[i + 1] = NULL;
        dest->n_chaves++;
        sourc->n_chaves--;
        j++;
    }
}

int ordenaNoh(noh* no, int chave)
{
    int i = no->n_chaves;
    while(i > 0 && no->chaves[i - 1] > chave)
	{
        no->chaves[i] = no->chaves[i - 1];
        no->ptr_noh[i + 1] = no->ptr_noh[i];
        i--;
    }
    no->chaves[i] = chave;
    no->n_chaves++;
    return i;
}

int ajustaPos(int *array, int pos, int chave)
{
    while(pos > 0 && array[pos - 1] > chave) pos--;
    return pos;
}

void trocaVetor(int* array, int tamanho)
{
    int j,item;
    for(int i = 1; i < tamanho; i++)
	{
        item = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > item)
		{
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = item;
    }
}

void divide(noh *no, int chave, noh *direita, noh *novo, int *chave_promovida, int ordem)
{
    if(no->folha == false) novo->folha = false;
    int pos;
    int m = (int)(ordem - 1)/2;
    if(chave < no->chaves[m]){
        copiaNoh(no, novo, ordem, m);
        no->chaves[no->n_chaves] = chave;
        no->n_chaves++;
        trocaVetor(no->chaves, no->n_chaves);
        pos = ajustaPos(no->chaves, no->n_chaves, chave);
        novo->ptr_noh[0] = no->ptr_noh[pos];
        no->ptr_noh[pos] = direita;

    } else {
        copiaNoh(no, novo, ordem, m + 1);
        novo->chaves[novo->n_chaves] = chave;
        novo->n_chaves++;

        trocaVetor(novo->chaves, novo->n_chaves);
        pos = ajustaPos(novo->chaves, novo->n_chaves, chave);
        novo->ptr_noh[0] = no->ptr_noh[no->n_chaves];
        novo->ptr_noh[pos] = direita;
    }
    *chave_promovida = no->chaves[(no->n_chaves) - 1];
    no->chaves[(no->n_chaves) - 1] = -1;
    no->n_chaves--;    
}

bool buscaInsere(noh* atual, int chave, bool* promocao, int* chave_promovida, noh** novo, int ordem)
{
    bool jaExiste = false;
    for(int i = 0; i < atual->n_chaves; i++) if(chave == atual->chaves[i]) jaExiste = true;
    if(jaExiste) return false;
    else 
	{
	    if(atual->folha) 
		{
            if(atual->n_chaves < ordem - 1)
			{
			    atual->chaves[(atual->n_chaves)] = chave;
                atual->n_chaves++;
                atual->ptr_noh[(atual->n_chaves) + 1] = NULL;
                *promocao = false;
                trocaVetor(atual->chaves, atual->n_chaves);
            } 
			else 
			{
                divide(atual, chave, NULL, *novo, chave_promovida, ordem);
                *promocao = true;
            }
            return true;
        } 
		else 
		{ 
            int pos = ajustaPos(atual->chaves, atual->n_chaves, chave);
            bool status = buscaInsere(atual->ptr_noh[pos], chave, promocao, chave_promovida, novo, ordem);
            if(status == true && *promocao == true)
			{
                if(atual->n_chaves < ordem - 1)
				{        
                    pos = ordenaNoh(atual, *chave_promovida);
                    atual->ptr_noh[pos + 1] = *novo;
                    *promocao = false;
                } 
				else 
				{    
                    noh* filho = criaNoh(filho, ordem);
                    divide(atual, *chave_promovida, *novo, filho, chave_promovida, ordem);
                    *novo = filho;
                }
            }
            return status;
        }
    }
}

bool insere(noh** raiz, int chave, int ordem)
{
    if(*raiz == NULL)
	{
        *raiz = criaNoh(*raiz, ordem);
        (*raiz)->chaves[0] = chave;
        (*raiz)->n_chaves++;
        return true;
    } 
	else 
	{
        bool status, promocao;
        int chave_promovida;
        noh *novo = criaNoh(novo, ordem);
        status = buscaInsere(*raiz, chave, &promocao, &chave_promovida, &novo, ordem);

        if(promocao == true)
		{
            noh *nova_raiz = criaNoh(nova_raiz, ordem);
            nova_raiz->folha = false;
            nova_raiz->chaves[0] = chave_promovida;
            nova_raiz->n_chaves++;
            nova_raiz->ptr_noh[0] = *raiz;
            nova_raiz->ptr_noh[1] = novo;
            *raiz = nova_raiz;
        }
        return status;
    }
}
void busca(noh* no, int elemento)
{	
	for(int i = 0; i <= no->n_chaves; i++)
	{
		if(elemento == no -> chaves[i]) printf("O elemento %d esta na arvore\n\7",no -> chaves[i]);			
		if(no -> folha == false) busca(no->ptr_noh[i],elemento);
	}
}
void mostraArvore(noh* no,int cont)
{
	int t=cont;
	while(t!=0) 
	{
	printf("    ");
	t--;
	}
	cont++;
	printf("|");
	for(int i = 0; i < no->n_chaves; i++) printf("%d ", no->chaves[i]);
    printf("|\n");
    if(no -> folha == false) for(int i = 0; i <= no->n_chaves; i++) mostraArvore(no->ptr_noh[i],cont);
}

int main(){
    int ordem=8;
    noh* raiz = NULL;
	printf("\n\n===Elementos de 1 a 100 com ordem %d===\n\n",ordem);
	for(int i=1;i<=100;i++) insere(&raiz, i, ordem);
   	mostraArvore(raiz,0);
   	busca(raiz,50);
    busca(raiz,100);
	busca(raiz,27);
	return 0;
}
