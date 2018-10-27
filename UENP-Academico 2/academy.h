#ifndef ACADEMY_H_INCLUDED
#define ACADEMY_H_INCLUDED
#define VALIDO 1
#define SI 40
#define CC 12
#define VET 50
#define BIO 20
#define ENF 30
#define AGRO 10

typedef struct a
{
    int RA_aluno;
    char nome_aluno [70];
    int curso_aluno;
} ALUNO;

typedef struct auxiliar
{
    ALUNO aluno;
    struct a *prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct
{
    PONT inicio;
} LISTA;

typedef struct aux
{
    ALUNO *aluno;
    int altura1;
    struct aux *esq, *dir;
} NO;

typedef NO * PONTEIRO;


///--------------------PROTÓTIPOS DAS FUNÇÕES DA LISTA ------------------------------------
void limparTela();
void sair_Sistema ();
void Limpar_Lista(LISTA *l);
void inicializar(LISTA *l);
void exibir(LISTA *l);
int inserir (LISTA *l, ALUNO aluno);
void excluirRa (LISTA *l, int ra);
void excluirNome(LISTA *l, char *nome);
int buscar (LISTA *l, int ra, char *nome);
PONT buscarRepetidos(LISTA *l, int ra);
PONT buscarCursos (LISTA *l, int ra);

///--------------------PROTÓTIPOS DAS FUNÇÕES DA ÁRVORE AVL-------------------------------------
PONTEIRO inicializar_Arvore ();
int max(int a, int b);
int altura(PONTEIRO raiz);
int defAltura(PONTEIRO p);
PONTEIRO criarNoArv(ALUNO *aluno);
int fatorBalanceamento(PONTEIRO raiz);
PONTEIRO esquerda(PONTEIRO r);
PONTEIRO direita(PONTEIRO r);
PONTEIRO esquerdaDireita(PONTEIRO r);
PONTEIRO direitaEsquerda(PONTEIRO r);
PONTEIRO rotacao(PONTEIRO raiz);
PONTEIRO inserir_Arvore_RA(PONTEIRO raiz, ALUNO *aluno);
PONTEIRO insere_Arvore_Nome(PONTEIRO raiz, ALUNO *aluno);
PONTEIRO procura_RA(PONTEIRO q, PONTEIRO p);
PONTEIRO procura_Nome(PONTEIRO q, PONTEIRO p);
void PosOrdem (PONTEIRO raiz);
void PreOrdem (PONTEIRO raiz);
void EmOrdem(PONTEIRO raiz);
PONTEIRO buscarArvoreRA(PONTEIRO raiz, int ra);
PONTEIRO buscarArvoreNome (PONTEIRO raiz, char *nome);
PONTEIRO remover_Nome(PONTEIRO raiz, char *nome);
PONTEIRO removerRa(PONTEIRO raiz, int ra);
PONTEIRO liberaNome(PONTEIRO raizNome);
PONTEIRO liberaRA(PONTEIRO raizRa);
#endif // ACADEMY_H_INCLUDED
