#include <stdio.h>
#include <stdlib.h>
#include "whisky.h"
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <dos.h>
#include <conio.h>

int main()
{

    setlocale(LC_ALL,"PORTUGUESE");
    system("COLOR 0A");

    int i;
    char  ce= '#';
    Sleep(200);
    int codigo;
    int chave;
    int choice;
    int novo;
    char drink [60] = "";
    LISTA lista;
    REGISTRO elem;

    inicializaLista(&lista);



    printf("CARREGANDO O SISTEMA - LIGUE O SOM: \n");
    for(i=0; i<=30; i++){

    Beep(660,100);Sleep(150);
    printf("%c", ce);
    Beep(660,100);Sleep(300);
    printf("%c", ce);
    Beep(660,100);Sleep( 300);
    printf("%c", ce);
    Beep(510,100);Sleep( 100);
    printf("%c", ce);
    Beep(660,100);Sleep( 300);
    printf("%c", ce);
    Beep(770,100);Sleep( 550);
    printf("%c", ce);
    Beep(380,100);Sleep( 575);
    printf("%c", ce);
    Beep(510,100);Sleep( 450);
    printf("%c", ce);
    Beep(380,100);Sleep( 400);
    printf("%c", ce);
    Beep(320,100);Sleep( 500);
    printf("%c", ce);
    Beep(440,100);Sleep( 300);
    printf("%c", ce);
    Beep(480,80);Sleep( 330);
    printf("%c", ce);
    Beep(450,100);Sleep( 150);
    printf("%c", ce);
    Beep(430,100);Sleep( 300);
    printf("%c", ce);
    Beep(380,100);Sleep( 200);
    printf("%c", ce);
    Beep(660,80);Sleep( 200);
    printf("%c", ce);
    Beep(760,50);Sleep( 150);
    printf("%c", ce);
    Beep(860,100);Sleep( 300);
    printf("%c", ce);
    Beep(700,80);Sleep( 150);
    printf("%c", ce);
    Beep(760,50);Sleep( 350);
    printf("%c", ce);
    Beep(660,80);Sleep( 300);
    printf("%c", ce);
    Beep(520,80);Sleep( 150);
    printf("%c", ce);
    Beep(580,80);Sleep( 150);
    printf("%c", ce);
    Beep(480,80);Sleep( 500);
    printf("%c", ce);
    Beep(510,100);Sleep( 450);
    printf("%c", ce);
    Beep(380,100);Sleep( 400);
    printf("%c", ce);
    Beep(320,100);Sleep( 500);
    printf("%c", ce);
    Beep(440,100);Sleep( 300);
    printf("%c", ce);
    Beep(480,80);Sleep( 330);
    printf("%c", ce);
    Beep(450,100);Sleep( 150);
    printf("%c", ce);
    Beep(430,100);Sleep( 300);
    printf("%c", ce);
    Beep(380,100);Sleep( 200);
    printf("%c", ce);
    Beep(660,80);Sleep( 200);
    printf("%c", ce);
    Beep(760,50);Sleep( 150);
    printf("%c", ce);
    Beep(860,100);Sleep( 300);
    printf("%c", ce);
    printf("\n Aperte enter para ir para o sistema\n");

    sistema();

    break;
    }
    Beep(1000,1300);

    do{

    menu();


    printf("\n\nDigite sua opção de escolha: \n");
    scanf("%d", &choice);
    printf("\n");

    if (choice == 1){
        int op;
        printf("\n [1] - Inserir ordenado por idade");
        printf("\n [2]-  Inserir ordenado por estoque");
        printf("\n [3] - Inserir ordenado por país\n");
        printf("\n Digite uma opção de escolha: ");
        scanf("%d", &op);

        switch (op){
        int i, n;
        case 1:


        printf("Quantas bebidas deseja inserir ? \n");
        scanf("%i", &n);

        for (i=0; i <n; i++){
        printf("\n--------Ordenar por idade---------\n");

        printf("\nCodigo: ");
        scanf("%d", &elem.codigo);
        fflush(stdin);

        printf("\nNome bebida: ");
        scanf("%s", &drink);
        strcpy(elem.nome, drink);
        fflush(stdin);

        printf("\nPaís: ");
        scanf("%s", drink);
        strcpy(elem.pais, &drink);
        fflush(stdin);

        printf("\nPreço bebida: ");
        scanf("%d", &elem.preco);
        fflush(stdin);

        printf("\nIdade bebida: ");
        scanf("%d", &elem.idade);
        fflush(stdin);

        printf("\nQuantidade em estoque: ");
        scanf("%d", &elem.estoque);
        fflush(stdin);

        inserir_idade_Ordenado(&lista, elem);
        printf("\n");

        strcpy(drink, "");

        }
        sistema();
        break;

        case 2:
        printf("\nQuantas bebidas deseja inserir ? \n");
        scanf("%i", &n);

        for (i=0; i <n; i++){
        printf("\n--------Ordenar por estoque--------\n");
        printf("\nCodigo: ");
        scanf("%d", &elem.codigo);
        fflush(stdin);

        printf("\nNome bebida: ");
        scanf("%s", &drink);
        strcpy(elem.nome, drink);
        fflush(stdin);

        printf("\nPaís: ");
        scanf("%s", drink);
        strcpy(elem.pais, &drink);
        fflush(stdin);

        printf("\nPreço bebida: ");
        scanf("%d", &elem.preco);
        fflush(stdin);

        printf("\nIdade bebida: ");
        scanf("%d", &elem.idade);
        fflush(stdin);

        printf("\nQuantidade em estoque: ");
        scanf("%d", &elem.estoque);
        fflush(stdin);

        inserir_estoque_Ordenado(&lista, elem);
        printf("\n");
        strcpy(drink, "");
        }
        sistema();
        break;

        case 3:
        printf("\nQuantas bebidas deseja inserir ? \n");
        scanf("%i", &n);

        for (i=0; i <n; i++){
        printf("\n--------Ordenar por país--------\n");
        printf("\nCodigo: ");
        scanf("%d", &elem.codigo);
        fflush(stdin);

        printf("\nNome bebida: ");
        scanf("%s", &drink);
        strcpy(elem.nome, drink);
        fflush(stdin);

        printf("\nPaís: ");
        scanf("%s", drink);
        strcpy(elem.pais, &drink);
        fflush(stdin);

        printf("\nPreço bebida: ");
        scanf("%d", &elem.preco);
        fflush(stdin);

        printf("\nIdade bebida: ");
        scanf("%d", &elem.idade);
        fflush(stdin);

        printf("\nQuantidade em estoque: ");
        scanf("%d", &elem.estoque);
        fflush(stdin);
        inserir_pais_Ordenado(&lista, elem);
        printf("\n");
        strcpy(drink, "");
        }
        sistema();
        break;

        default:
        printf("Digite uma opção válida ");
        break;
        }

    }
    else if(choice == 2){
    exibirLista(&lista);
    sistema();
    }
    else if(choice == 3){

    printf("\n Busca: \n");
    printf("\nCodigo do produto para busca: ");
    scanf("%d", &codigo);
    fflush(stdin);
    busca_elemento(&lista, codigo);
    sistema();

    }
    else if(choice == 4){
    printf("\n Excluir: \n");
    printf("\nCodigo do produto que desejaria excluir: ");
    scanf("%d", &codigo);
    fflush(stdin);
    excluir_elemento(&lista, codigo);
    sistema();

    }
    else if(choice == 5){
    alterar(&lista, chave, novo);
    sistema();
    }
    else if (choice == 6){
    printf("Reiniciando a lista \n");
    reinicializarLista(&lista);
    sistema();
    }
    else if(choice == 7){
        exit(0);
    }

    else{
        printf("Opção inválida\n");

    }

   }while (choice !=8);

    return 0;

}




