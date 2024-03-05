#include <stdio.h>

int soma(int *a, int*b)
{
    return *a + *b;
}

int main()
{
    int a = 5;
    int b = 7;
    int x;

    x = soma(&a, &b);

    printf("A soma de %d e %d é %d \n",a, b, x);

    return 0;
}