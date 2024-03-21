O trabalho está repartido por 3 ficheiros - CalcMatriz, ListasLigadas e MatrizesLigadas

No ficheiro ListasLigadas.c podemos encontrar funções para tratar operações básicas sobre listas ligadas baseadas numa estrutura que só tem um inteiro e um apontador para o próximo elemento:
- insereInicio - insere um novo elemento no início da lista
- insereFim - insere um novo elemento no fim da lista
- inserePosicao - insere um novo elemento numa determinada posição. A posição é numérica e começa no zero.
- imprimeLista - escreve os elementos todos da lista na consola
- calcularMedia - devolve o cálculo da média dos elementos
- contaElementos - devolve o número de elementos numa lista ligada
- obtemElementoNaPosicao - devolve o elemento que está na posição X da lista. A posição começa no zero
- somaElementos - devolve a soma dos elementos de uma lista
- LimpaMemoria - percorre toda a lista e liberta o espaço de memória ocupado pelos elementos.

No ficheiro MatrizesLigadas.c podemos encontrar funções para tratar operações com Matrizes, mas baseado em listas ligadas:
- matrizRestante - devolve uma matriz mais pequena a partir de uma matriz maior. Da matriz maior remove todos os elementos que façam parte de uma linha ou de uma coluna. É basicamente remover da matriz a linha e a coluna escolhida. A matriz resultante é uma matriz quadrada com dimensão N-1.
- obtemValorMatriz - obtem o valor da matriz na posição (linha, coluna). Na verdade, apenas calcula a posição absoluta na lista ligada e chama a função de ListasLigadas.
- RemoveLinhaMatriz - remove todos os elementos cuja posição se encontra em determina linha. Devolve a matriz resultante sem essa linha.
- RemoveColunaMatriz - remove todos os elementos cuja posição se encontra em determinada coluna. Devolve a matriz resultante sem essa coluna.
- InsereLinhaMatrix - insere uma linha nova na matriz. Todos os novos elementos ficam com valor igual a zero. Para isso tem de determinar a posição em que tem de inserir o primeiro elemento para poder inserir uma linha inteira.
- InsereColunaMatrix - insere uma nova coluna na matriz. Todos os novos elementos ficam com valor igual a zero. Para isso em cada posição tem de saber se está na coluna para inserir. Quando estiver, insere o novo elemento mas também o elemento em que está.
- AlterarValorMatriz - função que encontra um elemento numa determinada posição (linha, coluna) e muda o valor existente para um novo valor.

No ficheiro CalcMatriz, temos a função main, um conjunto de funções de menu, um conjunto de funções auxiliares e finalmente a função CalcMaxSoma que determina a soma máxima da matriz:
- ClearInputBuffer - função que limpa o input buffer para resolver um problema do sistema avançar sem parar.
- ClearConsole - função que limpa o output (consola)
- GetMenuOption - função que obtém do utilizador o valor da opção de menu escolhida.
- InputAnyText - função que pede ao utilizador para fazer ENTER (pausa para ver o que está no ecrã)
- CalcMaxSoma - função para determinar a soma máxima. É uma função recursiva que corre as linhas da matriz e encontra a soma máxima com esse elemento. Para isso determina a soma máxima da matriz sem esse elemento (sem a linha dele nem a coluna dele). Em todos os casos se a soma máxima é maior que a anterior, então muda a lista para a nova lista que tem soma maior. Consegue processar matrizes 10x10 mas à medida que o números de linhas/colunas aumenta para além disso, começa a ficar muito lento. A função só consegue processar em matrizes quadradas.
- DisplayMenu - função que mostra o menu principal
- CalculaSoma - função chamada pelo menu. Faz a verificação de ser matriz quadrada e mostra o resultado.
- countDigits - função auxiliar para determinar quantos dígitos tem um número. Útil para poder mostrar a matriz de forma mais bonita.
- ListagemTabela - função chamada pelo menu para lista a matriz. para isso determina quantos caracteres são necessários para cada elemento para mostrar todos com o mesmo tamanho. Também tem parâmetros para listar o número da coluna ou o número da linha, para melhor identificar. 
- RemocaoLinha - função chamada pelo menu para remover uma linha. Pede ao utilizador qual o número da linha a remover.
- RemocaoColuna - função chamada pelo menu para remover uma coluna. Pede ao utilizador qual o número da coluna a remover.
- InserirLinha - função chamada pelo menu para inserir uma linha vazia na posição que o utilizador escolher.
- InserirColuna - função chamada pelo menu para inserir uma coluna vazia na posição que o utilizador escolher.
- InserirValores  - função chamada pelo menu para alterar um valor da matriz. Pede ao utilizador qual a linha/coluna e também qual o valor a colocar.
- split_string - função auxiliar para dividir uma string conforme um separador.
- CarregarFicheiro - função chamada pelo menu que pede ao utilizador qual o nome do ficheiro (pode incluir um caminho) e qual o separador a usar. Depois limpa a matriz e obtém as linhas do ficheiro. Depois divide as linhas em valores e insere o valor na nova matriz.
- main - função principal, faz um ciclo para mostrar o menu e pede qual a opção. Conforme a opção, chama a respetiva função.
