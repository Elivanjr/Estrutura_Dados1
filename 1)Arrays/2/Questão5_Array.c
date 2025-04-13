#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Lista de Exercicios 2 - Array, String, Matriz | Questão 5

int main(){
	
	int n, x = 10, y = 30, sortCont = 0;
	
	printf("Digite um número: \n");
	scanf(" %i", &n);
	srand(time(NULL));
	
	int numeroS[n];
		
	//Números aleatorios dentro do intervalo X e Y(max - min + 1) + min;
	for(int i = 0; i < n; i++){
		numeroS[i] = (rand() % (y - x + 1)) + x;
	}
	
	//Mostrando o vetor dentro do intervalo X e Y;
	for(int i = 0; i < n; i++){
		printf("%i ", numeroS[i]);
	}
	
	//Mostrando a posição do menor numero sorteado;
	for(int j = 0; j < n; j++){
		int menorsorteado = 99;
		for(int i = 0; i < n; i++){
			if(numeroS[i] < menorsorteado){
				menorsorteado = numeroS[i];
				sortCont = i;
			}
		}
		printf("\n");
		printf("O %i° menor número é o %i, localizado na posição %i.", j+1, menorsorteado, sortCont);
		//Ex: O 1° menor número é o 11, localizado na posição 2.
		numeroS[sortCont] = 99;	
	}
	
	return 0;
}
