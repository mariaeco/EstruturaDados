#include <stdio.h>
#include <string.h>//necessário para strcmp
int main (void)
{
  char str1[] = "abcd";
  char str2[] = "abcd";
  char str3[] = "aeio";
  int retorno;
  
  retorno = strcmp(str1, str2);
  printf("retorno = %d\n", retorno);
  //mostra o retorno da função strcmp  
  

  retorno = strcmp(str1, str3);
  printf("retorno = %d\n", retorno);


  return 0;
}