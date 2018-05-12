#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include "Lista.h"


void inicializarLista (LISTA *l){
l->inicio=NULL;
l->fim = NULL;
}

int tamanhoLista(LISTA *l){
    int tam = 0;

    PONT aux = l->inicio;

    while(aux != NULL){
        tam++;
        aux = aux->prox;
    }

    return tam;
}

void imprime(LISTA *l){

    PONT aux = l->inicio;

    if(tamanhoLista(l) != 0){
        printf("Lista:");
    }

    while(aux!= NULL){
        printf("|%d", aux->reg.chave);
        aux = aux->prox;
    }
    printf("\n");
}

PONT buscaSequencial(LISTA *l, TIPOCHAVE ch, PONT *ant){
    *ant = NULL;
    PONT atual = l->inicio;

    while(atual != NULL && atual->reg.chave < ch){
        *ant = atual;
        atual = atual->prox;
    }

    return atual;
}

PONT buscaSequencial2(LISTA *l, TIPOCHAVE ch, PONT *ant){
    *ant = NULL;
    PONT atual = l->inicio;

    while(atual != NULL && atual->reg.chave > ch){
        *ant = atual;
        atual = atual->prox;
    }

    return atual;
}

void inserirElemOrdenado(LISTA *l, REGISTRO reg){
    TIPOCHAVE ch = reg.chave;
    PONT ant = NULL;
    PONT i=NULL, aux=NULL;

    aux = buscaSequencial(l, ch, &ant);

    if(aux != NULL && aux->reg.chave == ch){
        return INVALIDO;
    }

    aux = (PONT) malloc(sizeof(ELEMENTO));
    inicializa(aux);
    aux->reg = reg;

    if(ant == NULL){
        aux->prox = l->inicio;

        if(l->inicio != NULL){
            l->inicio->ant = aux;
        }
        l->inicio = aux;

        if(aux->prox == NULL){
            l->fim = aux;
        }
    }

    else{
        aux->prox = ant->prox;

        if(ant->prox != NULL){
            ant->prox->ant = aux;
        }
        aux->ant = ant;
        ant->prox = aux;

        if(aux->prox == NULL){
            l->fim = aux;
        }
    }
    return 0;
}

void inserirElemDesordenado1(LISTA *l, REGISTRO reg){
    TIPOCHAVE ch = reg.chave;
    PONT ant = NULL;
    PONT i=NULL, aux=NULL;

    aux = buscaSequencial2(l, ch, &ant);

    if(aux != NULL && aux->reg.chave == ch){
        return INVALIDO;
    }

    aux= (PONT) malloc(sizeof(ELEMENTO));
    inicializa(aux);
    aux->reg = reg;

    if(ant == NULL){
        aux->prox = l->inicio;

        if(l->inicio != NULL){
            l->inicio->ant = aux;
        }
        l->inicio = aux;

        if(aux->prox == NULL){
            l->fim = aux;
        }
    }
    else{
        aux->prox = aux->prox;

        if(ant->prox != NULL){
            ant->prox->ant = aux;
        }
        aux->ant = ant;
        ant->prox = aux;

        if(aux->prox == NULL){
            l->fim = aux;
        }
    }
    return 0;
}

void inicializa(PONT ponteiro){
    ponteiro->ant = NULL;
    ponteiro->prox = NULL;
}


LISTA concatenarListas(LISTA *l1, LISTA *l2, LISTA  *l3){
    LISTA l4;
    l4.inicio= l1->inicio;
    l4.fim = l1->fim;
    PONT auxiliar, current;
    int tamanhol2 = tamanhoLista(l2);
    int tamanhol3= tamanhoLista(l3);
    auxiliar = l2->fim;
    current = l3->fim;

    while(auxiliar != current){

        if(auxiliar == NULL){

            while (current != NULL){
                inserirElemOrdenado(&l4, current->reg);
                current = current->ant;
            }

            break;
        }else if(current == NULL){

            while(auxiliar != NULL){
                inserirElemOrdenado(&l4, auxiliar->reg);
                auxiliar = auxiliar->ant;
            }

            break;
        }

        if(auxiliar->reg.chave < current->reg.chave){
            inserirElemOrdenado(&l4, auxiliar->reg);
            auxiliar = auxiliar->ant;
        }

        else if(current->reg.chave < auxiliar->reg.chave){
            inserirElemOrdenado(&l4, current->reg);
            current = current->ant;
        }

        else if(auxiliar->reg.chave == current->reg.chave){
            inserirElemOrdenado(&l4, auxiliar->reg);
            auxiliar = auxiliar->ant;
            current = current->ant;
        }
    }
    imprime(&l4);
    return l4;
}

void reinicializar (LISTA *l){
PONT aux = l->inicio;

while (aux != NULL){

    l->inicio =l->inicio->prox;
    free(aux);
    aux=l->inicio;
}
}
