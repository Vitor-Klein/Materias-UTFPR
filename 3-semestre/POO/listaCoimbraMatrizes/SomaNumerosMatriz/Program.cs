using System;

class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Soma de Números em uma Matriz");

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


    int soma = CalcularSomaMatriz(matriz);

    Console.WriteLine($"\nA soma de todos os números na matriz é: {soma}");

    Console.ReadLine();
  }

  static int CalcularSomaMatriz(int[,] matriz)
  {
    int linhas = matriz.GetLength(0);
    int colunas = matriz.GetLength(1);
    int soma = 0;

    for (int i = 0; i < linhas; i++)
    {
      for (int j = 0; j < colunas; j++)
      {
        soma += matriz[i, j];
      }
    }

    return soma;
  }
}
