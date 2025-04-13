#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
	int placa;
	char nome[100];
	char modelo[100];
	int status;
	int qdteUsei;
}Cliente;

void wait(){
	printf("\nDigite Enter para continuar...\n");
	setbuf(stdin, NULL);
	getchar();
}

int busca(Cliente pessoas[], int *tamanho, int *chave){
	for(int i = 0; i < *tamanho; i++){
		if(pessoas[i].placa == *chave){
			return i;
		}
	}
	return -1;
}

int interface(){
	system("clear");
	int opcao;
	
	printf("[ - - - - - ESTACIONAMENTO MAYA - - - - - ]\n\n");
	printf("[1] - CADASTRAR NOVO CLIENTE\n");
	printf("[2] - REGISTRAR ENTRADA DE VEICULO\n");
	printf("[3] - REGISTRAR SAIDA DE VEÍCULO\n");
	printf("[4] - RELATÓRIO DE CARROS NO ESTACIONAMENTO\n");
	printf("[0] - ENCERRA O PROGRAMA\n");
	
	printf("\nDigite a opção que deseja acessar:\n");
	scanf(" %i", &opcao);
	return opcao;
}

Cliente cadastraCliente(Cliente pessoas[], int *quantidade){
	system("clear");
	printf("[1] - CADASTRAR NOVO CLIENTE\n\n");
	Cliente aux;
	int existe = 0;
	
	while(1){
		printf("Digite a placa do carro:\n");
		scanf(" %i", &aux.placa);
		
		existe = 0;
		for(int i = 0; i < *quantidade; i++){
			if(aux.placa == pessoas[i].placa){
				existe = 1;
				break;
			}
		}

		if(!existe){
				printf("Digite seu nome: \n");
				scanf(" %[^\n]s", aux.nome);
				printf("Digite o modelo do veiculo em sua posse:\n");
				scanf(" %[^\n]s", aux.modelo);
				printf("Cliente cadastrado com sucesso...\n");
				aux.status = 0;
				aux.qdteUsei = 0;
				break;
		}else if(existe){
			printf("Erro: já existe um cliente cadastrado com esta placa. Por favor, insira uma placa diferente.\n");
		}	
	}
	wait();
	return aux;
}

void entrada(Cliente pessoas[], int *quantidade){
	system("clear");
	printf("[2] - REGISTRAR ENTRADA DE VEICULO\n\n");
	int escolha;
	int estado;
	printf("Informe a placa do veiculo\n");
	scanf(" %i", &escolha);	
	
	int compare = busca(pessoas, quantidade, &escolha);
	
	if(compare != -1 && pessoas[compare].status == 0){
		system("clear");
		printf("[2] - REGISTRAR ENTRADA DE VEICULO\n\n");
		printf("---DADOS CADASTRAIS ---\n");
		printf("Nome do Cliente: %s\n", pessoas[compare].nome);
		printf("Modelo: %s\n", pessoas[compare].modelo);
		printf("Placa: %i\n\n\n", pessoas[compare].placa);
		printf("Deseja entrar no estacionamento? (1 - sim ou 2 - não)\n");
		scanf(" %i", &estado);
		
		if(estado == 1){
			pessoas[compare].status = 1;
			pessoas[compare].qdteUsei++;
			printf("Carro estacionado com sucesso...\n");
		}else if(estado == 2){
			pessoas[compare].status = 0;
			printf("Carro NÃO estacionado com sucesso...\n");
		}
		
	}else if(compare != -1 && pessoas[compare].status == 1){
		printf("Esse veiculo já está estacionado...\n");
	}else {
		printf("Erro ou placa inexistente...\n");
	}
	wait();
}

void saida(Cliente pessoas[], int *quantidade){
	system("clear");
	printf("[3] - REGISTRAR SAIDA DE VEÍCULO\n\n");
	int escolha;
	int estado;
	printf("Informe a placa do veiculo\n");
	scanf(" %i", &escolha);	
	
	int compare = busca(pessoas, quantidade, &escolha);
	
	if(compare != -1 && pessoas[compare].status == 1){
		system("clear");
		printf("[3] - REGISTRAR SAIDA DE VEÍCULO\n\n");
		printf("---DADOS CADASTRAIS ---\n");
		printf("Nome do Cliente: %s\n", pessoas[compare].nome);
		printf("Modelo: %s\n", pessoas[compare].modelo);
		printf("Placa: %i\n\n\n", pessoas[compare].placa);
		printf("Deseja sair do estacionamento? (1 - sim ou 2 - não)\n");
		scanf(" %i", &estado);
		
		if(estado == 1){
			pessoas[compare].status = 0;
			printf("O carro sai do estacionamento com sucesso...\n");
		}else if(estado == 2){
			pessoas[compare].status = 1;
			printf("O carro continua no estacionamento...\n");
		}
		
	}else if(compare != -1 && pessoas[compare].status == 0){
		printf("Esse veiculo nem está estacionado ainda...\n");
	}else {
		printf("Erro ou placa inexistente...\n");
	}
	wait();
}

void relatorio(Cliente pessoas[], int *quantidade){
	system("clear");
	printf("[4] - RELATÓRIO DE CARROS NO ESTACIONAMENTO\n\n");
	
	printf("--- CLIENTES CADASTRADOS ---\n");
	printf("Placa\t\tNome\t\tModelo\t\tSituação\t\tQtde.utilizações\n");
	for(int i = 0; i < *quantidade; i++){
		printf("%-10i\t%-10s\t%-10s\t%-15s\t%-10i\n",
									pessoas[i].placa,
									pessoas[i].nome,
									pessoas[i].modelo,
									pessoas[i].status == 1? "Estacionado": " - ",
									pessoas[i].qdteUsei);
	}
	wait();
}


int main(){
	
	Cliente humanos[100];
	int contHumanos = 0;
	do{
		switch(interface()){
			case 1: humanos[contHumanos] = cadastraCliente(humanos, &contHumanos);
					contHumanos++;
					wait();
					break;
			case 2: if(contHumanos == 0){
						printf("Calmae paizão, cadastre uma placa antes...\n");
						wait();
						humanos[contHumanos] = cadastraCliente(humanos, &contHumanos);
						contHumanos++;
						wait();
					}else{
						entrada(humanos, &contHumanos);
					}
					break;
			case 3: if(contHumanos == 0){
						printf("Calmae paizão, cadastre uma placa antes...\n");
						wait();
						humanos[contHumanos] = cadastraCliente(humanos, &contHumanos);
						contHumanos++;
						wait();
					}else{
						saida(humanos, &contHumanos);
					}
					break;
			case 4: relatorio(humanos, &contHumanos);
					break;
			case 0: return 0;
			
			default: printf("Opção invalida...\n");
					wait();
		}
	
	}while(1);
}
