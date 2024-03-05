#include <stdio.h>

int main(){
    int valor;

    printf("Introduza o Valor: ");
    scanf("%d", &valor);
    if(valor % 2 == 0){
        printf("O Valor é Par");   
    }  else{
        printf("O Valor é Ímpar");
    }


    return 0;
}