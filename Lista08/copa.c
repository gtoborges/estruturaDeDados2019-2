#include <stdio.h>
#include <stdlib.h>
typedef struct elemento * Inicio;

struct elemento{
  int valor;
  struct elemento * proximo;
};

Inicio * new_list(){
    Inicio * inicio = (Inicio*)malloc(sizeof(Inicio));
    if(inicio != NULL){
        *inicio = NULL;
    }
    return inicio;
}

int list_count(Inicio * inicio){
  if(inicio == NULL) return 0;

  if(*inicio == NULL) return 0;

  struct elemento * elementoAtual = *inicio;
  int cont = 0;
  while(elementoAtual != NULL){
    elementoAtual = elementoAtual->proximo;
    cont++;
  }
  return cont;
}

int list_inserir(Inicio * inicio, int novoDado){
    if(inicio == NULL) return 0;

    struct elemento * novoElemento = (struct elemento*)malloc(sizeof(struct elemento));
    if(novoElemento == NULL) return 0;

    novoElemento->proximo = NULL;
    novoElemento->valor = novoDado;

    if((*inicio) == NULL){
        *inicio = novoElemento;
    }
    else{
        struct elemento * elementoAtual = *inicio;

        while(elementoAtual->proximo != NULL){
          elementoAtual = elementoAtual->proximo;
        }

        elementoAtual->proximo = novoElemento;
    }
    return 1;
}

int list_remover_inicio(Inicio * inicio){
  if(inicio == NULL) return 0;

  if(*inicio == NULL) return 0;

  struct elemento * primeiroElemento = *inicio;
  *inicio = primeiroElemento->proximo;
  free(primeiroElemento);
  return 1;
}

int list_remover_meio(Inicio * inicio, int indice){
  if(inicio == NULL) return 0;

     if(*inicio == NULL) return 0;

     if(indice == 0)
        return list_remover_inicio(inicio);

     int cont = 0;

     struct elemento * elementoAtual = *inicio;
     struct elemento * elementoAnterior = *inicio;

     while(1){
         if(cont == indice)
            break;

         if(elementoAtual->proximo == NULL)
            break;

         cont++;
         elementoAnterior = elementoAtual;
         elementoAtual = elementoAtual->proximo;
     }

     if(cont != indice) return 0;

     elementoAnterior->proximo = elementoAtual->proximo;

     free(elementoAtual);
     return 1;
 }

 int * list_to_array(Inicio * inicio, int * outTamanhoVetor){
     if(inicio == NULL || *inicio == NULL) return NULL;

     struct elemento * elementoAtual = *inicio;
     *outTamanhoVetor = list_count(inicio);
     int * vetorGerado = (int*)malloc(*outTamanhoVetor * sizeof(int));
     if(vetorGerado == NULL)
        return NULL;

     int cont = 0;
     while(elementoAtual != NULL){
        vetorGerado[cont] = elementoAtual->valor;
        elementoAtual = elementoAtual->proximo;
        cont++;
     }

     return vetorGerado;
 }

void print_vetor(int * vetor, int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
      int elem = vetor[i];
        if(i == tamanho - 1){
          printf("%d ",elem);
        }else{
            printf("%d ",elem);
        }
    }
}

int main(int argc, char** argv){
    int tam, val;

    scanf("%d", &tam);

    Inicio * inicioDaLista = new_list();
    int i;
    for (i = 0; i < tam; i++){
        scanf("%d", &val);
        int sucesso = list_inserir(inicioDaLista, val);
        if(!sucesso){
            printf("Erro ao inserir elemento\n");
            break;
        }
    }

    //Convertendo lista para vetor
    int tamanhoVetor;
    int * vetor = list_to_array(inicioDaLista,&tamanhoVetor);
    int removes, j;

    scanf("%d", &removes);

    int toRemove[removes];

    for (i = 0; i <removes; i++){
      scanf("%d", &toRemove[i]);
    } 

    for (i = 0; i <removes; i++){
      for(j = 0; j< tamanhoVetor; j++){
          if(vetor[j] == toRemove[i]){
            list_remover_meio(inicioDaLista,j);
            vetor = list_to_array(inicioDaLista,&tamanhoVetor);
          }
      }
    } 
        print_vetor(vetor,tamanhoVetor);

    return (EXIT_SUCCESS);
}