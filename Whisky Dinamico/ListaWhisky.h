#ifndef LISTAWHISKY_H_INCLUDED
#define LISTAWHISKY_H_INCLUDED

typedef TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
    char nome[20];
    char pais[20];
    double preco;
    int idade;
    int codigoProduto;
    int quantidadeEstoque;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT inicio;
}LISTA;

 // PROTÓTIPOS
void imprime(LISTA *l, REGISTRO elem);
void inserirElemOrdenadoIdade(LISTA *l, REGISTRO elem);
void inserirElemOrdenadoQuantidade(LISTA *l, REGISTRO elem);
void inserirElemOrdenadoPais(LISTA *l, REGISTRO elem);
PONT buscaElemento(LISTA *l, int code);
void excluirElemento(LISTA *l, int exclui);
void reinicializa(LISTA *l);

#endif // LISTAWHISKY_H_INCLUDED
