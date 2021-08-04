#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <ctime>
#include <cmath>
#include <iostream>
#include <list>
#include <string>

#include "ScreenG.h"
#include "Mesh.h"

int main()
{

    Coord _vCoord;
    _vCoord.x = 4;
    _vCoord.y = 2;

    initscr();
    ScreenG *scr = new ScreenG;

    std::vector<std::string> aM;
    aM.push_back("####");
    aM.push_back("#00#");
    aM.push_back("#00#");
    aM.push_back("####");

    Mesh *vM = new Mesh(scr, aM, 4, 4);

    scr->fClear();

    vM->fPrintScr();
    scr->fPrint();

    getch();
    endwin();
}
