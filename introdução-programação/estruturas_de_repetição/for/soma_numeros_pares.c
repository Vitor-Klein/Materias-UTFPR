#include <stdio.h>

int main()
{
  int num = 0, soma = 0, cont = 0;

  printf("informe um numero para começar");
  scanf("%d", &num);
  for (int i = 1; i <= 10; i++)
  {
    if (num % 2 == 0)
    {
      soma += num;
      cont++;
    }
    printf("informe outro numero para continuar");
    scanf("%d", &num);
  }

  if (cont == 0)
  {
    printf("voce nao digitou nenhum numero par para fazer a media");
  }
  else
  {
    printf("A media dos numeros pares da serie eh: %d", soma / cont);
  }

  return 0;
}
