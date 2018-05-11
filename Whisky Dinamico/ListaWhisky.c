#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaWhisky.h"

void inicializar(LISTA *l){
    l->inicio=NULL;
}

void imprime(LISTA *l, REGISTRO reg){
    int i;
    PONT aux=l->inicio;
    while(aux!=NULL){
        printf("\n");
        printf("\n Codigo: %d", aux->reg.codigoProduto);
        printf("\n Nome: %s", aux->reg.nome);
        fflush(stdin);
        printf("\n Preço: %d", aux->reg.preco);
        printf("\n Idade: %d", aux->reg.idade);
        printf("\n País: %s", aux->reg.pais);
        printf("\n Quantidade: %d  \n", aux->reg.quantidadeEstoque);

        aux=aux->prox;
    }
    system("PAUSE");
}

void inserirElemOrdenadoIdade(LISTA *l, REGISTRO elem){
    PONT atual=NULL;
    PONT ant=NULL;
    PONT novo=NULL;

    novo=(PONT) malloc(sizeof(ELEMENTO));
    if(novo==NULL){
        printf("\n\n Erro de alocação: inserirElemOrdenado");
        return;
    }
    novo->reg=elem;
    novo->prox=NULL;

    atual=l->inicio;

    while(atual!=NULL && atual->reg.idade<elem.idade){
        ant=atual;
        atual=atual->prox;
    }

    novo->prox=atual;

    if(ant==NULL){
        l->inicio=novo;
    }
    else{
        ant->prox=novo;
    }
}

void inserirElemOrdenadoQuantidade(LISTA *l, REGISTRO elem){
    PONT atual=NULL;
    PONT ant=NULL;
    PONT novo=NULL;

    novo=(PONT) malloc(sizeof(ELEMENTO));

    if(novo==NULL){
        printf("\n\n Erro de alocação: inserirElemOrdenado");
        return;
    }
    novo->reg=elem;
    novo->prox=NULL;

    atual=l->inicio;

    while(atual!=NULL && atual->reg.quantidadeEstoque<elem.quantidadeEstoque){
        ant=atual;
        atual=atual->prox;
    }

    novo->prox=atual;

    if(ant==NULL){
        l->inicio=novo;
    }
    else{
        ant->prox=novo;
    }
}

void inserirElemOrdenadoPais(LISTA *l, REGISTRO elem){
    PONT atual=NULL;
    PONT ant=NULL;
    PONT novo=NULL;

    novo=(PONT) malloc(sizeof(ELEMENTO));

    if(novo==NULL){
        printf("\n\n Erro de alocação: inserirElemOrdenado");
        return;
    }
    novo->reg=elem;
    novo->prox=NULL;

    atual=l->inicio;

    while(atual!=NULL && atual->reg.pais<elem.pais){
        ant=atual;
        atual=atual->prox;
    }

    novo->prox=atual;

    if(ant==NULL){
        l->inicio=novo;
    }
    else{
        ant->prox=novo;
    }
}

PONT buscaElemento(LISTA *l, int code){
    printf("\n Informe o código que deseja buscar: \n");
    scanf("%d", &code);

    PONT aux=l->inicio;

    while(aux!=NULL && aux->reg.codigoProduto != code){
        aux=aux->prox;
    }
    printf("\n");
    printf("\n Codigo: %d", aux->reg.codigoProduto);
    printf("\n Nome: %s", aux->reg.nome);
    fflush(stdin);
    printf("\n Preço: %d", aux->reg.preco);
    printf("\n Idade: %d", aux->reg.idade);
    printf("\n País: %s", aux->reg.pais);
    printf("\n Quantidade: %d  \n", aux->reg.quantidadeEstoque);

    if(aux!=NULL && aux->reg.codigoProduto != code) return(aux);
    return (NULL);
}

void excluirElemento(LISTA *l, int exclui){
    printf("\n Qual produto deseja excluir: \n");
    scanf("%d", &exclui);

    PONT atual=l->inicio;
    PONT ant=NULL;

    while(atual!=NULL && atual->reg.codigoProduto<exclui){
    ant=atual;
    atual=atual->prox;
    }
    if(atual==NULL){
        printf("\n Nao houve exclusao");
    }
    else{
        if(atual->reg.codigoProduto!=exclui){
            printf("\n Nao houve exclusao");
        }
        else{
            if(ant==NULL){
                l->inicio=atual->prox;
            }
            else{
                ant->prox=atual->prox;
            }
            free(atual);
            printf("\n Elemento excluido com sucesso!!");

        }
    }
}
void reinicializa(LISTA *l){
    PONT aux=l->inicio;

    while(aux!=NULL){
        l->inicio=l->inicio->prox;
        free(aux);
        aux=l->inicio;
    }
}

