s/*
 * @Autor do Exercicio : Marcio Alexandre Freire Sindeaux 
 * @Data : 18/10/2018
 * 
 * Jesus, uma pessoa sensata, em Mateus 20:16 diz "Portanto os ultimos serão os primeiro e os primeiros serão os ultimos".
 *
 * Um dia, no paraiso, Jesus tem uma reunião com deus e tenta achar uma forma de automatizar isso, pra não ficar uma 
 * coisa massante na hora que o povo for entrar.
 * 
 * Então Deus contrata voce, outra pessoa sensata, e te diz o seguinte:
 *      ->Me ajude a automatiza a entrada das pessoas no céu, quero que voce faça um programa para isso, levando em 
 * consideração o que eu disse.
 * 
 * Faça o que Deus te pede.(kkkk)
 * 
 * ->RESPOSTA ABAIXO 
 */





#include<stdio.h>
#include<stdlib.h>

typedef struct mainStack{
    struct dado * inicio;
    int qtdDados;
}mainStack;

typedef struct dado{
    char nome[100];
    struct dado * prox;
}dado;

void inserirDado(mainStack *s);
void retirarDado(mainStack *s);
void mostrarDados(dado * d,int c);
mainStack * alocaPilha();
dado * alocaDado();

int main(void){
    int opc= -1;
    mainStack * s = alocaPilha();
	while(opc != 0){
        printf("[1] Colocar pessoa \n");
        printf("[2] Chamar pessoas\n");
        printf("[3] Mostrar pessoas na 'Lista'\n");
        printf("[0] Sair\t");
        scanf("%d",&opc);
        fflush(stdin);
        switch(opc){
            case 0:
                /*
                 * Caso a opção seja 0, ele infelismente não pode cair no caso 'default', Ele tem que seguir
                 * o fluxo, sem cair em menhum caso, para no final, a verifcação ser efetuda no laço 'while'
                 * e o proprio sistema se desligar
                 */
            break;
            case 1:
                inserirDado(s);
            break;
            case 2:
                retirarDado(s);
            break;
            case 3:
                mostrarDados(s->inicio,0);
            break;
	    case 4 :
		printf("\n\nExistem %d pessoas na lista ",l->qtdDados);
	    break;
            default:
                printf("\n\nNumero Inserido Invalido\n\n");
            break;
        }
    }

}
void inserirDado(mainStack *s){
    dado * d = alocaDado();
    printf("\n\nDigite o nome da pessoa : ");
    fflush(stdin);
    fgets(d->nome,100,stdin);
    d->prox = s->inicio;
    s->inicio = d;
    s->qtdDados++;
}

void retirarDado(mainStack *s){
    if(s->inicio != NULL){
        dado * aux = s->inicio;
        printf("\n\n CHAMANDO \t %s\n\n",aux->nome);
        s->inicio = aux->prox;
        free(aux);
		s->qtdDados--;
    }else{
        printf("\nLista sem ninguem \n");
    }
}

void mostrarDados(dado * d,int c){
    if(d == NULL){
        if(c == 0){
            printf("\n\nNenhuma pessoa na lista\n\n");
        }else{
            printf("\n\nFim da Lista\n\n");
        }
    }else{
        printf("\n--------------------------------------\n");
        printf("Nome : %s",d->nome);
        c++;
        mostrarDados(d->prox,c);
    }
}

mainStack * alocaPilha(){
    mainStack * s = (mainStack*)malloc(sizeof(mainStack));
    if(!s){
        printf("\n\nSistema não pode alocar memória");
        exit(1);
    }
    s->inicio = NULL;
    s->qtdDados = 0;
    return(s);
}

dado * alocaDado(){
    dado * d = (dado*)malloc(sizeof(dado));
    if(!d){
        printf("\n\nSistema não pode alocar memória");
        exit(1);
    }
    d->prox = NULL;
    return(d);
}
