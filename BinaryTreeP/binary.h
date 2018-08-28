#ifndef BINARY_H_INCLUDED
#define BINARY_H_INCLUDED
typedef int bool;
typedef int TipoChave;

typedef struct aux {
    TipoChave chave;
    struct aux *esq, *dir;
} NO;

typedef NO* Pont;


///----------------------PROTÓTIPOS--------------------------
Pont inicializa();
Pont criaNovoNo(TipoChave ch);
Pont adiciona(Pont raiz, Pont no);
Pont contem(TipoChave ch, Pont raiz);
void leituraEmOrdem(Pont raiz);
void leituraPreOrdem(Pont raiz);
void leituraPosOrdem(Pont raiz);
int conta(Pont raiz);
Pont buscaNo(Pont raiz, TipoChave ch, Pont *pai);
Pont removeNo(Pont raiz, TipoChave ch);
Pont removeNoDir(Pont raiz, TipoChave ch);


#endif // BINARY_H_INCLUDED
