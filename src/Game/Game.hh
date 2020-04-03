#pragma once

#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "SplashScreen/SplashScreen.hh"
#include "Menus/MainMenu.hh"
#include "Menus/GameOverMenu.hh"
#include "Objects/Player.hh"
#include "Objects/Monsters/Monster.hh"
#include "Objects/Monsters/SadIsaac.hh"
#include "Objects/ObjectManager.hh"



class Game
{
    public:

        static void start();
        static sf::RenderWindow& get_window();
        const static int SCREEN_WIDTH = 1920;
        const static int SCREEN_HEIGHT = 1080;

        const static ObjectManager get_object_manager();

    private:

        static bool is_exiting();
        static void game_loop();
        static void showSplashScreen();
        static void showMainMenu();
        static void showGameOverMenu();
        static void set_background();
        static void set_environment();
        static void reset();

        enum GameState {
                        Uninitialized,
                        Paused,
                        Playing,
                        Menuing,
                        ShowingSplash,
                        ShowingMainMenu,
                        ShowingGameOverMenu,
                        Exiting
                        };

        static GameState game_state_;
        static sf::RenderWindow main_window_;
        static ObjectManager object_manager_;
        static sf::Texture background_texture_;

    public:

        static void set_game_state(GameState state);
        static GameState get_game_state(int state);
};
