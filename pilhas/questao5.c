#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char l[MAX];
int pos = 0;

void push(char elemento){
  if(pos<MAX){
    l[pos++] = elemento;
  }
  else{
    printf("A pilha está cheia");
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

int verifica(char *string) {
    int len = strlen(string);

    for (int i = 0; i < len; i++) {
        if (string[i] == '(') {
            push(string[i]); 
        } 
        else if (string[i] == ')') {
            if (pos == 0) {
                return 0;  
            }
            pop();  
        }
    }
    return pos == 0;
}


int main() {
    char string[MAX];

    printf("Digite a expressão: ");
    fgets(string, MAX, stdin);
    string[strcspn(string, "\n")] = '\0';
    if (verifica(string)) {
        printf("OK\n");
    } 
    else {
      printf("Não OK\n");
    }

    return 0;
}



