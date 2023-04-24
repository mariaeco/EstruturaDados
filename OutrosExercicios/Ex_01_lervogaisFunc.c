/*
    FAZER UMA FUNÇÃO QUE CONTE AS VOGAIS DE UM VETOR CARACTERES LOCAL A MAIN
*/

#include  <stdio.h>
#include <stdlib.h>
#include <string.h>


int vogalCount(char *ptr){
    char * frase = ptr;
    int i, j;
    int nVogais;
    char vogais[] = {'a','A','e','E','i','I','o','O','u','U'};

    for (i = 0; i < strlen(frase); i++){
            printf("Letra digitada: %s", frase[i]);
        
        // count ++;

        for (j = 0; j < strlen(vogais); j++){
            if(frase[i] == vogais[j]){
                printf("-->Vogal encontrada.............\n");
                nVogais++;
                break;
            }else{
            printf("-->Nao eh a letra que procuramos\n"); 
            }

        }
    }

    printf("Numero de vogais: %d\n", nVogais);
    return nVogais;

}

int main (int argc, char const *argv[]){

//int nVogais;
char *frase = "Fulano DE TaU"; 

vogalCount(frase);

   return 0;
   
}