#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;

} REGISTRO;

typedef struct aux
{
    REGISTRO reg;
    struct aux * prox;
} ELEMENTO;

typedef ELEMENTO * PONT;

typedef struct
{
    PONT inicio;
    PONT fim;
    int nroElem;
} FILA;

//------PROTÓTIPOS---------
void inicializar (FILA * f);
int tamanhoFila(FILA*f);
void exibirFila (FILA * f);
void inserir(FILA *f, REGISTRO reg);
int excluirElem (FILA * f);
void reinicializar (FILA * f);
#endif // FILA_H_INCLUDED
