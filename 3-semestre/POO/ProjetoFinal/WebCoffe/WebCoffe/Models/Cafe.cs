namespace WebCoffe.Models
{
    public class Cafe : Receita
    {
        public string? Torragem { get; set; }
        public override string Tipo => "Café";
    }
}