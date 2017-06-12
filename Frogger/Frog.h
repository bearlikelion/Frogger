#pragma once
#include <SFML\Graphics.hpp>

class Frog
{
private:
    sf::RectangleShape frog;
public:
    Frog(sf::Vector2u size);
    
    void draw(sf::RenderWindow &window);
    void move(sf::Event event);

    sf::RectangleShape getShape();
};

