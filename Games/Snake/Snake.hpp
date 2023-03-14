/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** Snake.hpp
*/

#pragma once

#include "../IGame.hpp"

namespace Arcade {
    class SnakeGame: public IGame {
        public:
            SnakeGame() {
                _info = "Snake";
            };
            ~SnakeGame() = default;
            std::string getInfo();

        protected:
            std::string _info;
    };
}