#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <thread>
#include <future>

#include <ctime>
#include <cmath>
#include <iostream>
#include <list>
#include <string>

#include "ScreenG.h"
#include "Mesh.h"

void fOnClick(int nKey)
{
    switch (nKey)
    {
    case ERR:
        // printw("Please, press any key...\n"); //Если нажатия не было, напоминаем пользователю, что надо нажать клавишу
        break;
    case KEY_F(2): //Выходим из программы, если была нажата F2
        break;
    case KEY_UP:
        printw("U");
        break;
    case KEY_DOWN:
        printw("D");
        break;
    case KEY_LEFT:
        printw("L");
        break;
    case KEY_RIGHT:
        printw("R");
        break;
    default: //Если всё нормально, выводим код нажатой клавиши
        printw("Code of pressed key is %d\n", nKey);
        break;
    }
}

void foo()
{
    // do stuff...
    printw("Code of pressed key is %d\n", 1);
}

int main()
{

    Coord _vCoord;
    _vCoord.x = 4;
    _vCoord.y = 2;

    initscr();
    keypad(stdscr, true); //Включаем режим чтения функциональных клавиш
    noecho();             //Выключаем отображение вводимых символов, нужно для getch()
    halfdelay(1);         //Устанавливаем ограничение по времени ожидания getch() в 10 сек

    ScreenG *scr = new ScreenG;

    std::vector<std::string> aM;
    aM.push_back("####");
    aM.push_back("#00#");
    aM.push_back("#00#");
    aM.push_back("####");

    Mesh *vM = new Mesh(scr, aM, 4, 4);
    vM->vCoord = _vCoord;
    int nCh;

    std::vector<std::string> vWall;
    for (int k = 0; k < 4; k++)
    {
        vWall.push_back("##");
        vWall.push_back("##");
        vWall.push_back("##");
        vWall.push_back("##");
        vWall.push_back("  ");
    }
    std::vector<std::string> vRazmetka;
    for (int k = 0; k < 4; k++)
    {
        vRazmetka.push_back("||");
        vRazmetka.push_back("||");
        vRazmetka.push_back("||");
        vRazmetka.push_back("||");
        vRazmetka.push_back("  ");
    }

    std::vector<Mesh *> aWalls;
    const int nWallCount = 6;

    for (int k = 0; k < nWallCount; k++)
    {
        Mesh *vM = new Mesh(scr, vWall, 2, 5);
        vM->vCoord.x = 0;
        vM->vCoord.y = k * 5;
        aWalls.push_back(vM);

        Mesh *vMr = new Mesh(scr, vWall, 2, 5);
        vMr->vCoord.x = mx - 2;
        vMr->vCoord.y = k * 5;
        aWalls.push_back(vMr);

        Mesh *vRr = new Mesh(scr, vRazmetka, 2, 5);
        vRr->vCoord.x = mx / 2 - 2;
        vRr->vCoord.y = (k * 5)+3;
        aWalls.push_back(vRr);
    }

    std::vector<std::string> aMacquin;
    aMacquin.push_back(" II ");
    aMacquin.push_back("OTTO");
    aMacquin.push_back(" HH ");
    aMacquin.push_back("OvvO");

    Mesh *vMacquin = new Mesh(scr, aMacquin, 4, 4);
    vMacquin->vCoord.x = (mx / 4) - 2;
    vMacquin->vCoord.y = my - 4;

    while (true)
    {
        usleep(100000);
        // clear();
        scr->fClear();

        for (int k = 0; k < nWallCount * 2; k++)
        {
            aWalls[k]->vCoord.y += 1;
            if (aWalls[k]->vCoord.y > my)
            {
                aWalls[k]->vCoord.y = -5;
            }
            aWalls[k]->fPrintScr();
        }

        vMacquin->fPrintScr();

        scr->fPrint();

        nCh = getch();
        switch (nCh)
        {
        case ERR:
            // printw("Please, press any key...\n"); //Если нажатия не было, напоминаем пользователю, что надо нажать клавишу
            break;
        case KEY_F(2): //Выходим из программы, если была нажата F2
            break;
        case KEY_UP:
            vMacquin->vCoord.y -= 1;
            break;
        case KEY_DOWN:
            vMacquin->vCoord.y += 1;
            break;
        case KEY_LEFT:
            vMacquin->vCoord.x -= 1;
            printw("L");
            break;
        case KEY_RIGHT:
            vMacquin->vCoord.x += 1;
            printw("R");
            break;
        default: //Если всё нормально, выводим код нажатой клавиши
            break;
        }
        // std::thread vThreadClick(fOnClick, nCh);
        // vThreadClick.join();

        mvaddch(0, 0, 'W');
        mvaddch(0, 1, 'R');
        mvaddch(1, 1, 'T');
        // refresh();
    }

    getch();
    endwin();
}
