#include <stdio.h>

int main()
{
  int i = 0, count_altura = 0, count_idade = 0;
  float altura, idade, soma_altura = 0, soma_idade = 0;

  while (i < 45)
  {
    printf("Digite a altura (em metros) do aluno %d: ", i + 1);
    scanf("%f", &altura);

    printf("Digite a idade do aluno %d: ", i + 1);
    scanf("%f", &idade);

    if (altura < 1.7)
    {
      soma_idade += idade;
      count_idade++;
    }

    if (idade > 20)
    {
      soma_altura += altura;
      count_altura++;
    }

    i++;
  }

  if (count_idade > 0)
  {
    printf("A idade média dos alunos com menos de 1,70 de altura é: %.2f\n", soma_idade / count_idade);
  }
  else
  {
    printf("Não há alunos com menos de 1,70 de altura.\n");
  }

  if (count_altura > 0)
  {
    printf("A altura média dos alunos com mais de 20 anos é: %.2f metros\n", soma_altura / count_altura);
  }
  else
  {
    printf("Não há alunos com mais de 20 anos.\n");
  }

  return 0;
}
