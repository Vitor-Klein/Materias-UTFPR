using System;

class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Contagem Regressiva");

    Console.Write("Digite um número para iniciar a contagem regressiva: ");
    int numero = int.Parse(Console.ReadLine());

    Console.WriteLine("Iniciando contagem regressiva...");

    for (int i = numero; i >= 0; i--)
    {
      Console.WriteLine(i);
    }

    Console.WriteLine("Contagem regressiva concluída!");

    Console.ReadLine();
  }
}
