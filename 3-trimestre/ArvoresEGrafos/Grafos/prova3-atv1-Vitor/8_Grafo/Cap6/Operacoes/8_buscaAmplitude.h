#ifndef BUSCA_AMPLITUDE_H
#define BUSCA_AMPLITUDE_H
/* --------------------------- */
void buscaAmplitude(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi){

   if (fc == NULL)
       fc = grafo->fc;

   if (fi == NULL)
       fi = grafo->fi;

    //diz q todos os vertices nao foram visitados
    pNoh nohAtual = grafo->listaVertices->primeiro;
    while (nohAtual != NULL) {
        pVertice vertice = (pVertice) nohAtual->info;
        vertice->visitado = 0; //aqui add o visitado na estrutura do vetrtice
        nohAtual = nohAtual->prox;
    }

    //cria uma fila para gerenciar os vertices q vao ser visitdaos
    pDFila fila = criarFila();

    //comeca a busca com o primeiro vertice, enfilera e eh visitado
    pVertice verticeInicial = (pVertice) grafo->listaVertices->primeiro->info;
    enfileirarInfo(fila, verticeInicial);
    verticeInicial->visitado = 1;

    while (filaVazia(fila) > 0) {
        //desinfilera um vertice da fila
        pVertice verticeAtual = (pVertice) desenfileirarInfo(fila);
        fi(verticeAtual->info);

        //p/ cada vertice q sai do vertice atual ha enfileiramento e visitado
        pNoh nohAdjacente = verticeAtual->listaAdjacencias->primeiro;
        while (nohAdjacente != NULL) {
            pVertice verticeAdjacente = (pVertice) nohAdjacente->info;
            if (!verticeAdjacente->visitado) {
                verticeAdjacente->visitado = 1;
                enfileirarInfo(fila, verticeAdjacente);
            }
            nohAdjacente = nohAdjacente->prox;
        }
    }
    free(fila->pdLista);
    free(fila);
}
#endif
