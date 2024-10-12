#include <stdio.h>

int main()
{
  float soma = 0;
  int denominador = 500;
  int sinal = 1;

  for (int i = 1; i <= 10; i++)
  {
    if (sinal == 1)
    {
      soma += 2.0 / denominador;
    }
    else
    {
      soma -= 5.0 / denominador;
    }

    sinal *= -1;
    denominador -= 50;
  }

  printf("A soma dos dez primeiros termos da serie eh: %.2f", soma);

  return 0;
}
