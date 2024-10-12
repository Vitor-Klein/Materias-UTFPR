#ifndef 15_COLOREGRAFO_H_INCLUDED
#define 15_COLOREGRAFO_H_INCLUDED

//func de tad_grafo.h, colore e verifica validade da coloracao
int coloracao(pDGrafo grafo) {
    pNoh atual = grafo->listaVertices->primeiro;

    //coloracao de grafo
    while (atual != NULL) {
        pVertice vertice = (pVertice) atual->info;
        int cor = 1;

        //encontra uma cor valida
        while (1) {
            int corValida = 1;
            pNoh adjAtual = vertice->listaAdjacencias->primeiro; //comeaa a ver adjacencias do vertice

            while (adjAtual != NULL) {
                pVertice adj = (pVertice) adjAtual->info;

                if (adj->cor == cor) { //vertice adjacente ja tem cor?
                    corValida = 0; //cor NAO valida
                    break;
                }

                adjAtual = adjAtual->prox;
            }

            if (corValida) {
                break; //cor valida
            }
            cor++;
        }

        vertice->cor = cor; //atribui a cor ao vertice
        atual = atual->prox;
    }

    //------------------------------------------------
    //a coloracao eh valida?
    atual = grafo->listaVertices->primeiro;
    while (atual != NULL) {

        pVertice vertice = (pVertice) atual->info;
        pNoh adjAtual = vertice->listaAdjacencias->primeiro;

        while (adjAtual != NULL) {
            pVertice adj = (pVertice) adjAtual->info;


            if (vertice->cor == adj->cor) {
                return 0; //coloracao NAO valida
            }

            adjAtual = adjAtual->prox;
        }

        atual = atual->prox;
    }

    return 1; //coloracao valida
}

#endif // 15_COLOREGRAFO_H_INCLUDED
