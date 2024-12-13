#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sFILA{
  struct sNODE *ini, *fim;
};

typedef struct sFILA FILA;

void criar(FILA *fi){
  fi->ini = NULL;  
  fi->fim = NULL; 
}

void apagar(FILA *fi) {
    struct sNODE *aux;
    while (fi->ini != NULL) {
        aux = fi->ini;
        fi->ini = fi->ini->prox;
        free(aux);
    }
    fi->fim = NULL; 
}

void enqueue(FILA *fi, int dado) {
    struct sNODE *novo = malloc(sizeof(struct sNODE));
    novo->dado = dado;
    novo->prox = NULL;

    if (fi->fim == NULL) {  
        fi->ini = novo;
    } else {
        fi->fim->prox = novo;
    }
    fi->fim = novo;
}

int dequeue(FILA *fi) {
    if (fi->ini == NULL) { 
        printf("A fila está vazia!\n");
        return -1;  
    }
    struct sNODE *aux = fi->ini;
    int dado = aux->dado;
    fi->ini = fi->ini->prox;

    if (fi->ini == NULL) {  
        fi->fim = NULL;
    }
    free(aux);
    return dado;
}

int tamanho(FILA *fi) {
    int cont = 0;
    struct sNODE *aux = fi->ini;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void imprimir(FILA *fi) {
    struct sNODE *aux = fi->ini;
    printf("F[ ");
    while (aux != NULL) {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("]\n");
}


int main(void){
    FILA fila1;;
    criar(&fila1);
    enqueue(&fila1, 100);
    imprimir(&fila1);
    enqueue(&fila1, 50);
    imprimir(&fila1);
    enqueue(&fila1, 200);
    imprimir(&fila1);
    printf("Dequeue em Fila1 -> %d\n", dequeue(&fila1));
    imprimir(&fila1);
    printf("Dequeue em Fila1 -> %d\n", dequeue(&fila1));
    imprimir(&fila1);
    printf("Dequeue em Fila1 -> %d\n", dequeue(&fila1));
    imprimir(&fila1);
    apagar(&fila1);
    return 0;
}

