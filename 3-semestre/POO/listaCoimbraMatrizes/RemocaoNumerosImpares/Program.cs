using System;

class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Remoção de Números Ímpares em uma Matriz");

    Console.Write("Digite o número de linhas da matriz: ");
    int linhas = int.Parse(Console.ReadLine());

    Console.Write("Digite o número de colunas da matriz: ");
    int colunas = int.Parse(Console.ReadLine());

    int[,] matriz = new int[linhas, colunas];


    for (int i = 0; i < linhas; i++)
    {
      for (int j = 0; j < colunas; j++)
      {
        Console.Write($"Digite o valor para a posição [{i}, {j}]: ");
        matriz[i, j] = int.Parse(Console.ReadLine());
      }
    }


    int[,] matrizSemImpares = RemoverNumerosImpares(matriz);

    Console.WriteLine("\nMatriz sem números ímpares:");
    ImprimirMatriz(matrizSemImpares);

    Console.ReadLine();
  }

  static void ImprimirMatriz(int[,] matriz)
  {
    int linhas = matriz.GetLength(0);
    int colunas = matriz.GetLength(1);

    for (int i = 0; i < linhas; i++)
    {
      for (int j = 0; j < colunas; j++)
      {
        Console.Write(matriz[i, j] + "\t");
      }
      Console.WriteLine();
    }
  }

  static int[,] RemoverNumerosImpares(int[,] matriz)
  {
    int linhas = matriz.GetLength(0);
    int colunas = matriz.GetLength(1);


    int countImpares = 0;
    for (int i = 0; i < linhas; i++)
    {
      for (int j = 0; j < colunas; j++)
      {
        if (matriz[i, j] % 2 != 0)
        {
          countImpares++;
        }
      }
    }


    int[,] novaMatriz = new int[linhas, colunas - countImpares];
    int colunaNovaMatriz = 0;
    for (int i = 0; i < linhas; i++)
    {
      for (int j = 0; j < colunas; j++)
      {
        if (matriz[i, j] % 2 == 0)
        {
          novaMatriz[i, colunaNovaMatriz++] = matriz[i, j];
        }
      }
      colunaNovaMatriz = 0;
    }

    return novaMatriz;
  }
}
