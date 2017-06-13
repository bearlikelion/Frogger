#pragma once
#include <iostream>

#include "Entity.h"

using namespace std;

namespace FG
{
    class Truck : public Entity
    {
    public:
        Truck(float posX, float posY);
        void move(sf::Vector2u size);
    };
}