#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Lista de Exercicios 2 - Array, String, Matriz | Questão 4 (PODE SER QUE CAIA NA PROVA, REVISE ESSA)

int main(){
    int x, y, j;
    
    printf("Digite os valores consecutivamente para X e Y: \n");
    scanf(" %i %i", &x, &y);

    int tSoma = x + y;
    int vetor1[x], vetor2[y], temp, soma[tSoma];
    srand(time(NULL));

    for (int i = 0; i < tSoma; i++){
        soma[i] = i;
    }
    if (x <=0 || y <= 0){
        printf("Pode não mano, põe dois numeros maiores que zero.");
    }else{
        //Gambiarra que sorteia numeros que não repetem;
        for(int i = tSoma - 1; i > 0; i--){
            j = rand() % (i+1);
            temp = soma[i];
            soma[i] = soma[j];
            soma[j] = temp;
        }
        for(int i = 0; i < x; i++){
            vetor1[i] = soma[i];
        }
        for(int i = 0; i < y; i++){
            vetor2[i] = soma[i+x];
        }
        
        //Item A - Vetores X e Y;
        printf("\nVetor X\n");
        for(int i = 0; i < x; i++){
            printf("%i ", vetor1[i]);
        }
        printf("\nVetor Y\n");
        for(int i = 0; i < y; i++){
            printf("%i ", vetor2[i]);
        }
    }

    return 0;
}
