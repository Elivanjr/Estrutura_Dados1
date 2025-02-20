#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PEDRA 1
#define PAPEL 2
#define TESOURA 3

int main(){
	
	int escolhaU, user=0, pc=0, escolhaPc,rodada=1;
	srand(time(NULL));
	
	do{
		escolhaPc = 1 + rand()%3;
		printf("==========JoKenPô============\n");
		printf("Rodada %d           user: %d\n                   pc: %d \n",rodada, user, pc);
		printf("\n");
		printf("[1] Pedra\n");
		printf("[2] Papel\n");
		printf("[3] Tesoura\n");
		printf("Escolha:\n");
		scanf(" %d", &escolhaU);
		printf("\n");
		printf("User: %02d \n", user);
		printf("PC: %02d \n", pc);
		printf("\n");
		
					switch(escolhaU){
				case PEDRA : 
					printf("User: PEDRA\n");
					break;
				case PAPEL :
					printf("User: PAPEL\n");
					break;
				case TESOURA :
					printf("User: TESOURA \n");
					break;
				}
				
			switch(escolhaPc){
				case PEDRA : 
					printf("Pc: PEDRA\n");
					break;
				case PAPEL :
					printf("Pc: PAPEL\n");
					break;
				case TESOURA :
					printf("Pc: TESOURA \n");
					break;
				}
		
		system("clear");
	if(escolhaU == PAPEL || escolhaU == TESOURA || escolhaU == PEDRA){
		if((escolhaU == PEDRA && escolhaPc == TESOURA) || (escolhaU == PAPEL && escolhaPc == PEDRA) || (escolhaU == TESOURA && escolhaPc == PAPEL)){
				user +=1;
			}else if((escolhaPc == PEDRA && escolhaU == TESOURA) || (escolhaPc == PAPEL && escolhaU == PEDRA) || (escolhaPc == TESOURA && escolhaU == PAPEL)){
				pc += 1;
			}
			if(escolhaPc == escolhaU){
				user +=0;
				pc += 0;
			}
			rodada++;
		}else{
				printf("escolha inválida!\n");
			}
			

				
				if (user == 5 || pc == 5) {
				
					printf("==========JoKenPô============\n");
					printf("Rodada %d           user: %d\n                   pc: %d \n",rodada, user, pc);
					printf("\n");
				
					break;
				}
			}while(1);
			
			if(user == 5){
				printf("User venceu \n");
				}
			if(pc == 5){
				printf("Pc venceu \n");
				}
				
			
	return 0;
}
