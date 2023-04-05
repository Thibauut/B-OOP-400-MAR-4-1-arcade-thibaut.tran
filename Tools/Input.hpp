/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** Input.hpp
*/

#pragma once

namespace arcade {
    enum STATES {
        MENU = 0,
        GAME,
        SETTINGS,
        PAUSE,
        EXIT
    };

    enum Input {
        ENTER = 10,
        ESCAPE = 27,
        SPACE = 32,
        RESUME = 80,
        ARROW_UP = 65,
        ARROW_DOWN = 66,
        ARROW_RIGHT = 67,
        ARROW_LEFT = 68,
        SWITCH_LIB = 6,
        SWITCH_GAME = 7,
        MENU_1 = 109,
        PACMAN = 1000,
        SNAKE = 1001,
        PAUSE_1 = 80,
        NONE = 0
    };
}