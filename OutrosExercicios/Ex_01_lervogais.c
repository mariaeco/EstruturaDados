/*
    FAZER UMA FUNÇÃO QUE CONTE AS VOGAIS DE UM VETOR CARACTERES LOCAL A MAIN
*/

#include  <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (){

int i, j;
int nVogais = 0;
int tamanho;
char *frase = "Fulano DE TaU"; 
char vogais[] = {'a','A','e','E','i','I','o','O','u','U'};

//ptr = frase;

       
tamanho = strlen(frase);
printf("Tamanho: %d\n",tamanho);
printf("Frase digitada: %s\n",frase);



for (i = 0; i <tamanho; i++){

    for (j = 0; j < strlen(vogais); j++){
        if(frase[i] == vogais[j]){
            printf("Vogal encontrada.............\n");
            nVogais++;
            //break;
        }

    }
}

printf("Numero de vogais: %d\n", nVogais);

   return 0;
}