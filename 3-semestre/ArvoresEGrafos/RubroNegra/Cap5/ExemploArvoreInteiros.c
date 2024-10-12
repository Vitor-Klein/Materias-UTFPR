#include <stdio.h>
#include "Utils.h"
#include "ArvoreRubroNegra.h"

pDArvore constroiArvore(int dados[], int tam){

    pDArvore arvore = criarArvore(2);
    int i;
    for(i=0; i<tam; i++){
        incluirInfo(arvore, alocaInt(dados[i]),comparaInt);
    }

    return arvore;
}


int main(){

   int ex1[]   = {5, 10, 3, 2};   // caso 1
   int ex1_1[] = {5, 3, 2};       // caso 2.1
   int ex1_2[] = {5, 10, 12};     // caso 2.2
   int ex1_3[] = {5, 3, 4};       // caso 2.3
   int ex2[]   = {5, 10, 3, 2, 12, 11};  // caso 1 e caso 2.3
   int ex3[]   = {5, 10, 3, 2, 7, 8};    // caso 2.2
   int ex4[]   = {5, 10, 3, 2, 14, 12};  // caso 2.4
   int ex5[]   = {8, 3, 21, 16, 27, 9, 18, 29, 10}; // vários casos juntos

   pDArvore arvore = constroiArvore(ex1, 4);
   //constroiArvore(ex1_1, 3);
   // constroiArvore(ex1_3, 3);
   //constroiArvore(ex2, 6);
   //constroiArvore(ex3, 6);
   //constroiArvore(ex4, 6);
 // pDArvore arvore = constroiArvore(ex5, 9);

    //busca
    /*
  printf("Digite um numero para busca: \n");
    void *info;
    info = malloc(sizeof(int));
    scanf("%d", info);
    pNohArvore retorno;
    retorno = buscarInfo(arvore, info, comparaInt);

    if(retorno != NULL || retorno == (int*)info)
      printf("Numero encontrado na arvore\n");
      else
            printf("Numero nao encontrado\n");

            free(info);

*/

 //Exclusão
    printf("Digite um numero para exclusao: \n");
    void *infoDois;
    infoDois = malloc(sizeof(int));
    scanf("%d", infoDois);
    int aux;
     aux = excluirInfo(arvore, infoDois, comparaInt);
printf("Passou aqui final");
            desenhaArvore(arvore, imprimeInt);

            free(infoDois);

           // liberarArvore(arvore);



 }
/*
 void liberarArvore(pDArvore arvore) {
    if (arvore != NULL) {
        liberarArvore(arvore->raiz->esquerda);
        liberarArvore(arvore->raiz->direita);
        free(arvore->raiz->info);
        free(arvore->raiz);
    }
}

*/
