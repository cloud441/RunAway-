#pragma once

#include <vector>
//#include <Rect.hpp>

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"


class MainMenu
{
    public:

        enum MenuResult { Nothing, Exit, Resume};

        struct MenuItem
        {
            sf::Rect<int> rect_;
            MenuResult action_;
        };


        MenuResult show(sf::RenderWindow& window);
        MenuItem set_button(int left, int right, int top, int bottom,
                                MenuResult action);

    private:

        MenuResult GetMenuResponse(sf::RenderWindow& window);
        MenuResult HandleClick(int x, int y);

        std::vector<MenuItem> menu_items_;
};
