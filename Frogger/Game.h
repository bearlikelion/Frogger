#pragma once
#include <chrono>
#include <iostream>

#include "DEFINITIONS.h"
#include "Frog.h"
#include "Truck.h"

using namespace sf;
using namespace std;
using namespace chrono;

using FrameTime = float;

namespace FG
{
    class Game
    {        
    public:        
        Game();
        
        bool dead, win;
        Clock deadClock;
        RenderWindow *window;

        void input();
        void update();
        void draw();
        void run();
    private:        
        Frog *frog;
        Truck *truck;                
    };
}