#include <stdio.h>
#include <stdlib.h>
#include "binary.h"


Pont inicializa() {
    return(NULL);
}

Pont criaNovoNo(TipoChave ch) {
    Pont novoNo = (Pont)malloc(sizeof(NO));
    novoNo->chave = ch;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return(novoNo);
}

Pont adiciona(Pont raiz, Pont no){
    if (raiz == NULL)
        return(no);

    if (no->chave < raiz->chave)
        raiz->esq = adiciona(raiz->esq, no);
    else
        raiz->dir = adiciona(raiz->dir, no);

    return(raiz);
}

Pont contem(TipoChave ch, Pont raiz) {
    if (raiz == NULL)
        return(NULL);

    if (raiz->chave == ch)
        return(raiz);

    if (raiz->chave > ch)
        return(contem(ch, raiz->esq));
    else
        return(contem(ch, raiz->dir));
}

void leituraEmOrdem(Pont raiz){
    if ( raiz != NULL){
        leituraEmOrdem(raiz->esq);
        printf("%i ", raiz->chave);
        leituraEmOrdem(raiz->dir);
    }
}

void leituraPreOrdem(Pont raiz){
    if (raiz != NULL) {
        printf("%i ", raiz->chave);
        leituraPreOrdem(raiz->esq);
        leituraPreOrdem(raiz->dir);
    }
}

void leituraPosOrdem(Pont raiz) {
    if (raiz != NULL) {
        leituraPreOrdem(raiz->esq);
        leituraPreOrdem(raiz->dir);
        printf("%i ", raiz->chave);
    }
}

int conta(Pont raiz){
    if (raiz != NULL)
        return (conta(raiz->esq) + 1 + conta(raiz->dir));
    else return 0;
}

Pont buscaNo(Pont raiz, TipoChave ch, Pont *pai) {
    Pont atual = raiz;
    *pai = NULL;
    while (atual) {
        if (atual->chave == ch)
            return(atual);

        *pai = atual;

        if (ch < atual->chave)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return(NULL);
}

Pont removeNo(Pont raiz, TipoChave ch) {
    Pont pai, no, p, q;

    no = buscaNo(raiz, ch, &pai);
    if (no == NULL)
        return(raiz);
    if (!no->esq || !no->dir) {
        if (!no->esq)
            q = no->dir;
        else
            q = no->esq;
    }
    else {
        p = no;
        q = no->esq;

        while (q->dir) {
            p = q;
            q = q->dir;
        }
        if (p != no) {
            p->dir = q->esq;
            q->esq = no->esq;
        }
        q->dir = no->dir;
    }
    if (!pai) {
        free(no);
        return(q);
    }
    if (ch < pai->chave)
        pai->esq = q;
    else
        pai->dir = q;
    free(no);
    return(raiz);
}

Pont removeNoDir(Pont raiz, TipoChave ch) {
    Pont pai, no, p, q;

    no = buscaNo(raiz, ch, &pai);

    if (no == NULL)
        return(raiz);

    if (!no->esq || !no->dir) {
        if (!no->esq)
            q = no->dir;
        else
            q = no->esq;
    }
    else {
        p = no;
        q = no->dir;

        while (q->esq) {
            p = q;
            q = q->esq;
        }

        if (p != no) {
            p->esq = q->dir;
            q->dir = no->dir;
        }
        q->esq = no->esq;
    }

    if (!pai) {
        free(no);
        return(q);
    }

    if (ch < pai->chave)
        pai->esq = q;
    else
        pai->dir = q;

    free(no);
    return(raiz);
}
