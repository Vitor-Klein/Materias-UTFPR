using System;

class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Primeira e Última Fruta na Matriz");

    Console.Write("Digite o número de frutas que deseja inserir: ");
    int quantidadeFrutas = int.Parse(Console.ReadLine());

    string[] frutas = new string[quantidadeFrutas];


    for (int i = 0; i < quantidadeFrutas; i++)
    {
      Console.Write($"Digite o nome da fruta {i + 1}: ");
      frutas[i] = Console.ReadLine();
    }


    string primeiraFruta = frutas[0];
    string ultimaFruta = frutas[frutas.Length - 1];

    Console.WriteLine($"\nA primeira fruta na matriz é: {primeiraFruta}");
    Console.WriteLine($"A última fruta na matriz é: {ultimaFruta}");

    Console.ReadLine();
  }
}
