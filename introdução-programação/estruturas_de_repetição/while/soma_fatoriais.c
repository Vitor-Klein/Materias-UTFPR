#include <stdio.h>

int main()
{
  int num, cont, fat, sum;

  sum = 0;

  printf("Digite um numero inteiro positivo (ou um numero negativo para sair):\n");
  scanf("%d", &num);

  while (num >= 0)
  {
    cont = 1;
    fat = 1;
    while (cont <= num)
    {
      fat *= cont;
      cont++;
    }
    sum += fat;

    printf("Digite outro numero inteiro positivo (ou um numero negativo para sair):\n");
    scanf("%d", &num);
  }

  printf("A soma dos fatoriais dos numeros lidos e: %d\n", sum);

  return 0;
}
