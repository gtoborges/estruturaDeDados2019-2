#include <stdio.h>
#include <stdlib.h>

void insertionAsc(int vetor[], int tam){
	int i, j, aux;

	for(i=1; i<tam; i++){
		aux = vetor[i];    
		j = i - 1;

		while(j>=0  && vetor[j]> aux){
			vetor[j+1] = vetor[j];
			j--;
		}

		vetor[j+1] = aux;
	}
}

void insertionDesc(int vetor[], int tam){
	int i, j, aux;

	for(i=1; i<tam; i++){
		aux = vetor[i];    
		j = i - 1;

		while(j>=0  && vetor[j] < aux){
			vetor[j+1] = vetor[j];
			j--;
		}

		vetor[j+1] = aux;
	}
}

int *alocaVetor(int num_componentes){
	int *v; //definindo o ponteiro v

  if (num_componentes < 1) { /* verifica parametros recebidos */
		printf ("** Erro: Parametro invalido **\n");
 		return (NULL);
 	}
 
  v = (int *) malloc(num_componentes * sizeof(int));

  return (v);
}


int main(){

	int qtd, i;
	int contP=0;
	int contI=0;
	scanf("%d", &qtd);

	// int *vetor;
	// int *vetPar;
	// int *vetImpar;

	// vetor = alocaVetor(100);
	// vetPar = alocaVetor(100);
	// vetImpar = alocaVetor(100);

	int vetor[100];
	int vetPar[100];
	int vetImpar[100];

	for(i=0;i<qtd;i++){
		scanf("%d", &vetor[i]);
	}
    
	for(i=0;i<qtd;i++){
		if(vetor[i] % 2 == 0 ){
			contP++;
			vetPar[contP-1] = vetor[i];
		}    
	}

	insertionAsc(vetPar, contP);

	for(i=0;i<qtd;i++){
		if(vetor[i] % 2 != 0 ){
			contI++;
			vetImpar[contI-1] = vetor[i];
		}
	}

	insertionDesc(vetImpar, contI);
   	 
	for(i=0; i<contP ;i++){
		printf("%d ", vetPar[i]);
	}
        	
	if(contP !=0){
		printf("\n");
	}

	for(i=0; i<contI ;i++){
		printf("%d ", vetImpar[i]);
	}
}
