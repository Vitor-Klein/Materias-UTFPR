#ifndef 15_VERIFICAHAMILTONIANO_H_INCLUDED
#define 15_VERIFICAHAMILTONIANO_H_INCLUDED

//comeca vendo se ta td visitado
int todosVisitados(pDLista verticesVisitados, int numVertices) {
    return verticesVisitados->quantidade == numVertices;
}

//existe ciclo hamiltoniano?
int verificaCicloHamiltonianoRecursivo(pDGrafo grafo, pVertice vAtual, pDLista verticesVisitados, int numVertices, FuncaoComparacao fc) {


    if (todosVisitados(verticesVisitados, numVertices)) {
        //verifica se o ultimo vertice tem uma aresta para o primeiro vertice
        pVertice primeiroVertice = buscarInfoPos(verticesVisitados, 1);
        return contemInfo(vAtual->listaAdjacencias, primeiroVertice, fc);
    }

    //iteracao sobre os vertices adjacentes
    pNoh atual = vAtual->listaAdjacencias->primeiro;
    while (atual != NULL) {

        if (contemInfo(verticesVisitados, atual->info, fc) == 0) {

            incluirInfo(verticesVisitados, atual->info);
            if (verificaCicloHamiltonianoRecursivo(grafo, atual->info, verticesVisitados, numVertices, fc)) {
                return 1;
            }


            excluirInfo(verticesVisitados, atual->info, fc);
        }


        atual = atual->prox;
    }

    return 0;
}

//----------------------------------------------------
//----------------------------------------------------

//func principal p/ verificar hamiltoniano
int verificaCicloHamiltoniano(pDGrafo grafo, FuncaoComparacao fc) {
    if (grafo == NULL || grafo->listaVertices->quantidade == 0) {
        return 0;
    }

    pDLista verticesVisitados = criarLista();
    pVertice primeiroVertice = grafo->listaVertices->primeiro->info;
    incluirInfo(verticesVisitados, primeiroVertice);

    int resultado = verificaCicloHamiltonianoRecursivo(grafo, primeiroVertice, verticesVisitados, grafo->listaVertices->quantidade, fc);

    destruirLista(verticesVisitados, NULL);  //nao eh necessario liberar verrtices, apenas a lista

    return resultado;
}

#endif // 15_VERIFICAHAMILTONIANO_H_INCLUDED
