#include "circular.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

circular* criar_escala() {
  circular *c;
  c = (circular*) malloc(sizeof(circular));
  c->atual = NULL;
  return c;
}

void destruir_escala(circular *c) {
  while(remover_atual(c));
  free(c);
}

//insere no fim da vez: depois do ultimo, antes do atual
void inserir_medico(circular *c, char *nome) {
  NoMedico *novo, *ult;
  novo = (NoMedico*) malloc(sizeof(NoMedico));
  strcpy(novo->nome, nome);

  if(c->atual == NULL) {
    novo->prox = novo;  //sozinho: aponta para si mesmo
    c->atual = novo;
    return;
  }
  ult = c->atual;
  while(ult->prox != c->atual) ult = ult->prox;
  ult->prox = novo;
  novo->prox = c->atual;
}

void avancar(circular *c) {
  if(c->atual != NULL) c->atual = c->atual->prox;
}

int remover_atual(circular *c) {
  NoMedico *rem = c->atual;
  NoMedico *ant;
  if(rem == NULL) return 0;

  if(rem->prox == rem) {  //era o unico
    c->atual = NULL;
  } else {
    ant = rem;
    while(ant->prox != rem) ant = ant->prox;
    ant->prox = rem->prox;
    c->atual = rem->prox;  //plantao passa para o proximo
  }
  free(rem);
  return 1;
}

char* medico_atual(circular *c) {
  if(c->atual == NULL) return NULL;
  return c->atual->nome;
}

void imprimir_escala(circular *c) {
  NoMedico *p = c->atual;
  if(p == NULL) {
    printf("  (nenhum medico)\n");
    return;
  }
  do {  //para quando da a volta completa
    printf("  %s", p->nome);
    if(p == c->atual) printf("  <- de plantao");
    printf("\n");
    p = p->prox;
  } while(p != c->atual);
}
