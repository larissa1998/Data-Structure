#include <stdio.h>
#include <stdlib.h>
#include "whisky.h"
#include <locale.h>
#include <string.h>
#include <windows.h>

void sistema (){
system("pause");
system("cls");
}

void menu (){

setlocale(LC_ALL, "PORTUGUESE");



printf("          MENU DE WHISY\n");
printf("-----------------------------------");
printf("\n[1] - Inserir");
printf("\n[2] - Exibir");
printf("\n[3] - Buscar ");
printf("\n[4] - Excluir da lista");
printf("\n[5] - Alterar estoque da bebida");
printf("\n[6] - Reinicializar lista");
printf("\n[7] - Sair do sistema\n");
printf("-----------------------------------\n");
}


void inicializaLista(LISTA *l){

int i;

 l->nroElem =0;
 l->inicio = INVALIDO;
 l-> dispo = 0;

for (i=0; i<MAX-1; i++){

 l->A[i].prox = i+1;

}

l->A[MAX-1].prox = INVALIDO;

}

void tamanhoLista (LISTA *l){
int i = l->inicio;
int tam = 0;

while (i!=INVALIDO){
    tam ++;
    l->A[i].prox;
}

return tam;

}

void exibirLista (LISTA *l){
int i;

for(i=l->inicio; i!= INVALIDO; i=l->A[i].prox){

    printf("Whisky \n");
    printf("\n [%d] Codigo bebida: %d", i, l->A[i].codigo);
    printf("\n [%d] Nome da bebida: %s", i ,l->A[i].nome);
    printf("\n [%d] País: %s", i ,l->A[i].pais);
    printf("\n [%d] Preço: %d", i, l->A[i].preco);
    printf("\n [%d] Idade: %d", i ,l->A[i].idade);
    printf("\n [%d] Estoque: %d\n\n", i, l->A[i].estoque);
    }
}

void inserir_idade_Ordenado (LISTA *l, REGISTRO elem){
    int ant = INVALIDO;
    int atual;
    int aux_dispo=l->dispo==-1?1:l->A[l->dispo].prox;
    if(l->dispo == INVALIDO)
    return INVALIDO;
    l->A[l->dispo].codigo=elem.codigo;
    strcpy(l->A[l->dispo].nome,elem.nome);
    strcpy(l->A[l->dispo].pais,elem.pais);
    l->A[l->dispo].preco=elem.preco;
    l->A[l->dispo].idade=elem.idade;
    l->A[l->dispo].estoque=elem.estoque;

    l->nroElem=l->nroElem+1;

    atual=l->inicio;

    while(atual >=0 && l->A[atual].idade < elem.idade){
        ant=atual;
        atual=l->A[atual].prox;
    }

    if(/*atual == INVALIDO &&*/ ant == INVALIDO){
        l->A[l->dispo].prox=l->inicio;
        l->inicio=l->dispo;
    }
    else{
        l->A[ant].prox=l->dispo;
        l->A[l->dispo].prox=atual;
    }

    l->dispo=aux_dispo;
    return (1);
}


void inserir_estoque_Ordenado (LISTA *l, REGISTRO elem){
    int ant = INVALIDO;
    int atual;
    int aux_dispo=l->dispo==-1?1:l->A[l->dispo].prox;
    if(l->dispo == INVALIDO)
    return INVALIDO;
    l->A[l->dispo].codigo=elem.codigo;
    strcpy(l->A[l->dispo].nome,elem.nome);
    strcpy(l->A[l->dispo].pais,elem.pais);
    l->A[l->dispo].preco=elem.preco;
    l->A[l->dispo].idade=elem.idade;
    l->A[l->dispo].estoque=elem.estoque;

    l->nroElem=l->nroElem+1;

    atual=l->inicio;

    while(atual >=0 && l->A[atual].estoque < elem.estoque){
        ant=atual;
        atual=l->A[atual].prox;
    }

    if(/*atual == INVALIDO &&*/ ant == INVALIDO){
        l->A[l->dispo].prox=l->inicio;
        l->inicio=l->dispo;
    }
    else{
        l->A[ant].prox=l->dispo;
        l->A[l->dispo].prox=atual;
    }

    l->dispo=aux_dispo;
    return (1);
}

