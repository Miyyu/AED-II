#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

no* inserir(no* raiz, int valor){
    if(r == NULL){
        no* novo = (no*) malloc(sizeof(no));
        novo->dir = NULL;
        novo->esq = NULL;
        novo->valor = valor;
        return novo;
    }
    else{
        if(valor < raiz->valor){
            raiz->esq = inserir(raiz->esq, valor);
        }
        else{
            raiz->dir = inserir(raiz->dir, valor);
        }
         return raiz;
    }     
}

//--------------------PRINTS---------------------------------------------

void preorder(no* raiz){
    if(raiz != NULL){
        printf("[%d]", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
    
}

void inorder(no* raiz){
    if(raiz != NULL){
        inOrdem(raiz->esq);
        printf("[%d]", raiz->valor);
        inOrdem(raiz->dir);
    }
}

void posorder(no* raiz){
    if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("[%d]", raiz->valor);
    }
}

//--------------------------------------------------------------------

no* menor{
    
}


