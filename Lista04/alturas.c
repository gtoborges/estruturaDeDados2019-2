#include <stdio.h>
#include <stdlib.h>
 
 
int **Alocar_matriz_real (int m, int n)
{
  int **v;  /* ponteiro para a matriz */
  int   i;    /* variavel auxiliar      */
  if (m < 1 || n < 1) { /* verifica parametros recebidos */
     printf ("** Erro: Parametro invalido **\n");
     return (NULL);
     }
  /* aloca as linhas da matriz */
  v = (int **) calloc (m, sizeof(int *));
  if (v == NULL) {
     printf ("** Erro: Memoria Insuficiente **");
     return (NULL);
     }
  /* aloca as colunas da matriz */
  for ( i = 0; i < m; i++ ) {
      v[i] = (int*) calloc (n, sizeof(int));
      if (v[i] == NULL) {
         printf ("** Erro: Memoria Insuficiente **");
         return (NULL);
         }
      }
  return (v); /* retorna o ponteiro para a matriz */
}
 
void preencheMatrizAlturas(int **alturasArmazenadas, int casos, int alturas[]){
  int i, j;
  for(i=0; i<casos; i++){

    scanf("%d", &alturas[i]);

    for(j=0; j<alturas[i]; j++){
      scanf("%d", &alturasArmazenadas[i][j]);
    }

  }
 
}
 
void insertion(int **matriz, int alturas[], int caso){
  int i, j, k, aux;
 
  for(i=1; i<alturas[caso]; i++){
    j = i - 1;
    aux = matriz[caso][i];
 
    while(j>=0 && matriz[caso][j]>aux){
      matriz[caso][j+1] = matriz[caso][j];
      j--;
    }
 
    matriz[caso][j+1] = aux;    
  }

}
 
void escreveMatriz(int **alturasArmazenadas, int casos, int alturas[]){
  int i, j;
  for(i=0; i<casos; i++){
    for(j=0; j<alturas[i]; j++){
      printf("%d ", alturasArmazenadas[i][j]);
    }
    printf("\n");
  }
}
 
int main(){
    int qtd, casos;
    int i=0;
    scanf("%d", &casos);
 
    int alturas[casos];
    int **alturasArmazenadas;
    alturasArmazenadas = Alocar_matriz_real(casos, 1000);
 
    preencheMatrizAlturas(alturasArmazenadas, casos, alturas);
 
    for(i=0; i<casos; i++) {
      insertion(alturasArmazenadas, alturas, i);
    }

    escreveMatriz(alturasArmazenadas, casos, alturas); 
}