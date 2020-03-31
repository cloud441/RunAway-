#include "SplashScreen/SplashScreen.hh"


void SplashScreen::show(sf::RenderWindow& window)
{
        sf::Texture splash_image;

    if (!splash_image.loadFromFile("texture_pack/splash_screen.png"))
        return;

    sf::Sprite sprite(splash_image);
    window.draw(sprite);
    window.display();

    sf::Event event;

    while(true)
    {
        if (window.pollEvent(event)
            && (event.type == sf::Event::EventType::KeyPressed
            || event.type == sf::Event::EventType::MouseButtonPressed
            || event.type == sf::Event::EventType::Closed))
            return;
    }
}
