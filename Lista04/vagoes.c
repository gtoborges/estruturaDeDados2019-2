#include <stdio.h>
#include <stdlib.h>

int **Alocar_matriz_real (int m, int n){
   
	int **v;  /* ponteiro para a matriz */
	int   i;	/* variavel auxiliar  	*/
    	if (m < 1 || n < 1) { /* verifica parametros recebidos */
        	printf ("** Erro: Parametro invalido **\n");
        	return (NULL);
    	}
	/* aloca as linhas da matriz */
	v = (int **) calloc (m, sizeof(int *));
    	if (v == NULL) {
        	printf ("** Erro: Memoria Insuficiente **");
        	return (NULL);
    	}
	/* aloca as colunas da matriz */
	for ( i = 0; i < m; i++ ) {
    	v[i] = (int*) calloc (n, sizeof(int));
        	if (v[i] == NULL) {
            	printf ("** Erro: Memoria Insuficiente **");
            	return (NULL);
        	}
	}
	return (v); /* retorna o ponteiro para a matriz */
}

int insertion(int **matriz, int alturas[], int caso){
    
	int i, j, k, aux, cont =0;
 
    	for(i=1; i<alturas[caso]; i++){
        	j = i - 1;
        	aux = matriz[caso][i];
            	while(j>=0 && matriz[caso][j]>aux){
                	matriz[caso][j+1] = matriz[caso][j];
                	j--;
                	cont++;
            	}
 
        	matriz[caso][j+1] = aux;    
    	}
	return cont;
}

int main(){

	int  i, j, cont, qtd, casos;

    	scanf("%d", &casos);
   	 
	int **matrizNumeros;
    
    	matrizNumeros = Alocar_matriz_real(casos, 1000);
   	 
	int vetQtdNumeros[casos];
	int vetCont[casos];

    	for(i=0; i<casos;i++){
        	scanf("%d",&vetQtdNumeros[i]);
            	for(j=0;j<vetQtdNumeros[i];j++){
                	scanf("%d", &matrizNumeros[i][j]);
            	}
    	}

    	for(i=0; i<casos;i++){
        	vetCont[i] = insertion(matrizNumeros, vetQtdNumeros, i );
    	}

    	for(i=0; i<casos;i++){
        	printf("%d",vetCont[i]);
        	printf("\n");
    	}
   	 
    
}
