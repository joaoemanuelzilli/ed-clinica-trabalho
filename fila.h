//Dados: fila FIFO (sala de espera, guarda o ID do paciente)
typedef struct no_fila {
  int dado;
  struct no_fila *prox;
} NoFila;

typedef struct {
  NoFila *inicio;  //de onde sai
  NoFila *fim;     //onde entra
  int n;
} fila;

fila* criar_fila();
void destruir_fila(fila *f);

void enfileirar(fila *f, int x);
int desenfileirar(fila *f);
int tamanho_fila(fila *f);
void imprimir_fila(fila *f);
