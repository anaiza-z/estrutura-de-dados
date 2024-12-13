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
    for (int i = 0; string[i] != '\0'; i++) {
        char ch = string[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (pos == 0) {
                return 0;
            }
            char topoChar = pop();
            if ((ch == ')' && topoChar != '(') ||
                (ch == ']' && topoChar != '[') ||
                (ch == '}' && topoChar != '{')) {
                return 0; 
            }
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
        printf("Balanceada\n");
    } else {
        printf("Não Balanceada\n");
    }

    return 0;
}
