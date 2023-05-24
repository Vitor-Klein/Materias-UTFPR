#include <stdio.h>

int main()
{
  int idade, maiorIdade = 0, menorIdade = 1000, numMulheresSalarioAteCem = 0, numPessoas = 0;
  char sexo;
  float salario, somaSalarios = 0, mediaSalarios;

  printf("Informe a idade, o sexo (M/F) e o salário de cada pessoa (Digite -1 para finalizar):\n");

  while (1)
  {
    printf("Idade: ");
    scanf("%d", &idade);

    if (idade == -1)
    {
      break;
    }

    printf("Sexo (M/F): ");
    scanf(" %c", &sexo);

    printf("Salário: R$ ");
    scanf("%f", &salario);

    somaSalarios += salario;
    numPessoas++;
    mediaSalarios = somaSalarios / numPessoas;

    if (idade > maiorIdade)
    {
      maiorIdade = idade;
    }
    if (idade < menorIdade)
    {
      menorIdade = idade;
    }

    if (sexo == 'F' && salario <= 100.0)
    {
      numMulheresSalarioAteCem++;
    }
  }

  printf("\nA média de salários do grupo é de: R$ %.2f\n", mediaSalarios);
  printf("A maior idade do grupo é: %d\n", maiorIdade);
  printf("A menor idade do grupo é: %d\n", menorIdade);
  printf("A quantidade de mulheres com salário até R$ 100,00 é: %d\n", numMulheresSalarioAteCem);

  return 0;
}
