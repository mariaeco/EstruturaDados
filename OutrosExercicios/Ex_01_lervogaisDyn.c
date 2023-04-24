/*
    FAZER UMA FUNÇÃO QUE CONTE AS VOGAIS DE UM VETOR CARACTERES LOCAL A MAIN
*/

#include  <stdio.h>
#include <stdlib.h>
#include <string.h>


int vogalCount(char *ptr){
    char * frase = ptr;
    int i, j;
    int nVogais=0;
    char vogais[] = {'a','A','e','E','i','I','o','O','u','U'};

    printf("\nFrase digitada: %s\n", frase);

    for (i = 0; i < strlen(frase); i++){

        for (j = 0; j < strlen(vogais); j++){
            if(frase[i] == vogais[j]){
                nVogais++;
                break;
            }
        }
    }

    printf("Numero de vogais: %d\n", nVogais);
    return nVogais;
}

int main (int argc, char const *argv[]){

//int nVogais;
    char *frase;
    int Nnome = 1;
  
    frase  = (char*)malloc(sizeof(char)); // alocando as linhas
    if (frase == NULL){
        printf("Memoria insuficiente.\n");
    exit(1);
    }else{
        printf("Memoria Alocada.\n");
    }

    
    //gets(frase);
    printf("Digite uma palara ou frase: ");
    scanf("%[^\n]%*c",frase); // o mesmo que gets
      
    vogalCount(frase);
    

   free(frase);
   return 0;
   
}