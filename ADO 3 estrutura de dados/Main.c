#include <stdio.h>
#include <stdlib.h>
#include "Grafo.c"

int main(){
	
	grafo g;
	cor c;
	criagrafo(&g, &c, 5);
	matrizpadrao(&g, 5);
	printamatriz(&g,5);
	grauv(0,5,&g);
	grauv(1,5,&g);
	grauv(2,5,&g);
	grauv(3,5,&g);
	grauv(4,5,&g);
	grauv(5,5,&g);
	printf("\n======================\n=====BCC Senac SP=====\n======================\n====Fernando Alves====\n======================\n");
}
