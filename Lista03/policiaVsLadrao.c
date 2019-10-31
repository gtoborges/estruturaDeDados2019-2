#include <stdio.h>
#include <stdlib.h>

char **Alocar_matriz_real (int m, int n)
{
  char **v;  /* ponteiro para a matriz */
  int   i;    /* variavel auxiliar      */
  if (m < 1 || n < 1) { /* verifica parametros recebidos */
     printf ("** Erro: Parametro invalido **\n");
     return (NULL);
     }
  /* aloca as linhas da matriz */
  v = (char **) calloc (m, sizeof(char *));
  if (v == NULL) {
     printf ("** Erro: Memoria Insuficiente **");
     return (NULL);
     }
  /* aloca as colunas da matriz */
  for ( i = 0; i < m; i++ ) {
      v[i] = (char*) calloc (n, sizeof(char));
      if (v[i] == NULL) {
         printf ("** Erro: Memoria Insuficiente **");
         return (NULL);
         }
      }
  return (v); /* retorna o ponteiro para a matriz */
}

char **Liberar_matriz_real (int m, int n, char **v)
{
  int  i;  /* variavel auxiliar */
  if (v == NULL) return (NULL);
  if (m < 1 || n < 1) {  /* verifica parametros recebidos */
     printf ("** Erro: Parametro invalido **\n");
     return (v);
     }
  for (i=0; i<m; i++) free (v[i]); /* libera as linhas da matriz */
  free (v);      /* libera a matriz */
  return (NULL); /* retorna um ponteiro nulo */
}

void preencherMatriz(char **matriz, int n);
void escreveMatriz(char **matriz, int n);
int policialPegaLadrao(char **matriz, int tamanhoMatriz, int posLinha, int posColuna, int k);

int main(){

  int casos, i, j, linha, coluna, n, k;

  scanf("%d", &casos);

  int respostas[casos];

  for(i=0; i<casos; i++){
    scanf("%d %d", &n, &k);
    getchar();

    char **minimundo;
    minimundo = Alocar_matriz_real(n, n);

    preencherMatriz(minimundo, n);
    // escreveMatriz(minimundo, n);

    
    respostas[i] = 0;

    for(linha=0; linha<n; linha++){
      for(coluna=0; coluna<n; coluna++){
        if(minimundo[linha][coluna] == 'P') {
          respostas[i] += policialPegaLadrao(minimundo, n, linha, coluna, k);
        }
      }
    }
    // Liberar_matriz_real(n, n, minimundo);
  }

  for(j=0; j<casos; j++){
    printf("%d\n", respostas[j]);
  }


  return 0;
}

void preencherMatriz(char **matriz, int n){

  int linha, coluna;
  for(linha=0; linha<n; linha++){
    for(coluna=0; coluna<n; coluna++){
      scanf("%c", &matriz[linha][coluna]);
      getchar();
    }
  }

  return;
}

void escreveMatriz(char **matriz, int n){

  int linha, coluna;

  printf("\n\nmatriz\n\n");
  for(linha=0; linha<n; linha++){
    for(coluna=0; coluna<n; coluna++){
      printf("%c ", matriz[linha][coluna]);
    }
    printf("\n");
  }
  printf("\n\n");

  return;

}

int policialPegaLadrao(char **matriz, int tamanhoMatriz, int posLinha, int posColuna, int k) {

  int ladraoCapturado = 0;

  int i;
  for(i=k; i>0; i--){
    if(posColuna+i < tamanhoMatriz){
      if(matriz[posLinha][posColuna+i] == 'L') {
        matriz[posLinha][posColuna+i] = 'C';
        ladraoCapturado = 1;
        break;
      }
    }
    if(posColuna-i > 0 ){
      if(matriz[posLinha][posColuna-i] == 'L') {
        matriz[posLinha][posColuna-i] = 'C';
        ladraoCapturado = 1;
        break;
      } 
    } 
  }

  // escreveMatriz(matriz, tamanhoMatriz);

  return ladraoCapturado;
}
