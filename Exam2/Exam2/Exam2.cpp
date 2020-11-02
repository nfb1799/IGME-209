/*	Nik Barbero
*	IGME 209-01
*	Exam #2
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "MovableObject.h"
#include "Orc.h"
#include "Ogre.h"

using namespace std;

int main()
{
	vector<MovableObject*> objects;
	srand(time(NULL));

	objects.push_back(new Orc(rand() % 200 - 100, rand() % 200 - 100));
	objects.push_back(new Orc(rand() % 200 - 100, rand() % 200 - 100));
	objects.push_back(new Ogre(rand() % 200 - 100, rand() % 200 - 100));
	objects.push_back(new Ogre(rand() % 200 - 100, rand() % 200 - 100));
	objects.push_back(new Ogre(rand() % 200 - 100, rand() % 200 - 100));

	for (MovableObject* obj : objects) 
	{
		obj->Display();
		delete obj;
		obj = nullptr;
	}
}
