/*
PROGRAMA: LISTA ENCADEADA
AUTOR: MARIA MARCOLINA CARDOSO
Objetivos: 
    Menu Inicial:
    - Cria Lista
    - Limpa Lista
    - Insere no Inicio da Lista
    - Insere no Fim da Lista
    - Remove do Inicio da Lista
    - Remove do Fim da Lista
    - Mostra Lista
    - Ver se esta vazia a Lista
    - Ver se esta cheia a Lista
    - Consulta Valor na Lista
    - Altera Elemento da Lista

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"




int main(int argc, char const *argv[]){

    int choice = 0;
    int num;
    Lista *lista;



    // MEU MENU -------------------------------------------------
    do{
        printf ("MEU MENU\n");
        printf("1 - Cria Lista\n");
        printf("2 - Insere no inicio da Lista\n");
        printf("3 - Mostrar Lista\n");
        printf("4 - Limpar Lista\n");
        printf("0 - Sair\n");

           
        scanf("%d", &choice);
        system("cls||clear");

        switch(choice){
            case 1: //CriarLista
                criaLista(&lista);
                system("cls");
                break;
            case 2: //addInicio
                printf("Insira um numero: \n");
                scanf("%d", &num);
                insereInicio(&lista,num);
                system("cls");
                break;
            case 3: //mostraLista
                mostra(lista);
                system("cls");
                break;
            case 4: //esvaziarLista
                limparLista(&lista);
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
