#include "Objects/Monsters/SadIsaac.hh"

#define L_BORDER 200
#define R_BORDER 270
#define T_BORDER 150
#define D_BORDER 250


SadIsaac::SadIsaac()
: Monster(0, 5, 300.0f)
{
    load("texture_pack/sadisaac.png");
    assert(is_loaded());

    get_sprite().setOrigin(get_sprite().getScale().x / 2,
                            get_sprite().getScale().y / 2);
}




SadIsaac::~SadIsaac()
{}




void SadIsaac::draw(sf::RenderWindow& window)
{
    Monster::draw(window);
}


void SadIsaac::update(float time)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        Game::set_game_state(Game::get_game_state(5));

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
