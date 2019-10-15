#include<stdio.h>

void insertion(int arr[], int arrSize);

int main () {

  int array[10] = {6, 4, 2, 8, 5, 7, 1, 3, 9, 10};
  int arrSize = sizeof(array) / sizeof(array[0]);

  int i;

  printf("Array desordenado: ");
  for(i=0; i<arrSize; i++){
    printf("%d ", array[i]);
  }
  printf("\n\nArray ordenado: \n");

  insertion(array, arrSize);

  return 0;
}

void insertion(int arr[], int arrSize){
  int i, j, k, aux;

  for(i=1; i<arrSize; i++){
    j = i - 1;
    aux = arr[i];

    while(j>=0 && arr[j]>aux){
      arr[j+1] = arr[j];
      j--;
    }

    arr[j+1] = aux;    
  }
}