#include <stdio.h>
#include <stdlib.h>
#include "academy.h"
#include <string.h>

/// ---------------------------------------------------------LISTA DINÂMICA-------------------------------------------------------------------------------------
void sair_Sistema ()
{
    exit(0);

}

void Limpar_Lista(LISTA *l)
{
    PONT limpar=l->inicio;

    while(limpar!=NULL)
    {
        l->inicio=l->inicio->prox;
        free(limpar);
        limpar=l->inicio;
    }
}

void limparTela()
{
    system("pause");
    system("cls");
}

void inicializar(LISTA *l)
{
    l->inicio = NULL;
}

void exibir(LISTA *l)
{

    PONT aux=l->inicio;

    if(aux == NULL)
    {
        printf("Não há nada para exibir\n");
    }

    while(aux!=NULL)
    {

        printf("\n");
        printf("\n Curso: %d, RA: %d, Nome: %s \n", aux->aluno.curso_aluno, aux->aluno.RA_aluno, aux->aluno.nome_aluno);

        aux=aux->prox;
    }

}

int inserir (LISTA *l, ALUNO aluno)
{
    PONT novo;
    PONT atual;

    if(buscarRepetidos(l, aluno.RA_aluno) == 0)
    {


        puts("\n Aluno cadastrado no sistema\n");

        novo = (PONT) malloc(sizeof(ELEMENTO));
        novo->aluno=aluno;
        novo->prox=NULL;

        if(l->inicio==NULL)
        {

            l->inicio = novo;
        }
        else
        {
            atual=l->inicio;
            while(atual->prox !=NULL)
            {
                atual=atual->prox;
            }
            atual->prox = novo;
        }
        VALIDO;
    }

    else
    {
        printf("\nRA ou nome repetido\n");
        return 0;
    }
}

