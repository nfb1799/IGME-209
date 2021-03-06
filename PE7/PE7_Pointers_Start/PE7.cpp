// PE7_Pointers_Start.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster *boss = new Monster();
	//Player *pOne = new Player();
	MovableObject *boss = new Monster();
	MovableObject *pOne = new Player();
	Monster *fakeMonster = (Monster*)pOne;

	// add code here
	cout << "Boss Address: " << &boss << endl;
	cout << "Player Address: " << &pOne << endl;
	cout << "Fake Monster Address: " << &fakeMonster << endl;
	boss->xPos = 2;
	boss->yPos = 3;
	pOne->xPos = 4;
	pOne->yPos = 1;
	fakeMonster->xPos = 2;
	fakeMonster->yPos = 6;
	
	cout << "Boss Positions -- ";
	boss->PrintPos();
	cout << "Player Positions -- ";
	pOne->PrintPos();
	cout << "Fake Monster Positions -- ";
	fakeMonster->PrintPos();

	delete boss;
	delete pOne;

	return 0;
}

/*
* 1.
* The original code threw an exception at the `delete fakeMonster;` call.
* This is because fakeMonster is set equal to pOne rather than a copy of it.
* When pOne gets deleted, fakeMonster is also deleted. 
* Therefore, fakeMonster cannot be deleted.
*/

/*
* 6.
* When the player object gets initialized as a MoveableObject rather than a Player,
* the player object never gets deleted.
*/

