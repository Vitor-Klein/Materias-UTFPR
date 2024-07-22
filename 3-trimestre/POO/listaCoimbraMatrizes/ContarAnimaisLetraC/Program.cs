using System;

class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Contagem de Animais com a Letra 'C' em uma Matriz");

    Console.Write("Digite o número de animais que deseja inserir: ");
    int quantidadeAnimais = int.Parse(Console.ReadLine());

    string[] animais = new string[quantidadeAnimais];

    for (int i = 0; i < quantidadeAnimais; i++)
    {
      Console.Write($"Digite o nome do animal {i + 1}: ");
      animais[i] = Console.ReadLine();
    }

    Console.WriteLine("\nMatriz completa:");
    ImprimirMatriz(animais);

    int quantidadeAnimaisComC = ContarAnimaisComC(animais);
    Console.WriteLine($"\nTotal de animais com a letra 'C': {quantidadeAnimaisComC}");

    Console.ReadLine();
  }

  static void ImprimirMatriz(string[] animais)
  {
    Console.WriteLine("Nomes dos animais:");
    foreach (string animal in animais)
    {
      Console.WriteLine(animal);
    }
  }

  static int ContarAnimaisComC(string[] animais)
  {
    int quantidadeAnimaisComC = 0;

    foreach (string animal in animais)
    {
      if (animal.StartsWith("C", StringComparison.OrdinalIgnoreCase))
      {
        quantidadeAnimaisComC++;
      }
    }

    return quantidadeAnimaisComC;
  }
}
