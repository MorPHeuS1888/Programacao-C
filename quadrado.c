#include <stdio.h>
#include <math.h>

int calcquadrado(int numero){
    return numero*numero; 
}
int calcpotencia3(int numero){
    return numero*numero*numero;
}

int main(int argc, char const *argv[])
{
    int num;

    printf("Digite um numero para saber o seu quadrado \n");
    printf("Digite o numero: ");
    scanf("%d",&num);
    int quadrado = calcpotencia3(num);
    printf("O quadrado de %d e: %d",num ,quadrado);
    return 0;
}
