#pragma once


#include <cassert>
#include <cstdlib>

#include "Objects/Monsters/Monster.hh"
#include "Game/Game.hh"




class SadIsaac : public Monster
{

    public:
        SadIsaac();
        ~SadIsaac();

       void update(float time);
       void draw(sf::RenderWindow& window);
};
