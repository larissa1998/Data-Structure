#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#define MAX 50
#include <string.h>
#define true 1
#define false 0

typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
TIPOCHAVE codigo;
char livro [100];
char autor[50];
int ISBN;
int ano;
int numero;
}REGISTRO;

typedef struct{
REGISTRO A[MAX];
int topo;
}PILHA;

//---------------PROTÓTIPOS------------------
void inicializarPilhaLivro(PILHA*p);
int tamanhoPilhaLivro(PILHA*p);
void exibirPilhaLivro (PILHA *p);
bool inserirElemLivro(PILHA *p, REGISTRO reg);
bool excluirElemPilha(PILHA *p, REGISTRO *reg);
void reinicializarPilha(PILHA *p);
#endif // PILHA_H_INCLUDED
