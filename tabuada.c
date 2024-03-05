#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numero;
    do
    {
        printf("Insere um numero de 1 a 10 para saber a tabuada, escreve -1 para sair ");
        scanf("%d", &numero);
        if(numero == -1){
            break;
        }
        if(numero < 1 || numero > 10){
            printf("Por favor escolhe um numero entre 1 e 10");
            continue;
        }
        
        for (int i = 1; i <= 10; i++) {
            printf("%d x %d = %d\n", numero, i, numero*i);
        } 
    } while (numero != -1);
    
    
    
    

    return 0;
}
