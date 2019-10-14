#include <stdio.h>

void fibonacci(int n, int cont, int antecessor1, int antecessor2);

int main () {
  
  int cont=0;
  int antecessor1=1;
  int antecessor2=0;
  int n;

  scanf("%d", &n);
  fibonacci(n, cont, antecessor1, antecessor2);

  return 0;
}

void fibonacci(int n, int cont, int antecessor1, int antecessor2) {
  if(cont <= n) {
    if(cont == 0) {
      printf("%d ", cont);
      fibonacci(n, cont+1, antecessor1, antecessor2);
    } else {
      printf("%i ", antecessor1+antecessor2);
      fibonacci(n, cont+1, antecessor2, (antecessor1+antecessor2));
    }
  }
}