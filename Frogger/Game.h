#pragma once

#include "DEFINITIONS.h"

#include "Frog.h"
#include "Truck.h"

using namespace sf;

namespace FG
{
    class Game
    {
    private:
        RenderWindow *window;
        Frog *frog;
        Truck *truck;
    public:
        Game();
        void input();
        void update();
        void draw();
        void run();
    };


}