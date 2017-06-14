#pragma once

#include "Entity.h"

namespace FG
{
    class Frog : public Entity
    {    
    protected:
        Font font;
        Text splatText;        
    public:
        Frog(sf::Vector2f size);
        void splat(RenderWindow &window);
        void reset();
        void update(sf::Event event);
    };
}