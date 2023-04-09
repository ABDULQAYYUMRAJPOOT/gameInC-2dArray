#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
using namespace std;
// global variables
string flag;
string firstOption;
// int px = 15, py = 31;
int ex = 25, ey = 1, ex2 = 115, ey2 = 6, bx, by, ebx, eby, score = 0, bulletCount = 0, index = 0, EBcount = 0, Eindex = 0, E2Bcount = 0;
int fireLimit = 0;
int E2count = 0;
int PHealth = 25;

char a = 176, b = 177, c = 178, d = 31, heart = 3, semoji = 1;
char ja = 219;
char jb = 30, jc = 16, jd = 17;
char e2a = 219;
char e2b = 31;
char e2c = 30;
const int limit = 1000000;
int bulletx[limit];
int bullety[limit];
bool activeB[limit];

int EbulletX[limit];
int EbulletY[limit];
bool activeEb[limit];
string eDirection = "Right";

int E2bulletX[limit];
int E2bullety[limit];
bool activeE2b[limit];

// Functions
void bullet();
void movePB();
void moveEnemy();
void Ebullet();

void eraseE2();
void eraseE2complete();
void moveE2();
void E2bullet();
void moveE2Bullet(int px);
bool checkE2 = true;

void shugal();
void loading();
void showScore();
void showPhealth();
void checkElimit();
void eBmove();
void gotoxy(int x, int y);
char getcharAtxy(short int x, short int y);
void GameName();
void Died();
void Over();
void logo();
void firstMenu();
void printjet2d();
void erasejet2d(int px, int py);
void printjet2d(int px, int py);
void printmaze2d();
void printspace2d();
void printenemy22d();
void enemy32d(char enemy3[][4], int e3x, int e3y);
void removee3(int e3x, int e3y);
void movee3(char enemy3[][4], int &e3x, int &e3y, int py, int &e3count);
void removee3right(int e3x, int e3y);
void brokenjet(int px, int py);
void movepright(int &px, int &py);
void movepleft(int &px, int &py);
void movepup(int &px, int &py, char &c);
void movepdown(int &px, int &py, char &c);
void firepbullet(int &px, int &py);

void writefile(int px, int py, int &e3x, int &e3y);
void readfile(string &readdata);
string seperate(string line, int idx);
void tovariables(string &readdata, int &px, int &py, int &e3x, int &e3y);

