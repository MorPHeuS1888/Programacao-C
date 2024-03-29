#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ListasLigadas.h>
#include <MatrizesLigadas.h>


struct inteiro* matriz = NULL;
int numeroLinhas = 0;
int numeroColunas = 0;

void ClearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

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
            // limpar memoria do resultado final anterior
            LimpaMemoria(resultadoFinal);
            resultadoFinal = resultado;
            somaFinal = soma;
        }
        // limpar memoria da novaMatriz
        LimpaMemoria(novaMatriz);
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
    InputAnyText();

    // limpar memoria do resultado
    LimpaMemoria(resultado);
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

void ListagemTabela(int mostralinhas, int mostracolunas, int mostramaisum)
{
    ClearConsole();
    // Determinar qual o maior valor
    int maior = obtemMaiorValor(matriz);
    // Determinar o numero de digitos do maior valor
    int digitos = countDigits(maior);
    // Construct the format string dynamically
    char format[10]; // Sufficiently large buffer
    sprintf_s(format, sizeof(format), "%%%dd ", digitos);
    // listar
    for (int linha = 0; linha < numeroLinhas; linha++)
    {
        if (mostralinhas)
        {
            printf(format, linha);
        }
        for (int coluna = 0; coluna < numeroColunas; coluna++)
        {
            // obter valor na linha/coluna
            int valorMatriz = obtemValorMatriz(matriz, numeroColunas, linha, coluna);
            // Append null terminator to format string
            format[sizeof(format) - 1] = '\0';

            // Print the number using the constructed format string
            printf(format, valorMatriz);
        }
        printf("\n");
    }
    if (mostralinhas && mostramaisum)
    {
        printf(format, numeroLinhas);
        printf("\n");
    }

    if (mostracolunas)
    {
        for (int coluna = 0; coluna < numeroColunas; coluna++)
        {
            printf(format, coluna);
        }
        if (mostracolunas && mostramaisum)
        {
            printf(format, numeroColunas);
        }
        printf("\n");
    }
}

void RemocaoColuna()
{
    ClearConsole();
    ListagemTabela(0, 1, 0);
    printf("Qual o numero da coluna que quer remover? ");
    int numeroColuna;
    scanf_s("%d", &numeroColuna);
    if (numeroColuna < 0 || numeroColuna >= numeroColunas)
    {
        printf("Numero de coluna errado");
        InputAnyText();
        return;
    }
    // remover a coluna escolhida
    matriz = RemoveColunaMatrix(matriz, numeroLinhas, numeroColunas, numeroColuna);
    numeroColunas--;
    printf("Coluna removida :)");
    InputAnyText();
}

void RemocaoLinha()
{
    ClearConsole();
    ListagemTabela(1, 0, 0);
    printf("Qual o numero da linha que quer remover? ");
    int numeroLinha;
    scanf_s("%d", &numeroLinha);
    if (numeroLinha < 0 || numeroLinha >= numeroLinhas)
    {
        printf("Numero de linha errado");
        InputAnyText();
        return;
    }
    // remover a linha escolhida
    matriz = RemoveLinhaMatrix(matriz, numeroLinhas, numeroColunas, numeroLinha);
    numeroLinhas--;
    printf("linha removida :)");
    InputAnyText();
}

void InserirLinha()
{
    ClearConsole();
    ListagemTabela(1, 0, 1);
    printf("Em que posicao quer inserir a linha? ");
    int numeroLinha;
    scanf_s("%d", &numeroLinha);
    if (numeroLinha < 0 || numeroLinha > numeroLinhas)
    {
        printf("Numero de linha errado");
        InputAnyText();
        return;
    }
    // inserir a linha na posicao escolhida
    matriz = InsereLinhaMatrix(matriz, numeroLinhas, numeroColunas, numeroLinha);
    numeroLinhas++;
    printf("linha inserida :)");
    InputAnyText();
}

