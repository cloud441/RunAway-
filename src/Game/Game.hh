#pragma once

#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "SplashScreen/SplashScreen.hh"
#include "Menus/MainMenu.hh"
#include "Objects/Player.hh"
#include "Objects/ObjectManager.hh"



class Game
{
    public:

        static void start();
        static sf::RenderWindow& get_window();
        const static int SCREEN_WIDTH = 1920;
        const static int SCREEN_HEIGHT = 1080;

    private:

        static bool is_exiting();
        static void game_loop();
        static void showSplashScreen();
        static void showMenu();

        enum GameState {
                        Uninitialized,
                        Paused,
                        Playing,
                        Menuing,
                        ShowingSplash,
                        ShowingMenu,
                        Exiting
                        };

        static GameState game_state_;
        static sf::RenderWindow main_window_;
        static ObjectManager object_manager_;

    public:

        static void set_game_state(GameState state);
        static GameState get_game_state(int state);
};