string maze2d[42][1] = {
    {"##########################################################################################################################################################"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||___________________________||"},
    {"||                                                                                                                         ||___________________________||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         || KEYS TO PLAY GAME         ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         || Move up    = up arrow     ||"},
    {"||                                                                                                                         || Move down  = down arrow   ||"},
    {"||                                                                                                                         || Move right = right arrow  ||"},
    {"||                                                                                                                         || Move left  = left arrow   ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         || Fire bullet = Space       ||"},
    {"||                                                                                                                         || Exit        = Escape      ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         || NOTE:                     ||"},
    {"||                                                                                                                         ||      You will win if your ||"},
    {"||                                                                                                                         ||  score is 100. It will    ||"},
    {"||                                                                                                                         ||  happen if your bullet    ||"},
    {"||                                                                                                                         ||  hits main upper enemy.   ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"||                                                                                                                         ||                           ||"},
    {"##########################################################################################################################################################"}};
char jet2d[2][5] = {
    {' ', ' ', jb, ' ', ' '},
    {jd, '|', '|', '|', jc}};

char space2d[4][7] = {
    {' ', ' ', b, c, b, ' ', ' '},
    {' ', ' ', ' ', c, ' ', ' ', ' '},
    {a, a, b, c, b, a, a},
    {' ', ' ', ' ', d, ' ', ' ', ' '}};

char enemy22d[3][5] = {
    {' ', ' ', e2c, ' ', ' '},
    {'(', e2a, e2a, e2a, ')'},
    {' ', ' ', e2b, ' ', ' '}};
main()
{
    int px = 15, py = 31, e3x = 118, e3y = 20, e3count = 0;
    char c = 254;
    bool e3check = true;
    char enemy3[3][4] = {
        {'[', c, c, ']'},
        {b, b, b, b},
        {'[', c, c, ']'},
    };
    string readdata;
    string flag;

    while (true)
    {

        system("cls");
        GameName();
        firstMenu();
        cout << "Enter key: ";
        cin >> firstOption;
        if (firstOption == "1")
        {
            ex = 25, ey = 1, ex2 = 115, ey2 = 6, bx, by, ebx, eby, score = 0, bulletCount = 0, index = 0, EBcount = 0, Eindex = 0, E2Bcount = 0;
            fireLimit = 0;
            E2count = 0;
            PHealth = 25;
            px = 15, py = 31, e3x = 118, e3y = 20, e3count = 0;
            system("cls");
            logo();
            loading();
            Sleep(1000);
            system("cls");
            printmaze2d();
            printjet2d(px, py);
            printspace2d();
            enemy32d(enemy3, e3x, e3y);
            shugal();
            while (true)
            {
                printenemy22d();
                moveE2();
                moveE2Bullet(px);
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    movepright(px, py);
                }
                if (GetAsyncKeyState(VK_LEFT))
                {
                    movepleft(px, py);
                }
                if (GetAsyncKeyState(VK_UP) && py >= 10)
                {
                    movepup(px, py, c);
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    movepdown(px, py, c);
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    firepbullet(px, py);
                }
                else if (GetAsyncKeyState(VK_ESCAPE))
                {
                    break;
                }
                if (PHealth <= 0)
                {
                    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                    system("color 04");
                    erasejet2d(px, py);
                    brokenjet(px, py);
                    Sleep(2000);
                    SetConsoleTextAttribute(h, 15);
                    system("cls");
                    Died();

                    cout << "Enter any key to continue: ";
                    cin >> flag;
                    score = 0;
                    PHealth = 25;
                    break;
                }
                if (score >= 100)
                {
                    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                    system("color 02");
                    brokenjet(ex, ey + 1);
                    SetConsoleTextAttribute(h, 15);
                    Sleep(1000);
                    system("cls");
                    Over();
                    Sleep(1000);
                    PHealth = 0;
                    score = 0;
                    cout << "Enter any key to continue: ";
                    cin >> flag;
                    break;
                }
                movePB();
                showScore();
                showPhealth();
                moveEnemy();
                checkElimit();
                movee3(enemy3, e3x, e3y, py, e3count);
                Sleep(50);
            }
        }
        else if (firstOption == "2")
        {
            readfile(readdata);
            tovariables(readdata, px, py, e3x, e3y);
            system("cls");
            logo();
            loading();
            Sleep(1000);
            system("cls");
            printmaze2d();
            printjet2d(px, py);
            printspace2d();
            enemy32d(enemy3, e3x, e3y);
            shugal();
            while (true)
            {
                printenemy22d();
                moveE2();
                moveE2Bullet(px);
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    movepright(px, py);
                }
                if (GetAsyncKeyState(VK_LEFT))
                {
                    movepleft(px, py);
                }
                if (GetAsyncKeyState(VK_UP) && py >= 10)
                {
                    movepup(px, py, c);
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    movepdown(px, py, c);
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    firepbullet(px, py);
                }
                else if (GetAsyncKeyState(VK_ESCAPE))
                {
                    break;
                }
                if (PHealth <= 0)
                {
                    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                    system("color 04");
                    erasejet2d(px, py);
                    brokenjet(px, py);
                    Sleep(2000);
                    SetConsoleTextAttribute(h, 15);
                    system("cls");
                    Died();
                    string flag;
                    cout << "Enter any key to continue: ";
                    cin >> flag;
                    getch();
                    score = 0;
                    PHealth = 25;
                    break;
                }
                if (score >= 100)
                {
                    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                    system("color 02");
                    brokenjet(ex, ey + 1);
                    SetConsoleTextAttribute(h, 15);
                    Sleep(1000);
                    system("cls");
                    Over();
                    Sleep(1000);
                    PHealth = 0;
                    score = 0;
                    cout << "Enter any key to continue: ";
                    cin >> flag;
                    break;
                }
                movePB();
                showScore();
                showPhealth();
                moveEnemy();
                checkElimit();
                movee3(enemy3, e3x, e3y, py, e3count);
                Sleep(50);
            }
        }
        else if (firstOption == "4")
        {
            system("cls");
            break;
        }
        else if (firstOption == "3")
        {
            writefile(px, py, e3x, e3y);
            cout << "\nSaved successfully.";
            getch();
        }
    }
}

