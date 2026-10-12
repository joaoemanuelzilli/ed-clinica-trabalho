//Dados: pilha LIFO (historico de atendimentos, guarda o ID do paciente)
typedef struct no_pilha {
  int dado;
  struct no_pilha *prox;
} NoPilha;

typedef struct {
  NoPilha *topo;
  int n;
} pilha;

pilha* criar_pilha();
void destruir_pilha(pilha *p);

void empilhar(pilha *p, int x);
int desempilhar(pilha *p);
int tamanho_pilha(pilha *p);
void imprimir_pilha(pilha *p);
