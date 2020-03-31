#pragma once

#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "SplashScreen/SplashScreen.hh"
#include "Menus/MainMenu.hh"

class Game
{
    public:
        static void start();

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
};
