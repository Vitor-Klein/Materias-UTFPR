#include <stdio.h>

int main()
{
  int opcao;
  printf("Digite o codigo do produto \n");
  scanf("%d", &opcao);

  float preco;
  printf("Digite o preço do produto \n");
  scanf("%f", &preco);

  switch (opcao)
  {
  case 1:
    printf("sul: R$ %.2f", preco);
    break;
  case 2:
    printf("norte R$ %.2f", preco);
    break;
  case 3:
    printf("leste R$ %.2f", preco);
    break;
  case 4:
    printf("oeste R$ %.2f", preco);
    break;
  case 5 ... 6:
    printf("nordeste R$ %.2f", preco);
    break;
  case 7 ... 9:
    printf("sudeste R$ %.2f", preco);
    break;
  case 10 ... 20:
    printf("centro-oeste R$ %.2f", preco);
    break;
  case 25 ... 30:
    printf("noroeste R$ %.2f", preco);
    break;

  default:
    printf("produto importado");

    break;
  }
  return 0;
}
