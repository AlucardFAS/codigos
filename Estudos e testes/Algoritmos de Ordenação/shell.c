#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Função ShellSort retirada de https://pt.wikipedia.org/wiki/Shell_sort

void shell(int *vetor, int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vetor[i];
            j = i - gap;
            while (j >= 0 && value < vetor[j]) {
                vetor [j + gap] = vetor[j];
                j -= gap;
            }
            vetor [j + gap] = value;
        }
    }
}


int main(){
	
    int vetor[1000];
	
	for(int i=0;i<1000;i++)
	{
		vetor[i]=rand();
	}
	
	double inicio = clock();
	
	shell(vetor,1000);
	
	double fim = clock();
	
	printf("%lf\n", fim-inicio/CLOCKS_PER_SEC);
	
	return 0;
}
