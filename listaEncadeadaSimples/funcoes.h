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
int insereInicio(Lista **ll, int valor);
int insereFim(Lista **ll, int valor);
int insereOrdenado(Lista** ll, int valor);
void Ordenar(Lista **ll);
void mostra(Lista *ll);
void limparLista(Lista **ll);
void removerInicio(Lista** ll);
void removerFim(Lista** ll);
void removerElemento(Lista** ll, int valor);

#endif // FUNCOES_H