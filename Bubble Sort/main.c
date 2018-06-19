#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gerar_randomicamente(int *v){

 //int v[10];
 int i;

    for(i = 0; i < 10; i++){
        v[i] = rand() % 100 + 1;
    }

    for(i = 0; i < 10; i++){
        printf("%d  ", v[i]);

    }
    puts("");
}


void bubblesort(int *v, int n){

 int final= n-1;
 int i;
 int aux;
 int continua=0;

    do{
        continua =0;
        for(i = 0; i < final; i++){
            if(v[i] > v[i+1]){
                aux = v[i];
                continua =1;
                v[i] = v[i+1];
                v[i+1] = aux;
            }

        }
        final --;

    }while(continua!=0);

    for(i=0; i<10; i++){
        printf("%d ", v[i]);
 }
}

int main(){

int v[10];
int aux = 0;
int i;
int n = 10;
gerar_randomicamente(&v);
bubblesort(&v, n);

    return 0;

}
