#include <stdio.h>
#include "estruturas.h"

int main() {
    Fila *fila = inicializarFila();
    Pilha *pilha = inicializarPilha();

    // Adicionando tarefas na fila e pilha:
    enfileirar(fila, "Tarefa 1", 1);
    enfileirar(fila, "Tarefa 2", 2);
    empilhar(pilha, "Tarefa Urgente 1", 1);
    empilhar(pilha, "Tarefa Urgente 2", 2);

    // Removendo e mostrando tarefas da fila:
    Tarefa *tf;
    while (tf = desenfileirar(fila)) {
        printf("Tarefa Fila: %s - Prioridade: %d\n", tf->descricao, tf->prioridade);
        free(tf);
    }

    // Removendo e mostrando tarefas da pilha:
    Tarefa *tp;
    while (tp = desempilhar(pilha)) {
        printf("Tarefa Pilha: %s - Prioridade: %d\n", tp->descricao, tp->prioridade);
        free(tp);
    }

    free(fila);
    free(pilha);

    return 0;
}
