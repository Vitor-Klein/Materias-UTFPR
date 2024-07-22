using System;

public class Retangulo
{
    public double BaseRetangulo { get; set; }
    public double AlturaRetangulo { get; set; }

    public double CalcularPerimetro()
    {
        return (BaseRetangulo * 2) + (AlturaRetangulo * 2);
    }
}

public class Program
{
    static void Main(string[] args)
    {
        Retangulo retangulo = new Retangulo();
        Console.WriteLine("Digite a base do retângulo: ");
        retangulo.BaseRetangulo = double.Parse(Console.ReadLine());
        Console.WriteLine("Digite a altura do retângulo: ");
        retangulo.AlturaRetangulo = double.Parse(Console.ReadLine());

        Console.WriteLine($"O perímetro do retângulo é: {retangulo.CalcularPerimetro()}");

    }
}
