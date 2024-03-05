#include <stdio.h>

int main(int argc, char const *argv[]){
    
    int numeros[100];
    int max = 100;

    printf("Escreva ate cem numeros ou termine com zero.\n");

    for (int i = 0; i < 100; i++){
        printf("Escreva o numero %d: ",i);
        scanf("%d",&numeros[i]);    

        if (numeros[i] == 0){
            max = i;
            break;
        }
    }
    for (int i = 0; i < max; i++){
        
        if (numeros[i] < 0){
            printf("%d\n",numeros[i]);
        }
    }
    
        
    return 0;
}
