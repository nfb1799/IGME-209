#include "Orc.h"
#include <iostream>

using namespace std;

Orc::Orc() : MovableObject()
{
}

Orc::Orc(int _xPosition, int _yPosition) : MovableObject(_xPosition, _yPosition)
{
}

Orc::~Orc()
{
}

void Orc::Display()
{
	cout << "Object: Orc" << endl;
	cout << "Position: (" << xPosition << ", " << yPosition << ")" << endl;
}
