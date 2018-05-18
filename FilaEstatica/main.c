#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "fila.h"
int main()
{
    system("COLOR 0D");
    REGISTRO reg;
    FILA fila;


    inicializarFila(&fila);

    printf("Inserindo elementos na ");
    reg.chave = 5;
    inserirElemFila(&fila,reg);

    reg.chave = 15;
    inserirElemFila(&fila,reg);

    reg.chave = 1;
    inserirElemFila(&fila,reg);

    exibirFila(&fila);

    printf("Excluindo elementos da ");

    excluirElemFila(&fila);
    exibirFila(&fila);

    excluirElemFila(&fila);
    exibirFila(&fila);

    excluirElemFila(&fila);
    exibirFila(&fila);
    printf("Fila vazia !!");

    return 0;
}