void GameName()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 3);
    cout << "                                                                                                         " << endl;
    cout << "                                                                                                         " << endl;
    cout << "     __   ___    _____   _____       _____            ____     ______        ______      _____    _____  " << endl;
    cout << "    () ) / __)  (_   _) (_   _)     (_   _)          / __ \\   (   __ \\      (_  __ \\    (_   _)  / ___/  " << endl;
    cout << "    ( (_/ /       | |     | |         | |           / /  \\ \\   ) (__) )       ) ) \\ \\     | |   ( (__    " << endl;
    cout << "    ()   (        | |     | |         | |          ( ()  () ) (    __/       ( (   ) )    | |    ) __)   " << endl;
    cout << "    () /\\ \\       | |     | |   __    | |   __     ( ()  () )  ) \\ \\  _       ) )  ) )    | |   ( (      " << endl;
    cout << "    ( (  \\ \\     _| |__ __| |___) ) __| |___) )     \\ \\__/ /  ( ( \\ \\_))     / /__/ /    _| |__  \\ \\___  " << endl;
    cout << "    ()_)  \\_\\   /_____( \\________/  \\________/       \\____/    )_) \\__/     (______/    /_____(   \\____\\ " << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(h, 15);
}

void shugal()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    gotoxy(126, 38);
    SetConsoleTextAttribute(h, 8);
    cout << "Developed by:" << endl;
    // SetConsoleTextAttribute(h, 11);
    gotoxy(126, 39);
    cout << "   ABDUL QAYYUM RAJPOOT";
    SetConsoleTextAttribute(h, 15);
}

