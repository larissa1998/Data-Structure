#ifndef WHISKY_H_INCLUDED
#define WHISKY_H_INCLUDED
#define MAX 50
#define INVALIDO -1

typedef int TIPOCHAVE;

typedef struct {
TIPOCHAVE codigo;
int prox;
char nome [60];
int preco;
int idade;
char pais [60];
int estoque;
}REGISTRO;

typedef struct {
REGISTRO A[MAX];
int dispo;
int inicio;
int nroElem;
}LISTA;


//---------------PROTÓTIPOS DAS FUNÇÕES DO whisky.c-----------------
void sistema ();
void menu ();
void inicializaLista(LISTA *l);
void tamanhoLista(LISTA *l);
void exibirLista (LISTA *l);
void inserir_idade_Ordenado (LISTA *l, REGISTRO elem);
void inserir_estoque_Ordenado (LISTA *l, REGISTRO elem);
void inserir_pais_Ordenado (LISTA *l, REGISTRO elem);
int busca_elemento(LISTA *l, int codigo);
void excluir_elemento (LISTA *l, int codigo);
void alterar(LISTA * l, int chave, int novo);
void reinicializarLista (LISTA *l);

#endif
