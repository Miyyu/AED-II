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

            /*case 6:
                printf("MAIOR[%d]", maior(raiz));
                break;
            
            case 7:
                printf("MENOR[%d]", menor(raiz));
                break;*/

            case 6:
                x = maior(raiz);
                printf("MAIOR[%d]", x->valor) ;//OLHAR DEPOIS
                break;

            case 7:
                y = menor(raiz);
                printf("MENOR[%d]", y->valor); //OLHAR DEPOIS
                break;
            
            case 8:
                printf("Altura: [%d]", altura(raiz));
                break;

            case 9:
                printf("QUANT[%d]", quantidade_elementos(raiz)); //OLHAR DEPOIS
                break;

            case 10:
                scanf("%d", &valor);
                printf("Existe: %d ", existe_elemento(raiz, valor));  //OLHAR DEPOIS
                break;

            case 11:
                scanf("%d", &valor);
                x = predecessor(raiz, valor);
                printf("PRE[%d]", x->valor);
                break;

            case 12:
                scanf("%d", &valor);
                y = sucessor(raiz, valor);
                printf("SUCES[%d]", y->valor);
                break;

            case 99:
                exit(0);
        }
    }
}
