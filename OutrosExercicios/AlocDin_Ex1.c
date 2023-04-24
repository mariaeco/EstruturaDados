/* 
ALOCACAO DINAMICA

EXERCICIO 01 - Alocando dinamicamente uma frase de qualquer tamanho

*/


#include  <stdio.h>
#include <stdlib.h>
#include <string.h>


//Main
int main (){
    int i=0;
    int tamanho;
    char *linhas; // cada nome em uma linha
    
    linhas  = (char*)malloc(sizeof(char*)); // alocando as linhas
    
    if (linhas == NULL){
        printf("Memoria insuficiente.\n");
    exit(1);
    }else{
        printf("Memoria Alocada.\n");
    }


        printf("Digite o nome %i: ", i+1);
        gets(linhas);
        //scanf("%[^\n]%*c",linhas); // o mesmo que gets
        

        printf("Nomes: %s\n",linhas);
        
        tamanho = strlen(linhas); // strlen conta os caracteres
        printf("Tamanho da frase (em caracteres): %d", tamanho);

   // getchar();

   free(linhas);
    return 0;
}
