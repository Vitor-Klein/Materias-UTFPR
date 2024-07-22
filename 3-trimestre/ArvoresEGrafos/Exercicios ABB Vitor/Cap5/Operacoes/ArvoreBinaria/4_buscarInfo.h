#ifndef BUSCAR_INFO_H
#define BUSCAR_INFO_H
void *buscarInfo(pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    if (raiz == NULL)
        return NULL;

    int comparacao = pfc(raiz->info, info);
    if (comparacao == 0)
        return raiz->info;
    else if (comparacao < 0)
        return buscarInfo(raiz->esquerda, info, pfc);
    else
        return buscarInfo(raiz->direita, info, pfc);
}

// Função auxiliar para encontrar o nó com o menor valor na subárvore direita
pNohArvore encontrarMenorNoh(pNohArvore noh)
{
    pNohArvore atual = noh;
    while (atual && atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual;
}