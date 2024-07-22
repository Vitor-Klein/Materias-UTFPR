using System;

namespace Models
{
  class ContaBancaria
  {
    public double NumeroConta { get; private set; }
    public decimal SaldoConta { get; private set; }
    public Client TitularConta { get; private set; }

    public ContaBancaria(double numeroConta, decimal saldoConta, Client titularConta)
    {
      NumeroConta = numeroConta;
      SaldoConta = saldoConta;
      TitularConta = titularConta;
    }

    public void Depositar(decimal valor)
    {
      try
      {
        if (valor <= 0)
        {
          throw new ArgumentException("O valor do depósito deve ser maior que zero.");
        }

        SaldoConta += valor;
        Console.WriteLine($"Depósito de {valor:C} realizado com sucesso.");
      }
      catch (ArgumentException ex)
      {
        Console.WriteLine($"Erro ao depositar: {ex.Message}");
      }
    }

    public void Sacar(decimal valor)
    {
      try
      {
        if (valor <= 0)
        {
          throw new ArgumentException("O valor do saque deve ser maior que zero.");
        }

        if (valor > SaldoConta)
        {
          throw new InvalidOperationException("Saldo insuficiente para realizar o saque.");
        }

        SaldoConta -= valor;
        Console.WriteLine($"Saque de {valor:C} realizado com sucesso.");
      }
      catch (ArgumentException ex)
      {
        Console.WriteLine($"Erro ao sacar: {ex.Message}");
      }
      catch (InvalidOperationException ex)
      {
        Console.WriteLine($"Erro ao sacar: {ex.Message}");
      }
    }

    public void Transferir(decimal valor, ContaBancaria contaDestino)
    {
      try
      {
        if (valor <= 0)
        {
          throw new ArgumentException("O valor da transferência deve ser maior que zero.");
        }

        if (valor > SaldoConta)
        {
          throw new InvalidOperationException("Saldo insuficiente para realizar a transferência.");
        }

        SaldoConta -= valor;
        contaDestino.Depositar(valor);
        Console.WriteLine($"Transferência de {valor:C} para a conta {contaDestino.NumeroConta} realizada com sucesso.");
      }
      catch (ArgumentException ex)
      {
        Console.WriteLine($"Erro ao transferir: {ex.Message}");
      }
      catch (InvalidOperationException ex)
      {
        Console.WriteLine($"Erro ao transferir: {ex.Message}");
      }
    }
  }
}
