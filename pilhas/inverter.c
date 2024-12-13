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

void inverte(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        if (str[i] != ' '){
            push(str[i]);
        } 
        else {
            while (pos!=0){
                printf("%c", pop());
            }
            printf(" ");
        }
    }
    while (pos!=0){
        printf("%c", pop());
    }
    printf("\n");
}

int main(){
    char string[MAX];
    
    printf("Digite a string: ");
    fgets(string, MAX, stdin);
    string[strcspn(string, "\n")] = '\0';
    inverte(string);

    return 0;
}

