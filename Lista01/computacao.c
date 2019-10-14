#include <stdio.h>
#include <string.h>

int main () {

  int resto, val, j=0, cont=0;;
  int resultado, numTestes ;
  int escrito[10];
  int i, k;

  scanf("%d", &numTestes);

  int numero[numTestes];

  for(k = 0; k< numTestes; k++){
    scanf("%d", &numero[k]);
  }

  for(k = 0; k< numTestes; k++){
    if (numero[k] == 0) {
      printf("A\n");
    } else if (numero[k] == 1) {
      printf("C\n");
    } else if(numero[k] == 2) {
      printf("G\n");
    } else if(numero[k] == 3) {
      printf("T\n");
    } else {
      resultado = numero[k];
      while(resultado >= 4){
        val =resultado/4;
        resto = resultado % 4;
        resultado = 0;
        resultado = val;
        escrito[j+1]= val;
        escrito[j] = resto;
        cont++;
        j++;
      }

      for (i=cont; i>-1 ; i--) {
        if (escrito[i] == 0) {
          printf("A");
        } else if (escrito[i] == 1) {
          printf("C");
        } else if (escrito[i] == 2) {
          printf("G");
        } else if (escrito[i] == 3) {
          printf("T");
        }
      }
      resultado = 0;
      resto=0;
      cont=0;
      j=0;
      printf("\n");
    }

  }

}