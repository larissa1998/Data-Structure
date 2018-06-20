#include "insertion.h"

void insertionsort(int *V, int n)
{
    int i,j,k,aux;

    if(n==1)
        return;

    for(i=0; i<n-1; i++)
    {
        j=i+1;
        aux=V[j];
        for(k=i; k>=0 && aux<V[k]; k--)
        {
            V[k+1] = V[k];
        }
        V[k+1] = aux;
    }
}
