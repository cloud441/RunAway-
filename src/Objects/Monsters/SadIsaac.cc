#include "Objects/Monsters/SadIsaac.hh"

#define L_BORDER 250
#define R_BORDER 320
#define T_BORDER 200
#define D_BORDER 300




SadIsaac::SadIsaac()
: Monster(0, 5, 300.0f)
{
    load("texture_pack/sadisaac.png");
    assert(is_loaded());

    get_sprite().setOrigin(25, 30);
}




SadIsaac::~SadIsaac()
{}




void SadIsaac::draw(sf::RenderWindow& window)
{
    Monster::draw(window);
}


void SadIsaac::update(float time)
{
    if (velocity_x_ > max_velocity_)
        velocity_x_ = max_velocity_;

    if (velocity_x_ < -max_velocity_)
        velocity_x_ = -max_velocity_;

    if (velocity_y_ > max_velocity_)
        velocity_y_ = max_velocity_;

    if (velocity_y_ < -max_velocity_)
        velocity_y_ = -max_velocity_;



    sf::Vector2f position = this->get_position();


    if (velocity_y_ > 0)
    {
        if (position.y + velocity_y_ * time > Game::SCREEN_HEIGHT - D_BORDER)
            velocity_y_ = -velocity_y_;
    }
    else
    {
        if (position.y + velocity_y_ * time < T_BORDER)
            velocity_y_ = -velocity_y_;
    }

    get_sprite().move(0, velocity_y_ * time);
}
