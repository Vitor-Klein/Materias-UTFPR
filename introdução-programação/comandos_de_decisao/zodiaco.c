#include <stdio.h>
#include <stdlib.h>

int main()
{
  float mes, dia;
  printf("Informe o mes do aniversario: ");
  scanf("%d", &mes);
  printf("Informe o dia do aniversario: ");
  scanf("%d", &dia);

  if (mes == 01 && dia >= 21 || mes == 2 && dia <= 19)
  {
    printf("signo de Aquario");
  }
  else if (mes == 02 && dia >= 20 || mes == 3 && dia <= 20)
  {
    printf("signo de Peixes");
  }
  else if (mes == 03 && dia >= 21 || mes == 4 && dia <= 20)
  {
    printf("signo de Aries");
  }
  else if (mes == 04 && dia >= 21 || mes == 5 && dia <= 20)
  {
    printf("signo de Touro");
  }
  else if (mes == 05 && dia >= 21 || mes == 6 && dia <= 20)
  {
    printf("signo de Gemeos");
  }
  else if (mes == 06 && dia >= 21 || mes == 7 && dia <= 21)
  {
    printf("signo de Cancer");
  }
  else if (mes == 07 && dia >= 22 || mes == 8 && dia <= 22)
  {
    printf("signo de Leao");
  }
  else if (mes == 8 && dia >= 23 || mes == 9 && dia <= 22)
  {
    printf("signo de Virgem");
  }
  else if (mes == 9 && dia >= 23 || mes == 10 && dia <= 22)
  {
    printf("signo de Libra");
  }
  else if (mes == 10 && dia >= 23 || mes == 11 && dia <= 21)
  {
    printf("signo de Escorpiao");
  }
  else if (mes == 11 && dia >= 22 || mes == 12 && dia <= 22)
  {
    printf("signo de Sagitario");
  }
  else if (mes == 12 && dia >= 22 || mes == 1 && dia <= 20)
  {
    printf("signo de Capricorneo");
  }
  return 0;
}