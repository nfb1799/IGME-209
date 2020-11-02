#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{
	name = new char[] {"Unknown"};
	strength = 10;
	speed = 10;
	health = 10;
}
Player::Player(char* n, int str, int spe, int hp)
{
	name = n;
	strength = str;
	speed = spe;
	health = hp;
}

Player::~Player()
{
	name = nullptr;
}

void Player::PrintPlayer()
{
	cout << "Name: " << name << endl;
	cout << "Strength: " << strength << endl;
	cout << "Speed: " << speed << endl;
	cout << "Health: " << health << endl;
}