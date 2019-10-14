#include <stdio.h>

void imprimirNaturais(int a, int n);

int main () {
  
  int n;
  int a=1;

  scanf("%d", &n);
  imprimirNaturais(a, n);

  return 0;

}

void imprimirNaturais(int a, int n) {
  printf("%d ", a);
  if(a == n){
    return;
  } else {
    imprimirNaturais(a+1, n);
  }
}