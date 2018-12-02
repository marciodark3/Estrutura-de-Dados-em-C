/*
 * @Autor do exercicio : Márcio Alexandre Freire Sindeaux
 * @Data : 02/12/2018
 * @E-mail : sindeaux1999@hotmail.com
 * 
 * Uma agencia de banco, do Fradesco, propõe para a diretoria de tecnologia, que precisam ter um sistema de fila para
 * a agencia, pois estavam perdendo o controle da quantidade de pessoas que estavam entrando e saindo da agencia, além
 * disso, queriam saber a quantidade de pessoas que passabam pela agencia durante todo o dia. Sabe-se que a agencia 
 * tem 40 lugates.
 * 
 * Seu chefe, o diretor da DiTec desse banco, pediu para voce, o estagiário aprendiz, implementar esse código para
 * testar seus conhecimentos, ele diz também que se esse programa for bem implementado, seu código será impleentado 
 * de verdade.
 * ->RESPOSTA ABAIXO
 */
#include<stdio.h>
#include<stdlib.h>
#define max 40

void inicializaLista(int vet[]);


int main(void){
    int itemAtual=0,fimFila=0;
    int vet[max],acumulador=1;
    inicializaLista(vet);
    int opc=0;

    do{
    printf("\n\t#################### MENU PRINCIPAL ####################\n");
    printf("\t#\t[1] Inserir Pessoa                              #\n");
    printf("\t#\t[2] Retirar Pessoa                              #\n");
    printf("\t#\t[3] Verificar Proximo Item                      #\n");
    printf("\t#\t[4] Listar Todas as Pessoas na lista            #\n");
    printf("\t#\t[0] Sair do Programa                            #\n");
    printf("\t########################################################\n");
    printf("\tEscolha\t:\t");
    scanf("%d",&opc);
    switch(opc){
        case 0:

        break;

        case 1:
            if(vet[fimFila] == -1){
                printf("\n\n\n\n\n\t#################### INSERCAO DE PESSOAS ######################\n");
                printf("\t#\t INSERINDO NA POSICAO %d                               #\n",fimFila);
                printf("\t###############################################################\n\n\n\n\n");
                vet[fimFila] = acumulador;
                acumulador++;
                fimFila++;
                if(fimFila>= 40){
                    fimFila = fimFila%40;
                }
            }else{
                printf("\n\n\n\n\n\t#################### INSERCAO DE PESSOAS ######################\n");
                printf("\t#\t FILA CHEIA                                          #\n",vet[itemAtual]);
                printf("\t###############################################################\n\n\n\n\n");
            }
        break;

        case 2:
            if(vet[itemAtual] != -1){            
                printf("\n\n\n\n\n\t#################### CHAMADA DE PESSOAS ######################\n");
                printf("\t#\tChamando numero %d                                   #\n",vet[itemAtual]);
                printf("\t##############################################################\n\n\n\n\n");
                vet[itemAtual] = -1;
                itemAtual++;
                if(itemAtual >= 40){
                    itemAtual = itemAtual%40;
                }
            }else{
                printf("\n\n\n\n\n\t#################### CHAMADA DE PESSOAS ######################\n");
                printf("\t#\t FILA VAZIA                                          #\n",vet[itemAtual]);
                printf("\t##############################################################\n\n\n\n\n");
            }
        break;

        case 3:
            if(vet[itemAtual] != -1){
                printf("\n\n\n\n\n\t#################### CHAMADA DE PESSOAS ######################\n");
                printf("\t#\tProxima pessoa a ser camada vai ser o numero %d      #\n",vet[itemAtual]);
                printf("\t##############################################################\n\n\n\n\n");
            }else{
                printf("\n\n\n\n\n\t#################### CHAMADA DE PESSOAS ######################\n");
                printf("\t#\t Nao tem proxima pessoa                              #\n");
                printf("\t##############################################################\n\n\n\n\n");
            }
        break;

        case 4:
            printf("\n\n\n\n\n\t#################### MOSTRAGEM DE PESSOAS ######################\n");
            int ptr = itemAtual;
            while(ptr != fimFila){
                if((int)(ptr%itemAtual) == 0){
                    printf("\t#");
                }
                printf("%d  ",vet[ptr]);
                ptr++;
                if(ptr >= max){
                    ptr = ptr%max;
                }
                if(ptr%itemAtual == 0){
                    printf("#\n");
                }
            }
        break;

    }
    }while(opc != 0);
}

void inicializaLista(int vet[]){
    for(int i = 0; i < max; i++){
        vet[i] = -1;
    }
}
