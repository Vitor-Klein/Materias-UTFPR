#ifndef 16_VERIFICABIPARTIDO_H_INCLUDED
#define 16_VERIFICABIPARTIDO_H_INCLUDED

//primeiro uma func aux p/ ver biparticao usando BFS (busca em largura)
//necessario usar pilha
static int verificarBipartidoBFS(pDGrafo grafo, pVertice verticeInicial, FuncaoComparacao fc) {
    pDPilha pilha = criarPilha();
    empilharInfo(pilha, verticeInicial);


    //entao crio um array p/ guardar os conjuntos dos vertices onde:
    //0==nao visitado; 1==conjunto 1; 2==conjunto 2
    int numVertices = grafo->listaVertices->quantidade;
    int *conjunto = (int *)calloc(numVertices, sizeof(int));


    //verifico se a memoria foi alocada
    if (conjunto == NULL) {
        free(pilha);
        return 0;
    }


    conjunto[(intptr_t)verticeInicial] = 1; //conjunto inicial do vertice


    while (pilhaVazia(pilha) == 0) {
        pVertice vAtual = (pVertice) desempilharInfo(pilha);

        int conjuntoAtual = conjunto[(intptr_t)vAtual];

        pDLista adjacencias = vAtual->listaAdjacencias;
        pNoh atual = adjacencias->primeiro;



        while (atual != NULL) {

            pVertice vAdj = (pVertice) atual->info;

            if (conjunto[(intptr_t)vAdj] == 0) {
            //se o vertice adjacente nao foi visitado atribui-se o conjunto oposto
            conjunto[(intptr_t)vAdj] = (conjuntoAtual == 1) ? 2 : 1;
            empilharInfo(pilha, vAdj);
            }

            else if (conjunto[(intptr_t)vAdj] == conjuntoAtual) {
            //se o vertice adjacente pertence ao mesmo conjunto o grafo nao eh bipartido
            free(conjunto);
            free(pilha);
            return 0;
            }

            atual = atual->prox;
        }
    }


    free(conjunto);
    free(pilha);
    return 1;
}

//-----------------------------------------------------------------

//func em tad_grafo
int grafoBipartido(pDGrafo grafo, FuncaoComparacao fc) {
    if (grafo == NULL || grafo->listaVertices == NULL) {
        return 0; //nao eh bipartido se nao existe vertice
    }

    int numVertices = grafo->listaVertices->quantidade;
    int *visitado = (int *)calloc(numVertices, sizeof(int));


    //verifica alocacao memoria
    if (visitado == NULL) {
        return 0;
    }


    pNoh atual = grafo->listaVertices->primeiro;


    while (atual != NULL) {
        pVertice vertice = (pVertice) atual->info;
        if (visitado[(intptr_t)vertice] == 0) {

            if (!verificarBipartidoBFS(grafo, vertice, fc)) {
                free(visitado);
                return 0; //nao eh bipartido se alguma componente nao for bipartida
            }
        }

        atual = atual->prox;
    }


    free(visitado);
    return 1; //eh bipartido
}

#endif // 16_VERIFICABIPARTIDO_H_INCLUDED
