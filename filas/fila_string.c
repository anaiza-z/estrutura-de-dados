#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void enqueue(char dado){
  if(pos<MAX){
    l[pos++] = dado;
  }
  else{
    printf("A fila está cheia");
  }
}

char primeiro_cliente(){
  if(pos){
    return l[0];
  }
  else{
    printf("Não há clientes");
    exit(1);
  }
}

char prox_cliente(){
  if(pos){
    return l[0];
  }
  else{
    printf("Não há clientes");
    exit(1);
  }
}

char dequeue(){
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

void menu(){
  printf("1. Adicionar cliente\n2. Atender cliente\n3. Exibir fila de clientes\n4. Mostrar o próximo cliente\n0. Sair\n\n");
  printf("Escolha uma opção: ");
}

int main(){
  char cliente[50];
  int opcao = -1;
  while(opcao!=0){
    menu();
    scanf("%d", &opcao);
    if(opcao==1){
      printf("Digite o nome do cliente: ");
      fgets(cliente, 50, stdin);
      
    }
  }
  return 0;
}