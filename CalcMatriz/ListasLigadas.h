#include <stdio.h>
#include <stdlib.h>
#ifndef LISTASLIGADAS_H
#define LISTASLIGADAS_H

struct inteiro
{
    int valor;
    struct inteiro* next;
};

struct inteiro* insereInicio(struct inteiro* lista, int valor);

struct inteiro* insereFim(struct inteiro* lista, int valor);

struct inteiro* insereposicao(struct inteiro* lista, int valor, int posicao);

void imprimeLista(struct inteiro* lista);

float calcularMedia(struct inteiro* lista);

int contaElementos(struct inteiro* lista);

struct inteiro* obtemElementoNaPosicao(struct inteiro* lista, int posicao);

int somaElementos(struct inteiro* lista);

#endif 