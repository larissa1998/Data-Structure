#ifndef ACADEMICO_H_INCLUDED
#define ACADEMICO_H_INCLUDED

typedef struct dados
{
    int RA;
    char nome [100];
    int curso;
} ALUNO;

typedef struct aux2
{
    ALUNO aluno;
    struct dados *prox;
} ELEMENTO;

typedef ELEMENTO* PONT2;

typedef struct
{
    PONT2 inicio;
} LISTA;

typedef struct aux
{
    ALUNO *aluno;
    int h;
    struct aux *esq, *dir;
} NO;

typedef NO * PONT;

///------------------PROTÓTIPO LISTA DINÂMICA---------------------
void inicializarLista(LISTA *l);
void inserirOrdenado(LISTA *l, ALUNO aluno);
void exibirLista(LISTA *l);
void excluirRA (LISTA *l, int ra);
void excluirNome(LISTA *l, char *nome);
PONT2 buscarNomeLista(LISTA *l, char *nome);
PONT2 buscaRALista (LISTA *l, int ra);
PONT2 buscaTudo(LISTA *l, int ra);
void reinicializar(LISTA *l);

///------------------PROTÓTIPOS ÁRVORE AVL-------------------------
PONT inicializar ();
int max(int a, int b);
PONT criarNo(ALUNO *aluno);
int altura(PONT raiz);
int fatorB(PONT raiz);
PONT direita(PONT l) ;
PONT esquerda(PONT r);
PONT esquerdaDireita(PONT lr);
PONT direitaEsquerda(PONT rl) ;
PONT rotacao(PONT raiz);
PONT insereRA(PONT raiz,ALUNO *aluno);
PONT insereNome(PONT raiz, ALUNO *aluno);
void EmOrdem(PONT raiz);
void PreOrdem (PONT raiz);
void PosOrdem (PONT raiz);
PONT procuraNoRA(PONT q, PONT p);
PONT removerRa(PONT raiz, int ra);
int defAltura(PONT p);
PONT removerNome(PONT raiz, char *nome);
PONT procuraNoNome(PONT q, PONT p);
PONT buscarNome(PONT raiz, char *nome);
PONT buscaRA (PONT raiz, int ra);
PONT libera_arvRa(PONT arvRa);
PONT libera_arvNome (PONT arvNome);
#endif // ACADEMICO_H_INCLUDED
