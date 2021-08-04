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

public:
    Map(ScreenG *_scr)
    {
        this->scr = _scr;
    }

    void fAddMesh(Mesh *vMesh)
    {
        aMesh.push_back(vMesh);
    }

    void fPrint()
    {
        for (int k = 0; k < aMesh.size(); k++)
        {
        }
    }
};
