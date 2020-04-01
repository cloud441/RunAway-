#include "Game/Game.hh"



// Global variables for instantiate Game attributes:
Game::GameState Game::game_state_ = Game::GameState::Uninitialized;
sf::RenderWindow Game::main_window_;
ObjectManager Game::object_manager_;
sf::Texture Game::background_texture_;



void Game::set_background()
{
    sf::Texture background;
    background.loadFromFile("texture_pack/background.png");
    background_texture_ = background;
}


void Game::start()
{
    if (game_state_ != GameState::Uninitialized)
        return;

    main_window_.create(sf::VideoMode(1920, 1080, 32), "RunAway!!");

    //Add a player object:
    Player *player1 = new Player();
    player1->load("texture_pack/paddle.png");
    player1->set_position(SCREEN_WIDTH / 2 - 45, SCREEN_HEIGHT / 2 - 45);
    object_manager_.add("Paddle1", player1);

    //Add a SadIsaac Monster object:
    SadIsaac *sad_isaac1 = new SadIsaac();
    sad_isaac1->load("texture_pack/sadisaac.png");
    sad_isaac1->set_position((SCREEN_WIDTH / 3) * 2, SCREEN_HEIGHT / 2);
    object_manager_.add("SadIssac1", sad_isaac1);


    game_state_ = GameState::ShowingSplash;
    set_background();


    while (!is_exiting())
    {
        game_loop();
    }


    main_window_.close();
}




void Game::set_game_state(Game::GameState state)
{
    game_state_ = state;
}




Game::GameState Game::get_game_state(int state)
{
    switch(state)
    {
    case 0:
        return GameState::Uninitialized;
    case 1:
        return GameState::Paused;
    case 2:
        return GameState::Playing;
    case 3:
        return GameState::Menuing;
    case 4:
        return GameState::ShowingSplash;
    case 5:
        return GameState::ShowingMenu;
    default:
        return GameState::Exiting;
    }
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




sf::RenderWindow& Game::get_window()
{
    return main_window_;
}







void Game::game_loop()
{
    sf::Event current;
    sf::Sprite sprite(background_texture_);

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
            main_window_.draw(sprite);

            object_manager_.update_all();
            object_manager_.draw_all(main_window_);

            main_window_.display();

            if (current.type == sf::Event::Closed)
                game_state_ = GameState::Exiting;

            break;
        default:
            std::cout << "Not Implemented yet!" << '\n';
        }

    }
}
