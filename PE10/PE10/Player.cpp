#include "Player.h"
#include <iostream>
#include <cstring>

using namespace std;

Player::Player()
{
	name = new char[8] {"Unknown"};
	strength = 10;
	speed = 10;
	health = 10;
}
Player::Player(const char* _name, int _strength, int _speed, int _health)
{
	int size = strlen(_name) + 1;
	name = new char[size];
	strcpy_s(name, size, _name);

	strength = _strength;
	speed = _speed;
	health = _health;
}

Player::~Player()
{
	delete[] name;
	name = nullptr;
}

void Player::PrintPlayer()
{
	cout << "Name: " << name << endl;
	cout << "Strength: " << strength << endl;
	cout << "Speed: " << speed << endl;
	cout << "Health: " << health << endl;
}