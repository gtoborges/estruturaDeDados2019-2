#include <stdio.h>

void main () {
  int anoInput;
  int proximoHalley;
  int diferenca;
  int anoReferencia=1986;

  scanf("%d", &anoInput);

  if(anoInput > anoReferencia){
    // nextHalley = inputYear - ((inputYear - referenceYear) % 76) + 76;
    diferenca = anoInput - anoReferencia;
    int anos = anoInput - (anoReferencia + diferenca);
    


    if( (diferenca/4) > 365 ){

    }


    printf("%d", proximoHalley);
  } else {
    // nextHalley = inputYear + (((referenceYear - inputYear) % 76) * 76);
    

    printf("%d", proximoHalley);
  }
}