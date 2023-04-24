#include <stdio.h>
#include <stdlib.h>

int main() {
   int **tabuada;
   int linhas, colunas;
   int i, j;
   int n1; 
   int n2;

   // solicitar ao usuário o tamanho da matriz
   printf("Digite o numero de linhas da matriz: ");
   scanf("%d", &linhas);

   printf("Digite o numero de colunas da matriz: ");
   scanf("%d", &colunas);

   // alocar memória para a matriz
   tabuada = (int **) malloc(linhas * sizeof(int *));
   for(i=0; i<linhas; i++) {
      tabuada[i] = (int *) malloc(colunas * sizeof(int));
   }

   // preencher a matriz com a tabuada
   for(i=0; i<linhas; i++) {
      for(j=0; j<colunas; j++) {
         tabuada[i][j] = (i+1) * (j+1);
      }
   }

   // imprimir a matriz
   for(i=0; i<linhas; i++) {
      for(j=0; j<colunas; j++) {
         printf("%d\t", tabuada[i][j]);
      }
      printf("\n");
   }

   printf("\nDigite 2 numeros entre 1 e 9 para retornarmos resultado de sua multiplicacao:\n");
   scanf("%d", &n1);
   scanf("%d", &n2);

    
    printf("\nO resultado da multiplicacao entre %d e %d eh: %d\n", n1, n2,tabuada[n1-1][n2-1]);

   // liberar memória alocada para a matriz
   for(i=0; i<linhas; i++) {
      free(tabuada[i]);
   }
   free(tabuada);

   return 0;
}