#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./RubroNegra/ArvoreRubroNegra.h"

// Função de comparação usada na árvore (assumindo que os dados são inteiros)
int compararInt(void *a, void *b)
{
  int *x = (int *)a;
  int *y = (int *)b;
  return (*x) - (*y);
}

int main()
{
  int quantidade = 100000;
  int *numeros = malloc(quantidade * sizeof(int));
  if (numeros == NULL)
  {
    printf("Erro ao alocar memória!\n");
    return 1;
  }

  // Abre o arquivo contendo os números
  FILE *arquivo = fopen("Numeros Aleatorios BENCHMARK.txt", "r");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo!\n");
    free(numeros);
    return 1;
  }

  // Lê os números do arquivo
  for (int i = 0; i < quantidade; i++)
  {
    if (fscanf(arquivo, "%d", &numeros[i]) != 1)
    {
      printf("Erro ao ler o arquivo!\n");
      fclose(arquivo);
      free(numeros);
      return 1;
    }
  }
  fclose(arquivo);

  // Inicializa a árvore rubro-negra
  pDArvore arvore_rubro_negra = criarArvoreRubroNegra(sizeof(int));

  // Benchmark da inserção
  clock_t inicio = clock();
  for (int i = 0; i < quantidade; i++)
  {
    incluirInfo(arvore_rubro_negra, &numeros[i], compararInt);
  }
  clock_t fim = clock();
  double tempo_execucao_insercao = (double)(fim - inicio) / CLOCKS_PER_SEC;
  printf("Tempo de execucao (Insercao Rubro-Negra): %.6f segundos\n", tempo_execucao_insercao);

  // Benchmark da busca
  inicio = clock();
  for (int i = 0; i < quantidade; i++)
  {
    buscarInfo(arvore_rubro_negra, &numeros[i], compararInt);
  }
  fim = clock();
  double tempo_execucao_busca = (double)(fim - inicio) / CLOCKS_PER_SEC;
  printf("Tempo de execucao (Busca Rubro-Negra): %.6f segundos\n", tempo_execucao_busca);

  // Benchmark da exclusão
  inicio = clock();
  for (int i = 0; i < quantidade; i++)
  {
    excluirInfo(arvore_rubro_negra, &numeros[i], compararInt);
  }
  fim = clock();
  double tempo_execucao_exclusao = (double)(fim - inicio) / CLOCKS_PER_SEC;
  printf("Tempo de execucao (Exclusao Rubro-Negra): %.6f segundos\n", tempo_execucao_exclusao);

  // Libera a memória
  free(numeros);
  // (Assumindo que a função para liberar a árvore rubro-negra já está implementada)
  // liberarArvore(arvore_rubro_negra);

  return 0;
}
