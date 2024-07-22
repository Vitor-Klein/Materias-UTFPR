#include <stdio.h>
#include "Utils.h"
#include "ArvoreAVL.h"

pDArvore constroiArvore(int dados[], int tam)
{

    pDArvore arvore = criarArvore(2);
    int i;
    for (i = 0; i < tam; i++)
    {
        incluirInfo(arvore, alocaInt(dados[i]), comparaInt);
        desenhaArvore(arvore, imprimeInt);
    }

    return arvore;
}

int main()
{

    int ex1[] = {5, 10, 3, 7, 6};             // rotação simples - direita
    int ex2[] = {5, 10, 3, 12, 14};           // rotação simples - esquerda
    int ex3[] = {5, 10, 3, 7, 8};             // rotação dupla - esquerda/direita
    int ex4[] = {5, 10, 3, 4, 12, 9, 14, 13}; // rotação dupla - direita/esquerda
    int ex5[] = {5, 10, 3, 4, 12, 9, 14};     // Não precisa rotacionar

    printf("Exemplo 3:\n");
    pDArvore arvore3 = constroiArvore(ex3, 5);
    printf("\n\n");

    // Excluindo elementos específicos
    printf("Excluindo o valor 3 da árvore 3:\n");

    // Verifica se o elemento foi excluído
    if (excluirInfo(arvore3, alocaInt(3), comparaInt))
    {
        printf("Elemento 3 excluído com sucesso!\n");
    }
    else
    {
        printf("Elemento 3 não encontrado!\n");
    }

    desenhaArvore(arvore3, imprimeInt);
    printf("\n\n");

    return 0;
}