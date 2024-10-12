using HeracaProjetoBiblioteca.Modelos;

var livro = new Livro("Machado de assis", 123456, 100, "1", "Dom Casmurro", DateTime.Now);
DVD dvd = new("LucasFilmes", 120, "2", "JurasicPark2000", DateTime.Now);
Revista revista = new("Julho2024", 123456, "3", "Veja", DateTime.Now);

var items = new List<Item> { livro, dvd, revista };

foreach(var item in items)
{
    item.AdicionarItem();
}