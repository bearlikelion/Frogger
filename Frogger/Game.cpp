#include "Game.h"

namespace FG
{
    Game::Game()
    {
        window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
        FrameTime frameSlice = 1.0f, frameStep = 1.0f, lastFrameTime = 0.0f, currentSlice = 0.0f;

        bool died = false;
		Clock deadClock;

        frog = new Frog(Vector2f(window->getSize()));
        // TODO: MULTIPLE TRUCKS
        truck = new Truck(0, float(window->getSize().y / 2));
        truck2 = new Truck(0, float(window->getSize().y / 2) - FROG_SIZE);
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
            case Event::KeyPressed:
                if (Keyboard::Key::Escape == event.key.code) // TODO: PAUSE
                {
                    window->close();
                }
                else
                {
                    frog->update(event);
                }
                break;
            }
        }
    }

    // update
    void Game::update()
    {                
        currentSlice += lastFrameTime;
        for (; currentSlice >= frameSlice; currentSlice--)
        {            
            truck->move(window->getSize());
            truck2->move(window->getSize());

            // TODO: Collision class
            if (frog->getShape().getGlobalBounds().intersects(truck->getShape().getGlobalBounds()))
            {
				deadClock.restart();
                died = true;
                frog->reset();
            }
            else if (frog->getShape().getGlobalBounds().intersects(truck2->getShape().getGlobalBounds()))
            {
				deadClock.restart();
                died = true;
                frog->reset();
            }
            else if (frog->getShape().getPosition().y < 0) 
            {
                // TODO: WIN STATE
                frog->reset();
            }
        }        
    }

    // draw
    void Game::draw()
    {
        window->clear();            

        truck->draw(*window);
        truck2->draw(*window);        

		if (died == true)
		{									
			if (deadClock.getElapsedTime().asSeconds() <= DEAD_TIME)
			{
				cout << to_string(deadClock.getElapsedTime().asSeconds()) << endl;
				frog->splat(*window);
			}
			else
			{				
				died = false;				
			}
		}
		else
		{
			frog->draw(*window);
		}

        window->display();
    }

    // Game loop
    void Game::run()
    {
        while (window->isOpen())
        {   
            // Start frame
            time_point<steady_clock> startTime = steady_clock::now();

            Game::input();
            Game::update(); // TODO: FRAME RATE UPDATE SLICING
            Game::draw();

            // End Frame
            time_point<steady_clock> endTime = steady_clock::now();            
            auto elapsedTime = (endTime - startTime);
            FrameTime ft = duration_cast<duration<float, milli>>(elapsedTime).count();
            lastFrameTime = ft;
            
            float fps(1.0f / (ft / 1000.0f));
            // window->setTitle("FT: " + to_string(lastFrameTime) + " - FPS: " + to_string(fps));
        }
    }
}