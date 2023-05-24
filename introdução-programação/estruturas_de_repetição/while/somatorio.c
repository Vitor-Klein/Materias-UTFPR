#include <stdio.h>
#include <stdlib.h>

int main()
{
  int cont = 1, num, soma = 0;
  printf("Informe um numero: ");
  scanf("%d", &num);
  while (cont <= num)
  {
    soma += cont++;
  }
  printf("somatorio do numero = %d", soma);
  return 0;
}