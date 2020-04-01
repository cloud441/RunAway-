#include "Objects/Player.hh"

Player::Player()
: velocity_(0), max_velocity_(600.0f)
{
    load("texture_pack/paddle.png");
    assert(is_loaded());

    get_sprite().setOrigin(get_sprite().getScale().x / 2,
                            get_sprite().getScale().y / 2);
}




Player::~Player()
{}




void Player::draw(sf::RenderWindow& window)
{
    VisibleObject::draw(window);
}




float Player::get_velocity() const
{
    return velocity_;
}




void Player::update(float time)
{
    int is_vertical = -1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        velocity_ = -5.0f;
        is_vertical = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        velocity_ = 5.0f;
        is_vertical = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        velocity_ = -5.0f;
        is_vertical = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        velocity_ = 5.0f;
        is_vertical = 1;
    }

    if (velocity_ > max_velocity_)
        velocity_ = max_velocity_;

    if (velocity_ < -max_velocity_)
        velocity_ = -max_velocity_;


    sf::Vector2f position = this->get_position();

    if (position.x < get_sprite().getScale().x / 2
        || position.y < get_sprite().getScale().y / 2)
    {
        velocity_ = abs(velocity_);
    }

    if (is_vertical == 1)
    {
        if (position.y + velocity_ * time < Game::SCREEN_HEIGHT - get_sprite().getScale().y / 2)
            get_sprite().move(0, velocity_ * time);
    }
    else if (!is_vertical)
    {
        if (position.x + velocity_ * time < Game::SCREEN_WIDTH - get_sprite().getScale().x / 2)
            get_sprite().move(velocity_ * time, 0);
    }
}
