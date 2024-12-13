#include <stdio.h>
#include <stdlib.h>

struct sNode{
  int dado;
  struct sNode *prox;
};

struct sNode *ini = NULL, *fim = NULL;

void enqueue(int dado){
  struct sNode *aux = malloc(sizeof(struct sNode));
  aux->dado = dado;
  aux->prox = NULL;
  if(ini==NULL){
    ini = aux;
    fim = aux;
  }
  else{
    fim->prox = aux;
    fim = aux;
  }
}

int dequeue(){
  if(ini!=NULL){
  struct sNode *aux = ini;
  int first = ini->dado;
  ini = aux->prox;
  free(aux);
  return first;
  }
  else{
    printf("A fila está vazia");
  }
}

void imprimir(){
  struct sNode *aux = ini;
  printf("F[ ");
  while (aux != NULL) {
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  printf("]\n");
}

void apagar(){
  
}

int main(){
  enqueue(10);
  imprimir();
  enqueue(20);
  imprimir();
  enqueue(30);
  imprimir();
  dequeue();
  imprimir();
  dequeue();
  imprimir();
  dequeue();
  imprimir();
  return 0;
}