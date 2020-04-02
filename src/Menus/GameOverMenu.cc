#include "Menus/GameOverMenu.hh"






GameOverMenu::MenuItem GameOverMenu::set_button(int left, int right, int top,
        int bottom, MenuResult action)
{
    MenuItem button;
    button.rect_.left = left;
    button.rect_.width = right - left;
    button.rect_.top = top;
    button.rect_.height= bottom - top;
    button.action_ = action;

    return button;
}





GameOverMenu::MenuResult GameOverMenu::show(sf::RenderWindow& window)
{
    //Load menu images:
    sf::Texture menu;
    menu.loadFromFile("texture_pack/game_over_screen.png");
    sf::Sprite sprite(menu);

    auto yes_button = set_button(700, 925, 815, 945, MenuResult::Play);
    auto no_button = set_button(975, 1210, 815, 945, MenuResult::MainMenu);

    menu_items_.push_back(yes_button);
    menu_items_.push_back(no_button);

    window.draw(sprite);
    window.display();

    return GetMenuResponse(window);
}




GameOverMenu::MenuResult GameOverMenu::HandleClick(int x, int y)
{
    for (auto iter = menu_items_.begin(); iter != menu_items_.end(); iter++)
    {
        sf::Rect<int> rect = (*iter).rect_;

        if (rect.left < x && rect.left + rect.width > x
                && rect.top < y && rect.top + rect.height > y)
            return (*iter).action_;
    }

    return MenuResult::Nothing;
}



GameOverMenu::MenuResult GameOverMenu::GetMenuResponse(sf::RenderWindow& window)
{
    sf::Event event;

    while (true)
    {
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
                return HandleClick(event.mouseButton.x, event.mouseButton.y);
            if (event.type == sf::Event::Closed)
                return MenuResult::MainMenu;
        }
    }
}
