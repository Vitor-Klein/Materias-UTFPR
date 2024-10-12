#include <stdio.h>

int main()
{
  int numero, inicio, fim;

  printf("Digite um numero: ");
  scanf("%d", &numero);

  printf("Digite o valor inicial: ");
  scanf("%d", &inicio);

  printf("Digite o valor final: ");
  scanf("%d", &fim);

  printf("Tabuada de %d:\n", numero);
  for (int i = inicio; i <= fim; i++)
  {
    printf("%d x %d = %d\n", numero, i, numero * i);
  }

  return 0;
}
