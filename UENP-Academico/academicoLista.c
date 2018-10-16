#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "academico.h"

/// --------------------LISTA DINÂMICA---------------------------


void reinicializar(LISTA *l)
{
    PONT aux=l->inicio;
    while(aux!=NULL)
    {
        l->inicio=l->inicio->prox;
        free(aux);
        aux=l->inicio;
    }
}

void inicializarLista(LISTA *l)
{
    l->inicio = NULL;
}

void exibirLista(LISTA *l)
{

    PONT2 aux=l->inicio;

    if(aux == NULL)
    {
        printf("Não temos nada para exibir !\n");
    }

    while(aux!=NULL)
    {

        printf("\n");
        printf("\n RA: %d, Nome: %s, Curso: %d\n", aux->aluno.RA, aux->aluno.nome,aux->aluno.curso);

        aux=aux->prox;
    }

}

void inserirOrdenado(LISTA *l, ALUNO aluno)
{
    PONT2 novo;
    PONT2 novo2;

    if(buscarNomeLista(l, aluno.nome) == 0 && buscaRALista(l,aluno.RA)== 0)
    {


        printf("\n Cadastrado com sucesso\n");

        novo = (PONT) malloc(sizeof(ELEMENTO));
        novo->aluno=aluno;
        novo->prox=NULL;

        if(l->inicio==NULL)
        {

            l->inicio = novo;
        }
        else
        {
            novo2=l->inicio;
            while(novo2->prox !=NULL)
            {
                novo2=novo2->prox;
            }
            novo2->prox = novo;
        }
        return 1;
    }

    else
    {
        printf("\nRA ou nome repetido\n");
        return 0;
    }

}


void excluirRA(LISTA *l, int ra)
{
    PONT2 atual= l->inicio;
    PONT2 ant=NULL;

    while(atual!=NULL && atual->aluno.RA<ra)
    {
        ant = atual;
        atual = atual->prox;
    }
    if(atual==NULL)
    {
        puts("\nNão está na lista, impossível excluir!");
    }
    else
    {
        if(atual->aluno.RA!=ra)
        {
            puts("\nNão está na lista, impossível excluir!");
        }
        else
        {
            if(ant==NULL)
            {
                l->inicio=atual->prox;
            }
            else
            {
                ant->prox=atual->prox;
            }

            free(atual);
            puts("\nO elemento foi excluído com sucesso\n");
        }
    }
}


void excluirNome(LISTA *l, char *nome)
{
    PONT2 atual= l->inicio;
    PONT2 ant=NULL;

    while(atual!=NULL && strcmp(atual->aluno.nome, nome) < 0)
    {
        ant = atual;
        atual = atual->prox;
    }

    if(strcmp(atual->aluno.nome, nome) != 0)
    {
        puts("\nNão está na lista, impossível excluir!\n");
    }
    else
    {
        if(ant==NULL)
        {
            l->inicio=atual->prox;
        }
        else
        {
            ant->prox=atual->prox;
        }

        free(atual);
        puts("\nO elemento foi excluído \n");
    }
}


PONT2 buscarNomeLista(LISTA *l, char *nome)
{

    PONT2 aux= l->inicio;

    while(aux!=NULL && strcmp(aux->aluno.nome,nome)<0)
    {
        aux=aux->prox;

    }
    if(aux!=NULL && strcmp(aux->aluno.nome,nome)==0)
    {

        return 1;
    }
    else
    {
        return 0;
    }

}

PONT2 buscaRALista(LISTA *l, int ra)
{


    PONT2 aux=l->inicio;

    while(aux!=NULL && aux->aluno.RA<ra)
    {
        aux=aux->prox;

    }
    if(aux!=NULL && aux->aluno.RA==ra)
    {

        return 1;
    }
    else
    {
        return 0;
    }

}


PONT2 buscaTudo(LISTA *l, int ra)
{


    PONT2 aux=l->inicio;

    while(aux!=NULL )
    {

        if( ra == 40)
        {
            if (aux->aluno.curso == 40)
            {
                printf("\n");
                printf("RA: %d, Nome: %s, Curso: %d ", aux->aluno.RA,aux->aluno.nome,aux->aluno.curso);
            }
        }

        if( ra == 12)
        {
            if (aux->aluno.curso == 12)
            {
                printf("\n");
                printf("RA: %d, Nome: %s, Curso: %d ", aux->aluno.RA,aux->aluno.nome,aux->aluno.curso);
            }
        }

        if(ra == 20)
        {
            if(aux->aluno.curso == 20)
            {
                printf("\n");
                printf("RA: %d, Nome: %s, Curso: %d ", aux->aluno.RA,aux->aluno.nome,aux->aluno.curso);
            }
        }


        if(ra == 10)
        {
            if(aux->aluno.curso == 10)
            {
                printf("\n");
                printf("RA: %d, Nome: %s, Curso: %d ", aux->aluno.RA,aux->aluno.nome,aux->aluno.curso);
            }
        }

        if(ra == 50)
        {
            if(aux->aluno.curso == 50)
            {
                printf("\n");
                printf("RA: %d, Nome: %s, Curso: %d ", aux->aluno.RA,aux->aluno.nome,aux->aluno.curso);
            }
        }

        if(ra == 30)
        {
            if(aux->aluno.curso == 30)
            {
                printf("\n");
                printf("RA: %d, Nome: %s, Curso: %d ", aux->aluno.RA,aux->aluno.nome,aux->aluno.curso);
            }
        }

        aux=aux->prox;
    }

    if(aux!=NULL && aux->aluno.curso!= ra)
        return(aux);
    return (NULL);
}


