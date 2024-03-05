#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num1, num2;

    printf("Digite dois numeros e descubra qual o maior \n");
    printf("Digite o primeiro: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    
    if(num1 > num2){
        printf("O numero maior e %d ",num1);        
    }
    else if(num1 = num2){
        printf("Os numeros inseridos sao iguais");        
    }
    else{
        printf("O numero maior e %d ",num2);
    }
    
    return 0;
}
