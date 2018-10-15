#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void bubble(int *vetor,int n)
{
	int i,j,temp[1];
	
	for(i=0;i<n-1;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(vetor[j]<vetor[j-1])
			{
				temp[0]=vetor[j];
				vetor[j]=vetor[j-1];
				vetor[j-1]=temp[0];
			}
		}
		//printf("%d ", vetor[i]);
	}
	
	
}

int main(void) {
	
	int vetor[1000000];
	
	for(int i=0;i<1000000;i++)
	{
		vetor[i]=rand();
	}
	
	double inicio = clock();
	
	bubble(vetor,1000000);
	
	double fim = clock();
	
	printf("%lf\n", fim-inicio/CLOCKS_PER_SEC);
	
	return 0;
}
