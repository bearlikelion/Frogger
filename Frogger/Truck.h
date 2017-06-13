#pragma once

#include "BaseObject.h"

class Truck : public BaseObject
{
public:
	Truck(float posX, float posY);	
	void move(sf::Vector2u size);
};

