//Dados: lista circular (escala de medicos de plantao)
typedef struct no_medico {
  char nome[50];
  struct no_medico *prox;
} NoMedico;

typedef struct {
  NoMedico *atual;  //medico de plantao agora
} circular;

circular* criar_escala();
void destruir_escala(circular *c);

void inserir_medico(circular *c, char *nome);
void avancar(circular *c);
int remover_atual(circular *c);
char* medico_atual(circular *c);
void imprimir_escala(circular *c);
