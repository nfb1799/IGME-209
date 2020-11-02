#include <iostream>
#include "Item.h"
#include "Sword.h"
#include "Helmet.h"
#include "Shield.h"
#include "Armor.h"
#include <vector>

using namespace std;

int main()
{
    Sword* sword = new Sword();
    Helmet* helmet = new Helmet();
    Shield* shield = new Shield();
    Armor* armor = new Armor();
    vector<Item*> inventory(0);
    inventory.push_back(sword);
    inventory.push_back(helmet);
    inventory.push_back(shield);
    inventory.push_back(armor);

    for (Item* i : inventory)
        i->print();

    delete sword;
    sword = nullptr;
    
    delete helmet;
    helmet = nullptr;

    delete shield;
    shield = nullptr;

    delete armor;
    armor = nullptr;
}