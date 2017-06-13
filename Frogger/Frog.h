#pragma once

#include "BaseObject.h"
#include "DEFINITIONS.h"

class Frog : public BaseObject
{
public:
    Frog(sf::Vector2u size);
    void move(sf::Event event);
};

