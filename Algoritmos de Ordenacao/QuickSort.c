/*
 *@Autor : Marcio Alexandre Freire Sindeaux
 *@Data : 12/11/2018
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define max 100000
#define swap(A,B) \
	A = A + B;\
	B = A - B;\
	A = A - B;

void quickSort(int v[] , int inicio,int fim);

int main(){
	int vet[max];
	srand(time(NULL));
	for(int i=0;i < max ; i++){
		vet[i] = rand()%100;
	}
	printf("Vetor Não Ordenado : \n");
	for(int i=0;i < max ; i++){
		printf("%d\t",vet[i]);
	}
	printf("\n\n\n\n\n");
	quickSort(vet,0,max);	
	printf("\nVertor Ordenado : \t");
	for(int i = 0 ; i < max ; i++){
		printf("\t%d",vet[i]);
	}
}

void quickSort(int v[] , int inicio,int fim){
	/* Explicando o Funcionameto da função QuickSort:
	 * A função Quick Sort recebe um vetor, o inicio do vetor recebido e o "suposto fim" de onde se encerraria as comparações
	 * o Pivo é o ultimo elemento e o auxiliar é o primeiro. Dessa forma, se recebessemos um vetor de 6 posições da forma :
	 * [1,6,3,8,5,4], 4 é o pivô e 1 é o auxiliar.
	 *
	 * O Objetivo desse quick sort é ACHAR A POSIÇÃO FINAL DO PIVÔ, para isso, o pivo vai viajar até a sua posiçõa final atravez de certas iterações.
	 * Sempre que o indice do pivo for maior que o do auxiliar e o pivo for maior que o auxiliar, eles trocam, juntamete com os ponteiros, e 
	 * sempre que o indice do pivo for menor que o do auxiliar e o pivo for menor que o auxiliar, eles tambem trocam juntamente com os ponteiros.
	 * a variavel counter serve para isso : ver ser o indice do pivo é maior ou menor que o do auxiliar, sempre que ela for par, o indice do 
	 * pivo é maior (visto que nenhuma troca aconteceu ainda para o pivo ser menor, ou ja aconteceu pelo menos duas trocas).
	 *
	 * Exemplificando com o vetor dado acima : 
	 *      [(aux)1, 6 , 3 , 8 , 5 , (pivo)4]   --\  [(pivo)4 , 6 , 3 , 8 , 5 , 1(aux)]   --\  [(pivo)4 , 6 , 3 , 8 , 5(aux) , 1]  --\
	 *      aux = 0    Pivo = 5   couter = 0    --/  aux = 5   pivo = 0,  counter = 1     --/   aux = 4   pivo = 0,  counter = 1   --/
	 * 
	 *      [(aux)5 , 6 , 3 , 8 , 4(pivo) , 1]  --\  [5 , (aux)6 , 3 , 8 , 4(pivo) , 1]   --\ [5 , 6 , (aux)3 , 8 , 4(pivo) , 1]   --\
	 *      aux = 0   pivo = 4,  counter = 2    --/   aux = 1   pivo = 4,  counter = 2    --/ aux = 2   pivo = 4,  counter = 2     --/
	 *
	 *      [5 , 6 , (pivo)4 , 8 , 3(aux) , 1]  --\  [5 , 6 , (pivo)4 , 8(aux) , 3 , 1]   --\   [5 , 6 , 8 ,(pivo) 4 (aux), 3 , 1]
	 *      aux = 4  pivo = 2,  counter = 3     --/   aux = 3   pivo = 2,  counter = 3    --/   aux = 3   pivo = 3,  counter = 4
	 *
	 * Agora que pivo == aux, sabemos que esse numero está na posição correta. A Partir disso, sabendo 
	 * que o indice do numero na posição correta é 2 (porque vetor[2] = 4), a função, de forma recursiva, vai fazer a mesma operação no
	 * sub-vetor anterior ao indice, de 0 a (3-1 =) 2 , e no sub-vetor posterior ao indice, de (3+1 =) 4 até 5 
	 *
	 * Dentro dessa funçao existem dois tratamentos de caso.
	 */ 
	if(inicio != fim){
		/*
		 * Caso a função receba um vetor unico (da função main ou mesmo de recursividade), a função não vai ser executada, poque um vetor
		 * unitário já está ordenado. 
		 */
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
		if( fim != inicio+1){
			/*
			 * Caso eu receba um vetor de duas posições, só preciso que ele passe 1 vez na função, o laço while vai fazer ele trocar os 
			 * valores, caso isso seja necessário.
			 */
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
