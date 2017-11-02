#pragma once
#include <chrono>
#include <iostream>

#include "CONSTANTS.h"
#include "Frog.h"
#include "Truck.h"

using namespace sf;
using namespace std;
using namespace chrono;

using FrameTime = float;

namespace fg
{
    class Game
    {
    private:        
        RenderWindow *window;
        Frog *frog;
        Truck *truck;        
        bool dead, win;
		Clock deadClock;
        FrameTime frameStep, frameSlice, lastFrameTime, currentSlice;        
    public:
        Game();
        void input();
        void update();
        void draw();
        void start();
    };
}