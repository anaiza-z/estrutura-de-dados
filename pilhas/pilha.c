#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void push(int elemento){
  if(pos<MAX){
    l[pos++] = elemento;
  }
  else{
    printf("A pilha está cheia");
  }
}

int getTopo(){
  if(pos){
    return l[pos-1];
  }
  else{
    printf("Não há elemento no topo");
    exit(1);
  }
}

int pop(){
  if(pos){
    return l[--pos];
  }
  else{
    printf("A pilha está vazia");
    exit(1);
  }
}

int tamanho(){
  return pos;
}

void imprimir(){
  printf("P[ ");
  for(int i = pos - 1; i >=0; i--){
    printf("%d ", l[i]);
  }
  printf("]\n");
}

void apagar(){
  pos = 0;
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