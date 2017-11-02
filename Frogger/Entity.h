#pragma once

#include <SFML\Graphics.hpp>

using namespace sf;

namespace fg
{
    class Entity
    {
    protected:
        RectangleShape shape;
        float originalPosX, originalPosY;
    public:
        Entity();
        void draw(RenderWindow &window);
        RectangleShape getShape();
    };
}