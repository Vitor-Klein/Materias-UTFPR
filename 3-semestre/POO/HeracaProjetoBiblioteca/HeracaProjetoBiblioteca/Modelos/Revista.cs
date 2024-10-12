using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeracaProjetoBiblioteca.Modelos
{
    public class Revista : Item
    {
        public string Edicao { get; set; }
        public int ISSN { get; }

        public Revista(string edicao, int issn, string id, string titulo, DateTime dataDePublicacao)
            : base(id, titulo, dataDePublicacao)
        {
            Edicao = edicao;
            ISSN = issn;
        }

        public override void AdicionarItem()
        {
            Console.WriteLine($"Revista {Titulo} da edicao {Edicao} adicionado com sucesso!");
        }

    }
}
