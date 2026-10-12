#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

fila* criar_fila() {
  fila *f;
  f = (fila*) malloc(sizeof(fila));
  f->inicio = NULL;
  f->fim = NULL;
  f->n = 0;
  return f;
}

void destruir_fila(fila *f) {
  while(f->n > 0) desenfileirar(f);
  free(f);
}

//entra no fim
void enfileirar(fila *f, int x) {
  NoFila *novo;
  novo = (NoFila*) malloc(sizeof(NoFila));
  novo->dado = x;
  novo->prox = NULL;

  if(f->fim == NULL) f->inicio = novo;  //fila estava vazia
  else f->fim->prox = novo;
  f->fim = novo;
  f->n++;
}

//sai do inicio; retorna -1 se vazia
int desenfileirar(fila *f) {
  NoFila *rem;
  int x;
  if(f->inicio == NULL) return -1;

  rem = f->inicio;
  x = rem->dado;
  f->inicio = rem->prox;
  if(f->inicio == NULL) f->fim = NULL;  //ficou vazia
  free(rem);
  f->n--;
  return x;
}

int tamanho_fila(fila *f) {
  return f->n;
}

void imprimir_fila(fila *f) {
  NoFila *p;
  if(f->n == 0) {
    printf("  (fila vazia)\n");
    return;
  }
  printf("  inicio -> ");
  for(p = f->inicio; p != NULL; p = p->prox)
    printf("[%d] ", p->dado);
  printf("<- fim\n");
}
