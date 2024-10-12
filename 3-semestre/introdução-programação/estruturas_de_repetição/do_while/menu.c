#include <stdio.h>

int main()
{
  int opcao;
  float num1, num2, resultado;

  do
  {
    printf("\nMenu de opções:\n");
    printf("\n1 - somar dois numeros");
    printf("\n2 - subtracao de dois numeros");
    printf("\n3 - multiplicacao de dois numeros");
    printf("\n4 - divisao de dois numeros");
    printf("\n5 - fim");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      printf("Digite dois numeros: ");
      scanf("%f %f", &num1, &num2);
      resultado = num1 + num2;
      printf("Resultado da soma: %.2f", resultado);
      break;
    case 2:
      printf("Digite dois numeros: ");
      scanf("%f %f", &num1, &num2);
      resultado = num1 - num2;
      printf("Resultado da subtracao: %.2f", resultado);
      break;
    case 3:
      printf("Digite dois numeros: ");
      scanf("%f %f", &num1, &num2);
      resultado = num1 * num2;
      printf("Resultado da multiplicacao: %.2f", resultado);
      break;
    case 4:
      printf("Digite dois numeros: ");
      scanf("%f %f", &num1, &num2);
      if (num2 == 0)
      {
        printf("Não é possível dividir por zero.\n");
      }
      else
      {
        resultado = num1 / num2;
        printf("Resultado da divisao: %.2f", resultado);
      }
      break;
    case 5:
      printf("Programa finalizado.\n");
      break;
    default:
      printf("Opção invalida. Tente novamente.\n");
      break;
    }
  } while (opcao != 5);

  return 0;
}
