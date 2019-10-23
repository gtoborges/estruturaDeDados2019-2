#include <stdio.h>

int main(){

    int lanchonetes, dias;
    int i, j, x;
    int cont=0;

        scanf("%d", &lanchonetes);
               
    int preco[lanchonetes];

        for(i=0; i<lanchonetes; i++){
            scanf("%d", &preco[i]);
        }

        scanf("%d",&dias);

    int moedas[dias];

        for(j=0; j<dias; j++){
            scanf("%d", &moedas[j]);
        }

        for(j=0; j<dias; j++){

            for(i=0; i<lanchonetes;i++){
                
                if(moedas[j] >= preco[i]){
                    cont++;
                }
            }

         printf("\n%d ",cont);
            if(cont >= 0){
                for(x = 0; x<cont; x++){
                    printf("%d ",x+1);
                }
            }
    
            cont=0;
        }
}