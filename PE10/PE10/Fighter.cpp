#include "Fighter.h"
#include <iostream>

using namespace std;

Fighter::Fighter() : Player()
{
	weaponSkill = 0;
}

Fighter::Fighter(const char* _name, int _weaponSkill, int _strength, int _speed, int _health) : Player(_name, _strength, _speed, _health)
{
	weaponSkill = _weaponSkill;
}

void Fighter::PrintFighter()
{
	Player::PrintPlayer();
	cout << "Weapon Skill: " << weaponSkill << endl;
}