#include <ListasLigadas.h>

#ifndef MATRIZESLIGADAS_H
#define MATRIZESLIGADAS_H

struct inteiro* matrizRestante(struct inteiro* matriz, int linhas, int linha, int coluna);

int obtemValorMatriz(struct inteiro* matriz, int numeroColunas, int linha, int coluna);

// remover linha de uma matriz
struct inteiro* RemoveLinhaMatrix(struct inteiro* matriz, int numeroLinhas, int numeroColunas, int linhaRemover);

// remover coluna de uma matriz
struct inteiro* RemoveColunaMatrix(struct inteiro* matriz, int numeroLinhas, int numeroColunas, int colunaRemover);

// inserir linha numa matriz
struct inteiro* InsereLinhaMatrix(struct inteiro* matriz, int numeroLinhas, int numeroColunas, int linhaInserir);

// inserir coluna numa matriz
struct inteiro* InsereColunaMatrix(struct inteiro* matriz, int numeroLinhas, int numeroColunas, int colunaInserir);

// Alterar valor numa posicao da matriz
void AlterarValorMatriz(struct inteiro* matriz, int numeroLinhas, int numeroColunas, int linha, int coluna, int valor);

#endif