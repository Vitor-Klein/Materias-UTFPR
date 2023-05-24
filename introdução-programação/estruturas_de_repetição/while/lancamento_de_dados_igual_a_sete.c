#include <stdio.h>

int main()
{
  int dado1 = 1, dado2;
  while (dado1 <= 6)
  {
    dado2 = 1;
    while (dado2 <= 6)
    {
      if (dado1 + dado2 == 7)
      {
        printf("\ndado1 = %d dado2 = %d", dado1, dado2);
      }
      dado2++;
    }
    dado1++;
  }

  return 0;
}
