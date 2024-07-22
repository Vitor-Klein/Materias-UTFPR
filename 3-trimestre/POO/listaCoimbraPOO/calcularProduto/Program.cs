using System;

public class Produto
{
    public string Nome { get; set; }
    public double Preco { get; set; }
    public int Quantidade { get; set; }

    public double CalcularTotal()
    {
        return (Preco * Quantidade);
    }
}

public class Program
{
    static void Main(string[] args)
    {
        Produto produto = new Produto();

        string nomeProduto;
        double precoProduto;
        int quantidadeProduto;

        Console.WriteLine("Informe o nome do produto: ");
        nomeProduto = Console.ReadLine();
        Console.WriteLine("Informe o preço do produto: ");
        precoProduto = double.Parse(Console.ReadLine());
        Console.WriteLine("Informe quantas unidades do produto: ");
        quantidadeProduto = int.Parse(Console.ReadLine());

        produto.Preco = precoProduto;
        produto.Quantidade = quantidadeProduto;
        double total = produto.CalcularTotal();

        Console.WriteLine($"O valor total a se pagar por {produto.Nome} é R${total}");

    }
}
