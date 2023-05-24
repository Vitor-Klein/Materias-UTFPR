#include <stdio.h>

int main()
{
  int notaPortuges, notaMatematica, notaConhcimenosGerais, media;
  char nome[30];
  printf("Qual seu nome? ");
  gets(nome);
  printf("Qual a nota em Portugues? ");

  scanf("%d", &notaPortuges);

  printf("Qual a nota em Matematica? ");

  scanf("%d", &notaMatematica);

  printf("Qual a nota em Conhecimentos Gerais? ");

  scanf("%d", &notaConhcimenosGerais);

  media = (notaConhcimenosGerais * notaMatematica * notaPortuges) / 3;
  printf("Ola %s", nome);
  printf("\n \nSua nota em cada materia são: \n");
  printf("Portugues: %d", notaPortuges);
  printf("\n Matematica: %d", notaMatematica);
  printf("\n Conhecimentos Gerais: %d", notaConhcimenosGerais);
  printf(" \n \n Sua media e: %d", media);

  if (media > 7 && notaConhcimenosGerais >= 5 && notaMatematica >= 5 && notaPortuges >= 5)
  {
    printf("\n Aluno Aprovado!!");
  }
  else
  {
    printf("\n\nAluno reprovado");
  }

  return 0;
}