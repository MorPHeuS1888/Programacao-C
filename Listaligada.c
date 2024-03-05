#include <stdio.h>
#include <stdlib.h>

struct inteiro
{
    int valor;
    struct inteiro* next;
};

struct inteiro* insereinicio(struct inteiro* lista, int valor)
{         
     struct inteiro* novoElemento = malloc(sizeof(struct inteiro)); //determina o tamanho da estrutura em bytes(sizeof), 
     novoElemento->valor = valor;                                   //o malloc aloca espaço em memoria para conter o resultado do sizeof e devolve um apontador para o espaço alocado
     novoElemento->next = lista;                                   // o apontador chama-se novoElemento
     return novoElemento;
}

struct inteiro* inserefim(struct inteiro* lista, int valor)
{         
    struct inteiro* novoElemento = malloc(sizeof(struct inteiro)); 
    novoElemento->valor = valor;                                   
    novoElemento->next = NULL;
    
    // devolver novo elemento se lista for vazia
    struct inteiro* elementoAtual = lista;
    if (elementoAtual == NULL)
    {
        return novoElemento;
    }
    // ENCONTRAR O ULTIMO DA LISTA
    while (elementoAtual->next != NULL)
    {
        elementoAtual = elementoAtual->next;
    }
    // Apontar para o novo elemento                                   
    elementoAtual->next = novoElemento;
    return lista;
}

int main()
{
    struct inteiro* lista = NULL;
    lista = insereinicio(lista, 7);
    lista = insereinicio(lista, 12);
    lista = inserefim(lista, 6);
}