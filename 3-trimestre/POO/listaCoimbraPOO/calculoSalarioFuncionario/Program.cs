using System;

public class Funcionario
{
    public string Nome { get; set; }
    public double Salario { get; set; }
    public double HorasTrabalhadas { get; set; }
    public double CalcularSalarioTotal()
    {
        return Salario * HorasTrabalhadas;
    }
}

public class Program
{
    static void Main(string[] args)
    {
        Funcionario funcionario = new Funcionario();

        Console.WriteLine("Informe seu nome: ");
        funcionario.Nome = Console.ReadLine();
        Console.WriteLine("Informe o salário por 1 hora trabalhada: ");
        funcionario.Salario = double.Parse(Console.ReadLine());
        Console.WriteLine("Informe as horas trabalhadas: ");
        funcionario.HorasTrabalhadas = double.Parse(Console.ReadLine());

        Console.WriteLine($"O seu salário final é R${funcionario.CalcularSalarioTotal()}");
    }
}