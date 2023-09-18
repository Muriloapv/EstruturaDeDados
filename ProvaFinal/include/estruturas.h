#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct Tarefa {
    char descricao[100];
    int prioridade;
    struct Tarefa *proximo;
} Tarefa;

typedef struct Fila {
    Tarefa *inicio;
    Tarefa *fim;
} Fila;

typedef struct Pilha {
    Tarefa *topo;
} Pilha;

// Protótipos de funções
Fila *inicializarFila();
void enfileirar(Fila *f, char *desc, int prio);
Tarefa *desenfileirar(Fila *f);
Pilha *inicializarPilha();
void empilhar(Pilha *p, char *desc, int prio);
Tarefa *desempilhar(Pilha *p);

#endif
