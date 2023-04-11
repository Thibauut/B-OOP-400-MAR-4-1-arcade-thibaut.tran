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

        PLAYER1_JUMP = 65,
        PLAYER1_DOWN = 66,
        PLAYER1_RIGHT = 67,
        PLAYER1_LEFT = 68,
        PLAYER1_HIT = 102,

        PLAYER2_JUMP = 122,
        PLAYER2_DOWN = 115,
        PLAYER2_RIGHT = 100,
        PLAYER2_LEFT = 113,
        PLAYER2_HIT = 33,

        SWITCH_LIB = 6,
        SWITCH_GAME = 7,
        MENU_1 = 109,
        PACMAN = 1000,
        SNAKE = 1001,
        SFT = 1002,
        PAUSE_1 = 80,
        NONE = 0
    };
}