#include <stdio.h>

int main()
{
  int altura_ana = 150, altura_feliz = 110, anos = 1;

  while (altura_feliz < altura_ana)
  {
    altura_ana += 2;
    altura_feliz += 3;
    anos++;
  }

  printf("Para Feliz ser maior levara %d anos", anos);
  return 0;
}
