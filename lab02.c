#include <stdio.h>

int main(){
    float valor;
    float taxa;
    float imposto;

    printf("Introduza o Valor: ");
    scanf("%f", &valor);
    if(valor<100){
        taxa = 0.12;
    } else if(valor<500){
        taxa = 0.18;
    } else {
        taxa = 0.23;
    }
    imposto = valor * taxa;
    printf("O imposto é: %f",imposto);

    return 0;
}