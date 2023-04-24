/*
    FAZER UMA FUNÇÃO QUE CONTE AS VOGAIS DE UM VETOR CARACTERES LOCAL A MAIN
    Lendo um conjunto de vetores com nomes e contando as vogais de cada uma
*/

#include  <stdio.h>
#include <stdlib.h>
#include <string.h>


int vogalCount(char **ptr, int n){
    char **frase = ptr;
    int nLinhas = n;
    int nVogais=0;
    char vogais[] = {'a','A','e','E','i','I','o','O','u','U'};
  

    for (int i = 0; i < nLinhas; i++){
        printf("Frase digitada: %s\n",frase[i]);
    }

    for(int i = 0; i < nLinhas; i++){
        

        for (int j = 0; j < strlen(frase[i]); j++){
            
            for (int k = 0; k < strlen(vogais); k++){
                if(frase[i][j] == vogais[k]){
                    nVogais++;
                    break;
                }
            }
        }

        printf("Numero de vogais: %d\n", nVogais);
        nVogais=0;
    }

    return nVogais;
}

int main (int argc, char const *argv[]){

//int nVogais;
    char **frase;
    int Nnome;
  
    printf("Digite o numero de frases que deseja digitar: ");
    scanf("%i",&Nnome); // 

    //printf("numero de frases: %d",Nnome); 

    frase  = (char**)malloc(Nnome*sizeof(char*)); // alocando as linhas
    if (frase == NULL){
        printf("Memoria insuficiente.\n");
    exit(1);
    }else{
        printf("Memoria Alocada.\n");
    }

    for (int i=0; i<Nnome; i++){
        frase[i]  = (char*)malloc(sizeof(char));
        if (frase[i] == NULL){
            printf("Memoria insuficiente.\n");
            exit(1);
        }else{  
            printf("Memoria Alocada.\n");
        }

    }

    getchar();

    for (int i = 0; i < Nnome; i++){
        printf("Digite o nome %i: ", i+1);
         scanf("%[^\n]%*c",frase[i]); // o mesmo que gets mas nao usar gets, eh perigoso
    }
    
    vogalCount(frase, Nnome);
    

    for (int i = 0; i < Nnome; i++){  //    primeiro libero as colunas dentro de cada linha
        free(frase[i]);  
    };

    free(*frase); // agora libero as linhas
    *frase =  NULL; // e faço o ponteiro apontar para NULL



   
    return 0;
   
}