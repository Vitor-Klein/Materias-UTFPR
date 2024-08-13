#ifndef CRIAR_ARVORE_H
#define CRIAR_ARVORE_H

/* --------------------------*/
pDArvore criarArvore(int grau){
    pDArvore dArvore = malloc(sizeof(DArvore));
    dArvore->raiz = NULL;
    dArvore->quantidadeNohs = 0;
    dArvore->grau  = grau;

    dArvore->sentinela = malloc(sizeof(pNohArvore));
    dArvore->sentinela = BLACK;

    return dArvore;
};

#endif
