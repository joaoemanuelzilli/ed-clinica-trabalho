#include <stdio.h>
#include "lista.h"
#include "circular.h"
#include "fila.h"
#include "pilha.h"

int main() {
  lista *pacientes = criar_lista();
  circular *medicos = criar_escala();
  fila *espera = criar_fila();
  pilha *historico = criar_pilha();

  int op, id;
  char nome[50];
  NoPaciente *pac;

  do {
    printf("\n=== Clinica VidaSaudavel ===\n");
    printf(" 1. Cadastrar paciente\n");
    printf(" 2. Buscar paciente\n");
    printf(" 3. Remover paciente\n");
    printf(" 4. Listar pacientes\n");
    printf(" 5. Adicionar medico ao plantao\n");
    printf(" 6. Avancar plantao\n");
    printf(" 7. Remover medico de plantao\n");
    printf(" 8. Listar escala\n");
    printf(" 9. Colocar paciente na fila\n");
    printf("10. Ver fila de espera\n");
    printf("11. Atender proximo\n");
    printf("12. Desfazer ultimo atendimento\n");
    printf("13. Ver historico\n");
    printf(" 0. Sair\n");
    printf("Opcao: ");
    if(scanf("%d", &op) != 1) break;

    switch(op) {
      case 1:
        printf("ID: ");
        scanf("%d", &id);
        printf("Nome: ");
        scanf(" %49[^\n]", nome);
        if(inserir_paciente(pacientes, id, nome)) printf("Paciente cadastrado.\n");
        else printf("Ja existe paciente com esse ID.\n");
        break;
      case 2:
        printf("ID: ");
        scanf("%d", &id);
        pac = buscar_paciente(pacientes, id);
        if(pac != NULL) printf("Encontrado: %s\n", pac->nome);
        else printf("Paciente nao encontrado.\n");
        break;
      case 3:
        printf("ID: ");
        scanf("%d", &id);
        if(remover_paciente(pacientes, id)) printf("Paciente removido.\n");
        else printf("Paciente nao encontrado.\n");
        break;
      case 4:
        imprimir_lista(pacientes);
        break;
      case 5:
        printf("Nome do medico: ");
        scanf(" %49[^\n]", nome);
        inserir_medico(medicos, nome);
        printf("Medico adicionado a escala.\n");
        break;
      case 6:
        avancar(medicos);
        if(medico_atual(medicos) != NULL) printf("Agora de plantao: %s\n", medico_atual(medicos));
        else printf("Nenhum medico na escala.\n");
        break;
      case 7:
        if(remover_atual(medicos)) printf("Medico removido da escala.\n");
        else printf("Nenhum medico na escala.\n");
        break;
      case 8:
        imprimir_escala(medicos);
        break;
      case 9:
        printf("ID do paciente: ");
        scanf("%d", &id);
        if(buscar_paciente(pacientes, id) == NULL) {
          printf("Paciente nao cadastrado.\n");
        } else {
          enfileirar(espera, id);
          printf("Paciente entrou na fila.\n");
        }
        break;
      case 10:
        imprimir_fila(espera);
        break;
      case 11:
        if(medico_atual(medicos) == NULL) {
          printf("Nao ha medico de plantao.\n");
        } else if(tamanho_fila(espera) == 0) {
          printf("Fila vazia.\n");
        } else {
          id = desenfileirar(espera);  //sai da fila...
          empilhar(historico, id);     //...entra na pilha
          printf("Paciente %d atendido por %s.\n", id, medico_atual(medicos));
        }
        break;
      case 12:
        if(tamanho_pilha(historico) == 0) {
          printf("Nada para desfazer.\n");
        } else {
          id = desempilhar(historico);  //sai da pilha...
          enfileirar(espera, id);       //...volta para a fila
          printf("Atendimento do paciente %d desfeito. Voltou para a fila.\n", id);
        }
        break;
      case 13:
        imprimir_pilha(historico);
        break;
      case 0:
        printf("Saindo...\n");
        break;
      default:
        printf("Opcao invalida.\n");
    }
  } while(op != 0);

  destruir_lista(pacientes);
  destruir_escala(medicos);
  destruir_fila(espera);
  destruir_pilha(historico);

  return 0;
}
