using System;
using System.Collections.Generic;

class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Leitura de Números");
    Console.WriteLine("------------------");

    List<int> numerosPositivos = new List<int>();

    while (true)
    {
      Console.Write("Digite um número (ou um número negativo para sair): ");
      int numero = int.Parse(Console.ReadLine());

      if (numero < 0)
        break;

      numerosPositivos.Add(numero);
    }

    if (numerosPositivos.Count > 0)
    {
      Console.WriteLine("Números positivos digitados:");
      foreach (int num in numerosPositivos)
      {
        Console.WriteLine(num);
      }
    }
    else
    {
      Console.WriteLine("Nenhum número positivo foi digitado.");
    }

    Console.ReadLine(); // Espera o usuário pressionar Enter para sair
  }
}

