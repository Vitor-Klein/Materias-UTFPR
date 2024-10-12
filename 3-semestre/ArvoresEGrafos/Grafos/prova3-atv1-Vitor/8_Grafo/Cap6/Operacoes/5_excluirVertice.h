#ifndef EXCLUIR_VERTICE_H
#define EXCLUIR_VERTICE_H
/* --------------------------- */
//primeiro se busca o vertice a ser excluido
void excluirVertice(pDGrafo grafo, void* info, FuncaoComparacao fc) {
    if (fc == NULL)
        fc = grafo->fc;

    pVertice vertice = buscarVertice(grafo, info, fc);
    if (vertice == NULL)
        return; //nao achou o vertice

    //busca e exclui arestas incidentes do vertice
    pDLista verticesIncidentes = buscarVerticesIncidentes(grafo, vertice, fc);
    pNoh nohAtual = verticesIncidentes->primeiro;
    while (nohAtual != NULL) {
        excluirAresta(grafo, nohAtual->info, vertice, fc);
        nohAtual = nohAtual->prox;
    }

    //exclui todas as arestas saindo do mesmo vertice
    pNoh nohAdjacente = vertice->listaAdjacencias->primeiro;
    while (nohAdjacente != NULL) {
        excluirAresta(grafo, vertice, nohAdjacente->info, fc);
        nohAdjacente = nohAdjacente->prox;
    }

    //remove o vertice da lista de vertices
    excluirInfo(grafo->listaVertices, vertice, fc);
    free(vertice);
}
#endif