void excluirNome(LISTA *l, char *nome)
{
    PONT atual= l->inicio;
    PONT ant=NULL;

    while(atual!=NULL && strcmp(atual->aluno.nome_aluno, nome) < 0)
    {
        ant = atual;
        atual = (PONT)atual->prox;
    }

    if(strcmp(atual->aluno.nome_aluno, nome) != 0)
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


void excluirRa (LISTA *l, int ra)
{


    PONT atual= l->inicio;
    PONT ant=NULL;

    while(atual!=NULL && atual->aluno.RA_aluno<ra)
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
        if(atual->aluno.RA_aluno!=ra)
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

PONT buscarRepetidos(LISTA *l, int ra)
{
    PONT aux=l->inicio;

    while(aux!=NULL && aux->aluno.RA_aluno<ra)
    {
        aux=aux->prox;

    }
    if(aux!=NULL && aux->aluno.RA_aluno==ra)
    {

        VALIDO;
    }
    else
    {
        return 0;
    }
}

int buscar (LISTA *l, int ra, char *nome)
{

    int op;

    printf("\nDigite sua opção de escolha\n");
    printf("[1] - Por RA");
    printf("\n[2] - Por Nome\n");


    scanf("%d", &op);


    if (op ==1)
    {


        printf("\n Digite o RA:");
        scanf("%d", &ra);

        PONT atual = NULL;

        atual = l->inicio;

        while(atual!=NULL && atual->aluno.RA_aluno<ra)
        {
            atual = atual->prox;
        }

        if(atual!= NULL && atual->aluno.RA_aluno==ra)
        {

            printf("\n Curso: %d, RA: %d, Nome: %s \n", atual->aluno.curso_aluno, atual->aluno.RA_aluno, atual->aluno.nome_aluno);
            VALIDO;

        }
        else
        {
            return 0;
        }

    }

    else if(op == 2)
    {

        printf("\n Digite o Nome a ser buscado:");
        fflush(stdin);
        gets(nome);

        PONT atual = NULL;

        atual = l->inicio;

        while(atual!=NULL && strcmp(atual->aluno.nome_aluno,nome)<0)
        {
            atual = atual->prox;
        }

        if(atual!= NULL && strcmp(atual->aluno.nome_aluno,nome)==0)
        {

            printf("\n Curso: %d, RA: %d, Nome: %s \n", atual->aluno.curso_aluno, atual->aluno.RA_aluno, atual->aluno.nome_aluno);
            return atual;

        }
        else
        {
            return NULL;
        }

    }
    else
    {
        printf("\nDigite uma opção válida\n");
    }

}

void menuCursos()
{


    puts("\n-----------CURSOS UENP------------");
    printf("\n[40] - SI\n");
    printf("\n[12] - CC\n");
    printf("\n[50] - VET\n");
    printf("\n[20] - BIO\n");
    printf("\n[30] - ENF\n");
    printf("\n[10] - AGRO\n");

}


PONT buscarCursos (LISTA *l, int ra)
{


    menuCursos();

    puts("\nDigite o RA:");
    scanf("%i", &ra);

    PONT aux=l->inicio;

    while(aux!=NULL )
    {

        if( ra == SI))
        {
            if (aux->aluno.curso_aluno == SI)
            {
                printf("\n");
                printf("RA: %d, Nome: %s, Curso: %d ", aux->aluno.RA_aluno,aux->aluno.nome_aluno,aux->aluno.curso_aluno);
                printf("\n");
            }
        }

        if( ra == CC)
        {
            if (aux->aluno.curso_aluno == CC)
            {
                printf("\n");
                printf("RA: %d, Nome: %s, Curso: %d ", aux->aluno.RA_aluno,aux->aluno.nome_aluno,aux->aluno.curso_aluno);
                printf("\n");
            }
        }

        if(ra == BIO)
        {
            if(aux->aluno.curso_aluno == BIO)
            {
                printf("\n");
                printf("RA: %d, Nome: %s, Curso: %d ", aux->aluno.RA_aluno,aux->aluno.nome_aluno,aux->aluno.curso_aluno);
                printf("\n");
            }
        }


        if(ra == AGRO)
        {
            if(aux->aluno.curso_aluno == AGRO)
            {
                printf("\n");
                printf("RA: %d, Nome: %s, Curso: %d ", aux->aluno.RA_aluno,aux->aluno.nome_aluno,aux->aluno.curso_aluno);
                printf("\n");
            }
        }

        if(ra == VET)
        {
            if(aux->aluno.curso_aluno == VET)
            {
                printf("\n");
                printf("RA: %d, Nome: %s, Curso: %d ", aux->aluno.RA_aluno,aux->aluno.nome_aluno,aux->aluno.curso_aluno);
                printf("\n");
            }
        }

        if(ra == ENF)
        {
            if(aux->aluno.curso_aluno == ENF)
            {
                printf("\n");
                printf("RA: %d, Nome: %s, Curso: %d ", aux->aluno.RA_aluno,aux->aluno.nome_aluno,aux->aluno.curso_aluno);
                printf("\n");
            }
        }

        aux=aux->prox;
    }

    if(aux!=NULL && aux->aluno.curso_aluno!= ra)
        return(aux);
    return (NULL);
}



///-------------------------------------------------ÁRVORE BINÁRIA AVL----------------------------------------------------------------------------------------

PONTEIRO inicializar_Arvore ()
{
    return (NULL);
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int altura(PONTEIRO raiz)
{
    if (!raiz)
        return -1;
    return raiz->altura1;
}

int defAltura(PONTEIRO p)
{
    return (max(altura(p->dir), altura(p->esq)) + 1);
}

PONTEIRO criarNoArv(ALUNO *aluno)
{
    PONTEIRO novo = (PONTEIRO)malloc(sizeof(NO));
    novo->aluno = aluno;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->altura1 =  0;
    return (novo);
}

int fatorBalanceamento(PONTEIRO raiz)
{
    return (altura(raiz->esq) - altura(raiz->dir));
}

PONTEIRO esquerda(PONTEIRO r)
{
    PONTEIRO aux;
    aux = r->dir;
    r->dir = aux->esq;
    aux->esq = r;
    r->altura1 = max(altura(r->dir), altura(r->esq)) + 1;
    aux->altura1 = max(altura(aux->esq), r->altura1) + 1;

    return(aux);
}
PONTEIRO direita(PONTEIRO r)
{
    PONTEIRO aux;
    aux = r->esq;
    r->esq = aux->dir;
    aux->dir = r;
    r->altura1 = max(altura(r->dir), altura(r->esq)) + 1;
    aux->altura1 = max(altura(aux->esq), r->altura1) + 1;

    return(aux);
}
PONTEIRO esquerdaDireita(PONTEIRO r)
{
    r->esq = esquerda(r->esq);
    return(direita(r));
}

PONTEIRO direitaEsquerda(PONTEIRO r)
{
    r->dir = direita(r->dir);
    return(esquerda(r));
}

PONTEIRO rotacao(PONTEIRO raiz)
{

    if (fatorBalanceamento(raiz) >= 2)
    {
        if (fatorBalanceamento(raiz->esq) == 0 || fatorBalanceamento(raiz->esq) == 1)
            raiz = direita(raiz);
        else
            raiz = esquerdaDireita(raiz);
    }
    if (fatorBalanceamento(raiz) <= -2)
    {
        if (fatorBalanceamento(raiz->dir) == 0 || fatorBalanceamento(raiz->dir) == -1)
            raiz = esquerda(raiz);
        else
            raiz = direitaEsquerda(raiz);
    }

    return raiz;
}


PONTEIRO inserir_Arvore_RA(PONTEIRO raiz, ALUNO *aluno)
{

    if(!raiz)
        return (criarNoArv(aluno));

    if (aluno->RA_aluno < raiz->aluno->RA_aluno)
    {
        raiz->esq = inserir_Arvore_RA(raiz->esq, aluno);
        raiz = rotacao(raiz);
    }

    else
    {
        if (aluno->RA_aluno > raiz->aluno->RA_aluno)
        {
            raiz->dir = inserir_Arvore_RA(raiz->dir, aluno);
            raiz = rotacao(raiz);
        }
    }
    raiz->altura1 = defAltura(raiz);

    return(raiz);

}

PONTEIRO insere_Arvore_Nome(PONTEIRO raiz, ALUNO *aluno)
{
    if (!raiz)
        return(criarNoArv(aluno));

    if (strcmp(aluno->nome_aluno, raiz->aluno->nome_aluno) < 0)
    {
        raiz->esq = insere_Arvore_Nome(raiz->esq, aluno);
        raiz = rotacao(raiz);
    }

    else
    {
        if (strcmp(aluno->nome_aluno, raiz->aluno->nome_aluno) > 0)
        {
            raiz->dir = insere_Arvore_Nome(raiz->dir, aluno);
            raiz = rotacao(raiz);
        }

    }
    raiz->altura1 = defAltura(raiz);

    return(raiz);

}

PONTEIRO procura_Nome(PONTEIRO q, PONTEIRO p)
{

    if (strcmp(q->aluno->nome_aluno, p->aluno->nome_aluno)==0)
    {
        q->altura1 = defAltura(q);
        q = rotacao(q);
        return q;
    }
    if (strcmp(p->aluno->nome_aluno, q->aluno->nome_aluno) < 0)
    {

        q = procura_Nome(q->esq, p);
    }
    else
    {
        q = procura_Nome(q->dir, p);
    }
    q->altura1 = defAltura(q);
    q = rotacao(q);
    return q;
}

PONTEIRO procura_RA(PONTEIRO q, PONTEIRO p)
{
    if (q->aluno->RA_aluno == p->aluno->RA_aluno)
    {
        q->altura1 = defAltura(q);
        q = rotacao(q);
        return q;
    }
    if (p->aluno->RA_aluno < q->aluno->RA_aluno)
    {
        q = procura_RA(q->esq, p);
    }
    else
    {
        q = procura_RA(q->dir, p);
    }
    q->altura1 = defAltura(q);
    q = rotacao(q);
    return q;
}


void EmOrdem(PONTEIRO raiz)
{

    if (raiz != NULL)
    {
        EmOrdem(raiz->esq);
        printf("Curso: %d | RA: %d | Nome: %s", raiz->aluno->curso_aluno, raiz->aluno->RA_aluno, raiz->aluno->nome_aluno);
        printf("\n");
        EmOrdem(raiz->dir);
    }
}

void PreOrdem (PONTEIRO raiz)
{

    if(raiz!=NULL)
    {

        printf("Curso: %d | RA: %d | Nome: %s", raiz->aluno->curso_aluno, raiz->aluno->RA_aluno, raiz->aluno->nome_aluno);
        printf("\n");
        PreOrdem(raiz->esq);
        PreOrdem(raiz->dir);
    }
}

void PosOrdem (PONTEIRO raiz)
{

    if(raiz!=NULL)
    {
        PosOrdem(raiz->esq);
        PosOrdem(raiz->dir);
        printf("Curso: %d | RA: %d | Nome: %s", raiz->aluno->curso_aluno, raiz->aluno->RA_aluno, raiz->aluno->nome_aluno);
        printf("\n");
    }
}


PONTEIRO buscarArvoreRA(PONTEIRO raiz, int ra)
{


    if (ra < raiz->aluno->RA_aluno)
    {
        raiz->esq = buscarArvoreRA(raiz->esq, ra);

    }
    else if (ra >raiz->aluno->RA_aluno)
    {
        raiz->dir = buscarArvoreRA(raiz->dir, ra);

    }
    else if (ra == raiz->aluno->RA_aluno)
    {
        printf("\nRA: %d,  Nome: %s, Curso: %d", raiz->aluno->RA_aluno,  raiz->aluno->nome_aluno,raiz->aluno->curso_aluno);
        puts("\n");

    }
    return raiz;
}


PONTEIRO buscarArvoreNome (PONTEIRO raiz, char *nome)
{



    if (strcmp(nome,raiz->aluno->nome_aluno) < 0)
    {
        raiz->esq = buscarArvoreNome(raiz->esq, nome);

    }
    else if (strcmp(nome,raiz->aluno->nome_aluno)> 0)
    {
        raiz->dir = buscarArvoreNome(raiz->dir, nome);

    }
    else if (strcmp(nome,raiz->aluno->nome_aluno) == 0)
    {
        printf("\nRA: %d,  Nome: %s, Curso: %d", raiz->aluno->RA_aluno,  raiz->aluno->nome_aluno,raiz->aluno->curso_aluno);
        puts("\n");

    }
    return raiz;
}


PONTEIRO removerRa(PONTEIRO raiz, int ra)
{

    if (!raiz)
    {
        printf("RA nao encontrado na Arvore vazia!\n");
        return raiz;
    }

    PONTEIRO pai = NULL;

    if (ra < raiz->aluno->RA_aluno)
    {
        pai = raiz->esq;
        raiz->esq = removerRa(raiz->esq, ra);

        raiz = rotacao(raiz);
    }
    else if (ra > raiz->aluno->RA_aluno)
    {
        pai = raiz->dir;
        raiz->dir = removerRa(raiz->dir, ra);

        raiz = rotacao(raiz);
    }
    else if (ra == raiz->aluno->RA_aluno)
    {
        PONTEIRO p = NULL, q;

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
            else if (p->aluno->RA_aluno < q->aluno->RA_aluno)
                q->esq = procura_RA(q, p);
            else
                q->dir = procura_RA(q, p);

            q->altura1 = defAltura(q);
            q = rotacao(q);
        }
        if(!pai)
        {
            free(raiz);
            return(q);
        }

        if (ra < pai->aluno->RA_aluno)
            pai->esq = q;
        else
            pai->dir = q;

        free(raiz);

        q->altura1 = defAltura(q);

        return q;
    }
    else
        printf("RA não encontrada!!\n");

    raiz->altura1 = defAltura(raiz);
    return raiz;
}


PONTEIRO remover_Nome(PONTEIRO raiz, char *nome)
{


    if(!raiz)
    {
        printf("\z Árvore vazia!");
        return raiz;
    }

    PONTEIRO pai = NULL;

    if (strcmp(nome,raiz->aluno->nome_aluno) < 0)
    {
        pai = raiz->esq;
        raiz->esq = remover_Nome(raiz->esq, nome);

        raiz = rotacao(raiz);
    }
    else if (strcmp(nome,raiz->aluno->nome_aluno)> 0)
    {
        pai = raiz->dir;
        raiz->dir = remover_Nome(raiz->dir, nome);

        raiz = rotacao(raiz);
    }
    else if (strcmp(nome,raiz->aluno->nome_aluno) == 0)
    {
        PONTEIRO p = NULL, q;

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
            else if (strcmp(p->aluno->nome_aluno,q->aluno->nome_aluno) < 0)
                q->esq = procura_Nome(q, p);
            else
                q->dir = procura_Nome(q, p);

            q->altura1 = defAltura(q);
            q = rotacao(q);
        }
        if(!pai)
        {
            free(raiz);
            return(q);
        }

        if (strcmp(nome,pai->aluno->nome_aluno) < 0)
            pai->esq = q;
        else
            pai->dir = q;

        free(raiz);

        q->altura1 = defAltura(q);

        return q;
    }

    raiz->altura1 = defAltura(raiz);
    return raiz;
}


PONTEIRO liberaRA(PONTEIRO raizRa)
{
    if(raizRa == NULL)
    {
        return;
    }
    liberaRA(raizRa->esq);
    liberaRA(raizRa->dir);

    free(raizRa);
    return NULL;
}

PONTEIRO liberaNome(PONTEIRO raizNome)
{
    if(raizNome == NULL)
    {
        return;
    }
    liberaNome(raizNome->esq);
    liberaNome(raizNome->dir);

    free(raizNome);

    return NULL;
}


