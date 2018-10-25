 /*
 * Falta ajustar pequenos detalhes de livros e seções
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct livro{
	char titulo[100];
	struct livro * prox;
}livro;

typedef struct secao{
	int qtdSecao;
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
livro * buscaLivro(mainList * l);
void criaSecao(mainList * l);
void retiraSecao(mainList * l);
void insereLivro(mainList * l);
void retiraLivro(mainList * l);
void mostraSecaoMain(mainList * l);
void mostraSecao(secao * s);
void mostraQuantidadeSecao(mainList * l);
void listaSecoes(mainList * l);
void mostrarTudo(secao * s);

int main(void){
    livro * b = NULL;
	mainList * l = alocaList();
	int opc = -1;
	while(opc != 0){
		printf("\n[1] - Criar Secao\n");
		printf("[2] - Criar Livro\n");
		printf("[3] - Verificar quantidade total de livros\n");
		printf("[4] - Listar Seções \n");
		printf("[5] - Verificar quantidade da seção\n");
		printf("[6] - Retirar Livro da seção\n");
		printf("[7] - Excluir seção\n");
		printf("[8] - Buscar Livro\n");
        printf("[9] - Mostrar Livros da seção\n");
        printf("[10] - Mostrar Todos os Livros\n");
		printf("[0] - Sair do programa\n");
        scanf("%d",&opc);
        switch(opc){
            case 0:
            break;
            case 1:
                criaSecao(l);
            break;
            case 2:
                insereLivro(l);
            break;
            case 3:
                printf("\n\n Existem %d Livros \n\n",l->qtdLivros);
            break;
            case 4:
                listaSecoes(l);
            break;
            case 5:
                mostraQuantidadeSecao(l);
            break;
            case 6:
                retiraLivro(l);
            break;
            case 7:
                retiraSecao(l);
            break;
            case 8:
                b = buscaLivro(l);
                if(b != NULL){
                    printf("\n\nLivro Existente\n\n");
                }else{
                    printf("\n\nLivro não existe em nenhuma secao\n\n");
                }
            break;
            case 9:
                mostraSecaoMain(l);
            break;
            case 10:
                mostrarTudo(l->inicio);
            break;
            default:

            break;
        }
    }
}

mainList * alocaList(){
    mainList * l = (mainList*)malloc(sizeof(mainList));
    if(!l){
        printf("\n\nMemória não alocad por falta de espaco\n\n");
        exit(1);
    }else{
        l->qtdLivros = 0;
        l->inicio = NULL;
        return(l);
    }
}
secao * alocaSecao(){
    secao * s = (secao*)malloc(sizeof(secao));
    if(!s){
        printf("\n\nMemória não alocad por falta de espaco\n\n");
        exit(1);
    }else{
        s->qtdSecao = 0;
	    s->inicio = NULL;
        s->prox = NULL;
        return(s);
    }
}
livro * alocaLivro(){
    livro * b = (livro*)malloc(sizeof(livro));
    if(!b){
        printf("\n\nMemória não alocad por falta de espaco\n\n");
        exit(1);
    }else{
        b->prox = NULL;
        return(b);
    }
}
livro * buscaLivro(mainList * l){
    int contager=0;
    char nome[100];
    printf("\n\nDigite o nome do livro que quer buscar\n");
    fflush(stdin);
    fgets(nome,100,stdin);
    secao * auxc = l->inicio;
    livro * auxb = auxc->inicio;
    if(auxc == NULL){
        printf("\n\nNenhuma secao cadastrada\n\n");
    }else{
        if(auxc->prox == NULL){
            if(auxb == NULL){
                printf("\n\nNenhum livro cadastrado\n\n");
            }else{
                while(auxb != NULL){
                    if(strcmp(auxb->titulo,nome) == 0){
                        printf("\n\nLivro achado na primeira secao!\n\n");
                    }
                }
            }
        }else{
            int contS=1,contB=1;
            while(auxc != NULL){
                if(auxb != NULL){
                    while(auxb != NULL){
                        if(strcmp(auxb->titulo,nome) == 0){
                            printf("\n\nLivro achado na secao %d\n\n",contS);
                            contager++;
                        }
                        auxb = auxb->prox;
                    }
                }
                auxc = auxc->prox;
                auxb = auxc->inicio;
                contS++;
            }
            if(contager == 0){
                printf("Nenhum Livro cadaastrado com o nome especifcado");
            }
        }
    }
}

void criaSecao(mainList * l){
    secao * s = alocaSecao();
    secao * aux = l->inicio;
    printf("\n\nDigite o nome da secao\n");
    fflush(stdin);
    fgets(s->nome,20,stdin);
    if(aux == NULL){
        l->inicio = s;
    }else{
        while(aux->prox != NULL){
            aux=aux->prox;
        }
        aux->prox = s;
    }
}

void retiraSecao(mainList * l){
    if(l->inicio == NULL){
        printf("\n\nNão ha secoes\n\n");
    }else{
        listaSecoes(l);
        printf("\n\nDigite o nome da Lista que vai ser excluido\n");
        char nome[20];
        fflush(stdin);    
        fgets(nome,20,stdin);
        secao * aux = l->inicio;
        if(aux->prox == NULL){
            if(strcmp(aux->nome,nome) == 0){
                if(aux->inicio == NULL){
                    l->inicio = NULL;
                    free(aux);
                }else{
                    printf("\n\nSecao não pode ser excluida porque existem itens na secao\n\n");
                }
            }else{
                printf("\n\nNão pode ser excluido ... Nome Incopativel\n\n");
            }
        }else{
            secao * antaux = aux;
            aux = aux->prox;
            int conta = 0;
            while(aux != NULL){
                if(strcmp(aux->nome,nome)==0){
                    antaux->prox = aux->prox;
                    free(aux);
                    conta++;
                    break;
                }
            }
            if(conta == 0){
                printf("Não pode ser excluido ... Nome Incopativel");
            }
        }
    }
}


void insereLivro(mainList * l){
	livro * b = alocaLivro();
	printf("\nDigite o nome do livro que deseja Inserir\n");
	fflush(stdin);
	fgets(b->titulo,100,stdin);
	printf("\n\n");
	printf("Digite o numero da secao que voce deseja Incluir Livro : \n");
	listaSecoes(l);
	printf("\t[-1] - Criar secao\n");
	printf("\t[0] - Sair do programa\n");
	int opc;
	scanf("%d",&opc);
	if(opc > 0){
		secao * s = l->inicio;
		for(int i=1;i<opc;i++){
			s = s->prox;
		}
		b->prox = s->inicio;
		s->inicio = b;
		l->qtdLivros++;
		s->qtdSecao++;
	}else{
		if(opc == 0){
			printf("\n\n TUDO BEM ... \n\n");
		}else if(opc == -1){
			criaSecao(l);
			secao * s = l->inicio;
			if(s->prox == NULL){
				b->prox = s->inicio;
				s->inicio = b;
				l->qtdLivros++;
				s->qtdSecao++;
			}else{
				while(s->prox != NULL){
					s = s->prox;
				}
				b->prox = s->inicio;
				s->inicio = b;
				l->qtdLivros++;
				s->qtdSecao++;
			}
		}
	}	
}

void retiraLivro(mainList * l){
	printf("\nDigite o Tilulo do Livro : \t");
	char nome[100];
	fflush(stdin);
	fgets(nome,100,stdin);
	secao * s = l->inicio;
	livro * b;
	if(l->inicio != NULL){
		int conta;
		while(s != NULL){
			b = s->inicio;
			while(b != NULL){
				if(strcmp(b->prox->titulo,nome) == 0){
					livro * aux = b->prox;
					b->prox = aux->prox;
					free(aux);
					printf("\n\nLIVRO RETIRADO COM SUCESSO\n\n");
					conta++;
				}
				
			}
			s=s->prox;
		}
		if(conta == 0){
			printf("\n\nNenhum livro com esse titulo cadastrado\n\n");
		}
	}else{
		printf("\n\nNenhum livro Cadastrado\n\n");
	}
		
}

void mostraSecao(secao * s){
    printf("\n\n%s\n",s->nome);
    printf("Contem %d livros\n",s->qtdSecao);
    if(s->qtdSecao > 0){
        printf("Sendo eles : \n");
        livro * auxb = s->inicio;
        while(auxb != NULL){
            printf("\n-----------------------------------------------------\n");
            printf("Livro : %s",auxb->titulo);
            auxb = auxb->prox;
        }
    }
}

void mostraSecaoMain(mainList * l){
    listaSecoes(l);
    if(l->inicio != NULL){
        int escolha;
        scanf("%d",&escolha);
        secao * aux = l->inicio;
        for(int i=1;i<escolha;i++){
            aux = aux->prox;
        }
        mostraSecao(aux);
    }
}

void mostraQuantidadeSecao(mainList * l){
    listaSecoes(l);
    printf("Digite a numeracao da lista : \n");
    int escolha;
    scanf("%d",&escolha);
    secao * aux = l->inicio;
    for(int i=1;i<escolha;i++){
        aux = aux->prox;
    }
    printf("Essa lista possui %d livros",aux->qtdSecao);
}

void listaSecoes(mainList * l){
    int p = 1;
    secao * aux = l->inicio;
    if(aux == NULL){
        printf("\n\nNenhuma secao cadastrada\n\n");
    }else{
    	printf("\n");
        while(aux != NULL){
            printf("[%d] - %s",p,aux->nome);
            aux = aux->prox;
            p++;
        }
    }
}

void mostrarTudo(secao * s){
    if(s != NULL){
        mostraSecao(s);
        mostrarTudo(s->prox);
    }
}
