#include <stdio.h>

int main()
{
  int num, fat = 1;

  do
  {
    printf("Digite um número par: ");
    scanf("%d", &num);

    if (num % 2 == 0)
    {
      for (int i = num; i >= 2; i -= 2)
      {
        fat *= i;
      }

      printf("%d!! = %d", num, fat);
    }
    else
    {
      printf("%d não é um número par.\n", num);
    }

  } while (num % 2 != 0);

  return 0;
}
