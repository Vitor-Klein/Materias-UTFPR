#include <stdio.h>

int main()
{
  float altura, maior, menor, somaH = 0, somaM = 0, media;
  int cont = 1, cont_H = 0, cont_M = 0;
  char sexo;

  while (cont <= 5)
  {
    printf("informe sexo");
    scanf("%c", &sexo);
    printf("informe altura");
    scanf("%f", &altura);

    if (cont == 1)
    {
      maior = altura;
      menor = altura;
    }
    else if (altura > altura)
    {
      maior = altura;
    }
    else if (altura < altura)
    {
      menor = altura;
    }

    if (sexo == 'F')
    {
      somaM += altura;
      cont_M++;
    }
    else
    {
      somaH += altura;
      cont_H++;
    }
    cont++;
  }
  printf("\n maior altura %.2f menor altura %.2f", maior, menor);
  media = somaM / cont_M;
  printf("\n media de altura das mulheres %.2f", media);
  media = somaH / cont_H;
  printf("\n media de altura dos homens %.2f", media);

  return 0;
}
