#include <stdio.h>

int main()
{
  int num_maior = 0, num_menor = 0, num = 1;

  while (num > 0)
  {
    printf("Informe um numero positivo para continuar e um negativo para encerrar: ");
    scanf("%d", &num);
    if (num < 0)
    {
      break;
    }
    if (num_maior == 0 && num_menor == 0)
    {
      num_maior = num;
      num_menor = num;
    }

    if (num > num_maior)
    {
      num_maior = num;
    }
    if (num < num_menor)
    {
      num_menor = num;
    }
  }

  printf("maior numero informado: %d\n", num_maior);
  printf("menor numero informado: %d\n", num_menor);

  return 0;
}
