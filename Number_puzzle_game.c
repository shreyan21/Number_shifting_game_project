#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
void display(int (*)[4], char *, int);
void rules(int (*)[4]);
int check(int (*)[4], int (*)[4]);
void clearScreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

int main()
{
    int a[4][4] = {{10, 7, 5, 3}, {6, 15, 11, 4}, {9, 1, 13, 8}, {12, 14, 2, 0}};

    int b[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};
    char name[30];
    int l = 3, m = 3;
    int moves = 300;
    printf("Enter your name : ");
    gets(name);
    system("cls");
    rules(a);
    system("cls");
    printf("\e[?25l");
    while (moves>0)
    {
        display(a, name, moves);

        switch (getch())
        {

        case 75:

            if (m <= 2)
            {
                a[l][m] = a[l][m + 1];
                m++;
                a[l][m] = 0;
                moves--;
            }
            break;

        case 72:

            if (l <= 2)
            {
                a[l][m] = a[l + 1][m];
                l++;
                a[l][m] = 0;
                moves--;
            }
            break;

        case 77:

            if (m >= 1)
            {
                a[l][m] = a[l][m - 1];
                m--;
                a[l][m] = 0;
                moves--;
            }
            break;

        case 80:

            if (l >= 1)
            {
                a[l][m] = a[l - 1][m];
                l--;
                a[l][m] = 0;
                moves--;
            }
            break;

        default:
        
            printf("\nThanks for playing , See you next time ..\n");
            // getch();
            exit(0);
        }
      fflush(stdin);
        clearScreen();

        if (check(a, b))
        {
            printf("You won the game :) \n");

            break;
        }
    }
    if (moves == 0)
    {   
        system("cls");
        printf("\n\n You lose the game , Better Luck next time :( \n\n");
        getch();
    }
 
    getch();
    return 0;
}

int check(int (*a)[4], int (*b)[4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i == 3 && j == 3)
            {
                return 1;
            }
            else if (a[i][j] != b[i][j])
                return 0;
        }
    }
}

void rules(int (*a)[4])
{
    printf("\033[1;36m%90s", "** Welcome  To  Number  Shifting  Game **\n\n");

    printf("\033[1;36m%90s", "--- RULES OF THIS GAME ---\n");
    printf("\n\033[1;31m 1. You can move only 1 step at a time by arrow keys");
    printf("\n\033[1;37m Move Up   :   By Up Arrow key");
    printf("\n\033[1;37m Move Down :   By Down Arrow key");
    printf("\n\033[1;37m Move Left :   By Left Arrow key");
    printf("\n\033[1;37m Move Right:   By Right Arrow key");
    printf("\n\n\033[1;31m 2. You can move number at empty position only");
    printf("\n\033[1;31m 3. For each valid move :  Total number of moves get decreased by 1");
    printf("\n\033[1;31m 4. Winning Situation :  Number in a 4*4 matrix should be in order from 1 to 15");
    printf("\n\033[1;31m 5. You can exit anytime by typing 0");
    printf("\n\033[1;31m 6. Maximum moves are 300\n");
    printf("\n\033[1;31m *** If any invalid key is pressed then press tab and then press arrow key***\n");
    printf("    Winning  Condition  -\n");

    int i, j, k = 1;
    printf("\033[1;33m");
    for (i = 0; i < 28; i++)
    {
        printf("-");
    }
    printf("\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (a[i][j] == 0)
            {
                printf("%4c | ", 32);
            }
            else
            {
                printf("%4d | ", k++);
            }
        }
        printf("\n");
    }
    for (i = 0; i < 28; i++)
    {
        printf("-");
    }

    printf("\n So try to win in minimum number of moves\n");
    printf("\n%50s\n", "Happy Gaming , Good Luck :)");
    printf("\nPress enter key to start ....  ");
    getch();
}
void display(int (*a)[4], char *name, int moves)
{
    int i, j;
    printf("\n\n   Hello %s , Moves Remaining %d  \n\n", name, moves);
    for (i = 0; i < 28; i++)
    {
        printf("-");
    }
    printf("\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (a[i][j] == 0)
            {
                printf("%4c | ", 32);
                continue;
            }
            printf("%4d | ", a[i][j]);
        }

        printf("\n");
    }
    for (i = 0; i < 28; i++)
    {
        printf("-");
    }
    printf("\n");
    getch();
}