/*
 * Uma pequena companhia, BotoCaro, oferece produtos de perfumaria.
 *
 * Um dia, o dono dessa companhia queria saber os produtos lancados desde a abertura da sua pequena lojinha, tanto em ordem crescente como em decrescente.
 * Infelismente o dono dessa companhia DETESTA SQL, e pior de tudo, ele tem um ódio maior de um comando de SQL, o ORDER BY.
 *
 * Rico do jeito que ele é, e com ódio no coração, ele contratou voce, um programador experiente QUE NÃO TEM MEDO DE TRABALHO BRAÇAL
 *
 * O seu trabalho é coletar os dados do banco de dados e fazer o que o dono te pediu.
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct produto{
	char nomeProduto[100];
	int anoDeProducao;
}produto;
int qtd;

int main(void){
	printf("\nDigite a quantidade de Produtos no banco de dados\t\:\t");
	scanf("%d",&qtd);
	ligacao l[qtd]	
	
}
