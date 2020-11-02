#include "GameLevel.h"
#include <iostream>
#include <string>

GameLevel::GameLevel()
{
	levelNumber = 0;
	exitLocation = 0;
	active = false;
	name = "none";
}

GameLevel::GameLevel(int _levelNumber, int _exitLocation, bool _active, std::string _name)
{
	levelNumber = _levelNumber;
	exitLocation = _exitLocation;
	active = _active;
	name = _name;
	std::cout << "Game Level \'" << name << "\' Created" << std::endl;
}

GameLevel::~GameLevel()
{
	std::cout << "Game Level \'" << name << "\' Destroyed" << std::endl;
}