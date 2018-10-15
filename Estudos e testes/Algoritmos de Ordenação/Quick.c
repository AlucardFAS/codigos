#include<stdio.h>
#include <stdlib.h>
#include <time.h>

//algoritmo retirado de https://www.vivaolinux.com.br/script/Ordenacao-QuickSort

void Quick(int vetor[10], int inicio, int fim);

int main(){

	int vetor[1000],tamanho=1000;
	for(int i=0;i<1000;i++)
	{
		vetor[i]=rand();
	}

	double inicio = clock();
	Quick(vetor, 0, 9);
	double fim = clock();
	
	printf("%lf\n", fim-inicio/CLOCKS_PER_SEC);
	
	printf("Vetor ordenado:\n");
	for(i = 0; i < 10; i++)
	{
	printf("%d ", vetor[i]);
	}
  	
}

void Quick(int *vetor, int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);   

}
