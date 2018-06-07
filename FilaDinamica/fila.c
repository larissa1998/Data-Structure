#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "fila.h"

void inicializar (FILA * f)
{
    f->inicio = NULL;
    f->fim = NULL;
    f->nroElem = 0;
}


int tamanhoFila(FILA*f)
{
    return (f->nroElem);
}

void exibirFila (FILA * f)
{
    PONT p = NULL;

    if(f->inicio == NULL)
    {
        printf("Fila vazia");
        return;
    }

    for(p=f->inicio; p!=NULL; p=p->prox)
    {
        printf("Elemento |%d|", p->reg.chave);
        printf("\n");
    }
}

void inserir(FILA *f, REGISTRO reg)
{
    PONT novo =NULL;


    novo = (PONT) malloc(sizeof(ELEMENTO));

    if (novo == NULL)
    {
        printf("Nao alocou memoria");
        return;
    }

    novo->reg = reg;
    novo->prox = NULL;

    if(f->fim == NULL)
    {
        f->fim = novo;
        f->inicio = novo;
        //ou pode ser tambem
        //f->inicio=f->fim =novo;
    }

    else
    {

        f->fim->prox = novo;
        f->fim = novo;
    }
    f->nroElem = f->nroElem +1;
}

int excluirElem (FILA * f)
{
    PONT aux = f->inicio;

    if(aux == NULL) return (-1);

    f->inicio = aux->prox;

    if(f->inicio == NULL) f->fim = NULL;

    free (aux);
    f->nroElem = f->nroElem -1;

    return (1);
}

void reinicializar (FILA * f)
{
   while (excluirElem(f)!= 0);
}


