/*  The unique aspect I added to my game is the ability to freeze
    all forces applied to the snake. Sometimes the snake gets moving
    quite fast and hard to control. Instead of spending a lot of 
    forces to correct it, the player can simply freeze all forces.
*/

#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "snake.h"
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

int main()
{
    // create the window
    RenderWindow window(VideoMode(800, 600), "My window");

    // Creates the world
    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);

    // Creates the ground box
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, 0.0f);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(800.0f, 1.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    RectangleShape groundRect(Vector2f(800, 5));
    groundRect.setFillColor(Color(200, 155, 120));
    groundRect.setPosition(0, 0);

    // Creates the ceiling
    b2BodyDef ceilingBodyDef;
    ceilingBodyDef.position.Set(0.0f, 585.0f);
    b2Body* ceilingBody = world.CreateBody(&ceilingBodyDef);

    b2PolygonShape ceilingBox;
    ceilingBox.SetAsBox(800.0f, 1.0f);
    ceilingBody->CreateFixture(&ceilingBox, 0.0f);

    RectangleShape ceilingRect(Vector2f(800, 5));
    ceilingRect.setFillColor(Color(200, 155, 120));
    ceilingRect.setPosition(0, 595);

    // Creates the left wall
    b2BodyDef leftWallBodyDef;
    leftWallBodyDef.position.Set(0.0f, 0.0f);
    b2Body* leftWallBody = world.CreateBody(&leftWallBodyDef);

    b2PolygonShape leftWallBox;
    leftWallBox.SetAsBox(1.0f, 600.0f);
    leftWallBody->CreateFixture(&leftWallBox, 0.0f);

    RectangleShape leftRect(Vector2f(5, 600));
    leftRect.setFillColor(Color(200, 155, 120));
    leftRect.setPosition(0, 0);

    // Creates the right wall
    b2BodyDef rightWallBodyDef;
    rightWallBodyDef.position.Set(785.0f, 0.0f);
    b2Body* rightWallBody = world.CreateBody(&rightWallBodyDef);

    b2PolygonShape rightWallBox;
    rightWallBox.SetAsBox(1.0f, 600.0f);
    rightWallBody->CreateFixture(&rightWallBox, 0.0f);

    RectangleShape rightRect(Vector2f(5, 600));
    rightRect.setFillColor(Color(200, 155, 120));
    rightRect.setPosition(795, 0);

    // Creates the snake
    b2BodyDef snakeBodyDef;
    snakeBodyDef.type = b2_dynamicBody;
    snakeBodyDef.position.Set(750.0f, 550.0f);
    b2Body* snake = world.CreateBody(&snakeBodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    snake->CreateFixture(&fixtureDef);

    CircleShape snakeDisplay(10, 4);
    snakeDisplay.setFillColor(Color(102, 255, 255));

    // Create the first target 
    b2Vec2 target(100.0f, 100.0f);
    CircleShape targetDisplay(10);
    targetDisplay.setFillColor(Color(255, 255, 255));
    targetDisplay.setPosition(100, 100);
    
    // Create font for all texts
    Font font; 
    font.loadFromFile("ARIAL.ttf");

    // Create the welcome text
    Text welcomeText("Welcome to Graphical Snake!", font, 48);
    welcomeText.setFillColor(Color::Cyan);
    welcomeText.setPosition(80, 10);

    // Create the instructions text
    Text instructions("Use the Arrow Keys to Move\n\nPress 'F' to Freeze Forces", font, 32);
    instructions.setFillColor(Color::White);
    instructions.setPosition(190, 150);

    // Create the objective text
    Text goal("Collect Two Targets while Applying the Least Forces", font, 32);
    goal.setFillColor(Color::Cyan);
    goal.setPosition(35, 325);

    Text startText("Press Space to Start", font, 32);
    startText.setFillColor(Color::White);
    startText.setPosition(250, 520);

    // Create the forces applied text
    Text forcesApplied("Forces Applied:", font, 16);
    forcesApplied.setFillColor(Color::Cyan);
    forcesApplied.setPosition(10, 10);

    // Number of inputs used to complete the game
    int forces = 0;
    Text forcesDisplay("0", font, 16);
    forcesDisplay.setFillColor(Color::Red);
    forcesDisplay.setPosition(120, 10);

    // Create the freeze text
    Text freezeText("Frozen\nPress 'G' to unfreeze", font, 36);
    freezeText.setFillColor(Color::Red);
    freezeText.setPosition(200, 150);

    // Displayed when the user completes the game
    Text finalScore("none", font, 48);
    finalScore.setFillColor(Color::Cyan);
    finalScore.setPosition(200, 150);

    // Creates remaining number of targets and the pause toggle
    int targetsRemaining = 2;
    bool pause = false;
    bool start = false;

    // Creates the clock
    Clock deltaClock;
    Time deltaTime;

    // Clear the window and display instructions before game start
    window.clear(Color::Black);
    window.draw(welcomeText);
    window.draw(instructions);
    window.draw(goal);
    window.draw(startText);
    window.display();
    while (!start)
    {
        if (Keyboard::isKeyPressed(Keyboard::Space))
            start = true;
    }

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Runs the gameloop until no targets remain
        if(targetsRemaining != 0)
        {
            // Update deltaTime, reset deltaClock, then step the world
            deltaTime = deltaClock.getElapsedTime();
            deltaClock.restart();
            world.Step(deltaTime.asSeconds(), 6, 2);

            // clear the window with black color
            window.clear(Color::Black);

            // updates the positions of the snake and the target
            snakeDisplay.setPosition((snake->GetPosition().x),(snake->GetPosition().y));
            targetDisplay.setPosition(target.x, target.y);

            // draws all necessary items to the window
            window.draw(snakeDisplay);
            window.draw(targetDisplay);
            window.draw(groundRect);
            window.draw(ceilingRect);
            window.draw(leftRect);
            window.draw(rightRect);
            window.draw(forcesApplied);
            window.draw(forcesDisplay);

            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                applyForces(75, snake); // left
                forces++;
            }

            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                applyForces(77, snake); // right
                forces++;
            }

            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                applyForces(72, snake); // up
                forces++;
            }

            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                applyForces(80, snake); // down
                forces++;
            }

            if (Keyboard::isKeyPressed(Keyboard::F))
            {
                window.draw(freezeText);
                window.display();
                pause = true;
            }

            // freezes the games and all forces until 'G' is pressed
            while (pause)
            {
                if (Keyboard::isKeyPressed(Keyboard::G))
                    pause = false;
            }

            // update the force display
            forcesDisplay.setString(to_string(forces));

            // Checks if the snake hits the target and retargets when that happens
            if (checkCollisions(target, snake))
            {
                b2Vec2* targetPointer = &target;
                moveTarget(targetPointer, (rand() % 775), (rand() % 575));
                targetsRemaining--;
            }
        }

        // if both targets have been collected
        if (targetsRemaining == 0) 
        {
            // print the final score and how to quit
            finalScore.setString("Total Forces Applied:\n\t\t\t" + to_string(forces) + "\n\nPress Space to Quit");
            window.clear(Color::Black);
            window.draw(finalScore);
            window.display();
        }

        while (targetsRemaining == 0) 
        {
            if (Keyboard::isKeyPressed(Keyboard::Space))
                window.close();
        }

        // end the current frame
        window.display();

    }
}
