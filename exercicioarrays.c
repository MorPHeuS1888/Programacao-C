#include <stdio.h>

int main()
{
    int nums[10];
    
    for (int i = 1; i <= 10; i++)
    {
        printf("Escreva o %d numero: ", i);
        scanf("%d", &nums[i-1]);
    }

    for (int i = 1; i <= 10; i++)
    {
        printf("O numero introduzido na posicao %d foi: %d\n", i, nums[i-1]);
    }
    return 0;
}