void logo()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 3);
    cout << "                                                                                                              " << endl;
    cout << "                                                         ::....:                                              " << endl;
    cout << "                                                          .  :bbri7sSq                                        " << endl;
    cout << "                                                             :...::::7.                                       " << endl;
    cout << "                                                            ::....:::ii                                       " << endl;
    cout << "                                                           irr:..::i:ir                                       " << endl;
    cout << "                                                           :r::..i:i::7.                                      " << endl;
    cout << "                                                          .:.....:.::.::                                      " << endl;
    cout << "                                                         .i.......:::..:                                      " << endl;
    cout << "                                                         i::...:.:.::..:.         .qQgPgg                     " << endl;
    cout << "                                                        i:::::i::.:::...:       vgBBBBBQS.::                  " << endl;
    cout << "                                                       :::.:::::::::::..:    :qBBQZDdQQi .:7:                 " << endl;
    cout << "                                                    . ..... .......:i:..   LBQBgZdZdMBi ..ii                  " << endl;
    cout << "                                   ..r:iv.  ......   ..:::i:.:........ .YMBBRZdgdZbMBr .:ii                   " << endl;
    cout << "                          ir...bBBBQBBBBBQBPBQBBQQQ:        ........::.:BBgEMZdbggRQ: ..::                    " << endl;
    cout << "             <<JdBBBBBBBBBBBBBQBBBBBBBQBBBBQBBBBQBBBMSiiiiii::::s: ...  .1KdRQPPKbZM   .:.                    " << endl;
    cout << "                <iY5ZRBBBBBBBBBQBBBBBQBBBBRQRMRgQMQQBQBBBBBQBQBQBQBBBQBRd1PPPqqXPSdqsUSIQQQv                  " << endl;
    cout << "                                   ...:sBBBBgZddPDbMEDDggRgQDDZZPdqq22Jvr:LdXBEKKqdv :YbQBBU                  " << endl;
    cout << "                                          :YgBBBQDDdPqdPXSII17Yu::::::i::.rZEZZqddZDgggSJKu5.                 " << endl;
    cout << "                                              .vXgBBBBBgKU7rYuqP1SPZEgQBBBBBQBQBBBBBBQEddBBB:                 " << endl;
    cout << "                                                    .:vYJEZ7i.:::.:::::.XQRQqsI1RBBBBBBBBQB.                  " << endl;
    cout << "                                                          L57r:::::::::..MZB.    :gBBbYi...:                  " << endl;
    cout << "                                                           iKvr::...::i:.jRQu      .rri:..:.i.                " << endl;
    cout << "                                                            .5uri:. .iii.:gQD         rYrr:::r:               " << endl;
    cout << "                                                            .5uri:. .iii.:gQD         rYrr:::r:               " << endl;
    cout << "                                                                :Jr7r .::i.YBr              :::i:             " << endl;
    cout << "                                                                 7u7v7 .ir:.BE                                " << endl;
    cout << "                                                                  rJs57.:::.YB                                " << endl;
    cout << "                                                                   .v77i.:::.B.                               " << endl;
    cout << "                                                                     ir:::::.vL                               " << endl;
    cout << "                                                                  ::.:7g2rir7rL                               " << endl;
    cout << "                                                                  .         . .                               " << endl;
    cout << endl;
    SetConsoleTextAttribute(h, 15);
}
void loading()
{
    int j = 1;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 4);
    for (int i = 1; i < 4; i++)
    {
        gotoxy(55, 35);
        cout << "Loading";
        gotoxy((i + j) + 62, 35);
        j = j + 2;
        cout << i;
        Sleep(1000);
    }
    SetConsoleTextAttribute(h, 15);
}
void firstMenu()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 3);
    cout << "Enter 1 to play new game." << endl;
    cout << "Enter 2 to start saved game." << endl;
    cout << "Enter 3 to save game." << endl;
    cout << "Enter 4 to exit game." << endl;
    SetConsoleTextAttribute(h, 15);
}

void Died()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 4);

    cout << endl;
    cout << endl;
    cout << "   __      __    ____     __    __      _____         ____      _____    _____  " << endl;
    cout << "   ) \\    / (   / __ \\    ) )  ( (     (_   _)       / __ \\    / ____\\  / ___/  " << endl;
    cout << "    \\ \\  / /   / /  \\ \\  ( (    ) )      | |        / /  \\ \\  ( (___   ( (__    " << endl;
    cout << "     \\ \\/ /   ( ()  () )  ) )  ( (       | |       ( ()  () )  \\___ \\   ) __)   " << endl;
    cout << "      \\  /    ( ()  () ) ( (    ) )      | |   __  ( ()  () )      ) ) ( (      " << endl;
    cout << "       )(      \\ \\__/ /   ) \\__/ (     __| |___) )  \\ \\__/ /   ___/ /   \\ \\___  " << endl;
    cout << "      /__\\      \\____/    \\______/     \\________/    \\____/   /____/     \\____\\ " << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(h, 15);
}

void Over()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 2);
    cout << endl;
    cout << endl;
    cout << "   __      __    ____     __    __      ___       ___     ____        __      _  " << endl;
    cout << "   ) \\    / (   / __ \\    ) )  ( (     (  (       )  )   / __ \\      /  \\    / ) " << endl;
    cout << "    \\ \\  / /   / /  \\ \\  ( (    ) )     \\  \\  _  /  /   / /  \\ \\    / /\\ \\  / /  " << endl;
    cout << "     \\ \\/ /   ( ()  () )  ) )  ( (       \\  \\/ \\/  /   ( ()  () )   ) ) ) ) ) )  " << endl;
    cout << "      \\  /    ( ()  () ) ( (    ) )       )   _   (    ( ()  () )  ( ( ( ( ( (   " << endl;
    cout << "       )(      \\ \\__/ /   ) \\__/ (        \\  ( )  /     \\ \\__/ /   / /  \\ \\/ /   " << endl;
    cout << "      /__\\      \\____/    \\______/         \\_/ \\_/       \\____/   (_/    \\__/    " << endl;
    SetConsoleTextAttribute(h, 15);
}

