#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Lista de Exercicios 2 - Array, String, Matriz | Questão 1
int main(){
	
	//Gerando um vetor que representa o mês;
	int temp[30], maior = 0, menor = 81, diaMa = 0, diaMe = 0, dia=0, soma = 0, ac = 0, me = 0;
	srand(time(NULL));
	
	//Alimentando o vetor com números aleatorios;
	for (int i = 0; i < 30; i++){
		// Definindo o intervalo (12,80) usando (max - min + 1) + min;
		temp[i] = (rand() % (80-12+1))+12;
		//Condicional para determinar a menor e menor temperaturas;
		if (temp[i] > maior){
			maior = temp[i];
			diaMa = i+1;
		}else{
			if (temp[i] < menor) {
				menor = temp[i];
				diaMe = i+1;
			}
		}
		printf("Dia: %i | Temperatura: %i°C \n", i+1, temp[i]);
		dia++;
		soma+= temp[i];
	}
	
	float media = (float)soma/dia;
	// Mostrando maior e menor temperatura, media de temperatura e dias acima da media;
	printf("\nO dia %i teve a maior temperatura: %i°C\n", diaMa, maior);
	printf("O dia %i teve a menor temperatura: %i°C\n", diaMe, menor);
	printf("\nA media de temperatura mensal foi: %.2f°C\n \n", media);
	
	//Faça o printf dos dias acima da media hoje a tarde, quero dormir agora.
		for (int i = 0; i < 30; i++) {
			if (temp[i] > media) {
				ac = i+1;
				me = temp[i];
				printf("O dia %i foi acima da media %.2f°C, seu número foi de : %i°C \n", ac, media, me);
			}
		}
	return 0;
} // fim
