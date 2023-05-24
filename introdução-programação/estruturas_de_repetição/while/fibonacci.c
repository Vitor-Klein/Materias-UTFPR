#include <stdio.h>

int main()
{
  int n = 20;
  int num1 = 0, num2 = 1;
  int cont = 0;

  printf("Série de Fibonacci até o %dº termo:\n", n);

  while (cont < n)
  {
    printf("%d ", num1);
    int next = num1 + num2;
    num1 = num2;
    num2 = next;
    cont++;
  }

  return 0;
}
