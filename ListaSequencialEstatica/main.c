#include <stdio.h>
#include <stdlib.h>

#include "ListaSequencialEstatica.h" // incluindo o código do cabeçalho

//EXERCÍCIO DA PRIMEIRA AULA DE ESTRUTURA DE DADOS
//Aqui na main, é onde você vai pedir para executar todas as funções das outras telas.

//main vai ser a chamada principal, ai foi incluido um arquivo .h e um outro arquivo .c , foi separado assim por questão de organização
//o compilador n ve o ponto c , somente o .h

int main()
{
 LISTA lista;
 REGISTRO elem;
 TIPOCHAVE chave;
 inicializaLista(&lista);
// n aparece o numero de elementos correto, pois esta inicializando antes
 printf ("\n\n Numero elementos: %d", tamanho(&lista));
 elem.chave=7;
 insereElemLista(&lista, elem);

 elem.chave=9;
 insereElemLista(&lista, elem);

 elem.chave=3;
 insereElemLista(&lista, elem);

 elem.chave=5;
 insereElemLista(&lista, elem);

 exibirLista(&lista);

 chave = 2;

// if(buscaSequencial(&lista, chave) == -1)
 //printf("\n Elemento %d nao esta na lista", chave);
 //else printf ("\n Elemento %d esta na lista", chave);


 if(busca_binaria(&lista, chave, 0, lista.nroElem-1) == -1)
 printf("\n Elemento %d nao esta na lista", chave);
 else printf ("\n Elemento %d esta na lista", chave);

 return 0;
}

