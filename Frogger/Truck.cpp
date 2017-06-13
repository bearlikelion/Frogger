#include "Truck.h"

sf::RectangleShape truck;

Truck::Truck(float posX, float posY)
{
	truck.setSize(sf::Vector2f(120, 60));
	truck.setFillColor(sf::Color::Red);
	truck.setPosition(sf::Vector2f(posX, posY));

	originalPosX = posX;
	originalPosY = posY;
}

void Truck::draw(sf::RenderWindow &window)
{
	window.draw(truck);	
}

void Truck::move(sf::Vector2u size)
{
	truck.move(0.2, 0);

	if (truck.getPosition().x > size.x)
	{
        truck.setPosition(sf::Vector2f(0 - truck.getSize().x, originalPosY));
	}
}

sf::RectangleShape Truck::getShape()
{
	return truck;
}
