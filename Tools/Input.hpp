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
        EXIT
    };

    enum Input {
        ENTER = 10,
        ESCAPE = 27,
        SPACE = 32,
        ARROW_UP = 65,
        ARROW_DOWN = 66,
        ARROW_RIGHT = 67,
        ARROW_LEFT = 68,
        NONE = 0
    };
}