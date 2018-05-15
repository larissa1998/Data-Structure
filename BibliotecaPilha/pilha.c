#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "pilha.h"

void inicializarPilhaLivro(PILHA*p){
p->topo = -1;
}

int tamanhoPilhaLivro (PILHA*p){
return p->topo +1;
}

bool inserirElemLivro(PILHA *p, REGISTRO reg){
    if(p->topo >= MAX-1) return false;
    p->topo = p->topo+1;

    p->A[p->topo]= reg;

    return true;
}

void exibirPilhaLivro(PILHA *p){
setlocale(LC_ALL, "PORTUGUESE");
printf("Pilha:\n");

int i;

for(i=p->topo;i>=0;i--){
    printf("\nCódigo: %i",p->A[i].codigo);
    printf("\nLivro: %s",p->A[i].livro);
    printf("\nAutor: %s",p->A[i].autor);
    printf("\nAno: %i",p->A[i].ano);
    printf("\nNúmero de páginas: %i",p->A[i].numero);
    printf("\nISBN: %i",p->A[i].ISBN);
    printf("\n");
}
printf("\n");
}

bool excluirElemPilha(PILHA *p, REGISTRO *reg){
    if(p->topo == -1) return false;
    *reg = p->A[p->topo];
    p->topo = p->topo-1;
    return true;
}

void reinicializarPilha(PILHA *p){
inicializarPilhaLivro(&p);
}
