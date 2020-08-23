#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

int quant, i; //VARIÁVEL GLOBAL

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


// -------------------------REMOVER-------------------------------------------

no* remover(no* raiz, int valor){
    if(raiz != NULL){
        no* aux = raiz;
        no* ant = NULL;

        if(existe_elemento(raiz, valor) != 0){

            while(aux != NULL){
                if(valor == aux->valor){
                    //caso 1: remover a folha
                    if(aux->dir == NULL && aux->esq == NULL){
                        if(ant != NULL){
                            if(ant->valor > aux->valor){
                                free(aux);
                                ant->esq = NULL;
                            }
                            else{
                                free(aux);
                                ant->dir = NULL;
                            }
                            return raiz;
                        }
                        else{
                            free(aux);
                            return NULL;
                        }                                   
                    }

                    //caso 3: possui dois filho
                    else if(aux->dir != NULL && aux->esq != NULL){
                        int menorValor = menor(aux->dir);
                        aux->valor = menorValor;
                        aux->dir = remover(aux->dir, menorValor);
                        return raiz;
                    }

                    //caso 2: possui um filho
                    else{
                        if(ant != NULL){
                            if(valor < ant->valor){
                                if(aux->dir != NULL){
                                    free(aux);
                                    ant->esq = aux->dir;
                                    
                                }
                                else{
                                    free(aux);
                                    ant->esq = aux->esq;                            
                                }
                            }
                            else{
                                if(aux->dir != NULL){
                                    free(aux);
                                    ant->dir = aux->dir;                            
                                }
                                else{
                                    free(aux);
                                    ant->dir = aux->esq;                            
                                }
                            }
                            return raiz;
                        }
                        else{
                            if(aux->dir != NULL){
                                raiz = aux->dir;
                                free(aux);                            
                            }
                            else{
                                raiz = aux->esq;
                                free(aux);
                            }
                            return raiz;
                        }
                    }
                }
                else{
                    if(valor > aux->valor){
                        ant = aux;
                        aux = aux->dir;                    
                    }
                    else{
                        ant = aux;
                        aux = aux->esq;
                    }
                }
            }

        }

        else{
            return raiz;
        }
        
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

int predecessor(no* raiz, int valor){
   if(raiz != NULL){
        if(valor == raiz->valor){
           if(raiz->esq != NULL){
               return maior(raiz->esq);
           }
           else{
               return i;
           }
        }
        if(valor < raiz->valor){
            predecessor(raiz->esq, valor);
        }
        else{
            i = raiz->valor;
            predecessor(raiz->dir, valor);
        }      
   }
}

int sucessor(no* raiz, int valor){
    if(raiz != NULL){
        if(valor == raiz->valor){
            if(raiz->dir != NULL){
                return menor(raiz->dir);
            }
            else{
                return i;
            }
        }

        if(valor < raiz->valor){
            i = raiz->valor;
            sucessor(raiz->esq, valor);
        }
        else{
            sucessor(raiz->dir, valor);
        }
    }
}