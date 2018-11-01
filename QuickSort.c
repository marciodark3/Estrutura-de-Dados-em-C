#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define swap(A,B) \
	A = A + B;\
	B = A - B;\
	A = A - B;\
	printf("Dados trocados ; A = %d, e B = %d\n",A,B);
	
#define max 100000

void quickSort(int v[] , int inicio,int fim);
void bubbleSort(int v[], int fim);
int main(){
	
	int vet[max];
	
	srand(time(NULL));
	
	for(int i=0;i < max ; i++){
		vet[i] = rand()%100;
	}
	/*printf("Vetor : ");
	for(int i=0;i < max ; i++){
		printf("%d\t",vet[i]);
	}*/
	int opc = 0;
	printf("\n\n\n[1] - Bubble Sort\n");
	printf("[2] - Quick Sort");
	printf("\n\n\nChoice : \t");
	scanf("%d",&opc);
	if(opc == 1){
		bubbleSort(vet,max);
	}else{
		quickSort(vet,0,max);	
	}
	printf("\n");
	for(int i = 0 ; i < max ; i++){
		printf("\t%d",vet[i]);
	}
}

void bubbleSort(int v[],int fim){
	for(int i = 0; i<fim ; i++ ){
		for(int j = i+1; j < fim ; j++ ){
			if(v[i] > v[j]){
				swap(v[i],v[j]);
			}
		}
	}
	printf("\n\n\nVetor \n\t");
	/*for(int i = 0 ; i < max ; i++){
		printf("\t%d",v[i]);
	}*/ 
}

void quickSort(int v[] , int inicio,int fim){
	if(inicio != fim){
		int pivot = fim,aux = inicio;
		int counter = 0;
		while(aux != pivot){
			if(counter % 2 == 0){
				if(v[pivot]<v[aux]){
					swap(v[pivot],v[aux]);
					swap(pivot,aux);
					aux--;
					counter++;

				}else{
					aux++;
				}
			}else{
				if(v[pivot]>v[aux]){
					swap(v[pivot],v[aux]);
					swap(pivot,aux);
					aux++;
					counter++;
				}else{
					aux--;
				}
			}
		}
		if(v[fim] != v[inicio+1]){
			if(pivot == fim){
				quickSort(v,inicio,pivot-1);
			}else if(pivot == inicio){
				quickSort(v,pivot+1,fim);
			}else{
				quickSort(v,inicio,pivot-1);
				quickSort(v,pivot+1,fim);
			}
		}
	}
}
