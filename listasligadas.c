#include <stdio.h>
#include <stdlib.h>

struct inteiro
{
    int valor;
    struct inteiro* next;
};

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

int main()
{
    struct inteiro *lista = NULL;

    imprimeLista(lista);
    lista = insereInicio(lista, 7);
    printf("\nO primeiro da lista e' %d\n", lista->valor);
    imprimeLista(lista);
    lista = insereInicio(lista, 12);
    printf("\nO primeiro da lista e' %d\n", lista->valor);
    imprimeLista(lista);
    lista = insereFim(lista, 5);
    printf("\nO primeiro da lista e' %d\n", lista->valor);
    imprimeLista(lista);
    lista = insereposicao(lista, 20, 2);
    printf("\nO primeiro da lista e' %d\n", lista->valor);
    imprimeLista(lista);
    return 0;
}