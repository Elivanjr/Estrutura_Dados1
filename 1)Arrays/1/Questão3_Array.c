#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
	int n;
	// Inserindo um número N;
	printf("Escreva um número multiplo de 4: \n");
	scanf(" %i", &n);
	printf("Lista normal \n");

	// Verificando se N é um multiplo de 4;
	if (n%4 == 0) {
		srand(time(NULL));
		int vetor[n];
		int temp[n/2];
	
		//Exibindo os números aleatórios na matriz n;
		for (int i = 0; i < n; i++) {
			vetor[i] = rand() % n;
			printf("%i ", vetor[i]);
		}
		printf(" ");
		printf("\n---------------------\n");
		
		// Trocando os itens da matriz de lugar;
		printf("Lista trocada \n");
		for (int i = 0; i < (n/2); i++) {
			temp[i] = vetor[i];
			vetor[i] = vetor[i + n/2];
			vetor[i + n/2] = temp[i];
			}
			
		// Imprimindo os itens trocados; 
		for (int i = 0; i < (n/2); i++) {
			printf("%i ", vetor[i]);
			}
			printf(" ");
		for (int i = 0; i < (n/2); i++) {
			printf("%i ", vetor[i + n/2]);
			}
	}else{
		if(n%4 != 0)
			printf("Pode não mano, coloca um multiplo de 4 ae \n");
		}
	
	return 0;
}

