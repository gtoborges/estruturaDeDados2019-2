/*---------------------------------------------------------------------------*/
/* UNIVERSIDADE FEDERAL DE GOIÁS - UFG                                       */
/* INSTITUTO DE INFORMÁTICA - INF                                            */
/* Bacharelado em Sistemas de Informação                                     */
/*                                                                           */
/* Disciplina: Algoritmos e Estruturas de Dados - 1                          */
/* Professor.: Wanderley de Souza Alencar                                    */
/*                                                                           */
/* Observacoes:                                                              */
/*                                                                           */
/* Este programa implementa, de maneira simples, um conjunto basico de ope-  */
/* racoes sobre a estrutura de FILA, que utiliza a reprepresentação por      */
/* contiguidade, ou seja, um VETOR representa a fila.                        */
/* O tamanho máximo do vetor é dado pela constante:                          */
/*   TAMANHO_MAXIMO_FILA                                                     */
/*                                                                           */
/* A chave de cada célula da fila  está no intervalo 1..N, sendo o valor     */
/* ZERO considerado flag de "chave inválida" -- CHAVE_INVALIDA               */
/*                                                                           */
/* Operações:                                                                */
/*                                                                           */
/* 0) Criar uma fila  vazia                 -> criarFilaVazia                */
/* 1) Criar fila  com uma Celula            -> criarFilaChave                */
/* 1) Insercao de Celula no inicio da fila  -> insInicio                     */
/* 2) Insercao de Celula no final  da fila  -> insFinal                      */
/* 3) Remocao  de Celula no inicio da fila  -> remInicio                     */
/* 4) Remocao  de Celula no final  da fila  -> remFinal                      */
/* 5) Mostrar, no video, a fila             -> mostrarFila                   */
/* 6) Tamanho (numero de NOS) da fila       -> tamFila                       */
/* 7) Insercao de NO por ordem de chave     -> insOrdem                      */
/* 8) Remocao de NO por chave               -> remChave                      */
/* 9) Ordenar fila  por ordem de chave      -> ordenaLista                   */
/* A) Concatena duas filas                  -> concatFilas                   */
/* B) Consulta uma certa chave na fila      -> consultaChave                 */
/* C) Consulta certa posicao da fila        -> consultaPosicao               */
/*                                                                           */
/*                                                                           */
/* A estrutura de cada célula da fila  obedece ao seguinte leiaute:          */
/*                                                                           */
/*                                                                           */
/*              +-------+-------+                                            */
/*              | chave | dado  |                                            */
/*              +-------+-------+                                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define SUCESSO                1
#define FALHA                 -1
#define CHAVE_INVALIDA         0

#define TAMANHO_MAXIMO_FILA    100

/*
 * Representação de uma célula da fila : [<chave>, <dado>], onde a chave pode 
 * estar no intervalo de 1 ao "máximo inteiro" e o valor ZERO é considerado
 * um valor inválido -- flag
 */
typedef struct { 
     unsigned int chave;
     unsigned int dado;
} Celula;  

/*
 * Representação da fila 
 */
typedef struct {
    Celula celulas  [TAMANHO_MAXIMO_FILA];
    unsigned int    tamanho;
} Fila; 

/*
 * Criação da fila ...
 *     Pode-se criar uma fila  inicialmente vazia ou com uma <chave/dado>
 *     já inserida.
 * 
 */
int criarFilaVazia(Fila * fila ) {
    fila ->tamanho = 0;
    return (SUCESSO);
}

int criarFilaChave(Fila * fila , Celula celula) {
    fila ->celulas[0] = celula;
    fila ->tamanho    = 1;
    return (SUCESSO);
}

/*
 * Determina, e retorna, o número de células presentes na fila.
 */
int tamanhoFila(Fila fila ) {
    unsigned int i;
    
    if (fila.tamanho >= 0) { 
       return(fila .tamanho);   
    }
    else {
       return(FALHA);
    }
}

