#include <stdio.h>



int main(){
    int a;
    int b;
    int *p;
    int **k;

    printf("O endereco de &b eh: %d\n", &b);
    printf("O endereco de &p eh: %d\n", &p);
    printf("O endereco de &k eh: %d\n", &k);
    printf("O valor de b eh lixo, pois noa atribui nada a ele: %d\n", b);
    printf("O endereco apontado por p eh (lixo, pois na apontei nada ainda): %d\n", p);
    printf("O endereco apontado por k eh (lixo, pois na apontei nada ainda): %d\n", k);
    printf("\n\n");

    p = &b;
    k = &p;

    printf("O endereco de &b eh: %d\n", &b);
    printf("O endereco de &p eh: %d\n", &p);
    printf("O endereco de &k eh: %d\n", &k);
    printf("O valor de b eh: %d\n", b);
    printf("O valor apontado por *p eh: %d\n", *p);
    printf("O valor apontado por **k eh: %d\n", **k);
    printf("O valor apontado por *k!! eh: %d\n", *k);
    printf("\n\n");

    a = 3;
    b = 5;
    
    printf("Atribuindo o valor 5 a b:\n");
    printf("O valor de a eh: %d\n", a);
    printf("O valor de b eh: %d\n", b);
    printf("O endereco apontado por p eh: %d\n", p);
    printf("O endereco apontado por k eh: %d\n", k);
    printf("O valor apontado por *p eh: %d\n", *p);
    printf("O valor apontado por **k eh: %d\n\n", **k);

    //veja que o endereco apontado por p eh o endereco de b
    //e o endereco apontado por k eh o endereco de p

    printf("O valor de (*p)+1 eh: %d\n", (*p)+1);
    printf("O valor de (*k)+1 eh: %d\n", (*k)+1);
    printf("O valor de (**k)+1 eh: %d\n", (**k)+1);




    return 0;
}



