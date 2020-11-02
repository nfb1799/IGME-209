#include <iostream>
#include <Box2D/Box2D.h>
#include "snake.h"
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void display(b2Vec2 target, b2Body* snake)
{
	b2Vec2 pos = snake->GetPosition();
	cout << "Target: " << target.x << ", " << target.y << " --> " <<
		"Snake: " << pos.x << ", " << pos.y << endl;
}

void applyForces(int dir, b2Body* snake)
{
	b2Vec2 force(0.0f, 0.0f);
	if (dir == 72) // up
		force.Set(0.0, 10000.0f);
	else if (dir == 75) // left
		force.Set(-1000.0f, 0.0f);
	else if (dir == 77) // right
		force.Set(1000.0f, 0.0f);
	else if (dir == 80) // down
		force.Set(0.0f, -100.0f);
	snake->ApplyForceToCenter(force, true);
}

bool checkCollisions(b2Vec2 target, b2Body* snake)
{
	b2Vec2 pos = snake->GetPosition();
	if (
		(target.x - pos.x < 0.05f && target.x - pos.x > -0.05f)
		&&
		(target.y - pos.y < 0.05f && target.y - pos.y > -0.05f)
		)
		return true;
	return false;
}

void moveTarget(b2Vec2* target, float x, float y)
{
	target->Set(x, y);
}
