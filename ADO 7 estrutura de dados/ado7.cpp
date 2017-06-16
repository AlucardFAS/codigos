#include <stdio.h>
#include <stdlib.h>

int zeraHash(int *tabalahash,int M);
int dispersa(int M, int elemento);
int insereLinear(int *tabela, int M, int elemento);
int insereQuadratico(int *tabela, int M, int elemento);
int buscaQuadratico(int *tabela, int M, int elemento);
int buscaLinear(int *tabela, int M, int elemento);
int removerLinear(int *tabela, int M, int elemento);
int removerQuadratico(int *tabela, int M, int elemento);
void printHash(int *tabela, int M);

int main(){
	
	int M=167,tabelaHash[M];
	zeraHash(tabelaHash,M);
	insereLinear(tabelaHash,M,80);
	insereLinear(tabelaHash,M,5000);
	insereLinear(tabelaHash,M,5000);
	insereLinear(tabelaHash,M,5001);
	insereLinear(tabelaHash,M,166);
	insereLinear(tabelaHash,M,166);
	insereLinear(tabelaHash,M,2048);
	insereLinear(tabelaHash,M,512);
	insereLinear(tabelaHash,M,167);
	insereQuadratico(tabelaHash,M,5000);
	buscaQuadratico(tabelaHash,M,5000);
	buscaLinear(tabelaHash,M,80);
	buscaLinear(tabelaHash,M,167);
	removerLinear(tabelaHash,M,167);
	removerQuadratico(tabelaHash,M,5000);
	removerQuadratico(tabelaHash,M,5000);
	printHash(tabelaHash,M);
	
}

int zeraHash(int *tabelahash, int M)//zera o vetor
{
	for(int i=0;i<M;i++)
	{
		tabelahash[i] = 0;
	}	
	return *tabelahash;
}

int dispersa(int M, int elemento)//função de dispersão
{
	return elemento % M;
}

int insereLinear(int *tabela, int M, int elemento)//insere pelo método linear
{
	int pos = dispersa(M,elemento);
	int confirma = 0, check = pos, cont = 0;
	
	while(confirma == 0)
	{
		cont++;
		if(pos == M)
		{
			pos = 0;
		}
		else if(tabela[pos] == 0)
		{
			tabela[pos] = elemento;
			printf("inseriu %d na posicao %d\n",elemento,pos);
			confirma = 1;
		}
		else
		{
			pos++;
		}
		if(cont == check)
		{
			printf("tabela cheia!\n");
		}
	}
	
}

int insereQuadratico(int *tabela, int M, int elemento)//insere pelo método quadrático
{
	int pos = dispersa(M,elemento);
	int confirma = 0, check = pos, cont = 0;
	
	while(confirma == 0)
	{
		cont++;
		if(pos >= M)
		{
			pos-=M-1;
		}
		else if(tabela[pos] == 0)
		{
			tabela[pos] = elemento;
			printf("inseriu %d na posicao %d\n",elemento,pos);
			confirma = 1;
		}
		else if(pos == 0)
		{
			pos = 2;
		}
		else
		{
			pos= pos*pos;
		}
		if(cont == check)
		{
			printf("tabela cheia!\n");
			confirma = 1;
		}
	}
}


int buscaQuadratico(int *tabela, int M, int elemento)//busca pelo método de inserção quadrático
{
	int pos = dispersa(M,elemento);
	int confirma = 0, check = pos, cont = 0;
	
	while(confirma == 0)
	{
		cont++;
		if(pos >= M)
		{
			pos-=M-1;
		}
		else if(tabela[pos] == elemento)
		{
			printf("O elemento %d esta na posicao %d\n",elemento,pos);
			confirma = 1;
		}
		else if(pos == 0)
		{
//			printf("fez 2\n");
			pos = 2;
		}
		else
		{
//			printf("fez 3\n");
			pos= pos*pos;
		}
		if(cont == check)
		{
			printf("O elemento %d nao esta na tabela ou nao foi inserido de forma quadratica!\n",elemento);
			confirma = 1;
		}
	}
}

int buscaLinear(int *tabela, int M, int elemento)//busca pelo método de inserção linear
{
	int pos = dispersa(M,elemento);
	int confirma = 0, check = pos, cont = 0;
	
	while(confirma == 0)
	{
		cont++;
		if(pos == M)
		{
			pos=0;
		}
		else if(tabela[pos] == elemento)
		{
			printf("O elemento %d esta na posicao %d\n",elemento,pos);
			confirma = 1;
		}
		else
		{
			pos++;
		}
		if(cont == check)
		{
			printf("O elemento %d nao esta na tabela ou nao foi inserido pelo metodo linear!\n",elemento);
			confirma = 1;
		}
	}
}

int removerLinear(int *tabela, int M, int elemento)
{
	int pos = dispersa(M,elemento);
	int confirma = 0, check = pos, cont = 0;
	
	while(confirma == 0)
	{
		cont++;
		if(pos == M)
		{
			pos=0;
		}
		else if(tabela[pos] == elemento)
		{
			printf("O elemento %d foi removido!\n",elemento);
			tabela[pos] = 0;
			confirma = 1;
		}
		else
		{
			pos++;
		}
		if(cont == check)
		{
			printf("O elemento %d nao esta na tabela ou nao foi inserido pelo metodo linear!\n",elemento);
			confirma = 1;
		}
	}
}

int removerQuadratico(int *tabela, int M, int elemento)
{
	int pos = dispersa(M,elemento);
	int confirma = 0, check = pos, cont = 0;
	
	while(confirma == 0)
	{
		cont++;
		if(pos >= M)
		{
			pos-=M-1;
		}
		else if(tabela[pos] == elemento)
		{
			tabela[pos] = 0;
			printf("O elemento %d foi removido!\n",elemento);
			confirma = 1;
		}
		else if(pos == 0)
		{
//			printf("fez 2\n");
			pos = 2;
		}
		else
		{
//			printf("fez 3\n");
			pos= pos*pos;
		}
		if(cont == check)
		{
			printf("O elemento %d nao esta na tabela ou nao foi inserido de forma quadratica!\n",elemento);
			confirma = 1;
		}
	}
}

void printHash(int *tabela, int M)
{
	int cont=0;
	printf("\n\n[posicao][valor]\n");
	while(cont!=M)
	{
		printf("[%d]        [%d]\n",cont,tabela[cont]);
		cont++;
	}
}