void movepright(int &px, int &py)
{
    char next = getcharAtxy(px + 5, py + 1);
    if (next == ' ')
    {
        erasejet2d(px, py);
        px = px + 1;
        printjet2d(px, py);
    }
    else if (next == '.' || next == ':')
    {
        erasejet2d(px, py);
        px = px + 1;
        printjet2d(px, py);
        PHealth--;
    }
}
void movepleft(int &px, int &py)
{
    char next = getcharAtxy(px - 1, py + 1);
    if (next == ' ')
    {
        erasejet2d(px, py);
        px = px - 1;
        printjet2d(px, py);
    }
    else if (next == '.' || next == ':')
    {
        erasejet2d(px, py);
        px = px - 1;
        printjet2d(px, py);
        PHealth--;
    }
}
void movepup(int &px, int &py, char &c)
{
    char next = getcharAtxy(px + 2, py - 1);
    char next1 = getcharAtxy(px, py);
    char next2 = getcharAtxy(px + 3, py);
    char next3 = getcharAtxy(px + 4, py);
    char next4 = getcharAtxy(px + 1, py);

    if (next == ' ' && next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ')
    {
        erasejet2d(px, py);
        py = py - 1;
        printjet2d(px, py);
    }
    else if ((next == '.' || next == ':') || (next1 == '.' || next1 == ':') || (next2 == '.' || next2 == ':') || (next3 == '.' || next3 == ':') || (next4 == '.' || next4 == ':'))
    {
        erasejet2d(px, py);
        py = py - 1;
        printjet2d(px, py);
        PHealth--;
    }
    else if ((next == c || next == '[' || next == ']') || (next1 == c || next1 == '[' || next1 == ']') || (next2 == c || next2 == '[' || next2 == ']') || (next3 == c || next3 == '[' || next3 == ']') || (next4 == c || next4 == '[' || next4 == ']'))
    {
        PHealth == 0;
    }
}
void movepdown(int &px, int &py, char &c)
{
    char next = getcharAtxy(px + 2, py + 4);
    char next1 = getcharAtxy(px + 1, py + 4);
    char next2 = getcharAtxy(px + 3, py + 4);
    if (next == ' ')
    {

        erasejet2d(px, py);
        py = py + 1;
        printjet2d(px, py);
    }
    else if (next == '.' || next1 == '.' || next2 == '.')
    {
        erasejet2d(px, py);
        py = py + 1;
        printjet2d(px, py);
        PHealth--;
    }
    else if (next == c || next1 == c || next2 == c)
    {
        PHealth = 0;
    }
}

void firepbullet(int &px, int &py)
{
    bx = px + 2;
    by = py - 1;
    gotoxy(bx, by);
    bullet();
    bulletx[index] = bx;
    bullety[index] = by;
    activeB[index] = true;
    index++;
    bulletCount++;
}

void printspace2d()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 12);
    for (int i = 0; i < 4; i++)
    {
        gotoxy(ex, ey + i);
        for (int j = 0; j < 7; j++)
        {
            cout << space2d[i][j];
        }
        cout << endl;
    }
    SetConsoleTextAttribute(h, 15);
}

void printjet2d(int px, int py)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 2);
    for (int i = 0; i < 2; i++)
    {
        gotoxy(px, py + i);
        for (int j = 0; j < 5; j++)
        {
            cout << jet2d[i][j];
        }
        cout << endl;
    }
    gotoxy(px + 1, py + 2);
    cout << "<" << ja << ">";
    gotoxy(px + 1, py + 3);
    cout << "<" << ja << ">";
    SetConsoleTextAttribute(h, 15);
}

