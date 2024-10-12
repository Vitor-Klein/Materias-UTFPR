#include <stdio.h>

int main()
{
  int n_quadrados = 64;
  long long int n_graos = 1;
  int i = 1;
  long long int total_graos = n_graos;

  while (i < n_quadrados)
  {
    n_graos *= 2;
    total_graos += n_graos;
    i++;
  }

  printf("O numero total de graos em um tabuleiro de xadrez e: %lld\n", total_graos);
  return 0;
}
