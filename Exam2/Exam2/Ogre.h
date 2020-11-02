#pragma once
#include "MovableObject.h"
class Ogre :
    public MovableObject
{
private:
    int* inventoryIds;

public:
    Ogre();
    Ogre(int _xPosition, int _yPosition);
    Ogre(int _xPosition, int _yPosition, int* _inventoryIds);
    ~Ogre();

    void Display();
};

