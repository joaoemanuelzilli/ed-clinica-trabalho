#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

lista* criar_lista() {
  lista *l;
  l = (lista*) malloc(sizeof(lista));
  l->inicio = NULL;
  return l;
}

void destruir_lista(lista *l) {
  NoPaciente *p = l->inicio;
  NoPaciente *aux;
  while(p != NULL) {
    aux = p->prox;
    free(p);
    p = aux;
  }
  free(l);
}

//insere no inicio; retorna 0 se o ID ja existe
int inserir_paciente(lista *l, int id, char *nome) {
  NoPaciente *novo;
  if(buscar_paciente(l, id) != NULL) return 0;

  novo = (NoPaciente*) malloc(sizeof(NoPaciente));
  novo->id = id;
  strcpy(novo->nome, nome);
  novo->prox = l->inicio;
  l->inicio = novo;
  return 1;
}

NoPaciente* buscar_paciente(lista *l, int id) {
  NoPaciente *p;
  for(p = l->inicio; p != NULL; p = p->prox)
    if(p->id == id) return p;
  return NULL;
}

int remover_paciente(lista *l, int id) {
  NoPaciente *ant = NULL;
  NoPaciente *p = l->inicio;
  while(p != NULL && p->id != id) {
    ant = p;
    p = p->prox;
  }
  if(p == NULL) return 0;

  if(ant == NULL) l->inicio = p->prox;  //era o primeiro
  else ant->prox = p->prox;             //"pula" o no removido
  free(p);
  return 1;
}

void imprimir_lista(lista *l) {
  NoPaciente *p;
  if(l->inicio == NULL) printf("  (nenhum paciente)\n");
  for(p = l->inicio; p != NULL; p = p->prox)
    printf("  [%d] %s\n", p->id, p->nome);
}
