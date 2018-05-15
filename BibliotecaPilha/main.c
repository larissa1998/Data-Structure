#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "pilha.h"

int main()
{

TIPOCHAVE chave;
PILHA pilha;
REGISTRO reg;

setlocale(LC_ALL,"PORTUGUESE");
inicializarPilhaLivro(&pilha);

printf("Elementos inseridos na ");

reg.codigo = 5;
strcpy(reg.livro, "Cálculo volume 1");
strcpy(reg.autor, "James Stewart");
reg.ano = 2017;
reg.numero = 680;
reg.ISBN = 9788522125838;
inserirElemLivro(&pilha, reg);

reg.codigo = 10;
strcpy(reg.livro, "Estrutura de dados e algoritmos em C");
strcpy(reg.autor, "António Adrego da Rocha");
reg.ano = 2014;
reg.numero = 616;
reg.ISBN = 9727227694;
inserirElemLivro(&pilha, reg);

reg.codigo = 37;
strcpy(reg.livro, "A origem das espécies");
strcpy(reg.autor, "Charles Darwin");
reg.ano = 2014;
reg.numero = 574;
reg.ISBN = 8572329854;
inserirElemLivro(&pilha, reg);

exibirPilhaLivro(&pilha);


printf ("\nTamanho da pilha: %d", tamanhoPilhaLivro(&pilha));
printf("\n------------------------------------------------------");
printf("\n");

printf("Excluindo o topo 0 da ");
excluirElemPilha(&pilha, &reg);
exibirPilhaLivro(&pilha);
printf ("Tamanho da pilha : %d", tamanhoPilhaLivro(&pilha));
printf("\n");
printf("------------------------------------------------------");

printf("\nExcluindo o topo 1 da ");
excluirElemPilha(&pilha, &reg);
exibirPilhaLivro(&pilha);
printf ("Tamanho da pilha : %d", tamanhoPilhaLivro(&pilha));
printf("\n");
printf("------------------------------------------------------");

printf("\nExcluindo o topo 2 da ");
excluirElemPilha(&pilha, &reg);
exibirPilhaLivro(&pilha);
printf ("Tamanho da pilha : %d", tamanhoPilhaLivro(&pilha));
printf(" Pilha vazia!!\n");

return 0;
}
