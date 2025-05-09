#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int array[], int *n){
	for(int i = 0; i < *n-1; i++){
		for(int j = 0; j < *n-i-1; j++){
			if(array[j] > array[j+1]){
				int aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
			}
		}
	}
}

float mediana(int array[], int *n){
	float med;
	
	if(*n%2){
		med = array[*n/2];
	}else{
		med = (array[(*n/2)-1] + array[*n/2])/2.0;
	}
	
	return med;
}

void moda(int array[], int *n){
	int cont, contMax = 0;
	int moda = array[0];
	for(int i = 0; i < *n; i++){
		cont = 1;
		for(int j = i+1; j < *n; j++){
			if(array[i] == array[j]){
				cont++;
			}
		}
		if(cont > contMax){
			moda = array[i];
			contMax = cont;
		}
	}
	if(contMax > 1){
		printf("\nModa: %i, número de vezes: %i", moda, contMax);
	}else{
		printf("\n Não tem números que se repetem...");		
	}
}

float media(int array[], int *n){
	float total = 0;
	
	for(int i = 0; i < *n; i++){
		total += array[i];
	}
	return total / *n;
}

int main(void){
	
	int vetor[] = {4, 6, 8, 9, 5, 3, 10, 2, 2, 7, 1};
	int tamanho = sizeof(vetor)/sizeof(vetor[0]);
	
	bubbleSort(vetor, &tamanho);
	for(int i = 0; i < tamanho; i++){
		printf("[%i] ", vetor[i]);
	}
	
	printf("\n\n= = = = = = Estatisica básica= = = = = = \n");
	printf("\nMediana: %.2f", mediana(vetor, &tamanho));
	moda(vetor, &tamanho);
	printf("\nMedia: %.2f\n", media(vetor, &tamanho));

	return 0;
}

