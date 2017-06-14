#include "Frog.h"
#include <Windows.h>;
#include <iostream>;
#include <string>;

namespace FG
{
	Frog::Frog(sf::Vector2f size)
	{
		originalPosX = size.x / 2 - (FROG_SIZE / 2);
		originalPosY = size.y - FROG_SIZE;

		char path[MAX_PATH];
		GetCurrentDirectoryA(MAX_PATH, path);
		std::cout << path;

		// TODO: load font to display splat text		
		if (font.loadFromFile("Arial.ttf"))
		{	
			splatText.setFont(font);
			splatText.setString("SPLAT");
			splatText.setCharacterSize(48);
			splatText.setStyle(Text::Bold);
			splatText.setFillColor(Color::Green);
			
			FloatRect textRect = splatText.getLocalBounds();

			splatText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
			splatText.setPosition(size.x / 2, size.y / 2 - FROG_SIZE);
		}
		else
		{
			std::cout << "Failed to load Arial.ttf from: " << path;
		}

        shape.setSize(sf::Vector2f(FROG_SIZE, FROG_SIZE));
        Frog::reset();
    }

    void Frog::splat(RenderWindow &window)
    {        
        window.draw(splatText);
    }

    void Frog::reset()
    {
        shape.setPosition(originalPosX, originalPosY);
    }

    void Frog::update(sf::Event event)
    {
        if (sf::Keyboard::Key::Left == event.key.code)
        {
            shape.move(-FROG_HOP, 0);
        }
        else if (sf::Keyboard::Key::Right == event.key.code)
        {
            shape.move(FROG_HOP, 0);
        }
        else if (sf::Keyboard::Key::Up == event.key.code)
        {
            shape.move(0, -FROG_HOP);
        }
        else if (sf::Keyboard::Key::Down == event.key.code)
        {
            shape.move(0, FROG_HOP);
        }
    }

}