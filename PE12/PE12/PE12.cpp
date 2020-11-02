#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <memory>
#include <string>
#include "GameLevel.h"

using namespace std;

void smartPointerTest()
{
	unique_ptr<GameLevel> gamePtr(new GameLevel(1, 1, true, "Smart Pointer Level"));
}

void dumbPointerTest()
{
	GameLevel* level = new GameLevel(2, 2, true, "Dumb Pointer Level");
}

int main()
{
	smartPointerTest();
	dumbPointerTest();
	_CrtDumpMemoryLeaks();
}