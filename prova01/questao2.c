#include<stdio.h>

void insertion(int array[], int arraySize);

int numeroDeParesMaximo (int array[], int arraySize);

int main() {

  int t, i, j;
  scanf("%d", &t); // casos de teste

  int numParesMax;

  int n;
  for(i=0; i<t; i++){ 
    scanf("%d", &n); // numero de elementos em cada caso
    int vetor[n];

    for(j=0; j<n; j++){ // recebendo elementos de cada caso
      scanf("%d", &vetor[j]);
    }

    insertion(vetor, n); // ordenação do vetor do enésimo caso

    numParesMax = numeroDeParesMaximo(vetor, n);
    printf("%d", numParesMax);
  }



  return 0;
}

int numeroDeParesMaximo(int array[], int arraySize){

  int i, j;
  int pares[2][arraySize];

  for(i=0; i<arraySize; i++){
    for(j=0; j<i; j++){
      pares[i][j];
    }
  }

}

void insertion(int array[], int arraySize){
  int i, j, aux;
  for(i=1; i<arraySize; i++){
    j = i - 1;
    aux = array[i];

    while(j>=0 && array[j]>aux){
      array[j+1] = array[j];
      j--;
    }

    array[j+1] = aux;    
  }
}