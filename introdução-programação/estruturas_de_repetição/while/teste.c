#include <stdio.h>

int main()
{
  int cont = 85;
  int acc = 0;

  while (cont <= 907)
  {
    acc = acc + cont;
    cont++;
  }
  printf("soma igual: %d", acc);
  return 0;
}
