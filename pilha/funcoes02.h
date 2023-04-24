#ifndef FUNCOES02_H
#define FUNCOES02_H

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[30];
    int idade;
    Data data;
}Pessoa;

typedef struct no{
    Pessoa info;
    struct no* proximo; // na propria estrutura eu aponto para alguem do mesmo tipo dela
} No;

typedef struct{
    int tam; // tamanho da pilha
    No* topo; // na propria estrutura eu aponto para alguem do mesmo tipo dela
} Pilha;

/*
typedef struct no Lista; posso usar assim caso eu não faça com typedef
*/

Pessoa get_data();
void imprimirDado();
void criaPilha(Pilha *pilha);
void empilhar(Pilha *pilha);
No* desempilhar(Pilha *pilha);
void mostra(Pilha *pilha);
void limparLista(Pilha *pilha);

#endif // FUNCOES02_H