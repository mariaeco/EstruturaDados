#include <stdio.h>
#include <stdlib.h>


typedef struct _lista{
    int info[10];
    int c; //minha variavel de controle
}Lista;



int main(int argc, char const *argv[]){

    int aux, i, j;
    int a = 0;
    Lista L; 

    L.c = 10;

    for(i=0; i<= L.c; i++){
        L.info[i] = a;
        a++;
    }

    //imprimir lista
    printf("\nLista->");
    for(int i=0; i <= L.c ; i++){
            printf("%d",L.info[i]);
            printf("->");
    }
    printf("NULL\n");

    for(i = 0; i <= L.c; i++){
        for(j = 0; j <= L.c; j++){

            if(L.info[j]<L.info[i] ){
                aux = L.info[i];
                L.info[i] = L.info[j];
                L.info[j] = aux;
            }
        }
    }


    //imprimir lista ordenada
    printf("\nLista->");
    for(int i=0; i <= L.c ; i++){
            printf("%d",L.info[i]);
            printf("->");
    }
    printf("NULL\n");
    system("pause");

    return 0;
}
    