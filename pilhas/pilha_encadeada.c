#include <stdio.h>
#include <stdlib.h>

struct sNODE{
int dado;
struct sNODE *prox;
};

struct sNODE *topo = NULL;

void push(int elemento){
  struct sNODE *novo = (struct sNODE*)malloc(sizeof(struct sNODE));
  novo->dado = elemento;
  novo->prox = NULL;

  if (!topo){
    topo = novo;
  }
  else{
    novo->prox = topo;
    topo = novo;
  }
}

int getTopo(){
  if(topo){
    return topo->dado;
  }
  else{
    printf("Não há elemento no topo");
    exit(1);
  }
}

int pop(){
  if (topo){
    int dado = topo->dado;
    struct sNODE *tmp = topo;
    topo = topo->prox;
    free(tmp);
    return dado;
  }
  else{
    printf("Não há elementos");
    exit(1);
  }
}

int tamanho(){
  struct sNODE *aux = topo;
  int tam = 0;
  while(aux){
    tam++;
    aux = aux->prox;
  }
  return tam;
}

void imprimir(){
  struct sNODE *aux = topo;
  printf("P[ ");
  while(aux){
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  printf("]\n");
}

void apagar(){
  struct sNODE *aux = topo, *ant = NULL;
  while (aux){
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  topo = NULL;
}

int main(void){
  push(100);
  push(50);
  push(75);
  imprimir();
  printf("O topo é: %d\n", getTopo());
  printf("Pop -> %d\n", pop());
  imprimir();
  printf("Pop -> %d\n", pop());
  imprimir();
  printf("Pop -> %d\n", pop());
  imprimir();
  printf("O topo é: %d\n", getTopo());
  return 0;
}