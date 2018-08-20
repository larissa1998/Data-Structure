#include "arvore.h"
Pont inicializa(){
    return(NULL);
}
Pont adiciona(Pont raiz, Pont no){
    if(raiz == NULL){
        return(no);
    }
    if(no->chave < raiz->chave){
        raiz->esq = adiciona(raiz->esq, no);
    }else{
        raiz->dir = (adiciona(raiz->dir, no));
    }
    return(raiz);
}

Pont createNode(TIPOCHAVE ch){
Pont newNode = (Pont)malloc(sizeof(NO));
newNode->chave = ch;
newNode->esq = NULL;
newNode->dir = NULL;
return(newNode);
}
