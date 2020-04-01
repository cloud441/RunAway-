#pragma once


#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"



class VisibleObject
{
    public:

        VisibleObject();
        virtual ~VisibleObject();

        virtual void load(std::string filename);
        virtual void draw(sf::RenderWindow& window);
        virtual void update(float time);

        virtual void set_position(float x, float y);
        virtual sf::Vector2f get_position() const;
        virtual bool is_loaded() const;

        virtual float get_width() const;
        virtual float get_height() const;
        virtual sf::Rect<float> get_bounding_rect() const;

    protected:
        sf::Sprite& get_sprite();


    private:

        sf::Sprite sprite_;
        sf::Texture texture_;
        std::string filename_;
        bool is_load_;
};
