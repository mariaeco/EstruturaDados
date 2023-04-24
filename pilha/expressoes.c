/*
PILHA - VERIFICAR EXPRESSOES
    bem formada: [()]
    mal formada: [(]
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    char caracter;
    struct no *prox;
}No;

No* empilhar(No *pilha, char valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->caracter = valor;
        novo->prox = pilha;
        return novo;
    }
    else {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }
}

No* desempilhar(No **pilha){
    No *remover;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->prox;
       // printf("\nElemento removido com sucesso\n");
    }else{
        printf("Pilha Vazia!\n");
    }

    return remover;
    //system("pause");
}

void mostrar(No *pilha){
    //printf("\nExpressao: ");
    while(pilha){
        printf("%c",pilha->caracter);
        pilha = pilha->prox;
    }
    //printf("\n");
}

int comparar_par(char a,char f){//d = caracter de abertura; f = caracter de fechamento
    switch (f){
        case ')':
            if(a == '('){
                return 1;// bem formada
            }else{
                return 0;// mal formada
            }
            break;
        case ']':
            if(a == '['){
                return 1;
            }else{
                return 0;
            }
            break;
        case '}':
            if(a == '{'){
                return 1;
            }else{
                return 0;
            }
            break;
        default:
            break;
    }
}

int verificaSequencia(char sinal[]){
    int i = 0;
    No *pilha = NULL;
    No *remover;
    /* uso o i tambem para contar o numero de parenteses fechados e abertos
       se i for par ao final temos os pares formados (), se for impar, nao formado (
    */
    while(sinal[i] != '\0'){// enquanto nao for o final
        if (sinal[i] == '[' || sinal[i] == '(' || sinal[i] == '{'){
            pilha = empilhar(pilha, sinal[i]);
            mostrar(pilha);
        }else if(sinal[i] == ']' || sinal[i] == ')' || sinal[i] == '}'){
            remover = desempilhar(&pilha);// caracter que abriu e esta na pilha
            if(comparar_par(remover->caracter, sinal[i]) == 1){// se forma um par
                printf("------ > PAR FORMADO \n");
            }
            free(remover);
        }
        i++;
    }
 
    if(i % 2 == 0){ // se   resto da divisao por 2 for 0, entao temos um numero parc
        printf("\nExpressao bem formada \n");
        return 1;
    }else{
        printf("\nEXPRESSAO MAL FORMADA \n");
        return 0;
    }
}

int main(){
        
    char expressao[] = "{[()]}";
    verificaSequencia(expressao);

    char expressao1[] = "{{]] {)";
    verificaSequencia(expressao1);

    char expressao2[] = "{{[()()]}}";
    verificaSequencia(expressao2);

    char expressao3[] = "(){";
    verificaSequencia(expressao3);

    char exp[50];

    printf("\nDigite uma expressao: ");
    scanf("%49[^\n]", exp);
    printf("\nExpressao: %s\nRetorno: %d\n", exp, verificaSequencia(exp));

}