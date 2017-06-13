#include "Game.h"

namespace FG
{
    Game::Game()
    {
        window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
        frog = new Frog(window->getSize());
        truck = new Truck(0, float(window->getSize().y / 2));

    }

    // input
    void Game::input()
    {
        Event event;

        while (window->pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window->close();
            case Event::KeyReleased:
                if (Keyboard::Key::Escape == event.key.code) // TODO: PAUSE
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
        
        // TODO: Collision class
        if (frog->getShape().getGlobalBounds().intersects(truck->getShape().getGlobalBounds()))
        {
            // TODO: Move frog to originalPOS on collision
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
            Game::update(); // TODO: FRAME RATE UPDATE SLICING
            Game::draw();
        }
    }
}