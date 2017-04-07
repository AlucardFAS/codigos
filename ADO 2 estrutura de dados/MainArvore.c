#include <stdio.h>
#include <stdlib.h>
#include "Arvore.c"

int main(){

    noh *raiz = NULL;
    remover(&raiz,7);
    inserirIterativo(&raiz,6);
    inserirIterativo(&raiz,7);
    buscaRecursiva(&raiz,7);
    inserirRecursivo(&raiz,8);
    inserirRecursivo(&raiz,5);
    inserirRecursivo(&raiz,5);
    inserirRecursivo(&raiz,7);
    inserirRecursivo(&raiz,9);
    inserirRecursivo(&raiz,2);
    inserirRecursivo(&raiz,3);
    inserirRecursivo(&raiz,1);
    inserirRecursivo(&raiz,6);
    pre(&raiz);
    printf("\n");
    in(&raiz);
    printf("\n");
    pos(&raiz);
    printf("\n");
    remover(&raiz,6);
    remover(&raiz,7);
    remover(&raiz,1);
    buscaRecursiva(&raiz,2);
    buscaRecursiva(&raiz,7);
    buscaIterativa(&raiz,2);
    buscaIterativa(&raiz,7);


}
