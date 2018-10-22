/*
 * @Autor do Exercicio : Marcio Alexandre Freire Sindeaux 
 * @Data : 22/10/2018
 * 
 * Burger Things, uma rede de alimentos Task Food, pensando em melhor atender seus clientes resolve chamar seus clientes pelo nome.
 * Com o tempo, a clientela foi aumentando, e memorizar o nome de todos os clientes estava ficando muito dificil;
 *
 * Um programador foi contratado para construir um programa que, além de memorizar o nome dos clientes, mantivesse a ordem dos pedidos,
 * para melhorar a ordem do estabelecimento (Ordem de chegada).
 *
 * Voce é o programador, faça o que se pede.
 * ->RESPOSTA ABAIXO 
 */
 
#include<stdio.h>
#include<stdlib.h>

typedef struct pessoa{
	struct pessoa * prox;
	char nome[100];
}pessoa;

typedef struct mainFila{
	struct pessoa * inicio;
}mainLista;

mainFila * alocaFila();
pessoa * alocaPessoa();
void inserirPessoa(mainFila * f);
void chamarPessoa(mainFila * f);
void mostrarPessoa(pessoa * p);
void mostrarTodasPessoas(pessoa * p);
int main(void){
	int opc = -1;
	struct mainFila * f = alocaFila();
	while(opc != 0){
		printf("\n[1] -  Colocar Pessoa na fila\n");
		printf("[2] - Chamar pessoa da fila\n");
		printf("[3] - Mostrar proxima pessoa \n");
		printf("[4] - Limpar fila inteira\n");
		printf("[5] - Mostrar Pessoas da fila\n");
		printf("[0] - Sair\n");
		scanf("%d",&opc);
		switch(opc){
			case 0:
				printf("\n\nSaindo do programa ...\n\n");
			break;
			case 1:
				inserirPessoa(f);
			break;
			case 2:
				chamarPessoa(f);
			break;
			case 3:
				mostrarPessoa(f->inicio);
			break;
			case 4:
				free(f->inicio);
				f->inicio = NULL;
			break;
			case 5:
				mostrarTodasPessoas(f->inicio);
			break;
			default:
				printf("\n\nNumero Inserido Invalido\n\n");
			break;
		}
	}
	free(f);
	return(0);
}
void mostrarTodasPessoas(pessoa * p){
	if(p == NULL){
		printf("\n\n");
	}else{
		printf("\n NOME : \t %s",p->nome);
		mostrarTodasPessoas(p->prox);
	}
}

void mostrarPessoa(pessoa * p){
	if(p->prox == NULL){
		printf("\n\nPROXIMA PESSOA \t %s\n\n",p->nome);
	}else{
		mostrarPessoa(p->prox);
	}
}

void chamarPessoa(mainFila * f){
	if(f->inicio != NULL){
		struct pessoa * aux = f->inicio;
		if(aux->prox == NULL){
			printf("\n\nCHAMANDO \t %s\n\n",aux->nome);
			free(aux);
			f->inicio = NULL;
		}else{
			while(aux != NULL){
				if(aux->prox->prox == NULL){
					printf("\n\nCHAMANDO \t %s\n\n",aux->prox->nome);
					free(aux->prox);
					aux->prox = NULL;
					break;
				}
				aux = aux->prox;
			}
		}
	}else{
		printf("\n\nFILA VAZIA\n\n");
	}
		
}

void inserirPessoa(mainFila * f){
	fflush(stdin);
	struct pessoa * aux = alocaPessoa();
	printf("\nDigite o nome da pessoa : \n ");
	fgets(aux->nome,100,stdin);
	aux->prox = f->inicio;
	f->inicio = aux;
}

mainFila * alocaFila(){
	mainFila * f = (mainFila*)malloc(sizeof(mainFila));
	if(!f){
		printf("\nNão foi possivel criar fila por falta de memória");
		exit(1);
	}else{
		f->inicio = NULL;
		return(f);	
	}
}
pessoa * alocaPessoa(){
	pessoa * p = (pessoa*)malloc(sizeof(pessoa));
	if(!p){
		printf("\nNão foi possivel criar pessoa por falta de memória");
		exit(1);
	}else{
		p->prox = NULL;
		return(p);	
	}
}
