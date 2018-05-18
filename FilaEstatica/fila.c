#include "fila.h"

void inicializarFila(FILA *f)
{
    f->nmrElem = 0;
    f->inicio = 0;
}

int tamanhoFila(FILA *f)
{
    return f->nmrElem;
}

void exibirFila(FILA *f)
{
    int c;
    int pos = f->inicio;
    printf("FILA: ");
    for (c = 0; c < f->nmrElem; c++)
    {
        printf(" %d", f->A[pos].chave);
        printf("|");
        pos = (++pos) % MAX;
    }
    printf("\n");
}

int buscaSequencial(FILA *l, int elem)
{
    int c;
    for (c = 0; c < l->nmrElem; c++)
    {
        if (l->A[c].chave == elem)
        {
            return c;
        }
    }
    return -1;
}

int inserirElemFila(FILA *f, REGISTRO reg)
{
    if (f->nmrElem == MAX)
    {
        return -1;
    }
    int pos = (f->inicio + f->nmrElem) % MAX;
    f->A[pos] = reg;
    (f->nmrElem)++;
    return 0;
}

int excluirElemFila(FILA *f)
{
    if (f->nmrElem == 0)
    {
        return -1;
    }
    (f->nmrElem)--;
    (f->inicio)++;
    if (f->inicio == MAX)
    {
        f->inicio = 0;
    }
    return 0;
}

void reinicializarFila(FILA *f)
{
    inicializarFila(f);
}
