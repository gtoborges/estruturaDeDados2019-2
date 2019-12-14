#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct numero Numero;
struct numero {
  char num[15];
  Numero *proxNumero;
};

Numero* criarNumero(){
  Numero *n = (Numero*) malloc(sizeof(Numero));
  return n;
}

Numero* adicionarNumero(Numero *lista, char num[]){
  Numero *n = criarNumero();

  strcpy(n->num, num);
  n->proxNumero = NULL;

  if(lista == NULL){
    lista = n;
  } else {
    Numero *temp = lista;
    while(temp->proxNumero != NULL) {
      temp = temp->proxNumero;
    }
    temp->proxNumero = n;
  }

  return lista;
}

void imprimirLista(Numero *lista){
  Numero *n = lista;
  while(n != NULL){
    printf("%s ", n->num);
    n = n->proxNumero;
  }
}

void verificaNumeros(Numero *n, char k){
  int cont = 0;
  int i;
  for(i=0; i<strlen(n->num); i++){
    if(n->num[i] == k) {
      cont++;
    }
  }
  printf("%d ", cont);

  if(n->proxNumero == NULL){
    return;
  } else {
    verificaNumeros(n->proxNumero, k);
  }
}

int main() {

  Numero *lista = NULL;

  int casos;
  char k;

  scanf("%d", &casos);
  getchar();
  scanf("%c", &k);

  int i;
  char num[15];
  for(i=0; i<casos; i++){
    scanf("%s", num);
    lista = adicionarNumero(lista, num);
  }

  verificaNumeros(lista, k);

  return 0;
}