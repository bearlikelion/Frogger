#include "Frog.h"

sf::RectangleShape frog;

Frog::Frog(sf::Vector2u size)
{
    frog.setSize(sf::Vector2f(80, 80));
    frog.setPosition(sf::Vector2f(frog.getPosition().x, size.y - frog.getSize().y));
}

void Frog::Draw(sf::RenderWindow &window)
{
    window.draw(frog);
}

void Frog::Move(sf::Event event)
{

}

sf::RectangleShape Frog::getShape()
{
    return frog;
}
