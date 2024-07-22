#include <stdio.h>
#include "Utils.h"
#include "ArvoreBinaria.h"

int main()
{
    pDArvore pArvoreInt = criarArvore(2);

    /* teste de inclusao */
    incluirInfo(pArvoreInt, alocaInt(9), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(7), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(45), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(34), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(1), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(3), comparaInt);
    excluirInfo(pArvoreInt, alocaInt(34), comparaInt);

    desenhaArvore(pArvoreInt, imprimeInt);

    printf("\n Altura: %d \n", altura(pArvoreInt));
    printf("Qtde Folhas: %d \n", quantidadeFolhas(pArvoreInt));
    printf("Qtde Nohs: %d \n", quantidadeNohs(pArvoreInt));
}
