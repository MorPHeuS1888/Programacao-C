#include <stdio.h>

void mostraArray(int* firstelement, int size)
{
    int* currentelement = firstelement;

    for (int i = 0; i < size; i++)
    {
        printf("Na posicao %d, o valor e: %d \n", i, *currentelement);
        currentelement++;
    }
    
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int acharMaior(int* c, int* d)
{
    if (*c > *d)
    {
        return *c;
    }else
    {
        return *d;
    }
    
}

int soma(int* a, int* b)
{
    return *a + *b;
}

int main()
{
    int array[] = {1, 2, 4, 5, 7, 8};
    int a = 5;
    int b = 7;
    int x;

    x = soma(&a, &b);

    printf("A soma de %d e %d é %d \n",a, b, x);

     x = acharMaior(&a, &b);

    printf("O maior entre %d e %d é %d \n",a, b, x);

    swap(&a, &b);
    printf("O novo valor de a e %d, e o novo valor de b e %d \n", a, b);

    mostraArray(array, 6);

    return 0;
}