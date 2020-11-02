#include <iostream>
#include "Player.h"
#include "Fighter.h"

using namespace std;

int main()
{
	Player p1 = Player();

	char p2Name[] = "Player2";
	char* p2NamePtr = p2Name;
	Player p2 = Player(p2NamePtr, 8, 9, 10);

	Player* p3 = new Player();

	char p4Name[] = "Player4";
	char* p4NamePtr = p4Name;
	Player* p4 = new Player(p4NamePtr, 4, 5, 6);

	Fighter f1 = Fighter();
	Fighter f2 = Fighter("Fighter2", 1, 2, 3, 4);

	p1.PrintPlayer();
	p2.PrintPlayer();
	p3->PrintPlayer();
	p4->PrintPlayer();
	f1.PrintFighter();
	f2.PrintFighter();

	delete p3;
	p3 = nullptr;

	delete p4;
	p4 = nullptr;
}
