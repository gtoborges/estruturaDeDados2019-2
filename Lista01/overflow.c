#include <stdio.h>

int main(){

    int n1, n2, N, resultado;
    char C;

      scanf("%d", &N);
      scanf("%d %c %d", &n1, &C, &n2);
    
    if (C=='+'){
      resultado = n1 + n2;
      if(resultado > N ){
        printf("overflow");
      }else{
        printf("no overflow");
      }
    } else if(C=='x'){
      resultado = n1*n2;
      if(resultado>N){
        printf("overflow ");
      }else{
        printf("no overflow");
      }
    }

    return 0;
}