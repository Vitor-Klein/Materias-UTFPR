#include <stdio.h>

int main()
{
  float nota1, nota2, cont;
  float media, media_turma;

  while (cont <= 10)
  {
    printf("\nInforme a primeira nota do aluno ");
    scanf("%f", &nota1);

    printf("\nInforme a segunda nota do aluno ");
    scanf("%f", &nota2);

    media = (nota1 + nota2) / 2;

    if (media > 7)
    {
      printf("\nAluno aprovado!");
    }
    else
    {
      printf("\nAluno reprovado");
    }

    media_turma += media;
    cont++;
  }

  printf("Media geral da turma: %d\n", (media_turma) / 10);

  return 0;
}
