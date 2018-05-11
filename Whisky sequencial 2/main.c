#include <stdio.h>
#include <stdlib.h>
#include "whis.h"
#include <string.h>

int main() {
    LISTA lista;
    REGISTRO elem;

   // int ex;
    int op;
    char teste [] = "";
    inicio(&lista);


    elem.codigo_whisky = 1;
    strcpy(elem.nome_whisky, "Jack Daniels");
    elem.idade_bebida = 12;
    elem.estoque = 3;
    insereBebida(&lista, elem);

    elem.codigo_whisky = 2;
    strcpy(elem.nome_whisky , "Red Label");
    elem.idade_bebida = 5;
    elem.estoque = 8;
    insereBebida(&lista, elem);



    do {

    menuPrincipal();


    printf("Escolha uma opcao:");
    scanf("%i", &op);

    switch (op) {

    case 1:
     printf("Inserindo bebida\n");

            printf("\nCodigo: ");
            scanf("%i", &elem.codigo_whisky);
            fflush(stdin);

            printf("\nNome da bebida: ");
            scanf("%s", teste);

            strcpy(elem.nome_whisky, teste);
            fflush(stdin);

            printf("\nIdade da bebida: ");
            scanf("%d", &elem.idade_bebida);
            fflush(stdin);

            printf("\nQuantidade em estoque: ");
            scanf("%d", &elem.estoque);
            fflush(stdin);

           insereBebida(&lista, elem);
           system("pause");
           system("cls");
           char teste[] = "";
    break;

    case 2:
    exibirDrink(&lista);
    break;

    case 3:
    excluir(&lista,elem);
    system("pause");
    system("cls");
    break;

    case 4:
    buscaSeq(&lista, elem);
    system("pause");
    system("cls");
    break;

    case 5:

    break;

    case 6:
    printf("\nTotal de bebidas: %d\n",tamLista(&lista));
    system("pause");
    system("cls");
    break;

    case 7:
    reiniciar (&lista);
    system("pause");
    system("cls");
    break;

    case 8:

    break;

    }
    }while(op != 8);

    return 0;
}
