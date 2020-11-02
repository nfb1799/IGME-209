#pragma once
#include <string>

class GameLevel
{
public:
	GameLevel();
	GameLevel(int _levelNumber, int _exitLocation, bool _active, std::string _name);
	~GameLevel();

private:
	int levelNumber;
	int exitLocation;
	bool active;
	std::string name;
};

