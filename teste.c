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

            case 6:
                printf("MAIOR[%d]", maior(raiz)); //OLHAR DEPOIS
                break;

            case 7:
                printf("MENOR[%d]", menor(raiz)); //OLHAR DEPOIS
                break;
            
            case 9:
                printf("QUANT[%d]", quantidade_elementos(raiz)); //OLHAR DEPOIS
                break;
            case 10:
                scanf("%d", &valor);
                printf("Existe: %d ", existe(raiz, valor));  //OLHAR DEPOIS
                break;

            case 99:
                exit(0);
        }
    }
}
