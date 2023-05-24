#include <stdio.h>

int main()
{
  int m, divisores, i, fatorial, soma;

  printf("Digite um numero inteiro e positivo (digite um negativo para encerrar): ");
  scanf("%d", &m);

  while (m >= 0)
  {

    if (m % 2 == 0)
    {
      divisores = 0;
      i = 1;
      while (i <= m)
      {
        if (m % i == 0)
        {
          divisores++;
        }
        i++;
      }
      printf("O numero %d tem %d divisores.\n", m, divisores);
    }
    else
    {
      if (m < 10)
      {
        fatorial = 1;
        i = 2;
        while (i <= m)
        {
          fatorial *= i;
          i++;
        }
        printf("O fatorial de %d e %d.\n", m, fatorial);
      }
      else
      {
        soma = 0;
        i = 1;
        while (i <= m)
        {
          soma += i;
          i++;
        }
        printf("A soma dos inteiros de 1 ate %d e %d.\n", m, soma);
      }
    }

    printf("Digite outro numero inteiro e positivo (digite um negativo para encerrar): ");
    scanf("%d", &m);
  }

  return 0;
}
