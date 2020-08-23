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

/*no* maior(no* raiz){
    if(raiz != NULL){
        no* aux = raiz;
        if(aux->dir != NULL){
            maior(aux->dir);
        }
        else{
            return aux;
        }
    }
}

no* menor(no* raiz){  //OLHAR
    if(raiz != NULL){
        no* aux = raiz;
        if(aux->esq != NULL){
            menor(aux->esq);
        }
        else{
            return aux;
        }    
    }
}*/

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

//--------------------------ALTURA-------------------------------------

int altura(no* raiz){
    if(raiz != NULL){
        int dir, esq;
        esq = altura(raiz->esq);
        dir = altura(raiz->dir);

        if(dir > esq){
            return dir + 1;
        }
        else{
            return esq + 1;
        }
    }
    else{
        return 0;
    }
}

//---------------------------QUANTIDADE---------------------------------

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

//-------------------------------EXISTE-----------------------------------

int existe_elemento(no* raiz, int valor){
    if(raiz != NULL){
        if(valor == raiz->valor){
            return 1;
        }
        if(valor < raiz->valor && raiz->esq != NULL){
            existe_elemento(raiz->esq, valor);
        }
        else if(valor > raiz->valor && raiz->dir != NULL){
            existe_elemento(raiz->dir, valor);
        }
        else{
            return 0;
        }        
    }
}

int predecessor(no* raiz){
    if(raiz != NULL){
        
    }
}