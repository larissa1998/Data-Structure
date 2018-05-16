#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    PILHA pilha;
    REGISTRO reg;

    inicializar(&pilha);

    printf("Inserindo  \n");
    reg.chave = 30;
    inserir(&pilha,reg);

    reg.chave = 5;
    inserir(&pilha,reg);

    reg.chave = 100;
    inserir(&pilha,reg);

    exibir(&pilha);

    printf("\nExcluindo \n");
    excluir(&pilha, reg);
    exibir(&pilha);



    return 0;
}
