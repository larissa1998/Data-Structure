#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include <conio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "PORTUGUESE");
    LISTA lista;
    REGISTRO elem;
    int i;
    inicializaLista(&lista);
/*
    elem.chave = 5;
    inserir_elemento(&lista, elem);

    elem.chave = 10;
    inserir_elemento(&lista, elem);

    elem.chave = 3;
    inseir_elemento(&lista, elem);

    imprimeLista(&lista);

    chave=3;
*/


    elem.chave = 5;
    inserir_elemento_ordenado(&lista, elem);

    elem.chave = 10;
    inserir_elemento_ordenado(&lista, elem);

    elem.chave = 3;
    inserir_elemento_ordenado(&lista, elem);


    elem.chave = 7;
    inserir_elemento_ordenado(&lista, elem);


    elem.chave = 6;
    inserir_elemento_ordenado(&lista, elem);

    imprimeLista(&lista);

    if(busca_elemento(&lista, elem.chave)!= -1)printf("Encontrou elemento na posicao %d\n", i);
    else printf("\nO elemento nao esta na lista\n");
    return 0;
}
