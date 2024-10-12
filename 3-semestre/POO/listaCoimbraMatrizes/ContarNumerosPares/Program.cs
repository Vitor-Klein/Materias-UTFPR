using System;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Contagem de Números Pares em uma Matriz");

        Console.Write("Digite o número de linhas da matriz: ");
        int linhas = int.Parse(Console.ReadLine());

        Console.Write("Digite o número de colunas da matriz: ");
        int colunas = int.Parse(Console.ReadLine());

        int[,] matriz = new int[linhas, colunas];

        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                Console.Write($"Digite o valor para a posição [{i}, {j}]: ");
                matriz[i, j] = int.Parse(Console.ReadLine());
            }
        }

        Console.WriteLine("\nMatriz completa:");
        ImprimirMatriz(matriz);

        int numerosPares = ContarNumerosPares(matriz);
        Console.WriteLine($"\nTotal de números pares na matriz: {numerosPares}");

        Console.ReadLine(); // Espera o usuário pressionar Enter para sair
    }

    static void ImprimirMatriz(int[,] matriz)
    {
        int linhas = matriz.GetLength(0);
        int colunas = matriz.GetLength(1);

        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                Console.Write(matriz[i, j] + "\t");
            }
            Console.WriteLine();
        }
    }

    static int ContarNumerosPares(int[,] matriz)
    {
        int linhas = matriz.GetLength(0);
        int colunas = matriz.GetLength(1);
        int numerosPares = 0;

        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                if (matriz[i, j] % 2 == 0)
                {
                    numerosPares++;
                }
            }
        }

        return numerosPares;
    }
}

