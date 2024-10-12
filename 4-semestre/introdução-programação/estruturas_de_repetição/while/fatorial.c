#include <stdio.h>

int main()
{
  int num = 0;
  int fat = 1;

  printf("Escrva um numero para calcular seu fatorial");
  scanf("%d", &num);

  if (num < 0)
  {
    printf("Numeros negativos nao possuem fatorial");
  }

  int cont = 1;
  while (cont <= num)
  {
    fat *= cont;
    cont++;
  }
  printf("%d ", fat);

  return 0;
}
