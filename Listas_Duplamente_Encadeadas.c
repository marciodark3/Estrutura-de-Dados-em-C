/*
 *@author : Márcio Alexandre Freire Sindeaux
 *@professor : Filippe Giuliani (IESB)
 *@Date : 06/09/2018
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct mainList{
	int qtdDados;
	struct dado * inicio;
	struct dado * final;
}mainList;
typedef struct dado{
	struct dado * anterior;
	struct dado * proximo;
	int valor;
}dado;

//Prototipação de Funções

dado * alocaDado();
mainList * alocaLista();

void incluirDados(mainList * l);
void mainMostraDados(mainList * l);
void mostrarDadosInicio(dado * first);
void mostrarDadosFinal(dado * last);
void mainRetirarDado(mainList * l);
void retiraDadoInicio(dado * first);
void retiraDadoFinal(dado * last);
//Fim da prototipação 

int main(){
	mainList * s = alocaLista();
	int opc = -1 ;
	while(opc != 0){
		printf("[1] Para incluir dados \n");
		printf("[2] Para mostrar dados \n");
		printf("[3] Para retirar dado\n");
		printf("[0] Para Sair\n");
		scanf("%d",&opc);

		switch(opc){
			case 1:
				incluirDados(s);
			break;
			case 2:
				mainMostraDados(s);
			break;
			case 3:
				mainRetirarDado(s);
			case 0:
				free(s);
				printf("\nDesligando sistema ...\n");
				return(0);
			break; 
			default:
				printf("\n\nValor Não cadastrado\n\n");
		}
	}
}
void retiraDadoFinal(dado * last){
	int p;
	printf("\nDigite o numero que deseja exclouir :\t");
	scanf("%d",&p);
	dado * aux = last;
	while(aux != NULL){
		if(aux->valor == p){
			aux->anterior->proximo = aux->proximo;
			aux->proximo->anterior = aux->anterior;
			printf("\nItém excuido com sucesso \n");
		}
		aux = aux->proximo;
	}
}
void retiraDadoInicio(dado * first){
	int p;
	printf("\nDigite o numero que deseja exclouir :\t");
	scanf("%d",&p);
	dado * aux = first;
	while(aux != NULL){
		if(aux->valor == p){
			aux->anterior->proximo = aux->proximo;
			aux->proximo->anterior = aux->anterior;
			printf("\nItém excuido com sucesso \n");
		}
		aux = aux->proximo;
	}

}
void mainRetirarDado(mainList * l){
	int esc;
	printf("[1] Para Comecar a buscar pelo inicio\n");
	printf("[2] Para Comecar a buscar pelo final\n");
	scanf("%d",&esc);
	if(esc == 1){
		retiraDadoInicio(l->inicio);
	}else if(esc == 2){
		retiraDadoFinal(l->final);
	}else{
		printf("\n\nNumero Digitado Invalido \n\n");
	}
}
void mostrarDadosFinal(dado * last){
	if(last == NULL){
		printf("\n\nFIM DA LISTA\n\n");
	}else{
		printf("Dado : %d \n",last->valor);
		mostrarDadosFinal(last->anterior);
	}
}

void mostrarDadosInicio(dado * first){
	if(first == NULL){
		printf("\n\nFIM DA LISTA\n\n");
	}else{
		printf("Dado : %d \n",first->valor);
		mostrarDadosInicio(first->proximo);
	}
}
void mainMostraDados(mainList * l){
	int esc;
	printf("\n[1] Vizualizar lista do inicio");
	printf("\n[2]Vizualizar lista doo final \t");
	scanf("%d",&esc);
	if(esc == 1){
		mostrarDadosInicio(l->inicio);
	}else{ 
		if(esc == 2){
			mostrarDadosFinal(l->final);
		}else{
			printf("\nVoce digitou um numerro invalido\n");
		}
	}
}
dado * alocaDado(){
	dado * p = (dado*)malloc(sizeof(dado));
	p->anterior = NULL;
	p->proximo = NULL;
	return(p);
}
mainList * alocaLista(){
	mainList * p = (mainList*)malloc(sizeof(mainList));
	if(!p){
		printf("Dado não alocado por falta de memória\n");
		exit(1);
	}
	p->qtdDados = 0;
	p->inicio = NULL;
	p->final = NULL;
	return(p);
}
void incluirDados(mainList * l){
	int va;
	dado * novo;
	dado * aux;
	printf("\nDigite  o valor que quer inserir na lista \n");
	scanf("%d",&va);
	novo = alocaDado();
	novo->valor = va;
	if(l->inicio == NULL){
		l->inicio = novo;
		l->final = novo;
	}else{
		aux = l->final;
		l->final = novo;
		l->final->anterior = aux;
		aux->proximo = novo;
	}
}
//
