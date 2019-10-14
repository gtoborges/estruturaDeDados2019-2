#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int m, n;    
    int i, j, k ;
    char op;

    scanf("%d", &m);
    scanf("%d", &n);

    int matrix1[m][n];
    int matrix2[m][n];
    int res[m][n];
    int temp;
    int linha, coluna;

    for( i =0 ; i< m ; i++){
      for( j = 0 ; j<n; j++){
        scanf("%d", &matrix1[i][j]);
      }
    }

    scanf(" %c", &op);
  
    for( i =0 ; i< m ; i++){
      for( j = 0 ; j<n; j++){
        scanf("%d", &matrix2[i][j]);
      }
    }
    
    if (op == '+'){
      for( i =0 ; i< m ; i++){
        for( j = 0 ; j<n; j++){
          res[i][j] = matrix1[i][j] + matrix2[i][j];
        }  
      }
      for( i = 0 ; i< m ; i++){
        for( j = 0 ; j<n; j++){
          printf("%d ", res[i][j]);
        }
        printf("\n");
      }
    } else if (op == 'x' && m == n) {
      for( i = 0 ; i< m ; i++){                
        for( j = 0 ; j<n; j++){
          temp = 0;
          for(k = 0; k< m; k++){             
            temp = temp + matrix1[i][k] * matrix2 [k][j];
          }
          res[i][j] = temp;
        }
      }
      printf("\n");
      for( i = 0 ; i< m ; i++){
        for( j = 0 ; j<n; j++){
          printf("%d ", res[i][j]);
        }
        printf("\n");
      }
    } else {
      printf("ERROR");
    }

    return 0;
}