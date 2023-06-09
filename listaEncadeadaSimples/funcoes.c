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

    OBSERVACAO: observe que sempre nas funcoes utilizo **ll
    Como na main, minha lista eh definida como Lista *lista, sempre entrara na funcao um endereco de memoria,
    *lista eh um endereco de memora. Se Na fucao estiver *ll entao eu estou pegando o valor de *lista e fazendo uma copia.
    Agora se eu faco **ll eu pego o endereco de listam e altero a lista, nao faco uma copia, altero a propria lista.
    As funcoes em que altero devem sempre ter como entrada **ll

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

Lista* criarNo(int valor) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->info = valor;
    novo->proximo = NULL;
    return novo;
}

int listaVazia(Lista *ll){
    return (ll==NULL);
}

int insereInicio(Lista **ll, int valor){
    Lista *nova = criarNo(valor);

    if (*ll == NULL) {
        *ll = nova;
    } else {
        nova->proximo = *ll;
        *ll = nova;
    }
    system("pause");
    return 1;
}

int insereOrdenado(Lista** ll, int valor){
    Lista* novo = criarNo(valor);

    // Caso a lista esteja vazia ou o valor seja menor que o valor do primeiro nó
    if (*ll == NULL || valor < (*ll)->info) {
        novo->proximo = *ll;
        *ll = novo;
    } else {
        Lista* atual = *ll;
        while (atual->proximo != NULL && atual->proximo->info < valor) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
     return 1;
}

int insereFim(Lista **ll, int valor){
    Lista *novo, *aux;
    novo = criarNo(valor);

    if(*ll == NULL){ // se ll eh NULL, nao tem valor, vamos criar o primeiro no
        *ll = novo;
    }else{// nao eh o primeiro no
        aux = *ll;
        while(aux->proximo !=NULL){//enquanto existir um proximo ponto
            aux = aux->proximo; // caminha ate o final
        }
        aux->proximo = novo;// chegou ao final, cria um próximo no.
    }
    system("pause");
    return 1;
}

// Função para trocar os valores de dois nós
void trocar(Lista *a, Lista* b) {
    int aux;
    aux = a->info;
    a->info = b->info;
    b->info = aux;
}

//Ordenar Lista
void Ordenar(Lista **ll){
    int troca;
    Lista *no_atual;
    Lista *no_anterior = NULL;

    // Verifica se a lista está vazia ou possui apenas um elemento
    if (*ll == NULL || (*ll)->proximo == NULL) {
        return;
    }
   
    do {
        troca = 0;
        no_atual = *ll;

        // Percorre a lista encadeada comparando elementos adjacentes e trocando-os se estiverem fora de ordem
        while (no_atual->proximo != no_anterior) {
            if (no_atual->info > no_atual->proximo->info) {
                trocar(no_atual, no_atual->proximo);
                troca = 1;
            }
            no_atual = no_atual->proximo;
        }
        no_anterior = no_atual;

    } while (troca);

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


void limparLista(Lista **ll){
    Lista *aux; // cria uma copia para nao perder o endereço
    while(*ll){
        aux = *ll;
        *ll = (*ll)->proximo;
        free(aux);

    }
    system("pause");

}

void removerInicio(Lista** ll) {
    if (*ll == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Lista* aux = *ll;
    *ll = (*ll)->proximo;
    free(aux);
}


// Função para remover o último elemento da lista
void removerFim(Lista** ll) {
    if (*ll == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    if ((*ll)->proximo == NULL) {
        // Caso a lista tenha apenas um nó
        free(*ll);
        *ll = NULL;
    } else {
        Lista* anterior = NULL;
        Lista* atual = *ll;
        while (atual->proximo != NULL) {
            anterior = atual;
            atual = atual->proximo;
        }
        anterior->proximo = NULL;
        free(atual);
    }
}

// Função para remover um elemento específico da lista
void removerElemento(Lista** ll, int valor) {
    if (*ll == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Lista* atual = *ll;
    Lista* anterior = NULL;

    // Percorrer a lista até encontrar o elemento
    while (atual != NULL && atual->info != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Elemento não encontrado na lista.\n");
        return;
    }

    // Remover o nó contendo o elemento
    if (anterior == NULL) {
        *ll = (*ll)->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    free(atual);
}

