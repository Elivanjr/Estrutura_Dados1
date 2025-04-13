#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int num1 = -1, array[100], cont=0;
	srand(time(NULL));
	
	for (int i = 1; i < 101; i++){
		array [100] = 1 + rand() % 20;
		printf("Nº: %02i \n", array[100]);
		
	}
	while (num1 <= 0) {
		printf("Digite um número: \n");
		scanf(" %i", &num1);
		
		if (num1 != 0) {
			for (int i = 0; i < 101; i++)
				if (num1 == array[i]) {
					cont++;
					}
			}
	}
	
	 if (cont > 0) {
        printf("O número %d apareceu %d vezes no array. \n", num1, cont);
    } else {
        printf("O número %d não foi encontrado no array. \n", num1);
    }
	
	return 0;
}

