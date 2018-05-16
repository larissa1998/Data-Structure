#include "pilha.h"

void  inicializar(PILHA *p){
p->topo = NULL;
}

int tamanho_Lista (PILHA *p){
PONT aux = p->topo;

int tam = 0;

while (aux != NULL){
    tam ++;
    aux = aux->prox;
}
return tam;
}

void exibir (PILHA *p){
PONT aux = p->topo;

while (aux != NULL){
    printf("Pilha :%d", aux->reg.chave);
    printf("\n");
    aux = aux->prox;
}
}

void inserir(PILHA*p, REGISTRO reg){
PONT novo = NULL;

novo = (PONT) malloc(sizeof(ELEMENTO));

if(novo == NULL){
    printf("erro de alocacao");
    return;
}

    novo->reg=reg;
    novo->prox=p->topo;
    p->topo = novo;
}

void excluir(PILHA*p, REGISTRO reg){
PONT atual = p->topo;
PONT ant = NULL;
}

void reinicializar (PILHA *p){
PONT aux = p->topo;

if(aux==NULL){
    printf("\n não há como excluir elemento !! ");
    return;
}
p->topo = p->topo->prox;;
free(aux);
}
