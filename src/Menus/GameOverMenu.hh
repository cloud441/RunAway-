#pragma once

#include <vector>

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"


class GameOverMenu
{
    public:

        enum MenuResult { Nothing, MainMenu, Play};

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
