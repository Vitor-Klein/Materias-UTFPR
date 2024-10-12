#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H
//Se vira, eu mudei tudo
//N�o vai funcionar nada que tenha rota��o por causa da implementa��o no incluirinfo, eu teria que refaze-la aqui mas eu estou com pregui�a
//Mesmo se eu refizer as rota��es eu n�o sei se elas sobreescrevem, a melhor op��o � escrever com nomezinhos diferentes
//Outro ponto importante � que o exemplo que eu vi na internet sem DOUBLE BLACK era com orienta��o a objetos
//Portanto eu nao sei se esse c�digo funciona pq obviamente eu n�o testei
//Melhorias :
// Tipo de dado bool na fun��o excluirInfo, com a biblioteca stdbool.h
// Tirar todos os coment�rios e printf desnecess�rios
// trocar a playlist
// tirar a sentinela, j� que eu n�o usei
// tirar o DOUBLE BLACK  que eu tamb�m n�o usei
//Exclus�o recursiva igual �s anteriores
//Balanceamento com procedimento e fun��o para obter o irm�o da raiz
/*---------------------------*/
// fun��o para retornar o irm�o

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
    //Caso 1 e 2 - N� com nenhum ou 1 filho
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

        // Caso simples - raiz ou o pai s�o vermelhos
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
// substituir a cor do filho do n� que foi deletado para DOUBLE BLACK, mesmo se o n� deletado for uma folha.
        }

// 3.2 enquanto a raiz for DOUBLE BLACK (para corrigi-la)
// 3.2 -
//     a()irm�o preto com, pelo menos, um filho vermelho
//     i - Rota��o Left-Left se o irm�o for o filho esquerdo e o filho do irm�o estiver no lado esquerdo ou ambos os filhos do irm�o forem vermelhos
//     ii - Rota��o Left-Right se o irm�o for o filho esquerdo e o filho do irm�o estiver do lado direito
//     iii - Rota��o Right-Right se o irm�o for o filho direito e o filho do irm�o estiver do lado direito ou ambos os filhos do irm�o forem vermelhos
//     iv - Rota��o Right-Left se o irm�o for o filho dieito e o filho do irm�o estiver do lado esquerdo
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
//     b) irm�o preto com ambos os filhos pretos : Recolorir, e repetir se o pai for preto
//        se o pai for vermelho, n�s podemos transforma-lo em BLACK

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
//      c) Rotacionar - irm�o vermelho
//       i - Caso left se o irm�o for o filho esquerdo : Rotacione o pai para a direita
//       ii - Caso Right se o irm�o for o filho direito : Rotacione o pai para a esquerda
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
    // O n� exclu�do era a raiz
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

        // Caso 3.2 - Irm�o preto com pelo menos um filho vermelho
        if (irmao->cor == BLACK)
        {
            if ((irmao->esquerda != NULL && irmao->esquerda->cor == RED) ||
                (irmao->direita != NULL && irmao->direita->cor == RED))
            {
                if (irmao == pai->esquerda)
                {
                    if (irmao->esquerda != NULL && irmao->esquerda->cor == RED)
                    {
                        // Rota��o Left-Left
                        rotacaoDireitaEx(pai);
                        irmao->esquerda->cor = BLACK;
                    }
                    else
                    {
                        // Rota��o Left-Right
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
                        // Rota��o Right-Right
                        rotacaoEsquerdaEx(pai);
                        irmao->direita->cor = BLACK;
                    }
                    else
                    {
                        // Rota��o Right-Left
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

        // Caso 3.2 - Irm�o preto com ambos os filhos pretos
        if (irmao->cor == BLACK && (irmao->esquerda == NULL || irmao->esquerda->cor == BLACK) && (irmao->direita == NULL || irmao->direita->cor == BLACK))
        {
            irmao->cor = RED;
            noh = pai;
            continue;
        }

        // Caso 3.3 - Irm�o vermelho
        if (irmao->cor == RED)
        {
            if (irmao == pai->esquerda)
            {
                // Rota��o para direita
                rotacaoDireitaEx(pai);
            }
            else
            {
                // Rota��o para esquerda
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
//Rota��es XD
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
