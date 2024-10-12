using System;

class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Cálculo de Média Escolar");

    Console.Write("Quantas disciplinas você tem? ");
    int quantidadeDisciplinas = int.Parse(Console.ReadLine());

    double somaNotas = 0;

    for (int i = 1; i <= quantidadeDisciplinas; i++)
    {
      Console.Write($"Digite a nota da disciplina {i}: ");
      double nota = double.Parse(Console.ReadLine());
      somaNotas += nota;
    }

    double media = somaNotas / quantidadeDisciplinas;

    Console.WriteLine($"A média escolar é: {media}");

    Console.ReadLine();
  }
}