void InserirColuna()
{
    ClearConsole();
    ListagemTabela(0, 1, 1);
    printf("Em que posicao quer inserir a coluna? ");
    int numeroColuna;
    scanf_s("%d", &numeroColuna);
    if (numeroColuna < 0 || numeroColuna > numeroColunas)
    {
        printf("Numero de coluna errado");
        InputAnyText();
        return;
    }
    // inserir a coluna na posicao escolhida
    matriz = InsereColunaMatrix(matriz, numeroLinhas, numeroColunas, numeroColuna);
    numeroColunas++;
    printf("Coluna inserida :)");
    InputAnyText();
}

void InserirValores()
{
    ClearConsole();
    ListagemTabela(1, 0, 0);
    printf("Em que linha quer inserir o valor? ");
    int numeroLinha;
    scanf_s("%d", &numeroLinha);
    while (numeroLinha < 0 || numeroLinha > numeroLinhas)
    {
        printf("Numero de linha errado");
        InputAnyText();
        return;
    }

    ClearConsole();
    ListagemTabela(0, 1, 0);
    printf("Em que coluna quer inserir o valor? ");
    int numeroColuna;
    scanf_s("%d", &numeroColuna);
    while (numeroColuna < 0 || numeroColuna > numeroColunas)
    {
        printf("Numero de coluna errado");
        InputAnyText();
        return;
    }
    
    printf("�Qual o valor que quer inserir? ");
    int valor;
    scanf_s("%d", &valor);
    while (valor < 0)
    {
        printf("Valor errado");
        InputAnyText();
        return;
    }

    // alterar o valor na posicao escolhida
    AlterarValorMatriz(matriz, numeroLinhas, numeroColunas, numeroLinha, numeroColuna, valor);
    printf("Valor alterado :)");
    InputAnyText();
}

void split_string(char* str, char delimitador, char* tokens[], int* num_tokens) {
    char* ptr = str;
    char* ptr1 = str;
    int i = 0;

    while (*ptr != '\0') 
    {
        if (*ptr == delimitador)
        {
            *ptr = '\0'; // Substitui o espa�o por um caractere nulo
            tokens[i] = ptr1; // Armazena o endere�o do token
            ptr++; // Avan�a o ponteiro para o pr�ximo caractere
            ptr1 = ptr;
            i++;
        }
        else {
            ptr++; // Avan�a o ponteiro para o pr�ximo caractere
        }
    }

    tokens[i] = ptr1; // Armazena o �ltimo token
    *num_tokens = i + 1; // N�mero de tokens
}

void CarregarFicheiro()
{
    printf("Qual � o nome do ficheiro que quer carregar? ");
    char input[255]; // Assuming a maximum input length of 255 characters
    scanf_s("%s", input, (unsigned)_countof(input));
    FILE* file = fopen(input, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir ficheiro! :( ");
        InputAnyText();
        return;
    }
    ClearInputBuffer();

    printf("Qual � o caracter para usar como separador? ");
    char separador;
    scanf_s("%c", &separador, 1);

    // limpar a matriz
    LimpaMemoria(matriz);

    matriz = NULL;
    numeroColunas = 0;
    numeroLinhas = 0;

    char line[255];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        numeroLinhas++;
        char* tokens[255]; // Array de tokens
        int num_tokens;
        split_string(line, separador, tokens, &num_tokens);
        numeroColunas = num_tokens;
        for (int i = 0; i < num_tokens; i++)
        {
            if (tokens[i] != NULL) 
            {
                int valor = atoi(tokens[i]);
                matriz = insereFim(matriz, valor);
            }
        }
    }
    fclose(file);
    printf("O ficheiro foi carregado! :)");
    InputAnyText();
}

int main()
{
  
    int option;
    do
    {
        ClearConsole();
        DisplayMenu();
        option = GetMenuOption();
        switch (option)
        {
        case 1:
            CarregarFicheiro();
            break;
        case 2:
            InserirValores();
            break;
        case 3:
            InserirLinha();
            break;
        case 4:
            InserirColuna();
            break;
        case 5:
            RemocaoLinha();
            break;
        case 6: 
            RemocaoColuna();
            break;
        case 7:
            ListagemTabela(0, 0, 0);
            printf("Pressiona ENTER para continuar");
            InputAnyText();
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