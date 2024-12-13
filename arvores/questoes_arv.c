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

void mostrarFolhas(struct sNODE *no){
    if(no){
        mostrarFolhas(no->esq); 
        if (no->esq == no->dir) {
            printf("%d ", no->dado);
        }
        mostrarFolhas(no->dir); 
    }
}

int getMax(struct sNODE *no){
  if(no){
    while (no->dir != NULL) {
      no = no->dir;
    }
  }
  return no->dado;
}

int getMin(struct sNODE *no){
  if(no){
    while (no->esq != NULL) {
      no = no->esq;
    }
  }
  return no->dado;
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
  printf("Essas são as folhas da árvore: ");
  mostrarFolhas(raiz);
  printf("\n");
  printf("O maior elemento da árvore é: %d\n", getMax(raiz));
  printf("O menor elemento da árvore é: %d\n", getMin(raiz));

  return 0;
}



