#include<stdio.h>

void insertion(int array[], int n);
void insertionRecursivo(int array[], int n);

int main() {

  int array[] = { 10, 3, 5, 1, 4, 2, 9, 7, 8, 6 };
  int n, i;

  n = sizeof(array) / sizeof(array[0]);

  for(i=0; i<n; i++){
    printf("%d ", array[i]);
  }

  printf("\n");

  insertionRecursivo(array, n);
  // insertion(array, n);


  for(i=0; i<n; i++){
    printf("%d ", array[i]);
  }

  return 0;
}

void insertion(int array[], int n) {

  int i, j, k, aux;
  for(i=1; i<n; i++){
    aux = array[i];
    j = i-1;

    while(j>=0 && array[j]>aux){
      array[j+1] = array[j];
      j--;
    }

    array[j+1] = aux;
    for(k=0; k<n; k++){
      printf("%d ", array[k]);
    }
    printf("\n");
  }

}

void insertionRecursivo(int array[], int n) {

  if (n<=1){
    return;
  }

  insertionRecursivo(array, n-1);

  int aux = array[n-1];
  int j = n-2;

  while(j>=0 && array[j] > aux){
    array[j+1] = array[j];
    j--;
  }

  array[j+1] = aux;
}