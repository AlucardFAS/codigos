#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.c"

int main(){

    noh *raiz = NULL;
    inserir(&raiz,10,0);
    inserir(&raiz,9,0);
    inserir(&raiz,8,0);
    inserir(&raiz,7,0);
    inserir(&raiz,6,0);
    
    
    printf("\nin: ");
	in(&raiz);
    printf("\npre: ");
    pre(&raiz);
    printf("\npos: ");
    pos(&raiz);
    printf("\n");

}
