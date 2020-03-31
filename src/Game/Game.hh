#pragma once

#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"


class Game
{
    public:
        static void start();

    private:
        static bool is_exiting();
        static void game_loop();

        enum GameState {
                        Uninitialized,
                        Paused,
                        Playing,
                        Menuing,
                        ShowingAnimation,
                        Exiting
                        };

        static GameState game_state_;
        static sf::RenderWindow main_window_;
};
