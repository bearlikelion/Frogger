#include <SFML/Graphics.hpp>
#include "Frog.h"
#include "Truck.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Frogger");

	Frog frog(window.getSize());
	Truck truck(0, window.getSize().y / 2);

    while (window.isOpen())
    {
        // input
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type) 
			{
			case sf::Event::Closed:
				window.close();
			case sf::Event::KeyReleased:
				if (sf::Keyboard::Key::Escape == event.key.code) 
				{
					window.close();
				}
				else 
				{
					frog.move(event);
				}
				break;				
			}
        }

        // update
		truck.move(window.getSize());

        if (frog.getShape().getGlobalBounds().intersects(truck.getShape().getGlobalBounds()))
        {
            window.close();
        }

		// draw
        window.clear();       
		truck.draw(window);
		frog.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}