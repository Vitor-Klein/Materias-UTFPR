using System;

public class Calculadora
{
    public static double Adicao(double num1, double num2)
    {
        return num1 + num2;
    }

    public static double Subtracao(double num1, double num2)
    {
        return num1 - num2;
    }

    public static double Multiplicacao(double num1, double num2)
    {
        return num1 * num2;
    }

    public static double Divisao(double num1, double num2)
    {
        return num1 / num2;
    }
}

public class Program
{
    static void Main(string[] args)
    {
        Calculadora calculo = new Calculadora();
        double num1, num2;
        Console.WriteLine("Digite dois números: ");
        num1 = double.Parse(Console.ReadLine());
        num2 = double.Parse(Console.ReadLine());

        double resultadoAdicao = Calculadora.Adicao(num1, num2);
        double resultadoSubtracao = Calculadora.Subtracao(num1, num2);
        double resultadoMultiplicacao = Calculadora.Multiplicacao(num1, num2);
        double resultadoDivisao = Calculadora.Divisao(num1, num2);

        Console.WriteLine($"Resultado da adição: {resultadoAdicao}");
        Console.WriteLine($"Resultado da subtração: {resultadoSubtracao}");
        Console.WriteLine($"Resultado da multiplicação: {resultadoMultiplicacao}");
        Console.WriteLine($"Resultado da divisão: {resultadoDivisao}");

    }
}