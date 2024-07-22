namespace Models;
public class Passageiro
{
  public string Nome { get; set; }
  public string NumeroDocumento { get; set; }
  public string DetalhesContato { get; set; }

  public Passageiro(string nome, string numeroDocumento)
  {
    Nome = nome;
    NumeroDocumento = numeroDocumento;
  }

  // Métodos para atualizar informações do passageiro
  public void AtualizarDetalhesContato(string novoContato)
  {
    DetalhesContato = novoContato;
  }

  public void AtualizarNumeroDocumento(string novoDocumento)
  {
    NumeroDocumento = novoDocumento;
  }
}