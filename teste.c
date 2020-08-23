#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    no* raiz;
    raiz = NULL;
    no* x;
    no* y;


    while(1 == 1){
        int opcao;
        scanf("%d", &opcao);

        switch(opcao){
            int valor;
            case 1:
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            
            case 2:
                preorder(raiz);
                break;

            case 3:
                inorder(raiz);
                break;

            case 4:
                posorder(raiz);
                break;

            case 5:
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                break;

            case 6:
                x = maior(raiz);
                printf("[%d]", x->valor);
                break;

            case 7:
                y = menor(raiz);
                printf("[%d]", y->valor);
                break;
            
            case 8:
                printf("[%d]", altura(raiz));
                break;

            case 9:
                printf("[%d]", quantidade_elementos(raiz)); 
                break;

            case 10:
                scanf("%d", &valor);
                printf("[%d]", existe_elemento(raiz, valor));  
                break;

            case 11:
                scanf("%d", &valor);
                x = predecessor(raiz, valor);
                printf("[%d]", x->valor);
                break;

            case 12:
                scanf("%d", &valor);
                y = sucessor(raiz, valor);
                printf("[%d]", y->valor);
                break;

            case 99:
                exit(0);
        }
    }
}
