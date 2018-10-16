#include "academico.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

///------------------------ÁRVORE---------------------------------
PONT inicializar ()
{
    return (NULL);
}

PONT criarNo(ALUNO *aluno)
{
    PONT novo = (PONT)malloc(sizeof(NO));
    novo->aluno = aluno;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->h =  0;
    return (novo);
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int defAltura(PONT p)
{
    return (max(altura(p->dir), altura(p->esq)) + 1);
}

int altura(PONT raiz)
{
    if (!raiz)
        return -1;
    return raiz->h;
}

int fatorB(PONT raiz)
{
    return (altura(raiz->esq) - altura(raiz->dir));
}


//ROT LL
PONT direita(PONT l)
{
    PONT aux;
    aux = l->esq;
    l->esq = aux->dir;
    aux->dir = l;
    l->h = max(altura(l->dir), altura(l->esq)) + 1;
    aux->h = max(altura(aux->esq), l->h) + 1;

    return(aux);
}

//ROT RR
PONT esquerda(PONT r)
{
    PONT aux;
    aux = r->dir;
    r->dir = aux->esq;
    aux->esq = r;
    r->h = max(altura(r->dir), altura(r->esq)) + 1;
    aux->h = max(altura(aux->esq), r->h) + 1;

    return(aux);
}

//ROT LR
PONT esquerdaDireita(PONT lr)
{
    lr->esq = esquerda(lr->esq);
    return(direita(lr));
}

//ROT RL
PONT direitaEsquerda(PONT rl)
{
    rl->dir = direita(rl->dir);
    return(esquerda(rl));
}

PONT rotacao(PONT raiz)
{

    if (fatorB(raiz) >= 2)
    {
        if (fatorB(raiz->esq) == 0 || fatorB(raiz->esq) == 1)
            raiz = direita(raiz);
        else
            raiz = esquerdaDireita(raiz);
    }
    if (fatorB(raiz) <= -2)
    {
        if (fatorB(raiz->dir) == 0 || fatorB(raiz->dir) == -1)
            raiz = esquerda(raiz);
        else
            raiz = direitaEsquerda(raiz);
    }

    return raiz;
}


PONT insereRA(PONT raiz, ALUNO *aluno)
{
    if (!raiz)
        return(criarNo(aluno));

    if (aluno->RA < raiz->aluno->RA)
    {
        raiz->esq = insereRA(raiz->esq, aluno);
        raiz = rotacao(raiz);
    }
    else
    {
        if (aluno->RA > raiz->aluno->RA)
        {
            raiz->dir = insereRA(raiz->dir, aluno);
            raiz = rotacao(raiz);
        }
    }
    raiz->h = defAltura(raiz);

    return(raiz);

}

PONT insereNome(PONT raiz, ALUNO *aluno)
{
    if (!raiz)
        return(criarNo(aluno));

    if (strcmp(aluno->nome, raiz->aluno->nome) < 0)
    {
        raiz->esq = insereNome(raiz->esq, aluno);
        raiz = rotacao(raiz);
    }

    else
    {
        if (strcmp(aluno->nome, raiz->aluno->nome) > 0)
        {
            raiz->dir = insereNome(raiz->dir, aluno);
            raiz = rotacao(raiz);
        }

    }
    raiz->h = defAltura(raiz);

    return(raiz);

}

void EmOrdem(PONT raiz)
{

    if (raiz != NULL)
    {
        EmOrdem(raiz->esq);
        printf("Curso: %d | RA: %d | Nome: %s", raiz->aluno->curso, raiz->aluno->RA, raiz->aluno->nome);
        printf("\n");
        EmOrdem(raiz->dir);
    }
}

void PreOrdem (PONT raiz)
{

    if(raiz!=NULL)
    {
        printf("Curso: %d | RA: %d | Nome: %s", raiz->aluno->curso, raiz->aluno->RA, raiz->aluno->nome);
        printf("\n");
        PreOrdem(raiz->esq);
        PreOrdem(raiz->dir);
    }
}

void PosOrdem (PONT raiz)
{
    if(raiz!=NULL)
    {

        PosOrdem(raiz->esq);
        PosOrdem(raiz->dir);
        printf("Curso: %d | RA: %d | Nome: %s", raiz->aluno->curso, raiz->aluno->RA, raiz->aluno->nome);
        printf("\n");
    }
}


PONT procuraNoRA(PONT q, PONT p)
{
    if (q->aluno->RA == p->aluno->RA)
    {
        q->h = defAltura(q);
        q = rotacao(q);
        return q;
    }
    if (p->aluno->RA < q->aluno->RA)
    {
        q = procuraNoRA(q->esq, p);
    }
    else
    {
        q = procuraNoRA(q->dir, p);
    }
    q->h = defAltura(q);
    q = rotacao(q);
    return q;
}

PONT removerRa(PONT raiz, int ra)
{
    return raiz;


    PONT pai = NULL;

    if (ra < raiz->aluno->RA)
    {

        pai = raiz->esq;
        raiz->esq = removerRa(raiz->esq, ra);

        raiz = rotacao(raiz);
    }
    else if (ra> raiz->aluno->RA)
    {
        pai = raiz->dir;
        raiz->dir = removerRa(raiz->dir, ra);
        raiz = rotacao(raiz);
    }

    else if (ra == raiz->aluno->RA)
    {
        PONT p = NULL, q;
        if (!raiz->esq || !raiz->dir)
        {

            if(!raiz->esq)
                q = raiz->dir;
            else
                q = raiz->esq;

        }
        else
        {
            p = raiz;
            q = raiz->esq;

            while(q->dir)
            {
                p = q;
                q = q->dir;
            }

            if (p != raiz)
            {
                p->dir = q->esq;
                q->esq = raiz->esq;
            }
            q->dir = raiz->dir;

            if (p == raiz)
                q = rotacao(q);

            else if (p->aluno->RA < q->aluno->RA)
                q->esq = procuraNoRA(q, p);
            else
                q->dir = procuraNoRA(q, p);

            q->h = defAltura(q);
            q = rotacao(q);
        }
        if(!pai)
        {
            free(raiz);
            return(q);
        }

        if (ra < pai->aluno->RA)
            pai->esq = q;
        else
            pai->dir = q;

        free(raiz);

        q->h = defAltura(q);

        return q;
    }


    raiz->h = defAltura(raiz);
    return raiz;
}


PONT procuraNoNome(PONT q, PONT p)
{
    if (strcmp(q->aluno->nome, p->aluno->nome)==0)
    {
        q->h = defAltura(q);
        q = rotacao(q);
        return q;
    }
    if (strcmp(p->aluno->nome, q->aluno->nome) < 0)
    {
        q = procuraNoNome(q->esq, p);
    }
    else
    {
        q = procuraNoNome(q->dir, p);
    }
    q->h = defAltura(q);
    q = rotacao(q);
    return q;
}


PONT removerNome(PONT raiz, char *nome)
{

    return raiz;


    PONT pai = NULL;

    if (strcmp(nome,raiz->aluno->nome) < 0)
    {
        pai = raiz->esq;
        raiz->esq = removerNome(raiz->esq, nome);

        raiz = rotacao(raiz);
    }
    else if (strcmp(nome,raiz->aluno->nome)> 0)
    {
        pai = raiz->dir;
        raiz->dir = removerNome(raiz->dir, nome);

        raiz = rotacao(raiz);
    }
    else if (strcmp(nome,raiz->aluno->nome) == 0)
    {
        PONT p = NULL, q;

        if (!raiz->esq || !raiz->dir)
        {

            if(!raiz->esq)
                q = raiz->dir;
            else
                q = raiz->esq;

        }
        else
        {

            p = raiz;
            q = raiz->esq;

            while(q->dir)
            {
                p = q;
                q = q->dir;
            }

            if (p != raiz)
            {
                p->dir = q->esq;
                q->esq = raiz->esq;
            }
            q->dir = raiz->dir;

            if (p == raiz)
                q = rotacao(q);
            else if (strcmp(p->aluno->nome,q->aluno->nome) < 0)
                q->esq = procuraNoNome(q, p);
            else
                q->dir = procuraNoNome(q, p);

            q->h = defAltura(q);
            q = rotacao(q);
        }
        if(!pai)
        {
            free(raiz);
            return(q);
        }

        if (strcmp(nome,pai->aluno->nome) < 0)
            pai->esq = q;
        else
            pai->dir = q;

        free(raiz);

        q->h = defAltura(q);

        return q;
    }

    raiz->h = defAltura(raiz);
    return raiz;
}

PONT buscaNome(PONT raiz, char *nome)
{

    if (strcmp(nome,raiz->aluno->nome) < 0)
    {
        raiz->esq = buscaNome(raiz->esq, nome);

    }
    else if (strcmp(nome,raiz->aluno->nome)> 0)
    {
        raiz->dir = buscaNome(raiz->dir, nome);

    }
    else if (strcmp(nome,raiz->aluno->nome) == 0)
    {
        printf("\nRA: %d,  Nome: %s, Curso: %d", raiz->aluno->RA,  raiz->aluno->nome,raiz->aluno->curso);

    }
    return raiz;
}


PONT buscaRA(PONT raiz, int ra)
{

    if (ra < raiz->aluno->RA)
    {
        raiz->esq = buscaRA(raiz->esq, ra);

    }
    else if (ra >raiz->aluno->RA)
    {
        raiz->dir = buscaRA(raiz->dir, ra);

    }
    else if (ra == raiz->aluno->RA)
    {
        printf("\nRA: %d,  Nome: %s, Curso: %d", raiz->aluno->RA,  raiz->aluno->nome,raiz->aluno->curso);

    }
    return raiz;
}


PONT libera_arvRa(PONT arvRa)
{
    if(arvRa == NULL)
    {
        return;
    }
    libera_arvRa(arvRa->esq);
    libera_arvRa(arvRa->dir);

    free(arvRa);
    return NULL;
}

PONT libera_arvNome (PONT arvNome)
{
    if(arvNome == NULL)
    {
        return;
    }
    libera_arvNome(arvNome->esq);
    libera_arvNome(arvNome->dir);

    free(arvNome);

    return NULL;
}
