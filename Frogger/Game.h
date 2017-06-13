#pragma once

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
    void input();
    void update();
    void draw();
    void run();
};

