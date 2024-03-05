#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    float num, raiz;
    

    printf("Digite um numero e descubra a sua raiz: ");
    scanf("%f",&num);
    raiz = sqrt(num);
    printf("A raiz de %f e: %f", num, raiz);


    return 0;
}
