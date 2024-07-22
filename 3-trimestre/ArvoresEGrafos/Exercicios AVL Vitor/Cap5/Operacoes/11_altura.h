#ifndef ALTURA_ARVORE_BINARIA_H
#define ALTURA_ARVORE_BINARIA_H

/* -------------------------------------------*/
int alturaRecursiva(pNohArvore raiz)
{
  if (raiz == NULL)
    return 0;

  // � uma folha
  if (raiz->esquerda == NULL && raiz->direita == NULL)
    return 1;

  int alturaEsq, alturadireita;

  alturaEsq = 1 + alturaRecursiva(raiz->esquerda);
  alturadireita = 1 + alturaRecursiva(raiz->direita);

  if (alturaEsq > alturadireita)
    return alturaEsq;

  return alturadireita;
}

int altura(pDArvore arvore)
{
  return alturaRecursiva(arvore->raiz);
}
#endif
