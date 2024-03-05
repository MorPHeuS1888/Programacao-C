#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numeros[10];
    
    for (int i = 0; i < 10; i++)
    {
        printf("Escreva o numero %d: ",i);
        scanf("%d",&numeros[i]);    
    }
    
    for (int i = 0; i < 10; i++)
    {
        printf("Na posicao %d esta o valor %d \n", i, numeros[i-1]);
    }
    

    return 0;
}
