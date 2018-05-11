#include <conio.h>
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int tamanhoLista (LISTABEBIDA *l){
return (l->nroElem);
}

void inicializar (LISTABEBIDA *l){
l->nroElem = 0;
}

void exibirBebidas (LISTABEBIDA *l){
int j;
for (j=0; j<l->nroElem; j++){
    printf("Bebida %i \n", j+1);
    printf("\n (%d) Codigo: %d", j, l->W[j].codigo);
    printf("\n (%d) Nome whisky: %s", j,l->W[j].nome_bebida);
    printf("\n (%d) Idade: %d", j,l->W[j].idade_bebida);
    printf("\n (%d) Estoque: %d\n\n",j, l->W[j].quantidade);
}
}


void insereBebida (LISTABEBIDA*l, WHISKY whis){
int i;

  if(l->nroElem >=MAX){
    printf("\n Lista cheia");
    return;
  }

  for ( i=l->nroElem; i>0 && whis.codigo<l->W[i-1].codigo; i--){
    l->W[i]=l->W[i-1];
  }

  l->W[i]=whis;
  l->nroElem=l->nroElem+1;

}
void mostrarBusca(LISTABEBIDA *l, int esq, int dir, int cod)
{
    int meio;

    if(l->nroElem == 0)
        printf("\nLista vazia !!\n");

    do
    {
        meio = (int) ((esq + dir) / 2);
        if (l->W[meio].codigo > cod)
            dir = meio - 1;

        else if (l->W[meio].codigo < cod)
            esq = meio + 1;

        else
        {
            printf("Bebida %i \n", meio+1);

            printf("\n (%d) Codigo: %d", meio, l->W[meio].codigo);
            printf("\n (%d) Nome whisky: %s", meio,l->W[meio].nome_bebida);
            printf("\n (%d) Idade: %d", meio,l->W[meio].idade_bebida);
            printf("\n (%d) Estoque: %d\n\n",meio, l->W[meio].quantidade);
            return;

        }
    }while(esq < l->nroElem && dir >= 0 && esq <= dir);

    printf("\nBebida nao esta na lista\n");

}

int buscaBinaria(LISTABEBIDA *l, int esq, int dir, int cod)
{
    int meio;

    if(l->nroElem == 0)
       INVALIDO;

    do
    {
        meio = (int) ((esq + dir) / 2);
        if (l->W[meio].codigo > cod)
            dir = meio - 1;

        else if (l->W[meio].codigo < cod)
            esq = meio + 1;

        else
            return(meio);
    }while(esq < l->nroElem && dir >= 0 && esq <= dir);


    INVALIDO;
}

int buscaSequencialBebida(LISTABEBIDA *l, int busca2){
int i;

if(l->nroElem == 0) INVALIDO;

for(i = 0; i<l->nroElem && busca2!= l->W[i].codigo && busca2 >l->W[i].codigo; i++);


    printf("Bebida %i \n", busca2+1);
    printf("\n (%d) Codigo: %d", busca2, l->W[i].codigo);
    printf("\n (%d) Nome whisky: %s", busca2,l->W[i].nome_bebida);
    printf("\n (%d) Idade: %d", busca2,l->W[i].idade_bebida);
    printf("\n (%d) Estoque: %d\n\n",busca2, l->W[i].quantidade);

if(i<l->nroElem && busca2 == l->W[i].codigo) return (i);


else INVALIDO;
}

void excluirBebida (LISTABEBIDA *l, int excluir1){
    int pos = buscaSequencialBebida(l, excluir1);
    if (pos == -1)
        printf ("Bebida nao foi excluida !!");
    else{
        for(pos = 0; pos+1<l->nroElem; pos++)
            l->W[pos]=l->W[pos+1];
        l->nroElem= l->nroElem-1;
    printf (" O codigo (%d) do whisky foi excluido \n", excluir1);

    }
}
void alterar(LISTABEBIDA * l, int ch, int nestoque)
{
    int i = buscaBinaria(l, 0, l->nroElem - 1, ch);

    if (i == -1)
        printf("\nElemento nao esta na lista\n");
    else
    {
        l->W[i].quantidade = nestoque;
        printf("\nNumero do estoque de %d alterado\n", ch);
    }
}

void reinicializarLista (LISTABEBIDA *l){

l->nroElem = 0;
}


