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
#include<libio.h>
#include<stdlib.h>

typedef struct produto{
	char nomeProduto[100];
	int anoDeProducao;
}produto;
int qtd;

int main(void){
	printf("\nDigite a quantidade de Produtos no banco de dados\t:\t");
	scanf("%d",&qtd);
    fflush(stdin);
    fflush(stdout);
    fflush(stderr);
	produto l[qtd]	;
    int opc;
    int p,i,j;
    produto aux;
    printf("\nPor favor preencha os dados a seguir\n");
    for( i = 0 ; i < qtd ; i++ ){
        fflush(stdin);
        printf("\nDigite o nome do %do.p produto \t\n",i+1);

        /*
         * Os scanf abaixo são para pegar qualquer tipo de entrada que o computador possa dar com o lixo de memória
         * Não por outro, eles levam o dado adiquirido para o endereço NULL de memória
         */
        scanf("%s",NULL);
        scanf("%[^\n]s",&l[i].nomeProduto);
        fflush(stdin);
        printf("\n\nDigite o ano de fabricacao do produto \t");
        scanf("%d",&l[i].anoDeProducao);
    }
    printf("\n\n");
    printf("Digite o numero da opção que deseja\n");
    printf("[1] Ordenar do mais antigo para o mais novo\n");
    printf("[2] Ordenar do mais novo para o mais antigo\n");
    scanf("%d",&opc);
    /*
     * Nessa parte abaixo ocorre o bubble sort
     */
    for(i = 0 ; i < qtd - 1 ; i++){
        for( j = i + 1 ; j < qtd ; j++ ){
            if(l[i].anoDeProducao > l[j].anoDeProducao){
                aux = l[i];
                l[i]= l[j];
                l[j] = aux;
            }
        }
    }
    
    if(opc == 1){
        for(i=0;i<qtd;i++){
            printf("Ano de fabricacao : %d \nProduto %s\n-------------------------------------------\n",l[i].anoDeProducao,l[i].nomeProduto);
            
        }
    }else if(opc == 2){
        for( i = qtd - 1 ; i >= 0; i-- ){
            printf("Ano de fabricacao : %d \nProduto %s\n-------------------------------------------\n",l[i].anoDeProducao,l[i].nomeProduto);
            
        }
    }
    return(0);
}
