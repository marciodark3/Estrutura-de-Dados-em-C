#include<stdio.h>
#include<stdlib.h>

typedef struct livro{
	char titulo[100];
	struct livro * prox
}livro;

typedef struct secao{
	int qtdSecao
	char nome[20];
	struct livro * inicio;
	struct secao * prox;
}secao;

typedef struct mainList{
	int qtdLivros;
	struct secao * inicio;
}mainList;

mainList * alocaList();
secao * alocaSecao();
livro * alocaLivro();
livro * buscaLivro();
void insereLivro();
void retiraLivro();
void mostraSecao();
void listaSecoes();
int somaQtd();

int main(void){
	mainList * l =   alocaList();
	int opc = -1;
	while(opc != 0){
		printf("\n[1] - Criar Seção\n");
		printf("[2] - Criar Livro\n");
		printf("[3] - Verificar quantidade total de livros\n");
		printf("[4] - Listar Seções \n");
		printf("[5] - Verificar quantidade da seção\n");
		printf("[6] - Retirar Livro da seção\n");
		printf("[7] - Excluir seção\n");
		printf("[8] - Buscar Livro\n");
		printf("[0] - Sair do programa\n");
	}
}
