#ifndef BST_H
#define BST_H

typedef struct no{
    int valor;
    struct no* dir;
    struct no* esq;
}no;

no* inserir(no* r, int valor);
void preOrdem(no* r);

#endif



