#include "Objects/Monsters/Monster.hh"



Monster::Monster()
: velocity_x_(0), velocity_y_(0), max_velocity_(600.0f)
{}




Monster::Monster(float velocity_x, float velocity_y, float max_velocity)
: velocity_x_(velocity_x), velocity_y_(velocity_y), max_velocity_(max_velocity)
{}




Monster::~Monster()
{}




void Monster::draw(sf::RenderWindow& window)
{
    VisibleObject::draw(window);
}





void Monster::update(float time)
{
    time = time;
}




float Monster::get_velocity() const
{
    return sqrt(velocity_x_ * velocity_x_ + velocity_y_ * velocity_y_);
}
