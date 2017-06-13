#include "Game.h"

Game::Game()
{    
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    frog = new Frog(window->getSize());
    truck = new Truck(0, float(window->getSize().y / 2));    
    
}

// input
void Game::input()
{   
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
}

// update
void Game::update()
{
    truck->move(window->getSize());
    if (frog->getShape().getGlobalBounds().intersects(truck->getShape().getGlobalBounds()))
    {
        window->close();
    }
}

// draw
void Game::draw()
{    
    window->clear();
    truck->draw(*window);
    frog->draw(*window);
    window->display();
}

// Game loop
void Game::run()
{
    while (window->isOpen())
    {
        Game::input();
        Game::update();
        Game::draw();
    }
}