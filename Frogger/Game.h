#pragma once

#include <SFML\Graphics.hpp>
#include "Frog.h"
#include "Truck.h"

class Game
{
private:
    sf::RenderWindow *window;
    Frog *frog;
    Truck *truck;
public:
    Game();
    
    void Loop();
};

