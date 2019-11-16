#include <stdio.h>
#include <string.h>

void insertionSort(int arr[], int arrSize);

typedef struct {
  char nome[30];
  int nota;
} Aluno;

int main() {
  int numAlunos;
  scanf("%d", &numAlunos);

  Aluno alunos[numAlunos];

  int i;
  for(i=0;i<numAlunos;i++) {
    scanf("%s %d", alunos[i].nome, &alunos[i].nota);
  }

  // ordenar alunos por nota e depois por nome
  Aluno aux;
  for(i=1; i<numAlunos; i++) {
    int j = i - 1;
    aux = alunos[i];

    while(j >= 0 && alunos[j].nota<aux.nota) {
      alunos[j+1] = alunos[j];
      j--;
    }
    while(j >= 0 && strcmp(alunos[j].nome, aux.nome ) > 0 && alunos[j].nota == aux.nota) {
      alunos[j+1] = alunos[j];
      j--;
    }

    alunos[j+1] = aux;
  }

  // printf("\n");
  for(i=0;i<numAlunos;i++) {
    if(i!=0) printf("\n");
    printf("%s %d", alunos[i].nome, alunos[i].nota);
  }
  printf(" #reprovado(a)");

  return 0;
}