using System;

public class Pessoa
{
    public string Nome { get; set; }
    public int Idade { get; set; }
    public double Altura { get; set; }

    public void ImprimirDados()
    {
        Console.WriteLine("Nome: " + Nome);
        Console.WriteLine("Idade: " + Idade);
        Console.WriteLine("Altura: " + Altura.ToString("0.00") + " metros");
    }
}

public class Program
{
    static void Main(string[] args)
    {
        Pessoa pessoa = new Pessoa();

        pessoa.Nome = "Vitor";
        pessoa.Idade = 22;
        pessoa.Altura = 1.81;
        pessoa.ImprimirDados();
    }
}