#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <ListasLigadas.h>
#include <MatrizesLigadas.h>

struct inteiro* matriz = NULL;
int numeroLinhas = 0;
int numeroColunas = 0;

void ClearConsole()
{
#ifdef _WIN32
    system("cls");
#else 
    printf("\033[2J\033[H");
#endif
}

int GetMenuOption()
{
    int valor;
    scanf_s("%d", &valor);
    return valor;
}

void InputAnyText()
{
    char input[100]; // Assuming a maximum input length of 100 characters
    fgets(input, sizeof input, stdin);
    fgets(input, sizeof input, stdin);
}

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
        // criar matriz com todos os elementos que n�o fazem parte da linha i e coluna 0 
        struct inteiro* novaMatriz = matrizRestante(matriz, linhas, i, 0);
        // chamar novamente para calcular a soma da nova matriz 
        resultado = CalculaMaxSoma(novaMatriz, linhas - 1);
        // juntar valor ao resultado da chamada anterior
        resultado = insereInicio(resultado, valorAtual);
        // determinar se a nova soma � maior que a anterior
        int soma = somaElementos(resultado);
        if (soma >= somaFinal)
        {
            // TODO limpar memoria do resultado final anterior
            resultadoFinal = resultado;
            somaFinal = soma;
        }
        // TODO limpar memoria da novaMatriz
    }
    return resultadoFinal;
};

void DisplayMenu()
{
    ClearConsole();
    printf("+-------------------------------------------------------------------------------------+\n");
    printf("|                   Estruturas de dados avan�adas - Listas Ligadas                    |\n");
    printf("|                                                                                     |\n");
    printf("|                            1- Carregar a partir de ficheiro de texto                |\n");
    printf("|                            2- Altera��o dos valores                                 |\n");
    printf("|                            3- Inser��o de nova linha                                |\n");
    printf("|                            4- Inser��o de nova coluna                               |\n");
    printf("|                            5- Remo��o de linha                                      |\n");
    printf("|                            6- Remo��o de coluna                                     |\n");
    printf("|                            7- Listagem da Tabela                                    |\n");
    printf("|                            8- C�lculo da soma m�xima                                |\n");
    printf("|                                                                                     |\n");
    printf("|                            9- Exit                                                  |\n");
    printf("|                                                                                     |\n");
    printf("+-------------------------------------------------------------------------------------+\n");
}

void CalculaSoma()
{
    if (numeroLinhas != numeroColunas)
    {
        printf("O calculo da soma maxima so e possivel em matrizes quadradas\n");
        InputAnyText();
        return;
    }

    struct inteiro* resultado = CalculaMaxSoma(matriz, numeroLinhas);

    imprimeLista(resultado);

    int soma = somaElementos(resultado);

    printf("A soma final e' %d", soma);
    getchar();

    // TODO limpar memoria do resultado
}

int countDigits(int n) {
    int count = 0;

    // Handle negative numbers by taking absolute value
    if (n < 0) {
        n = -n;
    }

    // Count digits
    do {
        count++;
        n /= 10;
    } while (n != 0);

    return count;
}

void ListagemTabela()
{
    ClearConsole();
    // Determinar qual o maior valor
    int maior = obtemMaiorValor(matriz);
    // Determinar o numero de digitos do maior valor
    int digitos = countDigits(maior);
    // listar
    for (int linha = 0; linha < numeroLinhas; linha++)
    {
        for (int coluna = 0; coluna < numeroColunas; coluna++)
        {
            // obter valor na linha/coluna
            int valorMatriz = obtemValorMatriz(matriz, numeroLinhas, linha, coluna);

            // Construct the format string dynamically
            char format[10]; // Sufficiently large buffer
            sprintf_s(format, sizeof(format), "%%%dd ", digitos);

            // Append null terminator to format string
            format[sizeof(format) - 1] = '\0';

            // Print the number using the constructed format string
            printf(format, valorMatriz);
        }
        printf("\n");
    }
    printf("Pressiona ENTER para continuar");
    InputAnyText();
}

int main()
{
    int numeros[] = { 7, 53, 183, 439, 863,
                    497, 383, 563, 79, 973,
                    287, 63, 343, 169, 583,
                    627, 343, 773, 959, 943,
                    767, 473, 103, 699, 303 };

    numeroLinhas = 5;
    numeroColunas = 5;

    for (int i = 0; i < 25; i++)
    {
        matriz = insereFim(matriz, numeros[i]);
    }
    
    int option;
    do
    {
        ClearConsole();
        DisplayMenu();
        option = GetMenuOption();
        switch (option)
        {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 7:
            ListagemTabela();
            break;
        case 8: 
            CalculaSoma();
            break;
        case 9:
            break;

        default:
            break;
        }

    } while (option != 9);

    return 0;
}