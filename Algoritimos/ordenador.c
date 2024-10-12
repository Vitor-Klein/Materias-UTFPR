#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void lerArquivo(const char *nomeArquivo, int *array, int *tam)
{
  FILE *arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return;
  }

  int i = 0;
  while (fscanf(arquivo, "%d", &array[i]) != EOF && i < MAX_SIZE)
  {
    i++;
  }
  *tam = i;
  fclose(arquivo);

  printf("Arquivo %s lido com sucesso. %d elementos carregados.\n", nomeArquivo, *tam);
}

void imprimirArray(int *array, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void bubbleSort(int *array, int tam)
{
  for (int i = 0; i < tam - 1; i++)
  {
    for (int j = 0; j < tam - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        // Troca os elementos
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  printf("Array ordenado com Bubble Sort.\n");
}

void insertionSort(int *array, int tam)
{
  for (int i = 1; i < tam; i++)
  {
    int chave = array[i];
    int j = i - 1;

    while (j >= 0 && array[j] > chave)
    {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = chave;
  }
  printf("Array ordenado com Insertion Sort.\n");
}

void selectionSort(int *array, int tam)
{
  for (int i = 0; i < tam - 1; i++)
  {
    int minIndice = i;
    for (int j = i + 1; j < tam; j++)
    {
      if (array[j] < array[minIndice])
      {
        minIndice = j;
      }
    }
    int aux = array[i];
    array[i] = array[minIndice];
    array[minIndice] = aux;
  }
  printf("Array ordenado com Selection Sort.\n");
}

void shellSort(int *array, int tam)
{
  for (int gap = tam / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < tam; i++)
    {
      int temp = array[i];
      int j;
      for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
      {
        array[j] = array[j - gap];
      }
      array[j] = temp;
    }
  }
  printf("Array ordenado com Shell Sort.\n");
}

void exibirMenu()
{
  printf("\n--- Menu Principal ---\n");
  printf("1. Ler arquivo\n");
  printf("2. Ordenar com Bubble Sort\n");
  printf("3. Ordenar com Insertion Sort\n");
  printf("4. Ordenar com Selection Sort\n");
  printf("5. Ordenar com Shell Sort\n");
  printf("6. Imprimir array\n");
  printf("7. Sair\n");
  printf("Escolha uma opção: ");
}

int main()
{
  int opcao, tam = 0;
  int *array = (int *)malloc(MAX_SIZE * sizeof(int)); // Corrigindo alocação dinâmica
  char nomeArquivo[255];

  if (array == NULL)
  {
    printf("Erro ao alocar memória.\n");
    return 1;
  }

  do
  {
    exibirMenu();
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      printf("Informe o nome do arquivo: ");
      scanf("%s", nomeArquivo);
      lerArquivo(nomeArquivo, array, &tam);
      break;

    case 2:
      if (tam > 0)
      {
        clock_t start = clock();
        bubbleSort(array, tam);
        clock_t end = clock();

        double tempoExecucao = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Tempo de execução do Bubble Sort: %f segundos\n", tempoExecucao);
      }
      else
      {
        printf("Nenhum arquivo foi carregado.\n");
      }
      break;

    case 3:
      if (tam > 0)
      {
        insertionSort(array, tam);
      }
      else
      {
        printf("Nenhum arquivo foi carregado.\n");
      }
      break;

    case 4:
      if (tam > 0)
      {
        selectionSort(array, tam);
      }
      else
      {
        printf("Nenhum arquivo foi carregado.\n");
      }
      break;

    case 5:
      if (tam > 0)
      {
        shellSort(array, tam);
      }
      else
      {
        printf("Nenhum arquivo foi carregado.\n");
      }
      break;

    case 6:
      if (tam > 0)
      {
        imprimirArray(array, tam);
      }
      else
      {
        printf("Nenhum arquivo foi carregado.\n");
      }
      break;

    case 7:
      printf("Saindo...\n");
      break;

    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  } while (opcao != 7);

  free(array); // Liberando memória alocada
  return 0;
}
