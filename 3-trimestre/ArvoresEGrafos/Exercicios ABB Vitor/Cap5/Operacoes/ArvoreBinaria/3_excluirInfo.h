#include <stdio.h>
#include <stdlib.h>

pNohArvore excluirInfo(pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    if (raiz == NULL)
        return raiz;

    int comparacao = pfc(raiz->info, info);
    if (comparacao < 0)
        raiz->esquerda = excluirInfo(raiz->esquerda, info, pfc);
    else if (comparacao > 0)
        raiz->direita = excluirInfo(raiz->direita, info, pfc);
    else
    {
        // Caso 1: O nó a ser excluído é uma folha
        if (raiz->esquerda == NULL && raiz->direita == NULL)
        {
            free(raiz);
            raiz = NULL;
        }
        // Caso 2: O nó a ser excluído tem somente 1 filho
        else if (raiz->esquerda == NULL)
        {
            pNohArvore temp = raiz;
            raiz = raiz->direita;
            free(temp);
        }
        else if (raiz->direita == NULL)
        {
            pNohArvore temp = raiz;
            raiz = raiz->esquerda;
            free(temp);
        }
        // Caso 3: O nó a ser excluído tem dois filhos
        else
        {
            pNohArvore temp = encontrarMenorNoh(raiz->direita);
            raiz->info = temp->info;
            raiz->direita = excluirInfo(raiz->direita, temp->info, pfc);
        }
    }
    return raiz;
}