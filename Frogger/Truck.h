#pragma once
#include <SFML\Graphics.hpp>

class Truck
{
private:
	sf::RectangleShape truck;
	float originalPosX, originalPosY;
public:
	Truck(float posX, float posY);

	void draw(sf::RenderWindow &window);
	void move(sf::Vector2u size);

	sf::RectangleShape getShape();
};

