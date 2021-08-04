#pragma once
#include <vector>
#include <string>
#include "conf.h"
#include "ScreenG.h"
#include "Coord.h"

class Mesh
{
protected:
    std::vector<std::string> aData;
    int w = 4;
    int h = 4;
    ScreenG *scr;

public:
    Coord vCoord;

    Mesh(ScreenG *_scr, std::vector<std::string> _aData, int _w, int _h)
    {
        aData = _aData;
        scr = _scr;
        w = _w;
        h = _h;

        vCoord.x = 0;
        vCoord.y = 0;
    }

    void fPrint()
    {
        for (int k = 0; k < h; k++)
        {
            printw("%s", this->aData[k].c_str());
            printw("\n");
        }
    }
    void fPrintScr()
    {
        Coord _vCoord;
        _vCoord.x = 0;
        _vCoord.y = 0;

        if ((vCoord.x >= 0) && (vCoord.x <= mx) && (vCoord.y >= 0) && (vCoord.y <= my))
        {
            for (int dy = 0; dy < h; dy++)
            {
                _vCoord.y = vCoord.y + dy;
                for (int dx = 0; dx < w; dx++)
                {
                    _vCoord.x = vCoord.x + dx;
                    scr->fSetChar(std::string(1, aData[dy][dx]), _vCoord);
                }
            }
        }
    }
};