/*
 *  A inserção de uma <chave/dado> pode ocorrer...
 *    - no final da fila : após a última célula.
 */

int insFinal (Fila * fila , Celula celula) {
    unsigned int i;
    Celula auxiliar;
    
    if (fila->tamanho == TAMANHO_MAXIMO_FILA) {
        return(FALHA);                 // Overflow da fila. 
    }
    else { 
       // 
       // Insere a célula recebida após a última célula atualmente
       // presente na fila 
       // 
       fila ->celulas[fila ->tamanho] = celula;
       fila ->tamanho++;
       return(SUCESSO);
    }
}

/*
 *  A remoção de uma <chave/dado> pode ocorrer...
 *    - no início da fila : a primeira célula.
 *   
 *  Observação: A remoção devolve a célula removida ou uma célula com chave 
 *              igual a CHAVE_INVALIDA, indicando erro na remoção. 
 */
Celula remInicio (Fila * fila ) {
    unsigned int i;
    Celula   celulaResultado;
        
    if (fila ->tamanho == 0) {        // A fila está vazia ?
        celulaResultado.chave = CHAVE_INVALIDA;
        return(celulaResultado);
    }
    else {
       // 
       // Remove a primeira célula da fila e atualiza o tamanho desta...
       // 
       celulaResultado = fila ->celulas[0];
       for (i = 0; (i < fila ->tamanho - 1); i++) {
           fila ->celulas[i] = fila ->celulas[i+1];
       } 
       fila ->tamanho--;
       return(celulaResultado);
    }
}

/*
 * Retorna a célula (primeira) cuja chave é igual à solicitada ou 
 * uma célula com chave igual a CHAVE_INVALIDA, indicando que não encontrou a
 * célula desejada na fila. 
 */
Celula consultaChave(Fila fila , Celula celula) {
    unsigned int i;
    
    for (i = 0; (i < fila .tamanho); i++) {
        if (fila .celulas[i].chave == celula.chave) {
            return(fila .celulas[i]);
        }
    }
    celula.chave = CHAVE_INVALIDA;
    return(celula);
}

/*
 * Retorna a célula cuja posição é igual à solicitada ou 
 * uma célula com chave igual a CHAVE_INVALIDA, indicando que não existe a
 * célula desejada na fila . 
 * 
 * A primeira célula está na posição UM.
 */
Celula consultaPosicao(Fila fila , unsigned int intPosicao) {
    
    Celula celulaResultado;
    
    if ((intPosicao > 0) && (intPosicao <= fila .tamanho)) { 
        celulaResultado = fila .celulas[intPosicao - 1];
    }
    else {
        celulaResultado.chave = CHAVE_INVALIDA;
    }
    return(celulaResultado);
}

/*
 * Concatena duas filas, desde que a fila  final não ultrapasse 
 * o tamanho máximo permitido. Neste caso, retorna uma fila  linear
 * "falsa", cujo tamanho é igual a FALHA, indicando que ocorreu um 
 * erro durante a concatenação.
 */

Fila concatFilas(Fila *fila1, Fila *fila2) {
    unsigned int i;
    int          intResultado;
    Celula       celula;
    Fila         filaResultado;
    
    i = criarFilaVazia(&filaResultado);
    if ((fila1->tamanho + fila2->tamanho) > TAMANHO_MAXIMO_FILA) {
        filaResultado.tamanho = FALHA;
        return (filaResultado); 
    }
    else {
        for (i = 0; (i < fila1->tamanho); i++) {
            celula       = consultaPosicao(*fila1,(unsigned int) (i+1));
            intResultado = insFinal(&filaResultado, celula);
            if (intResultado == CHAVE_INVALIDA) {
                filaResultado.tamanho = FALHA;
                return (filaResultado);
            }
        }
        for (i = 0; (i < fila2->tamanho); i++) {
            celula       = consultaPosicao(*fila2,(unsigned int) (i+1));
            intResultado = insFinal(&filaResultado, celula);
            if (intResultado == CHAVE_INVALIDA) {
                filaResultado.tamanho = FALHA;
                return (filaResultado);
            }
        }
    }
}

