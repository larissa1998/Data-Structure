#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void inicializarPilha(PILHA*p){
p->topo = -1;
}

int tamanhoPilha (PILHA*p){
return p->topo +1;
}

void exibir (PILHA *p){
printf("Pilha:");

int i;

for(i=p->topo;i>=0;i--){
    printf("|");
    printf("%i",p->A[i].chave);
    printf("|");
}
printf("\n");
}

bool inserirElem(PILHA *p, REGISTRO reg){
    if(p->topo >= MAX-1) return false;
    p->topo = p->topo+1;
    p->A[p->topo] = reg;
    return true;
}

bool excluirElem(PILHA *p, REGISTRO *reg){
    if(p->topo == -1) return false;
    *reg = p->A[p->topo];
    p->topo = p->topo-1;
    return true;
}

void reinicializar(PILHA *p){
p->topo = -1;
}
