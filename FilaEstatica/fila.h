#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define MAX 9

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX];
    int nmrElem;
    int inicio;
} FILA;

//----------PROTÓTIPOS--------
void inicializarFila(FILA *f);
int tamanhoFila(FILA *f);
void exibirFila(FILA *f);
int buscaSequencial(FILA *l, int elem);
int inserirElemFila(FILA *f, REGISTRO reg);
int excluirElemFila(FILA *f);
void reinicializarFila(FILA *f);
#endif // FILA_H_INCLUDED
