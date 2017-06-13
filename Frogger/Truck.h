#pragma once

#include "Entity.h"

namespace FG
{
    class Truck : public Entity
    {
    public:
        Truck(float posX, float posY);
        void move(sf::Vector2u size);
    };
}