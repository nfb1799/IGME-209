#pragma once
class Player
{
protected:
	char* name;
	int strength;
	int speed;
	int health;

public:
	Player();
	Player(const char* n, int str, int spe, int hp);
	~Player();

	void PrintPlayer();
};

