#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAX 50
#define INVALIDO -1

typedef int TIPOCHAVE;

typedef struct {
TIPOCHAVE chave;
}REGISTRO;

typedef struct aux {
REGISTRO reg;
struct aux*prox;
struct aux*ant;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
PONT inicio;
PONT fim;
}LISTA;


//-------------------PROTÓTIPOS---------------------

void inicializarLista (LISTA *l);

PONT buscaSequencial(LISTA *l, TIPOCHAVE ch, PONT *ant);

PONT buscaSequencial2(LISTA *l, TIPOCHAVE ch, PONT *ant);

void inicializa(PONT ponteiro);

int tamanhoLista(LISTA *l);

void imprime(LISTA *l);

void inserirElemOrdenado (LISTA *l, REGISTRO reg);

void inserirElemDesordenado1 (LISTA *l, REGISTRO reg);

LISTA concatenarListas(LISTA *l1, LISTA *l2, LISTA  *l3);

void reinicializar (LISTA *l);

#endif // LISTA_H_INCLUDED
