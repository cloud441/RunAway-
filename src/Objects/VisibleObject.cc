#include "Objects/VisibleObject.hh"





VisibleObject::VisibleObject()
: is_load_(false)
{}





VisibleObject::~VisibleObject()
{}





void VisibleObject::load(std::string filename)
{
    if (!texture_.loadFromFile(filename))
    {
        filename_ = "";
        is_load_ = false;
    }
    else
    {
        filename_ = filename;
        sprite_.setTexture(texture_);
        is_load_ = true;
    }
}




void VisibleObject::draw(sf::RenderWindow& window)
{
    if (is_load_)
        window.draw(sprite_);
}




void VisibleObject::update(float time)
{
    time = time;
}





void VisibleObject::set_position(float x, float y)
{
    if (is_load_)
        sprite_.setPosition(x, y);
}




sf::Vector2f VisibleObject::get_position() const
{
    return is_load_ ? sprite_.getPosition() : sf::Vector2f();
}




sf::Sprite& VisibleObject::get_sprite()
{
    return sprite_;
}




bool VisibleObject::is_loaded() const
{
    return is_load_;
}




float VisibleObject::get_height() const
{
    return sprite_.getScale().y;
}




float VisibleObject::get_width() const
{
    return sprite_.getScale().x;
}




sf::Rect<float> VisibleObject::get_bounding_rect() const
{
    sf::Vector2f size = sprite_.getScale();
    sf::Vector2f position = sprite_.getOrigin();

    return sf::Rect<float>(position.x, position.y, position.x + size.x,
                            position.y + size.y);
}
