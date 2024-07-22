namespace Models;

public class Voo
{
  public string NumeroVoo { get; set; }
  public string Origem { get; set; }
  public string Destino { get; set; }
  public DateTime DataPartida { get; set; }
  public DateTime DataChegada { get; set; }
  public int AssentosDisponiveis { get; set; }

  public Voo(string numeroVoo, string origem, string destino, DateTime dataPartida, DateTime dataChegada, int assentosDisponiveis)
  {
    NumeroVoo = numeroVoo;
    Origem = origem;
    Destino = destino;
    DataPartida = dataPartida;
    DataChegada = dataChegada;
    AssentosDisponiveis = assentosDisponiveis;
  }

  // Métodos para verificar a disponibilidade de assentos e reservar assentos
  public bool VerificarDisponibilidadeAssentos(DateTime data)
  {
    // Lógica para verificar se há assentos disponíveis para a data fornecida
    return AssentosDisponiveis > 0;
  }

  public void ReservarAssento()
  {
    // Lógica para reservar um assento no voo
    AssentosDisponiveis--;
  }
}
