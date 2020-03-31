#include "Game/Game.hh"



// Global variables for instantiate Game attributes:
Game::GameState Game::game_state_ = Game::GameState::Uninitialized;
sf::RenderWindow Game::main_window_;


void Game::start()
{
    if (game_state_ != GameState::Uninitialized)
        return;

    main_window_.create(sf::VideoMode(1920, 1080, 32), "RunAway!!");
    game_state_ = GameState::ShowingSplash;


    while (!is_exiting())
    {
        game_loop();
    }


    main_window_.close();
}




bool Game::is_exiting()
{
    return (game_state_ == GameState::Exiting);
}




void Game::showSplashScreen()
{
    SplashScreen splashscreen;
    splashscreen.show(main_window_);
    game_state_ = Game::ShowingMenu;
}





void Game::showMenu()
{
    MainMenu mainmenu;
    MainMenu::MenuResult result = mainmenu.show(main_window_);

    switch(result)
    {
    case MainMenu::MenuResult::Exit:
        game_state_ = Game::Exiting;
        break;
    case MainMenu::MenuResult::Resume:
        game_state_ = Game::Playing;
        break;
    default:
        break;
    }
}


void Game::game_loop()
{
    sf::Event current;

    while (main_window_.pollEvent(current))
    {
        switch(game_state_)
        {
        case GameState::ShowingMenu:
            showMenu();
            break;

        case GameState::ShowingSplash:
            showSplashScreen();
            break;

        case GameState::Playing:
            main_window_.clear(sf::Color(255, 0, 0));
            main_window_.display();

            if (current.type == sf::Event::Closed)
                game_state_ = GameState::Exiting;

            break;
        default:
            std::cout << "Not Implemented yet!" << '\n';
        }

    }
}
