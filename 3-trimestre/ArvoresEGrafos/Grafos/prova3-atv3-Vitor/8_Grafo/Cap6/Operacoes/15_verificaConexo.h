#ifndef 15_VERIFICACONEXO_H_INCLUDED
#define 15_VERIFICACONEXO_H_INCLUDED

//primeiro uma func aux p/ marcar os vertices visitados
//necessario usar pilha
static void marcarVisitados(pDGrafo grafo, pVertice vertice, FuncaoComparacao fc, int *visitado) {

    pDPilha pilha = criarPilha();
    empilharInfo(pilha, vertice);

    while (pilhaVazia(pilha) == 0) {

        pVertice vAtual = (pVertice) desempilharInfo(pilha);

        if (visitado[(intptr_t)vAtual] == 0) {
            visitado[(intptr_t)vAtual] = 1;
            pDLista adjacencias = vAtual->listaAdjacencias;
            pNoh atual = adjacencias->primeiro;

            while (atual != NULL) {
                if (visitado[(intptr_t)atual->info] == 0) {
                    empilharInfo(pilha, atual->info);
                }

                atual = atual->prox;
            }
        }
    }

    free(pilha);
}

//-----------------------------------------------------------------

//func em tad_grafo
int grafoConexo(pDGrafo grafo, FuncaoComparacao fc) {


    if (grafo == NULL || grafo->listaVertices == NULL) {
        return 0; //nao eh conexo se nao existir vertice na lista
    }


    int numVertices = grafo->listaVertices->quantidade;
    int *visitado = (int *)calloc(numVertices, sizeof(int)); //calloc pq eh necessario passar numVertices e comeca em 0


    //verifica se a memoria foi alocada com sucesso
    if (visitado == NULL) {
        return 0;
    }

    //inicia uma busca em profundidade a partir do primeiro vertice
    pVertice verticeInicial = (pVertice)grafo->listaVertices->primeiro->info;
    marcarVisitados(grafo, verticeInicial, fc, visitado);


    //todos evrtices foram visitados?
    for (int i = 0; i < numVertices; i++) {

        if (visitado[i] == 0) {
            free(visitado);

            return 0; //n eh conexo se algum vertice n foi visitado
        }
    }

    free(visitado);
    return 1; //eh conexo
}

#endif // 15_VERIFICACONEXO_H_INCLUDED