void erasejet2d(int px, int py)
{
    for (int i = 0; i < 2; i++)
    {
        gotoxy(px, py + i);
        cout << "     ";
    }
    gotoxy(px + 1, py + 2);
    cout << "   ";
    gotoxy(px + 1, py + 3);
    cout << "   ";
}

void brokenjet(int px, int py)
{
    gotoxy(px + 1, py - 1);
    cout << "```~";
    gotoxy(px, py + 1);
    cout << "%&88**~";
    gotoxy(px, py + 1);
    cout << "%&**~~~";
}
void printmaze2d()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 3);
    for (int i = 0; i < 42; i++)
    {
        cout << maze2d[i][0] << endl;
    }
    SetConsoleTextAttribute(h, 15);
}

void printenemy22d()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 9);
    for (int i = 0; i < 3; i++)
    {
        gotoxy(ex2, ey2 + i);
        for (int j = 0; j < 5; j++)
        {
            cout << enemy22d[i][j];
        }
    }
    SetConsoleTextAttribute(h, 15);
}

void enemy32d(char enemy3[][4], int e3x, int e3y)
{
    for (int i = 0; i < 3; i++)
    {
        gotoxy(e3x, e3y + i);
        for (int j = 0; j < 4; j++)
        {
            cout << enemy3[i][j];
        }
        cout << endl;
    }
    gotoxy(e3x - 1, e3y + 1);
    cout << "<";
}

void removee3(int e3x, int e3y)
{
    for (int i = 0; i < 3; i++)
    {
        gotoxy(e3x, e3y + i);
        for (int j = 0; j < 4; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    gotoxy(e3x - 1, e3y + 1);
    cout << " ";
}
void movee3(char enemy3[][4], int &e3x, int &e3y, int py, int &e3count)
{
    char next = getcharAtxy(e3x - 2, e3y + 1);
    char next1 = getcharAtxy(e3x - 1, e3y);
    char next2 = getcharAtxy(e3x - 1, e3y + 2);
    if (e3x <= 4)
    {
        removee3(e3x, e3y);
        e3x = 118;
        e3y = 20;
    }
    if (e3x == 2)
    {
        removee3(e3x, e3y);
        e3x = 118;
        e3y = 20;
    }
    if ((next1 == ' ' || ':') && (next1 == ' ' || ':') && (next2 == ' ' || ':'))
    {
        removee3(e3x, e3y);
        e3x = e3x - 1;
        if (e3count >= 4)
        {
            if (py > e3y)
            {
                gotoxy(e3x, e3y);
                e3y++;
            }
            else if (py < e3y)
            {
                gotoxy(e3x, e3y + 2);
                e3y--;
            }
            e3count = 0;
        }
        else if (next == '>' || next1 == jb || next2 == jb || next1 == jc || next1 == '>' || next2 == jc || next2 == '>' || next == jb || next == jc)
        {
            PHealth = 0;
            e3x = 118;
            e3y = 20;
        }
        enemy32d(enemy3, e3x, e3y);
    }
    e3count++;
}

void showScore()
{
    gotoxy(128, 4);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 2);
    cout << semoji;
    SetConsoleTextAttribute(h, 15);
    cout << " Score: " << score;
}

void bullet()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 2);
    cout << "*";
    SetConsoleTextAttribute(h, 15);
}

void movePB()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if (activeB[i] == true)
        {
            char next = getcharAtxy(bulletx[i], bullety[i] - 1);
            if (next == ' ')
            {
                gotoxy(bulletx[i], bullety[i]);
                cout << " ";
                bullety[i] = bullety[i] - 1;
                gotoxy(bulletx[i], bullety[i]);
                bullet();
            }
            else if ((bullety[i] - 1 == ey + 2 && (bulletx[i] >= ex && bulletx[i] <= ex + 6)) || (next == d))
            {
                gotoxy(bulletx[i], bullety[i]);
                cout << " ";
                activeB[i] = false;
                score++;
            }
            else
            {
                gotoxy(bulletx[i], bullety[i]);
                cout << " ";
                activeB[i] = false;
            }
        }
    }
}

