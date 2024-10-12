using Models;

namespace Models
{
  class Program
  {
    static void Main(string[] args)
    {
      CompanhiaAerea companhia = new CompanhiaAerea("Vitor Airlines");
      Voo voo1 = new Voo("1234", "Missal", "Foz", DateTime.Now, DateTime.Now.AddHours(2), 100);
      Voo voo2 = new Voo("5678", "Foz", "Missal", DateTime.Now.AddHours(3), DateTime.Now.AddHours(5), 50);
      Voo voo3 = new Voo("3333", "Medianeira", "Sao Paulo", DateTime.Now.AddHours(3), DateTime.Now.AddHours(5), 50);
      Voo voo4 = new Voo("45345", "Sao Paulo", "Medianeira", DateTime.Now.AddHours(3), DateTime.Now.AddHours(5), 50);
      Voo voo5 = new Voo("67878", "Minas Gerais", "Missal", DateTime.Now.AddHours(3), DateTime.Now.AddHours(5), 50);
      Voo voo6 = new Voo("34234", "Missal", "Minas Gerais", DateTime.Now.AddHours(3), DateTime.Now.AddHours(5), 50);
      Passageiro passageiro = new Passageiro("Vitor", "23423434");

      companhia.AdicionarVoo(voo1);
      companhia.AdicionarVoo(voo2);
      companhia.AdicionarVoo(voo3);
      companhia.AdicionarVoo(voo4);
      companhia.AdicionarVoo(voo5);
      companhia.AdicionarVoo(voo6);

      Console.WriteLine("Selecione o voo para reservar:");
      Console.WriteLine("1. Voo de Missal para Foz");
      Console.WriteLine("2. Voo de Foz para Missal");
      int opcaoVoo = int.Parse(Console.ReadLine());

      Voo vooSelecionado = opcaoVoo == 1 ? voo1 : voo2;

      Console.WriteLine("Digite a data de partida (dd/mm/aaaa):");
      DateTime dataPartida;
      while (!DateTime.TryParse(Console.ReadLine(), out dataPartida))
      {
        Console.WriteLine("Data inválida. Digite novamente:");
      }

      Console.WriteLine("Digite a data de chegada (dd/mm/aaaa):");
      DateTime dataChegada;
      while (!DateTime.TryParse(Console.ReadLine(), out dataChegada))
      {
        Console.WriteLine("Data inválida. Digite novamente:");
      }

      try
      {
        Reserva novaReserva = new Reserva(passageiro, vooSelecionado, dataPartida, dataChegada);
        Console.WriteLine("\nReserva criada com sucesso:");
        Console.WriteLine($"Nome do passageiro: {novaReserva.Passageiro.Nome}");
        Console.WriteLine($"Número do voo: {novaReserva.Voo.NumeroVoo}");
        Console.WriteLine($"Origem: {novaReserva.Voo.Origem}, Destino: {novaReserva.Voo.Destino}");
        Console.WriteLine($"Data de partida: {novaReserva.DataPartida.ToShortDateString()}, Data de chegada: {novaReserva.DataChegada.ToShortDateString()}");
      }
      catch (InvalidOperationException ex)
      {
        Console.WriteLine($"Erro ao criar reserva: {ex.Message}");
      }
    }
  }
}
