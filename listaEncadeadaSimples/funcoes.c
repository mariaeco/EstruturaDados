//FUNCOES
/* 
    A LISTA ENCADEADA SIMPLES
    Cresce a medida que insiro elementos, com alocação dinamica
    A memoria eh o limite de armazanemaneto, continuo tendo limite, mas a memoria eh o limite
    Na lista simples ela eh unidirecional
    _____________________        _____________________   _____________________
    |__dados___|__prox__|----->  |__dados___|__prox__|-->|__dados___|__prox__|

    prox = ponteiro para o proximo
    O marco inicial Da lita eh uma variavel estatico - vamos chama-la de L;
    Nunca perder a marcação inicial 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"



//Funcao de criacao de lista
void criaLista(Lista **ll){ // l que vai apontar para a Lista
  
    *ll = NULL; // ou 0
    printf("Lista criada!\n");

    system("pause");
    return ;

}

int listaVazia(Lista *ll){
    return (ll==NULL);
}

int insereInicio(Lista **ll, int valor){

    Lista *nova;

    nova = (Lista *)malloc(sizeof(struct no));

    if(!nova){
        return 0;
    }

    nova->info = valor;
    nova->proximo = *ll;
    *ll = nova; 

    system("pause");
    return 1;

}

void mostra(Lista *ll){

    Lista *aux; 
    aux = ll;
    if(listaVazia(ll)){
        printf("Lista Vazia!\n");
    }
    else{
        for(aux == ll; aux != NULL; aux=aux->proximo){
            printf("%d",aux->info);
            printf("->");
            //printf("%d\n",(*ll).info);// eh a mesma coisa
        }
        printf("NULL\n");
    }
    system("pause");
}


void limparLista(Lista **ll){//Remove todos os nós da Lista
    Lista *atual; // variavel auxiliar para guardar a referencia atual
    Lista *next;// variavel auxiliar para guardar a referencia do próximo ponteiro
    atual = *ll; // atual recebe minha lista
    // nesse formato nao perco meu endereco inicial

    
    printf("ll 1 = %d\n",&ll);
    printf("atual = %d\n", *atual); // observe aqui que ele recebe o ultimo valor entrado
    
    if(listaVazia(*ll)){
        
        printf("Lista Vazia!\n");
    }
    else{
        while(atual != NULL){
            next = atual->proximo;
            free(atual);
            atual = next;
        }

    }
    *ll = NULL;
   
    printf("Lista Esvaziada com sucesso!\n");

    //printf("ll 2 = %d\n",ll);
    //printf("atual = %d\n", atual);// veja aqui que zerei atual
    
    system("pause");
}
