#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define myY 15
#define myX 40

char map[myY][myX], key;
int alive = 1, x, y,niv = 1, score = 0, dirX, dirY, oldBodyCor[myY*myX][2], body[myY*myX][2], numOfBody = 0,Choix;
int *speed;

int Menu();
void genMap();
void grow();
void genDefDir();
void kInp();
void genPlayer();
void genEnemy();
void draw();
void move();
void freeMove();
//void reset();
void hideCursor();
int gameSpeed (int niv,int *speed);
void goToXY(int column, int line);




int Menu()
{
    do
    {
        system("cls"); // efface l'้cran
        printf("             ษออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
        printf("             บ                                                      บ\n");
        printf("             บ                    Snake_game                       บ\n");
        printf("             บ                                                      บ\n");
        printf("             ศออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        printf("\n\n                 1- play");
        printf("\n                 2- difficult");
        printf("\n                 3- exit\n");
        printf("\n\n\n\n\n\n\nChoix :");
        scanf("%d",&Choix);

    }
    while (Choix <1 || Choix >3);
    return Choix;
}
int main()
{   label1 :

    Choix = Menu();
    while (Choix!=3)
    {
        switch (Choix)
        {
        case 1 :
            hideCursor();
            do
            {
                genMap();
                genPlayer();
                genDefDir();
                genEnemy();
                while (alive)
                {
                    speed = gameSpeed(niv,speed);
                    Sleep(speed);
                    kInp();
                    move();
                    draw();
                }
                system("cls");
                while (1)
                {
                    goToXY(0, 0);
                    printf("!!!!!!!Game Over!!!!!!!\n");
                    printf("\n FINAL SCORE : %d\n", score);
                    printf("\n Do you want to try again?[y/n]\n");
                    printf("\n yes <<ออ>> [y]\n");
                    printf("\n no _<<ออ>> [n]\n");
                    key = _getch();
                    if ((key == 'y')||(key == 'Y'))
                    {
                        score = 0;
                        alive = 1;

                        goto label1;


                    }
                    else if ((key == 'n')||(key == 'N'))
                    {
                        EXIT_SUCCESS;
                        break;
                    }


                }
            }
            while (alive);

        case 2 :
            do
            {
                printf("\n              ************    ");
                printf("\n******    **   difficult   **    ******\n");
                 printf("              ************    \n");
                printf("\n                 1- easy");
                printf("\n                 2- normal");
                printf("\n                 3- hard\n");

                scanf("%d",&niv);
                Choix = Menu();
            }
            while ((niv<0)&&(niv>4));

        }
    }

}

void genMap()
{
    int x, y;
    for (y = 0; y < myY; ++y)
    {
        for (x = 0; x < myX; ++x)
        {
            if (y == 0 || y == myY - 1)
            {
                map[y][x] = 'ฐ';
            }
            else if (x == 0 || x == myX - 1)
            {
                map[y][x] = 'ฐ';
            }
            else
            {
                map[y][x] = ' ';
            }
        }
    }
}
void grow()
{
    if (numOfBody == 0)
    {
        ++numOfBody;
        map[body[0][0] - dirY][body[0][1] - dirX] = '*';
        body[1][0] = body[0][0] - dirY;
        body[1][1] = body[0][1] - dirX;
        return;
    }
    for (int i = 0; i <= numOfBody; ++i)
    {
        if (i == numOfBody)
        {
            body[i + 1][0] = oldBodyCor[i][0];
            body[i + 1][1] = oldBodyCor[i][1];
            map[body[i + 1][0]][body[i + 1][1]] = '*';
            ++numOfBody;
            return;
        }
    }
    return;
}
void genDefDir()
{
    srand(time(NULL));
    for (y = 0; y < myY; ++y)
    {
        for (x = 0; x < myX; ++x)
        {
            switch (map[y][x])
            {
            case '@':
                if (y <= (myY / 2) - 1 && x <= (myX / 2) - 1)
                {
                    if ((rand() % 2) == 0)
                    {
                        dirX = 1;
                        dirY = 0;
                        return;
                    }
                    else
                    {
                        dirX = 0;
                        dirY = 1;
                        return;
                    }
                }
                else if (y <= (myY / 2) - 1 && x > (myX / 2) - 1)
                {
                    if ((rand() % 2) == 0)
                    {
                        dirX = -1;
                        dirY = 0;
                        return;
                    }
                    else
                    {
                        dirX = 0;
                        dirY = 1;
                        return;
                    }
                }
                else if (y > (myY / 2) - 1 && x <= (myX / 2) - 1)
                {
                    if ((rand() % 2) == 0)
                    {
                        dirX = 1;
                        dirY = 0;
                        return;
                    }
                    else
                    {
                        dirX = 0;
                        dirY = -1;
                        return;
                    }
                }
                else if (y > (myY / 2) - 1 && x > (myX / 2) - 1)
                {
                    if ((rand() % 2) == 0)
                    {
                        dirX = -1;
                        dirY = 0;
                        return;
                    }
                    else
                    {
                        dirX = 0;
                        dirY = -1;
                        return;
                    }
                }
            }
        }
    }
}
void kInp()
{
    if (_kbhit())
    {
        key = _getch();
    }
    if ((key == 'z')||(key == 'Z')||(key == 72))
    {
        dirX = 0;
        dirY = -1;
    }
    else if ((key == 's')||(key == 'S')||(key == 80))
    {
        dirX = 0;
        dirY = 1;
    }
    else if ((key == 'q')||(key == 'Q')||(key == 75))
    {
        dirX = -1;
        dirY = 0;
    }
    else if ((key == 'd')||(key == 'D')||(key == 'DOWN')||(key == 77))
    {
        dirX = 1;
        dirY = 0;
    }
}
void genPlayer()
{
    srand(time(NULL));
    int x = rand() % (myX - 3) + 1;
    int y = rand() % (myY - 3) + 1;
    map[y][x] = '@';
    body[0][0] = y;
    body[0][1] = x;
}
void genEnemy()
{
    srand(time(NULL));
    while (1)
    {
        int x = rand() % (myX - 3) + 1;
        int y = rand() % (myY - 3) + 1;
        if (map[y][x] != '@' && map[y][x] != '*')
        {
            map[y][x] = '&';
            return;
        }
    }

}
void draw()
{
    for (y = 0; y < myY; ++y)
    {
        goToXY(myX / 2, y);
        for (x = 0; x < myX; ++x)
        {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
    goToXY(0, 0);
    printf("Score : %d", score);
}
void move()
{
    for (y = 0; y < myY; ++y)
    {
        for (x = 0; x < myX; ++x)
        {
            switch (map[y][x])
            {
            case '@':
                if (map[y + dirY][x + dirX] == ' ')
                {
                    freeMove();
                    return;
                }
                else if (map[y + dirY][x + dirX] == '&')
                {
                    map[y + dirY][x + dirX] = ' ';
                    score += 10;
                    freeMove();
                    grow();
                    genEnemy();
                    return;
                }
                else if ((map[y + dirY][x + dirX] == 'ฐ' )|| (map[y + dirY][x + dirX] == '*'))
                {
                    alive = 0;
                }
            }
        }
    }
}
void freeMove()
{
    char headY = y;
    char headX = x;
    char temp = map[y][x];
    map[y][x] = map[y + dirY][x + dirX];
    map[y + dirY][x + dirX] = temp;
    body[0][0] = y + dirY;
    body[0][1] = x + dirX;
    for (int i = 1; i <= numOfBody; ++i)
    {
        if (i == 1)
        {
            oldBodyCor[i][0] = body[i][0];
            oldBodyCor[i][1] = body[i][1];
            char temp = map[body[i][0]][body[i][1]];
            map[body[i][0]][body[i][1]] = map[headY][headX];
            map[headY][headX] = temp;
            body[i][0] = headY;
            body[i][1] = headX;
            continue;
        }
        oldBodyCor[i][0] = body[i][0];
        oldBodyCor[i][1] = body[i][1];
        char temp = map[body[i][0]][body[i][1]];
        map[body[i][0]][body[i][1]] = map[oldBodyCor[i - 1][0]][oldBodyCor[i - 1][1]];
        map[oldBodyCor[i - 1][0]][oldBodyCor[i - 1][1]] = temp;
        body[i][0] = oldBodyCor[i - 1][0];
        body[i][1] = oldBodyCor[i - 1][1];
    }
    return;
}
/*void reset()
{
    score = 0;
    for (int i = 0; i <= numOfBody; ++i)
    {
        body[i][0] = 0;
        body[i][0] = 0;
    }
    numOfBody = 0;
}*/
void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
int gameSpeed (int niv,int *speed)
{

    switch (niv)
    {
    case (1) :
        speed = 200 ;
        return speed;

    case (2) :
        speed = 100 ;
        return speed;

    case (3) :
        speed = 50 ;
        return speed;
    }
}
void goToXY(int column, int line)
{
    // Create a COORD structure and fill in its members.
    // This specifies the new position of the cursor that we will set.
    COORD coord;
    coord.X = column;
    coord.Y = line;

    // Obtain a handle to the console screen buffer.
    // (You're just using the standard console, so you can use STD_OUTPUT_HANDLE
    // in conjunction with the GetStdHandle() to retrieve the handle.)
    // Note that because it is a standard handle, we don't need to close it.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Finally, call the SetConsoleCursorPosition function.
    if (!SetConsoleCursorPosition(hConsole, coord))
    {
        // Uh-oh! The function call failed, so you need to handle the error.
        // You can call GetLastError() to get a more specific error code.
        // ...
    }
}
