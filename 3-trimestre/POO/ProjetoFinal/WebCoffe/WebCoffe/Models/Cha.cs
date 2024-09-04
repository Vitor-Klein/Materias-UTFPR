namespace WebCoffe.Models
{
    public class Cha : Receita
    {
        public string? TipoFolha { get; set; }
        public override string Tipo => "Chá";
    }
}
