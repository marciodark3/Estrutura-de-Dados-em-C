#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define swap(a,b)\
	a = a + b;\
	b = a - b;\
	a = a - b; 
#define max 10000

void insertionSort(int vet[]);
void mostraVetor(int vet[]);

int main(void){
	int i =0;
	int vet[max];
	srand(time(NULL));
	for(int i = 0; i < max ; i++ ){
		vet[i] = rand()%100;
	}
	printf("Mostrando vetor nao ordenado : \n");
	mostraVetor(vet);
	insertionSort(vet);
	printf("\n\n\n\n");
	mostraVetor(vet);
	printf("\n");
	return(0);
}

void mostraVetor(int vet[]){
	for(int i = 0; i < max ; i++ ){
		printf("%d\t",vet[i]);
	}		
}

void insertionSort(int vet[]){
	/*
	 * Explicando o Insertion Sort:
	 * O insertion Sort é um algorito de ordenação relativamente simples, ele é muito parecido com o Bubble Sort, porem, ele, ao 
	 * invez de realizar apeenas uma troca, tenta achar a posição final do numero no vetor ordenao, por isso ele tem um desempenho
	 * ligeiramente superior ao Bubble Sort.
	 *Ex: vetor  v = [1,34,2,65,23,8] com o algoritmo que esta abaixo :
	 *    [(i)1 , (j)34 , 2 , 65 , 23 , 8] -->  [1 , (i)34 , (j)2 , 65 , 23 , 8] --> [1 , 2 , (i)34 , (j)65 , 23 , 8] 
	 *    34 > 1 então Não Troca		     Como 2 < 34 então TROCA        	 Como 65 > 34 então Não troca
	 *
	 *    [1 , 2 , 34 , (i)65 , (j)23 , 8] -->  [1 , 2 , (i)34 , (j)23, 65 , 8] --> [1 , 2(i) , (j)23 , 34, 65 , 8]
	 *	  Como 23 < 65 então TROCA	    Como 23 < 34 então Troca            Como 23 > 2 não troca
	 *
	 *    [1 , 2 , 23 , 34, 65(i) , 8(j)] --> [1 , 2 , 23 , (i)34, (j)8 , 65] --> [1 , 2 , (i)23 , (j)8, 34 , 65]
	 *	  Como 8 < 65 TROCA 		   Como 8 < 34 TROCA		      Como 8 < 23 TROCA
	 *
	 *    [1 , 2(i) , (j)8 , 23 , 34 , 65] --> VETOR ORDENADO
	 *	Como  8 > 2 Não Troca
	 */
	int aux = 0;
	int j,i;
	for(i = 0; i < max; i++){
		j = i + 1;
		if(vet[j] < vet[i]){
			swap(vet[i],vet[j]);
			if(i != 0){		
				i = i -2;
				j = j - 2;						
			}
		}
		
	}	
}
