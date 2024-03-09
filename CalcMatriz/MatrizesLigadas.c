#include <stdlib.h>
#include <stdio.h>
#include <ListasLigadas.h>

struct inteiro* matrizRestante(struct inteiro* matriz, int linhas, int linha, int coluna)
{

	struct inteiro* resultado = NULL;

    struct inteiro* currentElemento = matriz;
    int currentPosition = 0;
    while (currentElemento != NULL)
    {
        // encontrar a linha e coluna de um determinado elemento da matriz 
        int currentLinha = currentPosition / linhas;
        int currentColuna = currentPosition % linhas;
        // determinar se o elemento deve fazer parte da matriz restante
        if (currentLinha != linha && currentColuna != coluna)
        {
            resultado = insereFim(resultado, currentElemento->valor);
        }

        currentElemento = currentElemento->next;
        currentPosition++;
    }

	return resultado;
}

int obtemValorMatriz(struct inteiro* matriz, int linhas, int linha, int coluna)
{
    // determinar a posicao absoluta do elemento
    int posicao = linha * linhas + coluna;
    // obter o elemento na posicao absoluta 
    struct inteiro* currentElemento = obtemElementoNaPosicao(matriz, posicao);

    return currentElemento->valor;
}
