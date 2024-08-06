using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeracaProjetoBiblioteca.Modelos
{
    public class DVD : Item
    {
        public string Diretor { get; set; }
        public int Duracao { get; set; }

        public DVD(string diretor, int duracao, string id, string titulo, DateTime dataDePublicacao)
            : base(id, titulo, dataDePublicacao)
        {
            Diretor = diretor;
            Duracao = duracao;
        }

        public override void AdicionarItem()
        {
            Console.WriteLine($"DVD {Titulo} do diretor {Diretor} adicionado com sucesso!");
        }

    }
}
