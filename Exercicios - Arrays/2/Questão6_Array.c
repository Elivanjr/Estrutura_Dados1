#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Lista de Exercicios 2 - Array, String, Matriz | Questão 6 -> (PODE SER QUE CAIA NA PROVA, REVISE ESSA)

int main(){
	//inicializando variaveis e pedindo dados;
	int n=0, x=0, y=0;
	printf("Digite quantos números deseja sortear: \n");
	scanf(" %i", &n);
	printf("Digite o inicio e o fim do intervalo: \n");
	scanf(" %i %i", &x, &y);

	//colocando a semente pra aleatorios;
	srand(time(NULL));
	int sorteados[n];
	
	//Definindo o intervalo (x,y) usando (max - min + 1) + min;
	for(int i = 0; i < n; i++){
		sorteados[i] = (rand() % (y - x + 1)) + x ;;
	}
	
	
	//Mostrando os números aleatórios;
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%i ", sorteados[i]);
	}
	printf("\n-------------------\n");
	
	
	//eliminando os números que repetem;
	for(int i = 0; i < n; i++){		
		for(int j = i+1; j < n; j++){
			if(sorteados[i] == sorteados[j]){
				sorteados[j] = -1;
			}
		}
		if(sorteados[i] == -1){
			continue;
		}
	}
	
	//mostrando o novo array;
	for(int i = 0; i < n; i++){
		if(sorteados[i] != -1){
			printf("%i ", sorteados[i]);
		}
	}
	return 0;
}
