#include <stdio.h>

int main() {

  int marcas;
  int i,j, qtdR;
  int cont = 0;
  int resultado = 0;

  scanf("%d %d", &qtdR, &marcas);

  int colecionado[qtdR];
  int vetorMarca[qtdR];
    
  for(i=1 ; i<qtdR+1; i++){
  scanf("%d", &colecionado[i]);
  }

  for (i=1 ; i<marcas+1; i++) {
    for (j=1; j< qtdR+1 ; j++) {
      if (colecionado[j] == marcas) {
        cont++;
      }
    }
    vetorMarca[i] = cont;
    marcas++;
    cont=0;
  }

  for (i=1 ; i<marcas+1; i++){
    resultado = resultado + vetorMarca[i];
  }
  printf("%d", resultado);
  return 0;

}