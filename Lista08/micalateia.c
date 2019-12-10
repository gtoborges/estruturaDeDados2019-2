#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato Contato;
struct contato{
    char nome[15];
    char telefone[20];
    int qtd_ligacao;
    Contato *proxContato;
};

Contato* lista = NULL; //lista vazia

//cria contato
Contato* criaContato();

//Inserir novo contato
Contato* insereContato(Contato *prox, char nome[], char telefone[], int qtd_ligacao);

//Remover contato da lista
void removerContato(Contato *lista, char nome[]);

//Registrar quem da lista de contatos existente, fez uma ligação
void registraLigacao(Contato *Lista, char nome[]);

//Ordenar lista por quem ligou mais vezes
void ordenaListaQtdLigacao(Contato *c);

//Copia a lista para uma nova lista, reordenando-a
Contato* copiarListaOrdenando(Contato* Lista);

void imprimir(Contato *Lista);

Contato* buscarContato(Contato* Lista, char nome[]);

int main (){
    char tipo, nome[15]; 
    char telefone[20]; 
    int qtd_ligacao = 0;

    strcpy(nome, "Ooloneia");
    strcpy(telefone, "4523-4887");
    lista = insereContato(lista, nome, telefone, 299);
    strcpy(nome, "Hermanoteu");
    strcpy(telefone, "4523-2248");
    lista = insereContato(lista, nome, telefone, 300);

    do{
        scanf("%c", &tipo);
        switch(tipo)
        {
            case 'I':
            scanf("%s %s %d", &nome, &telefone, &qtd_ligacao);
            lista = insereContato(lista ,nome, telefone, qtd_ligacao);
            break;

            case 'R':
            scanf("%s", &nome);
            removerContato(lista, nome);
            break;

            case 'L':
            scanf("%s", &nome);
            registraLigacao(lista, nome);
            break;

        }
    }while(tipo!='F');
    
    // imprimir(lista);

    Contato *NovaLista = NULL;
    NovaLista = copiarListaOrdenando(lista);

    // printf("\n\nNova Lista");
    imprimir(NovaLista);

    return 0;
};

Contato* criaContato(){
    Contato *contato = (Contato*)malloc(sizeof(Contato));
    return contato;
}

Contato* copiarListaOrdenando(Contato* Lista){
  Contato *c = Lista;

  Contato *NovaLista = NULL;

  while(c != NULL){
    NovaLista = insereContato(NovaLista, c->nome, c->telefone, c->qtd_ligacao);
    c = c->proxContato;
  };

  return NovaLista;
}

Contato* insereContato(Contato *Lista, char nome[], char telefone[], int qtd_ligacao){
    Contato *contato = criaContato(); 

    strcpy(contato->nome,nome);
    strcpy(contato->telefone, telefone);
    contato->qtd_ligacao = qtd_ligacao;
    contato->proxContato = NULL;

    if(Lista == NULL){
        Lista = contato;
    }else{ 
        Contato *temp;
        temp = Lista;
        if(Lista->qtd_ligacao < contato->qtd_ligacao){
            contato->proxContato = Lista;
            Lista = contato;
            return Lista;
        }           
        while(temp->proxContato != NULL){
            if(temp->qtd_ligacao <= contato->qtd_ligacao){
                contato->proxContato = temp->proxContato;
                break;
            }
            temp = temp->proxContato;
        }
        temp->proxContato = contato;
    }

    return Lista;
}

Contato* buscarContato(Contato* Lista, char nome[]){
    Contato* temp = Lista;
    while (strcmp(temp->nome, nome) != 0){
        temp = temp->proxContato;
    }
    
    return temp;
}

void removerContato(Contato *Lista, char nome[]){

    Contato *temp = buscarContato(lista, nome);

    Contato *anteriorTemp;
    anteriorTemp = lista;
    while( anteriorTemp->proxContato != temp ){
        anteriorTemp = anteriorTemp->proxContato;
    }

    anteriorTemp->proxContato = temp->proxContato;
    free(temp);
}

void registraLigacao(Contato *Lista, char nome[]){
    Contato *temp = buscarContato(lista, nome);
    temp->qtd_ligacao = temp->qtd_ligacao +1;
}

void imprimir(Contato *Lista){
    Contato* aux = Lista;
    while(aux !=NULL){
        printf("%s - %s %d\n", aux->nome, aux->telefone, aux->qtd_ligacao);
        aux=aux->proxContato;
    }
}