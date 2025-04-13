#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Lista de Exercicios 2 - Array, String, Matriz | Questão 3 (PODE SER QUE CAIA NA PROVA, REVISE ESSA)

int main() {
    int n = 0, maior, menor, marcaPosicaoMa = 0, marcaPosicaoMe = 0, dif = 0;
    int maisCont = 0, menosCont = 0;

    printf("Digite um número: \n");
    scanf(" %i", &n);

    int vetor[n], controleVetor[n], posicao[n];
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        controleVetor[i] = 0;
	//Coloque 0 em tudo;
    }

    printf("\n       POSIÇÃO\n");
    for (int i = 0; i < n; i++) {
        posicao[i] = i;
        printf("%i ", posicao[i]);
	//Só para garantir que tudo vai correr certo;
    }

    printf("\n");
    printf("-------------------\n");

    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % n; 
        printf("%i ", vetor[i]);
        controleVetor[vetor[i]]++;

        if (i == 0) {
            maior = menor = vetor[i];
        }
        if (vetor[i] > maior) {
            maior = vetor[i];
            marcaPosicaoMa = i;
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
            marcaPosicaoMe = i;
        }
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        if (controleVetor[i] > 0) {
            dif++;
        }
    }

    maisCont = menosCont = controleVetor[0];
    for (int i = 1; i < n; i++) {
        if (controleVetor[i] > maisCont) {
            maisCont = controleVetor[i];
        }
        if (controleVetor[i] < menosCont && controleVetor[i] > 0) {
            menosCont = controleVetor[i];
        }
    }

    printf("\nForam sorteados %i números distintos.\n", dif);
    printf("\nMaior: %i, na posição %i\n", maior, marcaPosicaoMa);
    printf("Menor: %i, na posição %i\n", menor, marcaPosicaoMe);

    printf("\nNúmeros sorteados mais de %i vezes:\n", maisCont);
    for (int i = 0; i < n; i++) {
        if (controleVetor[i] == maisCont) {
            printf("%i ", i);
        }
    }
    printf("\nNúmeros sorteados menos de %i vezes:\n", menosCont);
    for (int i = 0; i < n; i++) {
        if (controleVetor[i] == menosCont) {
            printf("%i ", i);
        }
    }
    printf("\n");
    return 0;
}
