#include <stdio.h>

int main()
{
  float valor, valorPago;
  int notas100, notas10, moedas1;

  printf("Digite um valor da compra: R$ ");
  scanf("%f", &valor);

  printf("Digite um valor pago pelo cliente: R$ ");
  scanf("%f", &valorPago);

  int valorCentavos = (valorPago - valor) * 100;

  notas100 = valorCentavos / 10000;
  valorCentavos %= 10000;

  notas10 = valorCentavos / 1000;
  valorCentavos %= 1000;

  moedas1 = valorCentavos / 100;
  valorCentavos %= 100;

  printf("\nNotas de 100: %d", notas100);
  printf("\nNotas de 10: %d", notas10);
  printf("\nMoedas de 1: %d", moedas1);

  return 0;
}