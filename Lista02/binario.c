#include<stdio.h>

void binarioRecursivo(int n);

int main () {

  int n, num, i;
  scanf("%d", &n);
  
  int casos[n];

  for(i=0; i<n; i++){
    scanf("%d", &casos[i]);
  }

  for(i=0; i<n; i++){
    binarioRecursivo(casos[i]);
    printf("\n");
  }

  return 0;
}

void binarioRecursivo(int n){

  if(n == 0){
    printf("0");
    return;
  }
  if(n == 1){
    printf("1");
    return;
  }

  binarioRecursivo(n/2);
  printf("%d", n%2);
  return;
}
