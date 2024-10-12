#ifndef 16_EMPARELHAMENTOBIPARTIDO_H_INCLUDED
#define 16_EMPARELHAMENTOBIPARTIDO_H_INCLUDED

pDLista emparelhamento(pDGrafo grafo) {
    if (!coloracao(grafo)) {
        return NULL;
    }


    pDLista emparelhamento = criarLista();
    pNoh atual = grafo->listaVertices->primeiro;



    while (atual != NULL) {

        pVertice vertice = (pVertice) atual->info;

        if (vertice->cor == 1) {
            pNoh adjAtual = vertice->listaAdjacencias->primeiro;


            while (adjAtual != NULL) {
                pVertice adj = (pVertice) adjAtual->info;

                if (adj->cor == 2) {
                    incluirInfo(emparelhamento, vertice);
                    incluirInfo(emparelhamento, adj);
                    break;
                }

                adjAtual = adjAtual->prox;
            }

        }

        atual = atual->prox;
    }

    return emparelhamento;
}

#endif // 16_EMPARELHAMENTOBIPARTIDO_H_INCLUDED
