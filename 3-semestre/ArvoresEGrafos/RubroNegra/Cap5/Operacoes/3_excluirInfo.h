#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H
//Se vira, eu mudei tudo
//Não vai funcionar nada que tenha rotação por causa da implementação no incluirinfo, eu teria que refaze-la aqui mas eu estou com preguiça
//Mesmo se eu refizer as rotações eu não sei se elas sobreescrevem, a melhor opção é escrever com nomezinhos diferentes
//Outro ponto importante é que o exemplo que eu vi na internet sem DOUBLE BLACK era com orientação a objetos
//Portanto eu nao sei se esse código funciona pq obviamente eu não testei
//Melhorias :
// Tipo de dado bool na função excluirInfo, com a biblioteca stdbool.h
// Tirar todos os comentários e printf desnecessários
// trocar a playlist
// tirar a sentinela, já que eu não usei
// tirar o DOUBLE BLACK  que eu também não usei
//Exclusão recursiva igual às anteriores
//Balanceamento com procedimento e função para obter o irmão da raiz
/*---------------------------*/
// função para retornar o irmão

pNohArvore obterIrmao(pNohArvore noh)
{
    if (noh->pai == NULL)
        return NULL;

    if (noh == noh->pai->esquerda)
        return noh->pai->direita;

    return noh->pai->esquerda;
}

/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    if (raiz == NULL)
    {
        printf("raiz nula\n");
        return raiz;
    }
    printf("Passou aqui 1\n");
    //Caso 1 e 2 - Nó com nenhum ou 1 filho
    int comparacao = pfc(info, raiz->info);
    if (comparacao > 0)
    {
        printf("esquerda 1\n");
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, pfc);
    }
    else if (comparacao < 0)
    {
        printf("direita 1\n");
        raiz->direita = excluirInfoRecursivo(raiz->direita, info, pfc);
    }
    else
    {
        pNohArvore temp;
        printf("Passou aqui 2 nem esquerda nem direita\n");
        if (raiz->esquerda == NULL)
        {
            temp = raiz->direita;
            free(raiz);
        }
        else if (raiz->direita == NULL)
        {
            printf("pegou filho Esquerda \n");
            temp = raiz->esquerda;
            free(raiz);

        }
        printf("Passou aqui 3 - com 2 filhos\n");
        //Caso 2 - Noh com 2 filhos
        //pNohArvore tmp = raiz->direita ;
        //while (tmp && tmp->esquerda != NULL)
        //{
        //    tmp = tmp->esquerda;
        //}
        //raiz->info = tmp->info;
        //raiz->direita = excluirInfoRecursivo(raiz->direita, temp->info, pfc);

        printf("temp : %d \n", *(((int*)temp->info)));

        // Caso simples - raiz ou o pai são vermelhos
        if(raiz->cor == RED || temp->cor == RED)
        {
            temp->cor = BLACK ;
            //  free(raiz);
            return temp ;
        }

        // outros casos aqui

        //  Balanceamento
        balancearExclusao(raiz, temp);

//Tudo que vem abaixo vai estar no procedimento balancearExclusao
// 3.1 - pai e filho pretos
        if(raiz->cor == BLACK && raiz->cor == BLACK)
        {
            temp->cor = DOUBLEBLACK ;
// substituir a cor do filho do nó que foi deletado para DOUBLE BLACK, mesmo se o nó deletado for uma folha.
        }

// 3.2 enquanto a raiz for DOUBLE BLACK (para corrigi-la)
// 3.2 -
//     a()irmão preto com, pelo menos, um filho vermelho
//     i - Rotação Left-Left se o irmão for o filho esquerdo e o filho do irmão estiver no lado esquerdo ou ambos os filhos do irmão forem vermelhos
//     ii - Rotação Left-Right se o irmão for o filho esquerdo e o filho do irmão estiver do lado direito
//     iii - Rotação Right-Right se o irmão for o filho direito e o filho do irmão estiver do lado direito ou ambos os filhos do irmão forem vermelhos
//     iv - Rotação Right-Left se o irmão for o filho dieito e o filho do irmão estiver do lado esquerdo
        if(temp->cor == DOUBLE BLACK && temp->pai != NULL)
        {
            pNohArvore pai = temp->pai;
            pNohArvore irmao = obterIrmao(temp);
            if(irmao->cor == BLACK && (irmao->esquerda->cor == RED || irmao->direita->cor == RED))
            {

                if(irmao == pai->esquerda)
                {
                    if(irmao->esquerda != NULL && irmao->esquerda->cor == RED)
                    {
                        //Left-Left
                        rotacaoDireita(temp);
                        irmao->esquerda->cor = BLACK ;
                    }
                    else if(irmao->direita != NULL && irmao->direita->cor == RED)
                    {
                        //Left-Right
                        rotacaoEsquerdaDireita(temp);
                        irmao->direita->cor = BLACK ;
                    }
                }
                else
                {
                    if(irmao->direita != NULL && irmao->direita->cor == RED)
                    {
                        //Right-Right
                        rotacaoEsquerda(temp);
                        irmao->direita-> = BLACK;
                    }
                    else if(irmao->esquerda != NULL irmao->esquerda->cor == RED)
                    {
                        //Right-Left
                        rotacaoDireitaEsquerda(temp);
                        irmao->esquerda->cor = BLACK ;
                    }
                }

            }

// 3.2 -
//     b) irmão preto com ambos os filhos pretos : Recolorir, e repetir se o pai for preto
//        se o pai for vermelho, nós podemos transforma-lo em BLACK

            if(irmao->cor = BLACK && (irmao->esquerda->cor = BLACK || irmao->direita->cor = BLACK))
            {
                irmao->cor = RED ;
                if(irmao->pai->cor = BLACK)
                {
                    irmao->pai->cor = DOUBLEBLACK ;
                }
                else if(irmao->pai->cor == RED)
                {
                    irmao->pai->cor = BLACK ;
                }
            }

        }

// 3.2 -
//      c) Rotacionar - irmão vermelho
//       i - Caso left se o irmão for o filho esquerdo : Rotacione o pai para a direita
//       ii - Caso Right se o irmão for o filho direito : Rotacione o pai para a esquerda
        if(irmao->cor == RED)
        {
            if(irmao = pai->esquerda)
            {
                rotacaoDireita(pai);
            }
            else
            {
                rotacaoEsquerda(pai);
            }
        }



// 3.3 - Se for raiz, colorir de preto e retorna-lo (a altura da arvore reduz em 1 )

        if ( temp->pai == NULL)
            raiz->cor = BLACK;
        return temp;
    }


    return raiz ;
    //if (raiz->pai == NULL)
    //{
    //  printf("Passou aqui 6\n");
    // O nó excluído era a raiz
    //return raiz;
    //}
}

