#pragma once
#include <SFML\Graphics.hpp>

class Frog
{
private:
    sf::RectangleShape frog;
public:
    Frog(sf::Vector2u size);
    
    void Draw(sf::RenderWindow &window);
    void Move(sf::Event event);

    sf::RectangleShape getShape();
};

