#pragma once

#include "Entity.h"

namespace fg
{
    class Frog : public Entity
    {    
    protected:
        Font font;
        Text splatText;        
		Text winText;
    public:
        Frog(sf::Vector2f size);		
        void splat(RenderWindow &window);        
		void win(RenderWindow &window);
        void update(sf::Event event);
		void reset();
    };
}