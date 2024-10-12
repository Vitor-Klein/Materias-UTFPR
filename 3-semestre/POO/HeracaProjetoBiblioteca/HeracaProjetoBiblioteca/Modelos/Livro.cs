using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeracaProjetoBiblioteca.Modelos
{
    public class Livro : Item
    {
        public string Autor { get; set; }
        public int ISBN { get; }
        public int Paginas { get; set; }

        public Livro(string autor, int isbn, int paginas, string id, string titulo, DateTime dataDePublicacao) 
            : base(id,titulo,dataDePublicacao ) {
            Autor = autor;
            ISBN = isbn;
            Paginas = paginas;
        }

        public override void AdicionarItem()
        {
            Console.WriteLine($"Livro {Titulo} do autor {Autor} adicionado com sucesso!");
        }

    }
}
