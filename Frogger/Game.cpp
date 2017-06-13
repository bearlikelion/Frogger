#include "Game.h"

Game::Game()
{    
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Frogger");
    frog = new Frog(window->getSize());
    truck = new Truck(0, window->getSize().y / 2);    
}

void Game::Loop()
{
    while (window->isOpen())
    {
        // input
        sf::Event event;

        while (window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window->close();
            case sf::Event::KeyReleased:
                if (sf::Keyboard::Key::Escape == event.key.code)
                {
                    window->close();
                }
                else
                {
                    frog->move(event);
                }
                break;
            }
        }

        // update
        truck->move(window->getSize());        
        
        if (frog->getShape().getGlobalBounds().intersects(truck->getShape().getGlobalBounds()))            
        {
            window->close();
        }

        // draw
        window->clear();
        truck->draw(*window);
        frog->draw(*window);
        window->display();
    }
}