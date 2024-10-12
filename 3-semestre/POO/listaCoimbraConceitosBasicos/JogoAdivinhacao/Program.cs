class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Jogo da Adivinhação");

    Random numAleatorio = new Random();
    int programNumber = numAleatorio.Next(1, 51);

    Console.WriteLine("Adivinhe o numero que estou pensando");
    int userNumber = int.Parse(Console.ReadLine());

    while (userNumber != programNumber)
    {
      if (userNumber > programNumber)
      {
        Console.WriteLine("o numero que pensei é menor digite outro");
        userNumber = int.Parse(Console.ReadLine());
      }
      else if (userNumber < programNumber)
      {
        Console.WriteLine("o numero que pensei é maior digite outro");
        userNumber = int.Parse(Console.ReadLine());

      }
    }

    Console.WriteLine("-------------------------");
    Console.WriteLine("Parabéns, você acertou!");
    Console.WriteLine("-------------------------");
  }
}
