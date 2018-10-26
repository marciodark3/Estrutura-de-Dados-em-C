#include<stdio.h>
#include<stdlib.h>

typedef struct pessoa{
	char nome[100];
	long int cpf;
	long int matricula;
	struct pessoa * prox;
}pessoa;

typedef struct mainList{
	int qtd;
	struct pessoa * inicio;
}mainList;

mainList * alocaLista();
pessoa * alocaPessoa();
void ordenaMatricula(mainList * l);
void ordenaCPF(mainList * l);
void buscaPessoa(mainList * l);
void inserePessoa(mainList * l);
void retiraPessoa(mainList * l);


int main(void){
	int opc = -1;
	mainList * l = alocaLista();
	while(opc != 0){
		printf("\n\n[1] - Inserir Pessoa no sistema\n");
		printf("[2] - Retirar Pessoa\n");
		printf("[3] - Buscar Pessoa\n");
		printf("[4] - Mostrar pessoas em ordem por CPF\n");
		printf("[5] - Mostrar pessoas em ordem por matricula\n");
		printf("[0] - Sair\n");
		scanf("%d",&opc);
		switch(opc){
			case 0:
			break;
			case 1:
				inserePessoa(l);
			break;
			case 2:
				retiraPessoa(l);
			break;
			case 3:
				buscaPessoa(l);
			break;
			case 4:
				ordenaCPF(l);
			break;
			case 5:
				ordenaMatricula(l);
			break;
			default:
			break;
		}
	}
	return(0);
}
mainList * alocaLista();
pessoa * alocaPessoa();
void ordenaMatricula(mainList * l);
void ordenaCPF(mainList * l){
	if(l->inicio == NULL){
		printf("\n\nNão foi cadastrado nenhuma pessoa \n\n");
	}else{
		pessoa *posicao,*menorPTR,*corredor = l->inicio;
		if(corredor->prox != NULL){
			int menorCPF = corredor->cpf;
			menorPTR = corredor;
			while(corredor != null){
				if(corredor->cpf <)
			}
		}
	}
}

void buscaPessoa(mainList * l){
	int mat;
	printf("\nDigite a matricula da pessoa : \t");
	scanf("%d",&mat);
	if(l->inicio == NULL){
		printf("\n\nNão foi cadastrado nenhuma pessoa \n\n");
	}else{
		aux = l->inicio;
		if(aux->prox == NULL){
			if(aux->matricula == mat){
				printf("Pessoa : %s",aux->nome);
			}else{
				printf("\n\nItem não encontrado \n\n");
			}
		}else{
			int cont = 0;
			while(aux != 0){
				if(aux->matricula == mat){		
					printf("Pessoa : %s",aux->nome);
					cont ++;
					break;
				}
				aux=aux->prox;
			}
			if(cont==0){
				printf("\n\nItem não encontrado\n\n");
			}
		}
	}
}

void inserePessoa(mainList * l){
	pessoa * p = alocaPessoa();
	printf("\nDigite o nome da pessoa:\n");
	scanf("%[^\n]s",&p->nome);
	fflush(stdin);
	printf("\n\nDigite o CPF da pessoa \n");
	scanf("%ld",&p->cpf);
	printf("\n\nDigite o numero de matricula da pessoa \n");
	scanf("%ld",&p->matricula);
	p->prox = l->inicio;
	l->inicio = p;
}

void retiraPessoa(mainList * l){
	int mat;
	printf("\nDigite a matricula da pessoa : \t");
	scanf("%d",&mat);
	if(l->inicio == NULL){
		printf("\n\nNão foi cadastrado nenhuma pessoa \n\n");
	}else{
		aux = l->inicio;
		if(aux->prox == NULL){
			if(aux->matricula == mat){
				l->inicio = aux->prox;
				free(aux);
				printf("\n\nItem Excluido com Sucesso\\n\n")
			}else{
				printf("\n\nItem não encontrado \n\n");
			}
		}else{
			pessoa * antpessoa = aux;
			aux=aux->prox;
			int cont = 0;
			while(aux != 0){
				if(aux->matricula == mat){
					antaux->prox = aux->prox;
					free(aux);
					printf("\n\nItem Excluido com Sucesso\\n\n")
					cont++;
					break;		
				}
				antpessoa = aux;
				aux=aux->prox;
			}
			if(cont==0){
				printf("\n\nItem não encontrado\n\n");
			}
		}
	}
}
