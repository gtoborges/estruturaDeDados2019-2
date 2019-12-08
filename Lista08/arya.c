#include<stdio.h>
#include<stdlib.h>

typedef struct inimigo Inimigo;

struct inimigo {
  int inimigo;
  Inimigo *proxInimigo;
};

Inimigo* criarInimigo();
Inimigo* adicionarInimigo(Inimigo* lista, int numInimigo, int e);
Inimigo* buscarInimigo(Inimigo* lista, int numInimigo);
Inimigo* excluirInimigo(Inimigo* lista, int numInimigo);
int indexInimigo(Inimigo *lista, int i);
int contarInimigos(Inimigo* lista, int a, int b);
void imprimirInimigos(Inimigo *lista);


int main() {

  int numeroDeInimigosInicial;
  int inimigo;

  Inimigo *lista = NULL;

  scanf("%d", &numeroDeInimigosInicial);
  
  int i, novoInimigo, inimigoVazio = 0;
  for(i=0; i<numeroDeInimigosInicial; i++){
    scanf("%d", &novoInimigo);
    lista = adicionarInimigo(lista, novoInimigo, inimigoVazio);
  }

  char opcao;
  int p, e, r, a, b, x;

  do{
    opcao = getchar();

    switch (opcao)
    {
    case 'I':
      scanf("%d %d", &p, &e);
      lista = adicionarInimigo(lista, p, e);
      printf("inserido %d\n", p);
      break;
    case 'R':
      scanf("%d", &r);
      lista = excluirInimigo(lista, r);
      printf("removido %d\n", r);
      break;
    case 'C':
      scanf("%d %d", &a, &b);
      x = contarInimigos(lista, a, b);
      printf("quantidade %d\n", x);
      break;
    case 'M':
      imprimirInimigos(lista);
      break;
    
    default:
      break;
    }

  } while(opcao != 'F');
  printf("fim");

  return 0;
}

Inimigo* criarInimigo(){
  Inimigo *novoInimigo = (Inimigo*)malloc(sizeof(Inimigo));
  return novoInimigo;
}

Inimigo* adicionarInimigo(Inimigo* lista, int numInimigo, int e){
  Inimigo *novoInimigo = criarInimigo();

  novoInimigo->inimigo = numInimigo;
  novoInimigo->proxInimigo = NULL;

  if(lista == NULL){
    lista = novoInimigo;
  } else {
    Inimigo *temp = lista;
    while(temp->proxInimigo != NULL){
      if(e != 0 && temp->inimigo == e){
        novoInimigo->proxInimigo = temp->proxInimigo;
        break;
      }

      temp = temp->proxInimigo;
    }
    temp->proxInimigo = novoInimigo;
  }

  return lista;
}

Inimigo* buscarInimigo(Inimigo* lista, int numInimigo){
  Inimigo *temp = lista;

  while(temp->inimigo != numInimigo){
    temp = temp->proxInimigo;
  }

  return temp;
}

Inimigo* excluirInimigo(Inimigo* lista, int numInimigo){
  Inimigo *temp = buscarInimigo(lista, numInimigo);

  if(temp == lista){ // CASO A EXCLUSÃO SEJA O PRIMEIRO DA LISTA
    lista = lista->proxInimigo;
    free(temp);
    return lista;
  }

  Inimigo *anteriorTemp = lista;
  while(anteriorTemp->proxInimigo != temp){
    anteriorTemp = anteriorTemp->proxInimigo;
  }

  anteriorTemp->proxInimigo = temp->proxInimigo;
  free(temp);

  return lista;
}

int contarInimigos(Inimigo* lista, int a, int b){
  int indexA = indexInimigo(lista, a);
  int indexB = indexInimigo(lista, b);
  int cont = 0;

  int maior, menor;
  if(indexA > indexB){
    menor = b;
    maior = a;
  } else {
    menor = a;
    maior = b;
  }

  Inimigo *temp = buscarInimigo(lista, menor);

  while((temp->proxInimigo)->inimigo != maior){
    temp = temp->proxInimigo;
    cont++;
    if(temp == NULL) {
      temp = lista;
    }
  }

  return cont;
}

int indexInimigo(Inimigo *lista, int i){
  Inimigo *temp = lista;

  int cont=0;
  while(temp->inimigo != i){
    temp = temp->proxInimigo;
    cont++;
  }

  return cont;
}

void imprimirInimigos(Inimigo *lista){
  Inimigo *inimigo = lista;
  int i = 1;

  printf("lista");
  while(inimigo->proxInimigo != NULL){
    printf(" %d", inimigo->inimigo);
    inimigo = inimigo->proxInimigo;
    i++;
  }
  printf(" %d\n", inimigo->inimigo);
}
