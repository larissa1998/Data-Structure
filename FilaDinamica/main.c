#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{

FILA fila;
REGISTRO reg;

inicializar(&fila);

reg.chave = 2;
inserir(&fila, reg);

reg.chave = 10;
inserir(&fila, reg);

reg.chave = 5;
inserir(&fila, reg);

exibirFila(&fila);

printf("\n---------------------\n");

excluirElem(&fila);
exibirFila(&fila);


///printf("Nao possui mais elementos");

reinicializar(&fila);

    return 0;
}
