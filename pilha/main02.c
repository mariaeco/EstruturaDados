/*
PROGRAMA: PILHA
AUTOR: MARIA MARCOLINA CARDOSO

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes02.h"


int main(int argc, char const *argv[]){

    int choice = 0;
    int num;
    No *remover;
    Pilha pilha;



    // MEU MENU -------------------------------------------------
    do{
        printf ("MEU MENU\n");
        printf("1 - Cria Pilha\n");
        printf("2 - Inserir Elemento\n");
        printf("3 - Remover Elemento\n");
        printf("4 - Mostrar Elemento do Topo\n");
        printf("5 - Limpar Lista\n");
        printf("0 - Sair\n");

           
        scanf("%d", &choice);
        system("cls||clear");

        switch(choice){
            case 1: //CriaPilha
                criaPilha(&pilha);
                system("cls");
                break;
            case 2: //Push
                empilhar(&pilha);
                system("cls");
                break;
            case 3: //Pop
                remover = desempilhar(&pilha);
                system("cls");
                break;
            case 4: //mostraLista
                mostra(&pilha);
                system("cls");
                break;
            case 5: //Limpar lista
                limparLista(&pilha);
                system("cls");
                break;
            default:
                if(choice==0){
                limparLista(&pilha);
                exit(0);
                }
                printf("Digite uma opcao valida!\n");
                break;
            }
    }while(choice!= 0);

    
    return 0;
}
