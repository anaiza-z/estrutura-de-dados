#include <stdio.h>
#include <stdlib.h>

struct sPILHA{
  int pos, *arr;
  int MAX;
};

typedef struct sPILHA PILHA;

void criar(PILHA *pi, int tam_MAX){
  pi->pos = -1;  
  pi->MAX = tam_MAX; 
  pi->arr = malloc(tam_MAX * sizeof(int));
}

void apagar(PILHA *pi){
  free(pi->arr);  
  pi->arr = NULL; 
  pi->pos = -1; 
  pi->MAX = 0; 
}

void push(PILHA *pi, int dado) {
    if (pi->pos == pi->MAX - 1) {
        printf("A pilha está cheia\n");
    } 
    else{
        pi->arr[++(pi->pos)] = dado;
    }
}

int pop(PILHA *pi){
    if (pi->pos == -1){
      printf("Não há elementos\n");  
      exit(1);
    } else {
        return pi->arr[(pi->pos)--];
    }
}

int tamanho(PILHA *pi){
    return pi->pos + 1;
}

void imprimir(PILHA *pi){
    if (pi->pos == -1){
        printf("A pilha está vazia\n");
    } 
    else{
        printf("P[ ");
        for(int i = pi->pos; i >=0; i--){
            printf("%d ", pi->arr[i]);
        }
        printf("]\n");
    }
}


int main(void){
    PILHA pilha1;
    criar(&pilha1, 10);
    imprimir(&pilha1);
    push(&pilha1, 100);
    imprimir(&pilha1);
    push(&pilha1, 50);
    imprimir(&pilha1);
    push(&pilha1, 200);
    imprimir(&pilha1);
    printf("Pop em Pilha 1 -> %d\n",pop(&pilha1));
    imprimir(&pilha1);
    printf("Pop em Pilha 1 -> %d\n",pop(&pilha1));
    imprimir(&pilha1);
    printf("Pop em Pilha 1 -> %d\n",pop(&pilha1));
    imprimir(&pilha1);
    apagar(&pilha1);
    return 0;
}

