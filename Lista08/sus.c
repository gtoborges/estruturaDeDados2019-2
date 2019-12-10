#include<stdio.h>
#include<stdlib.h>

typedef struct paciente Paciente;

struct paciente {
  int chegada;
  int tempoCritico;
  Paciente *proxPaciente;
};

Paciente* criarPaciente();
Paciente* adicionarPacienteNaFila(Paciente *lista, int chegada, int tempoCritico);
void imprimirFila(Paciente *lista);
int pacientesCriticos(Paciente *lista);


int main () {

  int numeroDePacientes;
  scanf("%d", &numeroDePacientes);

  int i;
  int horas, minutos, tempoCritico, chegada;
  Paciente *lista = NULL;

  for(i=0; i<numeroDePacientes; i++){
    scanf("%d %d %d", &horas, &minutos, &tempoCritico);
    chegada = horas*60 + minutos;
    lista = adicionarPacienteNaFila(lista, chegada, tempoCritico);
  }

  // printf("\n");
  // imprimirFila(lista);
  
  int p = pacientesCriticos(lista);
  printf("%d\n", p);

  return 0;
}

Paciente* criarPaciente(){
  Paciente *p = (Paciente*)malloc(sizeof(Paciente));
  return p;
}

Paciente* adicionarPacienteNaFila(Paciente *lista, int chegada, int tempoCritico){
  Paciente *p = criarPaciente();

  p->chegada = chegada;
  p->tempoCritico = tempoCritico;
  p->proxPaciente = NULL;

  if(lista == NULL){
    lista = p;
  } else {
    Paciente *temp = lista;
    while(temp->proxPaciente != NULL){
      temp = temp->proxPaciente;
    }
    temp->proxPaciente = p;
  }

  return lista;
}

void imprimirFila(Paciente *lista){
  Paciente *p = lista;

  while(p->proxPaciente != NULL){
    printf("Chegada: %d | Tempo critico: %d\n", p->chegada, p->tempoCritico);
    p = p->proxPaciente;
  }
  printf("Chegada: %d | Tempo critico: %d\n", p->chegada, p->tempoCritico);

}

int pacientesCriticos(Paciente *lista){
  Paciente *p = lista;

  int cont = 0;

  int horario = 7*60;
  do{

    if(horario >= p->chegada){
      // printf("\nHorario: %d | Paciente => chegada: %d / tempo critico: %d", horario, p->chegada, (p->tempoCritico+p->chegada));
      if(horario < p->chegada && (p->tempoCritico+p->chegada) > horario){
        // printf("\n\nEMERGÊNCIA!\n\n");
        cont++;
      }

      // printf("\nAtendido!");
      p = p->proxPaciente;
    }
    // printf("\nPassou 30 min!");
    horario += 30;

  }while(p != NULL);

  // printf("\nDeu ruim %d vez(es)", cont);

  return cont;
}
