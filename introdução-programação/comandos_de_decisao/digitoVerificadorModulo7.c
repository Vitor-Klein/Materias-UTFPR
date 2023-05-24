#include <stdio.h>

int A, B, C, D, E, S, DigitoV;

int main()
{

  printf("Digite o valor de A: ");

  scanf("%d", &A);

  printf("Digite o valor de B: ");

  scanf("%d", &B);

  printf("Digite o valor de C: ");

  scanf("%d", &C);

  printf("Digite o valor de D: ");

  scanf("%d", &D);

  printf("Digite o valor de E: ");

  scanf("%d", &E);

  S = 2 * A + 3 * B + 4 * C + 5 * D + 6 * E;

  DigitoV = S % 7;

  printf("\nO digito verificador modulo 7 é: %d", DigitoV);
}