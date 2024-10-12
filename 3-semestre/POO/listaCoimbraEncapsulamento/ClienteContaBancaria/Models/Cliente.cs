using System;

namespace Models
{
  class Client
  {
    public string Nome { get; private set; }
    public string Email { get; private set; }
    public string Endereco { get; set; }
    public double Telefone { get; private set; }

    public Client(string nome, string email, string endereco, double telefone)
    {
      try
      {
        if (string.IsNullOrWhiteSpace(email))
        {
          throw new ArgumentException("Email inválido");
        }

        Nome = nome;
        Email = email;
        Endereco = endereco;
        Telefone = telefone;
      }
      catch (ArgumentException ex)
      {
        Console.WriteLine($"Erro ao criar cliente: {ex.Message}");
      }
    }

    public void AtualizarEndereco(string novoEndereco)
    {
      try
      {
        if (string.IsNullOrWhiteSpace(novoEndereco))
        {
          throw new ArgumentException("Endereço inválido");
        }

        Endereco = novoEndereco;
        Console.WriteLine("Endereço atualizado com sucesso.");
      }
      catch (ArgumentException ex)
      {
        Console.WriteLine($"Erro ao atualizar endereço: {ex.Message}");
      }
    }

    public override string ToString()
    {
      return $"Nome: {Nome}\nEmail: {Email}\nEndereço: {Endereco}\nTelefone: {Telefone}";
    }
  }
}
