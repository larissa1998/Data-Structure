#include <stdio.h>
#include <conio.h>
#include "Lista.h"
#include <string.h>



void inicializaLista (LISTA *l){
 l->nroElem = 0;
}

void tamanhoLista (LISTA *l){
return (l->nroElem);
}



void inserirElemLista(LISTA *l, AGENDA elem) {

    int i, n;
    printf("Quantas pessoas deseja inserir ? \n");
    scanf("%i", &n);

    if(n>50){
        printf("Lista cheia \n");
        system("pause");
        system("cls");
        return;
    }

    for (i=0; i <n; i++) {
        printf("\nPESSOA %i:", i+1);

        printf("\nDigite seu nome: ");

        scanf("%s", &(l->A[i].nome));
        fflush(stdin);
        printf("\nDigite seu telefone: ");

        scanf("%s", &(l->A[i].telefone));
        fflush(stdin);
        printf("\nDigite seu endereco: ");

        scanf("%s", &(l->A[i].endereco));
        fflush(stdin);
        printf("\nDigite seu email: ");

        scanf("%s", &(l->A[i].email));
        fflush(stdin);

        l->nroElem = l->nroElem + 1;
    }

system("cls");
}


void exibirLista(LISTA *l,AGENDA elem) {
    int i;

    for(i=0; i < l->nroElem; i++) {

        printf("\n");
        printf("Pessoa %i \n", i+1);
        printf("Nome: ");
        printf("%s\n", l->A[i].nome);
        printf("Telefone: ");
        printf("%s\n", l->A[i].telefone);
        printf("Endereço ");
        printf("%s\n", l->A[i].endereco);
        printf("Email: ");
        printf("%s\n", l->A[i].email);


}
  system("pause");
  system("cls");
}


int buscaSequencial(LISTA *l, AGENDA ag){
	char nome [100];
    printf("Digite o nome: \n");
    scanf("%s", nome);
	for(int i=0;i<l->nroElem;i++){
		if(!strcmp(l->A[i].nome,nome)){
			printf("O numero da chave do elemento é: %d \n", i);
			system("pause");
			system("cls");
			return i;
		}

	}

	printf ("Esse elemento não existe !!");
	system("pause");
    system("cls");
	return -1;
}

 void excluir(LISTA *l, AGENDA ag)
 {
    int pos = 0, i;
    char excluido = "";

    getchar();

    pos = buscaSequencial(l, ag);

    if(pos == -1)
    {
        puts("Elemento inexistente");
    }else
    {

        for(i = pos; i < l->nroElem; i++)
        {

            l->A[i] = l->A[i + 1];
        }

        l->A[i] = ag;
        l->nroElem--;
    }

}

