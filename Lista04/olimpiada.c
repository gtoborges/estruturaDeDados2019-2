#include <stdio.h>

typedef struct {
  int pais;
  int ouro;
  int prata;
  int bronze;
} Pais;

int main(){

  int n, m;

  scanf("%d %d", &n, &m);

  Pais paises[n];

  int i, j, k;
  Pais aux;
  for(i=0; i<n; i++){
    paises[i].pais = i+1;
    paises[i].ouro = 0;
    paises[i].prata = 0;
    paises[i].bronze = 0;
  }

  int ouro;
  int prata;
  int bronze;
  for(i=0; i<m; i++){
    scanf("%d %d %d", &ouro, &prata, &bronze);
    paises[ouro-1].ouro++;
    paises[prata-1].prata++;
    paises[bronze-1].bronze++;
  }

  for(i=1; i<n; i++){
    j = i - 1;
    aux = paises[i];


    while(j>=0 && paises[j].ouro<aux.ouro){
      paises[j+1] = paises[j];
      j--;
    }
    while(j>= 0 && paises[j].prata<aux.prata && paises[j].ouro == aux.ouro){
      paises[j+1] = paises[j];
      j--;
    }
    while(j>= 0 && paises[j].bronze<aux.bronze && paises[j].ouro == aux.ouro && paises[j].prata == aux.prata){
      paises[j+1] = paises[j];
      j--;
    }
    while(j>= 0 && paises[j].pais<aux.pais && paises[j].ouro == aux.ouro && paises[j].prata == aux.prata && paises[j].bronze == aux.bronze ){
      paises[j+1] = paises[j];
      j--;
    }
    
    paises[j+1] = aux;
  }

  for(i=0; i<n; i++){
    printf("%d ", paises[i].pais);
  }
  // for(i=0; i<n; i++){
  //   printf("Pais: %d - Ouros: %d / Pratas: %d / Bronze %d\n", paises[i].pais, paises[i].ouro, paises[i].prata, paises[i].bronze);
  // }

}