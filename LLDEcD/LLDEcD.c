/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "LLDEcD.h"

int CriarLista (ApontadorDescritor* d) {
    (*d) = (ApontadorDescritor) malloc( sizeof(struct Descritor) );
    if ((*d) == NULL) {
       return (FALHA);
    }
    else {
       (*d)->prim = (ApontadorCelula) NULL;
       (*d)->tam  = 0;
       (*d)->ult  = (ApontadorCelula) NULL;
       return (SUCESSO);
    }
}

int CriarListaChave (ApontadorDescritor* d, int chave, int valor) {
    int intResultado;
    
    intResultado = CriarLista(d);
    if (intResultado == FALHA) {
       return (FALHA);
    }
    else {
       return (InsInicio(d, chave, valor));
    }
}

int InsInicio (ApontadorDescritor* d, int chave, int valor) {
    ApontadorCelula q;

    q = (ApontadorCelula) malloc( sizeof(struct Celula) );
    if (q == NULL) {
        return(FALHA);
    }
    else {
        q->chave = chave;
        q->dado  = valor;
        q->ant   = (ApontadorCelula) NULL;
        q->prox  = (*d)->prim;

        if ((*d)->tam == 0) {
           (*d)->prim = q;
           (*d)->ult  = q;
        }
        else {
           ((*d)->prim)->ant = q;
           (*d)->prim        = q;
        }
        (*d)->tam++;
        return(SUCESSO);
    }
}

int InsFinal (ApontadorDescritor* d, int chave, int valor) {
    ApontadorCelula q;

    if ((*d)->tam == 0) {
       return (InsInicio (d, chave, valor)); 
    }
    else {
       q = (ApontadorCelula) malloc( sizeof(struct Celula) );
       if (q == NULL) {
          return (FALHA);
       }
       else {
          q->chave = chave;
          q->dado  = valor;
          q->prox  = (ApontadorCelula) NULL;
          q->ant   = (*d)->ult;

          ((*d)->ult)->prox  = q;
          (*d)->ult          = q;
          (*d)->tam++;

          return (SUCESSO);
       }
    }
}

int InsOrdem (ApontadorDescritor* d, int chave, int valor) {
    ApontadorCelula q, r;

    if ((*d)->tam == 0) {
        return ( InsInicio(d, chave, valor) );
    }
    else {
        if ( chave < ((*d)->prim)->chave ) {
           return ( InsInicio(d, chave, valor) );
        }
        else { 
           if ( chave >= ((*d)->ult)->chave ) {
               return ( InsFinal(d, chave, valor) );
           }
           else {
               q = (ApontadorCelula) malloc( sizeof(struct Celula));
               if (q == NULL) {
                   return (FALHA);
               }
               else {
                  q->chave = chave;
                  q->dado  = valor;
                  r = (*d)->prim;
                  while (r->dado < valor) { 
                        r = r->prox;
                  }
                  q->prox = r;
                  q->ant  = r->ant;

                  r->ant         = q;
                  (q->ant)->prox = q;

                  (*d)->tam++;

                  return(SUCESSO);
               }
           }
        }      
    }
}

void MostraLista (ApontadorDescritor* d) {
     ApontadorCelula r;

     printf("\n\n");
     printf("Lista Linear Duplamente Encadeada com Nó Descritor:\n\n");
     if ((*d)->tam == 0) {
         printf("A lista esta VAZIA.\n\n");
     }
     else {
          r = (*d)->prim;
          while (r->prox != NULL) { 
             printf("[%d, %d] -> ", r->chave, r->dado);
             r = r -> prox;
          }
          printf("[%d, %d]\n\n", r->chave, r->dado);
     }
}

int RemInicio (ApontadorDescritor* d) {
    ApontadorCelula q;

    if ((*d)->tam == 0) {
       return (FALHA);
    }
    else {
       if ((*d)->tam == 1) {
            q          = (*d)->prim;
            (*d)->prim = (ApontadorCelula) NULL;
            (*d)->ult  = (ApontadorCelula) NULL;
         } 
       else {
            q              = (*d)->prim;
            (*d)->prim     = q->prox;
            ((*d)->prim)->ant = (ApontadorCelula) NULL;
       }
       free(q);
       (*d)->tam--;  
       return(SUCESSO);
    }
}

int RemFinal (ApontadorDescritor* d) {
    ApontadorCelula q;

    if ((*d)->tam == 0) {
        return (FALHA);
    }
    else {
       if ((*d)->tam == 1) {
          return ( RemInicio(d) );
       }
       else {
          q                 = (*d)->ult;
          (*d)->ult         = q->ant;
          ((*d)->ult)->prox = (ApontadorCelula) NULL;
          free(q);
          (*d)->tam--;
       }
    }
}

int TamLista(ApontadorDescritor *d) {
    return((*d)->tam);
}

int RemChave (ApontadorDescritor* d, int chave) {
    ApontadorCelula r;

    if ((*d)->tam == 0) {
       return (FALHA);
    }
    else {
        if ((*d)->tam == 1) {
             if ( ((*d)->prim)->chave == chave ) {
                  return( RemInicio(d) );
             }
             else {
                  return(FALHA);
             }
        } 
        else {
           if ( ((*d)->prim)->chave == chave ) {
                return( RemInicio(d) );
           }
           else {
                if ( ((*d)->ult)->chave == chave ) {
                   return( RemFinal(d) );
                }
                else {
                   r = (*d)->prim;
                   while ((r->chave != chave) && (r->prox != NULL)) {
                          r = r->prox;
                   }
                   if (r->prox == NULL) {
                       return(FALHA);
                   }
                   else {
                       (r->ant)->prox = r->prox;
                       (r->prox)->ant = r->ant;
                       free(r);
                       (*d)->tam--;
                       return(SUCESSO);
                   }
               }
           }
       }
    }
}

ApontadorDescritor ConcatListas (ApontadorDescritor d1, ApontadorDescritor d2) {
    //
    // Para o(a) estudante implementar...
    //
    return (ApontadorDescritor) (NULL);
}


