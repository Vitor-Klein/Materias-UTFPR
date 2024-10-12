#include <stdio.h>

int main()
{
  int num = 1, soma = 0, cont_par = 0;
  float media;
  while (num > 0)
  {
    printf("Informe um numero");
    scanf("%d", &num);
    if (num <= 0)
    {
      break;
    }
    if (num % 2 == 0)
    {
      soma += num;
      cont_par++;
    }
  }
  media = soma / cont_par;

  printf("media dos pares = %.2f", media);
  return 0;
}
