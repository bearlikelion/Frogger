#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Starter Template");

    sf::RectangleShape frog;

    


    sf::RectangleShape truck;

    truck.setSize(sf::Vector2f(120, 60));
    truck.setFillColor(sf::Color::Red);
    truck.setPosition(sf::Vector2f(truck.getPosition().x, window.getSize().y / 2 - truck.getSize().y));

    while (window.isOpen())
    {
        // handle events
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:

                if (sf::Keyboard::Key::Left == event.key.code)
                {
                    frog.move(-80, 0);
                }
                else if (sf::Keyboard::Key::Right == event.key.code)
                {
                    frog.move(80, 0);
                }
                else if (sf::Keyboard::Key::Up == event.key.code)
                {
                    frog.move(0, -80);
                }
                else if (sf::Keyboard::Key::Down == event.key.code)
                {
                    frog.move(0, 80);
                }
            }
        }

        // update
        truck.move(0.2, 0);

        if (truck.getPosition().x > window.getSize().x)
        {
            truck.setPosition(sf::Vector2f(-truck.getSize().x, window.getSize().y / 2 - truck.getSize().y));
        }

        if (frog.getGlobalBounds().intersects(truck.getGlobalBounds()))
        {
            window.close();
        }

        window.clear();

        // draw SFML content
        
        window.draw(truck);

        window.display();
    }

    return EXIT_SUCCESS;
}