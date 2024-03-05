#include <stdio.h>

int main(){
    int dia;
    printf("Escreva o dia da Semana: ");
    scanf("%d", &dia);

    switch(dia){
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            printf("O dia é útil");
            break;
        case 7:
        case 8:
            printf("O dia não é útil");
            break;
        default:
            printf("Dia não aceite, por favor escreva número entre 2 e 8");
    }



    return 0;
}