#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//MERCEARIA SOLO - UM PRODUTO
typedef struct{
	int codigo;
	char nome[100];
	int estoque;
	float preco;
}Produto;

void calmaePaizao();
Produto cadastraProduto();
void mostrarProduto(Produto p);
void vendeProduto(Produto *p);

void calmaePaizao(){
	printf("Digite Enter para continuar...\n");
	setbuf(stdin,NULL);
	getchar();
}

Produto cadastraProduto(){
	system("clear");
	Produto novo;
	printf("Insira o código do produto: \n");
	scanf(" %i", &novo.codigo);
	printf("Insira o nome do produto: \n");
	scanf(" %[^\n]s", novo.nome);
	printf("Insira o valor unitário do produto: \n");
	scanf(" %f", &novo.preco);
	printf("Insira a quantidade do produto: \n");
	scanf(" %i", &novo.estoque);
	printf("Cadastro feito...\n");
	calmaePaizao();		
	return novo;
}

void mostrarProduto(Produto p){
	system("clear");
	printf("Código do Produto: %i\nNome do Produto: %s\n"
			"Valor unitário: R$ %.2f\nQuantidade: %i\n",
						p.codigo,
						p.nome,
						p.preco,
						p.estoque);
	calmaePaizao();
}

void vendeProduto(Produto *p){
	system("clear");
	printf("Nome do produto: %s\nQuantidade no estoque: %i\n",
													p->nome,
													p->estoque);
	int desejar = 0;
	printf("Quantidade desejada:\n");
	scanf(" %i", &desejar);
	if(desejar > p->estoque){
		printf("Impossivel. Você quer comprar uma quantidade maior que o estoque.\n");
		calmaePaizao();
		return;
	}
	float total = desejar * p->preco;
	float pagar = 0;
	printf("Valor da compra: R$ %.2f\n", total);
	printf("Quanto pode pagar?\n");
	scanf(" %f", &pagar);
	if(pagar < total){
		printf("Impossivel. Dinheiro insuficiente.\n");
		calmaePaizao();
		return;
	}
	if(pagar == total){
		printf("Compra realizada com sucesso!\n");
		p->estoque -= desejar;
		calmaePaizao();
	}
	float troco = 0;
	if(pagar > total){
		printf("Compra realizada com sucesso!\n");
		p->estoque -= desejar;
		troco = pagar - total;
		printf("Troco: R$ %.2f\n", troco);
		calmaePaizao();
	}
	
}

int main(){
	Produto p;
	p = cadastraProduto();
	printf("\nESTOQUE DA MERCEARIA\n");
	mostrarProduto(p);
	vendeProduto(&p);
	mostrarProduto(p);
	return 0;
}

