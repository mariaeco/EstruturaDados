/* 
ALOCACAO DINAMICA
AULA 01

*/
#include <stdio.h>
#include <stdlib.h>
//* malloc retorna um void ponteiro (void *)


int main(){
    int *p;
   // char *vet;
  //  int n = 8; // n eh o tamanho do  que quero alocar
// ponteiro para  (eu poderia fazer *vet[8]), mas assim eu nao aloco as
// posicoes na memoria stack que eh pequena. Com o malloc eu aloco na memoria Heap.

    // alocacao para int
    printf("\nValor antes da alocacao = %d", p);
    p = (int*)malloc(sizeof(int));
    printf("\nValor depois da alocacao = %d", p);
    printf("\n\n");
    //A malloc sempre retorna void, entao preciso forçar a retonar no tipo que desejo.
    //Faço isso usando um cash antes do malloc: (int*),(char*),(float*)..

    if(!p){
        printf("Sem memoria.\n");
        exit(1);
    }else{
        printf("Memoria alocada.\n");
    };

    printf("\nValor apontado por p = %d", *p);
    *p = 7;
    printf("\nValor apontado por p = %d", *p);

    free(p);
 
    printf("\nValor de p = %d", p);
    printf("\nValor apontado por p = %d", *p);

   // APOS O FREE o espaco nao eh mais meu, mas posso mesmo assim forcar e colocar valores dentro
   // nao eh legal, pois a memoria depois do free nao eh mais minha e pode entrar em espacos utilizados
    *p = 10;
    printf("\nValor apontado por p = %d", *p);
/*
    // alocacao para char
    int  i= 0;
    for(i = 0; i <= n; ++i){
        vet=(char*)malloc(sizeof(char)); // veja que aqui  nao preciso fazer vet[i] = ....
        if(!vet){
            printf("Sem memoria.\n");
            exit(1);
        }else{
            printf("Memoria para ponteiro de chars alocada.\n");
        };

    }
*/

  //  free(vet);
    return 0;
}
