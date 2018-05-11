#include "whis.h"
#include <stdio.h>
#include <stdlib.h>



void menuPrincipal() {

    puts("-------MENU IMPLEMENTACAO WHISKY------------");
    puts("[1] Cadastrar whisky");
    puts("[2] Exibir whisky");
    puts("[3] Excluir whisky");
    puts("[4] Buscar registro pelo codigo");
    puts("[6] Mostrar total de bebidas cadastradas");
    puts("[7] Reiniciar lista");
    puts("[8] Sair do programa");

}

int tamLista(LISTA *l) {
    return (l->numeroElem);
}

void inicio(LISTA *l){
l->numeroElem = 0;
}

void exibirDrink (LISTA *l){
 int i = 0;

    if(l->numeroElem != 0){
        do {
            printf("\n-----WHISKY:%i-----\n", (i+1));
            printf("Codigo %d \n", l->A[i].codigo_whisky);
            printf("Nome: %s \n", l->A[i].nome_whisky);
            printf("Idade: %d\n", l->A[i].idade_bebida);
            printf("Estoque: %d\n", l->A[i].estoque);

            i++;
        } while (i < l->numeroElem);
        puts("\nExibicao feita com sucesso!");
        system("pause");
        system("cls");
    } else {
        puts("Nao ha registros para exibir");
        system("pause");
        system("cls");
    }
}

void insereBebida (LISTA *l, REGISTRO elem){
int i;

  if(l->numeroElem >=MAX){
    printf("\n Lista cheia");
    return;
  }

  for ( i=l->numeroElem; i>0 && elem.codigo_whisky<l->A[i-1].codigo_whisky; i--){
    l->A[i]=l->A[i-1];
  }

  l->A[i]=elem;
  l->numeroElem=l->numeroElem+1;

}

int buscaSeq (LISTA *l, REGISTRO elem){

	int cod;
	int i;

    printf("Digite o codigo: \n");
    scanf("%i", &cod);

    if(l->numeroElem == 0) return -1;
	for(i = 0; i<l->numeroElem && cod!= l->A[i].codigo_whisky && cod >l->A[i].codigo_whisky; i++);

    printf("Bebida %i \n", i+1);
    printf("\n (%d) Codigo: %d", cod, l->A[i].codigo_whisky);
    printf("\n (%d) Nome whisky: %s", cod,l->A[i].nome_whisky);
    printf("\n (%d) Idade: %d", cod,l->A[i].idade_bebida);
    printf("\n (%d) Estoque: %d\n\n",cod, l->A[i].estoque);

if(i<l->numeroElem && cod == l->A[i].codigo_whisky) return (i);

else  return (-1);

}



void excluir(LISTA * l, REGISTRO elem)
{
    int i = buscaSeq(l,elem);

    if (i == -1)
        printf("\nElemento nao esta na lista\n");
    else
    {
        for (; (i + 1) < l->numeroElem ; i++)
        l->A[i] = l->A[i + 1];

        l->numeroElem = l->numeroElem - 1;
        printf("\nElemento %d excluido\n", elem);

    }
}


void reiniciar (LISTA *l){
return l->numeroElem = 0;
}
