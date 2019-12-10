 
#define TAMANHO_MAX_PILHA_CHAR 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

    typedef struct pilhaChar PilhaChar;
    
    PilhaChar * pilha_nova_char();
    int pilha_char_vazia(PilhaChar * pilha);
    int pilha_char_cheia(PilhaChar * pilha);
    int pilha_char_push(PilhaChar * pilha, char elemento);
    int pilha_char_pop(PilhaChar * pilha);
    int pilha_char_elemento_topo(PilhaChar * pilha, char * outElemento);
    int pilha_char_check_parentesis(PilhaChar * pilha);
    int pilha_char_esvaziar(PilhaChar * pilha);
    void pilha_char_free(PilhaChar * pilha);
    void pilha_to_string(PilhaChar * pilha);

struct pilhaChar{
    char dados[TAMANHO_MAX_PILHA_CHAR];
    int topo;
};

PilhaChar * pilha_nova_char(){
    PilhaChar * pilha = (PilhaChar*)malloc(sizeof(PilhaChar));
    if(pilha != NULL){
        pilha->topo = 0;
    }
    return pilha;
}
void pilha_char_free(PilhaChar * pilha){
    free(pilha);
}
int pilha_char_vazia(PilhaChar * pilha){
    if(pilha == NULL) return -1;
    
    return !pilha->topo;
}
    
int pilha_char_cheia(PilhaChar * pilha){
    if(pilha == NULL) return -1;
    
    if(pilha->topo == TAMANHO_MAX_PILHA_CHAR){
        return 1;
    }
    
    return 0;
}
    
int pilha_char_push(PilhaChar * pilha, char elemento){
    if(pilha == NULL) return -1;
    
    if(pilha_char_cheia(pilha)) return 0;
    
    pilha->dados[pilha->topo] = elemento;
    pilha->topo++;
    
    return 1;
}
    
int pilha_char_pop(PilhaChar * pilha){
    if(pilha == NULL) return -1;
    
    if(pilha_char_vazia(pilha)) return 0;
    
    pilha->topo--;
    return 1;
}

int pilha_char_esvaziar(PilhaChar * pilha){
    while(!pilha_char_vazia(pilha)){
        int sucesso = pilha_char_pop(pilha);
        if(!sucesso){
            return 0;
        }
    }
    return 1;
}
    
int pilha_char_check_parentesis(PilhaChar * pilha){
    if(pilha == NULL) return -1;
    int i;
    int profundidadeDentroDeParentesis = 0;
    
    for( i = pilha->topo-1; i>=0 ; i--){
        if(profundidadeDentroDeParentesis == 0 && pilha->dados[i] == '(')
        {
            return 0;
        }
        
        if(pilha->dados[i] == ')')
            profundidadeDentroDeParentesis++;
        
        if(pilha->dados[i] == '(')
            profundidadeDentroDeParentesis--;
    }
    
    if(profundidadeDentroDeParentesis != 0) return 0;
    
    return 1;
    
}
    
int main(){
    PilhaChar * pilha = pilha_nova_char();
    
    char palavra[1000];

    fgets(palavra, 1000, stdin);    
  
    int i;
    int length = strlen(palavra); 
    char vetor[length];

    for(i=0; i< length-1; i++){
    
      vetor[i] = palavra[i];

    }

    for(i=0; i< length-1; i++){
  
      if (vetor[i] == '(') {
        pilha_char_push(pilha,'(');
      }

      else if( vetor[i] == ')' ){
         pilha_char_push(pilha,')');
      }
    
    }

    if(pilha_char_check_parentesis(pilha) == 1){
        printf("correta");
    }else{
        printf("incorreta");
    }

  
}