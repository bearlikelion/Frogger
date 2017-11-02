#include "Entity.h"

RectangleShape shape;

namespace fg
{
    Entity::Entity()
    {
    }

    void Entity::draw(RenderWindow &window)
    {
        window.draw(shape);
    }

    RectangleShape Entity::getShape()
    {
        return shape;
    }
}