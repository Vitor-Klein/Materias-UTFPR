using System;

public class Aluno
{
    public string NomeAluno { get; set; }
    public double[] NotasAluno { get; set; }

    public double CalcularMedia()
    {
        double soma = 0;
        foreach (double nota in NotasAluno)
        {
            soma = soma + nota;
        }
        return soma / NotasAluno.Length;
    }
}

public class Program
{
    static void Main(string[] args)
    {
        Aluno aluno = new Aluno();

        int materias;
        Console.WriteLine("Informe seu nome: ");
        aluno.NomeAluno = Console.ReadLine();
        Console.WriteLine("Informe quantas matérias você tem: ");
        materias = int.Parse(Console.ReadLine());
        aluno.NotasAluno = new double[materias];


        for (int i = 0; i < materias; i++)
        {
            Console.WriteLine($"Informe a nota da matéria {i + 1}: ");
            aluno.NotasAluno[i] = double.Parse(Console.ReadLine());
        }

        double media = aluno.CalcularMedia();
        Console.WriteLine($"A média do aluno {aluno.NomeAluno} é: {media}");
    }
}