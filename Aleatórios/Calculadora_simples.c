
#include <stdio.h>


int main()
{
	int a, b, x;
	char c = '@';
	
	while (c != '#'){
		printf("Insira um número, um sinal de operação e outro número (tecle # para finalizar): \n");
		scanf(" %i %c %i", &a, &c, &b);
		
		switch(c) {
			case '#' : {
				printf("Sinal de operação invalido. \n");
				break;
			}
			case '+' : { 
				x = (a + b);
				printf("O resultado da operação: %i %c %i é %i. \n", a, c, b, x); 
				break;
			}
			case '-' : {
				x = (a - b);
				printf("O resultado da operação: %i %c %i é %i. \n", a, c, b, x);
				break;
			}
			case '*' : {
				x = (a * b);
				printf("O resultado da operação: %i %c %i é %i. \n", a, c, b, x);
				break;
			}
			case '/' : {
				x = (float)a / b;
				printf("O resultado da operação: %i %c %i é %d \n", a, c, b, x);
				break;
			}
		}
		
	};
	
	return 0;
}
