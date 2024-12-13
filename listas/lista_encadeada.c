#include <stdio.h>
#include <stdlib.h>

struct sNode{
  int dado;
  struct sNode *prox;
};


struct sNode *ini = NULL, *fim = NULL;

void inserir(int dado){
  struct sNode *aux = malloc(sizeof(struct sNode));
  aux->dado = dado;
  aux->prox = NULL;
  
  if(ini == NULL){
    ini = aux;
    fim = aux;
  }
  else{
    fim->prox = aux;
    fim = aux;
  }
}

void inserir_ini(int dado){
  struct sNode *aux = malloc(sizeof(struct sNode));
  aux->dado = dado;
  aux->prox = ini;
  ini = aux;

  if(fim == NULL){
    fim = aux;
  }
}

struct sNode *buscar(int dado){
  struct sNode *aux = ini;
  while(aux != NULL){
    if(aux->dado == dado){
      return aux;
    }
    aux = aux->prox;
  }
  return NULL;
}

void remover(int dado){
  struct sNode *aux = ini;
  struct sNode *ant = NULL;
  while (aux != NULL){
    if(aux->dado == dado){ 
      if(aux == ini){ //se for o primeiro elemento da lista
        ini = aux->prox;
      }
      else if (aux == fim){ //se for o ultimo da lista
        ant->prox = aux->prox;
      }
      else{
        ant->prox = aux->prox;
      }
      free(aux);
      return;
     }
    ant = aux;
    aux = aux->prox;
  }
}