#include <stdio.h>
#include <stdlib.h>

int retornaPrimo(int num) {
 
    int i, resultado = 0;
        
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                resultado++;
                break;
            }
        }

        if (resultado == 0){
   	        return num;
        }else
            return 0;
}

void insertion(int *v, int tam){

    int i, j, aux;
    
        for(i =1; i< tam; i++){
            aux = v[i];
            j = i - 1;

            while ((j >= 0) && (aux < v[j])){
                v[j+1] = v[j];
                j--;
            }
            v[j+1] = aux;
        }
}

int main(){

    int tam, i, j, res, maior, val;
    
        scanf("%d", &tam);

    int vetor[1000];
    int vetPrimo[1000];

        for(i=0; i<tam;i++){
            scanf("%d", &vetor[i]);
        }
    
        insertion(vetor, tam);

        for(i=0;i<tam;i++){
            maior = vetor[i];
        }

    int cont = 2;

        for(i=1;i<maior+1;){
            res = retornaPrimo(cont);
                if(res != 0){
                    vetPrimo[i] = cont;
                    cont++;
                    i++;
                }else
                    cont++;
        }

        for(i=0;i<tam;i++){
            val = vetor[i];
            printf("%d ", vetPrimo[val]);
            val=0;
        }
}
