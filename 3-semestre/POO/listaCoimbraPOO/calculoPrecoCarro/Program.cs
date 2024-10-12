using System;

public class Carro
{
    public string Nome { get; set; }
    public string Modelo { get; set; }
    public int Ano { get; set; }
    public double Preco { get; set; }

    public double CalcularDesconto()
    {
        if (Ano < 2010)
        {
            return Preco * 0.10;
        }

        else
            return Preco * 0.05;
    }
}

public class Program
{
    static void Main(string[] args)
    {
        Carro carro = new Carro();

        Console.WriteLine("Informe o nome do carro: ");
        carro.Nome = Console.ReadLine();
        Console.WriteLine("Informe o modelo do carro: ");
        carro.Modelo = Console.ReadLine();
        Console.WriteLine("Informe o ano do carro: ");
        carro.Ano = int.Parse(Console.ReadLine());
        Console.WriteLine("Informe o preço do carro: ");
        carro.Preco = double.Parse(Console.ReadLine());

        double precoComDesconto = carro.Preco - carro.CalcularDesconto();
        Console.WriteLine($"O valor do carro com desconto é R${precoComDesconto}");
    }
}