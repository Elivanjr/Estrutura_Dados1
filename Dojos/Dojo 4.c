#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    //Validador de CPF
    char cpf[11];
    int dv1=0, d1, m1;
    int dv2=0, d2, m2;
    printf("Digite seu CPF: \n");
    scanf("%s", cpf);
    
    //verificando o tamanho da string "cpf"
    int size = strlen(cpf);
    if (size < 11){
        printf("Erro. Digite um CPF com 11 digitos por favor.");
    }else {
        //Digito verificador 1
        for (int i = 0; i < 9; i++) {
            dv1 = dv1 + ((cpf[i] - '0') * (i+1));
        }
        d1 = dv1 % 11;
        if (d1 == 10){
            d1 = 0;
        }
        m1 = cpf[9] - '0';
        
        //Digito verificador 2
        for (int i = 0; i < 10; i++) {
            dv2 = dv2 + ((cpf[i] - '0') * (i));
        }
        d2 = dv2 % 11;
        if (d2 == 10){
            d2 = 0;
        }
        m2 = cpf[10] - '0';
    }
    
    //Verificação de validade
    if (d1 == m1 && d2 == m2) {
        printf("CPF VALIDO. \n");
    }else {
        printf("CPF INVALIDO. \n");
    }
}