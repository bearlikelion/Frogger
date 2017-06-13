#pragma once

#include "BaseObject.h"

class Frog : public BaseObject
{
public:
    Frog(sf::Vector2u size);
    void move(sf::Event event);
};

