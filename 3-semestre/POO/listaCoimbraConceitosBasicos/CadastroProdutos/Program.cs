class Produto
{
  public string Nome { get; set; }
  public double Preco { get; set; }

  public Produto(string nome, double preco)
  {
    Nome = nome;
    Preco = preco;
  }
}

class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Sistema de Cadastro de Produtos");

    List<Produto> listaProdutos = new List<Produto>();

    while (true)
    {
      Console.WriteLine("\nOpções:");
      Console.WriteLine("1. Cadastrar novo produto");
      Console.WriteLine("2. Visualizar produtos cadastrados");
      Console.WriteLine("3. Sair");
      Console.Write("Escolha uma opção: ");
      string opcao = Console.ReadLine();

      switch (opcao)
      {
        case "1":
          CadastrarProduto(listaProdutos);
          break;
        case "2":
          VisualizarProdutos(listaProdutos);
          break;
        case "3":
          Console.WriteLine("Saindo...");
          return;
        default:
          Console.WriteLine("Opção inválida. Tente novamente.");
          break;
      }
    }
  }

  static void CadastrarProduto(List<Produto> listaProdutos)
  {
    Console.WriteLine("\nCadastro de Produto");

    Console.Write("Nome do produto: ");
    string nome = Console.ReadLine();

    Console.Write("Preço do produto: ");
    double preco = double.Parse(Console.ReadLine());

    Produto novoProduto = new Produto(nome, preco);
    listaProdutos.Add(novoProduto);

    Console.WriteLine("Produto cadastrado com sucesso!");
  }

  static void VisualizarProdutos(List<Produto> listaProdutos)
  {
    Console.WriteLine("\nProdutos Cadastrados");

    if (listaProdutos.Count == 0)
    {
      Console.WriteLine("Nenhum produto cadastrado.");
    }
    else
    {
      foreach (var produto in listaProdutos)
      {
        Console.WriteLine($"Nome: {produto.Nome}, Preço: R${produto.Preco:F2}");
      }
    }
  }
}
