#pragma once


#include <cmath>

#include "Objects/VisibleObject.hh"


class Monster: public VisibleObject
{

    public:
        Monster();
        Monster(float velocity_x, float velocity_y, float max_velocity);
        ~Monster();

        void update(float time);
        void draw(sf::RenderWindow& window);

        float get_velocity() const;

    protected:

        float velocity_x_;
        float velocity_y_;
        float max_velocity_;
};
