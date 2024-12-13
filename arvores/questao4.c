#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *esq, *dir;
};

struct sNODE *raiz = NULL;

struct sNODE *inserir(struct sNODE *no, int dado){
  if (!no) {
  no = (struct sNODE*) malloc(sizeof(struct sNODE));
  no->dado = dado;
  no->esq = no->dir = NULL;
  } else if (dado < no->dado)
  no->esq = inserir(no->esq,dado);
  else
  no->dir = inserir(no->dir,dado);

  return no;  
}

void emOrdem(struct sNODE *no){
  if (no) {
  emOrdem(no->esq);
  printf("%d ",no->dado);
  emOrdem(no->dir);
  }
}

void preOrdem(struct sNODE *no){
  if (no) {
  printf("%d ",no->dado);
  preOrdem(no->esq);
  preOrdem(no->dir);
  }
}

void posOrdem(struct sNODE *no){
  if (no) {
  posOrdem(no->esq);
  posOrdem(no->dir);
  printf("%d ",no->dado);
  }
}

int distanciaDaRaiz(struct sNODE *no, int dado){
  int distancia = 0;
  while (no) {
    if (dado == no->dado) {
      return distancia;
    } else if (dado < no->dado) {
        no = no->esq;
   } else {
        no = no->dir;
    }
      distancia++; 
    }
  return -1; 
}

int main(){
  int valores[] = {50, 30, 70, 20, 40, 60, 80};  
  int n = sizeof(valores) / sizeof(valores[0]);   
  for (int i = 0; i < n; i++){
    raiz = inserir(raiz, valores[i]);
  }
  printf("Em ordem: ");
  emOrdem(raiz);
  printf("\n");
  printf("Pré-ordem: ");
  preOrdem(raiz);
  printf("\n");
  printf("Pós-ordem: ");
  posOrdem(raiz);
  printf("\n");

  int elemento = 20;
  int distancia = distanciaDaRaiz(raiz, elemento);

  if (distancia != -1) {
      printf("Distância da raiz até o elemento %d: %d saltos\n", elemento, distancia);
  } else {
      printf("Elemento %d não encontrado na árvore.\n", elemento);
  }

  return 0;
}
