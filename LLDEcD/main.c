/*---------------------------------------------------------------------------*/
/* UNIVERSIDADE FEDERAL DE GOIÁS - UFG                                       */
/* INSTITUTO DE INFORMÁTICA - INF                                            */
/* Bacharelados do INF/UFG (2019/2)                                                      */
/*                                                                           */
/* Disciplina: Algoritmos e Estruturas de Dados - 1                          */
/* Professor.: Wanderley de Souza Alencar                                    */
/*                                                                           */
/* Observacoes:                                                              */
/*                                                                           */
/* Este programa implementa, de maneira simples e com finalidade didática,   */
/* um conjunto basico de operacoes sobre a estrutura de LISTA LINEAR         */
/* DUPLAMENTE ENCADEADA COM NO DESCRITOR. Sao elas...                        */
/*                                                                           */
/* 0) Criar uma lista vazia                 -> CriarLista                    */
/* 1) Insercao de Celula no inicio da lista -> InsInicio                     */
/* 2) Insercao de Celula no final  da lista -> InsFinal                      */
/* 3) Remocao  de Celula no inicio da lista -> RemInicio                     */
/* 4) Remocao  de Celula no final  da lista -> RemFinal                      */
/* 5) Mostrar, no video, a lista            -> MostraLista                   */
/* 6) Tamanho (numero de NOS) da lista      -> TamLista                      */
/* 7) Insercao de NO por ordem de chave     -> InsOrdem                      */
/* 8) Remocao de NO por chave               -> RemChave                      */
/* 9) Ordenar lista por ordem de chave      -> OrdenaLista                   */
/* A) Concatena duas listas                 -> ConcatLista                   */
/*                                                                           */
/*                                                                           */
/* A estrutura da lista obedece o seguinte lay-out:                          */
/*                                                                           */
/*   numero in-  <---------+               +--> ponteiro para a proxima      */
/*   teiro                 |               |    Celula                       */
/*   (exemplo)  +------+-------+-------+------+                              */
/*              | ant  | chave | dados | prox |                              */
/*              +------+-------+-------+------+                              */
/*                 |                                                         */
/*                 +----> ponteiro para a proxima Celula                     */
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "LLDEcD.h"

int main (void) {
    printf("\n\n\n");
    printf("Lista Linear Duplamente Encadeada com Nó Descritor\n\n\n");
    CriarLista(&d);
    MostraLista(&d);
    do
      {
        puts("Informe o valor da CHAVE para INSERIR NO INICIO ou [0] para finalizar: ");
        scanf("%d",&intChave);
        if (intChave != CHAVE_INVALIDA) {
            puts("Informe o valor do DADO: ");
            scanf("%d",&intValor);
            InsInicio(&d, intChave, intValor);
            MostraLista(&d);
        }
      } while (intChave != CHAVE_INVALIDA);

    do
      {
        puts("Informe o valor da CHAVE para INSERIR NO FINAL ou [0] para finalizar: ");
        scanf("%d",&intChave);
        if (intChave != CHAVE_INVALIDA) {
             puts("Informe o valor do DADO: ");
             scanf("%d",&intValor);
             InsFinal(&d, intChave, intValor);
             MostraLista(&d);
        };
      }
    while (intChave != CHAVE_INVALIDA);

    do                     
      {
        puts("Informe o valor da CHAVE para inserir em ordem ou [0] para finalizar: ");
        scanf("%d",&intChave);
        if (intChave != CHAVE_INVALIDA) {
             puts("Informe o valor do DADO: ");
             scanf("%d",&intValor); 
             InsOrdem(&d, intChave, intValor);
             MostraLista(&d);
        };
      }
    while (intChave != CHAVE_INVALIDA);

    do
      {
        puts("Informe [1] para remover no INICIO, [0] para finalizar: ");
        scanf("%d",&intChave);
        if (intChave != CHAVE_INVALIDA) {
             RemInicio(&d);
             MostraLista(&d);
           };
      }
    while (intChave != CHAVE_INVALIDA);

    do
      {
        puts("Informe [1] para remover no FINAL, [0] para finalizar: ");
        scanf("%d",&intChave);
        if (intChave != CHAVE_INVALIDA) {
             RemFinal(&d);
             MostraLista(&d);
        };
      }
    while (intChave != CHAVE_INVALIDA);

    do
      {
        puts("Informe o valor da CHAVE a ser REMOVIDA ou [0] para finalizar: ");
        scanf("%d",&intChave);
        if (intChave != CHAVE_INVALIDA) {
             RemChave(&d, intChave);
             MostraLista(&d);
        };
      }
    while (intChave != CHAVE_INVALIDA);
    return (EXIT_SUCCESS);
  }
  
  
  



