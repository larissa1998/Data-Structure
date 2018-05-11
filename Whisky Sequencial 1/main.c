#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(){

setlocale(LC_ALL, "PORTUGUESE");

LISTABEBIDA lista;
WHISKY whis;

int busca;
int nestoque;
int exclui;
int operacao;

char novo[] = "";
char op;

inicializar(&lista);

whis.codigo = 1;
strcpy(whis.nome_bebida , "Jack Daniels");
whis.idade_bebida = 12;
whis.quantidade = 3;
insereBebida(&lista, whis);

whis.codigo = 2;
strcpy(whis.nome_bebida , "Red Label");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 3;
strcpy(whis.nome_bebida , "Johnnie Walker");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 4;
strcpy(whis.nome_bebida , "Chivas Regal");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 5;
strcpy(whis.nome_bebida , " Ballantine's");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);


whis.codigo = 6;
strcpy(whis.nome_bebida , " White Horse");
whis.idade_bebida= 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 7;
strcpy(whis.nome_bebida , " J & B");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 8;
strcpy(whis.nome_bebida , " Passport");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 9;
strcpy(whis.nome_bebida, " Jameson");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo= 10;
strcpy(whis.nome_bebida , " Blue Label");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 11;
strcpy(whis.nome_bebida , " 100 Pipers");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 12;
strcpy(whis.nome_bebida , " Black and White");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo= 13;
strcpy(whis.nome_bebida , "Buchanans");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 14;
strcpy(whis.nome_bebida , " Grant’s");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 15;
strcpy(whis.nome_bebida , " Burrberrys");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 16;
strcpy(whis.nome_bebida , " Teacher’s");
whis.idade_bebida = 5;
whis.quantidade= 8;
insereBebida(&lista, whis);

whis.codigo= 17;
strcpy(whis.nome_bebida , " Sir Edward’s");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 18;
strcpy(whis.nome_bebida , " Something Special");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 19;
strcpy(whis.nome_bebida , " Whyte & Mackay");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 20;
strcpy(whis.nome_bebida , "William Lawson’s");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 21;
strcpy(whis.nome_bebida , " Old Virginia");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 22;
strcpy(whis.nome_bebida , " Jim Beam Black");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 23;
strcpy(whis.nome_bebida , " Old Pulteney Malta");
whis.idade_bebida= 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 24;
strcpy(whis.nome_bebida , " Rob Roy");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 25;
strcpy(whis.nome_bebida , " William Lawson’s");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 26;
strcpy(whis.nome_bebida , " Of Ye Monks");
whis.idade_bebida = 5;
whis.quantidade= 8;
insereBebida(&lista, whis);

whis.codigo = 27;
strcpy(whis.nome_bebida , " Sandy Mac");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 28;
strcpy(whis.nome_bebida , " Dunhill");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);

whis.codigo = 29;
strcpy(whis.nome_bebida , " The Macallan");
whis.idade_bebida = 5;
whis.quantidade= 8;
insereBebida(&lista, whis);

whis.codigo = 30;
strcpy(whis.nome_bebida , " Evan William’s");
whis.idade_bebida = 5;
whis.quantidade = 8;
insereBebida(&lista, whis);


void sistema (){
 system("pause");
 system("cls");
 return;
}

void menuBebidas() {
    printf("Whisky menu");
    printf("\n [1] -  Inserir");
    printf("\n [2] -  Exibir");
    printf("\n [3] -  Busca Sequêncial ");
    printf("\n [4] -  Busca Binária");
    printf("\n [5] -  Alterar o estoque de bebidas");
    printf("\n [6] -  Excluir ");
    printf("\n [7] -  Reiniciar lista");
    printf("\n [8] -  Total de bebidas");
    printf("\n [9] -  Sair do sistema ");
    return;
}

do{

 menuBebidas();
 printf("\n");
 printf("Digite uma opção de escolha: \n");
 scanf("%d", &operacao);


 if (operacao == 1){

            printf("Inserindo bebida\n");

            printf("\nCodigo da bebida: ");
            scanf("%d", &whis,fflush(stdin));
            fflush(stdin);

            printf("\nNome da bebida: ");
            scanf("%s", novo);

            strcpy(whis.nome_bebida, novo);
            fflush(stdin);

            printf("\nIdade da bebida: ");
            scanf("%d", &whis.idade_bebida);
            fflush(stdin);

            printf("\nQuantidade em estoque: ");
            scanf("%d", &whis.quantidade);
            fflush(stdin);

            insereBebida(&lista, whis);
            char novo[] = "";



 }
    else if (operacao == 2){

            printf("\n Exibindo a lista: \n");
            exibirBebidas(&lista);

 }

    else if(operacao == 3){
            printf("\n Busca sequencial: \n");
            printf("\nCodigo do produto para busca: ");
            scanf("%d", &busca);
            fflush(stdin);
            buscaSequencialBebida(&lista, busca);

 }

  else if(operacao == 4){
            printf("\n Busca binária: \n");

            printf("\nCodigo do produto para busca: ");
            scanf("%d", &busca);
            fflush(stdin);

            mostrarBusca(&lista, 0, lista.nroElem - 1, busca);

 }

  else if(operacao == 5){
            printf("\n Alterando estoque: \n");

            printf("\nCodigo da bebida: ");
            scanf("%d", &busca);
            fflush(stdin);
            printf("\nNova quantidade em estoque: ");
            scanf("%d", &nestoque);
            fflush(stdin);
            alterar(&lista, busca, nestoque);

 }

  else if(operacao == 6){
            printf("\n Excluindo");
            printf("\nCodigo da bebida:\n ");
            scanf("%d", &exclui);
            fflush(stdin);
            excluirBebida(&lista, exclui);
 }

  else if(operacao == 7){
            printf("Reiniciando");
            reinicializarLista(&lista);

 }

  else if(operacao == 8){
            printf("\nTotal de bebidas no sistema: %d\n",tamanhoLista(&lista));

}

  else if(operacao == 9){
            printf("\n Saindo do sistema \n");
            exit (0);
  }


 else{

    printf("DIGITE UMA OPÇÃO VÁLIDA \n");
 }

sistema();

} while (operacao != 9);
}


