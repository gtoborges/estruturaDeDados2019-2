#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *v, int tam){

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

int qtd, i, l, k, soma;

    scanf("%d", &qtd);

int vetor[qtd];

        for(i=0; i<qtd; i++){
            scanf("%d", &vetor[i]);
        }

    scanf("%d", &l);
    scanf("%d", &k);

    insertion_sort(vetor, qtd);

    soma = vetor[l-1] + vetor[k-1];
    printf("%d", soma);

}