void showPhealth()
{
    gotoxy(128, 5);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 4);
    cout << heart;
    SetConsoleTextAttribute(h, 15);
    cout << " Player Health: " << PHealth;
}

void eraseJetR(int px, int py)
{

    gotoxy(px, py + 1);
    cout << " ";
}
void eraseJetL(int px, int py)
{
    gotoxy(px + 4, py + 1);
    cout << " ";
}

void moveEnemy()
{
    if (eDirection == "Right")
    {
        char next = getcharAtxy(ex + 7, ey + 2);
        if (next == '*')
        {
            score++;
        }
        if (next == ' ' || next == '*')
        {
            gotoxy(ex, ey + 2);
            cout << " ";
            ex = ex + 1;
            printspace2d();
        }
        else if (next == '|')
        {
            eDirection = "Down";
        }
    }
    else if (eDirection == "Down")
    {
        char next = getcharAtxy(ex - 1, ey + 2);
        if (next == '*')
        {
            score++;
        }
        if (next == ' ' || next == '*')
        {
            gotoxy(ex + 6, ey + 2);
            cout << " ";
            ex = ex - 1;
            printspace2d();
        }
        else if (next == '|')
        {
            eDirection = "Right";
        }
    }
}
void Ebullet()
{
    gotoxy(ex + 3, ey + 4);
    ebx = ex + 3;
    eby = ey + 4;
    EBcount++;
    EbulletX[Eindex] = ebx;
    EbulletY[Eindex] = eby;
    activeEb[Eindex] = true;
    Eindex++;
};

void eraseE2()
{
    gotoxy(ex2 + 4, ey2);
    cout << " ";
    gotoxy(ex2 + 4, ey2 + 1);
    cout << " ";
    gotoxy(ex2 + 4, ey2 + 2);
    cout << " ";
}
void eraseE2complete()
{
    gotoxy(ex2, ey2);
    cout << "     ";
    gotoxy(ex2, ey2 + 1);
    cout << "     ";
    gotoxy(ex2, ey2 + 2);
    cout << "     ";
}
void moveE2()
{
    if (checkE2 == true)
    {
        char next = getcharAtxy(ex2 - 1, ey2 + 1);
        if (next == ' ' || next == '.' || next == '*')
        {
            eraseE2complete();
            if (E2count == 1 || E2count == 58 || E2count == 110)
            {
                E2bullet();
                E2bulletX[E2Bcount] = ex2 + 2;
                E2bullety[E2Bcount] = ey2 + 3;
                activeE2b[E2Bcount] = true;
                E2Bcount++;
            }
            ex2 = ex2 - 1;
            printenemy22d();
            E2count++;
        }
        else if (next == '|')
        {
            eraseE2complete();
            ex2 = 115;
            E2count = 0;
        }
    }
}
void E2bullet()
{
    gotoxy(ex2 + 2, ey2 + 3);
    cout << ":";
}

