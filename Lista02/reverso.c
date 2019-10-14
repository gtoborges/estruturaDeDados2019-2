#include <stdio.h>
 
int main(){

  int invert(int n);
  int num;
  scanf("%d", &num);

  invert(num);
 
}

int invert(int num){
 
  int valor = num;

  if(num % 1000 == 0){
    num = num /1000;
  }
  
  if(num % 100 == 0){
    num = num /100;
  }

  if(num % 10 == 0){
    num = num /10;
  }

  int res;    
  if(num==0) {
    return 0;
  }
  if(num > 9) {
    res = num % 10; 
    num = num / 10; 
  } else if(num < 10) {
    res = num;
    num = 0;
  }
  printf("%d", res);

  return invert(num);
}