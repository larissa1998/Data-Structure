#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int main()
{
TIPOCHAVE chave;
PILHA pilha;
REGISTRO reg;

inicializarPilha(&pilha);

printf("Elementos inseridos na ");

reg.chave = 5;
inserirElem(&pilha, reg);

reg.chave = 2;
inserirElem(&pilha, reg);

reg.chave = 10;
inserirElem(&pilha, reg);

reg.chave = 9;
inserirElem(&pilha, reg);

reg.chave = -2;
inserirElem(&pilha, reg);

exibir(&pilha);

printf ("\nTamanho da pilha: %d", tamanhoPilha(&pilha));
printf("\n");

printf("\nExcluindo o topo 0 da ");
excluirElem(&pilha, &reg);
exibir(&pilha);

printf("\nExcluindo o topo 1 da ");
excluirElem(&pilha, &reg);
exibir(&pilha);

printf("\nExcluindo o topo 2 da ");
excluirElem(&pilha, &reg);
exibir(&pilha);

printf("\nExcluindo o topo 3 da ");
excluirElem(&pilha, &reg);
exibir(&pilha);

printf("\nExcluindo o topo 4 da ");
excluirElem(&pilha, &reg);
exibir(&pilha);
printf("Pilha vazia !!\n");

return 0;
}
