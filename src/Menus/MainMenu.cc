#include "Menus/MainMenu.hh"






MainMenu::MenuItem MainMenu::set_button(int left, int right, int top,
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





MainMenu::MenuResult MainMenu::show(sf::RenderWindow& window)
{
    //Load menu images:
    sf::Texture menu;
    menu.loadFromFile("texture_pack/main_menu.png");
    sf::Sprite sprite(menu);

    auto resume_button = set_button(700, 1200, 315, 450, MenuResult::Resume);
    auto exit_button = set_button(700, 1200, 550, 715, MenuResult::Exit);

    menu_items_.push_back(resume_button);
    menu_items_.push_back(exit_button);

    window.draw(sprite);
    window.display();

    return GetMenuResponse(window);
}




MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
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



MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
    sf::Event event;

    while (true)
    {
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
                return HandleClick(event.mouseButton.x, event.mouseButton.y);
            if (event.type == sf::Event::Closed)
                return MenuResult::Exit;
        }
    }
}
