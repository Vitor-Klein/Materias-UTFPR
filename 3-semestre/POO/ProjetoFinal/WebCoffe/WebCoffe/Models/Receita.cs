namespace WebCoffe.Models
{
    public abstract class Receita
    {
        public int Id { get; set; }
        public string? Nome { get; set; }
        public string? Descricao { get; set; }
        public TimeSpan TempoPreparo { get; set; }
        public virtual string? Tipo { get; }
    }
}
