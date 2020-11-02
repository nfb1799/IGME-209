#pragma once
#include <string>

struct Item
{
protected:
	std::string name;
	int damage;
	int weight;

public:
	Item();
	Item(std::string _name, int _damage, int _weight);

	void print();
};

