#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int n, dado[6] = {0};
	printf("Insira o número de vezes você vai girar o dado no ar: \n");
	scanf(" %i", &n);

	srand(time(NULL));
	for (int i = 0; i < n; i++) {	
		int v = rand() % 6+1;
		dado[v]++;
	}
		
	for (int i = 1; i < 6; i++){
		printf("Face %d apareceu %d vezes.\n", i+1, dado[i]);
	}
	
	return 0;
}
