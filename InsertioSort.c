#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define max 10

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
	printf("\n");
	mostraVetor(vet);
	return(0);
}

void mostraVetor(int vet[]){
	for(int i = 0; i < max ; i++ ){
		printf("%d\t",vet[i]);
	}		
}

void insertionSort(int vet[]){
	int aux = 0;
	int j,i;
	for(i = 0 ; i < max - 1 ; i++){
        for( j = i + 1 ; j < max ; j++ ){
        	if(vet[i] >= vet[j]){	
   		
			}
        }
    }
}
