#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

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

        // clear the window with black color
        window.clear(sf::Color::Black);

        // create a circle
        sf::CircleShape circle(75);
        circle.setFillColor(sf::Color(255, 255, 255));
        circle.setPosition(10, 150);

        // create a square
        sf::CircleShape square(35, 4);
        square.setFillColor(sf::Color(255, 0, 255));
        square.setPosition(250, 50);

        // create a rectangle
        sf::RectangleShape rect(sf::Vector2f(300, 150));
        rect.setFillColor(sf::Color(52, 235, 229));
        rect.setPosition(400, 400);

        // create a convex shape
        sf::ConvexShape convex;
        convex.setPointCount(6);

        convex.setPoint(0, sf::Vector2f(20, 0));
        convex.setPoint(1, sf::Vector2f(0, 30));
        convex.setPoint(2, sf::Vector2f(30, 75));
        convex.setPoint(3, sf::Vector2f(45, 65));
        convex.setPoint(4, sf::Vector2f(20, 40));
        convex.setPoint(5, sf::Vector2f(15, 15));

        convex.setFillColor(sf::Color(52, 235, 52));
        convex.setPosition(250, 250);

        // create an octagon with a boarder
        sf::CircleShape oct(125, 8);
        oct.setFillColor(sf::Color(235, 235, 52));

        oct.setOutlineThickness(5);
        oct.setOutlineColor(sf::Color(255, 0, 0));
        oct.setPosition(400, 100);
        
        // draw everything here...
        window.draw(circle);
        window.draw(square);
        window.draw(rect);
        window.draw(convex);
        window.draw(oct);

        // end the current frame
        window.display();
    }
}
