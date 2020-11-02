#include "Ogre.h"
#include <iostream>

using namespace std;

Ogre::Ogre() : MovableObject()
{
	inventoryIds = new int[3]{ 3, 9, 12 };
}

Ogre::Ogre(int _xPosition, int _yPosition) : MovableObject(_xPosition, _yPosition)
{
	inventoryIds = new int[3]{ 3, 9, 12 };
}

Ogre::Ogre(int _xPosition, int _yPosition, int* _inventoryIds) : MovableObject(_xPosition, _yPosition)
{
	inventoryIds = _inventoryIds;
}

Ogre::~Ogre()
{
	delete[] inventoryIds;
	inventoryIds = nullptr;
}

void Ogre::Display()
{
	cout << "Object: Ogre" << endl;
	cout << "Inventory IDs: " << inventoryIds[0] << ", " << inventoryIds[1] << ", " << inventoryIds[2] << endl;
	cout << "Position: (" << xPosition << ", " << yPosition << ")" << endl;
}