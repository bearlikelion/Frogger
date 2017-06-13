#pragma once

#include "Entity.h"

namespace FG
{
    class Frog : public Entity
    {
    public:
        Frog(sf::Vector2u size);
        void move(sf::Event event);
    };
}