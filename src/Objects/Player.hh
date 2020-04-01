#pragma once

#include <cassert>
#include <cmath>

#include "Objects/VisibleObject.hh"
#include "Game/Game.hh"




class Player : public VisibleObject
{

    public:
        Player();
        ~Player();

        void update(float time);
        void draw(sf::RenderWindow& window);

        float get_velocity() const;


    private:

        float velocity_x_;
        float velocity_y_;
        float max_velocity_;
};
