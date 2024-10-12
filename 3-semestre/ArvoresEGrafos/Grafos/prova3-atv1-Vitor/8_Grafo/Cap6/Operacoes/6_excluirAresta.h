#ifndef EXCLUIR_ARESTA_H
#define EXCLUIR_ARESTA_H
/* --------------------------- */
void excluirAresta(pDGrafo grafo, void *vOrig, void *vDest, FuncaoComparacao fc) {
    if (fc == NULL)
        fc = grafo->fc;

    //procura o vOrig e o vDest usando buscarVertice.h
    pVertice verticeOrigem = buscarVertice(grafo, vOrig, fc);
    pVertice verticeDestino = buscarVertice(grafo, vDest, fc);

    if (verticeOrigem == NULL || verticeDestino == NULL) {
        return; //se um dos vertices nao existir a aresta nao pode ser removida
    }

    //exclui o vDest da lista de adjaecncia do vOrig
    pNoh nohAtual = verticeOrigem->listaAdjacencias->primeiro;
    while (nohAtual != NULL) {
        if (fc(nohAtual->info, verticeDestino) == 0) { //ve se o noh eh o vDest
            excluirInfo(verticeOrigem->listaAdjacencias, nohAtual->info, fc); //exclui cap3.operacoes
            verticeOrigem->grau--;
            break;
        }
        nohAtual = nohAtual->prox;
    }

    //a aresta eh bidirecional?, exclui o vOrig da lista de adjacencia do vDest
    nohAtual = verticeDestino->listaAdjacencias->primeiro;
    while (nohAtual != NULL) {
        if (fc(nohAtual->info, verticeOrigem) == 0) {
            excluirInfo(verticeDestino->listaAdjacencias, nohAtual->info, fc)
            verticeDestino->grau--;
            break;
        }
        nohAtual = nohAtual->prox;
    }
}
#endif
