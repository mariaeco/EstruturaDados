/*
RECURSIVIDADE COM PILHA
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int valor;
    struct no* proximo; // na propria estrutura eu aponto para alguem do mesmo tipo dela
}No;


No* empilhar(No *pilha, int num){
    No* novo = (No*)malloc(sizeof(No));
    
    if (novo) {       
        novo->valor =num;
        novo->proximo = pilha;
        return novo;
    }else{
         printf("Erro ao alocar memória.\n");
         return NULL;
    }
}

No* desempilhar(No **pilha){// aqui removemos um nó
    No *remover = NULL;
    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
        free(remover);
        return remover;
    }else{
        printf("Pilha Vazia!\n");
        return NULL;
    }
    system("pause");
}

void imprimir(No *pilha){
    printf("\n\tPILHA\n");
    while(pilha){
        printf("\t%d\n", pilha->valor);
        pilha = pilha->proximo;
    }
    printf("\n");
}

int fatorial(int num){
    No* remover, *pilha = NULL;
    
    while(num>1){
        pilha = empilhar(pilha, num);
        num--;
    }

    imprimir(pilha);
    while(pilha){
        remover = desempilhar(&pilha);
        num = num*remover->valor;
        free(remover);    
    };
    return num;
}

int main(){
    int valor;

    printf ("Digite um valor maior que zero: ");
    scanf("%d", &valor);
    printf ("\n\tFatorial de %d: %d\n", valor, fatorial(valor));

    return 0;
}