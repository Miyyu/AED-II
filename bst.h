#ifndef BST_H
#define BST_H

typedef struct no{
    int valor;
    struct no* esq;
    struct no* dir;
}no;

//Op 1
no* inserir(no* raiz, int valor);
//Op 2
void preorder(no* raiz);
//Op 3
void inorder(no* raiz);
//Op 4
void posorder(no* raiz);
//Op 5
no* remover(no* raiz, int valor);
//Op 6
int maior(no* raiz);
//Op 7
int menor(no* raiz);
//Op 8
int altura(no* raiz);
//Op 9
int quantidade_elementos(no* raiz);
//Op 10
int existe_elemento(no* raiz, int valor); //Retornar 1(existe) ou 0(não existe)
//Op 11
int predecessor(no* raiz, int valor);
//Op 12
int sucessor(no* raiz, int valor); 

#endif



