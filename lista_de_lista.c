#include<stdio.h>
#include<stdlib.h>

typedef enum preferencial{
    idoso = 1,
    gestante,
    deficiente,
    normal
}pref;

typedef struct pessoa{
    char nome[100];
    int idade;
    pref p;
    struct pessoa * prox
}pessoa;

typedef struct caixa{
    int numero;
    int qtdPessoas;
    struct pessoa * inicio
}

typedef struct mainList{
    int qtdCaixas;
    struct caixa * inicio;
}
int main(void){
    
}

