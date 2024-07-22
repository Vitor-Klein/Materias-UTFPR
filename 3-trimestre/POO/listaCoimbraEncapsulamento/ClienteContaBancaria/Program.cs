using Models;

namespace Models
{
  class Program
  {
    static void Main(string[] args)
    {
      Client cliente = new Client("Vitor", "vitorklein@gmail.com", "Centro Missal PR", 45988288888);
      ContaBancaria contaBancaria = new ContaBancaria(123456, 1000.00m, cliente);

      Console.WriteLine("Selecione a operação:");
      Console.WriteLine("1. Depositar");
      Console.WriteLine("2. Sacar");
      Console.WriteLine("3. Transferir");
      int opcao = int.Parse(Console.ReadLine());

      switch (opcao)
      {
        case 1:
          Console.WriteLine("Digite o valor para depositar:");
          decimal valorDeposito = decimal.Parse(Console.ReadLine());
          contaBancaria.Depositar(valorDeposito);
          break;
        case 2:
          Console.WriteLine("Digite o valor para sacar:");
          decimal valorSaque = decimal.Parse(Console.ReadLine());
          contaBancaria.Sacar(valorSaque);
          break;
        case 3:
          Console.WriteLine("Digite o valor para transferir:");
          decimal valorTransferencia = decimal.Parse(Console.ReadLine());
          Console.WriteLine("Digite o número da conta para transferir:");
          int numeroContaDestino = int.Parse(Console.ReadLine());
          ContaBancaria contaDestino = new ContaBancaria(numeroContaDestino, 0.00m, new Client("Destinatario", "destinatario@gmail.com", "Endereco Destinatario", 123456789));
          contaBancaria.Transferir(valorTransferencia, contaDestino);
          break;
        default:
          Console.WriteLine("Opção inválida.");
          break;
      }

      Console.WriteLine("\nDetalhes da conta bancária:");
      Console.WriteLine($"Número da conta: {contaBancaria.NumeroConta}");
      Console.WriteLine($"Saldo: {contaBancaria.SaldoConta:C}");
      Console.WriteLine($"Titular da conta: {contaBancaria.TitularConta.Nome}");
    }
  }
}
