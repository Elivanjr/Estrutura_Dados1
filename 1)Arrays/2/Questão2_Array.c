#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FALSE 0
#define TRUE 1
//Lista de Exercicios 2 - Array, String, Matriz | Questão 2

int main(){
	int n=0, maior=0, menor=9999999;
	printf("Digite um número: \n");
	scanf(" %i", &n);
	
	int vetor[n];
	int vetorSaiu[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		vetorSaiu[i] = 0;
	}
	
	//Preenchendo o vetor com n numeros aleatorios;
	printf("NÚMEROS SORTEADOS\n"); 
	for (int i = 0; i < n; i++){
		vetor[i] = rand() % n;
		vetorSaiu[vetor[i]]++;
		printf("%i ", vetor[i]);
	}
	
	//Mostrando os números que não foram sorteados;
	printf("\n\nNÚMEROS NÃO SORTEADOS \n");
	for (int i = 0; i < n; i++) {
		if (vetorSaiu[i] == FALSE) {
			printf("%i ", i);
		}
	}
	
	//Verificando os números equivalentes ao indice;
	for (int i = 0; i < n; i++) {
		if (vetor[i] == i) {
			printf("\n\nO número sorteado %i é equivalente o indice %i do vetor.", vetor[i], i);
		}
	}
	//Mostrando os números que já se repetiram
	printf("\n\nFREQUÊNCIA DOS NÚMEROS SORTEADOS\n");
	for (int i = 0; i < n; i++) {
		if (vetorSaiu[i] > 0) { // Verifica se o número foi sorteado
			printf("O número %i saiu umas %i vezes.\n", i, vetorSaiu[i]);
		}
	}

	//O menor valor da metade inicial e maior valor da metade final;
	for(int i = 0; i < n/2; i++) {
		if(vetor[i] < menor)
			menor = vetor[i];
	}
	for (int i = 0; i < n/2; i++) {
		if(vetor[i + n/2] > maior)
			maior = vetor[i+n/2];
	}
	printf("\n\nO menor valor da metade inicial é: %i", menor);
	printf("\nO maior valor da metade final é: %i", maior);
	
	return 0;
}
