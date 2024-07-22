#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

/* --------------------------*/
#include <stdlib.h>

pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao fc)
{
  if (raiz == NULL)
  {
    return NULL;
  }

  int comparacao = fc(info, raiz->info);

  // Nó a ser excluído encontrado
  if (comparacao == 0)
  {
    // Nó folha
    if (raiz->esquerda == NULL && raiz->direita == NULL)
    {
      free(raiz);
      return NULL;
    }
    // Nó com um filho
    else if (raiz->esquerda == NULL)
    {
      pNohArvore aux = raiz->direita;
      free(raiz);
      return aux;
    }
    else if (raiz->direita == NULL)
    {
      pNohArvore aux = raiz->esquerda;
      free(raiz);
      return aux;
    }
    // Nó com dois filhos
    else
    {
      // Encontrar o sucessor (menor valor na subárvore direita)
      pNohArvore sucessor = raiz->direita;
      while (sucessor->esquerda != NULL)
      {
        sucessor = sucessor->esquerda;
      }

      // Trocar informações do sucessor com o nó a ser excluído
      void *temp = raiz->info;
      raiz->info = sucessor->info;
      sucessor->info = temp;

      // Excluir o sucessor (que agora tem no máximo um filho)
      raiz->direita = excluirInfoRecursivo(raiz->direita, sucessor->info, fc);
    }
  }
  // Continuar a busca recursivamente na subárvore esquerdauerda ou direita
  else if (comparacao < 0)
  {
    raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, fc);
  }
  else
  {
    raiz->direita = excluirInfoRecursivo(raiz->direita, info, fc);
  }

  return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{
  if (arvore == NULL || arvore->raiz == NULL)
  {
    return 0;
  }

  arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
  return 1;
}

#endif
