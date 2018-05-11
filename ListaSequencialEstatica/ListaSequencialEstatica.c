#include <conio.h>
#include "ListaSequencialEstatica.h"

void inicializaLista(LISTA *l){
l->nroElem = 0; // sempre com 0
}


int tamanho (LISTA *l){
return (l->nroElem);
}

void exibirLista (LISTA *l){
int i;
for (i=0; i<l->nroElem; i++){
    printf("\n [pos=%d, valor=%d]", i, l->A[i].chave); //para cada valor de i, será impresso um numero inteiro.
    }
}

void insereElemLista (LISTA*l, REGISTRO elem){
    int j;

  if(l->nroElem >=MAX){
    printf("\n Lista cheia, não inserir");
    return;
  }

  for (j=l->nroElem; j>0 && elem.chave<l->A[j-1].chave; j--){ //dentro de registro esta comparando chave com chave
    l->A[j]=l->A[j-1]; //ver se o elemento anterior é menor, e colocar na posicao, jogando o outro para a direita
  }

  l->A[j]=elem; //vendo o ultimo vazio, e colocando o numer\o de elementos la dentro
  l->nroElem=l->nroElem+1; //pegando o anterior, jogando para a direita e somando +1 , pq aumentou o numero de elementos, pois acrescentou mais um numero
}

//busca binaria só funciona orddenadamente
//busca sequencial ja n


//primeira coisa, é testar se a lista está vazia , caso esteja mandar uma msg falando
// if(l->nroElem ==0) { printf ("Lista vazia !")}

//segunda coisa, percorrer a lista
//for(j=0; j<l->nroElem && chave !=l->A[j]; j++);
//if(j<l->nroElem &&  chave == l->A[j].chave)
//return j;
//else return (-1);
int buscaSequencial(LISTA *l, TIPOCHAVE ch){
int i =0;

while (i<l->nroElem){
 if(ch == l->A[i].chave) return i; // comparando a chave em tal posição e vendo se é a mesma ou n, caso n seja , vai para o próximo elemento da lista sequencial
 else i++;
 printf("O numero da chave do elemento é: %d", i);
}
return -1;
printf ("Esse elemento não existe !!");
}


int busca_binaria (LISTA *l, TIPOCHAVE ch, int i, int f){
 int meio;

 meio = (int) (i+f)/2;

 while (f>0 && i>0 && i<=f && l->A[meio].chave!=ch){
    if(l->A[meio].chave > ch) f == meio -1;
    else
        i = meio +1;

    meio = (int) ((i+f)/2);
 }

    if (meio >= 0 && l->A[meio].chave == ch) return (meio);
    return (-1);
}

//int buscaSentinela (LISTA *l , TIPOCHAVE ch){
//    int i =0;
//
//    l->A[nroElem].chave =ch;
//    while (l->A[i].chave != ch) i++;
//    if(i != l->nroElem) return i;
//    return -1;
//}

 void excluir (LISTA *l, TIPOCHAVE ch){
int pos, i;
 if((pos = busca_binaria(l,ch,0,l->nroElem-1)) == -1){
 printf ("nao foi possivel excluir");
 return;
}
for(i=pos; i<l->nroElem-1; i++)
 l->A[i] = l->A[i+1];
l->nroElem = l->nroElem -1;
printf ("O elemento %d foi excluido", ch);
}

//int excluirElemLista (LISTA *l, TIPOCHAVE ch){
 //int pos, j;

 //pos = buscaSequencial(l, ch);

 //if(pos == -1) return -1;

// for (j = pos; j<l->nroElem; j++)
 //   l->A[j] = l->A[j+1];
 //   l->nroElem --;

 //   return 0;
//}

void reinicializaLista (LISTA *l){
 l->nroElem = 0;
}
