#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main()
{
    LISTA lista;
    REGISTRO reg;

    inicializarLista(&lista);

    reg.chave = 8;
    inserir_elemento(&lista, reg);

    reg.chave = 10;
    inserir_elemento(&lista, reg);

    reg.chave = 3;
    inserir_elemento(&lista, reg);

    reg.chave = 1;
    inserir_elemento(&lista, reg);

    reg.chave = 2;
    inserir_elemento(&lista, reg);

    reg.chave = 23;
    if(buscaElemento(&lista, reg.chave) != NULL)
        printf("O numero de elementos estah na lista");
    else printf("n esta na lista");
    imprime(&lista);
    exclui_elemento(&lista, reg.chave=10);
    reinicializar (&lista);

}
