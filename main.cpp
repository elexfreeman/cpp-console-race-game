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

    while (true)
    {
        usleep(100000);
        clear();
        scr->fClear();

        _vCoord.y += 1;
        if (_vCoord.y > my + 5)
        {
            _vCoord.y = 0;
        }

        vM->vCoord = _vCoord;
        vM->fPrintScr();
        scr->fPrint();

        nCh = getch();
        std::thread vThreadClick(fOnClick, nCh);
        vThreadClick.join();

        mvaddch(0, 0, 'W');
        mvaddch(0, 1, 'R');
        mvaddch(1, 1, 'T');
        refresh();
    }

    getch();
    endwin();
}
