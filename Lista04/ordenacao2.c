#include <stdio.h>

int insertion( int vetor[], int n ){
  int i,j, aux, cont;
  for(i = 1; i<n ; i++){
    aux = vetor[i];
    j = i-1;

    while( j>=0 &&  vetor[j] > vetor[j+1] ){
      vetor[j+1]= vetor[j];
      j--;
      cont++;
    }
    vetor[j+1] = aux;
    cont++;
  
  }
  return cont;
}

int selection(int vetor[], int max) {
  int i, j, min, aux, cont;
  
  for (i = 0; i < (max - 1); i++) {
    min = i;
    for (j = i+1; j < max; j++) {
      if (vetor[j] < vetor[min]) {       
        min = j;
      }
    }
    if (i != min) {
      aux = vetor[i];
      vetor[i] = vetor[min];
      vetor[min] = aux;
      cont++;
    }
  }

  printf("\nimprimindo cont ( %d ) de dentro da função", cont);
  return cont;
}

int main(){

  int tam, i,j, aux, cont, conts;

  scanf("%d", &tam);
  int vetorInsertion[tam];
  // int vetorSelection[tam];
  
  for (i=0;i<tam;i++){
    scanf("%d",&vetorInsertion[i]);
  }

  // for (i=0;i<tam;i++){
  //   vetorSelection[i] = vetorInsertion[i];
  // }

  // cont = insertion(vetorInsertion, tam);
  // printf("\n%d", cont);

  conts = selection(vetorInsertion, tam);
  printf("\n%d", conts);

  // printf("\n%d, ", cont - conts);

}