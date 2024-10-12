using System;

class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Ordenação Alfabética de Frutas");

    Console.Write("Digite o número de frutas que deseja inserir: ");
    int quantidadeFrutas = int.Parse(Console.ReadLine());

    string[] frutas = new string[quantidadeFrutas];


    for (int i = 0; i < quantidadeFrutas; i++)
    {
      Console.Write($"Digite o nome da fruta {i + 1}: ");
      frutas[i] = Console.ReadLine();
    }


    Array.Sort(frutas);

    Console.WriteLine("\nFrutas em ordem alfabética:");
    ImprimirMatriz(frutas);

    Console.ReadLine();
  }

  static void ImprimirMatriz(string[] frutas)
  {
    Console.WriteLine("Nomes das frutas:");
    foreach (string fruta in frutas)
    {
      Console.WriteLine(fruta);
    }
  }
}
