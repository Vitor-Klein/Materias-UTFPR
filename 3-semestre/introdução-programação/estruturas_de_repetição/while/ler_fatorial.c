#include <stdio.h>

int main()
{
  int n, i, num;
  long long fatorial;

  printf("Digite a quantidade de numeros a serem lidos: ");
  scanf("%d", &n);

  i = 1;
  while (i <= n)
  {
    printf("\nDigite o valor de numero %d: ", i);
    scanf("%d", &num);

    fatorial = 1;
    while (num > 0)
    {
      fatorial *= num;
      num--;
    }

    printf("O fatorial de %d eh: %lld\n", num + 1, fatorial);

    i++;
  }

  return 0;
}
