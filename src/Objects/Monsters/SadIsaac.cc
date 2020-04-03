#include "Objects/Monsters/SadIsaac.hh"

#define L_BORDER 300
#define R_BORDER 350
#define T_BORDER 200
#define D_BORDER 300




SadIsaac::SadIsaac()
: Monster(0, 0, 300.0f)
{

    velocity_x_ = rand() % 10;
    velocity_y_ = rand() % 10;

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


    //Random change of velocity and direction (7% chance):
    if (rand() % 1000 < 10)
    {
        velocity_x_ = rand() % 10;
        velocity_y_ = rand() % 10;
    }





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

    if (velocity_x_ > 0)
    {
        if (position.x + velocity_x_ * time > Game::SCREEN_WIDTH - R_BORDER)
            velocity_x_ = -velocity_x_;
    }
    else
    {
        if (position.x + velocity_x_ * time < L_BORDER)
            velocity_x_ = -velocity_x_;
    }


    get_sprite().move(velocity_x_ * time, velocity_y_ * time);
}
