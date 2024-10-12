#include <stdio.h>

int main()
{
  int opcao;
  printf("\n 1-venda a vista 10%% de desconto");
  printf("\n 2-venda a prazo 30 dias 5%% desconto");
  printf("\n 3-venda a prazo 60 dias mesmo preco");
  printf("\n 4-venda a prazo 90 dias 5%% de acressimo");
  printf("\n 5-venda com cartao de debito desconto de 8%% ");
  printf("\n 6-venda com cartao de credito desconto de 7%%");

  printf("Selecione o metodo de pagamento \n \n");

  scanf("%d", &opcao);

  float valor;
  printf("informe o valor da venda");
  scanf("%f", &valor);

  switch (opcao)
  {
  case 1:
    valor = valor - (valor * 10) / 100;
    printf("Valor total a pagar: %.2f", valor);
    break;
  case 2:
    valor = valor - (valor * 5) / 100;
    printf("Valor total a pagar: %.2f", valor);
    break;
  case 3:
    printf("Valor total a pagar: %.2f", valor);
    break;
  case 4:
    valor = (valor * 5) / 100;
    printf("Valor total a pagar: %.2f", valor);
    break;
  case 5:
    valor = valor - (valor * 8) / 100;
    printf("Valor total a pagar: %.2f", valor);
    break;
  case 6:
    valor = valor - (valor * 7) / 100;
    printf("Valor total a pagar: %.2f", valor);
    break;

  default:
    printf("produto importado");

    break;
  }
  return 0;
}
