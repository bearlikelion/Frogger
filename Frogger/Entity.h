#pragma once

#include <SFML\Graphics.hpp>
#include "DEFINITIONS.h"

using namespace sf;

namespace FG
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