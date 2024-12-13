#include <stdio.h>
#include <stdlib.h>

struct sNode{
  int dado;
  struct sNode *prox;
  struct sNode *ant;
};

struct sNode *ini = NULL, *fim = NULL;

void inserir(int dado){
  struct sNode *aux = malloc(sizeof(struct sNode));
  aux->dado = dado;
  aux->prox = NULL;
  aux->ant = NULL;
  
  if(ini == NULL){
    ini = fim = aux;   
  }
  else{
    fim->prox = aux;
    aux->ant = fim;
    fim = aux;
  }
}

void inserir_ini(int dado){
  struct sNode *aux = malloc(sizeof(struct sNode));
  aux->dado = dado;
  aux->prox = ini;
  aux->ant = NULL;
  
  if(ini != NULL){
    ini->ant = aux;
  }
  
  ini = aux;

  if(fim == NULL){
    fim = aux;
  }
}

struct sNode *buscar(int dado){
  struct sNode *aux = ini;
  while (aux != NULL){
    if(aux->dado == dado){
      return aux;
    }
    aux = aux->prox;
  }
  return NULL;
}

void remover(int dado){
  struct sNode *aux = buscar(dado);
  if(aux == NULL){
    return;
  }
  if(ini == fim){ // se tiver apenas um elemento 
    ini = fim = NULL;
  }
  else if (aux == ini){ // se for o primeiro
    ini = ini->prox;
    ini->ant = NULL;
  }
  else if (aux == fim){ // se for o ultimo
    fim = fim->ant;
    fim->prox = NULL;
  }
  else{
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
  }
  free(aux);
}