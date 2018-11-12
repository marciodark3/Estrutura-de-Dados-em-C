/*
 *@Autor : Marcio Alexandre Freire Sindeaux
 *@Data : 12/11/2018
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define fatorEncolhimento 1.24
#define max 100000
#define swap(A,B) \
	A = A + B;\
	B = A - B;\
	A = A - B;\
	//printf("Dados trocados ; A = %d, e B = %d\n",A,B);


int gap =  0;

void combSort(int vet[], int gap);
void mostrarVetor(int vet[]);

int main(void){
	int vet[max];                                             
	int aux;
	printf("Gerando %d numeros \n",max);
	srand(time(NULL));
	for(int i = 0;i<max;i++){
	    vet[i] = rand()%100;
	}
	gap = max/fatorEncolhimento;
	combSort(vet,gap);
	printf("Mostrando Vetor Ordenado : \t");
	mostrarVetor(vet);
	return(0);
}

void mostrarVetor(int vet[]){
	for(int i=0;i<max;i++){
		printf("%d\t",vet[i]);
	}
}

void combSort(int vet[], int gap){
	/*
	 * Explicando o CombSort :
	 * a função combSort(), recebe um vetor e um valor chamado "gap" o gap nada mais é que um valor que dita onde o atual numero será comparado
	 * o gap inicia, sempre sera o tamanho do vetor dividido por um fator de encolhimento, podendo ser ele 2. Nesse caso, escolhemos o fator 1.24
	 * por ser o com menor custo computacional.
	 *
	 * Comb Sort é um algoritmo de fácil aplicação, se parece muito com um bubbleSort, porem tem uma eficiencia bem superior.
	 * digamos que i é o indice do gap e c, é o indice central (inicial), i vai sempre ter o valor do gap.
	 
	 * Sigamos o exemplo : [2,4,3,6,5,1,8] , gap = 7/1.24 = 5.6, mas como o valor é inteiro ele vai usar apenas o 5.
	 * 
	 *  [(c)2,4,3,6,5,(i)1,8] ---> [1,(c)4,3,6,5,2,(i)8]   
	 *   omo 1 < 2, troca !		como 8>4, Não troca!
	 *
	 * Agora que o i == max, se encerra um ciclo , o gap passado para a recursividade nai ser gap/1.24 ( 5/1.24 = 4), dessa forma o gap vai sempre diminuindo até
	 * chegar a 1.
	 *
	 * Seguindo o exemplo : gap == 4
	 *
	 * [(c)1,4,3,6,5(i),2,8] ---> [1,4(c),3,6,5,2(i),8] ---> [1,2,3(c),6,5,4,8(i)]
	 * como 5>1 Não Troca	      Como 2 < 4 Troca !!         Como 8>3 , Não Troca 
	 *
	 * Proxima chamada da recursividade : gap == 4/1.24 == 3
	 * 
	 *  [1(c),2,3,6(i),5,4,8] --> [1,2(c),3,6,5(i),4,8] --> [1,2,3(c),6,5,4(i),8] --> [1,2,3,6(c),5,4,8(i)] 
	 *  Como 6 > 1 não troca       Como 6 > 1 não troca	Como 6 > 1 não troca	   Como 6 > 1 não troca 
	 *
	 * Proxima chamada da recursividade : gap == 3/1.24 == 2
	 * 
	 *  [1(c),2,3(i),6,5,4,8] --> [1,2(c),3,6(i),5,4,8] --> [1,2,3(c),6,5(i),4,8] --> [1,2,3,6(c),5,4(i),8] --> [1,2,3,4,5(c),6,8(i)]
	 *  Como 3 > 1 não troca      Como 6 > 2 Não Troca	Como 5 > 3 Não Troca	  Como 4 < 6 Troca	    como 8 > 5 Não Troca
	 */
	if(gap != 0){
		int c = 0;
		int trocas;
		for(int i = gap; i<= max; i++){
			if(vet[i] <= vet[c]){
				swap(vet[i],vet[c]);
				trocas++;
			}
			c++;
		}
		if((trocas == 0)&&(gap == 1)){
			
		}else{
			gap = gap/fatorEncolhimento;
			combSort(vet,gap);
		}
	}
}


