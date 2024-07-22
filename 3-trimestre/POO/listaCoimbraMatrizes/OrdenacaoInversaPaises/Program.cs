using System;

class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Ordenação Alfabética Reversa de Países");

    Console.Write("Digite o número de países que deseja inserir: ");
    int quantidadePaises = int.Parse(Console.ReadLine());

    string[] paises = new string[quantidadePaises];


    for (int i = 0; i < quantidadePaises; i++)
    {
      Console.Write($"Digite o nome do país {i + 1}: ");
      paises[i] = Console.ReadLine();
    }


    Array.Sort(paises);
    Array.Reverse(paises);

    Console.WriteLine("\nPaíses em ordem alfabética reversa:");
    ImprimirMatriz(paises);

    Console.ReadLine();
  }

  static void ImprimirMatriz(string[] paises)
  {
    Console.WriteLine("Nomes dos países:");
    foreach (string pais in paises)
    {
      Console.WriteLine(pais);
    }
  }
}
