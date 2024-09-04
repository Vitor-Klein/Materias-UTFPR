using WebCoffe.Models;

namespace WebCoffe.Services.Interfaces
{
    public interface IReceitaService
    {
        Task<List<Receita>> GetReceitasAsync();
        Task<Receita> GetReceitaByIdAsync(int id);
        Task AddReceitaAsync(Receita receita);
        Task UpdateReceitaAsync(Receita receita);
        Task DeleteReceitaAsync(int id);
    }

}
