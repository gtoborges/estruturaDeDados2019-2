#include <stdio.h>
#include <math.h>

int main(){

  int q;
  int i;

  scanf("%d", &q);
  int figura[q];
  char letra[q];
  int area[q];
  float pi = 3.14159265;

  //variavel circulo
  int raioC;
  float resC;

  //variaveis elipse
  int raioMaior, raioMenor;
  float resE;

  //variaveis triangulo
  float p;
  float ladoA, ladoB, ladoC;
  float  totalA, totalB, totalC ;
  float resT;

  //variaveis trapezio
  int baseMaior, baseMenor, altura;

  for(i = 0; i<q; i++){
    scanf(" %c", &letra[i]);
    if (letra[i] == 'C') {
      scanf("%d", &raioC);
      resC = pi *raioC * raioC;
      area[i] = round(resC);
    } else if (letra[i] == 'E') {
      scanf("%d", &raioMaior);
      scanf("%d", &raioMenor);
      resE = pi * raioMaior * raioMenor;  
      area[i] =  round(resE);
    } else if (letra[i] == 'T') {
      scanf("%f", &ladoA);
      scanf("%f", &ladoB);
      scanf("%f", &ladoC);

      p = (ladoA + ladoB + ladoC)/2;
      totalA = p - ladoA;
      totalB = p - ladoB;
      totalC = p - ladoC;

      resT = sqrt( p * totalA * totalB * totalC );
      area[i] =  round(resT);
    } else if (letra[i] == 'Z') {
      scanf("%d", &baseMaior);
      scanf("%d", &baseMenor);
      scanf("%d", &altura);
      area[i] = ((baseMaior + baseMenor) * altura)/2;
    }
  }

  for(i = 0; i<q; i++){
    printf("%d\n", area[i]);
  }

  return 0;
}