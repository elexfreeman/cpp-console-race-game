#pragma once
#include <vector>
#include "conf.h"
#include "ScreenG.h"
#include "Mesh.h"

class Map
{
protected:
    ScreenG *scr;

    std::vector<Mesh *> aMesh;
    std::vector<std::string> vWall;
    std::vector<std::string> vRazmetka;
    std::vector<Mesh *> aWalls;
    std::vector<std::string> aMacquin;


public:
    Mesh *vMacquin;

    Map(ScreenG *_scr)
    {
        this->scr = _scr;

        for (int k = 0; k < 4; k++)
        {
            vWall.push_back("##");
            vWall.push_back("##");
            vWall.push_back("##");
            vWall.push_back("##");
            vWall.push_back("  ");
        }
        for (int k = 0; k < 4; k++)
        {
            vRazmetka.push_back("||");
            vRazmetka.push_back("||");
            vRazmetka.push_back("||");
            vRazmetka.push_back("||");
            vRazmetka.push_back("  ");
        }

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
            vRr->vCoord.y = (k * 5) + 3;
            aWalls.push_back(vRr);
        }

        aMacquin.push_back(" II ");
        aMacquin.push_back("OTTO");
        aMacquin.push_back(" HH ");
        aMacquin.push_back("OvvO");

        vMacquin = new Mesh(scr, aMacquin, 4, 4);
        vMacquin->vCoord.x = (mx / 4) - 2;
        vMacquin->vCoord.y = my - 4;
    }

    void fTick()
    {
        scr->fClear();

        for (int k = 0; k < aWalls.size(); k++)
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
    }
};
