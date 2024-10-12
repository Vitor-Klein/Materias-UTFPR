using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeracaProjetoBiblioteca.Modelos
{
    public class Item(string id, string titulo, DateTime dataDePublicacao)
    {
        public string Id { get; set; } = id;
        public string Titulo { get; set; } = titulo;
        public DateTime DataDePublicacao { get; set; } = dataDePublicacao;
        public virtual void AdicionarItem()
        {
            Console.WriteLine("Adicionando item");
        }
    }

}
