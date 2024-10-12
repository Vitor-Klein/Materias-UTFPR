#include <stdio.h>
#include <stdlib.h>

int main()
{
  int valor1 = 500;
  int valor2 = 450;
  int flag = 2;
  int cont = 0;
  float soma;

  while (cont <= 10)
  {
    switch (flag)
    {
    case 2:
      soma += (float)flag / valor1;
      valor1 = valor1 - 100;
      flag = -5;
    case -5:
      soma += (float)flag / valor2;
      valor2 = valor2 - 100;
      flag = -5;
      break;
    }
    cont++;
  }

  printf("\n lor final: %f", soma);

  return 0;
}