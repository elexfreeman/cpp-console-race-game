#pragma once
#include <ncurses.h>
#include "conf.h"
#include <vector>
#include <string>
#include "Coord.h"

class ScreenG
{
private:
    std::vector<std::string> aMatrix;

public:
    void fClear()
    {
        for (int x = 0; x < mx; x++)
        {
            std::string s = "";
            for (int y = 0; y < my; y++)
            {
                s += " ";
            }
            aMatrix.push_back(s);
        }
    }

    void fPrint()
    {
        for (int x = 0; x < mx; x++)
        {
            printw("%s", aMatrix[x].c_str());
            printw("\n");
        }
    }

    void fSetChar(std::string c, Coord vCoord)
    {
        if (c.size() > 0 && vCoord.x >= 0 && vCoord.x < mx && vCoord.y >= 0 && vCoord.y < my)
        {
            aMatrix[vCoord.y][vCoord.x] = c[0];
        }
    }
};
