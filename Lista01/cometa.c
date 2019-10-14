#include <stdio.h>
 
int main () {
  int inputYear;
  int nextHalley;
 
  scanf("%d", &inputYear);
 
  int referenceYear=1986;
  if(inputYear > referenceYear){
    nextHalley = inputYear - ((inputYear - referenceYear) % 76) + 76;
    printf("%d", nextHalley);
  } else {
    nextHalley = inputYear + (((referenceYear - inputYear) % 76) * 76);
    printf("%d", nextHalley);
  }

  return 0;
}