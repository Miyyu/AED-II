#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

int quant; //VARIÁVEL GLOBAL

no* inserir(no* raiz, int valor){
    if(raiz == NULL){
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
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
    
}

void inorder(no* raiz){
    if(raiz != NULL){
        inorder(raiz->esq);
        printf("[%d]", raiz->valor);
        inorder(raiz->dir);
    }
}

void posorder(no* raiz){
    if(raiz != NULL){
        posorder(raiz->esq);
        posorder(raiz->dir);
        printf("[%d]", raiz->valor);
    }
}

//-----------------------(<) & (>)---------------------------------------------

int maior(no* raiz){  //OLHAR
    if(raiz != NULL){
        if(raiz->dir != NULL){
            maior(raiz->dir);
        }
        else{
            return raiz->valor;
        }
    }
}

int menor(no* raiz){  //OLHAR
    if(raiz != NULL){
        if(raiz->esq != NULL){
            menor(raiz->esq);
        }
        else{
            return raiz->valor;
        }    
    }
}

int quantidade_elementos(no* raiz){
    if(raiz != NULL){
        quantidade_elementos(raiz->esq);
        quantidade_elementos(raiz->dir);
        quant += 1;
    }
    else{
        return quant;
    }
}

int existe(no* raiz, int valor){
    if(raiz != NULL){
        if(valor == raiz->valor){
            return 1;
        }
        if(valor < raiz->valor && raiz->esq != NULL){
            existe(raiz->esq, valor);
        }
        else if(valor > raiz->valor && raiz->dir != NULL){
            existe(raiz->dir, valor);
        }
        else{
            return 0;
        }        
    }
}


