#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

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

// Função auxiliar para troca
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// QuickSort
int partition(int *array, int low, int high)
{
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++)
  {
    if (array[j] < pivot)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int *array, int low, int high)
{
  if (low < high)
  {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

// MergeSort
void merge(int *array, int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  int *L = (int *)malloc(n1 * sizeof(int));
  int *R = (int *)malloc(n2 * sizeof(int));

  for (int i = 0; i < n1; i++)
    L[i] = array[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = array[m + 1 + j];

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      array[k] = L[i];
      i++;
    }
    else
    {
      array[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    array[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    array[k] = R[j];
    j++;
    k++;
  }

  free(L);
  free(R);
}

void mergeSort(int *array, int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    mergeSort(array, l, m);
    mergeSort(array, m + 1, r);
    merge(array, l, m, r);
  }
}

// HeapSort
void heapify(int *array, int n, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && array[left] > array[largest])
    largest = left;

  if (right < n && array[right] > array[largest])
    largest = right;

  if (largest != i)
  {
    swap(&array[i], &array[largest]);
    heapify(array, n, largest);
  }
}

void heapSort(int *array, int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(array, n, i);

  for (int i = n - 1; i > 0; i--)
  {
    swap(&array[0], &array[i]);
    heapify(array, i, 0);
  }
}

// RadixSort
int getMax(int *array, int n)
{
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void countSort(int *array, int n, int exp)
{
  int *output = (int *)malloc(n * sizeof(int));
  int count[10] = {0};

  for (int i = 0; i < n; i++)
    count[(array[i] / exp) % 10]++;

  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (int i = n - 1; i >= 0; i--)
  {
    output[count[(array[i] / exp) % 10] - 1] = array[i];
    count[(array[i] / exp) % 10]--;
  }

  for (int i = 0; i < n; i++)
    array[i] = output[i];

  free(output);
}

void radixSort(int *array, int n)
{
  int max = getMax(array, n);
  for (int exp = 1; max / exp > 0; exp *= 10)
    countSort(array, n, exp);
  printf("Array ordenado com Radix Sort.\n");
}

void exibirMenu()
{
  printf("\n--- Menu Principal ---\n");
  printf("1. Ler arquivo\n");
  printf("2. Ordenar com Bubble Sort\n");
  printf("3. Ordenar com Insertion Sort\n");
  printf("4. Ordenar com Selection Sort\n");
  printf("5. Ordenar com Shell Sort\n");
  printf("6. Ordenar com Quick Sort\n");
  printf("7. Ordenar com Merge Sort\n");
  printf("8. Ordenar com Heap Sort\n");
  printf("9. Ordenar com Radix Sort\n");
  printf("10. Imprimir array\n");
  printf("11. Sair\n");
  printf("Escolha uma opção: ");
}

int main()
{
  int opcao, tam = 0;
  int *array = (int *)malloc(MAX_SIZE * sizeof(int));
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
        printf("Tempo de execução: %f segundos.\n", (double)(clock() - start) / CLOCKS_PER_SEC);
      }
      else
        printf("Nenhum array carregado.\n");
      break;

    case 3:
      if (tam > 0)
      {
        clock_t start = clock();
        insertionSort(array, tam);
        printf("Tempo de execução: %f segundos.\n", (double)(clock() - start) / CLOCKS_PER_SEC);
      }
      else
        printf("Nenhum array carregado.\n");
      break;

    case 4:
      if (tam > 0)
      {
        clock_t start = clock();
        selectionSort(array, tam);
        printf("Tempo de execução: %f segundos.\n", (double)(clock() - start) / CLOCKS_PER_SEC);
      }
      else
        printf("Nenhum array carregado.\n");
      break;

    case 5:
      if (tam > 0)
      {
        clock_t start = clock();
        shellSort(array, tam);
        printf("Tempo de execução: %f segundos.\n", (double)(clock() - start) / CLOCKS_PER_SEC);
      }
      else
        printf("Nenhum array carregado.\n");
      break;

    case 6:
      if (tam > 0)
      {
        clock_t start = clock();
        quickSort(array, 0, tam - 1);
        printf("Tempo de execução: %f segundos.\n", (double)(clock() - start) / CLOCKS_PER_SEC);
      }
      else
        printf("Nenhum array carregado.\n");
      break;

    case 7:
      if (tam > 0)
      {
        clock_t start = clock();
        mergeSort(array, 0, tam - 1);
        printf("Tempo de execução: %f segundos.\n", (double)(clock() - start) / CLOCKS_PER_SEC);
      }
      else
        printf("Nenhum array carregado.\n");
      break;

    case 8:
      if (tam > 0)
      {
        clock_t start = clock();
        heapSort(array, tam);
        printf("Tempo de execução: %f segundos.\n", (double)(clock() - start) / CLOCKS_PER_SEC);
      }
      else
        printf("Nenhum array carregado.\n");
      break;

    case 9:
      if (tam > 0)
      {
        clock_t start = clock();
        radixSort(array, tam);
        printf("Tempo de execução: %f segundos.\n", (double)(clock() - start) / CLOCKS_PER_SEC);
      }
      else
        printf("Nenhum array carregado.\n");
      break;

    case 10:
      if (tam > 0)
      {
        imprimirArray(array, tam);
      }
      else
        printf("Nenhum array carregado.\n");
      break;

    case 11:
      printf("Saindo do programa.\n");
      break;

    default:
      printf("Opção inválida.\n");
      break;
    }
  } while (opcao != 11);

  free(array);
  return 0;
}
