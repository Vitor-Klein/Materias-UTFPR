using System;

class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Remoção de Cidades com a Letra 'S'");

    Console.Write("Digite o número de cidades que deseja inserir: ");
    int quantidadeCidades = int.Parse(Console.ReadLine());

    string[] cidades = new string[quantidadeCidades];


    for (int i = 0; i < quantidadeCidades; i++)
    {
      Console.Write($"Digite o nome da cidade {i + 1}: ");
      cidades[i] = Console.ReadLine();
    }


    string[] cidadesSemS = RemoverCidadesComS(cidades);

    Console.WriteLine("\nCidades sem a letra 'S':");
    ImprimirMatriz(cidadesSemS);

    Console.ReadLine();
  }

  static void ImprimirMatriz(string[] matriz)
  {
    foreach (string item in matriz)
    {
      Console.WriteLine(item);
    }
  }

  static string[] RemoverCidadesComS(string[] cidades)
  {
    int count = 0;
    foreach (string cidade in cidades)
    {
      if (!cidade.StartsWith("S", StringComparison.OrdinalIgnoreCase))
      {
        count++;
      }
    }

    string[] cidadesSemS = new string[count];
    int index = 0;
    foreach (string cidade in cidades)
    {
      if (!cidade.StartsWith("S", StringComparison.OrdinalIgnoreCase))
      {
        cidadesSemS[index++] = cidade;
      }
    }

    return cidadesSemS;
  }
}
