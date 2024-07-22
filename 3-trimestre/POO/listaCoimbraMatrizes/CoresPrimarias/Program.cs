using System;

class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Contagem de Cores Primárias");

    Console.Write("Digite o número de cores que deseja inserir: ");
    int quantidadeCores = int.Parse(Console.ReadLine());

    string[] cores = new string[quantidadeCores];


    for (int i = 0; i < quantidadeCores; i++)
    {
      Console.Write($"Digite o nome da cor {i + 1}: ");
      cores[i] = Console.ReadLine();
    }


    int quantidadeCoresPrimarias = ContarCoresPrimarias(cores);

    Console.WriteLine($"\nTotal de cores primárias na matriz: {quantidadeCoresPrimarias}");

    Console.ReadLine();
  }

  static int ContarCoresPrimarias(string[] cores)
  {
    int quantidadeCoresPrimarias = 0;

    foreach (string cor in cores)
    {
      string corLower = cor.ToLower();
      if (corLower == "vermelho" || corLower == "azul" || corLower == "amarelo")
      {
        quantidadeCoresPrimarias++;
      }
    }

    return quantidadeCoresPrimarias;
  }
}
