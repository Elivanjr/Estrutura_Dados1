#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int jaSaiu(int vetor[], int *procura, int *size){
    for(int i = 0; i < *size; i++){
        if(vetor[i] == *procura){
            return 1;
        }
    }
    return 0;
}

void bubbleSort(int vetor[], int *size){
    for(int i = 0; i < *size-1; i=i+1){
        for(int j = 0; j < *size-i-1; j++){
        
        }
    }

}

int main(){
    int vetor[15];
    int random;
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    
    for(int i = 0; i < tamanho;){
        random = 1+rand()%25;
        if(!jaSaiu(vetor, &random, &tamanho)){
            vetor[i] = random;
            i++;
        }
    }
    for(int i = 0; i < tamanho; i++){
        printf("[%02i] ", vetor[i]);
    }
    return 0;
}
