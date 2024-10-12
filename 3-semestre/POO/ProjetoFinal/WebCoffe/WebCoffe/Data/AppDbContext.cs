using Microsoft.EntityFrameworkCore;
using WebCoffe.Models;

namespace WebCoffe.Data
{
    public class AppDbContext : DbContext
    {
        public AppDbContext(DbContextOptions<AppDbContext> options)
            : base(options)
        {
        }

        public DbSet<Receita> Receitas { get; set; }
        public DbSet<Cafe> Cafes { get; set; }
        public DbSet<Cha> Chas { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Receita>().HasDiscriminator<string>("Tipo")
                .HasValue<Cafe>("Café")
                .HasValue<Cha>("Chá");
        }
    }
}
