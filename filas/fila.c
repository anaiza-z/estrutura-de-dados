#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void enqueue(int dado){
  if(pos<MAX){
    l[pos++] = dado;
  }
  else{
    printf("A fila está cheia");
  }
}

int getFront(){
  if(pos){
    return l[0];
  }
  else{
    printf("Não há elemento no início");
    exit(1);
  }
}

int dequeue(){
  if(pos){
    int first = l[0];
    for(int i = 0; i < pos-1; i++){
      l[i] = l[i+1];  
    }
    pos--;
    return first;
  }
  else{
    printf("A fila está vazia");
    exit(1);
  }
}

int tamanho(){
  return pos;
}

void imprimir(){
  printf("F[ ");
  for(int i = 0; i < pos; i++){
    printf("%d ", l[i]);
  }
  printf("]\n");
}

int main(){
  enqueue(10);
  printf("Tem %d elemento(s) na fila:\n", tamanho());
  imprimir();
  enqueue(20);
  printf("Tem %d elemento(s) na fila:\n", tamanho());
  imprimir();
  enqueue(30);
  printf("Tem %d elemento(s) na fila:\n", tamanho());
  imprimir();
  printf("O primeiro elemento é: %d\n", getFront());
  dequeue();
  imprimir();
  dequeue();
  imprimir();
  dequeue();
  imprimir();
  printf("O primeiro elemento é: %d\n", getFront());
  printf("O início é: %d\n", getFront());
  return 0;
}