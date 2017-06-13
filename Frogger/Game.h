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
    private:        
        RenderWindow *window;
        Frog *frog;
        Truck *truck;
        FrameTime frameStep, frameSlice, lastFrameTime, currentSlice;        
    public:
        Game();
        void input();
        void update();
        void draw();
        void run();
    };
}