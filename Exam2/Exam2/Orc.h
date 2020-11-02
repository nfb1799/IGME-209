#pragma once
#include "MovableObject.h"
class Orc :
    public MovableObject
{
public:
    Orc();
    Orc(int _xPosition, int _yPosition);
    ~Orc();

    void Display();
};

