#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

pilha* criar_pilha() {
  pilha *p;
  p = (pilha*) malloc(sizeof(pilha));
  p->topo = NULL;
  p->n = 0;
  return p;
}

void destruir_pilha(pilha *p) {
  while(p->n > 0) desempilhar(p);
  free(p);
}

//coloca no topo
void empilhar(pilha *p, int x) {
  NoPilha *novo;
  novo = (NoPilha*) malloc(sizeof(NoPilha));
  novo->dado = x;
  novo->prox = p->topo;  //novo aponta para o antigo topo
  p->topo = novo;
  p->n++;
}

//tira do topo; retorna -1 se vazia
int desempilhar(pilha *p) {
  NoPilha *rem;
  int x;
  if(p->topo == NULL) return -1;

  rem = p->topo;
  x = rem->dado;  //guarda antes do free
  p->topo = rem->prox;
  free(rem);
  p->n--;
  return x;
}

int tamanho_pilha(pilha *p) {
  return p->n;
}

void imprimir_pilha(pilha *p) {
  NoPilha *q;
  if(p->n == 0) {
    printf("  (nenhum atendimento)\n");
    return;
  }
  for(q = p->topo; q != NULL; q = q->prox) {
    printf("  [%d]", q->dado);
    if(q == p->topo) printf("  <- topo");
    printf("\n");
  }
}
