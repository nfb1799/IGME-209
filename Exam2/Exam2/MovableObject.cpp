#include "MovableObject.h"
#include <iostream>

using namespace std;

MovableObject::MovableObject()
{
	xPosition = 0;
	yPosition = 0;
}

MovableObject::MovableObject(int _xPosition, int _yPosition)
{
	xPosition = _xPosition;
	yPosition = _yPosition;
}

MovableObject::~MovableObject()
{

}

void MovableObject::SetPosition(int x, int y)
{
	xPosition = x;
	yPosition = y;
}

void MovableObject::Display()
{
	cout << "Position: (" << xPosition << ", " << yPosition << ")" << endl;
}