#include <stdio.h>

int main()
{
  int i, som = 0, num;
  printf("digite um numero para calcular seu somatorio");
  scanf("%d", &num);
  for (i = 1; i <= num; i++)
  {
    som += i;
  }
  printf("valor da serie = %d", som);
  return 0;
}