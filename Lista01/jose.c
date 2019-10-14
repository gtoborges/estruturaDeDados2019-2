#include <stdio.h>

int main () {

  int unidade, dezena, centena, resultado, i;
  int n1, n2;
  int v[2];
  int r[2];

  scanf("%d %d", &n1, &n2);
  v[0] = n1;
  v[1] = n2;

  for(i=0; i<2; i++){
    unidade = v[i]/ 100 ;   
    dezena =  (v[i]/10) - (unidade *10);
    centena =  v[i] - (dezena * 10) - (unidade * 100);
    resultado = (centena*100) + (dezena*10) + unidade;
    r[i] = resultado;
  }

  if(r[0] > r[1]){
    printf("%d", r[0]);
  } else {
    printf("%d", r[1]);
  }

  return 0;
}