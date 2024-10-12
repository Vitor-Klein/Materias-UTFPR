using System;

class Program
{
  static void Main(string[] args)
  {
    ConversorDeMoedas conversor = new ConversorDeMoedas();

    // Convertendo Real para Dólar
    double valorRealParaDolar = 100;
    double valorConvertidoRealParaDolar = conversor.RealParaDolar(valorRealParaDolar);
    Console.WriteLine($"R${valorRealParaDolar} equivale a ${valorConvertidoRealParaDolar:F2}");

    // Convertendo Dólar para Real
    double valorDolarParaReal = 50;
    double valorConvertidoDolarParaReal = conversor.DolarParaReal(valorDolarParaReal);
    Console.WriteLine($"${valorDolarParaReal} equivale a R${valorConvertidoDolarParaReal:F2}");

    // Convertendo Real para Euro
    double valorRealParaEuro = 150;
    double valorConvertidoRealParaEuro = conversor.RealParaEuro(valorRealParaEuro);
    Console.WriteLine($"R${valorRealParaEuro} equivale a €{valorConvertidoRealParaEuro:F2}");

    // Convertendo Euro para Real
    double valorEuroParaReal = 80;
    double valorConvertidoEuroParaReal = conversor.EuroParaReal(valorEuroParaReal);
    Console.WriteLine($"€{valorEuroParaReal} equivale a R${valorConvertidoEuroParaReal:F2}");

    Console.ReadLine(); // Espera o usuário pressionar Enter para sair
  }
}

public class ConversorDeMoedas
{
  private double taxaDolar = 5.50;
  private double taxaEuro = 6.20;

  public double RealParaDolar(double valorEmReal)
  {
    return valorEmReal / taxaDolar;
  }

  public double DolarParaReal(double valorEmDolar)
  {
    return valorEmDolar * taxaDolar;
  }

  public double RealParaEuro(double valorEmReal)
  {
    return valorEmReal / taxaEuro;
  }

  public double EuroParaReal(double valorEmEuro)
  {
    return valorEmEuro * taxaEuro;
  }
}