void moveE2Bullet(int px)
{
    char b = 30, c = 16, d = 17;
    for (int i = 0; i <= E2Bcount; i++)
    {
        if (activeE2b[i] == true)
        {
            char next = getcharAtxy(E2bulletX[i], E2bullety[i] + 1);
            if (next == b || next == c || next == d || next == '|')
            {
                PHealth--;
                gotoxy(E2bulletX[i], E2bullety[i]);
                cout << " ";
                activeE2b[i] = false;
            }
            if ((next == ' ' || next == '.' || next == '*') && px + 2 < E2bulletX[i])
            {
                gotoxy(E2bulletX[i], E2bullety[i]);
                cout << " ";
                E2bulletX[i] = E2bulletX[i] - 1;
                E2bullety[i] = E2bullety[i] + 1;
                gotoxy(E2bulletX[i], E2bullety[i]);
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 9);
                cout << ":";
                SetConsoleTextAttribute(h, 15);
            }
            else if ((next == ' ' || next == '.' || next == '*') && px + 2 > E2bulletX[i])
            {
                gotoxy(E2bulletX[i], E2bullety[i]);
                cout << " ";
                E2bulletX[i] = E2bulletX[i] + 1;
                E2bullety[i] = E2bullety[i] + 1;
                gotoxy(E2bulletX[i], E2bullety[i]);
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 9);
                cout << ":";
                SetConsoleTextAttribute(h, 15);
            }
            else if ((next == ' ' || next == '.' || next == '*') && px + 2 == E2bulletX[i])
            {
                gotoxy(E2bulletX[i], E2bullety[i]);
                cout << " ";
                E2bullety[i] = E2bullety[i] + 1;
                gotoxy(E2bulletX[i], E2bullety[i]);
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 9);
                cout << ":";
                SetConsoleTextAttribute(h, 15);
            }
            else if (next == '#')
            {
                gotoxy(E2bulletX[i], E2bullety[i]);
                cout << " ";
                activeE2b[i] = false;
            }
        }
    }
}

void checkElimit()
{

    if (fireLimit == 7)
    {
        Ebullet();
    }
    else if (fireLimit > 7)
    {
        fireLimit = 0;
    }
    eBmove();
    fireLimit++;
}

void eBmove()
{
    char b = 30, c = 16, d = 17;
    for (int i = 0; i < EBcount; i++)
    {
        if (activeEb[i] == true)
        {
            char next = getcharAtxy(EbulletX[i], EbulletY[i] + 1);
            if (next == ' ')
            {
                gotoxy(EbulletX[i], EbulletY[i]);
                cout << " ";
                EbulletY[i] = EbulletY[i] + 1;
                gotoxy(EbulletX[i], EbulletY[i]);
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 12);
                cout << ".";
                SetConsoleTextAttribute(h, 15);
            }
            else if (next == b || next == c || next == d || next == '|')
            {
                gotoxy(EbulletX[i], EbulletY[i]);
                cout << " ";
                activeEb[i] = false;
                PHealth--;
            }
            else
            {
                gotoxy(EbulletX[i], EbulletY[i]);
                cout << " ";
                activeEb[i] = false;
            }
        }
    }
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getcharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufsize;
    coordBufsize.X = 1;
    coordBufsize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufsize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void writefile(int px, int py, int &e3x, int &e3y)
{
    fstream write;
    write.open("data.txt", ios::out);
    write << px << "," << py << "," << e3x << "," << e3y << "," << ex2 << "," << ey2 << "," << score << "," << PHealth;
    write.close();
}

void readfile(string &readdata)
{
    fstream read;
    read.open("data.txt", ios::in);
    getline(read, readdata);
    read.close();
}
string seperate(string line, int idx)
{
    int comma = 1;
    string result = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            comma++;
        }
        else if (comma == idx)
        {
            result = result + line[i];
        }
    }
    return result;
}

void tovariables(string &readdata, int &px, int &py, int &e3x, int &e3y)
{
    string flag;
    flag = seperate(readdata, 1);
    px = atoi(flag.c_str());
    flag = seperate(readdata, 2);
    py = atoi(flag.c_str());
    flag = seperate(readdata, 3);
    e3x = atoi(flag.c_str());
    flag = seperate(readdata, 4);
    e3y = atoi(flag.c_str());
    flag = seperate(readdata, 5);
    ex2 = atoi(flag.c_str());
    flag = seperate(readdata, 6);
    ey2 = atoi(flag.c_str());
    flag = seperate(readdata, 7);
    score = atoi(flag.c_str());
    flag = seperate(readdata, 8);
    PHealth = atoi(flag.c_str());
}
