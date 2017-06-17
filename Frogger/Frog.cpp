#include "Frog.h"

namespace FG
{
    Frog::Frog(sf::Vector2f size)
    {
        originalPosX = size.x / 2 - (FROG_SIZE / 2);
        originalPosY = size.y - FROG_SIZE;

        if (font.loadFromFile("Arial.ttf"))
        {	
            splatText.setFont(font);
            splatText.setString("SPLAT");			
            splatText.setFillColor(Color::Green);
            
            // Center the text on screen
            FloatRect textRect = splatText.getLocalBounds();
            splatText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f); // set new origin to left/top offeset
            splatText.setPosition(size.x / 2, size.y / 2 - FROG_SIZE);

            winText.setFont(font);
            winText.setString("WINNER");
            winText.setFillColor(Color::Blue);

            // Center the text on screen
            FloatRect textRect2 = winText.getLocalBounds();
            winText.setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top + textRect2.height / 2.0f); // set new origin to left/top offeset
            winText.setPosition(size.x / 2, size.y / 2 - FROG_SIZE);
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

    void Frog::win(RenderWindow &window)
    {
        window.draw(winText);
    }

    void Frog::update(sf::Event event)
    {
        if (sf::Keyboard::Key::Left == event.key.code) shape.move(-FROG_HOP, 0);        
        else if (sf::Keyboard::Key::Right == event.key.code) shape.move(FROG_HOP, 0);        
        else if (sf::Keyboard::Key::Up == event.key.code) shape.move(0, -FROG_HOP);        
        else if (sf::Keyboard::Key::Down == event.key.code) shape.move(0, FROG_HOP);        
    }
}