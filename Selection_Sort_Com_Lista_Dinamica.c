#include<stdio.h>
#include<stdlib.h>

typedef struct dadosPessoas{
    char nome[100];
	int cpf;
	int matricula;
}dadosPessoas;
typedef struct pessoa{
	struct dadosPessoas dados;
	struct pessoa * proximo;
    struct pessoa * anterior;
}pessoa;

typedef struct mainList{
	int qtd;
	struct pessoa * inicio;
    struct pessoa * fim;
}mainList;

mainList * alocaLista();
pessoa * alocaPessoa();
void ordenaMatricula(mainList * l);
void ordenaCPF(mainList * l);
void buscaPessoa(mainList * l);
void inserePessoa(mainList * l);
void retiraPessoa(mainList * l);
void mostrarLista(mainList * l);


int main(void){
    //Funciona
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
            case 10:
                mostrarLista(l);
            break;
			default:
			break;
		}
	}
	return(0);
}

mainList * alocaLista(){
    //Funciona
    mainList * L = (mainList*)malloc(sizeof(mainList));
    L->qtd = 0;
    L->inicio = NULL;
    L->fim = NULL;
    return(L);
}

pessoa * alocaPessoa(){
    //Funciona
    pessoa * p = (pessoa*)malloc(sizeof(pessoa));
    p->proximo = NULL;
    p->anterior = NULL;
    return(p);
}
void ordenaMatricula(mainList * l){
    //Funciona
    if(l->inicio == NULL){
        printf("\nNenhum item cadastrado\n");
    }else{
        dadosPessoas auxtroca;
        pessoa * aux1 = l->inicio;
        pessoa * aux2 = l->inicio;
        pessoa * maior = l->inicio;
        long int maiormatricula = maior->dados.matricula;
        while(aux1->proximo != NULL){
            while(aux2 != NULL){
                if(aux2->dados.matricula > maiormatricula){
                    maior = aux2;
                    maiormatricula = maior->dados.matricula;
                }
                aux2 = aux2->proximo;
            }
            auxtroca = maior->dados;
            maior->dados = aux1->dados;
            aux1->dados = auxtroca;
            aux1 = aux1->proximo;
            aux2=aux1;
        }
    }
    mostrarLista(l);
}

void ordenaCPF(mainList * l){
    //Funciona
    if(l->inicio == NULL){
        printf("\nNenhum item cadastrado\n");
    }else{
        dadosPessoas auxtroca;
        pessoa * aux1 = l->inicio;
        pessoa * aux2 = l->inicio;
        pessoa * maior = l->inicio;
        long int maiorcpf = maior->dados.cpf;
        while(aux1->proximo != NULL){
            while(aux2 != NULL){
                if(aux2->dados.cpf > maiorcpf){
                    maior = aux2;
                    maiorcpf = maior->dados.cpf;
                }
                aux2 = aux2->proximo;
            }
            auxtroca = maior->dados;
            maior->dados = aux1->dados;
            aux1->dados = auxtroca;
            aux1 = aux1->proximo;
            aux2=aux1;
        }
    }
    mostrarLista(l);
}


void buscaPessoa(mainList * l){
    long int mat;
    printf("\n\nDIGITE A MATRICULA DA PESSOA QUE VAI SER ACHADA \t:\t");
    scanf("%d",&mat);
    pessoa * aux = l->inicio;
    while(aux != NULL){
        if(aux->dados.matricula == mat){
            printf("\nPessoa %s Encontrada \n",aux->dados.nome);
            printf("Matricula : %ld",aux->dados.matricula);
            printf("\nCPF : %ld\n\n",aux->dados.cpf);
        }
        aux = aux->proximo;
    }
}

void inserePessoa(mainList * l){
    //Funciona !!
    pessoa * p = alocaPessoa();
    printf("\n\nDigite o nome da Pessoa : \t");
    scanf("%s",NULL);
    scanf("%[^\n]s",p->dados.nome);
    printf("\nDigite apenas os numeros do CPF da pessoa : \t");
    scanf("%d",&p->dados.cpf);
    printf("\nDigite a numeração da matricula da p0essoa na empresa : \t");
    scanf("%d",&p->dados.matricula);
    if(l->inicio == NULL){
        if(l->fim == NULL){
            l->inicio = p;
            l->fim = p;
            l->qtd++;
        }
    }else {
        p->proximo = l->inicio;
        l->inicio = p;
        l->qtd++;
    }   
}
void retiraPessoa(mainList * l){
    long int mat;
    printf("\n\nDIGITE A MATRICULA DA PESSOA QUE VAI SER RETIRADA \t:\t");
    scanf("%ld",&mat);
    pessoa * aux = l->inicio;
    if(aux->dados.matricula == mat){
        l->inicio = aux->proximo;
        l->qtd--;
    }else {
        while(aux->proximo != NULL ){
            if(aux != l->fim){
                if(aux->dados.matricula == mat){
                    pessoa * antaux = aux->anterior;
                    pessoa * proxaux = aux->proximo;
                    antaux->proximo = proxaux;
                    proxaux->anterior = antaux;
                    l->qtd--;
                    break;
                }
            }else{
                if(aux->dados.matricula == mat){
                    l->fim = aux->anterior;
                    l->qtd--;
                    break;
                }
            }
                
            aux = aux->proximo;
        }
    }    
    free(aux);
}

void mostrarLista(mainList * l){
    //funciona
    pessoa * aux = l->inicio;
    while(aux != NULL ){
        printf("\nPessoa %s Encontrada \n",aux->dados.nome);
        printf("Matricula : %ld",aux->dados.matricula);
        printf("\nCPF : %ld\n\n",aux->dados.cpf);
        printf("--------------------------------------------");
        aux = aux->proximo;
    }
}
