#include <stdio.h>

int main()
{
  int num;
  char primo = 'S';
  printf("informe um numero: ");
  scanf("%d", &num);
  if (num <= 1)
  {
    printf("numero não é primo");
  }
  else
  {
    for (int i = 2; i <= num / 2; i++)
    {
      if (num % i == 0)
      {
        primo = 'N';
      }
    }

    if (primo == 'S')
    {
      printf("numero %d eh primo", num);
    }
    else
    {
      printf("numero %d nao eh primo", num);
    }
  }
  return 0;
}