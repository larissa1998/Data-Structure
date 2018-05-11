#include <conio.h>
#include "Lista.h"


void inicializaLista (LISTA *l){
int i;

l->nroElem = 0;
l->dispo = 0;
l->inicio = INVALIDO;

for (i=0; i<MAX-1; i++){
    l->A[i].prox = i+1;
}
    l->A[MAX-1].prox = -1;
}

//INSERÇÃO DESORDENADA
//void inserirElemLista(LISTA *l, REGISTRO reg){
// if(l->nroElem >= MAX){
//    printf("\n Não foi possivel inserir lista, lista cheia !! ");
//    return;
// }
// l->nroElem=l->nroElem+1;
// reg.prox=l>inicio;
// aux=l->dispo;
// l->dispo=l->A[l->dispo].prox;
// l->inicio=aux;
// l->A[aux]=reg;
//}

int tamanho (LISTA *l){
int i = l->inicio;
int tam = 0;

while (i!=INVALIDO){
    tam ++;
    i=l->A[i].prox;
}
return tam;
}

//INSERIR ELEMENTO NA LISTA ORDENADAMENTE
void inserir_elemento_ordenado (LISTA *l, REGISTRO reg){
int ant = INVALIDO;
    int atual;
    int aux_dispo=l->A[l->dispo].prox;
    if(l->dispo == INVALIDO)
    return INVALIDO;
    l->A[l->dispo].chave=reg.chave;
    l->nroElem=l->nroElem+1;

    atual=l->inicio;

    while(atual >= 0 && l->A[atual].chave < reg.chave){
        ant=atual;
        atual=l->A[atual].prox;
    }

    if(atual == INVALIDO && ant == INVALIDO){
        l->A[l->dispo].prox=l->inicio;
        l->inicio=l->dispo;
    }
    else{
        l->A[ant].prox=l->dispo;
        l->A[l->dispo].prox=atual;
    }

     l->dispo=aux_dispo;
    return(1);
}

void imprimeLista(LISTA *l){
    int i;

    for(i=l->inicio; i!=INVALIDO; i=l->A[i].prox){
        printf("[%d] = %d", i, l->A[i].chave);
    }
}

int busca_elemento(LISTA *l, TIPOCHAVE chave){
    int i;

    if(l->inicio == INVALIDO) return (INVALIDO);
    for(i=l->inicio; i>0 && l->A[i].chave < chave;i=l->A[i].prox);

    if(i==INVALIDO || (i>=0 && l->A[i].chave!=chave)) return(INVALIDO);

    return(i);

}

void excluir_elemento (LISTA *l, TIPOCHAVE ch)
{
int ant = -1;
int atual;

if(l->dispo == -1){
    printf("\n\n Elemento nao esta na lsita: LISTA VAZIA");
    return;
}

atual = l->inicio;
while (atual>=0 && l->A[atual].chave<ch){
    ant =atual;
    atual = l->A[atual].prox;
}

if(l->A[atual].chave == ch){
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
else printf("\n O elemento nao esta na lista");
}

void reinicializarLista (LISTA *l){
 inicializaLista (l);
}
