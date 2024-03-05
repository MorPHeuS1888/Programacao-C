#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h>
#include <ctype.h>

char BuildingNames[2][5][25] =   
{
    { "Gondor Base", "Shire Mine", "Rohan Barracks", "Lothlorien Stables", "Gondorian Forge Armoury"},
    { "Mordor Base", "Erebor Mine", "Isengard Barracks", "Mirkwood Stables", "Dark Forge Armoury"}     
};

struct PlayerInfo
{
    int Side;
    int CastarCoins; 
};

struct GameInfo
{
    struct PlayerInfo Player1;
    struct PlayerInfo Player2;
    int Turn;
};

struct GameInfo gameInfo;

void ClearConsole()
{
    #ifdef _WIN32
    system("cls");
    #else 
    printf("\033[2J\033[H");
    #endif
}

void GoToXY(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

void SplashScreen()
{
    ClearConsole();
    printf("+-------------------------------------------------------------------------------------+\n");
    printf("|                                                                                     |\n");
    printf("|                             The Lord Of The Rings                                   |\n");
    printf("|                                                                                     |\n");
    printf("|                            Battle for Middle Earth                                  |\n");
    printf("|                                                                                     |\n");
    printf("|                           A Text Based Strategy Game                                |\n");
    printf("|                                                                                     |\n");
    printf("+-------------------------------------------------------------------------------------+\n");
    getchar();
}

void DisplayMenu()
{
    ClearConsole();
    printf("+-------------------------------------------------------------------------------------+\n");
    printf("|                          Battle For Middle Earth                                    |\n");
    printf("|                                                                                     |\n");
    printf("|                            1- New game                                              |\n");
    printf("|                            2- Load Game                                             |\n");
    printf("|                            3- Settings                                              |\n");
    printf("|                                                                                     |\n");
    printf("|                            9- Exit                                                  |\n");
    printf("|                                                                                     |\n");
    printf("+-------------------------------------------------------------------------------------+\n");
}

int GetMenuOption()
{
    int valor;
    scanf("%d",&valor);
    return valor;
}

int ConfirmExit()
{
    char confirmOption;
    // loop
    do
    {
        GoToXY(60, 12);
        printf("Are you sure you want to quit the game (Y/N)?              ");
        GoToXY(106, 12);
        scanf("%c", &confirmOption);
        confirmOption = toupper(confirmOption);
    } while (confirmOption != 'Y' && confirmOption != 'N');
    
    GoToXY(60, 12);
    printf("                                                      ");

    if (confirmOption == 'Y')
    {
        return 1;
    }
    else
    {
        return 0;
    }   
}

void DrawGameGrid()
{
    ClearConsole();
    puts("   A B C D E F G H I J K L M N O P Q R S T U V W X Y Z ");
    for (int i = 0; i <= 34; i++)
    {
        if(i == 0)
        {
            // First Line
            printf("  ┌");
            for (int j = 0; j < 26; j++)
            {
                if(j == 25)
                {
                    printf("─┐");
                }
                else
                {
                    printf("─┬");
                }
            }
            printf("\n");
        } 
        else if (i == 34)
        {
            // Last Line
            printf("  └");
            for (int j = 0; j < 26; j++)
            {
                if(j == 25)
                {
                    printf("─┘");
                }
                else
                {
                    printf("─┴");
                }
            }
            printf("\n");
        }
        else if(i % 2 != 0)
        {
            // Line with Number 
            int lineNumber = i/2;
            printf("%2d│", lineNumber);
            for (int j = 0; j < 26; j++)
            {
                if(j == 25)
                {
                    printf(" │");
                }
                else
                {
                    printf(" │");
                }
            }
            printf("\n");
        }
        else
        {
            // Line Without Number
            printf("  ├");
            for (int j = 0; j < 26; j++)
            {
                if(j == 25)
                {
                    printf("─┤");
                }
                else
                {
                    printf("─┼");
                }
            }
            printf("\n");
        }
    }
    
}

void ChangeTurn()
{
    if(gameInfo.Turn == 1)
    {
        gameInfo.Turn = 2;
    }
    else 
    {
        gameInfo.Turn = 1;
    }
}

void DisplayPlayerMenu()
{
    GoToXY(60, 3);
    printf("Player %d", gameInfo.Turn);
    struct PlayerInfo playerInfo;
    if(gameInfo.Turn == 1)
    {
        playerInfo = gameInfo.Player1;
    }
    else
    {
        playerInfo = gameInfo.Player2;
    }
    GoToXY(60, 4);
    printf("You have %d Castar Coins   ", playerInfo.CastarCoins);

    GoToXY(60, 6);
    printf("Options: ");
    GoToXY(60, 7);
    printf("         1- Building Placement");
    GoToXY(60, 8);
    printf("         2- Unit Movement");
    GoToXY(60, 9);
    printf("         3- Unit Attacks");
    GoToXY(60, 10);
    printf("         9- End Turn");
    GoToXY(60, 11);    
    printf("         0- Exit");
    GoToXY(60, 12);
    printf("   ");
    GoToXY(60, 12);
}

void PlaceBuildings()
{
    struct PlayerInfo playerInfo;
    if(gameInfo.Turn == 1)
    {
        playerInfo = gameInfo.Player1;
    }
    else
    {
        playerInfo = gameInfo.Player2;
    }

    int option;
    do
    {
        GoToXY(60, 13);
        printf("Buildings: ");
        for (int i = 0; i < 5; i++)
        {
            GoToXY(60, 14+i);
            printf("         %d- %s", 1 + i, BuildingNames[playerInfo.Side-1][i]);
        }
        GoToXY(60, 19);    
        printf("         0- Back");
        GoToXY(60, 20);
        printf("   ");
        GoToXY(60, 20);
        option = GetMenuOption();

    } while(option != 0);
    for (int i = 13; i < 21; i++)
    {
        GoToXY(60, i);
        printf("                                                       ");
    }
    
}

void GameLoop()
{    
    int option;
    do
    {
        DisplayPlayerMenu();
        option = GetMenuOption();
        switch (option)
        {
            case 1: // Place Buildings
                PlaceBuildings();
                break;

            case 9: // end turn
                ChangeTurn();
                break;

            case 0: // exit
                int isExit = ConfirmExit();
                if (!isExit)
                {
                    option = -1;
                }
                break;
        
            default:
                break;
        }

    } while(option != 0);

}

void StartNewGame()
{
    // Choose Side
    int option;
    do
    {
        printf("Player one: choose your side\n");
        printf("  1- Gondor/Rivendell    2- Mordor\n");
        option = GetMenuOption();
    } while (option != 1 && option != 2);
    if (option == 1)
    {
        gameInfo.Player1.Side = 1;
        gameInfo.Player2.Side = 2;
    }
    else 
    {
        gameInfo.Player1.Side = 2;
        gameInfo.Player2.Side = 1;
    }
    // Set other Player properties
    gameInfo.Player1.CastarCoins = 100;
    gameInfo.Player2.CastarCoins = 100;

    // Set General Game Properties
    gameInfo.Turn = 1;

    // Draw Game Grid
    DrawGameGrid();

    GameLoop();
}

void LoadGame()
{

}

void Settings()
{

}

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");
    ClearConsole();
    SplashScreen();
    int option;
    do
    {
        DisplayMenu();
        option = GetMenuOption();
        switch (option)
        {
            case 1:
                StartNewGame();
                break;
            case 2:
                LoadGame();
                break;
            case 3:
                Settings();
                break;
            case 9: 
                break;
        
            default:
                break;
        }

    } while(option != 9);
    
    return 0;
}
