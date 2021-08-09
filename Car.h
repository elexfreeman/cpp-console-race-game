#pragma once
#include <vector>
#include <string>
#include "conf.h"
#include "ScreenG.h"
#include "Coord.h"
#include "Mesh.h"

class Car : public Mesh
{
protected:
    float nSpeed;

public:
    Car(ScreenG *_scr, std::vector<std::string> _aData, int _w, int _h, float _nSpeed)
        : Mesh(_scr, _aData, _w, _h)
    {

        nSpeed = _nSpeed;
    }
};
