
#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAX 100

#define INVALIDO -1;

typedef int TIPOCHAVE;

typedef struct {
 TIPOCHAVE codigo;
 char nome_bebida [70];
 int idade_bebida;
 int quantidade;
} WHISKY;

typedef struct {
WHISKY W[MAX];
int nroElem;
} LISTABEBIDA;

//PROTÓTIPOS

int tamanhoLista (LISTABEBIDA *l);
void inicializar (LISTABEBIDA *l);
void exibirBebidas (LISTABEBIDA *l);
void insereBebida (LISTABEBIDA*l, WHISKY whis);
int buscaBinaria(LISTABEBIDA *l, int esq, int dir, int cod);
int buscaSequencialBebida(LISTABEBIDA *l, int busca2);
void excluirBebida (LISTABEBIDA *l, int excluir1);
void reinicializarLista (LISTABEBIDA *l);
void alterar(LISTABEBIDA * l, int ch, int nestoque);
void mostrarBusca(LISTABEBIDA *l, int esq, int dir, int cod);

#endif



