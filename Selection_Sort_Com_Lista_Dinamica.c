/*
 *@Autor : Marcio Alexandre Freire Sindeaux
 *@Data : 29/10/2018
 *
 *Problema : 
 *
 * O RH de uma empresa estava com dificuldades de ultilizar codigos de SQL para ordenar os dados dos funcionários
 * Diziam que o SQL era dificil de entender(coisa de novato). Em Fim, eles contataram o superior da área, que sabia que
 * isso poderia ser feito de forma rápida em algumas linguagens.
 *
 * Nessa história, o superior da ÁREA fez esse programa.
 *
 * Dado algum tempo, o mesmo superior foi fazer entrevistas de emprego para a area de TI(Afinal , ele também é do R.H). 
 * Nessa entrevista, no qual voce é o entrevistado ele pediu :
 *
 * "Faça um programa que implemente um algoritmo de ordenação que não seja o Bubble Sort. Esse programa consiste em um mini
 *  cadastro de funcionários do RH. Implemente funções dinamicas, afinal, voce não sabe quantos empregados existem nessa empresa.
 *  Obs : EU TE GARANTO QUE NENHUM DADO SERÁ COLOCADO DE FORMA ERRADA, portanto não precisa sem preocupar em remover os itens."
 *
 * Faça o que seu futuro chefe te pede.
 *
 *RESOLUÇÃO:
 */

#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

typedef struct dadosPessoas{
	/*
	 * Estrutura nde os dados dos funcionários vão ficar
	 */
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
void mostrarLista(mainList * l);


int main(void){
    //Funciona
	int opc = -1;
	mainList * l = alocaLista();
	while(opc != 0){
		printf("\n\n[1] - Inserir Pessoa no sistema\n");
		printf("[2] - Buscar Pessoa\n");
		printf("[3] - Mostrar pessoas em ordem por CPF\n");
		printf("[4] - Mostrar pessoas em ordem por matricula\n");
		printf("[5] - Mostrar Lista \n");
		printf("[0] - Sair\n");
		scanf("%d",&opc);
		switch(opc){
			case 0:
			break;
			case 1:
				inserePessoa(l);
			break;
			case 2:
				buscaPessoa(l);
			break;
			case 3:
				ordenaCPF(l);
			break;
			case 4:
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
    mainList * L = (mainList*)malloc(sizeof(mainList));
    L->qtd = 0;
    L->inicio = NULL;
    L->fim = NULL;
    return(L);
}

pessoa * alocaPessoa(){
    pessoa * p = (pessoa*)malloc(sizeof(pessoa));
    p->proximo = NULL;
    p->anterior = NULL;
    return(p);
}
void ordenaMatricula(mainList * l){
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
    pessoa * aux;
	int mat;
	printf("\nDigite a matricula da pessoa : \t");
	scanf("%d",&mat);
	if(l->inicio == NULL){
		printf("\n\nNão foi cadastrado nenhuma pessoa \n\n");
	}else{
		aux = l->inicio;
		if(aux->proximo == NULL){
			if(aux->dados.matricula == mat){
				printf("Pessoa : %s",aux->dados.nome);
			}else{
				printf("\n\nItem não encontrado \n\n");
			}
		}else{
			int cont = 0;
			while(aux != 0){
				if(aux->dados.matricula == mat){		
					printf("Pessoa : %s",aux->dados.nome);
					cont ++;
					break;
				}
				aux=aux->proximo;
			}
			if(cont==0){
				printf("\n\nItem não encontrado\n\n");
			}
		}
	}
}

void inserePessoa(mainList * l){
    pessoa * p = alocaPessoa();
    printf("\n\nDigite o nome da Pessoa : \t");
    fflush(stdin);
    fgets(p->dados.nome,100,stdin);
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

void mostrarLista(mainList * l){
    pessoa * aux = l->inicio;
    while(aux != NULL ){
        printf("\nPessoa %s",aux->dados.nome);
        printf("Matricula : %ld",aux->dados.matricula);
        printf("\nCPF : %ld\n\n",aux->dados.cpf);
        printf("--------------------------------------------");
        aux = aux->proximo;
    }
}


