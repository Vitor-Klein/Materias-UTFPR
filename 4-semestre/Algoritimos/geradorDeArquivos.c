#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  FILE *ordenado, *invertido, *randomico;
  int tam, x;
  char nomeArquivo[255];

  printf("Informe o tamanho do arquivo: ");
  scanf("%d", &tam);

  // Gerando o arquivo ordenado
  sprintf(nomeArquivo, "Ordenado%05d.txt", tam);
  ordenado = fopen(nomeArquivo, "w");
  for (x = 1; x <= tam; x++)
  {
    fprintf(ordenado, "%d\n", x);
  }
  fclose(ordenado);

  // Gerando o arquivo invertido
  sprintf(nomeArquivo, "Invertido%05d.txt", tam);
  invertido = fopen(nomeArquivo, "w");
  for (x = tam; x >= 1; x--)
  {
    fprintf(invertido, "%d\n", x);
  }
  fclose(invertido);

  // Inicializando o gerador de números aleatórios com a semente baseada no tempo
  srand(time(NULL));

  // Gerando o arquivo randomico
  sprintf(nomeArquivo, "Randomico%05d.txt", tam);
  randomico = fopen(nomeArquivo, "w");
  for (x = 0; x < tam; x++)
  {
    fprintf(randomico, "%d\n", rand() % tam + 1); // Números aleatórios entre 1 e tam
  }
  fclose(randomico);

  return 0;
}
