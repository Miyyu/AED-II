#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    no* raiz;
    raiz = NULL;

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
                printf("\n"); //Apagar depois
                break;

            case 3:
                inorder(raiz);
                printf("\n"); //Apagar depois
                break;

            case 4:
                posorder(raiz);
                printf("\n"); //Apagar depois
                break;

            case 5:
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                break;

            case 6:
                printf("[%d]", maior(raiz));
                break;
            
            case 7:
                printf("[%d]", menor(raiz));
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
                printf("[%d]", predecessor(raiz, valor));
                break;

            case 12:
                scanf("%d", &valor);
                printf("[%d]", sucessor(raiz, valor));
                break;

            case 99:
                exit(0);
        }
    }
}
