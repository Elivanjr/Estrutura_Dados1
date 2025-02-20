#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define PARTIDA 10
#define PISTA 60
#define CHEGADA 10

typedef struct{
	char nome[10];
	char simbolo;
	int posicao;
}Personagem;

int main(){
	srand(time(NULL));
	int n;
	printf("Digite quantos corredores: \n");
	scanf(" %i", &n);
	
	Personagem corredores[n];
	
	//recebe dados
	for(int i = 0; i < n; i++){
		do{
			printf("Nome do corredor: \n");
			scanf(" %s", corredores[i].nome);
		}while(strlen(corredores[i].nome) > 10);
		
		printf("Simbolo do corredor: \n");
		scanf(" %c", &corredores[i].simbolo);
			
		corredores[i].posicao = 0;
	}
	
	do{
		//veririca vencedor
		int cont=0;
		char vencedor[10];
		for(int i=0; i<n; i++)
			if(corredores[i].posicao==PISTA+CHEGADA){ 
				cont++;
				strcpy(vencedor, corredores[i].nome);
			}
		
		for(int i=0; i<n-1; i++)
			for(int j=0; j<n-i-1; j++)
				if(corredores[j].posicao<corredores[j+1].posicao){
					Personagem aux=corredores[j];
					corredores[j]=corredores[j+1];
					corredores[j+1]=aux;
				}
		
		//printa
		system("clear");
		for(int i = 0; i < n; i++){
			printf("%-10s ", corredores[i].nome);
			for (int j = 0; j<PISTA+CHEGADA+1; j++){
				if(j<corredores[i].posicao)
					printf("%c", corredores[i].simbolo);
				else if(j<PISTA+CHEGADA)
					printf(" ");
				else
					printf("|\n");
			}
			corredores[i].posicao+=rand()%3+1;
			if(corredores[i].posicao>PISTA+CHEGADA)
				corredores[i].posicao=PISTA+CHEGADA;
		}

		//caso tenha vencedor ou empate quebra
		if(cont==1){
			printf("vencedor: %s", vencedor);
			break;
		}
		if(cont>1){
			printf("empate");
			break;
		}
		
		system("sleep 0.2");
	}while(1);
	return 0;
}

