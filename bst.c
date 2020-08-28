#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

no* inserir(no* raiz, int chave){
    if(raiz == NULL){
        no* novo = (no*) malloc(sizeof(no));
        novo->dir = NULL;
        novo->esq = NULL;
        novo->chave = chave;
        return novo;
    }
    else{
        if(chave < raiz->chave){
            raiz->esq = inserir(raiz->esq, chave);
        }
        else{
            raiz->dir = inserir(raiz->dir, chave);
        }
         return raiz;
    }     
}

//--------------------PRINTS---------------------------------------------

void preorder(no* raiz){
    if(raiz != NULL){
        printf("[%d]", raiz->chave);
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
    
}

void inorder(no* raiz){
    if(raiz != NULL){
        inorder(raiz->esq);
        printf("[%d]", raiz->chave);
        inorder(raiz->dir);
    }
}

void posorder(no* raiz){
    if(raiz != NULL){
        posorder(raiz->esq);
        posorder(raiz->dir);
        printf("[%d]", raiz->chave);
    }
}

// -------------------------REMOVER-------------------------------------------

no* remover(no* raiz, int chave){
    if(raiz != NULL){
        no* aux = raiz;
        no* ant = NULL;

        if(existe(raiz, chave) != 0){

            while(aux != NULL){
                if(chave == aux->chave){
                    //caso 1: não possui filho
                    if(aux->dir == NULL && aux->esq == NULL){
                        if(ant != NULL){ //Verificando se minha raiz só tem um chave
                            if(ant->chave > aux->chave){
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
                        no* menorchave = menor(aux->dir);
                        aux->chave = menorchave->chave;
                        aux->dir = remover(aux->dir, menorchave->chave);
                        return raiz;
                    }

                    //caso 2: possui um filho
                    else{
                        if(ant != NULL){ //Verificando se minha árvore só tem 2 chavees
                            if(chave < ant->chave){
                                if(aux->dir != NULL){
                                    ant->esq = aux->dir;
                                    free(aux);
                                    
                                }
                                else{
                                    ant->esq = aux->esq;
                                    free(aux);                            
                                }
                            }
                            else{
                                if(aux->dir != NULL){
                                    ant->dir = aux->dir;  
                                    free(aux);                          
                                }
                                else{
                                    ant->dir = aux->esq;
                                    free(aux);                           
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
                    if(chave > aux->chave){
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

no* maior(no* raiz){
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
        int quantE = quantidade_elementos(raiz->esq);
        int quantD = quantidade_elementos(raiz->dir);
        return quantE + quantD + 1;
    }
    else{
        return 0;
    }
}

//-------------------------------EXISTE-----------------------------------

int existe(no* raiz, int chave){
    if(raiz != NULL){
        if(chave == raiz->chave){
            return 1;
        }
        if(chave < raiz->chave && raiz->esq != NULL){
            existe(raiz->esq, chave);
        }
        else if(chave > raiz->chave && raiz->dir != NULL){
            existe(raiz->dir, chave);
        }
        else{
            return 0;
        }        
    }
}

no* predecessor(no* raiz, int chave){
    if(raiz != NULL){
        no* aux = raiz;
        no* i = NULL;

        while(aux != NULL){
            if(chave == aux->chave){
                if(aux->esq != NULL){
                    return maior(aux->esq);
                }
                else{
                    if(i != NULL){
                        return i;
                    }
                }
            }
            if(chave > aux->chave){
                i = aux;
                aux = aux->dir;
            }
            else{
                aux = aux->esq;
            }
        }

    }
    else{
        return NULL;
    }
}

no* sucessor(no* raiz, int chave){
    if(raiz != NULL){
        no* aux = raiz;
        no* i = NULL;

        while(aux != NULL){
            if(chave == aux->chave){
                if(aux->dir != NULL){
                    return menor(aux->dir);
                }
                else{
                    if(i != NULL){
                        return i;
                    }
                }
            }
            if(chave > aux->chave){
                aux = aux->dir;
            }
            else{
                i = aux;
                aux = aux->esq;
            }
        }        
    }
}