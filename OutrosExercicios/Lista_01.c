/* 
LISTAS:
    - inserir elementos
    - remover elementos
    - mostrar elementos
    - ordenar elementos
    - esvaziar elementos

*/

#include  <stdio.h>

struct lista{
    int controle;
    int info[10];
};

int criaLista(struct lista*);
int esvaziar(struct lista*);
int insereInicio(struct lista*, int valor);
void mostrarLista(struct lista*);

//Funcao de criacao de lista
int criaLista(struct lista *ptr){
    ptr->controle = -1;
    printf("Lista criada com sucesso!\n");
    printf("Tamanho da lista: %d",ptr->controle);
    //system("pause");
    return ptr->controle;
}

int esvaziar(struct lista *ptr){
    if(ptr->controle==-1){
        printf("Lista esta vazia!\n");
    }else{
        ptr->controle = - 1;
        printf("Lista limpa!\n");
    }
}


//Insere elemento no final da lista
int insereFinal(struct lista *lista, int valor){

    int arraySize = sizeof(lista->info);
    int intSize = sizeof(lista->info[0]);
    int length = arraySize/intSize;

    if (lista->controle == length-1){
        printf("size: %i\n",length);
        printf("Lista cheia\n");
    }else{      
        lista->info[lista->controle+1] = valor;
        lista->controle = lista->controle + 1;
    }
}

//Inserir no inicio da lista
int insereInicio(struct lista *L, int valor){
    // se a lista não tiver cheia
    // percorrer a lista até o fim
    if(L->controle == -1){ // se estiver vazia, inserir numero na posicao 1 e passar para a proxima casa do controle
        L->info[0] = valor;
        L->controle = L->controle+1;
    }else if(L->controle < 9) { 
        for(int i = L->controle; i>=0; i--){
            L->info[i+1] = L->info[i];
        }
        L->info[0] = valor;
        L->controle = L->controle + 1;
    }
    // se nao estiver vazia: iniciar o for da atual posicao do controle  
}



int main(){

    struct lista Lista;
    criaLista(&Lista);


    return 0;
}

