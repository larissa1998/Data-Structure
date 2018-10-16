#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "academico.h"
#include <string.h>
#include <windows.h>
#include <conio.h>

int main()
{

///LARISSA FOGAÇA MENDES

    system("COLOR 0A");

    setlocale(LC_ALL, "PORTUGUESE");

    int ra;
    LISTA lista;
    ALUNO aluno;
    int choice;
    char ce = '#';
    Sleep(200);
    inicializarLista(&lista);
    PONT arvRa = inicializar();
    PONT arvNome = inicializar();

    void sistema()
    {
        printf("\n");
        system("pause");
        system("cls");
    }


    printf("CARREGANDO O SISTEMA \n");
    Beep(293,250);
    printf("%c", ce);
    Beep(293,250);
    printf("%c", ce);
    Beep(220,250);
    printf("%c", ce);
    Beep(220,250);
    printf("%c", ce);
    Beep(293,250);
    printf("%c", ce);
    Beep(293,250);
    printf("%c", ce);
    Beep(330,250);
    printf("%c", ce);
    Beep(330,250);
    printf("%c", ce);
    Beep(349,250);
    printf("%c", ce);
    Beep(349,250);
    printf("%c", ce);
    Beep(330,250);
    printf("%c", ce);
    Beep(330,250);
    printf("%c", ce);
    Beep(293,250);
    printf("%c", ce);
    Beep(293,250);
    printf("%c", ce);
    Beep(330,250);
    printf("%c", ce);
    Beep(293,250);
    printf("%c", ce);
    Beep(262,250);
    printf("%c", ce);
    Beep(262,250);
    printf("%c", ce);
    Beep(196,250);
    printf("%c", ce);
    Beep(196,250);
    printf("%c", ce);
    Beep(262,250);
    printf("%c", ce);
    Beep(262,250);
    printf("%c", ce);
    Beep(293,250);
    printf("%c", ce);
    Beep(293,250);
    printf("%c", ce);
    Beep(330,250);
    printf("%c", ce);
    Beep(330,250);
    printf("%c", ce);
    Beep(293,250);
    printf("%c", ce);
    Beep(293,250);
    printf("%c", ce);
    Beep(262,250);
    printf("%c", ce);
    Beep(262,250);
    printf("%c", ce);
    Beep(330,250);
    printf("%c", ce);
    Beep(262,250);
    printf("%c", ce);


    printf("\n Aperte enter para ir para o sistema\n");

    sistema();

    Beep(1000,1300);
    do
    {


        char nome2 [200];

        printf("\n---------------MENU---------------");

        printf("\n [1] -  Inserir");
        printf("\n [2] -  Exibir");
        printf("\n [3] -  Buscar");
        printf("\n [4] -  Remover");
        printf("\n [5] -  Liberar Memória");
        printf("\n [0] -  Sair do sistema \n");

        printf("Digite uma opção de escolha: \n");
        scanf("%d", &choice);


        switch(choice)
        {

        case 1:

            printf("\n----------INSERIR----------- \n");

            printf("\nNome do Aluno:  ");
            scanf("%s", &nome2);
            strcpy(aluno.nome, nome2);
            fflush(stdin);

            printf("\nRA do Aluno:  ");
            scanf("%d", &aluno.RA);
            fflush(stdin);

            aluno.curso = (aluno.RA/10000);

            inserirOrdenado(&lista, aluno);


            PONT2 aux = lista.inicio;

            while(aux!=NULL)
            {
                ALUNO *aluno2 = &aux->aluno;
                arvNome = insereNome(arvNome, aluno2);
                arvRa= insereRA(arvRa, aluno2);
                aux = aux->prox;
            }

            sistema();
            break;


        case 2:
            printf("\n -------EXIBIR-----------\n");

            printf("\n [1] -  Exibir em Lista");
            printf("\n [2] -  Exibir em Árvore");

            printf("\nDigite uma opção de escolha: \n");
            scanf("%d", &choice);

            if(choice == 1)
            {
                printf("\n-----------EXIBIÇÃO LISTA-----------\n");
                exibirLista(&lista);
                printf("--------------------");
            }
            else if (choice == 2)
            {

                printf("\n----------TIPO DE EXIBIÇÃO DA ÁRVORE----------\n");
                printf("\n [1] - Exibir em Ordem");
                printf("\n [2] - Exibir em Pré-Ordem");
                printf("\n [3] - Exibir em Pós-Ordem");
                printf("\nDigite uma opção de escolha: \n");
                scanf("%d", &choice);


                if(choice == 1)
                {

                    printf("\n Em Ordem do RA:\n");
                    EmOrdem(arvRa);
                    if(arvRa == NULL)
                    {
                        printf("Não temos nada para exibir!\n");
                    }
                    printf("\n Em Ordem do Nome:\n");
                    EmOrdem(arvNome);
                    if(arvNome == NULL)
                    {
                        printf("Não temos nada para exibir!\n");
                    }
                }

                else if(choice == 2)
                {
                    printf("\n Pré-Ordem do RA:\n");
                    PreOrdem(arvRa);
                    if(arvRa == NULL)
                    {
                        printf("Não temos nada para exibir!\n");
                    }
                    printf("\n Pré-Ordem do Nome:\n");
                    PreOrdem(arvNome);
                    if(arvNome == NULL)
                    {
                        printf("Não temos nada para exibir!\n");
                    }
                }

                else if(choice == 3)
                {
                    printf("\n Pós-Ordem do RA:\n");
                    PosOrdem(arvRa);
                    if(arvRa == NULL)
                    {
                        printf("Não temos nada para exibir!\n");
                    }
                    printf("\n Pós-Ordem do Nome:\n");
                    PosOrdem(arvNome);

                    if(arvNome == NULL)
                    {
                        printf("Não temos nada para exibir!\n");
                    }
                }

                else
                {
                    printf("\n Opção inválida!\n");
                }

            }

            sistema();
            break;

        case 3:
            printf("\n---------- BUSCAR-----------");
            printf("\n [1] -  Por Nome");
            printf("\n [2] -  Por RA");

            printf("\n [3] -  Buscar alunos de um determinado curso\n");

            printf("\nDigite uma opção de escolha: \n");
            scanf("%d", &choice);

            if(choice == 1)
            {
                printf("\n Digite o Nome:");
                fflush(stdin);
                gets(nome2);

                printf("\nBuscando:");
                arvNome = buscaNome(arvNome,nome2);


                printf("\n\n");
            }
            else if(choice == 2)
            {
                printf("\nDigite o RA a ser buscado:");
                scanf("%i", &ra);


                printf("\n");

                printf("\nBuscando :");
                arvRa = buscaRA(arvRa, ra);

                printf("\n\n");


            }
            else if(choice == 3)
            {

                printf("\n Tabela de cursos\n");

                printf("\n[12] - Ciência da Computação\n");
                printf("\n[40] - Sistemas de Informação\n");
                printf("\n[20] - Biologia\n");
                printf("\n[10] - Agronomia\n");
                printf("\n[30] - Enfermagem\n");
                printf("\n[50] - Medicina Veterinária\n");

                printf("\nDigite o código do curso a ser buscado:");
                scanf("%i", &ra);

                if(ra == 12)
                {
                    printf("\nCiência da Computação\n");
                }
                else if(ra == 40)
                {
                    printf("\nSistemas de Informação\n");
                }
                else if(ra == 50)
                {
                    printf("\nMedicina Veterinária\n");
                }
                else if(ra == 30)
                {
                    printf("\nEnfermagem\n");
                }
                else if(ra == 20)
                {
                    printf("\nBiologia\n");
                }
                else if(ra == 10)
                {
                    printf("\nAgronomia\n");
                }
                printf("\nBuscando por curso:");
                buscaTudo(&lista,ra);
            }
            else
            {
                printf("Digite uma opção válida!\n");
            }

            sistema();
            break;

        case 4:

            printf("\n------EXCLUIR ------");
            printf("\n [1] - Por Nome");
            printf("\n [2] - Por RA");

            printf("\nDigite uma opção de escolha: \n");
            scanf("%d", &choice);


            if(choice == 1)
            {
                char nomeExcluir[50];
                printf("\n Digite o Nome:");
                fflush(stdin);
                gets(nomeExcluir);
                arvRa = removerNome(arvRa, nomeExcluir);
                arvNome = removerNome(arvNome,nomeExcluir);
                excluirNome(&lista, nomeExcluir);

            }
            else if(choice == 2)
            {
                int r;
                printf("\n Digite o RA:");
                scanf("%d", &r);
                arvRa = removerRa(arvRa, r);
                arvNome = removerRa(arvRa,r);
                excluirRA(&lista, r);
            }

            else
            {
                printf("\nDigite uma opção válida");
            }
            sistema();
            break;

        case 5:
            arvRa = libera_arvRa(arvRa);
            arvNome = libera_arvNome(arvNome);

            reinicializar(&lista);
            sistema();
            break;

        case 0:
            exit(0);
            break;

        }
    }
    while(choice != 6);

}
