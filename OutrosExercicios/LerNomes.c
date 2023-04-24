/* 
ALOCACAO DINAMICA

EXERCICIO 03 - Guardar 10 nomes simples em um vetor de ponteiros alocados dinamicamente
    - alocar tudo dinamicamente
    - usar funcao para guardar nomes
    - usas funcao para mostrar nomes
    - liberar memoria

*/

#include  <stdio.h>
#include <stdlib.h>

//Variaveis Globais
int Nnome = 5; //quantidade de nomes que desejo utilizar

//Functions
void guardarNomes(char **vetNomes); //Funcao para ler nomes escritos pelo usuario: nomes = matriz de nomes, n = numero de nomes
void mostrarNomes(char **vetNomes); //Funcao para imprimir os nomes: nomes = matriz de nomes, n = numero de nomes
void limparMemoria(char **vetNomes);


void guardarNomes(char **vetNomes){ //funcao para guardar nomes

    int i;
    for (i = 0; i < Nnome; i++){
        printf("Digite o nome %i: ", i+1);
        scanf("%[^\n]%*c",vetNomes[i]); // le carecteres com espaco
    }

}

void mostrarNomes(char **vetNomes){

    int i;
    printf("\nNomes digitados\n");
    for (i = 0; i < Nnome; i++){
        printf("Nomes: %s\n",vetNomes[i]);
    }
    printf("\n");
}

void limparMemoria(char **vetNomes){ //funcao para limpar memoria

    int i;
    for (i = 0; i < Nnome; i++){  //    primeiro libero as colunas dentro de cada linha
        free(vetNomes[i]);  
    };

    free(*vetNomes); // agora libero as linhas
    *vetNomes =  NULL; // e faço o ponteiro apontar para NULL

}



//Main
int main (){
    int i;
    char **linhas; // cada nome em uma linha

    linhas  = (char**)malloc(Nnome*sizeof(char*)); // alocando as linhas
    // (char**)calloc(Nnome, sizeof(char*)); // usando calloc
    //alocando as colunas (caracteres):
    for (i=0; i<Nnome; i++){
        linhas[i]  = (char*)malloc(sizeof(char));
    }
    if (linhas == NULL){
        printf("Memoria insuficiente.\n");
    exit(1);
    }

    guardarNomes(linhas);
    mostrarNomes(linhas);
    limparMemoria(linhas);

    getchar();
    return 0;
}
