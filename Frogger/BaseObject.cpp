#include "BaseObject.h"

sf::RectangleShape shape;

BaseObject::BaseObject()
{   
}

void BaseObject::draw(sf::RenderWindow &window)
{
    window.draw(shape);
}

sf::RectangleShape BaseObject::getShape()
{
    return shape;
}