void inserir_pais_Ordenado (LISTA *l, REGISTRO elem){
    int ant = INVALIDO;
    int atual;
    int aux_dispo=l->dispo==-1?1:l->A[l->dispo].prox;
    if(l->dispo == INVALIDO)
    return INVALIDO;
    l->A[l->dispo].codigo=elem.codigo;
    strcpy(l->A[l->dispo].nome,elem.nome);
    strcpy(l->A[l->dispo].pais,elem.pais);
    l->A[l->dispo].preco=elem.preco;
    l->A[l->dispo].idade=elem.idade;
    l->A[l->dispo].estoque=elem.estoque;

    l->nroElem=l->nroElem+1;

    atual=l->inicio;

    while(atual >=0 && l->A[atual].pais < elem.pais){
        ant=atual;
        atual=l->A[atual].prox;
    }

    if(/*atual == INVALIDO &&*/ ant == INVALIDO){
        l->A[l->dispo].prox=l->inicio;
        l->inicio=l->dispo;
    }
    else{
        l->A[ant].prox=l->dispo;
        l->A[l->dispo].prox=atual;
    }

    l->dispo=aux_dispo;
    return (1);
}

int busca_elemento(LISTA *l, int codigo){
    int i = 0;

    if(l->inicio == INVALIDO) return (INVALIDO);

    for(i = l->inicio; i >= 0 && l->A[i].codigo != codigo;i=l->A[i].prox);

    printf("\nWhisky:\n");
    printf("\n [%d] Codigo: %d", i, l->A[i].codigo);
    printf("\n [%d] Nome da bebida: %s", i ,l->A[i].nome);
    printf("\n [%d] Pais de origem: %s", i ,l->A[i].pais);
    printf("\n [%d] Preço: %d", i ,l->A[i].preco);
    printf("\n [%d] Idade: %d", i ,l->A[i].idade);
    printf("\n [%d] Estoque: %d\n", i ,l->A[i].estoque);
    if(i==INVALIDO || (i>=0 && l->A[i].codigo!=codigo)) return(INVALIDO);

    return (i);
}

void excluir_elemento (LISTA *l, int codigo)
{
int ant = INVALIDO;
int atual;

if(l->dispo == INVALIDO){
    printf("\n\n Elemento nao esta na lista: LISTA VAZIA");
    return;
}

atual = l->inicio;
while (atual>=0 && l->A[atual].codigo<codigo){
    ant =atual;
    atual = l->A[atual].prox;
}

if(l->A[atual].codigo == codigo){
    if(ant == -1){
    l->inicio=l->A[atual].prox;
    }

    else {
    l->A[ant].prox = l->A[atual].prox;
    }
    l->A[atual].prox = l->dispo;
    l->dispo = atual;

    l->nroElem = l->nroElem-1;
}
else printf("\n O elemento (%d) nao esta na lista");
}

void alterar(LISTA * l, int chave, int novo)
{
    printf("\nCodigo da bebida: ");
    scanf("%d", &chave);
    fflush(stdin);
    printf("\nNovo estoque: ");
    scanf("%d", &novo);
    fflush(stdin);

    int i = busca_elemento(l,  chave);

    if (i == INVALIDO)
        printf("\nElemento nao esta na lista\n");
    else
    {

        l->A[i].estoque = novo;
        printf("\nNumero %d alterado\n\n", chave);
        printf("Para visualizar a alteração, exiba a lista novamente\n\n");
    }

}
void reinicializarLista (LISTA *l){
 inicializaLista(l);
}


