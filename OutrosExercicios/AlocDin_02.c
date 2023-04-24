/* 
ALOCACAO DINAMICA
AULA 02 - alocando espaco para 10 inteiros

*/
#include <stdio.h>
#include <stdlib.h>
//* malloc retorna um void ponteiro (void *)


int main(){
    int *p;
    int i;

    // alocacao para int

    p = (int*)malloc(sizeof(int));

    //A malloc sempre retorna void, entao preciso forçar a retonar no tipo que desejo.
    //Faço isso usando um cash antes do malloc: (int*),(char*),(float*)..

    if(!p){
        printf("Sem memoria.\n");
        exit(1);
    }else{
        printf("Memoria alocada.\n");
    };

    for(i=0; i<10;i=i+1){
        printf("\np[%d] = %d", i, p[i]);   
    }

    for(i=0; i<10;i=i+1){
        p[i] = i*10;
    }

    for(i=0; i<10;i=i+1){
        printf("\np [%d] = %d", i, p[i]);   
    }


    free(p);
 
    return 0;
}