#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Lista.h"
#include <windows.h>

int main()
{
    system("COLOR 0B");

    setlocale(LC_ALL, "PORTUGUESE");

    int op;

    LISTA l1,l2,l3,l4;

    REGISTRO reg;

    inicializarLista(&l1);
    inicializarLista(&l2);
    inicializarLista(&l3);
    inicializarLista(&l4);

 do{
    system("cls");
    printf("==========Menu===========");
    printf("\n 1 - Inserir Listas");
    printf("\n 2 - Imprimir Listas");
    printf("\n 3 - Concatenar Listas");
    printf("\n 4 - Reinicializar");
    printf("\n 5 - Sair");
    printf("\n Digite a opção: \n");
    scanf("%d", & op);
    printf("\n");

    if(op==1){

    printf("---------------------------------------");

    printf("\nDigite três número para lista 1:\n");
    scanf("%d", &reg.chave);
    inserirElemOrdenado(&l1, reg);
    scanf("%d", &reg.chave);
    inserirElemOrdenado(&l1, reg);
    scanf("%d", &reg.chave);
    inserirElemOrdenado(&l1, reg);

    printf("Digite três números para a lista 2: \n");
    scanf("%d", &reg.chave);
    inserirElemDesordenado1(&l2,reg);
    scanf("%d", &reg.chave);
    inserirElemDesordenado1(&l2,reg);
    scanf("%d", &reg.chave);
    inserirElemDesordenado1(&l2,reg);


    printf("Digite três números para a lista 3: \n");
    scanf("%d", &reg.chave);
    inserirElemDesordenado1(&l3,reg);
    scanf("%d", &reg.chave);
    inserirElemDesordenado1(&l3,reg);
    scanf("%d", &reg.chave);
    inserirElemDesordenado1(&l3,reg);

    } else if(op==2){
    imprime(&l1);
    printf("\n");

    imprime(&l2);
    printf("\n");

    imprime(&l3);
    printf("\n");

    } else if(op == 3){
    concatenarListas(&l1,&l2, &l3);
    imprime(&l4);

    }else if(op == 4){
    reinicializar(&l1);
    reinicializar(&l2);
    reinicializar(&l3);
    reinicializar(&l4);

    }

    system("PAUSE");

    }while(op!=5);
  }
