using System;

public class Triangulo
{
    public double Base { get; set; }
    public double Altura { get; set; }

    public double CalcularArea()
    {
        return Base * Altura / 2;
    }
}

public class Program
{
    static void Main(string[] args)
    {
        Triangulo triangulo = new Triangulo();
        double baseTriangulo, alturaTriangulo;
        Console.WriteLine("Digite dois valores, respectivamente para base e altura: ");
        baseTriangulo = double.Parse(Console.ReadLine());
        alturaTriangulo = double.Parse(Console.ReadLine());

        triangulo.Base = baseTriangulo;
        triangulo.Altura = alturaTriangulo;

        double areaTriangulo = triangulo.CalcularArea();
        Console.WriteLine($"Área do triângulo: {areaTriangulo}");

    }
}
