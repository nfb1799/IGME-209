#include "Item.h"
#include <string>
#include <iostream>

using namespace std;

Item::Item()
{
	name = "Item";
	damage = 0;
	weight = 0;
}

Item::Item(string _name, int _damage, int _weight)
{
	name = _name;
	damage = _damage;
	weight = _weight;
}

void Item::print()
{
	cout << "Name: " << name << endl;
	cout << "Damage: " << damage << endl;
	cout << "Weight: " << weight << endl;
}