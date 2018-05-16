#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include <stdio.h>
#define MAX 50

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT topo;
}PILHA;

void excluir(PILHA*p, REGISTRO reg);
void reinicializar (PILHA *p);
void inserir(PILHA*p, REGISTRO reg);
void exibir (PILHA *p);
int tamanho_Lista (PILHA *p);
void  inicializar(PILHA *p);
#endif // PILHA_H_INCLUDED
