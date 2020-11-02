#include <iostream>
#include <Box2D/Box2D.h>
#include "snake.h"
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <conio.h>

using namespace std;
using namespace sf;

int main()
{
    // Creates the world
    b2Vec2 gravity(0.0f, -1.0f);
    b2World world(gravity);

    // Creates the ground box
    b2BodyDef groundBodyDef; 
    groundBodyDef.position.Set(0.0f, -10.0f);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(5.0f, 1.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Creates the ceiling
    b2BodyDef ceilingBodyDef;
    ceilingBodyDef.position.Set(0.0f, 10.0f);
    b2Body* ceilingBody = world.CreateBody(&ceilingBodyDef);

    b2PolygonShape ceilingBox;
    ceilingBox.SetAsBox(5.0f, 1.0f);
    ceilingBody->CreateFixture(&ceilingBox, 0.0f);

    // Creates the left wall
    b2BodyDef leftWallBodyDef;
    leftWallBodyDef.position.Set(-5.0f, 0.0f);
    b2Body* leftWallBody = world.CreateBody(&leftWallBodyDef);

    b2PolygonShape leftWallBox;
    leftWallBox.SetAsBox(1.0f, 10.0f);
    leftWallBody->CreateFixture(&leftWallBox, 0.0f);

    // Creates the right wall
    b2BodyDef rightWallBodyDef;
    rightWallBodyDef.position.Set(5.0f, 0.0f);
    b2Body* rightWallBody = world.CreateBody(&rightWallBodyDef);

    b2PolygonShape rightWallBox;
    rightWallBox.SetAsBox(1.0f, 10.0f);
    rightWallBody->CreateFixture(&rightWallBox, 0.0f);

    // Creates the snake
    b2BodyDef snakeBodyDef;
    snakeBodyDef.type = b2_dynamicBody;
    snakeBodyDef.position.Set(0.0f, 9.0f);
    b2Body* snake = world.CreateBody(&snakeBodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    snake->CreateFixture(&fixtureDef);

    // Create the first target and variables for the game loop
    b2Vec2 target(1.0f, 1.0f); 
    bool running = false;
    int key;
    int score = 0;

    // Introduce the game and how to play
    cout << "Let's play Gravity Snake!" << endl;
    cout << "Use the arrow keys to move." << endl;
    cout << "Targets can be collected within 0.05 units." << endl;
    cout << "Collect 5 targets or hit esc to exit." << endl;
    cout << "Press space to start." << endl;
    if (_getch() == 32)
        running = true;

    // Set up deltaTime
    Clock deltaClock;
    Time deltaTime;
    
    while (running)
    {
        // Update deltaTime, reset deltaClock, then step the world
        deltaTime = deltaClock.getElapsedTime();
        deltaClock.restart();
        world.Step(deltaTime.asSeconds(), 6, 2);
        display(target, snake);

        // When a valid key is hit, a force is applied to the snake
        if (_kbhit()) 
        {
            key = _getch();
            if (key == 27)
                running = false;
            applyForces(key, snake);
        }
        
        // Checks if the snake hits the target and retargets when that happens
        if (checkCollisions(target, snake)) 
        {
            cout << "Target Hit!" << endl;
            cout << "Retargeting..." << endl;
            b2Vec2* targetPointer = &target;
            moveTarget(targetPointer, (rand() % 6) - 3, (rand() % 14) - 7);
            score++;
        }

        // Exits the game after 5 targets are hit
        if (score == 5)
            running = false;
    }
    cout << "Final score: " << score << endl;
}