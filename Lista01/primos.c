#include <stdio.h>

int main(){

  int num, q, i, j;
  int cont=0;

  scanf("%d", & q);
  int vetor[q];

  for(i = 0; i < q; i++){
      scanf("%d", &vetor[i]);
  }

  for(i = 0; i< q ; i++){
    for(j = 1; j < vetor[i]; j++ ){
      if(vetor[i] % j == 0){
          cont ++;
      }
    }
    if(cont > 2){
        printf("composto\n");
    }else 
    if(cont <=2){
        printf("primo\n");
    }
    cont=0;
  }
  
  return 0;

}