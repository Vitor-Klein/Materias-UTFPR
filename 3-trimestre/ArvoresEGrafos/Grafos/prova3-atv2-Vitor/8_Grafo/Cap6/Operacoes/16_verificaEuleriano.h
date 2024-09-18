#ifndef 16_VERIFICAEULERIANO_H_INCLUDED
#define 16_VERIFICAEULERIANO_H_INCLUDED

//grafo conexo?
int grafoConexoEuleriano(pDGrafo grafo, FuncaoComparacao fc) {
    pDLista verticesVisitados = criarLista();
    pVertice primeiroVertice = grafo->listaVertices->primeiro->info;

    buscaEmProfundidadeAux(grafo, primeiroVertice, verticesVisitados, fc);

    int resultado = (verticesVisitados->quantidade == grafo->listaVertices->quantidade);

    destruirLista(verticesVisitados, NULL);  //nao precisa liberar os vertices, apenas a lista

    return resultado;
}

//----------------------------------------------------

void buscaEmProfundidadeAux(pDGrafo grafo, pVertice vAtual, pDLista verticesVisitados, FuncaoComparacao fc) {
    incluirInfo(verticesVisitados, vAtual);

    pNoh atual = vAtual->listaAdjacencias->primeiro;
    while (atual != NULL) {
        if (contemInfo(verticesVisitados, atual->info, fc) == 0) {
            buscaEmProfundidadeAux(grafo, atual->info, verticesVisitados, fc);
        }
        atual = atual->prox;
    }
}

//----------------------------------------------------

//verificacao de grau par em tds vertices
int todosVerticesGrauPar(pDGrafo grafo, FuncaoComparacao fc) {
    pNoh atual = grafo->listaVertices->primeiro;

    while (atual != NULL) {
        pVertice verticeAtual = (pVertice) atual->info;
        if (verticeAtual->listaAdjacencias->quantidade % 2 != 0) {
            //se algum vertice tiver grau impar, o grafo nao eh euleriano
            return 0;
        }
        atual = atual->prox;
    }

    return 1; //todos os vertices tem grau par
}

//----------------------------------------------------
//----------------------------------------------------


//funç principal p/ verificar euleriano
int verificaGrafoEuleriano(pDGrafo grafo, FuncaoComparacao fc) {

    if (grafo == NULL || grafo->listaVertices->quantidade == 0) {
        return 0;
    }

    //grafo conexo?
    if (!grafoConexoEuleriano(grafo, fc)) {
        return 0;
    }

    return todosVerticesGrauPar(grafo, fc);
}

#endif // 16_VERIFICAEULERIANO_H_INCLUDED
