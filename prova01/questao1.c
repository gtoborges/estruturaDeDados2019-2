#include<stdio.h>

void imprimirMatriz(int array[], int arraySize, int cont, int x, int y);

int main() {

  int n, x, y;

  scanf("%d %d %d", &n, &x, &y);

  int matriz[x][y];
  
  int array[n];

  int i, j, cont=0;

  // for(i=0; i<n; i++){
  //   for(j=0; j<n; j++){
  //     if( i==1 || i==(n-cont) || j==1 || j==(n-cont) ){
  //       matriz[i][j] = x;
  //     } else {
  //       matriz[i][j] = y;
  //     }
  //   }
  //   cont++;
  // }

  // for(i=0; i<n; i++){
  //   for(j=0; j<n; j++){
  //     printf("%d ", matriz[i][j]);
  //   }
  //   printf("\n");
  // }

  imprimirMatriz();

  return 0;
}

void imprimirMatriz(int array[], int arraySize, int cont, int x, int y){
  int i;
  if(cont==0){
    return;
  }
  for(i=0; i<arraySize; i++){
    printf("%d ", x);
  }
  printf("\n");

  imprimirMatriz(array, arraySize, cont-1, x, y);
}

