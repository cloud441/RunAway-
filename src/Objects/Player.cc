#include "Objects/Player.hh"

#define BORDER 30

Player::Player()
: velocity_x_(0), velocity_y_(0), max_velocity_(600.0f)
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
    return sqrt(velocity_x_ * velocity_x_ + velocity_y_ * velocity_y_);
}




void Player::update(float time)
{
    int is_moving = false;
    velocity_x_ = 0;
    velocity_y_ = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        velocity_x_ = -5.0f;
        is_moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        velocity_x_ = 5.0f;
        is_moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        velocity_y_ = -5.0f;
        is_moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        velocity_y_ = 5.0f;
        is_moving = true;
    }

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


    if (is_moving)
    {
        if (position.y + velocity_y_ * time < Game::SCREEN_HEIGHT - 4 * BORDER
            && position.y + velocity_y_ * time > BORDER)
            get_sprite().move(0, velocity_y_ * time);

        if (position.x + velocity_x_ * time < Game::SCREEN_WIDTH -  3 * BORDER
            && position.x + velocity_x_ * time > BORDER)
            get_sprite().move(velocity_x_ * time, 0);
    }
}
