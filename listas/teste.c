#include <stdio.h>
#include <stdlib.h>

struct Memoria{
  int felicidade;
  struct Memoria *prox;
  struct Memoria *ant;
};

struct Memoria *ini = NULL, *fim = NULL;

void inserir_fim(int dado){
  struct Memoria *aux = malloc(sizeof(struct Memoria));
  aux->felicidade = dado;
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
  struct Memoria *aux = malloc(sizeof(struct Memoria));
  aux->felicidade = dado;
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

struct Memoria *buscar(int dado){
  struct Memoria *aux = ini;
  while(aux != NULL){
    if(aux->felicidade == dado){
      return aux;
    }
    aux = aux->prox;
  }
  return NULL;
}

void remover(int dado){
  struct Memoria *aux = buscar(dado);
  if (aux == NULL){
    return;
  }
  if (ini == fim){
    ini = fim = NULL;
  }
  else if (aux == ini){
    ini = aux->prox;
    ini->ant = NULL;
  }
  else if (aux == fim){
    fim = aux->ant;
    fim->prox = NULL;
  }
  else{
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
  }
  free(aux);
}

void imprimir() {
    struct Memoria *aux = ini;
    while (aux != NULL) {
        printf("%d", aux->felicidade);
        if (aux->prox != NULL) {
            printf(" -> ");
        }
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
  printf("Memórias felizes da Riley:\n");
  inserir_fim(10);
  inserir_fim(20);
  inserir_fim(30);
  inserir_ini(100);
  imprimir();
  remover(30);
  printf("Memória de felicidade removida\n");
  printf("Memórias felizes da Riley:\n");
  imprimir();
  return 0;
}