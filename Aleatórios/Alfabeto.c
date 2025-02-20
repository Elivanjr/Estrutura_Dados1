#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ALFAMAX 26

int main(){
	
	//pede uma letra ao usuário
	int letra;
	printf("Escreva um número referente a uma letra do alfabeto: \n");
	scanf("%i", &letra);
	
	//lista com as letras do alfabeto
	char alfa[ALFAMAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	//imprimindo as letras do alfabeto
	if (letra >= 27 || letra == 0) {
		printf("Pode não... Tenta de novo... \n");
	}
	else{
		if (letra <= 26 || letra >= 1){
			for (int i = 0; i < letra; i++){
				printf("%c ", alfa[i]);
			}
			printf("\n");
		}	
	}		
	
	return 0;
}
