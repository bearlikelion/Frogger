#pragma once

#include <SFML\Graphics.hpp>

class BaseObject
{
protected:
    sf::RectangleShape shape;
    float originalPosX, originalPosY;
public:
    BaseObject();
    void draw(sf::RenderWindow &window);
    sf::RectangleShape getShape();
};