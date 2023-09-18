#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

Fila *inicializarFila() {
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void enfileirar(Fila *f, char *desc, int prio) {
    Tarefa *t = (Tarefa *)malloc(sizeof(Tarefa));
    strcpy(t->descricao, desc);
    t->prioridade = prio;
    t->proximo = NULL;

    if (f->fim) {
        f->fim->proximo = t;
    }
    f->fim = t;

    if (!f->inicio) {
        f->inicio = t;
    }
}

Tarefa *desenfileirar(Fila *f) {
    if (!f->inicio) {
        return NULL;
    }

    Tarefa *t = f->inicio;
    f->inicio = f->inicio->proximo;

    if (!f->inicio) {
        f->fim = NULL;
    }

    return t;
}

Pilha *inicializarPilha() {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void empilhar(Pilha *p, char *desc, int prio) {
    Tarefa *t = (Tarefa *)malloc(sizeof(Tarefa));
    strcpy(t->descricao, desc);
    t->prioridade = prio;
    t->proximo = p->topo;
    p->topo = t;
}

Tarefa *desempilhar(Pilha *p) {
    if (!p->topo) {
        return NULL;
    }

    Tarefa *t = p->topo;
    p->topo = p->topo->proximo;
    return t;
}
