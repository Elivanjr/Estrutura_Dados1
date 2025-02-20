
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gconio.h>

int main()
{
	int x, y, z, min = 1, max = 99, cont1=0, cont2=0;
	printf("------- Jogo de advinhação (chad pc vs user) ------- \n");
	
	srand(time(NULL));
	for (int i = 0; i < 1; i++) {
		x = rand() % 100;		
	};

	do {
		printf("Escolha um número: \n");
		scanf(" %d",&y);
	    if ( x > y ){
			printf("O numero escolhido pelo PC é maior que : %d\n", y);
        }
        if ( x < y ){
			printf("O numero escolhido pelo PC é menor que : %d\n", y);
        }
        if ( x == y ){
			printf("VOCÊ ACERTOU!!!\n");
        }
		cont1 ++; 
	}while(y != x);

 	printf("Você teve %d tentativas\n", cont1);
 	

	srand(time(NULL));
	for (int j = 0; j < 1; j++) {
		z = rand() % 100;
		printf("O número que escolheu foi %d? \n", z);
	};	
	
	
 	
 	printf("Você teve %d tentativas. \n", cont2);
 	
	return 0;
};
