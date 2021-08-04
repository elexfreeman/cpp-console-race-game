#pragma once
#include "conf.h"
#include <vector>
#include <string>
#include "Coord.h"

class ScreenG
{
private:
    std::vector<std::string> aMatrix;

public:
    ScreenG()
    {
        for (int y = 0; y < my; y++)
        {
            std::string s = "";
            for (int x = 0; x < mx; x++)
            {
                s += " ";
            }
            aMatrix.push_back(s);
        }
    }

    void fClear()
    {
        for (int y = 0; y < my; y++)
        {
            std::string s = "";
            for (int x = 0; x < mx; x++)
            {
                s += " ";
            }
            aMatrix[y] = s;
        }
    }

    void fPrint()
    {
        for (int y = 0; y < my; y++)
        {
            printw("%s", aMatrix[y].c_str());
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
