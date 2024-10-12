namespace Models;

public class CompanhiaAerea
{
  public string Nome { get; set; }
  public List<Voo> VoosDisponiveis { get; set; }
  public List<Reserva> Reservas { get; set; }

  public CompanhiaAerea(string nome)
  {
    Nome = nome;
    VoosDisponiveis = new List<Voo>();
    Reservas = new List<Reserva>();
  }

  // Métodos para adicionar novos voos à programação da companhia aérea e obter voos disponíveis para reserva
  public void AdicionarVoo(Voo voo)
  {
    VoosDisponiveis.Add(voo);
  }

  public List<Voo> ObterVoosDisponiveis(DateTime data)
  {
    // Lógica para retornar uma lista de voos disponíveis para a data fornecida
    return VoosDisponiveis.FindAll(voo => voo.VerificarDisponibilidadeAssentos(data));
  }
}