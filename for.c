#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num;
    
    printf("Introduza um numero natural: ");
    scanf("%d", &num);
    for (int i = num;i > 0; i--) {
      if(i % 2 == 0){
        printf("%d\n", i);
      }      
    }

    printf("Introduza um numero natural: ");
    scanf("%d", &num);
    int j = num;
    while (j > 0) {
        if(j % 2 == 0){
            printf("%d\n", j);
        }
        j--;
    }
    int k = 1;
    printf("Introduza um numero natural: ");
    scanf("%d", &num);
    do {
        if(k % 2 == 0){
            printf("%d\n", k);
        }
        k++;
    } while (k <= num);
    

    return 0;
}
