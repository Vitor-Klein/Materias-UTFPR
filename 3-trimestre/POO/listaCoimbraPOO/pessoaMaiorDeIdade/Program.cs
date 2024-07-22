using System;

public class Pessoa
{
    public string NomePessoa { get; set; }
    public int IdadePessoa { get; set; }

    public bool EhMaiorDeIdade()
    {
        return Idade > 18;
    }
}

public class Program
{
    static void Main(string[] args)
    {
        Pessoa pessoa = new Pessoa();

        Console.WriteLine("Digite seu nome: ");
        pessoa.NomePessoa = Console.ReadLine();
        Console.WriteLine("Digite sua idade: ");
        pessoa.IdadePessoa = int.Parse(Console.ReadLine());

        if (pessoa.EhMaiorDeIdade())
        {
            Console.WriteLine($"{pessoa.NomePessoa} é maior de idade");
        }

        else
        {
            Console.WriteLine($"{pessoa.NomePessoa} não é maior de idade");
        }
    }
}