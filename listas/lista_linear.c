#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void inserir(int dado){
    if(pos < MAX){
        l[pos++] = dado;
    }
    else{
        printf("Não foi possível inserir %d, pois a lista está cheia.", dado);
    }
}

int buscar(int dado){
    for(int i = 0; i < pos; i++){
        if(l[i] == dado){
            return i;
        }
    }
    return -1;
}

void remover(int dado){
    int p = buscar(dado);
    if (p == -1){
        return;
    }
    for (int i = p; i < pos -1; i++){
        l[i] = l[i+1];
    }
} 

int main(){
    

    return 0;
}