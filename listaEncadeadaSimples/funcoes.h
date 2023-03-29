#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct no{
    int info;
    struct no* proximo; // na propria estrutura eu aponto para alguem do mesmo tipo dela
} Lista;

/*
typedef struct no Lista; posso usar assim caso eu não faça com typedef
*/

void criaLista(Lista **ll);
int listaVazia(Lista *ll);
int insereInicio(Lista **ll, int valor);
void mostra(Lista *ll);
void limparLista(Lista **ll);

/*
void insereFinal(Lista *L, int valor);
void removeFim(Lista *L);
void imprimeLista(Lista *L);
void limparLista(Lista *L);
*/


#endif // FUNCOES_H