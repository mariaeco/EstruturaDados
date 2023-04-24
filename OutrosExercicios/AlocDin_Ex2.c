/* 
ALOCACAO DINAMICA
EXERCICIO 02 - Alocando dinamicamente quantas frases eu desejar
                entretanto digo o numero inicial de frases que irei digitar
*/


#include  <stdio.h>
#include <stdlib.h>
#include <string.h>


//Main
int main (){
    int i; int tamanho;
    char **vfrases;
    //char *linhas; // cada nome em uma linha
    int Nnome=2; int count = 0;
    
    vfrases  = (char**)malloc(Nnome*sizeof(char*)); // alocando as linhas

    for (i=0; i<Nnome; i++){
        vfrases[i]  = (char*)malloc(100*sizeof(char));
    }
    
    if (vfrases == NULL){
        printf("Memoria insuficiente.\n");
    exit(1);
    }else{
        printf("Memoria Alocada.\n");
    }

    for (i = 0; i < Nnome; i++){
        printf("Digite o nome %i: ", i+1);
        gets(vfrases[i]);
        //scanf("%[^\n]%*c",vfrases[i]); // o mesmo que gets
    }

    printf("\nNomes digitados\n");
    for (i = 0; i < Nnome; i++){
        printf("Nomes: %s\n",vfrases[i]);
    }
    printf("\n");
        
    printf("\n\n\nNumero de caracteres por frase\n");
    for (i = 0; i < Nnome; i++){
        tamanho = strlen(vfrases[i]); // strlen conta os caracteres
        printf("Tamanho da frase (em caracteres): %d\n", tamanho);
        count ++;
    }

    printf("\nNumero de frases digitadas: %d\n", count);


    for (i = 0; i < Nnome; i++){  //    primeiro libero as colunas dentro de cada linha
        free(vfrases[i]);  
    };

    free(*vfrases); // agora libero as linhas
    *vfrases =  NULL; // e faço o ponteiro apontar para NULL

    getchar();

   return 0;
}
