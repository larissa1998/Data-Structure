#ifndef WHIS_H_INCLUDED
#define WHIS_H_INCLUDED
#define MAX 50


typedef struct {
 int codigo_whisky;
 char nome_whisky [40];
 int idade_bebida;
 int estoque;
} REGISTRO;

typedef struct {
REGISTRO A[MAX];
int numeroElem;
} LISTA;

//------------PROTÓTIPOS----------------

void menuPrincipal();
void inicio(LISTA *l);
void exibirDrink (LISTA *l);
int tamLista(LISTA *l);
void insereBebida (LISTA *l, REGISTRO elem);
void reiniciar (LISTA *l);
int buscaSeq (LISTA *l, REGISTRO elem);
void excluir(LISTA * l, REGISTRO elem);
#endif



