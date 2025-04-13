#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arvorePisca(int tamanho){
	
	srand(time(NULL));
	while(1){
		system("clear");
		for(int i = 0; i < tamanho; i++){
			for(int j = 0; j < tamanho-i-1; j++){
				printf(" ");
			}		
			for(int k = 0;  k < 2 * i + 1; k++){
				if(rand() % 5 == 0){
					printf("O");
				}else{
					printf("*");
				}
			}	 
			printf("\n");
		}

		for(int i = 0; i < 3; i++){
			printf("          ###\n");
		}
		for(int i = 0; i < 2 * tamanho - 1; i++){
			printf("-"); //chao
		}
		printf("\n");
		
		system("sleep 0.5");
	}
}



int main(){


	
	int n = 12;
	arvorePisca(n);


	return 0;
}

