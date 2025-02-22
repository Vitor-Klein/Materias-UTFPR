 #include <stdio.h>
#include "Utils.h"
#include "ArvoreAVL.h"

pDArvore constroiArvore(int dados[], int tam){

    pDArvore arvore = criarArvore(2);
    int i;
    for(i=0; i<tam; i++){
        incluirInfo(arvore, alocaInt(dados[i]),comparaInt);
        desenhaArvore(arvore, imprimeInt);
    }
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



    return arvore;
}


int main(){

   int ex1[] = {5, 10, 3, 7, 6};             // rotacao simples - direita
   int ex2[] = {5, 10, 3, 12, 14};           // rotacao simples - esquerda
   int ex3[] = {5, 10, 3, 7, 8};             // rotacao dupla - esquerda/direita
   int ex4[] = {5, 10, 3, 4, 12, 9, 14, 13}; // rotacao dupla - direita/esquerda
   int ex5[] = {5, 10, 3, 4, 12, 9, 14};     // N�o precisa rotacionar

   pDArvore temporaria ;

   //constroiArvore(ex1, 5);
   //constroiArvore(ex2, 5);
   temporaria = constroiArvore(ex3, 5);
 //temporaria =  constroiArvore(ex4, 8);
   //constroiArvore(ex5, 7);


              //Exclus�o
    printf("Digite um numero para exclusao: \n");
    void *info;
    info = malloc(sizeof(int));
    scanf("%d", info);
    int aux;
     aux = excluirInfo(temporaria, info, comparaInt);

            desenhaArvore(temporaria, imprimeInt);

            free(info);

 }
