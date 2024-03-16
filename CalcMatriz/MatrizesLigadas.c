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

int obtemValorMatriz(struct inteiro* matriz, int numeroColunas, int linha, int coluna)
{
    // determinar a posicao absoluta do elemento
    int posicao = linha * numeroColunas + coluna;
    // obter o elemento na posicao absoluta 
    struct inteiro* currentElemento = obtemElementoNaPosicao(matriz, posicao);

    return currentElemento->valor;
}

// remover linha de uma matriz
struct inteiro* RemoveLinhaMatrix(struct inteiro* matriz, int numeroLinhas, int numeroColunas, int linhaRemover)
{
    // criar nova matriz para conter os elementos que vao ficar
    struct inteiro* novaMatriz = NULL;

    // determinar posicao do primeiro 
    int posicaoPrimeiro = linhaRemover * numeroColunas + 0;
    // determinar posicao do ultimo 
    int posicaoUltimo = linhaRemover * numeroColunas + numeroColunas - 1;

    // fazer um ciclo para correr a matriz toda
    struct inteiro* currentElemento = matriz;
    int posicao = 0;
    while (currentElemento != NULL)
    {
        // se posicao < 1º a remover, adicionar à nova matriz (no fim)
        if (posicao < posicaoPrimeiro)
        {
            novaMatriz = insereFim(novaMatriz, currentElemento->valor);
        }
        // se posicao > ultimo a remover, adicionar à nova matriz (no fim)
        if (posicao > posicaoUltimo)
        {
            novaMatriz = insereFim(novaMatriz, currentElemento->valor);
        }

        posicao++;
        currentElemento = currentElemento->next;
    }

    // libertar espaço da matriz antiga (toda)

    // devolver nova matriz
    return novaMatriz;
}

// remover coluna de uma matriz
struct inteiro* RemoveColunaMatrix(struct inteiro* matriz, int numeroLinhas, int numeroColunas, int colunaRemover)
{
    // criar nova matriz para conter os elementos que vao ficar
    struct inteiro* novaMatriz = NULL;

    // fazer um ciclo para correr a matriz toda
    struct inteiro* currentElemento = matriz;
    int posicao = 0;
    while (currentElemento != NULL)
    {
        // determinar a coluna do current element
        int colunaElemento = posicao % numeroColunas;
        // se coluna != colunaRemover, adicionar à nova matriz (no fim)
        if (colunaElemento != colunaRemover)
        {
            novaMatriz = insereFim(novaMatriz, currentElemento->valor);
        }

        posicao++;
        currentElemento = currentElemento->next;
    }
    

    
    // libertar espaço da matriz antiga (toda)

    // devolver nova matriz
    return novaMatriz;
}

// inserir linha numa matriz
struct inteiro* InsereLinhaMatrix(struct inteiro* matriz, int numeroLinhas, int numeroColunas, int linhaInserir)
{
    // se linha a inserir >= numeroLinhas
    if (linhaInserir >= numeroLinhas)
    {
        // inserir N (numeroColunas) elementos novos (valor=0)
        for (int i = 0; i < numeroColunas; i++)
        {
            matriz = insereFim(matriz, 0);
        }
        // devolver matriz
        return matriz;
    }

    // criar nova matriz para conter os elementos que vao ficar
    struct inteiro* novaMatriz = NULL;
    
    // fazer um ciclo para correr a matriz toda
    struct inteiro* currentElemento = matriz;
    int posicao = 0;
    while (currentElemento != NULL)
    {
        // determinar a linha do current element
        int linhaElemento = posicao / numeroColunas;
        int colunaElemento = posicao % numeroColunas;
        // se linhaelemento = linhainserir e colunaelemento for 0, inserir N elementos novos
        if (linhaElemento == linhaInserir && colunaElemento == 0)
        {
            for (int i = 0; i < numeroColunas; i++)
            {
                novaMatriz = insereFim(novaMatriz, 0);
            }
        }
        // de qualquer forma inserir todos os elementos
        novaMatriz = insereFim(novaMatriz, currentElemento->valor);

        posicao++;
        currentElemento = currentElemento->next;
    }
    // libertar espaço da matriz antiga (toda)

    // devolver nova matriz
    return novaMatriz;
}

// inserir coluna numa matriz
struct inteiro* InsereColunaMatrix(struct inteiro* matriz, int numeroLinhas, int numeroColunas, int colunaInserir)
{
    // criar nova matriz para conter os elementos que vao ficar
    struct inteiro* novaMatriz = NULL;

    // fazer um ciclo para correr a matriz toda
    struct inteiro* currentElemento = matriz;
    int posicao = 0;
    while (currentElemento != NULL)
    {
        int colunaElemento = posicao % numeroColunas;
        // se coluna != colunaInserir em que insere, adicionar à nova matriz (no fim)
        if (colunaElemento != colunaInserir)
        {
            novaMatriz = insereFim(novaMatriz, currentElemento->valor);
            if (colunaInserir == numeroColunas && colunaElemento == numeroColunas - 1)
            {
                novaMatriz = insereFim(novaMatriz, 0);
            }
        }
        // se posicao == posicao em que insere
        else
        {
            // inserir um elemento novo (valor=0)
            novaMatriz = insereFim(novaMatriz, 0);
            // adicionar current element à nova matriz (no fim)
            novaMatriz = insereFim(novaMatriz, currentElemento->valor);
        }
        posicao++;
        currentElemento = currentElemento->next;
    }
    // libertar espaço da matriz antiga (toda)

    // devolver nova matriz
    return novaMatriz;
}

void AlterarValorMatriz(struct inteiro* matriz, int numeroLinhas, int numeroColunas, int linha, int coluna, int valor) 
{
    // determinar posicao
    int posicao = linha * numeroColunas + coluna;
    // encontrar elemento na posicao
    struct inteiro* currentElemento = matriz;
    int posicaoElementoAtual = 0;
    while (currentElemento != NULL && posicaoElementoAtual != posicao)
    {
        posicaoElementoAtual++;
        currentElemento = currentElemento->next;
    }

    // confirmar
    if (currentElemento == NULL)
    {
        return;
    }

    // alterar valor
    currentElemento->valor = valor;
}