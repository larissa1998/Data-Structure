#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include "Lista.h"

void inicializarLista (LISTA *l){
l->inicio=NULL;
}
void imprime(LISTA *l){
PONT aux = l->inicio;
while (aux!=NULL){
    printf("\t %d", aux->reg.chave);
    aux = aux->prox;
}
}

void reinicializar (LISTA *l){
PONT aux = l->inicio;

while (aux != NULL){

    l->inicio =l->inicio->prox;
    free(aux);
    aux=l->inicio;
}
}

void inserirElemOrdenado (LISTA *l, REGISTRO reg){
PONT atual =NULL;
PONT ant =NULL;
PONT novo = NULL;

novo = (PONT) malloc(sizeof (ELEMENTO));

if(novo == NULL){

    printf("\n\n Erro de alocacao: inserirElemOrdenado");
    return;
}
novo->reg = reg;
novo->prox = NULL;
novo->ant=NULL;

atual = l->inicio;

while(atual !=NULL && atual->reg.chave<reg.chave){
    ant = atual;
    atual = atual->prox;
}
novo->prox = atual;
novo->ant=ant;
if(ant == NULL){
    l->inicio = novo;
if(atual!=NULL) atual ->ant=novo;
} else {
 ant ->prox = novo;
 if(atual!= NULL) atual->ant=novo;
}
}


int buscaElemento(LISTA *l, TIPOCHAVE ch){
PONT aux = l->inicio;
while (aux!=NULL && (aux->reg.chave<ch)){
    aux = aux->prox;
}
if(aux!= NULL && aux->reg.chave == ch) return(aux);
return (NULL);
}

void exclui_elemento(LISTA *l, TIPOCHAVE ch){
PONT atual = l->inicio;
PONT ant = NULL;

while(atual!=NULL && atual->reg.chave<ch){
    ant =atual;
    atual = atual->prox;
}
if(atual == NULL){
    printf("\n\n Nao houve exclusao");
}else{
    if(atual->reg.chave!=ch){

        printf("\n n excluiu");
    }
    else{
        if(ant == NULL){
            l->inicio=atual->prox;
            l->inicio->ant =NULL;
        }
        else{
            ant->prox=atual->prox;
            if(atual->prox!NULL) atual->prox->ant=ant;
        }
        free(atual);
        printf("Elemento excluido com sucesso");
    }
}
}
