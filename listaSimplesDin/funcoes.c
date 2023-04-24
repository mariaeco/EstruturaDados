//FUNCOES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

typedef struct _lista{
    int info;
}Lista;

typedef struct _controle{
    int c; //minha variavel de controle
    int tamanho;
}Ctr;



//Funcao para criar meu controle
Ctr *criaControle(int n){
    Ctr *ctr;
    ctr->c = -1;
    ctr->tamanho = n;
    printf("Tamanho atual da lista: %d",ctr->c+1);
    printf("\n\nLista criada com sucesso!\n\n");

    return ctr;
}

//Funcao de criacao de lista
Ctr *criaLista(Lista *lista, int n){
    Ctr *ctr;
    ctr =  criaControle(n);

    lista = (Lista*)malloc(n*sizeof(Lista));

    system("pause");
    return ctr;

}


//Insere elemento no final da lista
void insereFinal(Lista *lista, int valor){
    Ctr *ctr;
    int arraySize = sizeof(lista->info);
    int intSize = sizeof(lista[0].info);
    int length = arraySize/intSize;// tamanho do meu vetor info

    if (ctr->c == length-1){// se minha lista esta cheia
        printf("size: %i\n",length);
        printf("Lista cheia\n");
    }else{// caso nao esteja cheia, quero que insira na ultima posicao vazia
        lista[ctr->c+1].info = valor;
        ctr->c = ctr->c+1;
    }
}


void imprimeLista(Lista *L){ //Lista *L
    Ctr *ctr;
    if (ctr->c ==-1){
        printf("Lista Vazia!\n");
    }else{
        printf("Lista->");
        for(int i=0; i <= ctr->c ; i++){
            printf("%d",L[i].info);
            printf("->");
        }
        printf("NULL\n");
    }
    system("pause");
}


void removeFim(Lista *lista){
        Ctr *ctr;
    ctr->c = ctr->c-1;
    printf("Elemento no final da lista removido com sucesso!\n");
    system("pause");
}

void limparLista(Lista *lista){//Remove todos os nós da Lista
    Ctr *ctr;
    if(ctr->c==-1){
        printf("Lista esta vazia!\n");
    }else{
        ctr->c = - 1;
        printf("Lista limpa!\n");
    }
    system("pause");
}





/*
//Inserir no inicio da lista
void insereInicio(Lista *L, int valor){

    if(L->c == -1){ // se a lista esta vazia, inserir o valor na casa 0
        L->info[0] = valor;
        L->c = L->c + 1;
    }else if(L->c < 9) {
        // Ainda se a c > 9 ou seja, a lista não esteja cheia
        // percorrer toda a lista de trás para frente
        for(int i = L->c; i>=0; i--){
            L->info[i+1] = L->info[i];
            // puxar todos os valores para a direita
            // Se preenchi até a casa 3, então eu peço que
            // a casa 4 receba o valor da casa 3;
            // faço isso até a casa 0, nesse ponto
            // a casa 0 e a terão o mesmo valor
        }// em seguida coloco  meu novo calor na casa 0
        L->info[0] = valor;
        L->c = L->c + 1;
    }
}
*/