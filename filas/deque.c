#include <stdio.h>
#include <stdlib.h>

struct sNODE {
    int dado;
    struct sNODE *prox;
    struct sNODE *ant;
};

struct sDEQUE {
    struct sNODE *ini;
    struct sNODE *fim;
};

typedef struct sDEQUE DEQUE;

void criar(DEQUE *dq) {
    dq->ini = NULL;
    dq->fim = NULL;
}

void inserir_ini(DEQUE *dq, int dado) {
    struct sNODE *novo = malloc(sizeof(struct sNODE));
    novo->dado = dado;
    novo->ant = NULL;
    novo->prox = dq->ini;
    if (dq->ini == NULL){  
        dq->fim = novo;
    } 
    else {
        dq->ini->ant = novo;
    }
    dq->ini = novo;
}

void inserir_fim(DEQUE *dq, int dado) {
    struct sNODE *novo = malloc(sizeof(struct sNODE));
    novo->dado = dado;
    novo->prox = NULL;
    novo->ant = dq->fim;

    if (dq->fim == NULL){ 
        dq->ini = novo;
    } 
    else{
        dq->fim->prox = novo;
    }
    dq->fim = novo;
}

int remover_ini(DEQUE *dq) {
    if (dq->ini == NULL) {
        printf("O deque está vazio!\n");
        return -1;
    }
    struct sNODE *aux = dq->ini;
    int dado = aux->dado;

    dq->ini = dq->ini->prox;

    if (dq->ini == NULL){  
        dq->fim = NULL;
    } 
    else {
        dq->ini->ant = NULL;
    }

    free(aux);
    return dado;
}

int remover_fim(DEQUE *dq) {
    if (dq->fim == NULL) {  
        printf("O deque está vazio!\n");
        return -1;
    }

    struct sNODE *aux = dq->fim;
    int dado = aux->dado;

    dq->fim = dq->fim->ant;

    if (dq->fim == NULL) {  
        dq->ini = NULL;
    } else {
        dq->fim->prox = NULL;
    }

    free(aux);
    return dado;
}


void imprimir(DEQUE *dq) {
    struct sNODE *aux = dq->ini;
    printf("[ ");
    while (aux != NULL) {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("]\n");
}

void apagar(DEQUE *dq) {
    struct sNODE *aux;
    while (dq->ini != NULL) {
        aux = dq->ini;
        dq->ini = dq->ini->prox;
        free(aux);
    }
    dq->fim = NULL;
}

int main() {
    DEQUE deque;
    criar(&deque);

    inserir_ini(&deque, 10);
    inserir_fim(&deque, 20);
    inserir_ini(&deque, 5);
    inserir_fim(&deque, 30);
    inserir_ini(&deque, 70);
    printf("Deque após inserções: ");
    imprimir(&deque);
    printf("Remover do início: %d\n", remover_ini(&deque));
    printf("Remover do fim: %d\n", remover_fim(&deque));
    printf("Deque atualizado: ");
    imprimir(&deque);
    apagar(&deque);
    printf("Deque após ser apagado: ");
    imprimir(&deque);
    return 0;
}
