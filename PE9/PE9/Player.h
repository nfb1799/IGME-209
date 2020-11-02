#pragma once
class Player
{
private:
	char* name;
	int strength;
	int speed;
	int health;

public:
	Player();
	Player(char* n, int str, int spe, int hp);
	~Player();

	void PrintPlayer();
};

