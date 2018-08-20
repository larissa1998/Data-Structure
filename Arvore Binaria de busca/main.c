#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"




int main()
{
    Pont r = inicializa();
    Pont node = createNode(23);
    r = adiciona(r,node);
    node = createNode(12);
    r = adiciona(r,node);
}
