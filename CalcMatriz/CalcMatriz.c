#include <stdio.h>
#include <stdlib.h>
#include <ListasLigadas.h>
#include <MatrizesLigadas.h>

struct inteiro* CalculaMaxSoma(struct inteiro* matriz, int linhas)
{
    if (contaElementos(matriz) == 1)
    {
        return insereInicio(NULL, matriz->valor);
    } 

    struct inteiro* resultadoFinal = NULL;
    int somaFinal = 0;

    for (int i = 0; i < linhas; i++)
    {
        struct inteiro* resultado = NULL;
        // determinar elemento atual (valor)
        int valorAtual = obtemValorMatriz(matriz, linhas, i, 0);
        // criar matriz com todos os elementos que não fazem parte da linha i e coluna 0 
        struct inteiro* novaMatriz = matrizRestante(matriz, linhas, i, 0);
        // chamar novamente para calcular a soma da nova matriz 
        resultado = CalculaMaxSoma(novaMatriz, linhas - 1);
        // juntar valor ao resultado da chamada anterior
        resultado = insereInicio(resultado, valorAtual);
        // determinar se a nova soma é maior que a anterior
        int soma = somaElementos(resultado);
        if (soma >= somaFinal)
        {
            resultadoFinal = resultado;
            somaFinal = soma;
        }
    }
    return resultadoFinal;
};

int main()
{
    struct inteiro *matriz = NULL;

    int numeros[] = { 7, 53, 183, 439, 863,
                    497, 383, 563, 79, 973,
                    287, 63, 343, 169, 583,
                    627, 343, 773, 959, 943,
                    767, 473, 103, 699, 303 };

    for (int i = 0; i < 25; i++)
    {
        matriz = insereFim(matriz, numeros[i]);
    }

    struct inteiro* resultado = CalculaMaxSoma(matriz, 5);

    imprimeLista(resultado);

    int soma = somaElementos(resultado);

    printf("A soma final e' %d", soma);

    return 0;
}