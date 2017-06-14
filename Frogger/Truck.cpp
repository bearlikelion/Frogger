#include "Truck.h"

namespace FG
{
    // TODO: Multiple trucks in one constructor
    Truck::Truck(float posX, float posY)
    {
        shape.setSize(sf::Vector2f(120, 60));
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(sf::Vector2f(posX, posY));

        originalPosX = posX;
        originalPosY = posY;
    }

    void Truck::move(sf::Vector2u size)
    {        
        shape.move(float(TRUCK_SPEED), 0);

        if (shape.getPosition().x > size.x)
        {
            shape.setPosition(sf::Vector2f(0 - shape.getSize().x, originalPosY));
        }
    }
}