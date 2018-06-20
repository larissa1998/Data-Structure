#include <stdio.h>
#include <stdlib.h>

int main()
{
    int V[10] = {5,10,2,3,8,20,1,9,7,6};
    int n = 10;
    int i;

    printf("\n-----------------------------Antes\n");

    for(i = 0; i<n; i++) printf("\t%i", V[i]);

    insertionsort(&V, n);

    printf("\n-----------------------------Depois\n");

    for(i = 0; i<n; i++) printf("\t%i", V[i]);

    return 0;
}
