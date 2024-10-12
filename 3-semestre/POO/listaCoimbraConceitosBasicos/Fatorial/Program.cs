using System;

class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Cálculo do Fatorial");
    Console.WriteLine("--------------------");

    Console.Write("Digite um número para calcular o fatorial: ");
    int numero = int.Parse(Console.ReadLine());

    long fatorial = CalcularFatorial(numero);

    Console.WriteLine($"O fatorial de {numero} é: {fatorial}");

    Console.ReadLine(); // Espera o usuário pressionar Enter para sair
  }

  static long CalcularFatorial(int n)
  {
    if (n < 0)
    {
      throw new ArgumentException("O fatorial de um número negativo não está definido.");
    }
    else if (n == 0 || n == 1)
    {
      return 1;
    }
    else
    {
      long resultado = 1;
      for (int i = 2; i <= n; i++)
      {
        resultado *= i;
      }
      return resultado;
    }
  }
}
