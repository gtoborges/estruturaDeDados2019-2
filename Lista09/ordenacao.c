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

Frase* ordernarAsc(Frase *lista){
  Frase *j;
  Frase *i = lista->proxFrase;
  char temp[1000];
  char auxFrase[1000];
  
  while(i != NULL){
    Frase *aux = i;
    strcpy(auxFrase, "");
    strcpy(auxFrase, aux->frase);
    j = i->fraseAnterior;

    while(j != NULL && (strcmp(j->frase, aux->frase) > 0) ){
      strcpy(temp, "");
      strcpy(temp, j->frase);
      strcpy(j->frase, aux->frase);
      strcpy(aux->frase, temp);

      j->fraseAnterior;
    }
    
    if(j == NULL){
      j = lista;
      j = j->proxFrase;
    } else {
      j = j->proxFrase;
    }

    strcpy(j->frase, auxFrase);

    i = i->proxFrase;

    printf("\n\nOrdenando lista\n");
    imprimirLista(lista);
  }

  return lista;
}

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
  ordernarAsc(lista);
  printf("\n\nLista ordenada:\n");
  imprimirLista(lista);

  return 0;
}