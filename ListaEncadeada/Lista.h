#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAX 50
#define INVALIDO -1
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
    //demais informações
    int prox;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int nroElem;
    int dispo;
    int inicio;
}LISTA;

void inicializa(LISTA *l);
void imprimeLista(LISTA *l);
void inserir_elemento_ordenado(LISTA *l, REGISTRO reg);
int busca_elemento(LISTA *l, TIPOCHAVE chave);
int tamanho (LISTA *l);
void reinicializarLista (LISTA *l);
void excluir_elemento (LISTA *l, TIPOCHAVE ch);
#endif // LISTA_H_INCLUDED

