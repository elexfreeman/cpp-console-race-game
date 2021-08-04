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
#include "Map.h"

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

void fRender(Map *vMap)
{

    while (true)
    {
        usleep(100000);
        // clear();
        vMap->fTick();
    }
}

void foo()
{
    // do stuff...
    printw("Code of pressed key is %d\n", 1);
}

int main()
{

    initscr();
    keypad(stdscr, true); //Включаем режим чтения функциональных клавиш
    noecho();             //Выключаем отображение вводимых символов, нужно для getch()
    halfdelay(1);         //Устанавливаем ограничение по времени ожидания getch() в 10 сек

    ScreenG *scr = new ScreenG;
    Map *vMap = new Map(scr);

    int nCh;

    // рендерный поток
    // чтобы нажатия клавиш не тормозили
    std::thread vThreadClick(fRender, vMap);

    while (true)
    {
        usleep(100000);
        // clear();

        nCh = getch();
        switch (nCh)
        {
        case ERR:
            // printw("Please, press any key...\n"); //Если нажатия не было, напоминаем пользователю, что надо нажать клавишу
            break;
        case KEY_F(2): //Выходим из программы, если была нажата F2
            break;
        case KEY_UP:
            vMap->vMacquin->vCoord.y -= 1;
            break;
        case KEY_DOWN:
            vMap->vMacquin->vCoord.y += 1;
            break;
        case KEY_LEFT:
            vMap->vMacquin->vCoord.x -= 1;
            printw("L");
            break;
        case KEY_RIGHT:
            vMap->vMacquin->vCoord.x += 1;
            printw("R");
            break;
        default: //Если всё нормально, выводим код нажатой клавиши
            break;
        }
    }

    getch();
    endwin();
    vThreadClick.join();
}
