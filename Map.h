#pragma once
#include <vector>
#include <random>
#include "conf.h"
#include "ScreenG.h"
#include "Mesh.h"
#include "Car.h"

class Map
{
protected:
    ScreenG *scr;

    // визуализация объектов
    std::vector<std::string> vWall;
    std::vector<std::string> vRazmetka;
    std::vector<std::string> aMacquin;
    std::vector<std::string> aCarDown;
    std::vector<std::string> aCarUp;

    // массив объектов дороги
    std::vector<Mesh *> aWalls;

    // массив встркечных машин
    std::vector<Car *> aCarsDown;

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

        aCarDown.push_back("O  O");
        aCarDown.push_back(" TT ");
        aCarDown.push_back("OMMO");
        aCarDown.push_back(" vv ");

        aCarUp.push_back(" AA ");
        aCarUp.push_back("O()O");
        aCarUp.push_back(" () ");
        aCarUp.push_back("OTTO");

        Car* vCar1 = fGetCarDown();
        vCar1->vCoord.y = -5;
        Car* vCar2 = fGetCarDown();
        vCar2->vCoord.y = -10;

        aCarsDown.push_back(vCar1);
        aCarsDown.push_back(vCar2);
    }

    void fTick()
    {
        scr->fClear();

        fRenderRoad();
        fRenderCars();

        vMacquin->fPrintScr();

        scr->fPrint();
    }

    Car *fGetCarDown()
    {
        int nSpeed = rand() % 3 + 1;
        Car *vCarDown = new Car(scr, aCarDown, 4, 4, nSpeed);

        int nX = rand() % (mx - 5);
        int nY = (rand() % 5) - 10;

        vCarDown->vCoord.x = nX;
        vCarDown->vCoord.y = nY;

        return vCarDown;
    }

    void fRenderRoad()
    {
        for (int k = 0; k < aWalls.size(); k++)
        {
            aWalls[k]->vCoord.y += 1;
            if (aWalls[k]->vCoord.y > my)
            {
                aWalls[k]->vCoord.y = -5;
            }
            aWalls[k]->fPrintScr();
            aWalls[k]->fPrintScr();
        }
    }

    void fRenderCars()
    {
        for (int k = 0; k < aCarsDown.size(); k++)
        {
            aCarsDown[k]->vCoord.y += 1;
            if (aCarsDown[k]->vCoord.y > my)
            {
                aCarsDown.erase(aCarsDown.begin() + k);
                aCarsDown.push_back(fGetCarDown());
            }
            aCarsDown[k]->fPrintScr();
        }
    }
};
