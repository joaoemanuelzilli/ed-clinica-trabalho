//Dados: lista encadeada simples (cadastro de pacientes)
typedef struct no_paciente {
  int id;
  char nome[50];
  struct no_paciente *prox;
} NoPaciente;

typedef struct {
  NoPaciente *inicio;
} lista;

lista* criar_lista();
void destruir_lista(lista *l);

int inserir_paciente(lista *l, int id, char *nome);
int remover_paciente(lista *l, int id);
NoPaciente* buscar_paciente(lista *l, int id);
void imprimir_lista(lista *l);
