#include <stdio.h>

int main()
{
  int i = 1;
  float S = 0;

  while (i <= 10)
  {
    if (i % 2 == 0)
    {
      S -= (float)i / (i * i);
    }
    else
    {
      S += (float)i / (i * i);
    }
    i++;
  }

  printf("O valor de S e %.2f\n", S);

  return 0;
}
