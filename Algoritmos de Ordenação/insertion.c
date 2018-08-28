#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void insertion(int *vetor,int tamanho){
	
	int i, j, atual;
	
	for (i = 1; i < tamanho; i++)
	{
		atual = vetor[i];
		j = i - 1;

		while ((j >= 0) && (atual < vetor[j]))
		{
			vetor[j + 1] = vetor[j];
			j = j - 1;
		}
    
		vetor[j + 1] = atual;
	}
	
}

int main(void) {
	
	int vetor[100], tamanho=100;
	
	for(int i=0;i<tamanho;i++)
	{
		vetor[i]=rand();
	}
	
	double inicio = clock();
	insertion(vetor,tamanho);
	double fim = clock();
	
	printf("%lf\n", fim-inicio/CLOCKS_PER_SEC);
	
	for(int i=0;i<tamanho;i++)
	{
		printf("%d\n", vetor[i]);
	}
	
	
	return 0;
}

