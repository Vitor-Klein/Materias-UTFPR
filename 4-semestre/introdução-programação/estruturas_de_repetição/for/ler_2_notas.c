#include <stdio.h>

int main()
{
  int i, nota1 = 0, nota2 = 0, media = 0;
  for (i = 0; i <= 5; i++)
  {
    printf("\n escreva a primeira nota do aluno");
    scanf("%d", &nota1);

    printf("\n escreva a segunda nota do aluno");
    scanf("%d", &nota2);

    media = (nota1 + nota2) / 2;

    if (media < 7)
    {
      printf("\n Aluno reprovado com media %d", media);
    }
    else
    {
      printf("\n Aluno aprovado!!! com media %d", media);
    }
  }

  return 0;
}
