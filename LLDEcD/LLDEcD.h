/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LLDEcD.h
 * Author: wsa
 *
 * Created on 12 de Novembro de 2019, 15:49
 */

#ifndef LLDECD_H
#define LLDECD_H

#ifdef __cplusplus
extern "C" {
#endif
    
#define SUCESSO        1
#define FALHA         -1
#define CHAVE_INVALIDA 0

typedef
   struct Celula*    ApontadorCelula;
typedef
   struct Descritor* ApontadorDescritor;

struct Descritor {
     ApontadorCelula prim;
     int             tam;
     ApontadorCelula ult;
};

struct Celula {
     ApontadorCelula ant;
     int             chave; 
     int             dado;
     ApontadorCelula prox;
};

ApontadorDescritor d;
int                intChave;
int                intValor;

/*
Prototipos das funcoes...
*/
int                CriarLista        (ApontadorDescritor* d);
int                CriarListaChave   (ApontadorDescritor* d, int chave, int valor);
int                InsInicio         (ApontadorDescritor* d, int chave, int valor);
int                InsFinal          (ApontadorDescritor* d, int chave, int valor);
int                InsOrdem          (ApontadorDescritor* d, int chave, int valor);
void               MostraLista       (ApontadorDescritor* d);
int                RemInicio         (ApontadorDescritor* d); 
int                RemFinal          (ApontadorDescritor* d);
int                TamLista          (ApontadorDescritor* d);
int                RemChave          (ApontadorDescritor* d, int chave);
ApontadorDescritor ConcatListas      (ApontadorDescritor d1, ApontadorDescritor d2);


#ifdef __cplusplus
}
#endif

#endif /* LLDECD_H */

