#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

no* inserir(no* r, int valor){
    if(r == NULL){
        no* novo = (no*) malloc(sizeof(no));
        novo->dir = NULL;
        novo->esq = NULL;
        novo->valor = valor;
        return novo;
    }
    
    if(valor > r->valor){
        r->esq = inserir(r->esq, valor);
    }
    else{
        r->dir = inserir(r->dir, valor);
    }
    
    return r;
}

void preOrdem(no* r){
    if(r != NULL){
        printf("[%d]", r->valor);
        preOrdem(r->esq);
        preOrdem(r->dir);
    }
}


