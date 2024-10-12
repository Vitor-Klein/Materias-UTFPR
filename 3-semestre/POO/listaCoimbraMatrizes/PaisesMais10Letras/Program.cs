using System;

class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Contagem de Países com Mais de 10 Letras");

    Console.Write("Digite o número de países que deseja inserir: ");
    int quantidadePaises = int.Parse(Console.ReadLine());

    string[] paises = new string[quantidadePaises];


    for (int i = 0; i < quantidadePaises; i++)
    {
      Console.Write($"Digite o nome do país {i + 1}: ");
      paises[i] = Console.ReadLine();
    }


    int quantidadePaisesMaisDe10Letras = ContarPaisesMaisDe10Letras(paises);

    Console.WriteLine($"\nTotal de países com mais de 10 letras em seu nome: {quantidadePaisesMaisDe10Letras}");

    Console.ReadLine();
  }

  static int ContarPaisesMaisDe10Letras(string[] paises)
  {
    int quantidadePaisesMaisDe10Letras = 0;

    foreach (string pais in paises)
    {
      if (pais.Length > 10)
      {
        quantidadePaisesMaisDe10Letras++;
      }
    }

    return quantidadePaisesMaisDe10Letras;
  }
}