/*
 * Apresenta, no dispositivo de saída (monitor de vídeo), o valor
 * da <chave> e do <dado> de uma célula recebida como entrada.
 */
void mostrarCelula(Celula celula) {
    printf("Chave......: %u\n", celula.chave);
    printf("Dado.......: %u\n", celula.dado);
}

/*
 * Mostra as células da fila , a partir de sua 'cabeça' até sua 'cauda'.
 */
void mostrarLista(Fila fila) {
    unsigned int i;
    
    if (fila.tamanho == 0) { 
       printf("Atenção: A fila  está vazia.\n");   
    }
    else {
       printf("A fila  linear possui %u elementos.\n\n", fila.tamanho); 
       for (i = 0; (i < fila.tamanho); i++) {
           printf("Elemento nº: %u\n", (i+1)); 
           mostrarCelula(fila.celulas[i]);
       }
    }
}
/*
 * Programa principal: utiliza as funções de fila  linear
 * 
 */
int main(int argc, char** argv) {
    unsigned int i;
    int          intResultado;
    Fila         fila;
    Celula       celula;
    //
    // Cria, inicialmente, uma fila  vazia...
    //
    intResultado =  criarFilaVazia(&fila);
    if (intResultado == FALHA) {
        return(EXIT_FAILURE);
    }
    mostrarLista(fila);
    //
    // Inserção na fila ...
    // 
    printf("Inserção no FINAL da fila :\n");
    printf("Observação: Forneça <chave> igual [0] para finalizar.\n\n");
    do { 
        printf("Chave: ");
        scanf("%u", &celula.chave);
        if (celula.chave != CHAVE_INVALIDA) {
           printf("Dado.: ");
           scanf("%u", &celula.dado);
           intResultado = insFinal(&fila, celula);
           if (intResultado == CHAVE_INVALIDA) {
               printf("Erro: Problema ao inserir no FINAL da fila .\n");
               printf("      Aplicação interrompida por falha.\n");
               return(EXIT_FAILURE);
           }
        }
    } while (celula.chave != CHAVE_INVALIDA);
    mostrarLista(fila);  
    printf("\n\n");
    printf("Remoção de célula no INÍCIO da fila :\n");
    printf("Observação: Digite...   [1] para remover    [0] para finalizar.\n\n");
    do { 
        printf("Operação: ");
        scanf("%u", &celula.chave);
        if (celula.chave != CHAVE_INVALIDA) {
           celula = remInicio(&fila);
           if (celula.chave == CHAVE_INVALIDA) {
               printf("Erro: Problema ao remover no INÍCIO da fila .\n");
               printf("      A fila  está vazia.\n");
               printf("      Aplicação interrompida por falha.\n");
               return(EXIT_FAILURE);
           }
           else {
               printf("Primeira célula da fila  foi removida: \n\n");
               mostrarCelula(celula);
           }
        }
    } while (celula.chave != CHAVE_INVALIDA);
    mostrarLista(fila);     
    printf("\n\n");
    printf("Consulta a fila  por CHAVE:\n");
    printf("Digite o valor da chave desejada ou [0] para finalizar.\n\n");
    do { 
        printf("Chave: ");
        scanf("%u", &celula.chave);
        if (celula.chave != CHAVE_INVALIDA) {
           celula = consultaChave(fila, celula);
           if (celula.chave == CHAVE_INVALIDA) {
               printf("Célula com chave solicitada não está na fila .\n\n");
               celula.chave  = 1; 
           }
           else {
               printf("\n\n");
               printf("Célula com chave solicitada encontrada:\n\n");
               mostrarCelula(celula);
           }
        }
    } while (celula.chave != CHAVE_INVALIDA);

    return (EXIT_SUCCESS);
}

