#include <stdio.h>
#include <stdlib.h>

struct sNode{
  int dado;
  struct sNode *esq, *dir;
};

struct sNode *raiz = NULL;

struct sNode *inserir(struct sNode *no, int dado){
  if(!no){
    no = malloc(sizeof(struct sNode));
    no->dado = dado;
    no->esq = no->dir = NULL;
  }
  else if(dado > no-dado){
    no->dir = inserir(no->dir, dado);
  }
  else{
    no->esq = inserir(no->esq, dado);
  }
  return no;
}

int main(){

  return 0;
}