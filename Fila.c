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
	struct pessoa * final;
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
				mostrarPessoa(f->final);
			break;
			case 4:
				free(f->inicio);
				f->inicio = NULL;
			break;
			case 5:
				mostrarTodasPessoas(f->final);
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
	/*
	 * Funcionamento recursivo.
	 * Enquanto não chegar ao primeiro elemento , ele vai mostrar o nome do elemento atual e passar o proximo como parametro.
	 */
	if(p == NULL){
		printf("\n\n");
	}else{
		printf("\n NOME : \t %s",p->nome);
		mostrarTodasPessoas(p->prox);
	}
}

void mostrarPessoa(pessoa * p){
	/*
	 * Funcionamento recursivo.
	 * Enquanto não chegar ao primeiro elemento, a função chama a si mesma, mandando o proximo elemento como parametro.
	 * Quando chegar no primeiro, ele mostra o nome da pessoa.
	 */
	if(p->prox == NULL){
		printf("\n\nPROXIMA PESSOA \t %s\n\n",p->nome);
	}else{
		mostrarPessoa(p->prox);
	}
}

void chamarPessoa(mainFila * f){
	/*
	 * Se a fila não tiver elementos, vai aparecer na tela "FILA VAZIA".
	 * Se a fila não está vazia, se faz necessária a verificação de um caso especial : a fila com apenas 1 elemento.
	 * 	->Caso a fila tenha apenas um elemento, f->final tem que voltar a apontar para "NULL",
	 * 	->se a fila tivert mais de um elemento a seguinte lógica é executada :
	 *		--Vá até o segundo elemento da fila(vamos tratar ele como "aux");
	 *		--Mostre o primeiro elemento da lista.	printf("%s",aux->prox->nome);
	 *		--exclua o primeiro elemento da lista.	free(aux->prox)
	 *		--Faça o elemento atual não apontar para mais ninguem.	(aux->prox = NULL)
	 * Dessa forma a lista vai ser executada de forma correta.
	 */
	if(f->final != NULL){
		struct pessoa * aux = f->final;
		if(aux->prox == NULL){
			printf("\n\nCHAMANDO \t %s\n\n",aux->nome);
			free(aux);
			f->final = NULL;
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
	/*
	 * Nessa lógica, sempre será inserida uma pessoa no fim da fila.
	 * f->final Indica aonde fica o fim da fila.
	 */
	fflush(stdin);
	struct pessoa * aux = alocaPessoa();
	printf("\nDigite o nome da pessoa : \n ");
	fgets(aux->nome,100,stdin);
	aux->prox = f->final;
	f->final = aux;
}

mainFila * alocaFila(){
	mainFila * f = (mainFila*)malloc(sizeof(mainFila));
	if(!f){
		printf("\nNão foi possivel criar fila por falta de memória");
		exit(1);
	}else{
		f->final = NULL;
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
