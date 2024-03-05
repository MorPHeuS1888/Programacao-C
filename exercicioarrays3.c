#include <stdio.h>

int main()
{
    //guardar numeros de telemovel 
    int numeros[10];
    
    for (int i = 1; i <= 10; i++)
    {
        printf("Escreva o %d numero: ", i);
        scanf("%d", &numeros[i-1]);
    }

    for (int i = 1; i <= 10; i++)
    {
        printf("Os numeros guardados foram: %d\n", numeros[i-1]);
    }
    
    return 0;
}