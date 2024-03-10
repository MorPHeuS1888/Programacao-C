#include <stdio.h>
#include <stdlib.h>
#include <ListasLigadas.h>

struct inteiro* insereInicio(struct inteiro* lista, int valor)
{
    struct inteiro* novoElemento = malloc(sizeof(struct inteiro));
    novoElemento->valor = valor;
    novoElemento->next = lista;
    return novoElemento;
}

struct inteiro* insereFim(struct inteiro* lista, int valor)
{
    struct inteiro* novoElemento = malloc(sizeof(struct inteiro));
    novoElemento->valor = valor;
    novoElemento->next = NULL;

    if (lista == NULL)
    {
        return novoElemento;
    }
    else
    {
        // encontrar o ultimo da lista
        struct inteiro* currentElemento = lista;
        while (currentElemento->next != NULL)
        {
            currentElemento = currentElemento->next;
        }
        currentElemento->next = novoElemento;
        return lista;
    }
}

struct inteiro* insereposicao(struct inteiro* lista, int valor, int posicao)
{
    // criar o novo elemento
    struct inteiro* novoElemento = malloc(sizeof(struct inteiro));
    novoElemento->valor = valor;
    novoElemento->next = NULL;  
    // caso especial - lista vazia
    if (lista == NULL)
    {
        return novoElemento;    
    }
    // 2nd caso especial - inserir no inicio
    if (posicao <= 0)
    {
        novoElemento->next = lista;
        return novoElemento;
    }
    // posicionar no sitio certo
    struct inteiro* currentElement = lista;
    int currentPosition = 0;
    while (currentPosition < posicao - 1 && currentElement->next != NULL)
    {
        currentElement = currentElement->next;
        currentPosition++; 
    }
    // mudar os valores
    novoElemento->next = currentElement->next;
    currentElement->next = novoElemento;
    return lista;
}

void imprimeLista(struct inteiro* lista)
{
    int posicao = 0;
    struct inteiro* listatemp = lista; 
    while (listatemp != NULL)
    {
        printf("O elemento numero %d e' %d\n", posicao, listatemp->valor); 
        posicao = posicao + 1;
        listatemp = listatemp->next;
    }
    
}

float calcularMedia(struct inteiro* lista) 
{
    int total = 0;
    int somatotal = 0;
    float media = 0.0;
    struct inteiro* currentElemento = lista;
    
    while (currentElemento != NULL)
    {
        total += currentElemento->valor;
        somatotal++;
        currentElemento = currentElemento->next;
    }
    
    if (somatotal != 0)
    {
        media = (float)total / somatotal;
        printf("A media dos numeros inteiros na lista e: %f\n", media);
    }
    return media;
}

int contaElementos(struct inteiro* lista)
{
    struct inteiro* currentElemento = lista;
    int contador = 0;
    while (currentElemento != NULL)
    {
        contador++;
        currentElemento = currentElemento->next;
    }
    return contador;
}

struct inteiro* obtemElementoNaPosicao(struct inteiro* lista, int posicao)
{
    // caso especial - lista vazia
    if (lista == NULL)
    {
        return NULL;
    }
    // 2nd caso especial - inserir no inicio
    if (posicao <= 0)
    {
        return lista;
    }
    // posicionar no sitio certo
    struct inteiro* currentElement = lista;
    int currentPosition = 0;
    while (currentPosition < posicao - 1 && currentElement->next != NULL)
    {
        currentElement = currentElement->next;
        currentPosition++;
    }

    return currentElement->next;
}

int somaElementos(struct inteiro* lista)
{
    struct inteiro* currentElemento = lista;
    int soma = 0;
    while (currentElemento != NULL)
    {
        soma = soma + currentElemento->valor;
        currentElemento = currentElemento->next;
    }
    return soma;
}

int obtemMaiorValor(struct inteiro* lista) 
{
    struct inteiro* currentElemento = lista;
    int maior = 0;
    while (currentElemento != NULL)
    {
        if(currentElemento->valor > maior)
        {
            maior = currentElemento->valor;
        }
        currentElemento = currentElemento->next;
    }
    return maior;
}