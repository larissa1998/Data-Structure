#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef int TIPOCHAVE;

typedef struct {
TIPOCHAVE chave;
}REGISTRO;

typedef struct aux {
REGISTRO reg;
struct aux*prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
PONT inicio;
}LISTA;


void inicializarLista (LISTA *l);
void inserir_elemento (LISTA *l, REGISTRO reg);
void imprime(LISTA *l);
int buscaElemento(LISTA *l, TIPOCHAVE chave);
void exclui_elemento(LISTA *l, TIPOCHAVE ch);
#endif // LISTA_H_INCLUDED
