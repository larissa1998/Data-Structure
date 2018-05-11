#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define MAX 50


typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

typedef struct{
    char nome[100];
    char endereco[100];
    char telefone[15];
    char email[50];
}AGENDA;


typedef struct {
    AGENDA A[MAX];
    int nroElem;
} LISTA;


#endif // LISTA_H_INCLUDED
