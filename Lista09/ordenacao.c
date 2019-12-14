#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct frase Frase;
struct frase{
  Frase *fraseAnterior;
  char frase[1000];
  Frase *proxFrase;
};

Frase* criarFrase(){
  Frase *f = (Frase*)malloc(sizeof(Frase));
  return f;
}

Frase* adicionarFrase(Frase *lista, char f[]){
  Frase *fr = criarFrase();

  fr->fraseAnterior = NULL;
  strcpy(fr->frase, f);
  fr->proxFrase = NULL;

  if(lista == NULL){
    lista = fr;
  } else {
    Frase *temp = lista;

    while(temp->proxFrase != NULL){
      temp = temp->proxFrase;
    }
    
    temp->proxFrase = fr;
    fr->fraseAnterior = temp;
  }

  return lista;
}

void imprimirLista(Frase *lista){
  while(lista != NULL){
    printf("%s\n", lista->frase);
    lista = lista->proxFrase;
  }
}

// void ordenacaoAlfabeticaAsc(Frase *lista){
//   Frase *temp = lista->proxFrase;

//   while(lista != NULL){
//     Frase *i, *j, *aux;
//     i = temp;
//     j = temp->fraseAnterior;
//     aux = 
//   }
// }

// void insertion(int arr[], int arrSize){
//   int i, j, k, aux;

//   for(i=1; i<arrSize; i++){
//     j = i - 1;
//     aux = arr[i];

//     while(j>=0 && arr[j]>aux){
//       arr[j+1] = arr[j];
//       j--;
//     }

//     arr[j+1] = aux;    
//   }
// }

int main() {

  Frase *lista = NULL;

  char f[1000];
  f[0] = '\0';
  int i;

  do{
    if(strlen(f) != 0) lista = adicionarFrase(lista, f);
    // scanf("%s", f);
    // fgets(f, 999, stdin);
    gets(f);

  }while( !(strcmp(f, "ASC") == 0) && !(strcmp(f, "DESC") == 0) );

  imprimirLista(lista);

  return 0;
}