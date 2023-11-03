#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameOfLife.h"
using namespace sf;

int main()
{
    RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML works!");
    srand(time(NULL));
    window->setFramerateLimit(60);

    GameOfLife gameOfLife(window);
    

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                std::cout << "click!\n";
            }
            else if (event.type == Event::KeyPressed) {
                
            }
        }
        window->clear({ 66,66,66 });

        gameOfLife.update();
        gameOfLife.draw(window);

        window->display();
    }

    return 0;
}