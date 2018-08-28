#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

int main()
{
    Pont r = inicializa();
    Pont no = criaNovoNo(17);

    r = adiciona(r, no);

    no = criaNovoNo(12);
    r = adiciona(r, no);

    no = criaNovoNo(15);
    r = adiciona(r, no);

    no = criaNovoNo(25);
    r = adiciona(r, no);

    no = criaNovoNo(8);
    r = adiciona(r, no);

    no = criaNovoNo(20);
    r = adiciona(r, no);

    no = criaNovoNo(30);
    r = adiciona(r, no);

    r = removeNoDir(r, 17);

    printf("\n Leitura em Pre-Ordem \n");
    leituraPreOrdem(r);
    printf("\n");

    printf("\n Leitura em Pos-Ordem\n");
    leituraPosOrdem(r);
    printf("\n");

    printf("\n Leitura em Ordem\n");
    leituraEmOrdem(r);
    printf("\n");

    return 0;
}
