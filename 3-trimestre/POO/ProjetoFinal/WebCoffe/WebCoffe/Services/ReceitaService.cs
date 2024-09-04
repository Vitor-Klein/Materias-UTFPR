using WebCoffe.Data;
using WebCoffe.Models;
using WebCoffe.Services.Interfaces;
using Microsoft.EntityFrameworkCore;

namespace WebCoffe.Services
{
    public class ReceitaService : IReceitaService
    {
        private readonly AppDbContext _context;

        public ReceitaService(AppDbContext context)
        {
            _context = context;
        }

        public async Task<List<Receita>> GetReceitasAsync()
        {
            return await _context.Receitas.ToListAsync();
        }

        public async Task<Receita> GetReceitaByIdAsync(int id)
        {
            return await _context.Receitas.FindAsync(id);
        }

        public async Task AddReceitaAsync(Receita receita)
        {
            _context.Receitas.Add(receita);
            await _context.SaveChangesAsync();
        }

        public async Task UpdateReceitaAsync(Receita receita)
        {
            _context.Entry(receita).State = EntityState.Modified;
            await _context.SaveChangesAsync();
        }

        public async Task DeleteReceitaAsync(int id)
        {
            var receita = await _context.Receitas.FindAsync(id);
            if (receita != null)
            {
                _context.Receitas.Remove(receita);
                await _context.SaveChangesAsync();
            }
        }
    }

}
