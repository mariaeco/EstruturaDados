//FUNCOES
/* 
    PILHA
    FORMATO 2 - 
    Crio uma outra estrutura - tenho agora a estrutura do no e a estrutura da pilha
    ver no arquivo h.
    Na propria estrutura eu aponto para alguem do mesmo tipo dela

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes02.h"


Pessoa get_data(){
    Pessoa p;

    printf("\n--- INSIRA OS DADOS PARA CADASTRO ----\n");
    printf ("Digite o nome completo: ");
    scanf(" %[^\n]%*c", p.nome);//scanf(" %[^\n]%*c",p->nome);//outra forma
    printf ("Digite a idade: ");
    scanf("%i",&p.idade);
    printf ("Digite a data de nascimento dd/mm/aaaa: ");
    scanf("%d/%d/%d",&p.data.dia,&p.data.mes,&p.data.ano);

    printf("\n\tInformacoes de Cadastro:\n");
    printf("Nome:%s\n", p.nome);
    printf("Idade:%d\n", p.idade);
    printf("Data de Nascimento:%d/%d/%d\n\n", p.data.dia, p.data.mes,p.data.ano);
   
    system("pause");
    return p;
}

void imprimirDado(Pessoa p){
    printf("\n\tInformacoes de Cadastro:\n");
    printf("Nome:%s\n", p.nome);
    printf("Idade:%d\n", p.idade);
    printf("Data de Nascimento:%d/%d/%d\n\n", p.data.dia, p.data.mes,p.data.ano);
}

//Funcao de criacao de Pilha
void criaPilha(Pilha *pilha){ //
  
    pilha->topo = NULL; // ou 0
    pilha->tam = 0 ;
    printf("Pilha criada!\n");
    system("pause");
    return ;
}

int pilhaVazia(Pilha *topo){
    return (topo==NULL);
}

//FUNCAO PARA EMPILHAR (push)
void empilhar(Pilha *pilha) { // agora posso ir direto pelo void
    No* novo = (No*)malloc(sizeof(No));
    
    if (novo == NULL) {       
        printf("Erro ao alocar memória.\n");
        exit(1);
    }else{
        novo->info = get_data();
        novo->proximo = pilha->topo;
        pilha->topo = novo;
        pilha->tam++;
    }
}

//FUNCAO PARA DESEMPILHAR (pop)
No* desempilhar(Pilha *pilha){// aqui removemos um nó
    if(pilha->topo){
        No *remover = pilha->topo;
        pilha->topo = remover->proximo;
        pilha->tam--;
        free(remover);
        printf("\nElemento removido com sucesso\n");
        return remover;
    }else{
        printf("Pilha Vazia!\n");
        return NULL;
    }
    system("pause");
}

void limparLista(Pilha *pilha){
    No *remover; // cria uma copia para nao perder o endereço
    while(pilha->topo){
        remover = pilha->topo;
        pilha->topo = remover->proximo;
        pilha->tam--;
        printf("TAM: %d\n", pilha->tam);
        free(remover);
    }
    if(pilha->topo == NULL) {
        printf("\nPilha deletada com sucesso\n");
        //return NULL;
    }
    system("pause");
}

void mostra(Pilha *pilha){
    No *aux; 
    aux = pilha->topo;
    printf("\n------------- PILHA Tam: %d ------------------", pilha->tam);
    while(aux){
        imprimirDado(aux->info);
        aux = aux->proximo;
    }
    printf("\n------------  FIM DA PILHA -------------------\n");
    system("pause");
}

