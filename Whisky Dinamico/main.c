#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "ListaWhisky.h"


int main()
{
    setlocale(LC_ALL, "PORTUGUESE");
    int op;
    int code;
    int exclui;
    char novo[20] = "";
    LISTA lista;
    ELEMENTO elem;
    REGISTRO reg;
    int sair=0;

    inicializar(&lista);
 do{
    system("cls");
    printf("Menu");
    printf("\n 1 - Inserir");
    printf("\n 2 - Buscar");
    printf("\n 3 - Imprimir");
    printf("\n 4 - Excluir");
    printf("\n 5 - Reinicializar");
    printf("\n 6 - Sair");
    printf("\n Digite a opção: \n");
    scanf("%d", & op);

    switch(op){
    case 1:
    printf("\n 1 - Ordernar por idade");
    printf("\n 2 - Ordernar por quantidade");
    printf("\n 3 - Ordernar por páis \n");
    fflush(stdin);
    scanf("%d", & op);

    if(op==1){
        int escolha,i;
    printf("Inserindo bebida\n");
    printf("Quantas bebidas deseja inserir: \n");
    scanf("%d", &escolha);
    for(i=0; i<escolha; i++){
    printf("---------------------------------------");
    printf("\nCodigo da bebida: ");
    scanf("%d", &reg.codigoProduto);
    fflush(stdin);

    printf("\nNome da bebida: ");
    scanf("%s", &novo);

    strcpy(reg.nome, novo);
    fflush(stdin);

    printf("\nPaís: ");
    scanf("%s", &novo);

    strcpy(reg.pais, novo);
    fflush(stdin);

    printf("\nIdade da bebida: ");
    scanf("%d", &reg.idade);
    fflush(stdin);

    printf("\nQuantidade em estoque: ");
    scanf("%d", &reg.quantidadeEstoque);
    fflush(stdin);

    printf("\nPreço do produto: ");
    scanf("%d", &reg.preco);
    fflush(stdin);

    inserirElemOrdenadoIdade(&lista, reg);
    strcpy(novo, "");
    }
    system("PAUSE");

    }else if(op==2){
        int escolha,i;
    printf("Inserindo bebida\n");
    printf("Quantas bebidas deseja inserir: \n");
    scanf("%d", &escolha);

    for(i=0; i<escolha; i++){
    printf("---------------------------------------");
    printf("\nCodigo da bebida: ");
    scanf("%d", &reg.codigoProduto);
    fflush(stdin);

    printf("\nNome da bebida: ");
    scanf("%s", &novo);

    strcpy(reg.nome, novo);
    fflush(stdin);

    printf("\nPaís: ");
    scanf("%s", &novo);

    strcpy(reg.pais, novo);
    fflush(stdin);

    printf("\nIdade da bebida: ");
    scanf("%d", &reg.idade);
    fflush(stdin);

    printf("\nQuantidade em estoque: ");
    scanf("%d", &reg.quantidadeEstoque);
    fflush(stdin);

    printf("\nPreço do produto: ");
    scanf("%d", &reg.preco);
    fflush(stdin);

    inserirElemOrdenadoQuantidade(&lista, reg);
    strcpy(novo, "");
    }
    system("PAUSE");

    }else if(op==3){
            int escolha,i;
    printf("Inserindo bebida\n");
    printf("Quantas bebidas deseja inserir: \n");
    scanf("%d", &escolha);

    for(i=0; i<escolha; i++){
    printf("---------------------------------------");
    printf("\nCodigo da bebida: ");
    scanf("%d", &reg.codigoProduto);
    fflush(stdin);

    printf("\nNome da bebida: ");
    scanf("%s", &novo);

    strcpy(reg.nome, novo);
    fflush(stdin);

    printf("\nPaís: ");
    scanf("%s", &novo);

    strcpy(reg.pais, novo);
    fflush(stdin);

    printf("\nIdade da bebida: ");
    scanf("%d", &reg.idade);
    fflush(stdin);

    printf("\nQuantidade em estoque: ");
    scanf("%d", &reg.quantidadeEstoque);
    fflush(stdin);

    printf("\nPreço do produto: ");
    scanf("%d", &reg.preco);
    fflush(stdin);

    inserirElemOrdenadoPais(&lista, reg);
    strcpy(novo, "");
    }
    system("PAUSE");

    }else{
    printf("\n Opção inválida!!");
    }
    break;

    case 2:
    buscaElemento(&lista, code);
    system("PAUSE");
    break;

    case 3:
    imprime(&lista, reg);
    break;

    case 4:
    excluirElemento(&lista, exclui);
    system("PAUSE");
    break;

    case 5:
    reinicializa(&lista);
    system("PAUSE");
    break;

    case 6:
    sair=-1;
    break;

    default:
    printf("\n Opção inválida!! \n");
    system("PAUSE");
    break;
    }
    }
    while(sair==0);
  }
