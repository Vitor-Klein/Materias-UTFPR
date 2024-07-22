namespace Models;

public class Reserva
{
  public Passageiro Passageiro { get; set; }
  public Voo Voo { get; set; }
  public DateTime DataPartida { get; set; }
  public DateTime DataChegada { get; set; }

  public Reserva(Passageiro passageiro, Voo voo, DateTime dataPartida, DateTime dataChegada)
  {
    Passageiro = passageiro;
    Voo = voo;
    DataPartida = dataPartida;
    DataChegada = dataChegada;
  }

  // Método para validar as datas de partida e chegada
  public static void ValidarDatas(DateTime partida, DateTime chegada)
  {
    if (partida > chegada || partida < DateTime.Today || chegada < DateTime.Today)
    {
      throw new InvalidOperationException("Datas de partida e chegada inválidas.");
    }
  }
}