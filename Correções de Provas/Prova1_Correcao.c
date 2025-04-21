#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void grafico(int valores[], int *numero){
	int i = 0;
	
	for(;i < *numero;){
		valores[i] = (rand()% (*numero)*2) + 1;
		printf("Dia %02i: %02i ", i+1, valores[i]);
		
		int j = 0;
		for(; j < valores[i];){
			printf("-");
			j++;
		}
		printf("\n");
		i++;
	}// testando um "for" com estrutura diferente;
}

void analiseDados(int valores[], int *numero){
	int boaCompra = 0, lucro = 0, lucroMaximo = 0;
	int boaVenda = 0, intervalo = 0, aux = 0;
	
	for(int i = 0; i < *numero; i++){
		for(int j = i+1; j < *numero; j++){
			lucro = valores[i] - valores[j];
			intervalo = i - j;
			
			if(lucro > lucroMaximo || (lucro == lucroMaximo && intervalo < aux)){
				lucroMaximo = lucro;
				boaCompra = i;
				boaVenda = j;
				aux = intervalo;
			}
		}
	}
	
	printf("Resultado da Análise:\n");
	printf("Melhor dia para compra: Dia %02i - R$ %i\n", boaCompra+1, valores[boaCompra]);
	printf("Melhor dia para venda: Dia %02i - R$ %i\n",  boaVenda+1, valores[boaVenda]);
	printf("Lucro Obtido: R$ %i\n", lucroMaximo);
}

int main(){

	printf("----------- BOLSA DA VALORES M.A.Y.A -----------\n\n");	
	srand(time(NULL));
	
	int n;
	printf("Informe a quantidade de dias no periodo:\n");
	scanf(" %i", &n);
	printf("\n");
	
	int dias[n];	
	
	grafico(dias, &n);
	analiseDados(dias, &n);

	return 0;
}

