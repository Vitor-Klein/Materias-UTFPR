#include <stdio.h>

int main()
{
  float nota, soma = 0, media;
  int contador = 0;

  do
  {
    printf("Digite a nota do aluno %d: ", contador + 1);
    scanf("%f", &nota);

    soma += nota;
    contador++;
  } while (contador < 5);

  media = soma / 5;

  printf("A média das notas dos alunos é %.2f", media);

  return 0;
}
