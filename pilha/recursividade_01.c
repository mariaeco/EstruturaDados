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


void criaPilha(No **pilha){ //
  
    *pilha = NULL; // ou 0
    printf("Pilha criada!\n");
    system("pause");
    return ;
}

int pilhaVazia(No *topo){
    return (topo==NULL);
}

No* empilhar(No *pilha, int num){
    No* novo = (No*)malloc(sizeof(No));
    
    if (novo) {       
        novo->valor = num;
        novo->proximo = pilha;
    }else{
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    return novo;
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
    No *aux;
    aux = pilha;
    if(!aux){ 
        printf("Pilha Vazia!\n");
        system("pause");
        return ;
    }
    while(aux){
        printf("\t%d\n", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
    system("pause");
}

void mostraR(No *pilha){// DE FRENTE PARA TRAS// SEMELHANTE A IMPRIMIR
    No *aux;
    aux = pilha;

    if(!aux){ 
        printf("NULL!\n");
        return ;
    }else{
        printf("%d ->", aux->valor);
        mostraR(aux->proximo);
    }
    system("pause");
}

void mostraR2(No *pilha){// DE TRAS PARA FRENTE
    No *aux;
    aux = pilha;

    printf("\nInicio\n");

    if(!aux){ 
        printf("NULL\n");
        return ;
    }else{
        mostraR2(aux->proximo);
        printf("%d ", aux->valor);
    }

    system("pause");
}


No* limparR(No *pilha){// DE FRENTE PARA TRAS/

    if(pilha == NULL){
        return NULL;
    }

    No *aux;
    aux = pilha;
    pilha = limparR(pilha->proximo);
    free(aux);  
    
    if(pilha == NULL){
        printf("Pilha Vazia!\n");
    }

    return pilha;
    system("pause");
    
}

void limparR2(No** pilha) {
    limparR(*pilha);
    *pilha = NULL;
}


int main(){
    int valor;
  
    int choice = 0;
    int num;
    No *topo, *remover; 

    // MEU MENU -------------------------------------------------
    do{
        printf ("MEU MENU\n");
        printf("1 - Cria Pilha\n");
        printf("2 - Inserir Elemento\n");
        printf("3 - Remover Elemento\n");
        printf("4 - Imprimir lista\n");
        printf("5 - Imprimir lista Recursiva Frente-Tras\n");
        printf("6 - Imprimir lista Recursiva Tras-Frente\n");
        printf("7 - Limpar Recursiva Tras-Frente\n");
        printf("8 - Limpar Recursiva Frente-Tras\n");
        printf("0 - Sair\n");

           
        scanf("%d", &choice);
        system("cls||clear");

        switch(choice){
            case 1: //CriaPilha
                criaPilha(&topo);
                system("cls");
                break;
            case 2: //Push
                printf ("Digite um valor: ");
                scanf("%d", &valor);
                topo = empilhar(topo, valor);
                system("cls");
                break;
            case 3: //Pop
                remover = desempilhar(&topo);
                system("cls");
                break;
            case 4: //mostraLista
                imprimir(topo);
                system("cls");
                break;
            case 5: //Mostra Recursiva
                mostraR(topo);
                system("cls");
                break;
            case 6: //Mostra Recursiva inversa
                mostraR2(topo);
                system("cls");
                break;
            case 7: //Imprimir recursiva
                topo = limparR(topo);
                system("cls");
                break;
            case 8: //Imprimir recursiva
                limparR2(&topo);
                system("cls");
                break;
            default:
                if(choice==0){
                    exit(0);
                }
                printf("Digite uma opcao valida!\n");
                break;
            }
    }while(choice!= 0);

    return 0;
}