/* ---------------------------------------------------------- */
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{
    printf("Passou aqui -1\n");
    arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
    if (arvore->raiz != NULL)
    {
        arvore->raiz->cor = BLACK;
    }

    arvore->quantidadeNohs--;
    return 1;

}

/* ------------------------------------------------------------- */
//procedimento balancearExclusao
/*
void balancearExclusao(pNohArvore raiz, pNohArvore noh)
{
    // Caso 3.1 - Pai e filho pretos
    while (noh != raiz && (noh == NULL || noh->cor == BLACK))
    {
        pNohArvore pai = noh->pai;
        pNohArvore irmao = obterIrmao(noh);

        // Caso 3.2 - Irmão preto com pelo menos um filho vermelho
        if (irmao->cor == BLACK)
        {
            if ((irmao->esquerda != NULL && irmao->esquerda->cor == RED) ||
                (irmao->direita != NULL && irmao->direita->cor == RED))
            {
                if (irmao == pai->esquerda)
                {
                    if (irmao->esquerda != NULL && irmao->esquerda->cor == RED)
                    {
                        // Rotação Left-Left
                        rotacaoDireitaEx(pai);
                        irmao->esquerda->cor = BLACK;
                    }
                    else
                    {
                        // Rotação Left-Right
                        // rotacaoEsquerdaDireita();
                        rotacaoEsquerdaEx(irmao);
                        rotacaoDireitaEx(pai);
                        irmao->direita->cor = BLACK;
                    }
                }
                else
                {
                    if (irmao->direita != NULL && irmao->direita->cor == RED)
                    {
                        // Rotação Right-Right
                        rotacaoEsquerdaEx(pai);
                        irmao->direita->cor = BLACK;
                    }
                    else
                    {
                        // Rotação Right-Left
                        // rotacaoDireitaEsquerda();
                        rotacaoDireitaEx(irmao);
                        rotacaoEsquerdaEx(pai);
                        irmao->esquerda->cor = BLACK;
                    }
                }
                irmao->cor = pai->cor;
                pai->cor = BLACK;
                return;
            }
        }

        // Caso 3.2 - Irmão preto com ambos os filhos pretos
        if (irmao->cor == BLACK && (irmao->esquerda == NULL || irmao->esquerda->cor == BLACK) && (irmao->direita == NULL || irmao->direita->cor == BLACK))
        {
            irmao->cor = RED;
            noh = pai;
            continue;
        }

        // Caso 3.3 - Irmão vermelho
        if (irmao->cor == RED)
        {
            if (irmao == pai->esquerda)
            {
                // Rotação para direita
                rotacaoDireitaEx(pai);
            }
            else
            {
                // Rotação para esquerda
                rotacaoEsquerdaEx(pai);
            }
            pai->cor = RED;
            irmao->cor = BLACK;
         //   continue;
        }
    }

    if (noh != NULL)
        noh->cor = BLACK;
}
*/
/*-------------------------------------------------------*/
//Rotações XD
/*
void rotacaoEsquerdaEx(pNohArvore x)
{
    pNohArvore y = x->direita;
    x->direita = y->esquerda;
    if (y->esquerda != NULL)
        y->esquerda->pai = x;

    y->pai = x->pai;
    if (x->pai == NULL)
        raiz = y;
    else if (x == x->pai->esquerda)
        x->pai->esquerda = y;
    else
        x->pai->direita = y;

    y->esquerda = x;
    x->pai = y;
}

void rotacaoDireitaEx(pNohArvore x)
{
    pNohArvore y = x->esquerda;
    x->esquerda = y->direita;
    if (y->direita != NULL)
        y->direita->pai = x;

    y->pai = x->pai;
    if (x->pai == NULL)
        raiz = y;
    else if (x == x->pai->direita)
        x->pai->direita = y;
    else
        x->pai->esquerda = y;

    y->direita = x;
    x->pai = y;
}
*/
#endif
